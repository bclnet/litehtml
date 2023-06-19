#ifndef LH_API_ANY_H
#define LH_API_ANY_H

#include <any>
#include <functional>

namespace litehtml
{
	// tany
	using tany = std::any;

	// to_string
	class Location;
	std::string to_string(tany t);
	std::string to_string(std::shared_ptr<Location> t);

	// tfunc
	using tfunc = std::function<void()>;
	template <class T1> using tfunc1 = std::function<void(T1)>;
	template <class T1, class T2> using tfunc2 = std::function<void(T1, T2)>;

	using _f = tfunc;
	template <class T1> using _f1 = tfunc1<T1>;
	template <class T1, class T2> using _f2 = tfunc2<T1, T2>;

	template <class T1> tfunc to_func(tfunc1<T1> t);
	template <class T1, class T2> tfunc to_func(tfunc2<T1, T2> t);
}

#endif  // LH_API_ANY_H

/*typedef struct tany_t
{
	char type[3];
	void* value0;
	tany_t(const char* value) { }
	tany_t(std::string value) { }
	tany_t(std::string value[]) { }
	tany_t(std::map<string, string> v) { }
	tany_t(char* t, void* value) { }
} tany;
#define _a(type, value) tany(#type, value)*/