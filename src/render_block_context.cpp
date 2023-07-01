#include "html.h"
#include "render_block_context.h"
#include "document.h"

int litehtml::render_item_block_context::_render_content(point p, bool second_pass, const containing_block_context &self_size, formatting_context* fmt_ctx)
{
    element_position el_position;

	int ret_width = 0;
    int child_top = 0;
    int last_margin_bottom = 0;
	std::shared_ptr<render_item> last_margin_el;
    bool is_first = true;
    #if H3ML
    int child_back = 0;
    int last_margin_front = 0;
    #endif
    for (const auto& el : m_children)
    {
        // we don't need to process absolute and fixed positioned element on the second pass
        if (second_pass)
        {
            el_position = el->src_el()->css().get_position();
            if ((el_position == element_position_absolute || el_position == element_position_fixed)) continue;
        }

        if(el->src_el()->css().get_float() != float_none)
        {
            int rw = place_float(el, child_top, self_size, fmt_ctx);
            if (rw > ret_width)
            {
                ret_width = rw;
            }
        } else if(el->src_el()->css().get_display() != display_none)
        {
            if(el->src_el()->css().get_position() == element_position_absolute || el->src_el()->css().get_position() == element_position_fixed)
            {
				int min_rendered_width = el->render(POINT(0, child_top, child_back), self_size, fmt_ctx);
				if(min_rendered_width < el->width() && el->src_el()->css().get_width().is_predefined())
				{
					el->render(POINT(0, child_top, child_back), self_size.new_width(min_rendered_width), fmt_ctx);
				}
            } else
            {
                child_top = fmt_ctx->get_cleared_top(el, child_top);
                int child_x  = 0;
                int child_width = self_size.render_width;

                el->calc_outlines(self_size.width);

                // Collapse top margin
                if(is_first && collapse_top_margin())
                {
                    child_top -= el->get_margins().top;
                    if(el->get_margins().top > get_margins().top)
                    {
                        m_margins.top = el->get_margins().top;
                    }
                } else
                {
                    if(last_margin_bottom > el->get_margins().top)
                    {
                        child_top -= el->get_margins().top;
                    } else
                    {
                        child_top -= last_margin_bottom;
                    }
                }

                #if H3ML
                // Collapse back margin
                if (is_first && collapse_back_margin())
                {
                    child_back -= el->get_margins().back;
                    if (el->get_margins().back > get_margins().back)
                    {
                        m_margins.back = el->get_margins().back;
                    }
                }
                else
                {
                    if (last_margin_front > el->get_margins().back)
                    {
                        child_back -= el->get_margins().back;
                    }
                    else
                    {
                        child_back -= last_margin_front;
                    }
                }
                #endif

                if(el->src_el()->is_replaced() || el->src_el()->is_block_formatting_context() || el->src_el()->css().get_display() == display_table)
                {
                    int ln_left = 0;
                    int ln_right = child_width;
                    fmt_ctx->get_line_left_right(child_top, child_width, ln_left, ln_right);
                    child_x = ln_left;
                    child_width = ln_right - ln_left;

                    auto el_parent = el->parent();
                    el->pos().width = el->src_el()->css().get_width().calc_percent(child_width);
                    el->pos().height = el->src_el()->css().get_height().calc_percent(el_parent ? el_parent->pos().height : 0);
                    #if H3ML
                    el->pos().depth = el->src_el()->css().get_depth().calc_percent(el_parent ? el_parent->pos().depth : 0);
                    #endif
                }

                int rw = el->render(POINT(child_x, child_top, child_back), self_size.new_width(child_width), fmt_ctx);
				// Render table with "width: auto" into returned width
				if(el->src_el()->css().get_display() == display_table && rw < child_width && el->src_el()->css().get_width().is_predefined())
				{
					el->render(POINT(child_x, child_top, child_back), self_size.new_width(rw), fmt_ctx);
				}
				int auto_margin = el->calc_auto_margins(child_width);
				if(auto_margin)
				{
					el->pos().x += auto_margin;
				}
                if (rw > ret_width)
                {
                    ret_width = rw;
                }
                child_top += el->height();
                last_margin_bottom = el->get_margins().bottom;
                #if H3ML
                child_back += el->depth();
                last_margin_front = el->get_margins().front;
                #endif
				last_margin_el = el;
                is_first = false;

                if (el->src_el()->css().get_position() == element_position_relative)
                {
                    el->apply_relative_shift(self_size);
                }
            }
        }
    }

    int block_height = 0;
    if (get_predefined_height(block_height, self_size.height))
    {
        m_pos.height = block_height;
    } else
    {
        m_pos.height = child_top;
        if(collapse_bottom_margin())
        {
            m_pos.height -= last_margin_bottom;
            if(m_margins.bottom < last_margin_bottom)
            {
                m_margins.bottom = last_margin_bottom;
            }
			if(last_margin_el)
			{
				last_margin_el->get_margins().bottom = 0;
			}
        }
    }

    #if H3ML
    int block_depth = 0;
    if (get_predefined_depth(block_depth, self_size.depth))
    {
        m_pos.depth = block_depth;
    } else
    {
        m_pos.depth = child_back;
        if(collapse_front_margin())
        {
            m_pos.depth -= last_margin_front;
            if(m_margins.front < last_margin_front)
            {
                m_margins.front = last_margin_front;
            }
			if(last_margin_el)
			{
				last_margin_el->get_margins().front = 0;
			}
        }
    }
    #endif

    return ret_width;
}
