#ifndef LH_CSS_POSITION_H
#define LH_CSS_POSITION_H

#include "css_length.h"

namespace litehtml
{
	struct css_position
	{
		css_length	x;
		css_length	y;
		#if H3ML
		css_length	z;
		#endif
		css_length	width;
		css_length	height;
		#if H3ML
		css_length	depth;
		#endif

		css_position() = default;

		css_position(const css_position& val)
		{
			x		= val.x;
			y		= val.y;
			width	= val.width;
			height	= val.height;
			#if H3ML
			z		= val.z;
			depth	= val.depth;
			#endif
		}

		css_position& operator=(const css_position& val)
		{
			x		= val.x;
			y		= val.y;
			width	= val.width;
			height	= val.height;
			#if H3ML
			z		= val.z;
			depth	= val.depth;
			#endif
			return *this;
		}
	};
}

#endif  // LH_CSS_POSITION_H
