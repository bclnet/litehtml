#include "html.h"
#include "render_item.h"
#include "document.h"
#include <typeinfo>
#include <utf8_strings.h>

litehtml::render_item::render_item(std::shared_ptr<element>  _src_el) :
        m_element(std::move(_src_el)),
        m_skip(false),
        m_box(nullptr)
{
    document::ptr doc = src_el()->get_document();
    auto fnt_size = src_el()->css().get_font_size();

    m_margins.left		= doc->to_pixels(src_el()->css().get_margins().left,         fnt_size);
    m_margins.right		= doc->to_pixels(src_el()->css().get_margins().right,        fnt_size);
    m_margins.top		= doc->to_pixels(src_el()->css().get_margins().top,          fnt_size);
    m_margins.bottom	= doc->to_pixels(src_el()->css().get_margins().bottom,       fnt_size);
    #if H3ML
    m_margins.front		= doc->to_pixels(src_el()->css().get_margins().front,        fnt_size);
    m_margins.back	    = doc->to_pixels(src_el()->css().get_margins().back,         fnt_size);
    #endif

    m_padding.left		= doc->to_pixels(src_el()->css().get_padding().left,         fnt_size);
    m_padding.right		= doc->to_pixels(src_el()->css().get_padding().right,        fnt_size);
    m_padding.top		= doc->to_pixels(src_el()->css().get_padding().top,          fnt_size);
    m_padding.bottom	= doc->to_pixels(src_el()->css().get_padding().bottom,       fnt_size);
    #if H3ML
    m_padding.front		= doc->to_pixels(src_el()->css().get_padding().front,        fnt_size);
    m_padding.back	    = doc->to_pixels(src_el()->css().get_padding().back,         fnt_size);
    #endif

    m_borders.left		= doc->to_pixels(src_el()->css().get_borders().left.width,   fnt_size);
    m_borders.right		= doc->to_pixels(src_el()->css().get_borders().right.width,  fnt_size);
    m_borders.top		= doc->to_pixels(src_el()->css().get_borders().top.width,    fnt_size);
    m_borders.bottom	= doc->to_pixels(src_el()->css().get_borders().bottom.width, fnt_size);
    #if H3ML
    m_borders.front		= doc->to_pixels(src_el()->css().get_borders().front.width,  fnt_size);
    m_borders.back	    = doc->to_pixels(src_el()->css().get_borders().back.width,   fnt_size);
    #endif
}

void litehtml::render_item::calc_outlines( int parent_width )
{
    m_padding.left	= m_element->css().get_padding().left.calc_percent(parent_width);
    m_padding.right	= m_element->css().get_padding().right.calc_percent(parent_width);

    m_borders.left	= m_element->css().get_borders().left.width.calc_percent(parent_width);
    m_borders.right	= m_element->css().get_borders().right.width.calc_percent(parent_width);

    m_margins.left	= m_element->css().get_margins().left.calc_percent(parent_width);
    m_margins.right	= m_element->css().get_margins().right.calc_percent(parent_width);

    m_margins.top		= m_element->css().get_margins().top.calc_percent(parent_width);
    m_margins.bottom	= m_element->css().get_margins().bottom.calc_percent(parent_width);

    m_padding.top		= m_element->css().get_padding().top.calc_percent(parent_width);
    m_padding.bottom	= m_element->css().get_padding().bottom.calc_percent(parent_width);

    #if H3ML
    m_margins.front		= m_element->css().get_margins().front.calc_percent(parent_width);
    m_margins.back	    = m_element->css().get_margins().back.calc_percent(parent_width);

    m_padding.front		= m_element->css().get_padding().front.calc_percent(parent_width);
    m_padding.back	    = m_element->css().get_padding().back.calc_percent(parent_width);
    #endif
}

void litehtml::render_item::calc_auto_margins(int parent_width)
{
    if ((src_el()->css().get_display() == display_block || src_el()->css().get_display() == display_table) &&
            src_el()->css().get_position() != element_position_absolute &&
            src_el()->css().get_float() == float_none)
    {
        if (src_el()->css().get_margins().left.is_predefined() && src_el()->css().get_margins().right.is_predefined())
        {
            int el_width = m_pos.width + m_borders.left + m_borders.right + m_padding.left + m_padding.right;
            if (el_width <= parent_width)
            {
                m_margins.left = (parent_width - el_width) / 2;
                m_margins.right = (parent_width - el_width) - m_margins.left;
            }
            else
            {
                m_margins.left = 0;
                m_margins.right = 0;
            }
        }
        else if (src_el()->css().get_margins().left.is_predefined() && !src_el()->css().get_margins().right.is_predefined())
        {
            int el_width = m_pos.width + m_borders.left + m_borders.right + m_padding.left + m_padding.right + m_margins.right;
            m_margins.left = parent_width - el_width;
            if (m_margins.left < 0) m_margins.left = 0;
        }
        else if (!src_el()->css().get_margins().left.is_predefined() && src_el()->css().get_margins().right.is_predefined())
        {
            int el_width = m_pos.width + m_borders.left + m_borders.right + m_padding.left + m_padding.right + m_margins.left;
            m_margins.right = parent_width - el_width;
            if (m_margins.right < 0) m_margins.right = 0;
        }
    }
}

void litehtml::render_item::apply_relative_shift(int parent_width)
{
    if (src_el()->css().get_position() == element_position_relative)
    {
        css_offsets offsets = src_el()->css().get_offsets();
        if (!offsets.left.is_predefined())
        {
            m_pos.x += offsets.left.calc_percent(parent_width);
        }
        else if (!offsets.right.is_predefined())
        {
            m_pos.x -= offsets.right.calc_percent(parent_width);
        }
        if (!offsets.top.is_predefined())
        {
            int h = 0;

            if (offsets.top.units() == css_units_percentage)
            {
                auto el_parent = parent();
                if (el_parent)
                {
                    el_parent->get_predefined_height(h);
                }
            }

            m_pos.y += offsets.top.calc_percent(h);
        }
        else if (!offsets.bottom.is_predefined())
        {
            int h = 0;

            if (offsets.top.units() == css_units_percentage)
            {
                auto el_parent = parent();
                if (el_parent)
                {
                    el_parent->get_predefined_height(h);
                }
            }

            m_pos.y -= offsets.bottom.calc_percent(h);
        }
        #if H3ML
        else if (!offsets.front.is_predefined())
		{
			int d = 0;
			if (offsets.front.units() == css_units_percentage)
			{
				auto el_parent = parent();
				if (el_parent)
				{
					el_parent->get_predefined_depth(d);
				}
			}
			m_pos.z += offsets.bottom.calc_percent(d);
		}
		else if (!offsets.back.is_predefined())
		{
			int d = 0;
			if (offsets.back.units() == css_units_percentage)
			{
				auto el_parent = parent();
				if (el_parent)
				{
					el_parent->get_predefined_depth(d);
				}
			}
			m_pos.z -= offsets.bottom.calc_percent(d);
		}
        #endif
    }
}

bool litehtml::render_item::get_predefined_height(int& p_height) const
{
    css_length h = src_el()->css().get_height();
    if(h.is_predefined())
    {
        p_height = m_pos.height;
        return false;
    }
    if(h.units() == css_units_percentage)
    {
        auto el_parent = parent();
        if (!el_parent)
        {
            position client_pos;
            src_el()->get_document()->container()->get_client_rect(client_pos);
            p_height = h.calc_percent(client_pos.height);
            return true;
        } else
        {
            int ph = 0;
            if (el_parent->get_predefined_height(ph))
            {
                p_height = h.calc_percent(ph);
                if (src_el()->is_body())
                {
                    p_height -= content_margins_height();
                }
                return true;
            } else
            {
                p_height = m_pos.height;
                return false;
            }
        }
    }
    p_height = src_el()->get_document()->to_pixels(h, src_el()->css().get_font_size());
    return true;
}

#if H3ML
bool litehtml::render_item::get_predefined_depth(int& p_depth) const
{
	css_length d = src_el()->css().get_depth();
	if (d.is_predefined())
	{
		p_depth = m_pos.depth;
		return false;
	}
	if (d.units() == css_units_percentage)
	{
		auto el_parent = parent();
		if (!el_parent)
		{
			position client_pos;
			src_el()->get_document()->container()->get_client_rect(client_pos);
			p_depth = d.calc_percent(client_pos.depth);
			return true;
		}
		else
		{
			int pd = 0;
			if (el_parent->get_predefined_depth(pd))
			{
				p_depth = d.calc_percent(pd);
				if (src_el()->is_body())
				{
					p_depth -= content_margins_depth();
				}
				return true;
			}
			else
			{
				p_depth = m_pos.depth;
				return false;
			}
		}
	}
    p_depth = src_el()->get_document()->to_pixels(d, src_el()->css().get_font_size());
	return true;
}
#endif

int litehtml::render_item::get_inline_shift_left()
{
    int ret = 0;
    auto el_parent = parent();
    if (el_parent)
    {
        if (el_parent->src_el()->css().get_display() == display_inline)
        {
            style_display disp = src_el()->css().get_display();

            if (disp == display_inline_text || disp == display_inline_block)
            {
                auto el = shared_from_this();
                while (el_parent && el_parent->src_el()->css().get_display() == display_inline)
                {
                    if (el_parent->is_first_child_inline(el))
                    {
                        ret += el_parent->padding_left() + el_parent->border_left() + el_parent->margin_left();
                    } else
                        break;
                    el = el_parent;
                    el_parent = el_parent->parent();
                }
            }
        }
    }

    return ret;
}

int litehtml::render_item::get_inline_shift_right()
{
    int ret = 0;
    auto el_parent = parent();
    if (el_parent)
    {
        if (el_parent->src_el()->css().get_display() == display_inline)
        {
            style_display disp = src_el()->css().get_display();

            if (disp == display_inline_text || disp == display_inline_block)
            {
                auto el = shared_from_this();
                while (el_parent && el_parent->src_el()->css().get_display() == display_inline)
                {
                    if (el_parent->is_last_child_inline(el))
                    {
                        ret += el_parent->padding_right() + el_parent->border_right() + el_parent->margin_right();
                    } else
                        break;
                    el = el_parent;
                    el_parent = el_parent->parent();
                }
            }
        }
    }

    return ret;
}

bool litehtml::render_item::is_first_child_inline(const std::shared_ptr<render_item>& el) const
{
    if(!m_children.empty())
    {
        for (const auto& this_el : m_children)
        {
            if (!this_el->src_el()->is_white_space())
            {
                if (el == this_el)
                {
                    return true;
                }
                if (this_el->src_el()->css().get_display() == display_inline)
                {
                    if (this_el->have_inline_child())
                    {
                        return false;
                    }
                } else
                {
                    return false;
                }
            }
        }
    }
    return false;
}

bool litehtml::render_item::is_last_child_inline(const std::shared_ptr<render_item>& el) const
{
    if(!m_children.empty())
    {
        for (auto it = m_children.rbegin(); it != m_children.rend(); ++it)
        {
            const auto& this_el = *it;
            if (!this_el->src_el()->is_white_space())
            {
                if (el == this_el)
                {
                    return true;
                }
                if (this_el->src_el()->css().get_display() == display_inline)
                {
                    if (this_el->have_inline_child())
                    {
                        return false;
                    }
                } else
                {
                    return false;
                }
            }
        }
    }
    return false;
}

bool litehtml::render_item::have_inline_child() const
{
    if(!m_children.empty())
    {
        for(const auto& el : m_children)
        {
            if(!el->src_el()->is_white_space())
            {
                return true;
            }
        }
    }
    return false;
}

int litehtml::render_item::calc_width(int defVal) const
{
    css_length w = src_el()->css().get_width();
    if(w.is_predefined() || src_el()->css().get_display() == display_table_cell)
    {
        return defVal;
    }
    if(w.units() == css_units_percentage)
    {
        auto el_parent = parent();
        if (!el_parent)
        {
            position client_pos;
            src_el()->get_document()->container()->get_client_rect(client_pos);
            return w.calc_percent(client_pos.width) - content_margins_width();
        } else
        {
            int pw = el_parent->calc_width(defVal);
            if (src_el()->is_body())
            {
                pw -= content_margins_width();
            }
            return w.calc_percent(pw);
        }
    }
    return 	src_el()->get_document()->to_pixels(w, src_el()->css().get_font_size());
}

std::tuple<
        std::shared_ptr<litehtml::render_item>,
        std::shared_ptr<litehtml::render_item>,
        std::shared_ptr<litehtml::render_item>
        > litehtml::render_item::split_inlines()
{
    std::tuple<
            std::shared_ptr<litehtml::render_item>,
            std::shared_ptr<litehtml::render_item>,
            std::shared_ptr<litehtml::render_item>
    > ret;
    for(const auto& child: m_children)
    {
        if(child->src_el()->is_block_box() && child->src_el()->css().get_float() == float_none)
        {
            std::get<0>(ret) = clone();
            std::get<1>(ret) = child;
            std::get<2>(ret) = clone();

            std::get<1>(ret)->parent(std::get<0>(ret));
            std::get<2>(ret)->parent(std::get<0>(ret));

            bool found = false;
            for(const auto& ch: m_children)
            {
                if(ch == child)
                {
                    found = true;
                    continue;
                }
                if(!found)
                {
                    std::get<0>(ret)->add_child(ch);
                } else
                {
                    std::get<2>(ret)->add_child(ch);
                }
            }
            break;
        }
        if(!child->children().empty())
        {
            auto child_split = child->split_inlines();
            if(std::get<0>(child_split))
            {
                std::get<0>(ret) = clone();
                std::get<1>(ret) = std::get<1>(child_split);
                std::get<2>(ret) = clone();

                std::get<2>(ret)->parent(std::get<0>(ret));

                bool found = false;
                for(const auto& ch: m_children)
                {
                    if(ch == child)
                    {
                        found = true;
                        continue;
                    }
                    if(!found)
                    {
                        std::get<0>(ret)->add_child(ch);
                    } else
                    {
                        std::get<2>(ret)->add_child(ch);
                    }
                }
                std::get<0>(ret)->add_child(std::get<0>(child_split));
                std::get<2>(ret)->add_child(std::get<2>(child_split));
                break;
            }
        }
    }
    return ret;
}

bool litehtml::render_item::fetch_positioned()
{
    bool ret = false;

    m_positioned.clear();

    litehtml::element_position el_pos;

    for(auto& el : m_children)
    {
        el_pos = el->src_el()->css().get_position();
        if (el_pos != element_position_static)
        {
            add_positioned(el);
        }
        if (!ret && (el_pos == element_position_absolute || el_pos == element_position_fixed))
        {
            ret = true;
        }
        if(el->fetch_positioned())
        {
            ret = true;
        }
    }
    return ret;
}

void litehtml::render_item::render_positioned(render_type rt)
{
    position wnd_position;
    src_el()->get_document()->container()->get_client_rect(wnd_position);

    element_position el_position;
    bool process;
    for (auto& el : m_positioned)
    {
        el_position = el->src_el()->css().get_position();

        process = false;
        if(el->src_el()->css().get_display() != display_none)
        {
            if(el_position == element_position_absolute)
            {
                if(rt != render_fixed_only)
                {
                    process = true;
                }
            } else if(el_position == element_position_fixed)
            {
                if(rt != render_no_fixed)
                {
                    process = true;
                }
            }
        }

        if(process)
        {
            int parent_height	= 0;
            int parent_width	= 0;
            #if H3ML
            int parent_depth    = 0;
            #endif
            int client_x		= 0;
            int client_y		= 0;
            #if H3ML
            int client_z		= 0;
            #endif
            if(el_position == element_position_fixed)
            {
                parent_height	= wnd_position.height;
                parent_width	= wnd_position.width;
                #if H3ML
                parent_depth    = wnd_position.depth;
                #endif
                client_x		= wnd_position.left();
                client_y		= wnd_position.top();
                #if H3ML
                client_z        = wnd_position.front();
                #endif
            } else
            {
                auto el_parent = el->parent();
                if(el_parent)
                {
                    parent_height	= el_parent->height();
                    parent_width	= el_parent->width();
                    #if H3ML
                    parent_depth    = el_parent->depth();
                    #endif
                }
            }

            css_length	css_left	= el->src_el()->css().get_offsets().left;
            css_length	css_right	= el->src_el()->css().get_offsets().right;
            css_length	css_top		= el->src_el()->css().get_offsets().top;
            css_length	css_bottom	= el->src_el()->css().get_offsets().bottom;
            #if H3ML
			css_length	css_front   = el->src_el()->css().get_offsets().front;
			css_length	css_back    = el->src_el()->css().get_offsets().back;
            #endif

            bool need_render = false;

            css_length el_w = el->src_el()->css().get_width();
            css_length el_h = el->src_el()->css().get_height();
            #if H3ML
            css_length el_d = el->src_el()->css().get_depth();
            #endif

            int new_width = -1;
            int new_height = -1;
            #if H3ML
            int new_depth = -1;
            #endif
            if(el_w.units() == css_units_percentage && parent_width)
            {
                new_width = el_w.calc_percent(parent_width);
                if(el->m_pos.width != new_width)
                {
                    need_render = true;
                    el->m_pos.width = new_width;
                }
            }

            if(el_h.units() == css_units_percentage && parent_height)
            {
                new_height = el_h.calc_percent(parent_height);
                if(el->m_pos.height != new_height)
                {
                    need_render = true;
                    el->m_pos.height = new_height;
                }
            }

            #if H3ML
			if(el_d.units() == css_units_percentage && parent_depth)
			{
				new_depth = el_d.calc_percent(parent_depth);
				if (el->m_pos.depth != new_depth)
				{
					need_render = true;
					el->m_pos.depth = new_depth;
				}
			}
            #endif

            bool cvt_x = false;
            bool cvt_y = false;
            #if H3ML
            bool cvt_z = false;
            #endif

            if(el_position == element_position_fixed)
            {
                if(!css_left.is_predefined() || !css_right.is_predefined())
                {
                    if(!css_left.is_predefined() && css_right.is_predefined())
                    {
                        el->m_pos.x = css_left.calc_percent(parent_width) + el->content_margins_left();
                    } else if(css_left.is_predefined() && !css_right.is_predefined())
                    {
                        el->m_pos.x = parent_width - css_right.calc_percent(parent_width) - el->m_pos.width - el->content_margins_right();
                    } else
                    {
                        el->m_pos.x		= css_left.calc_percent(parent_width) + el->content_margins_left();
                        el->m_pos.width	= parent_width - css_left.calc_percent(parent_width) - css_right.calc_percent(parent_width) - (el->content_margins_left() + el->content_margins_right());
                        need_render = true;
                    }
                }

                if(!css_top.is_predefined() || !css_bottom.is_predefined())
                {
                    if(!css_top.is_predefined() && css_bottom.is_predefined())
                    {
                        el->m_pos.y = css_top.calc_percent(parent_height) + el->content_margins_top();
                    } else if(css_top.is_predefined() && !css_bottom.is_predefined())
                    {
                        el->m_pos.y = parent_height - css_bottom.calc_percent(parent_height) - el->m_pos.height - el->content_margins_bottom();
                    } else
                    {
                        el->m_pos.y			= css_top.calc_percent(parent_height) + el->content_margins_top();
                        el->m_pos.height	= parent_height - css_top.calc_percent(parent_height) - css_bottom.calc_percent(parent_height) - (el->content_margins_top() + el->content_margins_bottom());
                        need_render = true;
                    }
                }

                #if H3ML
                if(!css_front.is_predefined() || !css_back.is_predefined())
				{
					if (!css_front.is_predefined() && css_back.is_predefined())
					{
						el->m_pos.z = css_front.calc_percent(parent_depth) + el->content_margins_front();
					} else if (css_front.is_predefined() && !css_back.is_predefined())
					{
						el->m_pos.z = parent_depth - css_back.calc_percent(parent_depth) - el->m_pos.depth - el->content_margins_back();
					} else
					{
						el->m_pos.z     = css_front.calc_percent(parent_depth) + el->content_margins_front();
						el->m_pos.depth = parent_depth - css_front.calc_percent(parent_depth) - css_back.calc_percent(parent_depth) - (el->content_margins_front() + el->content_margins_back());
						need_render = true;
					}
				}
                #endif
            } else
            {
                if(!css_left.is_predefined() || !css_right.is_predefined())
                {
                    if(!css_left.is_predefined() && css_right.is_predefined())
                    {
                        el->m_pos.x = css_left.calc_percent(parent_width) + el->content_margins_left() - m_padding.left;
                    } else if(css_left.is_predefined() && !css_right.is_predefined())
                    {
                        el->m_pos.x = m_pos.width + m_padding.right - css_right.calc_percent(parent_width) - el->m_pos.width - el->content_margins_right();
                    } else
                    {
                        el->m_pos.x		= css_left.calc_percent(parent_width) + el->content_margins_left() - m_padding.left;
                        el->m_pos.width	= m_pos.width + m_padding.left + m_padding.right - css_left.calc_percent(parent_width) - css_right.calc_percent(parent_width) - (el->content_margins_left() + el->content_margins_right());
                        if (new_width != -1)
                        {
                            el->m_pos.x += (el->m_pos.width - new_width) / 2;
                            el->m_pos.width = new_width;
                        }
                        need_render = true;
                    }
                    cvt_x = true;
                }

                if(!css_top.is_predefined() || !css_bottom.is_predefined())
                {
                    if(!css_top.is_predefined() && css_bottom.is_predefined())
                    {
                        el->m_pos.y = css_top.calc_percent(parent_height) + el->content_margins_top() - m_padding.top;
                    } else if(css_top.is_predefined() && !css_bottom.is_predefined())
                    {
                        el->m_pos.y = m_pos.height + m_padding.bottom - css_bottom.calc_percent(parent_height) - el->m_pos.height - el->content_margins_bottom();
                    } else
                    {
                        el->m_pos.y			= css_top.calc_percent(parent_height) + el->content_margins_top() - m_padding.top;
                        el->m_pos.height	= m_pos.height + m_padding.top + m_padding.bottom - css_top.calc_percent(parent_height) - css_bottom.calc_percent(parent_height) - (el->content_margins_top() + el->content_margins_bottom());
                        if (new_height != -1)
                        {
                            el->m_pos.y += (el->m_pos.height - new_height) / 2;
                            el->m_pos.height = new_height;
                        }
                        need_render = true;
                    }
                    cvt_y = true;
                }

                #if H3ML
                if(!css_front.is_predefined() || !css_back.is_predefined())
				{
					if (!css_front.is_predefined() && css_back.is_predefined())
					{
						el->m_pos.z = css_front.calc_percent(parent_depth) + el->content_margins_front() - m_padding.front;
					} else if (css_front.is_predefined() && !css_back.is_predefined())
					{
						el->m_pos.z = m_pos.depth + m_padding.back - css_back.calc_percent(parent_depth) - el->m_pos.depth - el->content_margins_back();
					} else
					{
						el->m_pos.z         = css_front.calc_percent(parent_depth) + el->content_margins_front() - m_padding.front;
						el->m_pos.depth     = m_pos.depth + m_padding.front + m_padding.back - css_front.calc_percent(parent_depth) - css_back.calc_percent(parent_depth) - (el->content_margins_front() + el->content_margins_back());
						if (new_depth != -1)
						{
							el->m_pos.z += (el->m_pos.depth - new_depth) / 2;
							el->m_pos.depth = new_depth;
						}
						need_render = true;
					}
					cvt_z = true;
				}
                #endif
            }

            if(cvt_x || cvt_y
            #if H3ML
            || cvt_z
            #endif
            )
            {
                int offset_x = 0;
                int offset_y = 0;
                #if H3ML
                int offset_z = 0;
                #endif
                auto cur_el = el->parent();
                auto this_el = shared_from_this();
                while(cur_el && cur_el != this_el)
                {
                    offset_x += cur_el->m_pos.x;
                    offset_y += cur_el->m_pos.y;
                    #if H3ML
                    offset_z += cur_el->m_pos.z;
                    #endif
                    cur_el = cur_el->parent();
                }
                if(cvt_x)	el->m_pos.x -= offset_x;
                if(cvt_y)	el->m_pos.y -= offset_y;
                #if H3ML
                if(cvt_z)	el->m_pos.z -= offset_z;
                #endif
            }

            if(need_render)
            {
                position pos = el->m_pos;
                el->_render({ el->left(), el->top() 
                    #if H3ML
                    , el->front()
                    #endif
                    }, el->width(), true);
                el->m_pos = pos;
            }

            if(el_position == element_position_fixed)
            {
                position fixed_pos;
                el->get_redraw_box(fixed_pos);
                src_el()->get_document()->add_fixed_box(fixed_pos);
            }
        }

        el->render_positioned();
    }

    if(!m_positioned.empty())
    {
        std::stable_sort(m_positioned.begin(), m_positioned.end(), [](const std::shared_ptr<render_item>& Left, const std::shared_ptr<render_item>& Right)
            {
                return (Left->src_el()->css().get_z_index() < Right->src_el()->css().get_z_index());
            });
    }
}

void litehtml::render_item::add_positioned(const std::shared_ptr<litehtml::render_item> &el)
{
    if (src_el()->css().get_position() != element_position_static || (!have_parent()))
    {
        m_positioned.push_back(el);
    } else
    {
        auto el_parent = parent();
        if (el_parent)
        {
            el_parent->add_positioned(el);
        }
    }
}

void litehtml::render_item::get_redraw_box(litehtml::position& pos, point p /*= 0*/)
{
    if(is_visible())
    {
        int p_left		= std::min(pos.left(),	p.x + m_pos.left() - m_padding.left - m_borders.left);
        int p_right		= std::max(pos.right(), p.x + m_pos.right() + m_padding.left + m_borders.left);
        int p_top		= std::min(pos.top(), p.y + m_pos.top() - m_padding.top - m_borders.top);
        int p_bottom	= std::max(pos.bottom(), p.y + m_pos.bottom() + m_padding.bottom + m_borders.bottom);
        #if H3ML
		int p_front     = std::min(pos.front(), p.z + m_pos.front() + m_padding.front + m_borders.front);
		int p_back      = std::max(pos.back(), p.z + m_pos.back() + m_padding.back + m_borders.back);
        #endif

        pos.x = p_left;
        pos.y = p_top;
        #if H3ML
        pos.z = p_front;
        #endif
        pos.width	= p_right - p_left;
        pos.height	= p_bottom - p_top;
        #if H3ML
        pos.depth 	= p_back - p_front;
        #endif

        if(src_el()->css().get_overflow() == overflow_visible)
        {
            for(auto& el : m_children)
            {
                if(el->src_el()->css().get_position() != element_position_fixed)
                {
                    el->get_redraw_box(pos, p + m_pos.p());
                }
            }
        }
    }
}

void litehtml::render_item::calc_document_size( litehtml::size& sz, point p /*= 0*/ )
{
    if(is_visible() && src_el()->css().get_position() != element_position_fixed)
    {
        sz.width	= std::max(sz.width,	p.x + right());
        sz.height	= std::max(sz.height,   p.y + bottom());
        #if H3ML
        sz.depth	= std::max(sz.depth,	p.z + front());
        #endif

        if(src_el()->css().get_overflow() == overflow_visible)
        {
            for(auto& el : m_children)
            {
                el->calc_document_size(sz, p + m_pos.p());
            }
        }

        // root element (<html>) have to cover entire window
        if(!have_parent())
        {
            position client_pos;
            src_el()->get_document()->container()->get_client_rect(client_pos);
            m_pos.height = std::max(sz.height, client_pos.height) - content_margins_top() - content_margins_bottom();
            m_pos.width	 = std::max(sz.width, client_pos.width) - content_margins_left() - content_margins_right();
            #if H3ML
            m_pos.depth  = std::max(sz.depth, client_pos.depth) - content_margins_front() - content_margins_back();
            #endif
        }
    }
}

void litehtml::render_item::get_inline_boxes( position::vector& boxes )
{
    if(src_el()->css().get_display() == display_table_row)
    {
        position pos;
        for(auto& el : m_children)
        {
            if(el->src_el()->css().get_display() == display_table_cell)
            {
                pos.x		= el->left() + el->margin_left();
                pos.y		= el->top() - m_padding.top - m_borders.top;
                #if H3ML
                pos.z       = el->front() - m_padding.front - m_borders.front;
                #endif

                pos.width	= el->right() - pos.x - el->margin_right() - el->margin_left();
                pos.height	= el->height() + m_padding.top + m_padding.bottom + m_borders.top + m_borders.bottom;
                #if H3ML
                pos.depth   = el->depth() + m_padding.front + m_padding.back + m_borders.front + m_borders.back;
                #endif

                boxes.push_back(pos);
            }
        }
    } else
    {

        litehtml::line_box *old_box = nullptr;
        position pos;
        for (auto &el: m_children)
        {
            if (!el->skip())
            {
                if (el->m_box)
                {
                    if (el->m_box != old_box)
                    {
                        if (old_box)
                        {
                            if (boxes.empty())
                            {
                                pos.x -= m_padding.left + m_borders.left;
                                pos.width += m_padding.left + m_borders.left;
                            }
                            boxes.push_back(pos);
                        }
                        old_box = el->m_box;
                        pos.x = el->left() + el->margin_left();
                        pos.y = el->top() - m_padding.top - m_borders.top;
                        #if H3ML
                        pos.z = el->front() - m_padding.front - m_borders.front;
                        #endif
                        pos.width = 0;
                        pos.height = 0;
                        #if H3ML
                        pos.depth = 0;
                        #endif
                    }
                    pos.width = el->right() - pos.x - el->margin_right() - el->margin_left();
                    pos.height = std::max(pos.height, el->height() + m_padding.top + m_padding.bottom + m_borders.top + m_borders.bottom);
                    #if H3ML
                    pos.depth = std::max(pos.depth, el->depth() + m_padding.front + m_padding.back + m_borders.front + m_borders.back);
                    #endif
                } else if (el->src_el()->css().get_display() == display_inline)
                {
                    position::vector sub_boxes;
                    el->get_inline_boxes(sub_boxes);
                    if (!sub_boxes.empty())
                    {
                        sub_boxes.rbegin()->width += el->margin_right();
                        if (boxes.empty())
                        {
                            if (m_padding.left + m_borders.left > 0)
                            {
                                position padding_box = (*sub_boxes.begin());
                                padding_box.x -= m_padding.left + m_borders.left + el->margin_left();
                                padding_box.width = m_padding.left + m_borders.left + el->margin_left();
                                boxes.push_back(padding_box);
                            }
                        }

                        sub_boxes.rbegin()->width += el->margin_right();

                        boxes.insert(boxes.end(), sub_boxes.begin(), sub_boxes.end());
                    }
                }
            }
        }
        if (pos.width || pos.height
        #if H3ML
        || pos.depth
        #endif
        )
        {
            if (boxes.empty())
            {
                pos.x -= m_padding.left + m_borders.left;
                pos.width += m_padding.left + m_borders.left;
            }
            boxes.push_back(pos);
        }
        if (!boxes.empty())
        {
            if (m_padding.right + m_borders.right > 0)
            {
                boxes.back().width += m_padding.right + m_borders.right;
            }
        }
    }
}

void litehtml::render_item::draw_stacking_context( uint_ptr hdc, point p, const position* clip, bool with_positioned )
{
    if(!is_visible()) return;

    std::map<int, bool> z_indexes;
    if(with_positioned)
    {
        for(const auto& idx : m_positioned)
        {
            z_indexes[idx->src_el()->css().get_z_index()];
        }

        for(const auto& idx : z_indexes)
        {
            if(idx.first < 0)
            {
                draw_children(hdc, p, clip, draw_positioned, idx.first);
            }
        }
    }
    draw_children(hdc, p, clip, draw_block, 0);
    draw_children(hdc, p, clip, draw_floats, 0);
    draw_children(hdc, p, clip, draw_inlines, 0);
    if(with_positioned)
    {
        for(auto& z_index : z_indexes)
        {
            if(z_index.first == 0)
            {
                draw_children(hdc, p, clip, draw_positioned, z_index.first);
            }
        }

        for(auto& z_index : z_indexes)
        {
            if(z_index.first > 0)
            {
                draw_children(hdc, p, clip, draw_positioned, z_index.first);
            }
        }
    }
}

void litehtml::render_item::draw_children(uint_ptr hdc, point p, const position* clip, draw_flag flag, int zindex)
{
    position pos = m_pos;
    pos.x += p.x;
    pos.y += p.y;
    #if H3ML
    pos.z += p.z;
    #endif

    document::ptr doc = src_el()->get_document();

    if (src_el()->css().get_overflow() > overflow_visible)
    {
        // TODO: Process overflow for inline elements
        if(src_el()->css().get_display() != display_inline)
        {
            position border_box = pos;
            border_box += m_padding;
            border_box += m_borders;

            border_radiuses bdr_radius = src_el()->css().get_borders().radius.calc_percents(border_box.sz());

            bdr_radius -= m_borders;
            bdr_radius -= m_padding;

            doc->container()->set_clip(pos, bdr_radius, true, true);
        }
    }

    for (const auto& el : m_children)
    {
        if (el->is_visible())
        {
            bool process = true;
            switch (flag)
            {
                case draw_positioned:
                    if (el->src_el()->is_positioned() && el->src_el()->css().get_z_index() == zindex)
                    {
                        if (el->src_el()->css().get_position() == element_position_fixed)
                        {
                            position browser_wnd;
                            doc->container()->get_client_rect(browser_wnd);

                            el->src_el()->draw(hdc, browser_wnd.p(), clip, el);
                            el->draw_stacking_context(hdc, browser_wnd.p(), clip, true);
                        }
                        else
                        {
                            el->src_el()->draw(hdc, pos.p(), clip, el);
                            el->draw_stacking_context(hdc, pos.p(), clip, true);
                        }
                        process = false;
                    }
                    break;
                case draw_block:
                    if (!el->src_el()->is_inline_box() && el->src_el()->css().get_float() == float_none && !el->src_el()->is_positioned())
                    {
                        el->src_el()->draw(hdc, pos.p(), clip, el);
                    }
                    break;
                case draw_floats:
                    if (el->src_el()->css().get_float() != float_none && !el->src_el()->is_positioned())
                    {
                        el->src_el()->draw(hdc, pos.p(), clip, el);
                        el->draw_stacking_context(hdc, pos.p(), clip, false);
                        process = false;
                    }
                    break;
                case draw_inlines:
                    if (el->src_el()->is_inline_box() && el->src_el()->css().get_float() == float_none && !el->src_el()->is_positioned())
                    {
                        el->src_el()->draw(hdc, pos.p(), clip, el);
                        if (el->src_el()->css().get_display() == display_inline_block)
                        {
                            el->draw_stacking_context(hdc, pos.p(), clip, false);
                            process = false;
                        }
                    }
                    break;
                default:
                    break;
            }

            if (process)
            {
                if (flag == draw_positioned)
                {
                    if (!el->src_el()->is_positioned())
                    {
                        el->draw_children(hdc, pos.p(), clip, flag, zindex);
                    }
                }
                else
                {
                    if (el->src_el()->css().get_float() == float_none &&
                        el->src_el()->css().get_display() != display_inline_block &&
                        !el->src_el()->is_positioned())
                    {
                        el->draw_children(hdc, pos.p(), clip, flag, zindex);
                    }
                }
            }
        }
    }

    if (src_el()->css().get_overflow() > overflow_visible)
    {
        doc->container()->del_clip();
    }
}

std::shared_ptr<litehtml::element>  litehtml::render_item::get_child_by_point(point p, point client_p, draw_flag flag, int zindex)
{
    element::ptr ret = nullptr;

    if(src_el()->css().get_overflow() > overflow_visible)
    {
        if(!m_pos.is_point_inside(p))
        {
            return ret;
        }
    }

    position el_pos = m_pos;
    el_pos.x	= p.x - el_pos.x;
    el_pos.y    = p.y - el_pos.y;
    #if H3ML
    el_pos.z	= p.z - el_pos.z;
    #endif

    for(auto i = m_children.begin(); i != m_children.end() && !ret; std::advance(i, 1))
    {
        auto el = (*i);

        if(el->is_visible() && el->src_el()->css().get_display() != display_inline_text)
        {
            switch(flag)
            {
                case draw_positioned:
                    if(el->src_el()->is_positioned() && el->src_el()->css().get_z_index() == zindex)
                    {
                        if(el->src_el()->css().get_position() == element_position_fixed)
                        {
                            ret = el->get_element_by_point(client_p, client_p);
                            if(!ret && (*i)->is_point_inside(client_p))
                            {
                                ret = (*i)->src_el();
                            }
                        } else
                        {
                            ret = el->get_element_by_point(el_pos.p(), client_p);
                            if(!ret && (*i)->is_point_inside(el_pos.p()))
                            {
                                ret = (*i)->src_el();
                            }
                        }
                        el = nullptr;
                    }
                    break;
                case draw_block:
                    if(!el->src_el()->is_inline_box() && el->src_el()->css().get_float() == float_none && !el->src_el()->is_positioned())
                    {
                        if(el->is_point_inside(el_pos.p()))
                        {
                            ret = el->src_el();
                        }
                    }
                    break;
                case draw_floats:
                    if(el->src_el()->css().get_float() != float_none && !el->src_el()->is_positioned())
                    {
                        ret = el->get_element_by_point(el_pos.p(), client_p);

                        if(!ret && (*i)->is_point_inside(el_pos.p()))
                        {
                            ret = (*i)->src_el();
                        }
                        el = nullptr;
                    }
                    break;
                case draw_inlines:
                    if(el->src_el()->is_inline_box() && el->src_el()->css().get_float() == float_none && !el->src_el()->is_positioned())
                    {
                        if(el->src_el()->css().get_display() == display_inline_block ||
                                el->src_el()->css().get_display() == display_inline_table ||
                                el->src_el()->css().get_display() == display_inline_flex)
                        {
                            ret = el->get_element_by_point(el_pos.p(), client_p);
                            el = nullptr;
                        }
                        if(!ret && (*i)->is_point_inside(el_pos.p()))
                        {
                            ret = (*i)->src_el();
                        }
                    }
                    break;
                default:
                    break;
            }

            if(el && !el->src_el()->is_positioned())
            {
                if(flag == draw_positioned)
                {
                    element::ptr child = el->get_child_by_point(el_pos.p(), client_p, flag, zindex);
                    if(child)
                    {
                        ret = child;
                    }
                } else
                {
                    if(	el->src_el()->css().get_float() == float_none &&
                           el->src_el()->css().get_display() != display_inline_block)
                    {
                        element::ptr child = el->get_child_by_point(el_pos.p(), client_p, flag, zindex);
                        if(child)
                        {
                            ret = child;
                        }
                    }
                }
            }
        }
    }

    return ret;
}

std::shared_ptr<litehtml::element> litehtml::render_item::get_element_by_point(point p, point client_p)
{
    if(!is_visible()) return nullptr;

    element::ptr ret;

    std::map<int, bool> z_indexes;

    for(const auto& i : m_positioned)
    {
        z_indexes[i->src_el()->css().get_z_index()];
    }

    for(const auto& zindex : z_indexes)
    {
        if(zindex.first > 0)
        {
            ret = get_child_by_point(p, client_p, draw_positioned, zindex.first);
            break;
        }
    }
    if(ret) return ret;

    for(const auto& z_index : z_indexes)
    {
        if(z_index.first == 0)
        {
            ret = get_child_by_point(p, client_p, draw_positioned, z_index.first);
            break;
        }
    }
    if(ret) return ret;

    ret = get_child_by_point(p, client_p, draw_inlines, 0);
    if(ret) return ret;

    ret = get_child_by_point(p, client_p, draw_floats, 0);
    if(ret) return ret;

    ret = get_child_by_point(p, client_p, draw_block, 0);
    if(ret) return ret;


    for(const auto& z_index : z_indexes)
    {
        if(z_index.first < 0)
        {
            ret = get_child_by_point(p, client_p, draw_positioned, z_index.first);
            break;
        }
    }
    if(ret) return ret;

    if(src_el()->css().get_position() == element_position_fixed)
    {
        if(is_point_inside(client_p))
        {
            ret = src_el();
        }
    } else
    {
        if(is_point_inside(p))
        {
            ret = src_el();
        }
    }

    return ret;
}

bool litehtml::render_item::is_point_inside( point p )
{
	if(src_el()->css().get_display() != display_inline && src_el()->css().get_display() != display_table_row)
	{
		position pos = m_pos;
		pos += m_padding;
		pos += m_borders;
		if(pos.is_point_inside(p))
		{
			return true;
		} else
		{
			return false;
		}
	} else
	{
		position::vector boxes;
		get_inline_boxes(boxes);
		for(auto & box : boxes)
		{
			if(box.is_point_inside(p))
			{
				return true;
			}
		}
	}
    return false;
}

void litehtml::render_item::get_rendering_boxes( position::vector& redraw_boxes)
{
    if(src_el()->css().get_display() == display_inline || src_el()->css().get_display() == display_table_row)
    {
        position::vector boxes;
        get_inline_boxes(boxes);
        for(auto & box : boxes)
        {
            redraw_boxes.push_back(box);
        }
    } else
    {
        position pos = m_pos;
        pos += m_padding;
        pos += m_borders;
        redraw_boxes.push_back(pos);
    }

    if(src_el()->css().get_position() != element_position_fixed)
    {
        auto cur_el = parent();
        while(cur_el)
        {
            for(auto& box : redraw_boxes)
            {
                box.x += cur_el->m_pos.x;
                box.y += cur_el->m_pos.y;
                #if H3ML
                box.z += cur_el->m_pos.z;
                #endif
            }
            cur_el = cur_el->parent();
        }
    }
}

void litehtml::render_item::dump(litehtml::dumper& cout)
{
    cout.begin_node(src_el()->dump_get_name() + "{" + string(typeid(*this).name()) + "}");

    auto attrs = src_el()->dump_get_attrs();
    if(!attrs.empty())
    {
        cout.begin_attrs_group("attributes");
        for (const auto &attr: attrs)
        {
            cout.add_attr(std::get<0>(attr), std::get<1>(attr));
        }
        cout.end_attrs_group();
    }

    if(!m_children.empty())
    {
        cout.begin_attrs_group("children");
        for (const auto &el: m_children)
        {
            el->dump(cout);
        }
        cout.end_attrs_group();
    }

    cout.end_node();
}

litehtml::position litehtml::render_item::get_placement() const
{
	litehtml::position pos = m_pos;
	auto cur_el = parent();
	while(cur_el)
	{
		pos.x += cur_el->m_pos.x;
		pos.y += cur_el->m_pos.y;
        #if H3ML
        pos.z += cur_el->m_pos.z;
        #endif
		cur_el = cur_el->parent();
	}
	return pos;
}

std::shared_ptr<litehtml::render_item> litehtml::render_item::init()
{
    src_el()->add_render(shared_from_this());

    for(auto& el : children())
    {
        el = el->init();
    }

    return shared_from_this();
}
