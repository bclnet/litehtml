#include "html.h"

/// <summary>
/// to_string
/// </summary>
namespace litehtml
{
	// to_string
	std::string to_string(tany t) { return ""; }
	std::string to_string(std::shared_ptr<Location> t) { return ""; }

	// tfunc
	template <class T1> tfunc to_func(tfunc1<T1> t) { return tfunc(); }
	template <class T1, class T2> tfunc to_func(tfunc2<T1, T2> t) { return tfunc(); }

	template tfunc to_func<MediaQueryList::ptr>(tfunc1<MediaQueryList::ptr>);
	template tfunc to_func<tany, tany>(tfunc2<tany, tany>);
}
