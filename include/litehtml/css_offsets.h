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
		css_length	front;
		css_length	back;
		#endif

		css_offsets() = default;

		css_offsets(const css_offsets& val)
		{
			left	= val.left;
			top		= val.top;
			right	= val.right;
			bottom	= val.bottom;
			#if H3ML
			front	= val.front;
			back	= val.back;
			#endif
		}

		css_offsets& operator=(const css_offsets& val)
		{
			left	= val.left;
			top		= val.top;
			right	= val.right;
			bottom	= val.bottom;
			#if H3ML
			front	= val.front;
			back	= val.back;
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
					+ ", front: " + front.to_string() +
					", back: " + back.to_string()
					#endif
					;
		}
	};
}

#endif  // LH_CSS_OFFSETS_H
