#ifndef LH_TESTUTIL_H
#define LH_TESTUTIL_H

#include <string>

namespace litehtml
{
	class Date
	{
	public:
		string toLocaleTimeString();
	};

	class Math
	{
	public:
		static int random();
	};
}

#endif  // LH_TESTUTIL_H
