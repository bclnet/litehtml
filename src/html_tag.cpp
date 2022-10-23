#include "html.h"
#include "html_tag.h"
#include "document.h"
#include "iterators.h"
#include "stylesheet.h"
#include "table.h"
#include <algorithm>
#include <locale>
#include "el_before_after.h"
#include "num_cvt.h"
#include "line_box.h"
#include <stack>
#include "render_item.h"

litehtml::html_tag::html_tag(const std::shared_ptr<document>& doc) : element(doc)
{
}

bool litehtml::html_tag::appendChild(const element::ptr &el)
{
	if(el)
	{
		el->parent(shared_from_this());
		m_children.push_back(el);
		return true;
	}
	return false;
}

bool litehtml::html_tag::removeChild(const element::ptr &el)
{
	if(el && el->parent() == shared_from_this())
	{
		el->parent(nullptr);
		m_children.erase(std::remove(m_children.begin(), m_children.end(), el), m_children.end());
		return true;
	}
	return false;
}

void litehtml::html_tag::clearRecursive()
{
	for(auto& el : m_children)
	{
		el->clearRecursive();
		el->parent(nullptr);
	}
	m_children.clear();
}


const char* litehtml::html_tag::get_tagName() const
{
	return m_tag.c_str();
}

void litehtml::html_tag::set_attr( const char* name, const char* val )
{
	if(name && val)
	{
		string s_val = name;
		for(char& i : s_val)
		{
			i = std::tolower(i, std::locale::classic());
		}
		m_attrs[s_val] = val;

		if( t_strcasecmp( name, "class" ) == 0 )
		{
			m_class_values.resize( 0 );
			split_string( val, m_class_values, " " );
		}
		
		// event
		if(t_strncasecmp(name, "on", 2) == 0)
		{
			document::ptr doc = get_document();
			if (doc->script())
			{
				// doc->script()->addEvent(shared_from_this(), name, m_text);
			}
		}
	}
}

const char* litehtml::html_tag::get_attr( const char* name, const char* def ) const
{
	auto attr = m_attrs.find(name);
	if(attr != m_attrs.end())
	{
		return attr->second.c_str();
	}
	return def;
}

litehtml::elements_vector litehtml::html_tag::select_all( const string& selector )
{
	css_selector sel(media_query_list::ptr(nullptr), "");
	sel.parse(selector);
	
	return select_all(sel);
}

litehtml::elements_vector litehtml::html_tag::select_all( const css_selector& selector )
{
	litehtml::elements_vector res;
	select_all(selector, res);
	return res;
}

void litehtml::html_tag::select_all(const css_selector& selector, elements_vector& res)
{
	if(select(selector))
	{
		res.push_back(shared_from_this());
	}
	
	for(auto& el : m_children)
	{
		el->select_all(selector, res);
	}
}


litehtml::element::ptr litehtml::html_tag::select_one( const string& selector )
{
	css_selector sel(media_query_list::ptr(nullptr), "");
	sel.parse(selector);

	return select_one(sel);
}

litehtml::element::ptr litehtml::html_tag::select_one( const css_selector& selector )
{
	if(select(selector))
	{
		return shared_from_this();
	}

	for(auto& el : m_children)
	{
		element::ptr res = el->select_one(selector);
		if(res)
		{
			return res;
		}
	}
	return nullptr;
}

void litehtml::html_tag::apply_stylesheet( const litehtml::css& stylesheet )
{
	//: remove_before_after();

	for(const auto& sel : stylesheet.selectors())
	{
		int apply = select(*sel, false);

		if(apply != select_no_match)
		{
			used_selector::ptr us = std::unique_ptr<used_selector>(new used_selector(sel, false));

			if(sel->is_media_valid())
			{
				if(apply & select_match_pseudo_class)
				{
					if(select(*sel, true))
					{
						if(apply & select_match_with_after)
						{
							element::ptr el = get_element_after(sel->m_style, sel->m_baseurl, true);
							if(el)
							{
								el->add_style(sel->m_style, sel->m_baseurl);
							}
						} else if(apply & select_match_with_before)
						{
							element::ptr el = get_element_before(sel->m_style, sel->m_baseurl, true);
							if(el)
							{
								el->add_style(sel->m_style, sel->m_baseurl);
							}
						}
						else
						{
							add_style(sel->m_style, sel->m_baseurl);
							us->m_used = true;
						}
					}
				} else if(apply & select_match_with_after)
				{
					element::ptr el = get_element_after(sel->m_style, sel->m_baseurl, true);
					if(el)
					{
						el->add_style(sel->m_style, sel->m_baseurl);
					}
				} else if(apply & select_match_with_before)
				{
					element::ptr el = get_element_before(sel->m_style, sel->m_baseurl, true);
					if(el)
					{
						el->add_style(sel->m_style, sel->m_baseurl);
					}
				} else
				{
					add_style(sel->m_style, sel->m_baseurl);
					us->m_used = true;
				}
			}
			m_used_styles.push_back(std::move(us));
		}
	}

	for(auto& el : m_children)
	{
		if(el->css().get_display() != display_inline_text)
		{
			el->apply_stylesheet(stylesheet);
		}
	}
}

void litehtml::html_tag::get_content_size( size& sz, int max_width )
{
	sz.height	= 0;
	if(m_css.get_display() == display_block)
	{
		sz.width	= max_width;
	} else
	{
		sz.width	= 0;
	}
	#if H3ML
	sz.depth = 0;
	#endif
}

void litehtml::html_tag::draw(uint_ptr hdc, point p, const position *clip, const std::shared_ptr<render_item> &ri)
{
	position pos = ri->pos();
	pos.x += p.x;
	pos.y += p.y;
#if H3ML
	pos.z += p.z;
#endif

    draw_background(hdc, p, clip, ri);

	if(m_css.get_display() == display_list_item && m_css.get_list_style_type() != list_style_type_none)
	{
		if(m_css.get_overflow() > overflow_visible)
		{
			position border_box = pos;
			border_box += ri->get_paddings();
			border_box += ri->get_borders();

			border_radiuses bdr_radius = m_css.get_borders().radius.calc_percents(border_box.sz());

			bdr_radius -= ri->get_borders();
			bdr_radius -= ri->get_paddings();

			get_document()->container()->set_clip(pos, bdr_radius, true, true);
		}

		draw_list_marker(hdc, pos);

		if(m_css.get_overflow() > overflow_visible)
		{
			get_document()->container()->del_clip();
		}
	}
}

const char* litehtml::html_tag::get_style_property( const char* name, bool inherited, const char* def /*= 0*/ ) const
{
	const char* ret = m_style.get_property(name);
	element::ptr el_parent = parent();
	if (el_parent)
	{
		if ( ( ret && !t_strcasecmp(ret, "inherit") ) || (!ret && inherited) )
		{
			ret = el_parent->get_style_property(name, inherited, def);
		}
	}

	if(!ret)
	{
		ret = def;
	}

	return ret;
}

void litehtml::html_tag::parse_styles(bool is_reparse)
{
	const char* style = get_attr("style");

	if(style)
	{
		m_style.add(style, nullptr, this);
	}

    document::ptr doc = get_document();
    m_css.parse(shared_from_this(), doc);

	if(!is_reparse)
	{
        for(const auto& el : m_children)
        {
            el->parse_styles();
        }
	}
}

bool litehtml::html_tag::is_white_space() const
{
	return false;
}

int litehtml::html_tag::select(const css_selector& selector, bool apply_pseudo)
{
	int right_res = select(selector.m_right, apply_pseudo);
	if(right_res == select_no_match)
	{
		return select_no_match;
	}
	element::ptr el_parent = parent();
	if(selector.m_left)
	{
		if (!el_parent)
		{
			return select_no_match;
		}
		switch(selector.m_combinator)
		{
		case combinator_descendant:
			{
				bool is_pseudo = false;
				element::ptr res = find_ancestor(*selector.m_left, apply_pseudo, &is_pseudo);
				if(!res)
				{
					return select_no_match;
				} else
				{
					if(is_pseudo)
					{
						right_res |= select_match_pseudo_class;
					}
				}
			}
			break;
		case combinator_child:
			{
				int res = el_parent->select(*selector.m_left, apply_pseudo);
				if(res == select_no_match)
				{
					return select_no_match;
				} else
				{
					if(right_res != select_match_pseudo_class)
					{
						right_res |= res;
					}
				}
			}
			break;
		case combinator_adjacent_sibling:
			{
				bool is_pseudo = false;
				element::ptr res = el_parent->find_adjacent_sibling(shared_from_this(), *selector.m_left, apply_pseudo, &is_pseudo);
				if(!res)
				{
					return select_no_match;
				} else
				{
					if(is_pseudo)
					{
						right_res |= select_match_pseudo_class;
					}
				}
			}
			break;
		case combinator_general_sibling:
			{
				bool is_pseudo = false;
				element::ptr res =  el_parent->find_sibling(shared_from_this(), *selector.m_left, apply_pseudo, &is_pseudo);
				if(!res)
				{
					return select_no_match;
				} else
				{
					if(is_pseudo)
					{
						right_res |= select_match_pseudo_class;
					}
				}
			}
			break;
		default:
			right_res = select_no_match;
		}
	}
	return right_res;
}

int litehtml::html_tag::select(const css_element_selector& selector, bool apply_pseudo)
{
	if(!selector.m_tag.empty() && selector.m_tag != "*")
	{
		if(selector.m_tag != m_tag)
		{
			return select_no_match;
		}
	}

	int res = select_match;
	element::ptr el_parent = parent();

	for(const auto& attr : selector.m_attrs)
	{
		const char* attr_value = get_attr(attr.attribute.c_str());
		switch(attr.condition)
		{
		case select_exists:
			if(!attr_value)
			{
				return select_no_match;
			}
			break;
		case select_equal:
			if(!attr_value)
			{
				return select_no_match;
			} else 
			{
				if(attr.attribute == "class")
				{
					const string_vector & tokens1 = m_class_values;
					const string_vector & tokens2 = attr.class_val;
					bool found = true;
					for(const auto& str1 : tokens2)
					{
						bool f = false;
						for(const auto& str2 : tokens1)
						{
							if( !t_strcasecmp(str1.c_str(), str2.c_str()) )
							{
								f = true;
							}
						}
						if(!f)
						{
							found = false;
						}
					}
					if(!found)
					{
						return select_no_match;
					}
				} else
				{
					if( t_strcasecmp(attr.val.c_str(), attr_value) )
					{
						return select_no_match;
					}
				}
			}
			break;
		case select_contain_str:
			if(!attr_value || !strstr(attr_value, attr.val.c_str()))
			{
				return select_no_match;
			}
			break;
		case select_start_str:
			if(!attr_value || strncmp(attr_value, attr.val.c_str(), attr.val.length()))
			{
				return select_no_match;
			}
			break;
		case select_end_str:
			if(!attr_value)
			{
				return select_no_match;
			} else if(strncmp(attr_value, attr.val.c_str(), attr.val.length()))
			{
				const char* s = attr_value + strlen(attr_value) - attr.val.length() - 1;
				if(s < attr_value)
				{
					return select_no_match;
				}
				if(attr.val != s)
				{
					return select_no_match;
				}
			}
			break;
		case select_pseudo_element:
			if(attr.val == "after")
			{
				res |= select_match_with_after;
			} else if(attr.val == "before")
			{
				res |= select_match_with_before;
			} else
			{
				return select_no_match;
			}
			break;
		case select_pseudo_class:
			if(apply_pseudo)
			{
				//: if (!el_parent) return select_no_match;

				string selector_param;
				string selector_name;

				string::size_type begin	= attr.val.find_first_of('(');
				string::size_type end	= (begin == string::npos) ? string::npos : find_close_bracket(attr.val, begin);
				if(begin != string::npos && end != string::npos)
				{
					selector_param = attr.val.substr(begin + 1, end - begin - 1);
				}
				if(begin != string::npos)
				{
					selector_name = attr.val.substr(0, begin);
					litehtml::trim(selector_name);
				} else
				{
					selector_name = attr.val;
				}

				int pseudo_selector = value_index(selector_name, pseudo_class_strings);
				
				switch(pseudo_selector)
				{
				case pseudo_class_only_child:
					if (!el_parent || !el_parent->is_only_child(shared_from_this(), false))
					{
						return select_no_match;
					}
					break;
				case pseudo_class_only_of_type:
					if (!el_parent || !el_parent->is_only_child(shared_from_this(), true))
					{
						return select_no_match;
					}
					break;
				case pseudo_class_first_child:
					if (!el_parent || !el_parent->is_nth_child(shared_from_this(), 0, 1, false))
					{
						return select_no_match;
					}
					break;
				case pseudo_class_first_of_type:
					if (!el_parent || !el_parent->is_nth_child(shared_from_this(), 0, 1, true))
					{
						return select_no_match;
					}
					break;
				case pseudo_class_last_child:
					if (!el_parent || !el_parent->is_nth_last_child(shared_from_this(), 0, 1, false))
					{
						return select_no_match;
					}
					break;
				case pseudo_class_last_of_type:
					if (!el_parent || !el_parent->is_nth_last_child(shared_from_this(), 0, 1, true))
					{
						return select_no_match;
					}
					break;
				case pseudo_class_nth_child:
				case pseudo_class_nth_of_type:
				case pseudo_class_nth_last_child:
				case pseudo_class_nth_last_of_type:
					{
						if(!el_parent || selector_param.empty()) return select_no_match;

						int num = 0;
						int off = 0;

						parse_nth_child_params(selector_param, num, off);
						if(!num && !off) return select_no_match;
						switch(pseudo_selector)
						{
						case pseudo_class_nth_child:
							if (!el_parent->is_nth_child(shared_from_this(), num, off, false))
							{
								return select_no_match;
							}
							break;
						case pseudo_class_nth_of_type:
							if (!el_parent->is_nth_child(shared_from_this(), num, off, true))
							{
								return select_no_match;
							}
							break;
						case pseudo_class_nth_last_child:
							if (!el_parent->is_nth_last_child(shared_from_this(), num, off, false))
							{
								return select_no_match;
							}
							break;
						case pseudo_class_nth_last_of_type:
							if (!el_parent->is_nth_last_child(shared_from_this(), num, off, true))
							{
								return select_no_match;
							}
							break;
						}

					}
					break;
				case pseudo_class_not:
					{
						css_element_selector sel;
						sel.parse(selector_param);
						if(select(sel, apply_pseudo))
						{
							return select_no_match;
						}
					}
					break;
				case pseudo_class_lang:
					{
						trim( selector_param );

						if( !get_document()->match_lang( selector_param ) )
						{
							return select_no_match;
						}
					}
					break;
				default:
					if(std::find(m_pseudo_classes.begin(), m_pseudo_classes.end(), attr.val) == m_pseudo_classes.end())
					{
						return select_no_match;
					}
					break;
				}
			} else
			{
				res |= select_match_pseudo_class;
			}
			break;
		}
	}
	return res;
}

litehtml::element::ptr litehtml::html_tag::find_ancestor(const css_selector& selector, bool apply_pseudo, bool* is_pseudo)
{
	element::ptr el_parent = parent();
	if (!el_parent)
	{
		return nullptr;
	}
	int res = el_parent->select(selector, apply_pseudo);
	if(res != select_no_match)
	{
		if(is_pseudo)
		{
			if(res & select_match_pseudo_class)
			{
				*is_pseudo = true;
			} else
			{
				*is_pseudo = false;
			}
		}
		return el_parent;
	}
	return el_parent->find_ancestor(selector, apply_pseudo, is_pseudo);
}

void litehtml::html_tag::parse_attributes()
{
	for(auto& el : m_children)
	{
		el->parse_attributes();
	}
}

void litehtml::html_tag::get_text( string& text )
{
	for (auto& el : m_children)
	{
		el->get_text(text);
	}
}

bool litehtml::html_tag::is_body()  const
{
	return false;
}

void litehtml::html_tag::set_data(const char* /*data*/)
{
}

bool litehtml::html_tag::on_mouse_over()
{
	bool ret = false;

	element::ptr el = shared_from_this();
	while(el)
	{
		if(el->set_pseudo_class("hover", true))
		{
			ret = true;
		}
		el = el->parent();
	}

	return ret;
}

bool litehtml::html_tag::on_mouse_leave()
{
	bool ret = false;

	element::ptr el = shared_from_this();
	while(el)
	{
		if(el->set_pseudo_class("hover", false))
		{
			ret = true;
		}
		if(el->set_pseudo_class("active", false))
		{
			ret = true;
		}
		el = el->parent();
	}

	return ret;
}

bool litehtml::html_tag::on_lbutton_down()
{
    bool ret = false;

	element::ptr el = shared_from_this();
    while (el)
    {
        if (el->set_pseudo_class("active", true))
        {
            ret = true;
        }
        el = el->parent();
    }

    return ret;
}

bool litehtml::html_tag::on_lbutton_up()
{
	bool ret = false;

	element::ptr el = shared_from_this();
    while (el)
    {
        if (el->set_pseudo_class("active", false))
        {
            ret = true;
        }
        el = el->parent();
    }

    on_click();

	return ret;
}

void litehtml::html_tag::on_click()
{
	if (have_parent())
	{
		element::ptr el_parent = parent();
		if (el_parent)
		{
			el_parent->on_click();
		}
	}
}

const char* litehtml::html_tag::get_cursor()
{
	return get_style_property("cursor", true, nullptr);
}

bool litehtml::html_tag::is_break() const
{
	return false;
}

void litehtml::html_tag::set_tagName( const char* tag )
{
	m_tag = tag;
	for (char& i : m_tag)
	{
		i = std::tolower(i, std::locale::classic());
	}
}

void litehtml::html_tag::draw_background(uint_ptr hdc, point p, const position *clip,
                                         const std::shared_ptr<render_item> &ri)
{
	position pos = ri->pos();
	pos.x += p.x;
	pos.y += p.y;
	#if H3ML
	pos.z += p.z;
	#endif

	position el_pos = pos;
	el_pos += ri->get_paddings();
	el_pos += ri->get_margins();

	if(m_css.get_display() != display_inline && m_css.get_display() != display_table_row)
	{
		if(el_pos.does_intersect(clip))
		{
            auto v_offset = ri->get_draw_vertical_offset();
            pos.y += v_offset;
            pos.height -= v_offset;

			const background* bg = get_background();
			if(bg)
			{
				background_paint bg_paint;
				init_background_paint(pos, bg_paint, bg, ri);

				get_document()->container()->draw_background(hdc, bg_paint);
			}
			position border_box = pos;
			border_box += ri->get_paddings();
			border_box += ri->get_borders();

			borders bdr = m_css.get_borders();
            if(bdr.is_visible())
            {
                bdr.radius = m_css.get_borders().radius.calc_percents(border_box.sz());
                get_document()->container()->draw_borders(hdc, bdr, border_box, !have_parent());
            }
		}
	} else
	{
		const background* bg = get_background();

		position::vector boxes;
		ri->get_inline_boxes(boxes);

		background_paint bg_paint;
		position content_box;

		for(auto box = boxes.begin(); box != boxes.end(); box++)
		{
			box->x	+= p.x;
			box->y	+= p.y;
			#if H3ML
			box->z	+= p.z;
			#endif

			if(box->does_intersect(clip))
			{
				content_box = *box;
				content_box -= ri->get_borders();
				content_box -= ri->get_paddings();

				if(bg)
				{
					init_background_paint(content_box, bg_paint, bg, ri);
				}

				css_borders bdr;

				// set left borders radius for the first box
				if(box == boxes.begin())
				{
					bdr.radius.bottom_left_x	= m_css.get_borders().radius.bottom_left_x;
					bdr.radius.bottom_left_y	= m_css.get_borders().radius.bottom_left_y;
					#if H3ML
					bdr.radius.bottom_left_z 	= m_css.get_borders().radius.bottom_left_z;
					#endif
					bdr.radius.top_left_x		= m_css.get_borders().radius.top_left_x;
					bdr.radius.top_left_y		= m_css.get_borders().radius.top_left_y;
					#if H3ML
					bdr.radius.top_left_z		= m_css.get_borders().radius.top_left_z;
					#endif
				}

				// set right borders radius for the last box
				if(box == boxes.end() - 1)
				{
					bdr.radius.bottom_right_x	= m_css.get_borders().radius.bottom_right_x;
					bdr.radius.bottom_right_y	= m_css.get_borders().radius.bottom_right_y;
					#if H3ML
					bdr.radius.bottom_right_z 	= m_css.get_borders().radius.bottom_right_z;
					#endif
					bdr.radius.top_right_x		= m_css.get_borders().radius.top_right_x;
					bdr.radius.top_right_y		= m_css.get_borders().radius.top_right_y;
					#if H3ML
					bdr.radius.top_right_z 		= m_css.get_borders().radius.top_right_z;
					#endif
				}

				
				bdr.top		= m_css.get_borders().top;
				bdr.bottom	= m_css.get_borders().bottom;
				if(box == boxes.begin())
				{
					bdr.left	= m_css.get_borders().left;
				}
				if(box == boxes.end() - 1)
				{
					bdr.right	= m_css.get_borders().right;
				}

				if(bg)
				{
					bg_paint.border_radius = bdr.radius.calc_percents(bg_paint.border_box.sz());
					get_document()->container()->draw_background(hdc, bg_paint);
				}
                if(bdr.is_visible())
                {
                    borders b = bdr;
                    b.radius = bdr.radius.calc_percents(box->sz());
                    get_document()->container()->draw_borders(hdc, b, *box, false);
                }
            }
		}
	}
}

bool litehtml::html_tag::set_pseudo_class( const char* pclass, bool add )
{
    if(m_tag == "a")
    {
        int i = 0;
        i++;
    }
	bool ret = false;
	if(add)
	{
		if(std::find(m_pseudo_classes.begin(), m_pseudo_classes.end(), pclass) == m_pseudo_classes.end())
		{
			m_pseudo_classes.push_back(pclass);
			ret = true;
		}
	} else
	{
		auto pi = std::find(m_pseudo_classes.begin(), m_pseudo_classes.end(), pclass);
		if(pi != m_pseudo_classes.end())
		{
			m_pseudo_classes.erase(pi);
			ret = true;
		}
	}
	return ret;
}

bool litehtml::html_tag::set_class( const char* pclass, bool add )
{
	string_vector classes;
	bool changed = false;

	split_string( pclass, classes, " " );

	if(add)
	{
		for( auto & _class : classes  )
		{
			if(std::find(m_class_values.begin(), m_class_values.end(), _class) == m_class_values.end())
			{
				m_class_values.push_back( std::move( _class ) );
				changed = true;
			}
		}
	} else
	{
		for( const auto & _class : classes )
		{
			auto end = std::remove(m_class_values.begin(), m_class_values.end(), _class);

			if(end != m_class_values.end())
			{
				m_class_values.erase(end, m_class_values.end());
				changed = true;
			}
		}
	}

	if( changed )
	{
		string class_string;
		join_string(class_string, m_class_values, " ");
		set_attr("class", class_string.c_str());

		return true;
	}
	else
	{
		return false;
	}

}

bool litehtml::html_tag::is_replaced() const
{
	return false;
}

bool litehtml::html_tag::is_floats_holder() const
{
	if(	m_css.get_display() == display_inline_block || 
		m_css.get_display() == display_table_cell || 
		!have_parent() ||
		is_body() || 
		m_css.get_float() != float_none ||
		m_css.get_position() == element_position_absolute ||
		m_css.get_position() == element_position_fixed ||
		m_css.get_overflow() > overflow_visible)
	{
		return true;
	}
	return false;
}

size_t litehtml::html_tag::get_children_count() const
{
	return m_children.size();
}

litehtml::element::ptr litehtml::html_tag::get_child( int idx ) const
{
	return m_children[idx];
}


void litehtml::html_tag::init_background_paint(position pos, background_paint &bg_paint, const background* bg, const std::shared_ptr<render_item> &ri)
{
	if(!bg) return;

	bg_paint = *bg;
	position content_box	= pos;
	position padding_box	= pos;
	padding_box += ri->get_paddings();
	position border_box		= padding_box;
	border_box += ri->get_borders();

	switch(bg->m_clip)
	{
	case litehtml::background_box_padding:
		bg_paint.clip_box = padding_box;
		break;
	case litehtml::background_box_content:
		bg_paint.clip_box = content_box;
		break;
	default:
		bg_paint.clip_box = border_box;
		break;
	}

	switch(bg->m_origin)
	{
	case litehtml::background_box_border:
		bg_paint.origin_box = border_box;
		break;
	case litehtml::background_box_content:
		bg_paint.origin_box = content_box;
		break;
	default:
		bg_paint.origin_box = padding_box;
		break;
	}

	if(!bg_paint.image.empty())
	{
		get_document()->container()->get_image_size(bg_paint.image.c_str(), bg_paint.baseurl.c_str(), nullptr, bg_paint.image_size);
		if(bg_paint.image_size.width && bg_paint.image_size.height)
		{
			litehtml::size img_new_sz = bg_paint.image_size;
			double img_ar_width		= (double) bg_paint.image_size.width / (double) bg_paint.image_size.height;
			double img_ar_height	= (double) bg_paint.image_size.height / (double) bg_paint.image_size.width;

			if(bg->m_position.width.is_predefined())
			{
				switch(bg->m_position.width.predef())
				{
				case litehtml::background_size_contain:
					if( (int) ((double) bg_paint.origin_box.width * img_ar_height) <= bg_paint.origin_box.height )
					{
						img_new_sz.width = bg_paint.origin_box.width;
						img_new_sz.height	= (int) ((double) bg_paint.origin_box.width * img_ar_height);
						#if H3ML
						img_new_sz.depth 	= 0;
						#endif
					} else
					{
						img_new_sz.height = bg_paint.origin_box.height;
						img_new_sz.width	= (int) ((double) bg_paint.origin_box.height * img_ar_width);
						#if H3ML
						img_new_sz.depth 	= 0;
						#endif
					}
					break;
				case litehtml::background_size_cover:
					if( (int) ((double) bg_paint.origin_box.width * img_ar_height) >= bg_paint.origin_box.height )
					{
						img_new_sz.width = bg_paint.origin_box.width;
						img_new_sz.height	= (int) ((double) bg_paint.origin_box.width * img_ar_height);
						#if H3ML
						img_new_sz.depth 	= 0;
						#endif
					} else
					{
						img_new_sz.height = bg_paint.origin_box.height;
						img_new_sz.width	= (int) ((double) bg_paint.origin_box.height * img_ar_width);
						#if H3ML
						img_new_sz.depth 	= 0;
						#endif
					}
					break;
				case litehtml::background_size_auto:
					if(!bg->m_position.height.is_predefined())
					{
						img_new_sz.height	= bg->m_position.height.calc_percent(bg_paint.origin_box.height);
						img_new_sz.width	= (int) ((double) img_new_sz.height * img_ar_width);
						#if H3ML
						img_new_sz.depth 	= 0;
						#endif
					}
					break;
				}
			} else
			{
				img_new_sz.width = bg->m_position.width.calc_percent(bg_paint.origin_box.width);
				if(bg->m_position.height.is_predefined())
				{
					img_new_sz.height = (int) ((double) img_new_sz.width * img_ar_height);
				} else
				{
					img_new_sz.height = bg->m_position.height.calc_percent(bg_paint.origin_box.height);
				}
				#if H3ML
				img_new_sz.depth = 0;
				#endif
			}

			bg_paint.image_size = img_new_sz;
			bg_paint.position.x = bg_paint.origin_box.x + (int) bg->m_position.x.calc_percent(bg_paint.origin_box.width - bg_paint.image_size.width);
			bg_paint.position.y = bg_paint.origin_box.y + (int) bg->m_position.y.calc_percent(bg_paint.origin_box.height - bg_paint.image_size.height);
			#if H3ML
			bg_paint.position.z = bg_paint.origin_box.z + (int) bg->m_position.z.calc_percent(bg_paint.origin_box.depth - bg_paint.image_size.depth);
			#endif
		}

	}
	bg_paint.border_radius	= m_css.get_borders().radius.calc_percents(border_box.sz());
	bg_paint.border_box		= border_box;
	bg_paint.is_root		= !have_parent();
}

void litehtml::html_tag::draw_list_marker( uint_ptr hdc, const position &pos )
{
	list_marker lm;

	const char* list_image = get_style_property("list-style-image", true, nullptr);
	size img_size;
	if(list_image)
	{
		css::parse_css_url(list_image, lm.image);
		lm.baseurl = get_style_property("list-style-image-baseurl", true, nullptr);
		get_document()->container()->get_image_size(lm.image.c_str(), lm.baseurl, nullptr, img_size);
	} else
	{
		lm.baseurl = nullptr;
	}

	int ln_height	= css().get_line_height();
	int sz_font		= css().get_font_size();
	lm.pos.x		= pos.x;
	lm.pos.width = sz_font - sz_font * 2 / 3;
	lm.color = get_color("color", true, web_color(0, 0, 0));
	lm.marker_type = m_css.get_list_style_type();
	lm.font = css().get_font();

	if (m_css.get_list_style_type() >= list_style_type_armenian)
	{
		lm.pos.y = pos.y;
		lm.pos.height = pos.height;
		lm.index = atoi(get_attr("list_index", "0"));
	}
	else
	{
		lm.pos.height = sz_font - sz_font * 2 / 3;
		lm.pos.y = pos.y + ln_height / 2 - lm.pos.height / 2;
		lm.index = -1;
	}
	#if H3ML
	lm.pos.depth = 0;
	lm.pos.z = pos.z;
	#endif
	
	if(img_size.width && img_size.height)
	{
		if(lm.pos.y + img_size.height > pos.y + pos.height)
		{
			lm.pos.y = pos.y + pos.height - img_size.height;
		}
		if(img_size.width > lm.pos.width)
		{
			lm.pos.x -= img_size.width - lm.pos.width;
		}
		#if H3ML
		if(img_size.depth > lm.pos.depth)
		{
			lm.pos.z -= img_size.depth - lm.pos.depth;
		}
		#endif
		
		lm.pos.width	= img_size.width;
		lm.pos.height	= img_size.height;
		#if H3ML
		lm.pos.depth	= img_size.depth;
		#endif
	}

	if (m_css.get_list_style_position() == list_style_position_outside)
	{
		if (m_css.get_list_style_type() >= list_style_type_armenian)
		{
			auto tw_space = get_document()->container()->text_width(" ", lm.font);
			lm.pos.x = pos.x - tw_space * 2;
			lm.pos.width = tw_space;
		}
		else
		{
			lm.pos.x -= sz_font;
		}
	}

	if (m_css.get_list_style_type() >= list_style_type_armenian)
	{
		auto marker_text = get_list_marker_text(lm.index);
		lm.pos.height = ln_height;
		if (marker_text.empty())
		{
			get_document()->container()->draw_list_marker(hdc, lm);
		}
		else
		{
			marker_text += ".";
			auto tw = get_document()->container()->text_width(marker_text.c_str(), lm.font);
			auto text_pos = lm.pos;
			text_pos.move_to(text_pos.right() - tw, text_pos.y);
			text_pos.width = tw;
			get_document()->container()->draw_text(hdc, marker_text.c_str(), lm.font, lm.color, text_pos);
		}
	}
	else
	{
		get_document()->container()->draw_list_marker(hdc, lm);
	}
}

litehtml::string litehtml::html_tag::get_list_marker_text(int index)
{
	switch (m_css.get_list_style_type())
	{
	case litehtml::list_style_type_decimal:
		return std::to_string(index);
	case litehtml::list_style_type_decimal_leading_zero:
		{
			auto txt = std::to_string(index);
			if (txt.length() == 1)
			{
				txt = "0" + txt;
			}
			return txt;
		}
	case litehtml::list_style_type_lower_latin:
	case litehtml::list_style_type_lower_alpha:
		return num_cvt::to_latin_lower(index);
	case litehtml::list_style_type_lower_greek:
		return num_cvt::to_greek_lower(index);
	case litehtml::list_style_type_upper_alpha:
	case litehtml::list_style_type_upper_latin:
		return num_cvt::to_latin_upper(index);
	case litehtml::list_style_type_lower_roman:
		return num_cvt::to_roman_lower(index);
	case litehtml::list_style_type_upper_roman:
		return num_cvt::to_roman_upper(index);
    default:
        return "";
//	case litehtml::list_style_type_armenian:
//	case litehtml::list_style_type_georgian:
//	case litehtml::list_style_type_hebrew:
//	case litehtml::list_style_type_hiragana:
//	case litehtml::list_style_type_hiragana_iroha:
//	case litehtml::list_style_type_katakana:
//	case litehtml::list_style_type_katakana_iroha:
//  case litehtml::list_style_type_none:
//  case litehtml::list_style_type_circle:
//  case litehtml::list_style_type_disc:
//  case litehtml::list_style_type_square:
//  case litehtml::list_style_type_cjk_ideographic:
//      break;
    }
}

bool litehtml::html_tag::is_nth_child(const element::ptr& el, int num, int off, bool of_type) const
{
	int idx = 1;
	for(const auto& child : m_children)
	{
		if(child->css().get_display() != display_inline_text)
		{
			if( (!of_type) || (of_type && !strcmp(el->get_tagName(), child->get_tagName())) )
			{
				if(el == child)
				{
					if(num != 0)
					{
						if((idx - off) >= 0 && (idx - off) % num == 0)
						{
							return true;
						}

					} else if(idx == off)
					{
						return true;
					}
					return false;
				}
				idx++;
			}
			if(el == child) break;
		}
	}
	return false;
}

bool litehtml::html_tag::is_nth_last_child(const element::ptr& el, int num, int off, bool of_type) const
{
	int idx = 1;
	for(auto child = m_children.rbegin(); child != m_children.rend(); child++)
	{
		if((*child)->css().get_display() != display_inline_text)
		{
			if( !of_type || (of_type && !strcmp(el->get_tagName(), (*child)->get_tagName())) )
			{
				if(el == (*child))
				{
					if(num != 0)
					{
						if((idx - off) >= 0 && (idx - off) % num == 0)
						{
							return true;
						}

					} else if(idx == off)
					{
						return true;
					}
					return false;
				}
				idx++;
			}
			if(el == (*child)) break;
		}
	}
	return false;
}

void litehtml::html_tag::parse_nth_child_params( const string& param, int &num, int &off )
{
	if(param == "odd")
	{
		num = 2;
		off = 1;
	} else if(param == "even")
	{
		num = 2;
		off = 0;
	} else
	{
		string_vector tokens;
		split_string(param, tokens, " n", "n");

		string s_num;
		string s_off;

		string s_int;
		for(const auto& token : tokens)
		{
			if(token == "n")
			{
				s_num = s_int;
				s_int.clear();
			} else
			{
				s_int += token;
			}
		}
		s_off = s_int;

		num = atoi(s_num.c_str());
		off = atoi(s_off.c_str());
	}
}

litehtml::element::ptr litehtml::html_tag::find_adjacent_sibling( const element::ptr& el, const css_selector& selector, bool apply_pseudo /*= true*/, bool* is_pseudo /*= 0*/ )
{
	element::ptr ret;
	for(auto& e : m_children)
	{
		if(e->css().get_display() != display_inline_text)
		{
			if(e == el)
			{
				if(ret)
				{
					int res = ret->select(selector, apply_pseudo);
					if(res != select_no_match)
					{
						if(is_pseudo)
						{
							if(res & select_match_pseudo_class)
							{
								*is_pseudo = true;
							} else
							{
								*is_pseudo = false;
							}
						}
						return ret;
					}
				}
				return nullptr;
			} else
			{
				ret = e;
			}
		}
	}
	return nullptr;
}

litehtml::element::ptr litehtml::html_tag::find_sibling(const element::ptr& el, const css_selector& selector, bool apply_pseudo /*= true*/, bool* is_pseudo /*= 0*/)
{
	element::ptr ret = nullptr;
	for(auto& e : m_children)
	{
		if(e->css().get_display() != display_inline_text)
		{
			if(e == el)
			{
				return ret;
			} else if(!ret)
			{
				int res = e->select(selector, apply_pseudo);
				if(res != select_no_match)
				{
					if(is_pseudo)
					{
						if(res & select_match_pseudo_class)
						{
							*is_pseudo = true;
						} else
						{
							*is_pseudo = false;
						}
					}
					ret = e;
				}
			}
		}
	}
	return nullptr;
}

bool litehtml::html_tag::is_only_child(const element::ptr& el, bool of_type) const
{
	int child_count = 0;
	for(const auto& child : m_children)
	{
		if(child->css().get_display() != display_inline_text)
		{
			if( !of_type || (of_type && !strcmp(el->get_tagName(), child->get_tagName())) )
			{
				child_count++;
			}
			if(child_count > 1) break;
		}
	}
	if(child_count > 1)
	{
		return false;
	}
	return true;
}

litehtml::element::ptr litehtml::html_tag::get_element_before(const string& style, const string& baseurl, bool create)
{
	if(!m_children.empty())
	{
		if( !strcmp(m_children.front()->get_tagName(), "::before") )
		{
			return m_children.front();
		}
	}
    if(create)
    {
        return add_pseudo_before(style, baseurl);
    }
    return nullptr;
}

litehtml::element::ptr litehtml::html_tag::get_element_after(const string& style, const string& baseurl, bool create)
{
	if(!m_children.empty())
	{
		if( !strcmp(m_children.back()->get_tagName(), "::after") )
		{
			return m_children.back();
		}
	}
    if(create)
    {
        return add_pseudo_after(style, baseurl);
    }
    return nullptr;
}

void litehtml::html_tag::add_style(const string& style, const string& baseurl)
{
	m_style.add(style.c_str(), baseurl.c_str(), this);
}

void litehtml::html_tag::refresh_styles()
{
	//: remove_before_after();
	
	for (auto& el : m_children)
	{
		if(el->css().get_display() != display_inline_text)
		{
			el->refresh_styles();
		}
	}

	m_style.clear();

	for (auto& usel : m_used_styles)
	{
		usel->m_used = false;

		if(usel->m_selector->is_media_valid())
		{
			int apply = select(*usel->m_selector, false);

			if(apply != select_no_match)
			{
				if(apply & select_match_pseudo_class)
				{
					if(select(*usel->m_selector, true))
					{
						if(apply & select_match_with_after)
						{
							element::ptr el = get_element_after(usel->m_selector->m_style, usel->m_selector->m_baseurl, false);
							if(el)
							{
								el->add_style(usel->m_selector->m_style, usel->m_selector->m_baseurl);
							}
						} else if(apply & select_match_with_before)
						{
							element::ptr el = get_element_before(usel->m_selector->m_style, usel->m_selector->m_baseurl, false);
							if(el)
							{
								el->add_style(usel->m_selector->m_style, usel->m_selector->m_baseurl);
							}
						}
						else
						{
							add_style(usel->m_selector->m_style, usel->m_selector->m_baseurl);
							usel->m_used = true;
						}
					}
				} else if(apply & select_match_with_after)
				{
					element::ptr el = get_element_after(usel->m_selector->m_style, usel->m_selector->m_baseurl, false);
					if(el)
					{
						el->add_style(usel->m_selector->m_style, usel->m_selector->m_baseurl);
					}
				} else if(apply & select_match_with_before)
				{
					element::ptr el = get_element_before(usel->m_selector->m_style, usel->m_selector->m_baseurl, false);
					if(el)
					{
						el->add_style(usel->m_selector->m_style, usel->m_selector->m_baseurl);
					}
				} else
				{
					add_style(usel->m_selector->m_style, usel->m_selector->m_baseurl);
					usel->m_used = true;
				}
			}
		}
	}
}

const litehtml::background* litehtml::html_tag::get_background(bool own_only)
{
	if(own_only)
	{
		// return own background with check for empty one
		if(m_css.get_bg().m_image.empty() && !m_css.get_bg().m_color.alpha)
		{
			return nullptr;
		}
		return &m_css.get_bg();
	}

	if(m_css.get_bg().m_image.empty() && !m_css.get_bg().m_color.alpha)
	{
		// if this is root element (<html>) try to get background from body
		if (!have_parent())
		{
			for (const auto& el : m_children)
			{
				if( el->is_body() )
				{
					// return own body background
					return el->get_background(true);
				}
			}
		}
		return nullptr;
	}
	
	if(is_body())
	{
		element::ptr el_parent = parent();
		if (el_parent)
		{
			if (!el_parent->get_background(true))
			{
				// parent of body will draw background for body
				return nullptr;
			}
		}
	}

	return &m_css.get_bg();
}

litehtml::string litehtml::html_tag::dump_get_name()
{
    return m_tag.empty()
    	? "anon [html_tag]"
    	: m_tag + " [html_tag]";
}
