#ifndef LH_CSS_POSITION_H
#define LH_CSS_POSITION_H

#include "css_length.h"

namespace litehtml
{
	struct css_position
	{
		css_length	x;
		css_length	y;
		css_length	width;
		css_length	height;
		#if H3ML
		css_length	z;
		css_length	depth;
		#endif
	};

	struct css_size
	{
		css_length	width;
		css_length	height;
		#if H3ML
		css_length	depth;
		#endif

		css_size() = default;
		#if H3ML
		css_size(css_length width, css_length height, css_length depth) : width(width), height(height), depth(depth) {}
		#else
		css_size(css_length width, css_length height) : width(width), height(height) {}
		#endif
	};

	using size_vector = std::vector<css_size>;
}

#endif  // LH_CSS_POSITION_H
