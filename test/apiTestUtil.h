#ifndef LH_TESTUTIL_H
#define LH_TESTUTIL_H

#include <string_view>
#include <iostream>
#include <string>

namespace litehtml
{
	/// <summary>
	/// Number
	/// </summary>
	#define Number(a) 0

	/// <summary>
	/// Date
	/// </summary>
	class Date
	{
	public:
		Date();
		Date(int64_t ticks);
		static Date now();
		std::string toLocaleTimeString();
		//std::string toString();
	};
	std::string to_string(Date t);

	/// <summary>
	/// Math
	/// </summary>
	class Math
	{
	public:
		static int random();
	};

	/// <summary>
	/// string_hash
	/// </summary>
	// https://learnmoderncpp.com/2020/06/01/strings-as-switch-case-labels/
	inline constexpr auto string_hash(const std::string_view sv) {
		unsigned long hash { 5381 };
		for (unsigned char c : sv) hash = ((hash << 5) + hash) ^ c;
		return hash;
	}

	inline constexpr auto operator"" _sh(const char* str, size_t len) {
		return string_hash(std::string_view { str, len });
	}
}

#endif  // LH_TESTUTIL_H
