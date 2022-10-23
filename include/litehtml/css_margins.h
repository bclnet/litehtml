#ifndef LH_CSS_MARGINS_H
#define LH_CSS_MARGINS_H

#include "css_length.h"

namespace litehtml
{
	struct css_margins
	{
		css_length	left;
		css_length	right;
		css_length	top;
		css_length	bottom;
		#if H3ML
		css_length	front;
		css_length	back;
		#endif

		css_margins() = default;

		css_margins(const css_margins& val)
		{
			left	= val.left;
			right	= val.right;
			top		= val.top;
			bottom	= val.bottom;
			#if H3ML
			front	= val.front;
			back	= val.back;
			#endif
		}

		css_margins& operator=(const css_margins& val)
		{
			left	= val.left;
			right	= val.right;
			top		= val.top;
			bottom	= val.bottom;
			#if H3ML
			front	= val.front;
			back	= val.back;
			#endif
			return *this;
		}

        string to_string()
        {
            return "left: " + left.to_string() +
                   ", right: " + right.to_string() +
                   ", top: " + top.to_string() +
                   ", bottom: " + bottom.to_string()
				   #if H3ML
				   + ", front: " + front.to_string() +
				   ", back: " + back.to_string()
				   #endif
		   		   ;
        }
	};
}

#endif  // LH_CSS_MARGINS_H
