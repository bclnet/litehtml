#ifndef LH_SCRIPT_ENGINE_H
#define LH_SCRIPT_ENGINE_H

#include <string>
#include "api.h"

namespace litehtml
{
	class script_engine
	{
	public:
		void addScript(const Document* doc, const char* function);
		void addEvent(const Element* el, const char* event, const char* function);
	};
}

#endif  // LH_SCRIPT_ENGINE_H
