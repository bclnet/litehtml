#ifndef LH_BORDERS_H
#define LH_BORDERS_H

#include "css_length.h"
#include "types.h"
#include "web_color.h"

namespace litehtml
{
	struct css_border
	{
		css_length		width;
		border_style	style;
		web_color		color;

		css_border()
		{
			style = border_style_none;
		}

		css_border(const css_border& val)
		{
			width	= val.width;
			style	= val.style;
			color	= val.color;
		}

		css_border& operator=(const css_border& val)
		{
			width	= val.width;
			style	= val.style;
			color	= val.color;
			return *this;
		}

		string to_string();
	};

	struct border
	{
		int				width;
		border_style	style;
		web_color		color;

		border()
		{
			width = 0;
		}
		border(const border& val)
		{
			width = val.width;
			style = val.style;
			color = val.color;
		}
		border(const css_border& val)
		{
			width = (int)val.width.val();
			style = val.style;
			color = val.color;
		}
		border& operator=(const border& val)
		{
			width = val.width;
			style = val.style;
			color = val.color;
			return *this;
		}
		border& operator=(const css_border& val)
		{
			width = (int)val.width.val();
			style = val.style;
			color = val.color;
			return *this;
		}
	};

	struct border_radiuses
	{
		int	top_left_x;
		int	top_left_y;
		#if H3ML
		int	top_left_z;
		#endif

		int	top_right_x;
		int	top_right_y;
		#if H3ML
		int	top_right_z;
		#endif

		int	bottom_right_x;
		int	bottom_right_y;
		#if H3ML
		int	bottom_right_z;
		#endif

		int	bottom_left_x;
		int	bottom_left_y;
		#if H3ML
		int	bottom_left_z;
		#endif

		border_radiuses()
		{
			top_left_x = 0;
			top_left_y = 0;
			top_right_x = 0;
			top_right_y = 0;
			bottom_right_x = 0;
			bottom_right_y = 0;
			bottom_left_x = 0;
			bottom_left_y = 0;
			#if H3ML
			top_left_z = 0;
			top_right_z = 0;
			bottom_right_z = 0;
			bottom_left_z = 0;
			#endif
		}
		border_radiuses(const border_radiuses& val)
		{
			top_left_x = val.top_left_x;
			top_left_y = val.top_left_y;
			top_right_x = val.top_right_x;
			top_right_y = val.top_right_y;
			bottom_right_x = val.bottom_right_x;
			bottom_right_y = val.bottom_right_y;
			bottom_left_x = val.bottom_left_x;
			bottom_left_y = val.bottom_left_y;
			#if H3ML
			top_left_z = val.top_left_z;
			top_right_z = val.top_right_z;
			bottom_right_z = val.bottom_right_z;
			bottom_left_z = val.bottom_left_z;
			#endif
		}
		border_radiuses& operator = (const border_radiuses& val)
		{
			top_left_x = val.top_left_x;
			top_left_y = val.top_left_y;
			top_right_x = val.top_right_x;
			top_right_y = val.top_right_y;
			bottom_right_x = val.bottom_right_x;
			bottom_right_y = val.bottom_right_y;
			bottom_left_x = val.bottom_left_x;
			bottom_left_y = val.bottom_left_y;
			#if H3ML
			top_left_z = val.top_left_z;
			top_right_z = val.top_right_z;
			bottom_right_z = val.bottom_right_z;
			bottom_left_z = val.bottom_left_z;
			#endif
			return *this;
		}
		void operator += (const margins& mg)
		{
			top_left_x += mg.left;
			top_left_y += mg.top;
			top_right_x += mg.right;
			top_right_y += mg.top;
			bottom_right_x += mg.right;
			bottom_right_y += mg.bottom;
			bottom_left_x += mg.left;
			bottom_left_y += mg.bottom;
			#if H3ML
			top_left_z += mg.front;
			top_right_z += mg.front;
			bottom_right_z += mg.back;
			bottom_left_z += mg.back;
			#endif
			fix_values();
		}
		void operator -= (const margins& mg)
		{
			top_left_x -= mg.left;
			top_left_y -= mg.top;
			top_right_x -= mg.right;
			top_right_y -= mg.top;
			bottom_right_x -= mg.right;
			bottom_right_y -= mg.bottom;
			bottom_left_x -= mg.left;
			bottom_left_y -= mg.bottom;
			#if H3ML
			top_left_z -= mg.front;
			top_right_z -= mg.front;
			bottom_right_z -= mg.back;
			bottom_left_z -= mg.back;
			#endif
			fix_values();
		}
		void fix_values()
		{
			if (top_left_x < 0)	top_left_x = 0;
			if (top_left_y < 0)	top_left_y = 0;
			if (top_right_x < 0) top_right_x = 0;
			if (top_right_y < 0) top_right_y = 0;
			if (bottom_right_x < 0) bottom_right_x = 0;
			if (bottom_right_y < 0) bottom_right_y = 0;
			if (bottom_left_x < 0) bottom_left_x = 0;
			if (bottom_left_y < 0) bottom_left_y = 0;
			#if H3ML
			if (top_left_z < 0)	top_left_z = 0;
			if (top_right_z < 0) top_right_z = 0;
			if (bottom_right_z < 0) bottom_right_z = 0;
			if (bottom_left_z < 0) bottom_left_z = 0;
			#endif
		}
	};

	struct css_border_radius
	{
		css_length	top_left_x;
		css_length	top_left_y;
		#if H3ML
		css_length	top_left_z;
		#endif

		css_length	top_right_x;
		css_length	top_right_y;
		#if H3ML
		css_length	top_right_z;
		#endif

		css_length	bottom_right_x;
		css_length	bottom_right_y;
		#if H3ML
		css_length	bottom_right_z;
		#endif

		css_length	bottom_left_x;
		css_length	bottom_left_y;
		#if H3ML
		css_length	bottom_left_z;
		#endif

		css_border_radius()
		{
		}

		css_border_radius(const css_border_radius& val)
		{
			top_left_x		= val.top_left_x;
			top_left_y		= val.top_left_y;
			top_right_x		= val.top_right_x;
			top_right_y		= val.top_right_y;
			bottom_left_x	= val.bottom_left_x;
			bottom_left_y	= val.bottom_left_y;
			bottom_right_x	= val.bottom_right_x;
			bottom_right_y	= val.bottom_right_y;
			#if H3ML
			top_left_z		= val.top_left_z;
			top_right_z		= val.top_right_z;
			bottom_left_z	= val.bottom_left_z;
			bottom_right_z	= val.bottom_right_z;
			#endif
		}

		css_border_radius& operator=(const css_border_radius& val)
		{
			top_left_x		= val.top_left_x;
			top_left_y		= val.top_left_y;
			top_right_x		= val.top_right_x;
			top_right_y		= val.top_right_y;
			bottom_left_x	= val.bottom_left_x;
			bottom_left_y	= val.bottom_left_y;
			bottom_right_x	= val.bottom_right_x;
			bottom_right_y	= val.bottom_right_y;
			#if H3ML
			top_left_z		= val.top_left_z;
			top_right_z		= val.top_right_z;
			bottom_left_z	= val.bottom_left_z;
			bottom_right_z	= val.bottom_right_z;
			#endif
			return *this;
		}
		
		border_radiuses calc_percents(const size& sz) const
		{
			border_radiuses ret;
			ret.bottom_left_x = bottom_left_x.calc_percent(sz.width);
			ret.bottom_left_y = bottom_left_y.calc_percent(sz.height);
			ret.top_left_x = top_left_x.calc_percent(sz.width);
			ret.top_left_y = top_left_y.calc_percent(sz.height);
			ret.top_right_x = top_right_x.calc_percent(sz.width);
			ret.top_right_y = top_right_y.calc_percent(sz.height);
			ret.bottom_right_x = bottom_right_x.calc_percent(sz.width);
			ret.bottom_right_y = bottom_right_y.calc_percent(sz.height);
			#if H3ML
			ret.bottom_left_z = bottom_left_z.calc_percent(sz.depth);
			ret.top_left_z = top_left_z.calc_percent(sz.depth);
			ret.top_right_z = top_right_z.calc_percent(sz.depth);
			ret.bottom_right_z = bottom_right_z.calc_percent(sz.depth);
			#endif
			return ret;
		}
	};

	struct css_borders
	{
		css_border			left;
		css_border			top;
		css_border			right;
		css_border			bottom;
		#if H3ML
		css_border			front;
		css_border			back;
		#endif
		css_border_radius	radius;

		css_borders() = default;

		bool is_visible() const
		{
			return left.width.val() != 0 || right.width.val() != 0 || top.width.val() != 0 || bottom.width.val() != 0
			#if H3ML
			|| front.width.val() != 0 || back.width.val() != 0
			#endif
			;
		}

		css_borders(const css_borders& val)
		{
			left	= val.left;
			right	= val.right;
			top		= val.top;
			bottom	= val.bottom;
			#if H3ML
			front	= val.front;
			back	= val.back;
			#endif
			radius	= val.radius;
		}

		css_borders& operator=(const css_borders& val)
		{
			left	= val.left;
			right	= val.right;
			top		= val.top;
			bottom	= val.bottom;
			#if H3ML
			front	= val.front;
			back	= val.back;
			#endif
			radius	= val.radius;
			return *this;
		}
		
		string to_string()
		{
			return "left: " + left.to_string() +
				", top: " + top.to_string() +
				", right: " + right.to_string() +
				", bottom: " + bottom.to_string()
				#if H3ML
				+ ", front: " + front.to_string() +
				", back: " + back.to_string()
				#endif
				;
		}
	};

	struct borders
	{
		border			left;
		border			top;
		border			right;
		border			bottom;
		#if H3ML
		border			front;
		border			back;
		#endif
		border_radiuses	radius;

		borders() = default;

		borders(const borders& val)
		{
			left = val.left;
			right = val.right;
			top = val.top;
			bottom = val.bottom;
			#if H3ML
			front = val.front;
			back = val.back;
			#endif
			radius = val.radius;
		}

		borders(const css_borders& val)
		{
			left = val.left;
			right = val.right;
			top = val.top;
			bottom = val.bottom;
			#if H3ML
			front = val.front;
			back = val.back;
			#endif
		}

		bool is_visible() const
		{
			return left.width != 0 || right.width != 0 || top.width != 0 || bottom.width != 0
			#if H3ML
			|| front.width != 0 || back.width != 0
			#endif
			;
		}

		borders& operator=(const borders& val)
		{
			left = val.left;
			right = val.right;
			top = val.top;
			bottom = val.bottom;
			#if H3ML
			front = val.front;
			back = val.back;
			#endif
			radius = val.radius;
			return *this;
		}

		borders& operator=(const css_borders& val)
		{
			left = val.left;
			right = val.right;
			top = val.top;
			bottom = val.bottom;
			#if H3ML
			front = val.front;
			back = val.back;
			#endif
			return *this;
		}
	};
}

#endif  // LH_BORDERS_H
