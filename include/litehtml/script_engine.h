#ifndef LH_SCRIPT_ENGINE_H
#define LH_SCRIPT_ENGINE_H

#include <string>
#include "api.h"

namespace litehtml
{
	class script_engine
	{
	public:
		void addScript(const Document* doc, const tchar_t* function);
		void addEvent(const Element* el, const tchar_t* event, const tchar_t* function);
	};
}

#endif  // LH_SCRIPT_ENGINE_H
