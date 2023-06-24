#ifndef LH_TYPES_H
#define LH_TYPES_H

#include <cstdlib>
#include <memory>
#include <map>
#include <vector>
#include <list>
#include "api.h"

namespace litehtml
{
	class document;
	class element;
	class script_engine;

	typedef std::map<string, string>					string_map;
	typedef std::list< std::shared_ptr<element> >		elements_list;
	typedef std::vector<int>							int_vector;
	typedef std::vector<string>							string_vector;

	const unsigned int font_decoration_none			= 0x00;
	const unsigned int font_decoration_underline	= 0x01;
	const unsigned int font_decoration_linethrough	= 0x02;
	const unsigned int font_decoration_overline		= 0x04;

	typedef unsigned char	byte;
	typedef unsigned int	ucode_t;

	struct margins
	{
		int	left;
		int	right;
		int top;
		int bottom;
		#if H3ML
		int front;
		int back;
		#endif

		margins()
		{
			left = right = top = bottom = 0;
			#if H3ML
			front = back = 0;
			#endif
		}

		int width()		const	{ return left + right; } 
		int height()	const	{ return top + bottom; } 
		#if H3ML
		int depth()		const 	{ return front + back; }
		#endif
	};

	struct point
	{
		int x;
		int y;
		#if H3ML
		int z;
		#endif

		point()
		{
			x = y = 0;
			#if H3ML
			z = 0;
			#endif
		}
		point(int x, int y)
		{
			this->x = x;
			this->y = y;
			#if H3ML
			this->z = 0;
			#endif
		}
		#if H3ML
		point(int x, int y, int z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		#endif

		point operator+(const point& p)
		{
			x += p.x;
			y += p.y;
			#if H3ML
			z += p.z;
			#endif
			return *this;
		}
		point operator-(const point& p)
		{
			x -= p.x;
			y -= p.y;
			#if H3ML
			z -= p.z;
			#endif
			return *this;
		}
	};
	extern point point_zero;

	#if H3ML
	#define POINT(x, y, z) litehtml::point(x, y, z)
	#else
	#define POINT(x, y, z) litehtml::point(x, y)
	#endif

	struct size
	{
		int		width;
		int		height;
		#if H3ML
		int		depth;
		#endif

		#if H3ML
		size(int w, int h, int d) : width(w), height(h), depth(d)
		{
		}
		#endif

		size(int w, int h) : width(w), height(h)
			#if H3ML
			, depth(0)
			#endif
		{
		}

		size() : width(0), height(0)
			#if H3ML
			, depth(0)
			#endif
		{
		}
	};
	extern size size_zero;

	#if H3ML
	#define SIZE(w, h, d) litehtml::size(w, h, d)
	#else
	#define SIZE(w, h, d) litehtml::size(w, h)
	#endif

	struct position : Rect
	{
		typedef std::vector<position>	vector;

		int	x;
		int	y;
		int	width;
		int	height;
		#if H3ML
		int z;
		int depth;
		#endif

		position()
		{
			x = y = width = height = 0;
			#if H3ML
			z = depth = 0;
			#endif
		}

		position(point p, size sz)
		{
			x = p.x;
			y = p.y;
			width = sz.width;
			height = sz.height;
			#if H3ML
			z = p.z;
			depth = sz.depth;
			#endif
		}

		point p() 		const		{ return { x, y
			#if H3ML
			, z
			#endif
		};	}
		size sz()		const		{ return { width, height
			#if H3ML
			, depth
			#endif
		}; }
		int right()		const		{ return x + width;		}
		int bottom()	const		{ return y + height;	}
		int left()		const		{ return x;				}
		int top()		const		{ return y;				}
		#if H3ML
		int front() 	const 		{ return z; 			}
		int back() 		const 		{ return z + depth; 	}
		#endif

		void operator+=(const margins& mg)
		{
			x		-= mg.left;
			y		-= mg.top;
			width	+= mg.left + mg.right;
			height	+= mg.top + mg.bottom;
			#if H3ML
			z		-= mg.front;
			depth 	+= mg.front + mg.back;
			#endif
		}
		void operator-=(const margins& mg)
		{
			x		+= mg.left;
			y		+= mg.top;
			width	-= mg.left + mg.right;
			height	-= mg.top + mg.bottom;
			#if H3ML
			z		+= mg.front;
			depth 	-= mg.front + mg.back;
			#endif
		}

		void clear()
		{
			x = y = width = height = 0;
			#if H3ML
			z = depth = 0;
			#endif
		}

		void operator=(const point& p)
		{
			x = p.x;
			y = p.y;
			#if H3ML
			z = p.z;
			#endif
		}

		void operator=(const size& sz)
		{
			width	= sz.width;
			height	= sz.height;
			#if H3ML
			depth = sz.depth;
			#endif
		}

		void move_to(point p)
		{
			x = p.x;
			y = p.y;
			#if H3ML
			z = p.z;
			#endif
		}

		bool does_intersect(const position* val) const
		{
			if(!val) return true;

			return (
				left()			<= val->right()		&& 
				right()			>= val->left()		&& 
				bottom()		>= val->top()		&& 
				top()			<= val->bottom()
				#if H3ML
				&& front() 		<= val->back() 		&&
				back() 			>= val->front()
				#endif
				) || (
				val->left()		<= right()			&& 
				val->right()	>= left()			&& 
				val->bottom()	>= top()			&& 
				val->top()		<= bottom()			
				#if H3ML
				&& val->front()	<= back() 			&&
				val->back() 	>= front()
				#endif
				);
		}

		bool empty() const
		{
			if(!width && !height
				#if H3ML
				&& !depth
				#endif
			)
			{
				return true;
			}
			return false;
		}

		bool is_point_inside(point p) const
		{
			if(p.x >= left() && p.x <= right() && p.y >= top() && p.y <= bottom()
				#if H3ML
				&& p.z >= front() && p.z <= back()
				#endif
			)
			{
				return true;
			}
			return false;
		}
	};

	struct font_metrics
	{
		int		height;
		int		ascent;
		int		descent;
		int		x_height;
		bool	draw_spaces;

		font_metrics()
		{
			height			= 0;
			ascent			= 0;
			descent			= 0;
			x_height		= 0;
			draw_spaces		= true;
		}
		int base_line() const	{ return descent; }
	};

	struct font_item
	{
		uint_ptr		font;
		font_metrics	metrics;
	};

	typedef std::map<string, font_item> fonts_map;

	enum draw_flag
	{
		draw_root,
		draw_block,
		draw_floats,
		draw_inlines,
		draw_positioned,
	};

	struct containing_block_context
	{
		enum cbc_value_type
		{
			cbc_value_type_absolute,	// width/height of containing block is defined as absolute value
			cbc_value_type_percentage,	// width/height of containing block is defined as percentage
			cbc_value_type_auto,		// width/height of containing block is defined as auto
			cbc_value_type_none,		// min/max width/height of containing block is defined as none
		};

		struct typed_int
		{
			int 			value;
			cbc_value_type	type;

			typed_int(int val, cbc_value_type tp)
			{
				value = val;
				type = tp;
			}

			operator int() const
			{
				return value;
			}

			typed_int& operator=(int val)
			{
				value = val;
				return *this;
			}

			typed_int& operator=(const typed_int& v)
			{
				value = v.value;
				type = v.type;
				return *this;
			}
		};

		typed_int width;						// width of the containing block
		typed_int render_width;
		typed_int min_width;
		typed_int max_width;

		typed_int height;						// height of the containing block
		typed_int min_height;
		typed_int max_height;

		#if H3ML
		typed_int depth;						// depth of the containing block
		typed_int min_depth;
		typed_int max_depth;
		#endif

		int context_idx;

		containing_block_context() :
				width(0, cbc_value_type_auto),
				render_width(0, cbc_value_type_auto),
				min_width(0, cbc_value_type_none),
				max_width(0, cbc_value_type_none),
				height(0, cbc_value_type_auto),
				min_height(0, cbc_value_type_none),
				max_height(0, cbc_value_type_none),
				#if H3ML
				depth(0, cbc_value_type_auto),
				min_depth(0, cbc_value_type_none),
				max_depth(0, cbc_value_type_none),
				#endif
				context_idx(0)
		{}

		containing_block_context new_width(int w) const
		{
			containing_block_context ret = *this;
			//if(ret.width.type != cbc_value_type_absolute)
			{
				ret.render_width = w - (ret.width - ret.render_width);
				ret.width = w;
			}
			return ret;
		}
	};

#define  style_display_strings		"none;block;inline;inline-block;inline-table;list-item;table;table-caption;table-cell;table-column;table-column-group;table-footer-group;table-header-group;table-row;table-row-group;inline-text;flex;inline-flex"

	enum style_display
	{
		display_none,
		display_block,
		display_inline,
		display_inline_block,
		display_inline_table,
		display_list_item,
		display_table,
		display_table_caption,
		display_table_cell,
		display_table_column,
		display_table_column_group,
		display_table_footer_group,
		display_table_header_group,
		display_table_row,
		display_table_row_group,
		display_inline_text,
		display_flex,
		display_inline_flex,
	};

#define  font_size_strings		"xx-small;x-small;small;medium;large;x-large;xx-large;smaller;larger"

	enum font_size
	{
		font_size_xx_small,
		font_size_x_small,
		font_size_small,
		font_size_medium,
		font_size_large,
		font_size_x_large,
		font_size_xx_large,
		font_size_smaller,
		font_size_larger,
	};

#define line_height_strings "normal"

	enum line_height
	{
		line_height_normal
	};

#define  font_style_strings		"normal;italic"

	enum font_style
	{
		font_style_normal,
		font_style_italic
	};

#define  font_variant_strings		"normal;small-caps"

	enum font_variant
	{
		font_variant_normal,
		font_variant_small_caps
	};

#define  font_weight_strings	"normal;bold;bolder;lighter;100;200;300;400;500;600;700;800;900"

	enum font_weight
	{
		font_weight_normal,
		font_weight_bold,
		font_weight_bolder,
		font_weight_lighter,
		font_weight_100,
		font_weight_200,
		font_weight_300,
		font_weight_400,
		font_weight_500,
		font_weight_600,
		font_weight_700,
		font_weight_800,
		font_weight_900
	};

#define  list_style_type_strings	"none;circle;disc;square;armenian;cjk-ideographic;decimal;decimal-leading-zero;georgian;hebrew;hiragana;hiragana-iroha;katakana;katakana-iroha;lower-alpha;lower-greek;lower-latin;lower-roman;upper-alpha;upper-latin;upper-roman"

	enum list_style_type
	{
		list_style_type_none,
		list_style_type_circle,
		list_style_type_disc,
		list_style_type_square,
		list_style_type_armenian,
		list_style_type_cjk_ideographic,
		list_style_type_decimal,
		list_style_type_decimal_leading_zero,
		list_style_type_georgian,
		list_style_type_hebrew,
		list_style_type_hiragana,
		list_style_type_hiragana_iroha,
		list_style_type_katakana,
		list_style_type_katakana_iroha,
		list_style_type_lower_alpha,
		list_style_type_lower_greek,
		list_style_type_lower_latin,
		list_style_type_lower_roman,
		list_style_type_upper_alpha,
		list_style_type_upper_latin,
		list_style_type_upper_roman,
	};

#define  list_style_position_strings	"inside;outside"

	enum list_style_position
	{
		list_style_position_inside,
		list_style_position_outside
	};

#define  vertical_align_strings	"baseline;sub;super;top;text-top;middle;bottom;text-bottom"

	enum vertical_align
	{
		va_baseline,
		va_sub,
		va_super,
		va_top,
		va_text_top,
		va_middle,
		va_bottom,
		va_text_bottom
	};

#define  border_width_strings	"thin;medium;thick"

	enum border_width
	{
		border_width_thin,
		border_width_medium,
		border_width_thick
	};

	const float border_width_thin_value = 1;
	const float border_width_medium_value = 3;
	const float border_width_thick_value = 5;
	const float border_width_values[] = { border_width_thin_value, border_width_medium_value, border_width_thick_value };

#define  border_style_strings	"none;hidden;dotted;dashed;solid;double;groove;ridge;inset;outset"

	enum border_style
	{
		border_style_none,
		border_style_hidden,
		border_style_dotted,
		border_style_dashed,
		border_style_solid,
		border_style_double,
		border_style_groove,
		border_style_ridge,
		border_style_inset,
		border_style_outset
	};

#define  element_float_strings	"none;left;right"

	enum element_float
	{
		float_none,
		float_left,
		float_right
	};

#define  element_clear_strings	"none;left;right;both"

	enum element_clear
	{
		clear_none,
		clear_left,
		clear_right,
		clear_both
	};

#define  css_units_strings	"none;%;in;cm;mm;em;ex;pt;pc;px;dpi;dpcm;vw;vh;vmin;vmax;rem"

	enum css_units : byte
	{
		css_units_none,
		css_units_percentage,
		css_units_in,
		css_units_cm,
		css_units_mm,
		css_units_em,
		css_units_ex,
		css_units_pt,
		css_units_pc,
		css_units_px,
		css_units_dpi,
		css_units_dpcm,
		css_units_vw,
		css_units_vh,
		css_units_vmin,
		css_units_vmax,
		css_units_rem,
	};

#define  background_attachment_strings	"scroll;fixed"

	enum background_attachment
	{
		background_attachment_scroll,
		background_attachment_fixed
	};

#define  background_repeat_strings	"repeat;repeat-x;repeat-y;no-repeat"

	enum background_repeat
	{
		background_repeat_repeat,
		background_repeat_repeat_x,
		background_repeat_repeat_y,
		background_repeat_no_repeat
	};

#define  background_box_strings	"border-box;padding-box;content-box"

	enum background_box
	{
		background_box_border,
		background_box_padding,
		background_box_content
	};

#define  background_position_strings	"top;bottom;left;right;center"

	enum background_position
	{
		background_position_top,
		background_position_bottom,
		background_position_left,
		background_position_right,
		background_position_center,
	};

#define element_position_strings	"static;relative;absolute;fixed"

	enum element_position
	{
		element_position_static,
		element_position_relative,
		element_position_absolute,
		element_position_fixed,
	};

#define text_align_strings		"left;right;center;justify"

	enum text_align
	{
		text_align_left,
		text_align_right,
		text_align_center,
		text_align_justify
	};

#define text_transform_strings		"none;capitalize;uppercase;lowercase"

	enum text_transform
	{
		text_transform_none,
		text_transform_capitalize,
		text_transform_uppercase,
		text_transform_lowercase
	};

#define white_space_strings		"normal;nowrap;pre;pre-line;pre-wrap"

	enum white_space
	{
		white_space_normal,
		white_space_nowrap,
		white_space_pre,
		white_space_pre_line,
		white_space_pre_wrap
	};

#define overflow_strings		"visible;hidden;scroll;auto;no-display;no-content"

	enum overflow
	{
		overflow_visible,
		overflow_hidden,
		overflow_scroll,
		overflow_auto,
		overflow_no_display,
		overflow_no_content
	};

#define background_size_strings		"auto;cover;contain"

	enum background_size
	{
		background_size_auto,
		background_size_cover,
		background_size_contain,
	};

#define visibility_strings			"visible;hidden;collapse"

	enum visibility
	{
		visibility_visible,
		visibility_hidden,
		visibility_collapse,
	};

#define border_collapse_strings		"collapse;separate"

	enum border_collapse
	{
		border_collapse_collapse,
		border_collapse_separate,
	};

#define content_property_string		"none;normal;open-quote;close-quote;no-open-quote;no-close-quote"

	enum content_property
	{
		content_property_none,
		content_property_normal,
		content_property_open_quote,
		content_property_close_quote,
		content_property_no_open_quote,
		content_property_no_close_quote,
	};

	class render_item;

	struct floated_box
	{
		position		                pos;
		element_float	                float_side;
		element_clear	                clear_floats;
		std::shared_ptr<render_item>	el;
		int								context;
		int 							min_width;

		floated_box() = default;
		floated_box(const floated_box& val)
		{
			pos = val.pos;
			float_side = val.float_side;
			clear_floats = val.clear_floats;
			el = val.el;
			context = val.context;
			min_width = val.min_width;
		}
		floated_box& operator=(const floated_box& val)
		{
			pos = val.pos;
			float_side = val.float_side;
			clear_floats = val.clear_floats;
			el = val.el;
			context = val.context;
			min_width = val.min_width;
			return *this;
		}
		floated_box(floated_box&& val)
		{
			pos = val.pos;
			float_side = val.float_side;
			clear_floats = val.clear_floats;
			el = std::move(val.el);
			context = val.context;
			min_width = val.min_width;
		}
		void operator=(floated_box&& val)
		{
			pos = val.pos;
			float_side = val.float_side;
			clear_floats = val.clear_floats;
			el = std::move(val.el);
			context = val.context;
			min_width = val.min_width;
		}
	};

	struct int_int_cache
	{
		int		hash;
		int		val;
		bool	is_valid;
		bool	is_default;

		int_int_cache()
		{
			hash		= 0;
			val			= 0;
			is_valid	= false;
			is_default	= false;
		}
		void invalidate()
		{
			is_valid	= false;
			is_default	= false;
		}
		void set_value(int vHash, int vVal)
		{
			hash		= vHash;
			val			= vVal;
			is_valid	= true;
		}
	};

	enum select_result
	{
		select_no_match				= 0x00,
		select_match				= 0x01,
		select_match_pseudo_class	= 0x02,
		select_match_with_before	= 0x10,
		select_match_with_after		= 0x20,
	};

	template<class T>
	class def_value
	{
		T		m_val;
		bool	m_is_default;
	public:
		def_value(T def_val)
		{
			m_is_default	= true;
			m_val			= def_val;
		}
		void reset(T def_val)
		{
			m_is_default	= true;
			m_val			= def_val;
		}
		bool is_default()
		{
			return m_is_default;
		}
		T operator=(T new_val)
		{
			m_val			= new_val;
			m_is_default	= false;
			return m_val;
		}
		operator T()
		{
			return m_val;
		}
	};


#define media_orientation_strings		"portrait;landscape"

	enum media_orientation
	{
		media_orientation_portrait,
		media_orientation_landscape,
	};

#if H3ML
#define media_feature_strings		"none;width;min-width;max-width;height;min-height;max-height;depth;min-depth;max-depth;device-width;min-device-width;max-device-width;device-height;min-device-height;max-device-height;device-depth;min-device-depth;max-device-depth;orientation;aspect-ratio;min-aspect-ratio;max-aspect-ratio;device-aspect-ratio;min-device-aspect-ratio;max-device-aspect-ratio;color;min-color;max-color;color-index;min-color-index;max-color-index;monochrome;min-monochrome;max-monochrome;resolution;min-resolution;max-resolution"
#else
#define media_feature_strings		"none;width;min-width;max-width;height;min-height;max-height;device-width;min-device-width;max-device-width;device-height;min-device-height;max-device-height;orientation;aspect-ratio;min-aspect-ratio;max-aspect-ratio;device-aspect-ratio;min-device-aspect-ratio;max-device-aspect-ratio;color;min-color;max-color;color-index;min-color-index;max-color-index;monochrome;min-monochrome;max-monochrome;resolution;min-resolution;max-resolution"
#endif
	enum media_feature
	{
		media_feature_none,

		media_feature_width,
		media_feature_min_width,
		media_feature_max_width,

		media_feature_height,
		media_feature_min_height,
		media_feature_max_height,

		#if H3ML
		media_feature_depth,
		media_feature_min_depth,
		media_feature_max_depth,
		#endif

		media_feature_device_width,
		media_feature_min_device_width,
		media_feature_max_device_width,

		media_feature_device_height,
		media_feature_min_device_height,
		media_feature_max_device_height,

		#if H3ML
		media_feature_device_depth,
		media_feature_min_device_depth,
		media_feature_max_device_depth,
		#endif

		media_feature_orientation,

		media_feature_aspect_ratio,
		media_feature_min_aspect_ratio,
		media_feature_max_aspect_ratio,

		media_feature_device_aspect_ratio,
		media_feature_min_device_aspect_ratio,
		media_feature_max_device_aspect_ratio,

		media_feature_color,
		media_feature_min_color,
		media_feature_max_color,

		media_feature_color_index,
		media_feature_min_color_index,
		media_feature_max_color_index,

		media_feature_monochrome,
		media_feature_min_monochrome,
		media_feature_max_monochrome,

		media_feature_resolution,
		media_feature_min_resolution,
		media_feature_max_resolution,
	};

#define box_sizing_strings		"content-box;border-box"

	enum box_sizing
	{
		box_sizing_content_box,
		box_sizing_border_box,
	};


#define media_type_strings		"none;all;screen;print;braille;embossed;handheld;projection;speech;tty;tv"

	enum media_type
	{
		media_type_none,
		media_type_all,
		media_type_screen,
		media_type_print,
		media_type_braille,
		media_type_embossed,
		media_type_handheld,
		media_type_projection,
		media_type_speech,
		media_type_tty,
		media_type_tv,
	};

	struct media_features
	{
		media_type	type;
		int			width;			// (pixels) For continuous media, this is the width of the viewport including the size of a rendered scroll bar (if any). For paged media, this is the width of the page box.
		int			height;			// (pixels) The height of the targeted display area of the output device. For continuous media, this is the height of the viewport including the size of a rendered scroll bar (if any). For paged media, this is the height of the page box.
		int			device_width;	// (pixels) The width of the rendering surface of the output device. For continuous media, this is the width of the screen. For paged media, this is the width of the page sheet size.
		int			device_height;	// (pixels) The height of the rendering surface of the output device. For continuous media, this is the height of the screen. For paged media, this is the height of the page sheet size.
		int			color;			// The number of bits per color component of the output device. If the device is not a color device, the value is zero.
		int			color_index;	// The number of entries in the color lookup table of the output device. If the device does not use a color lookup table, the value is zero.
		int			monochrome;		// The number of bits per pixel in a monochrome frame buffer. If the device is not a monochrome device, the output device value will be 0.
		int			resolution;		// The resolution of the output device (in DPI)
		#if H3ML
		int			depth;			// (pixels) The depth of the targeted display area of the output device. For continuous media, this is the depth of the viewport including the size of a rendered scroll bar (if any). For paged media, this is the depth of the page box.
		int			device_depth;	// (pixels) The depth of the rendering surface of the output device. For continuous media, this is the depth of the screen. For paged media, this is the depth of the page sheet size.
		#endif

		media_features()
		{
			type = media_type::media_type_none,
			width =0;
			height = 0;
			device_width = 0;
			device_height = 0;
			color = 0;
			color_index = 0;
			monochrome = 0;
			resolution = 0;
			#if H3ML
			depth = 0;
			device_depth = 0;
			#endif
		}
	};

	enum render_type
	{
		render_all,
		render_no_fixed,
		render_fixed_only,
	};

	// List of the Void Elements (can't have any contents)
	const char* const void_elements = "area;base;br;col;command;embed;hr;img;input;keygen;link;meta;param;source;track;wbr";

#define flex_direction_strings		"row;row-reverse;column;column-reverse"

	enum flex_direction
	{
		flex_direction_row,
		flex_direction_row_reverse,
		flex_direction_column,
		flex_direction_column_reverse
	};

#define flex_wrap_strings		"nowrap;wrap;wrap-reverse"

	enum flex_wrap
	{
		flex_wrap_nowrap,
		flex_wrap_wrap,
		flex_wrap_wrap_reverse
	};

#define flex_justify_content_strings		"flex-start;flex-end;center;space-between;space-around"

	enum flex_justify_content
	{
		flex_justify_content_flex_start,
		flex_justify_content_flex_end,
		flex_justify_content_center,
		flex_justify_content_space_between,
		flex_justify_content_space_around
	};

#define flex_align_items_strings		"flex-start;flex-end;center;baseline;stretch"

	enum flex_align_items
	{
		flex_align_items_flex_start,
		flex_align_items_flex_end,
		flex_align_items_center,
		flex_align_items_baseline,
		flex_align_items_stretch
	};

#define flex_align_self_strings		"auto;flex-start;flex-end;center;baseline;stretch"

	enum flex_align_self
	{
		flex_align_self_auto,
		flex_align_self_flex_start,
		flex_align_self_flex_end,
		flex_align_self_center,
		flex_align_self_baseline,
		flex_align_self_stretch
	};

#define flex_align_content_strings		"flex-start;flex-end;center;space-between;space-around;stretch"

	enum flex_align_content
	{
		flex_align_content_flex_start,
		flex_align_content_flex_end,
		flex_align_content_center,
		flex_align_content_space_between,
		flex_align_content_space_around,
		flex_align_content_stretch
	};

#define flex_basis_strings		"auto;content;fit-content;min-content;max-content"

	enum flex_basis
	{
		flex_basis_auto,
		flex_basis_content,
		flex_basis_fit_content,
		flex_basis_min_content,
		flex_basis_max_content,
	};

}

#endif  // LH_TYPES_H
