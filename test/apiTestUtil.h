#ifndef LH_TESTUTIL_H
#define LH_TESTUTIL_H

#include <string>

namespace litehtml
{
	class Date
	{
	public:
		Date();
		Date(int64_t ticks);
		string toLocaleTimeString();
		string toString();
	};

	class Math
	{
	public:
		static int random();
	};
}

#endif  // LH_TESTUTIL_H
