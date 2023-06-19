#include "html.h"

/// <summary>
/// EventTarget
/// </summary>
namespace litehtml
{
	EventTarget::EventTarget() {}

	/// <summary>
	/// Attaches an event handler to the document
	/// </summary>
	/// <param name="evnt">The event.</param>
	/// <param name="function">The function.</param>
	/// <param name="useCapture">if set to <c>true</c> [use capture].</param>
	void EventTarget::addEventListener(string evnt, tfunc function, bool useCapture/* = false*/) { }

	void EventTarget::dispatchEvent(EventTarget::ptr evnt) { }

	/// <summary>
	/// Removes an event handler from the document (that has been attached with the addEventListener() method)
	/// </summary>
	/// <param name="evnt">The event.</param>
	/// <param name="function">The function.</param>
	/// <param name="useCapture">if set to <c>true</c> [use capture].</param>
	void EventTarget::removeEventListener(string evnt, tfunc function, bool useCapture/* = false*/) { }
}