#ifndef LH_CSS_OFFSETS_H
#define LH_CSS_OFFSETS_H

#include "css_length.h"

namespace litehtml
{
	struct css_offsets
	{
		css_length	left;
		css_length	top;
		css_length	right;
		css_length	bottom;
		#if H3ML
		css_length	back;
		css_length	front;
		#endif

		css_offsets() = default;

		css_offsets(const css_offsets& val)
		{
			left	= val.left;
			top		= val.top;
			right	= val.right;
			bottom	= val.bottom;
			#if H3ML
			back	= val.back;
			front	= val.front;
			#endif
		}

		css_offsets& operator=(const css_offsets& val)
		{
			left	= val.left;
			top		= val.top;
			right	= val.right;
			bottom	= val.bottom;
			#if H3ML
			back	= val.back;
			front	= val.front;
			#endif
			return *this;
		}

		string to_string() const
		{
			return	"left: " + left.to_string() +
					", top: " + top.to_string() +
					", right: " + right.to_string() +
					", bottom: " + bottom.to_string()
					#if H3ML
					+ ", back: " + back.to_string() +
					", front: " + front.to_string()
					#endif
					;
		}
	};
}

#endif  // LH_CSS_OFFSETS_H
