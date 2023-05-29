#ifndef LH_API_ANY_H
#define LH_API_ANY_H

namespace litehtml
{
	typedef struct tany_t
	{
		char type[3];
		void* value0;
		tany_t(const char* value) { }
		tany_t(string value) { }
		tany_t(string value[]) { }
		tany_t(std::map<string, string> v) { }
		tany_t(char* t, void* value) { }
	} tany;
#define _a(type, value) tany(#type, value)
}

#endif  // LH_API_ANY_H
