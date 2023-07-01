#include "html.h"
#include "style.h"

namespace litehtml
{

std::map<string_id, string> style::m_valid_values =
{
	{ _display_, style_display_strings },
	{ _visibility_, visibility_strings },
	{ _position_, element_position_strings },
	{ _float_, element_float_strings },
	{ _clear_, element_clear_strings },
	{ _overflow_, overflow_strings },
	{ _box_sizing_, box_sizing_strings },

	{ _text_align_, text_align_strings },
	{ _vertical_align_, vertical_align_strings },
	{ _text_transform_, text_transform_strings },
	{ _white_space_, white_space_strings },

	{ _font_style_, font_style_strings },
	{ _font_variant_, font_variant_strings },
	{ _font_weight_, font_weight_strings },

	{ _list_style_type_, list_style_type_strings },
	{ _list_style_position_, list_style_position_strings },

	{ _border_left_style_, border_style_strings },
	{ _border_right_style_, border_style_strings },
	{ _border_top_style_, border_style_strings },
	{ _border_bottom_style_, border_style_strings },
	{ _border_collapse_, border_collapse_strings },
    #if H3ML
    { _border_front_style_, border_style_strings },
	{ _border_back_style_, border_style_strings },
    #endif

	// these 4 properties are comma-separated lists of keywords, see parse_keyword_comma_list
	{ _background_attachment_, background_attachment_strings },
	{ _background_repeat_, background_repeat_strings },
	{ _background_clip_, background_box_strings },
	{ _background_origin_, background_box_strings },

	{ _flex_direction_, flex_direction_strings },
	{ _flex_wrap_, flex_wrap_strings },
	{ _justify_content_, flex_justify_content_strings },
	{ _align_items_, flex_align_items_strings },
	{ _align_content_, flex_align_content_strings },
	{ _align_self_, flex_align_self_strings },
};

void style::parse(const string& txt, const string& baseurl, document_container* container)
{
	std::vector<string> properties;
	split_string(txt, properties, ";", "", "\"'");

	for(const auto & property : properties)
	{
		parse_property(property, baseurl, container);
	}
}

void style::parse_property(const string& txt, const string& baseurl, document_container* container)
{
	string::size_type pos = txt.find_first_of(':');
	if(pos != string::npos)
	{
		string name = txt.substr(0, pos);
		string val	= txt.substr(pos + 1);

		trim(name); lcase(name);
		trim(val);

		if(!name.empty() && !val.empty())
		{
			string_vector vals;
			split_string(val, vals, "!");
			if(vals.size() == 1)
			{
				add_property(_id(name), val, baseurl, false, container);
			} else if(vals.size() > 1)
			{
				trim(vals[0]);
				lcase(vals[1]);
				add_property(_id(name), vals[0], baseurl, vals[1] == "important", container);
			}
		}
	}
}

void style::add_property(string_id name, const string& val, const string& baseurl, bool important, document_container* container)
{
	if (val.find("var(") != -1) return add_parsed_property(name, property_value(val, important, prop_type_var));
	if (val == "inherit" && name != _font_)       return add_parsed_property(name, property_value(important, prop_type_inherit));

	int idx;
	string url;
	css_length len[4], length;

	switch (name)
	{
	// keyword-only properties
	case _display_:
	case _visibility_:
	case _position_:
	case _float_:
	case _clear_:
	case _box_sizing_:
	case _overflow_:

	case _text_align_:
	case _vertical_align_:
	case _text_transform_:
	case _white_space_:

	case _font_style_:
	case _font_variant_:
	case _font_weight_:

	case _list_style_type_:
	case _list_style_position_:

	case _border_top_style_:
	case _border_bottom_style_:
	case _border_left_style_:
	case _border_right_style_:
	case _border_collapse_:
    #if H3ML
    case _border_front_style_:
	case _border_back_style_:
    #endif

	case _flex_direction_:
	case _flex_wrap_:
	case _justify_content_:
	case _align_items_:
	case _align_content_:
	case _align_self_:

		idx = value_index(val, m_valid_values[name]);
		if (idx >= 0)
		{
			add_parsed_property(name, property_value(idx, important));
		}
		break;

	// <length>
	case _text_indent_:
	case _padding_left_:
	case _padding_right_:
	case _padding_top_:
	case _padding_bottom_:
		length.fromString(val);
		add_parsed_property(name, property_value(length, important));
		break;
	
	// <length> | auto
	case _left_:
	case _right_:
	case _top_:
	case _bottom_:
	case _z_index_: // <integer> | auto
	case _width_:
	case _height_:
	case _min_width_:
	case _min_height_:
	case _margin_left_:
	case _margin_right_:
	case _margin_top_:
	case _margin_bottom_:
    #if H3ML
    case _front_:
	case _back_:
	case _depth_:
	case _min_depth_:
	case _margin_front_:
	case _margin_back_:
    #endif
		length.fromString(val, "auto", -1);
		add_parsed_property(name, property_value(length, important));
		break;

	// <length> | none
	case _max_width_:
	case _max_height_:
    #if H3ML
    case _max_depth_:
    #endif
		length.fromString(val, "none", -1);
		add_parsed_property(name, property_value(length, important));
		break;
	
	case _line_height_:
		length.fromString(val, "normal", -1);
		add_parsed_property(name, property_value(length, important));
		break;

	case _font_size_:
		length.fromString(val, font_size_strings, -1);
		add_parsed_property(name, property_value(length, important));
		break;

	// Parse background shorthand properties 
	case _background_:
		parse_background(val, baseurl, important, container);
		break;

	case _background_image_:
		parse_background_image(val, baseurl, important);
		break;

	case _background_attachment_:
	case _background_repeat_:
	case _background_clip_:
	case _background_origin_:
		parse_keyword_comma_list(name, val, important);
		break;

	case _background_position_:
		parse_background_position(val, important);
		break;

	case _background_size_:
		parse_background_size(val, important);
		break;

	// Parse border spacing properties 
	case _border_spacing_:
		parse_three_lengths(val, len);
		add_parsed_property(__litehtml_border_spacing_x_, property_value(len[0], important));
		add_parsed_property(__litehtml_border_spacing_y_, property_value(len[1], important));
		#if H3ML
		add_parsed_property(__litehtml_border_spacing_z_, property_value(len[2], important));
		#endif
		break;

	// Parse borders shorthand properties 
	case _border_:
	{
		string_vector tokens;
		split_string(val, tokens, " ", "", "(");
		for (const auto& token : tokens)
		{
			int idx = value_index(token, border_style_strings);
			if (idx >= 0)
			{
				property_value style(idx, important);
				add_parsed_property(_border_left_style_,	style);
				add_parsed_property(_border_right_style_,	style);
				add_parsed_property(_border_top_style_,		style);
				add_parsed_property(_border_bottom_style_,	style);
				#if H3ML
				add_parsed_property(_border_front_style_,	style);
				add_parsed_property(_border_back_style_,	style);
				#endif
			}
			else if (t_isdigit(token[0]) || token[0] == '.' ||
				value_in_list(token, border_width_strings))
			{
				property_value width(parse_border_width(token), important);
				add_parsed_property(_border_left_width_,	width);
				add_parsed_property(_border_right_width_,	width);
				add_parsed_property(_border_top_width_,		width);
				add_parsed_property(_border_bottom_width_,	width);
				#if H3ML
				add_parsed_property(_border_front_width_,	width);
				add_parsed_property(_border_back_width_,	width);
				#endif
			}
			else
			{
				web_color _color = web_color::from_string(token, container);
				property_value color(_color, important);
				add_parsed_property(_border_left_color_,	color);
				add_parsed_property(_border_right_color_,	color);
				add_parsed_property(_border_top_color_,		color);
				add_parsed_property(_border_bottom_color_,	color);
				#if H3ML
				add_parsed_property(_border_front_color_,	color);
				add_parsed_property(_border_back_color_,	color);
				#endif
			}
		}
		break;
	}

	case _border_left_:
	case _border_right_:
	case _border_top_:
	case _border_bottom_:
    #if H3ML
	case _border_front_:
	case _border_back_:
    #endif
	{
		string_vector tokens;
		split_string(val, tokens, " ", "", "(");
		for (const auto& token : tokens)
		{
			int idx = value_index(token, border_style_strings);
			if (idx >= 0)
			{
				add_parsed_property(_id(_s(name) + "-style"), property_value(idx, important));
			}
			else if (t_isdigit(token[0]) || token[0] == '.' ||
				value_in_list(token, border_width_strings))
			{
				property_value width(parse_border_width(token), important);
				add_parsed_property(_id(_s(name) + "-width"), width);
			}
			else
			{
				web_color color = web_color::from_string(token, container);
				add_parsed_property(_id(_s(name) + "-color"), property_value(color, important));
			}
		}
		break;
	}

	// Parse border-width/style/color shorthand properties 
	case _border_width_:
	case _border_style_:
	case _border_color_:
	{
		string prop = name == _border_width_ ? "-width" : name == _border_style_ ? "-style" : "-color";

		string_vector tokens;
		split_string(val, tokens, " ");
		#if H3ML
		if (tokens.size() == 6)
		{
			add_property(_id("border-top"    + prop), tokens[0], baseurl, important, container);
			add_property(_id("border-right"  + prop), tokens[1], baseurl, important, container);
			add_property(_id("border-bottom" + prop), tokens[2], baseurl, important, container);
			add_property(_id("border-left"   + prop), tokens[3], baseurl, important, container);
			add_property(_id("border-front"  + prop), tokens[4], baseurl, important, container);
			add_property(_id("border-back"   + prop), tokens[5], baseurl, important, container);
		}
		else
		#endif
		if (tokens.size() == 4)
		{
			add_property(_id("border-top"    + prop), tokens[0], baseurl, important, container);
			add_property(_id("border-right"  + prop), tokens[1], baseurl, important, container);
			add_property(_id("border-bottom" + prop), tokens[2], baseurl, important, container);
			add_property(_id("border-left"   + prop), tokens[3], baseurl, important, container);
			#if H3ML
			add_property(_id("border-front"  + prop), tokens[0], baseurl, important, container);
			add_property(_id("border-back"   + prop), tokens[0], baseurl, important, container);
			#endif
		}
		else if (tokens.size() == 3)
		{
			add_property(_id("border-top"    + prop), tokens[0], baseurl, important, container);
			add_property(_id("border-right"  + prop), tokens[1], baseurl, important, container);
			add_property(_id("border-left"   + prop), tokens[1], baseurl, important, container);
			add_property(_id("border-bottom" + prop), tokens[2], baseurl, important, container);
			#if H3ML
			add_property(_id("border-front"  + prop), tokens[0], baseurl, important, container);
			add_property(_id("border-back"   + prop), tokens[0], baseurl, important, container);
			#endif
		}
		else if (tokens.size() == 2)
		{
			add_property(_id("border-top"    + prop), tokens[0], baseurl, important, container);
			add_property(_id("border-bottom" + prop), tokens[0], baseurl, important, container);
			add_property(_id("border-right"  + prop), tokens[1], baseurl, important, container);
			add_property(_id("border-left"   + prop), tokens[1], baseurl, important, container);
			#if H3ML
			add_property(_id("border-front"  + prop), tokens[0], baseurl, important, container);
			add_property(_id("border-back"   + prop), tokens[0], baseurl, important, container);
			#endif
		}
		else if (tokens.size() == 1)
		{
			add_property(_id("border-top"    + prop), tokens[0], baseurl, important, container);
			add_property(_id("border-bottom" + prop), tokens[0], baseurl, important, container);
			add_property(_id("border-right"  + prop), tokens[0], baseurl, important, container);
			add_property(_id("border-left"   + prop), tokens[0], baseurl, important, container);
			#if H3ML
			add_property(_id("border-front"  + prop), tokens[0], baseurl, important, container);
			add_property(_id("border-back"   + prop), tokens[0], baseurl, important, container);
			#endif
		}
		break;
	}

	case _border_top_width_:
	case _border_bottom_width_:
	case _border_left_width_:
	case _border_right_width_:
		length = parse_border_width(val);
		add_parsed_property(name, property_value(length, important));
		break;

	case _color_:
	case _background_color_:
	case _border_top_color_:
	case _border_bottom_color_:
	case _border_left_color_:
	case _border_right_color_:
	{
		web_color color = web_color::from_string(val, container);
		add_parsed_property(name, property_value(color, important));
		break;
	}

	// Parse border radius shorthand properties 
	case _border_bottom_left_radius_:
	case _border_bottom_right_radius_:
	case _border_top_right_radius_:
	case _border_top_left_radius_:
		parse_three_lengths(val, len);
		add_parsed_property(_id(_s(name) + "-x"), property_value(len[0], important));
		add_parsed_property(_id(_s(name) + "-y"), property_value(len[1], important));
		#if H3ML
		add_parsed_property(_id(_s(name) + "-z"), property_value(len[2], important));
		#endif
		break;

	// Parse border-radius shorthand properties 
	case _border_radius_:
	{
		string_vector tokens;
		split_string(val, tokens, "/");
		if (tokens.size() == 1)
		{
			add_property(_border_radius_x_, tokens[0], baseurl, important, container);
			add_property(_border_radius_y_, tokens[0], baseurl, important, container);
			#if H3ML
			add_property(_border_radius_z_, tokens[0], baseurl, important, container);
			#endif
		}
		else if (tokens.size() >= 2)
		{
			add_property(_border_radius_x_, tokens[0], baseurl, important, container);
			add_property(_border_radius_y_, tokens[1], baseurl, important, container);
			#if H3ML
			add_property(_border_radius_z_, tokens.size() >= 3 ? tokens[2] : tokens[1], baseurl, important, container);
			#endif
		}
		break;
	}
	case _border_radius_x_:
	case _border_radius_y_:
    #if H3ML
	case _border_radius_z_:
    #endif
	{
		string_id top_left, top_right, bottom_right, bottom_left;
		#if H3ML
		string_id front_left, front_right, back_right, back_left;
		if (name == _border_radius_z_)
		{
			top_left		= _border_top_left_radius_z_;
			top_right		= _border_top_right_radius_z_;
			bottom_right	= _border_bottom_right_radius_z_;
			bottom_left		= _border_bottom_left_radius_z_;
			front_left		= _border_front_left_radius_z_;
			front_right		= _border_front_right_radius_z_;
			back_right		= _border_back_right_radius_z_;
			back_left		= _border_back_left_radius_z_;
		}
		else
		#endif
		if (name == _border_radius_x_)
		{
			top_left		= _border_top_left_radius_x_;
			top_right		= _border_top_right_radius_x_;
			bottom_right	= _border_bottom_right_radius_x_;
			bottom_left		= _border_bottom_left_radius_x_;
			#if H3ML
			front_left		= _border_front_left_radius_x_;
			front_right		= _border_front_right_radius_x_;
			back_right		= _border_back_right_radius_x_;
			back_left		= _border_back_left_radius_x_;
			#endif
		}
		else
		{
			top_left		= _border_top_left_radius_y_;
			top_right		= _border_top_right_radius_y_;
			bottom_right	= _border_bottom_right_radius_y_;
			bottom_left		= _border_bottom_left_radius_y_;
			#if H3ML
			front_left		= _border_front_left_radius_y_;
			front_right		= _border_front_right_radius_y_;
			back_right		= _border_back_right_radius_y_;
			back_left		= _border_back_left_radius_y_;
			#endif
		}

		switch (
			#if H3ML
			parse_eight_lengths(val, len)
			#else
			parse_four_lengths(val, len)
			#endif
		)
		{
		case 1:
			add_parsed_property(top_left,		property_value(len[0], important));
			add_parsed_property(top_right,		property_value(len[0], important));
			add_parsed_property(bottom_right,	property_value(len[0], important));
			add_parsed_property(bottom_left,	property_value(len[0], important));
			#if H3ML
			add_parsed_property(front_left,		property_value(len[0], important));
			add_parsed_property(front_right,	property_value(len[0], important));
			add_parsed_property(back_right,		property_value(len[0], important));
			add_parsed_property(back_left,		property_value(len[0], important));
			#endif
			break;
		case 2:
			add_parsed_property(top_left,		property_value(len[0], important));
			add_parsed_property(top_right,		property_value(len[1], important));
			add_parsed_property(bottom_right,	property_value(len[0], important));
			add_parsed_property(bottom_left,	property_value(len[1], important));
			#if H3ML
			add_parsed_property(front_left,		property_value(len[0], important));
			add_parsed_property(front_right,	property_value(len[1], important));
			add_parsed_property(back_right,		property_value(len[0], important));
			add_parsed_property(back_left,		property_value(len[1], important));
			#endif
			break;
		case 3:
			add_parsed_property(top_left,		property_value(len[0], important));
			add_parsed_property(top_right,		property_value(len[1], important));
			add_parsed_property(bottom_right,	property_value(len[2], important));
			add_parsed_property(bottom_left,	property_value(len[1], important));
			#if H3ML
			add_parsed_property(front_left,		property_value(len[0], important));
			add_parsed_property(front_right,	property_value(len[1], important));
			add_parsed_property(back_right,		property_value(len[2], important));
			add_parsed_property(back_left,		property_value(len[1], important));
			#endif
			break;
		case 4:
			add_parsed_property(top_left,		property_value(len[0], important));
			add_parsed_property(top_right,		property_value(len[1], important));
			add_parsed_property(bottom_right,	property_value(len[2], important));
			add_parsed_property(bottom_left,	property_value(len[3], important));
			#if H3ML
			add_parsed_property(front_left,		property_value(len[0], important));
			add_parsed_property(front_right,	property_value(len[1], important));
			add_parsed_property(back_right,		property_value(len[2], important));
			add_parsed_property(back_left,		property_value(len[3], important));
			#endif
			break;
		#if H3ML
		case 5:
			add_parsed_property(top_left,		property_value(len[0], important));
			add_parsed_property(top_right,		property_value(len[1], important));
			add_parsed_property(bottom_right,	property_value(len[2], important));
			add_parsed_property(bottom_left,	property_value(len[3], important));
			add_parsed_property(front_left,		property_value(len[4], important));
			add_parsed_property(front_right,	property_value(len[4], important));
			add_parsed_property(back_right,		property_value(len[4], important));
			add_parsed_property(back_left,		property_value(len[4], important));
		case 6:
			add_parsed_property(top_left,		property_value(len[0], important));
			add_parsed_property(top_right,		property_value(len[1], important));
			add_parsed_property(bottom_right,	property_value(len[2], important));
			add_parsed_property(bottom_left,	property_value(len[3], important));
			add_parsed_property(front_left,		property_value(len[4], important));
			add_parsed_property(front_right,	property_value(len[5], important));
			add_parsed_property(back_right,		property_value(len[4], important));
			add_parsed_property(back_left,		property_value(len[5], important));
		case 7:
			add_parsed_property(top_left,		property_value(len[0], important));
			add_parsed_property(top_right,		property_value(len[1], important));
			add_parsed_property(bottom_right,	property_value(len[2], important));
			add_parsed_property(bottom_left,	property_value(len[3], important));
			add_parsed_property(front_left,		property_value(len[4], important));
			add_parsed_property(front_right,	property_value(len[5], important));
			add_parsed_property(back_right,		property_value(len[6], important));
			add_parsed_property(back_left,		property_value(len[4], important));
		case 8:
			add_parsed_property(top_left,		property_value(len[0], important));
			add_parsed_property(top_right,		property_value(len[1], important));
			add_parsed_property(bottom_right,	property_value(len[2], important));
			add_parsed_property(bottom_left,	property_value(len[3], important));
			add_parsed_property(front_left,		property_value(len[4], important));
			add_parsed_property(front_right,	property_value(len[5], important));
			add_parsed_property(back_right,		property_value(len[6], important));
			add_parsed_property(back_left,		property_value(len[7], important));
		#endif
			break;
		}
		break;
	}

	// Parse list-style shorthand properties 
	case _list_style_:
	{
		add_parsed_property(_list_style_type_,			property_value(list_style_type_disc,		important));
		add_parsed_property(_list_style_position_,		property_value(list_style_position_outside,	important));
		add_parsed_property(_list_style_image_,			property_value("",							important));
		add_parsed_property(_list_style_image_baseurl_,	property_value("",							important));

		string_vector tokens;
		split_string(val, tokens, " ", "", "(");
		for (const auto& token : tokens)
		{
			int idx = value_index(token, list_style_type_strings);
			if (idx >= 0)
			{
				add_parsed_property(_list_style_type_, property_value(idx, important));
			}
			else
			{
				idx = value_index(token, list_style_position_strings);
				if (idx >= 0)
				{
					add_parsed_property(_list_style_position_, property_value(idx, important));
				}
				else if (!strncmp(token.c_str(), "url", 3))
				{
					css::parse_css_url(token, url);
					add_parsed_property(_list_style_image_,			property_value(url,     important));
					add_parsed_property(_list_style_image_baseurl_, property_value(baseurl, important));
				}
			}
		}
		break;
	}

	case _list_style_image_:
		css::parse_css_url(val, url);
		add_parsed_property(_list_style_image_,			property_value(url,     important));
		add_parsed_property(_list_style_image_baseurl_, property_value(baseurl, important));
		break;

	// Parse margin and padding shorthand properties 
	case _margin_:
	case _padding_:
	{
		switch (
			#if H3ML
			parse_six_lengths(val, len)
			#else
			parse_four_lengths(val, len)
			#endif
		)
		{
		#if H3ML
		case 6:
			add_parsed_property(_id(_s(name) + "-top"),		property_value(len[0], important));
			add_parsed_property(_id(_s(name) + "-right"),	property_value(len[1], important));
			add_parsed_property(_id(_s(name) + "-bottom"),	property_value(len[2], important));
			add_parsed_property(_id(_s(name) + "-left"),	property_value(len[3], important));
			add_parsed_property(_id(_s(name) + "-front"),	property_value(len[4], important));
			add_parsed_property(_id(_s(name) + "-back"),	property_value(len[5], important));
			break;
		case 5:
			add_parsed_property(_id(_s(name) + "-top"),		property_value(len[0], important));
			add_parsed_property(_id(_s(name) + "-right"),	property_value(len[1], important));
			add_parsed_property(_id(_s(name) + "-bottom"),	property_value(len[2], important));
			add_parsed_property(_id(_s(name) + "-left"),	property_value(len[3], important));
			add_parsed_property(_id(_s(name) + "-front"),	property_value(len[4], important));
			add_parsed_property(_id(_s(name) + "-back"),	property_value(len[4], important));
			break;
		#endif
		case 4:
			add_parsed_property(_id(_s(name) + "-top"),		property_value(len[0], important));
			add_parsed_property(_id(_s(name) + "-right"),	property_value(len[1], important));
			add_parsed_property(_id(_s(name) + "-bottom"),	property_value(len[2], important));
			add_parsed_property(_id(_s(name) + "-left"),	property_value(len[3], important));
			//#if H3ML
			//add_parsed_property(_id(_s(name) + "-front"),	property_value(len[0], important));
			//add_parsed_property(_id(_s(name) + "-back"),	property_value(len[2], important));
			//#endif
			break;
		case 3:
			add_parsed_property(_id(_s(name) + "-top"),		property_value(len[0], important));
			add_parsed_property(_id(_s(name) + "-right"),	property_value(len[1], important));
			add_parsed_property(_id(_s(name) + "-left"),	property_value(len[1], important));
			add_parsed_property(_id(_s(name) + "-bottom"),	property_value(len[2], important));
			//#if H3ML
			//add_parsed_property(_id(_s(name) + "-front"),	property_value(len[0], important));
			//add_parsed_property(_id(_s(name) + "-back"),	property_value(len[2], important));
			//#endif
			break;
		case 2:
			add_parsed_property(_id(_s(name) + "-top"),		property_value(len[0], important));
			add_parsed_property(_id(_s(name) + "-bottom"),	property_value(len[0], important));
			add_parsed_property(_id(_s(name) + "-right"),	property_value(len[1], important));
			add_parsed_property(_id(_s(name) + "-left"),	property_value(len[1], important));
			//#if H3ML
			//add_parsed_property(_id(_s(name) + "-front"),	property_value(len[0], important));
			//add_parsed_property(_id(_s(name) + "-back"),	property_value(len[1], important));
			//#endif
			break;
		case 1:
			add_parsed_property(_id(_s(name) + "-top"),		property_value(len[0], important));
			add_parsed_property(_id(_s(name) + "-bottom"),	property_value(len[0], important));
			add_parsed_property(_id(_s(name) + "-right"),	property_value(len[0], important));
			add_parsed_property(_id(_s(name) + "-left"),	property_value(len[0], important));
			//#if H3ML
			//add_parsed_property(_id(_s(name) + "-front"),	property_value(len[0], important));
			//add_parsed_property(_id(_s(name) + "-back"),	property_value(len[0], important));
			//#endif
			break;
		}
		break;
	}

	// Parse font shorthand properties 
	case _font_:
		parse_font(val, important);
		break;

	// Parse flex-flow shorthand properties
	case _flex_flow_:
	{
		string_vector tokens;
		split_string(val, tokens, " ");
		for (const auto& tok : tokens)
		{
			int idx;
			if ((idx = value_index(tok, flex_direction_strings)) >= 0)
			{
				add_parsed_property(_flex_direction_, property_value(idx, important));
			}
			else if ((idx = value_index(tok, flex_wrap_strings)) >= 0)
			{
				add_parsed_property(_flex_wrap_, property_value(idx, important));
			}
		}
		break;
	}

	// Parse flex shorthand properties
	case _flex_:
		parse_flex(val, important);
		break;

	case _flex_grow_:
	case _flex_shrink_:
		add_parsed_property(name, property_value(t_strtof(val), important));
		break;

	case _flex_basis_:
		length.fromString(val, flex_basis_strings, -1);
		add_parsed_property(_flex_basis_, property_value(length, important));
		break;

	default:
		add_parsed_property(name, property_value(val, important));
	}
}

css_length style::parse_border_width(const string& str)
{
	css_length len;
	if (t_isdigit(str[0]) || str[0] == '.')
	{
		len.fromString(str);
	}
	else
	{
		int idx = value_index(str, border_width_strings);
		if (idx >= 0)
		{
			len.set_value(border_width_values[idx], css_units_px);
		}
	}
	return len;
}

void style::parse_three_lengths(const string& str, css_length len[3])
{
	string_vector tokens;
	split_string(str, tokens, " ");
	if (tokens.size() == 1)
	{
		css_length length;
		length.fromString(tokens[0]);
		len[0] = len[1] = len[2] =length;
	}
	else if (tokens.size() == 2)
	{
		len[0].fromString(tokens[0]);
		len[1].fromString(tokens[1]);
		len[2].fromString(tokens[1]);
	}
	else if (tokens.size() >= 3)
	{
		len[0].fromString(tokens[0]);
		len[1].fromString(tokens[1]);
		len[2].fromString(tokens[2]);
	}
}

#if H3ML
int style::parse_six_lengths(const string& str, css_length len[6])
{
	string_vector tokens;
	split_string(str, tokens, " ");
	if (tokens.size() == 0 || tokens.size() > 6)
	{
		return 0;
	}
	for (size_t i = 0; i < tokens.size(); i++)
	{
		len[i].fromString(tokens[i]);
	}
	return (int)tokens.size();
}

int style::parse_eight_lengths(const string& str, css_length len[8])
{
	string_vector tokens;
	split_string(str, tokens, " ");
	if (tokens.size() == 0 || tokens.size() > 8)
	{
		return 0;
	}
	for (size_t i = 0; i < tokens.size(); i++)
	{
		len[i].fromString(tokens[i]);
	}
	return (int)tokens.size();
}
#else
int style::parse_four_lengths(const string& str, css_length len[4])
{
	string_vector tokens;
	split_string(str, tokens, " ");
	if (tokens.size() == 0 || tokens.size() > 4)
	{
		return 0;
	}
	for (size_t i = 0; i < tokens.size(); i++)
	{
		len[i].fromString(tokens[i]);
	}
	return (int)tokens.size();
}
#endif

void style::parse_background(const string& val, const string& baseurl, bool important, document_container* container)
{
	string_vector tokens;
	split_string(val, tokens, ",", "", "(");
	if (tokens.empty()) return;

	web_color color;
	string_vector images; 
	int_vector repeats, origins, clips, attachments;
	length_vector x_positions, y_positions;
	#if H3ML
	length_vector z_positions;
	#endif
	size_vector sizes;

	for (const auto& token : tokens)
	{
		background bg;
		if (!parse_one_background(token, container, bg))
			return;
		
		color = bg.m_color;
		images.push_back(bg.m_image[0]);
		repeats.push_back(bg.m_repeat[0]);
		origins.push_back(bg.m_origin[0]);
		clips.push_back(bg.m_clip[0]);
		attachments.push_back(bg.m_attachment[0]);
		x_positions.push_back(bg.m_position_x[0]);
		y_positions.push_back(bg.m_position_y[0]);
		#if H3ML
		z_positions.push_back(bg.m_position_z[0]);
		#endif
		sizes.push_back(bg.m_size[0]);
	}

	add_parsed_property(_background_color_,			property_value(color,		important));
	add_parsed_property(_background_image_,			property_value(images,		important));
	add_parsed_property(_background_image_baseurl_, property_value(baseurl,		important));
	add_parsed_property(_background_repeat_,		property_value(repeats,		important));
	add_parsed_property(_background_origin_,		property_value(origins,		important));
	add_parsed_property(_background_clip_,			property_value(clips,		important));
	add_parsed_property(_background_attachment_,	property_value(attachments, important));
	add_parsed_property(_background_position_x_,	property_value(x_positions, important));
	add_parsed_property(_background_position_y_,	property_value(y_positions, important));
	#if H3ML
	add_parsed_property(_background_position_z_,	property_value(z_positions, important));
	#endif
	add_parsed_property(_background_size_,			property_value(sizes,		important));
}

bool style::parse_one_background(const string& val, document_container* container, background& bg)
{
	bg.m_color = web_color::transparent;
	bg.m_image = {""};
	bg.m_repeat = { background_repeat_repeat };
	bg.m_origin = { background_box_padding };
	bg.m_clip = { background_box_border };
	bg.m_attachment = { background_attachment_scroll };
	bg.m_position_x = { css_length(0, css_units_percentage) };
	bg.m_position_y = { css_length(0, css_units_percentage) };
	#if H3ML
	bg.m_position_z = { css_length(0, css_units_percentage) };
	#endif
	bg.m_size = { css_size(css_length::predef_value(background_size_auto), css_length::predef_value(background_size_auto)
		#if H3ML
		, css_length::predef_value(background_size_auto)
		#endif
	) };

	if(val == "none")
	{
		return true;
	}

	string_vector tokens;
	split_string(val, tokens, " \t\n\r", "", "(");

	bool color_found = false;
	bool image_found = false;
	bool origin_found = false;
	bool clip_found = false;
	bool repeat_found = false;
	bool attachment_found = false;

	string position;
	for(const auto& token : tokens)
	{
		int idx;
		if(token.substr(0, 3) == "url")
		{
			if (image_found) return false;
			string url;
			css::parse_css_url(token, url);
			bg.m_image = { url };
			image_found = true;
		} else if( (idx = value_index(token, background_repeat_strings)) >= 0 )
		{
			if (repeat_found) return false;
			bg.m_repeat = { idx };
			repeat_found = true;
		} else if( (idx = value_index(token, background_attachment_strings)) >= 0 )
		{
			if (attachment_found) return false;
			bg.m_attachment = { idx };
			attachment_found = true;
		} else if( (idx = value_index(token, background_box_strings)) >= 0 )
		{
			if(!origin_found)
			{
				bg.m_origin = { idx };
				origin_found = true;
			} else
			{
				if (clip_found) return false;
				bg.m_clip = { idx };
				clip_found = true;
			}
		} else if(	value_in_list(token, background_position_strings) ||
					token.find('/') != -1 ||
					t_isdigit(token[0]) ||
					token[0] == '+'	||
					token[0] == '-'	||
					token[0] == '.' )
		{
			position += " " + token;
		} else if (web_color::is_color(token, container))
		{
			if (color_found) return false;
			bg.m_color = web_color::from_string(token, container);
			color_found = true;
		}
		else
		{
			return false;
		}
	}
	
	if (position != "")
	{
		string_vector tokens;
		split_string(position, tokens, "/");

		if (tokens.size() > 2) return false;

		if (tokens.size() == 2 && !parse_one_background_size(tokens[1], bg.m_size[0]))
			return false;

		if (tokens.size() > 0 && !parse_one_background_position(tokens[0], bg.m_position_x[0], bg.m_position_y[0]
			#if H3ML
			, bg.m_position_z[0]
			#endif
		))
			return false;
	}
	
	return true;
}

void style::parse_background_image(const string& val, const string& baseurl, bool important)
{
	string_vector tokens;
	split_string(val, tokens, ",", "", "(");
	if (tokens.empty()) return;

	string_vector images;

	for (const auto& token : tokens)
	{
		string url;
		css::parse_css_url(token, url);
		images.push_back(url);
	}

	add_parsed_property(_background_image_,         property_value(images,  important));
	add_parsed_property(_background_image_baseurl_, property_value(baseurl, important));
}

void style::parse_keyword_comma_list(string_id name, const string& val, bool important)
{
	string_vector tokens;
	split_string(val, tokens, ",");
	if (tokens.empty()) return;

	int_vector vec;

	for (auto& token : tokens)
	{
		trim(token);
		int idx = value_index(token, m_valid_values[name]);
		if (idx == -1) return;
		vec.push_back(idx);
	}

	add_parsed_property(name, property_value(vec, important));
}

void style::parse_background_position(const string& val, bool important)
{
	string_vector tokens;
	split_string(val, tokens, ",");
	if (tokens.empty()) return;

	length_vector x_positions, y_positions;
	#if H3ML
	length_vector z_positions;
	#endif

	for (const auto& token : tokens)
	{
		css_length x, y;
		#if H3ML
		css_length z;
		#endif
		if(!parse_one_background_position(token, x, y
			#if H3ML
			, z
			#endif
		)) return;
		x_positions.push_back(x);
		y_positions.push_back(y);
		#if H3ML
		z_positions.push_back(z);
		#endif
	}
	
	add_parsed_property(_background_position_x_, property_value(x_positions, important));
	add_parsed_property(_background_position_y_, property_value(y_positions, important));
	#if H3ML
	add_parsed_property(_background_position_z_, property_value(z_positions, important));
	#endif
}

bool style::parse_one_background_position(const string& val, css_length& x, css_length& y
	#if H3ML
	, css_length& z
	#endif
)
{
	string_vector pos;
	split_string(val, pos, " \t");
	
	if (pos.empty() || 
		#if H3ML
		pos.size() > 3
		#else
		pos.size() > 2
		#endif
	)
	{
		return false;
	}
	
	if (pos.size() == 1)
	{
		if (value_in_list(pos[0], "left;right;center"))
		{
			x.fromString(pos[0], "left;right;center");
			y.set_value(50, css_units_percentage);
			#if H3ML
			z.set_value(50, css_units_percentage);
			#endif
		}
		else if (value_in_list(pos[0], "top;bottom;center"))
		{
			y.fromString(pos[0], "top;bottom;center");
			x.set_value(50, css_units_percentage);
			#if H3ML
			z.set_value(50, css_units_percentage);
			#endif
		}
		#if H3ML
		else if (value_in_list(pos[0], "front;back;center"))
		{
			z.fromString(pos[0], "front;back;center");
			x.set_value(50, css_units_percentage);
			y.set_value(50, css_units_percentage);
		}
		#endif
		else
		{
			x.fromString(pos[0], "left;right;center");
			y.set_value(50, css_units_percentage);
			#if H3ML
			z.set_value(50, css_units_percentage);
			#endif
		}
	}
	else if (pos.size() == 2)
	{
		if (value_in_list(pos[0], "left;right"))
		{
			x.fromString(pos[0], "left;right;center");
			y.fromString(pos[1], "top;bottom;center");
			#if H3ML
			z.set_value(50, css_units_percentage);
			#endif
		}
		else if (value_in_list(pos[0], "top;bottom"))
		{
			x.fromString(pos[1], "left;right;center");
			y.fromString(pos[0], "top;bottom;center");
			#if H3ML
			z.set_value(50, css_units_percentage);
			#endif
		}
		else if (value_in_list(pos[1], "left;right"))
		{
			x.fromString(pos[1], "left;right;center");
			y.fromString(pos[0], "top;bottom;center");
			#if H3ML
			z.set_value(50, css_units_percentage);
			#endif
		}
		else if (value_in_list(pos[1], "top;bottom"))
		{
			x.fromString(pos[0], "left;right;center");
			y.fromString(pos[1], "top;bottom;center");
			#if H3ML
			z.set_value(50, css_units_percentage);
			#endif
		}
		#if H3ML
		else if (value_in_list(pos[0], "front;back"))
		{
			x.fromString(pos[1], "left;right;center");
			y.set_value(50, css_units_percentage);
			z.fromString(pos[0], "front;back;center");
		}
		else if (value_in_list(pos[1], "front;back"))
		{
			x.fromString(pos[0], "left;right;center");
			y.set_value(50, css_units_percentage);
			z.fromString(pos[1], "front;back;center");
		}
		#endif
		else
		{
			x.fromString(pos[0], "left;right;center");
			y.fromString(pos[1], "top;bottom;center");
			#if H3ML
			z.set_value(50, css_units_percentage);
			#endif
		}
	}
	#if H3ML
	else if (pos.size() == 3)
	{
		if (value_in_list(pos[0], "left;right"))
		{
			x.fromString(pos[0], "left;right;center");
			y.fromString(pos[1], "top;bottom;center");
			z.fromString(pos[2], "front;back;center");
		}
		else if (value_in_list(pos[0], "top;bottom"))
		{
			x.fromString(pos[1], "left;right;center");
			y.fromString(pos[0], "top;bottom;center");
			z.fromString(pos[2], "front;back;center");
		}
		else if (value_in_list(pos[0], "front;back"))
		{
			x.fromString(pos[1], "left;right;center");
			y.fromString(pos[2], "top;bottom;center");
			z.fromString(pos[0], "front;back;center");
		}
		else if (value_in_list(pos[1], "left;right"))
		{
			x.fromString(pos[1], "left;right;center");
			y.fromString(pos[0], "top;bottom;center");
			z.fromString(pos[2], "front;back;center");
		}
		else if (value_in_list(pos[1], "top;bottom"))
		{
			x.fromString(pos[0], "left;right;center");
			y.fromString(pos[1], "top;bottom;center");
			z.fromString(pos[2], "front;back;center");
		}
		else if (value_in_list(pos[1], "front;back"))
		{
			x.fromString(pos[0], "left;right;center");
			y.fromString(pos[2], "top;bottom;center");
			z.fromString(pos[1], "front;back;center");
		}
		else if (value_in_list(pos[2], "left;right"))
		{
			x.fromString(pos[2], "left;right;center");
			y.fromString(pos[1], "top;bottom;center");
			z.fromString(pos[0], "front;back;center");
		}
		else if (value_in_list(pos[2], "top;bottom"))
		{
			x.fromString(pos[1], "left;right;center");
			y.fromString(pos[2], "top;bottom;center");
			z.fromString(pos[0], "front;back;center");
		}
		else if (value_in_list(pos[2], "front;back"))
		{
			x.fromString(pos[0], "left;right;center");
			y.fromString(pos[1], "top;bottom;center");
			z.fromString(pos[2], "front;back;center");
		}
		else
		{
			x.fromString(pos[0], "left;right;center");
			y.fromString(pos[1], "top;bottom;center");
			z.fromString(pos[2], "front;back;center");
		}
	}
	#endif

	if (x.is_predefined())
	{
		switch (x.predef())
		{
		case 0:
			x.set_value(0, css_units_percentage);
			break;
		case 1:
			x.set_value(100, css_units_percentage);
			break;
		case 2:
			x.set_value(50, css_units_percentage);
			break;
		}
	}
	if (y.is_predefined())
	{
		switch (y.predef())
		{
		case 0:
			y.set_value(0, css_units_percentage);
			break;
		case 1:
			y.set_value(100, css_units_percentage);
			break;
		case 2:
			y.set_value(50, css_units_percentage);
			break;
		}
	}
	#if H3ML
	if (z.is_predefined())
	{
		switch (z.predef())
		{
		case 0:
			z.set_value(0, css_units_percentage);
			break;
		case 1:
			z.set_value(100, css_units_percentage);
			break;
		case 2:
			z.set_value(50, css_units_percentage);
			break;
		}
	}
	#endif
	return true;
}

void style::parse_background_size(const string& val, bool important)
{
	string_vector tokens;
	split_string(val, tokens, ",");
	if (tokens.empty()) return;

	size_vector sizes;

	for (const auto& token : tokens)
	{
		css_size size;
		if (!parse_one_background_size(token, size)) return;
		sizes.push_back(size);
	}

	add_parsed_property(_background_size_, property_value(sizes, important));
}

bool style::parse_one_background_size(const string& val, css_size& size)
{
	string_vector res;
	split_string(val, res, " \t");
	if (res.empty())
	{
		return false;
	}

	size.width.fromString(res[0], background_size_strings);
	if (res.size() > 1)
	{
		size.height.fromString(res[1], background_size_strings);
	}
	else
	{
		size.height.predef(background_size_auto);
	}
	#if H3ML
	if (res.size() > 2)
	{
		size.depth.fromString(res[2], background_size_strings);
	}
	else
	{
		size.depth.predef(background_size_auto);
	}
	#endif
	return true;
}

void style::parse_font(const string& val, bool important)
{
	if (val == "inherit")
	{
		add_parsed_property(_font_style_, property_value(important, prop_type_inherit));
		add_parsed_property(_font_variant_, property_value(important, prop_type_inherit));
		add_parsed_property(_font_weight_, property_value(important, prop_type_inherit));
		add_parsed_property(_font_size_, property_value(important, prop_type_inherit));
		add_parsed_property(_line_height_, property_value(important, prop_type_inherit));
		return;
	} else
	{
		add_parsed_property(_font_style_, property_value(font_style_normal, important));
		add_parsed_property(_font_variant_, property_value(font_variant_normal, important));
		add_parsed_property(_font_weight_, property_value(font_weight_normal, important));
		add_parsed_property(_font_size_, property_value(font_size_medium, important));
		add_parsed_property(_line_height_, property_value(line_height_normal, important));
	}

	string_vector tokens;
	split_string(val, tokens, " ", "", "\"");

	int idx;
	bool is_family = false;
	string font_family;
	for(const auto& token : tokens)
	{
		if(is_family)
		{
			font_family += token;
			continue;
		}

		if((idx = value_index(token, font_style_strings)) >= 0)
		{
			if(idx == 0)
			{
				add_parsed_property(_font_style_,	property_value(font_style_normal,	important));
				add_parsed_property(_font_variant_, property_value(font_variant_normal,	important));
				add_parsed_property(_font_weight_,	property_value(font_weight_normal,	important));
			} else
			{
				add_parsed_property(_font_style_,	property_value(idx,		important));
			}
		} else if((idx = value_index(token, font_weight_strings)) >= 0)
		{
			add_parsed_property(_font_weight_, property_value(idx, important));
		} else if((idx = value_index(token, font_variant_strings)) >= 0)
		{
			add_parsed_property(_font_variant_, property_value(idx, important));
		}
		else if(t_isdigit(token[0]) || token[0] == '.' || 
			value_in_list(token, font_size_strings) || token.find('/') != -1)
		{
			string_vector szlh;
			split_string(token, szlh, "/");

			auto size = css_length::from_string(szlh[0], font_size_strings, -1);
			add_parsed_property(_font_size_, property_value(size, important));

			if(szlh.size() == 2)
			{
				auto height = css_length::from_string(szlh[1], "normal", -1);
				add_parsed_property(_line_height_, property_value(height, important));
			}
		} else
		{
			is_family = true;
			font_family += token;
		}
	}
	add_parsed_property(_font_family_, property_value(font_family, important));
}

void style::parse_flex(const string& val, bool important)
{
	auto is_number = [](const string& val)
	{
		for (auto ch : val)
		{
			if ((ch < '0' || ch > '9') && ch != '.')
			{
				return false;
			}
		}
		return true;
	};

	css_length _auto = css_length::predef_value(flex_basis_auto);

	if (val == "initial")
	{
		// 0 1 auto
		add_parsed_property(_flex_grow_,	property_value(0.f, important));
		add_parsed_property(_flex_shrink_,	property_value(1.f, important));
		add_parsed_property(_flex_basis_,	property_value(_auto, important));
	}
	else if (val == "auto")
	{
		// 1 1 auto
		add_parsed_property(_flex_grow_,	property_value(1.f, important));
		add_parsed_property(_flex_shrink_,	property_value(1.f, important));
		add_parsed_property(_flex_basis_,	property_value(_auto, important));
	}
	else if (val == "none")
	{
		// 0 0 auto
		add_parsed_property(_flex_grow_,	property_value(0.f, important));
		add_parsed_property(_flex_shrink_,	property_value(0.f, important));
		add_parsed_property(_flex_basis_,	property_value(_auto, important));
	}
	else
	{
		string_vector tokens;
		split_string(val, tokens, " ");
		if (tokens.size() == 3)
		{
			float grow = t_strtof(tokens[0]);
			float shrink = t_strtof(tokens[1]);
			auto basis = css_length::from_string(tokens[2], flex_basis_strings, -1);
			
			add_parsed_property(_flex_grow_,	property_value(grow, important));
			add_parsed_property(_flex_shrink_,	property_value(shrink, important));
			add_parsed_property(_flex_basis_,	property_value(basis, important));
		}
		else if (tokens.size() == 2)
		{
			float grow = t_strtof(tokens[0]);
			add_parsed_property(_flex_grow_, property_value(grow, important));
			
			if (is_number(tokens[1]))
			{
				float shrink = t_strtof(tokens[1]);
				add_parsed_property(_flex_shrink_, property_value(shrink, important));
			}
			else
			{
				auto basis = css_length::from_string(tokens[1], flex_basis_strings, -1);
				add_parsed_property(_flex_basis_, property_value(basis, important));
			}
		}
		else if (tokens.size() == 1)
		{
			if (is_number(tokens[0]))
			{
				float grow = t_strtof(tokens[0]);
				add_parsed_property(_flex_grow_, property_value(grow, important));
				
				if (grow >= 1)
				{
					add_parsed_property(_flex_shrink_, property_value(1.f, important));
					add_parsed_property(_flex_basis_,  property_value(css_length(0), important));
				}
			}
			else
			{
				auto basis = css_length::from_string(tokens[0], flex_basis_strings, -1);
				add_parsed_property(_flex_basis_, property_value(basis, important));
			}
		}
	}
}

void style::add_parsed_property( string_id name, const property_value& propval )
{
	auto prop = m_properties.find(name);
	if (prop != m_properties.end())
	{
		if (!prop->second.m_important || (propval.m_important && prop->second.m_important))
		{
			prop->second = propval;
		}
	}
	else
	{
		m_properties[name] = propval;
	}
}

void style::remove_property( string_id name, bool important )
{
	auto prop = m_properties.find(name);
	if(prop != m_properties.end())
	{
		if( !prop->second.m_important || (important && prop->second.m_important) )
		{
			m_properties.erase(prop);
		}
	}
}

void style::combine(const litehtml::style& src)
{
	for (const auto& property : src.m_properties)
	{
		add_parsed_property(property.first, property.second);
	}
}

const property_value& style::get_property(string_id name) const
{
	auto it = m_properties.find(name);
	if (it != m_properties.end())
	{
		return it->second;
	}
	static property_value dummy;
	return dummy;
}

void style::subst_vars_(string& str, const element* el)
{
	while (1)
	{
		auto start = str.find("var(");
		if (start == -1) break;
		if (start > 0 && isalnum(str[start - 1])) break;
		auto end = str.find(")", start + 4);
		if (end == -1) break;
		auto name = str.substr(start + 4, end - start - 4);
		trim(name);
		string val = el->get_custom_property(_id(name), "");
		str.replace(start, end - start + 1, val);
	}
}

void style::subst_vars(const element* el)
{
	for (auto& prop : m_properties)
	{
		if (prop.second.m_type == prop_type_var)
		{
			subst_vars_(prop.second.m_string, el);
			// re-adding the same property
			// if it is a custom property it will be readded as a string (currently it is prop_type_var)
			// if it is a standard css property it will be parsed and properly added as typed property
			add_property(prop.first, prop.second.m_string, "", prop.second.m_important, el->get_document()->container());
		}
	}
}

} // namespace litehtml