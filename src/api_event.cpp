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

	void EventTarget::dispatchEvent(std::shared_ptr<Event> evnt) { }

	/// <summary>
	/// Removes an event handler from the document (that has been attached with the addEventListener() method)
	/// </summary>
	/// <param name="evnt">The event.</param>
	/// <param name="function">The function.</param>
	/// <param name="useCapture">if set to <c>true</c> [use capture].</param>
	void EventTarget::removeEventListener(string evnt, tfunc function, bool useCapture/* = false*/) { }
}

/// <summary>
/// UiEvent
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Returns a number with details about the event
	/// </summary>
	/// <value>The detail.</value>
	int UiEvent::detail() { return 0; }

	/// <summary>
	/// Returns a reference to the Window object where the event occurred
	/// </summary>
	/// <value>The view.</value>
	Window* UiEvent::view() { return nullptr; }
}

/// <summary>
/// MouseEvent
/// </summary>
namespace litehtml
{
	/// <summary>
	/// 
	/// </summary>
	void MouseEvent::initMouseEvent(string type, bool canBubble, bool cancelable, std::shared_ptr<Window> view, int detail, int screenX, int screenY, int clientX, int clientY, bool ctrlKey, bool altKey, bool shiftKey, bool metaKey, int button, Event::ptr relatedTarget) { }

	/// <summary>
	/// Returns whether the "ALT" key was pressed when the mouse event was triggered
	/// </summary>
	/// <value><c>true</c> if [alt key]; otherwise, <c>false</c>.</value>
	bool MouseEvent::altKey() { return false; }

	/// <summary>
	/// Returns which mouse button was pressed when the mouse event was triggered
	/// </summary>
	/// <value>The button.</value>
	int MouseEvent::button() { return 0; }

	/// <summary>
	/// Returns which mouse buttons were pressed when the mouse event was triggered
	/// </summary>
	/// <value>The buttons.</value>
	int MouseEvent::buttons() { return 0; }

	/// <summary>
	/// Returns the horizontal coordinate of the mouse pointer, relative to the current window, when the mouse event was triggered
	/// </summary>
	/// <value>The client x.</value>
	int MouseEvent::clientX() { return 0; }

	/// <summary>
	/// Returns the vertical coordinate of the mouse pointer, relative to the current window, when the mouse event was triggered
	/// </summary>
	/// <value>The client y.</value>
	int MouseEvent::clientY() { return 0; }

	/// <summary>
	/// Returns whether the "CTRL" key was pressed when the mouse event was triggered
	/// </summary>
	/// <value>The control key.</value>
	int MouseEvent::ctrlKey() { return 0; }

	/// <summary>
	/// Returns true if the specified key is activated
	/// </summary>
	/// <param name="modifierKey">The modifier key.</param>
	/// <returns><c>true</c> if XXXX, <c>false</c> otherwise.</returns>
	/// <exception cref="System.NotImplementedException"></exception>
	bool MouseEvent::getModifierState(wchar_t* modifierKey) { return false; }

	/// <summary>
	/// Returns whether the "META" key was pressed when an event was triggered
	/// </summary>
	/// <value><c>true</c> if [meta key]; otherwise, <c>false</c>.</value>
	bool MouseEvent::metaKey() { return false; }

	/// <summary>
	/// Returns the horizontal coordinate of the mouse pointer relative to the position of the last mousemove event
	/// </summary>
	/// <value>The movement x.</value>
	int MouseEvent::movementX() { return 0; }

	/// <summary>
	/// Returns the vertical coordinate of the mouse pointer relative to the position of the last mousemove event
	/// </summary>
	/// <value>The movement y.</value>
	int MouseEvent::movementY() { return 0; }

	/// <summary>
	/// Returns the horizontal coordinate of the mouse pointer relative to the position of the edge of the target element
	/// </summary>
	/// <value>The offset x.</value>
	int MouseEvent::offsetX() { return 0; }

	/// <summary>
	/// Returns the vertical coordinate of the mouse pointer relative to the position of the edge of the target element
	/// </summary>
	/// <value>The offset y.</value>
	int MouseEvent::offsetY() { return 0; }

	/// <summary>
	/// Returns the horizontal coordinate of the mouse pointer, relative to the document, when the mouse event was triggered
	/// </summary>
	/// <value>The page x.</value>
	int MouseEvent::pageX() { return 0; }

	/// <summary>
	/// Returns the vertical coordinate of the mouse pointer, relative to the document, when the mouse event was triggered
	/// </summary>
	/// <value>The page y.</value>
	int MouseEvent::pageY() { return 0; }

	/// <summary>
	/// Gets the region.
	/// </summary>
	/// <value>The region.</value>
	string MouseEvent::region() { return ""; }

	/// <summary>
	/// Returns the element related to the element that triggered the mouse event
	/// </summary>
	/// <value>The related target.</value>
	Element* MouseEvent::relatedTarget() { return nullptr; }

	/// <summary>
	/// Returns the horizontal coordinate of the mouse pointer, relative to the screen, when an event was triggered
	/// </summary>
	/// <value>The screen x.</value>
	int MouseEvent::screenX() { return 0; }

	/// <summary>
	/// Returns the vertical coordinate of the mouse pointer, relative to the screen, when an event was triggered
	/// </summary>
	/// <value>The screen y.</value>
	int MouseEvent::screenY() { return 0; }

	/// <summary>
	/// Returns whether the "SHIFT" key was pressed when an event was triggered
	/// </summary>
	/// <value><c>true</c> if [shift key]; otherwise, <c>false</c>.</value>
	bool MouseEvent::shiftKey() { return false; }

	/// <summary>
	/// Returns which mouse button was pressed when the mouse event was triggered
	/// </summary>
	/// <value>The which.</value>
	int MouseEvent::which() { return 0; }
}

/// <summary>
/// AnimationEvent
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Returns the name of the animation
	/// </summary>
	/// <value>The name of the animation.</value>
	string AnimationEvent::animationName() { return ""; }

	/// <summary>
	/// Returns the number of seconds an animation has been running
	/// </summary>
	/// <value>The elapsed time.</value>
	int AnimationEvent::elapsedTime() { return 0; }

	/// <summary>
	/// Returns the name of the pseudo-element of the animation
	/// </summary>
	/// <value>The pseudo element.</value>
	string AnimationEvent::pseudoElement() { return ""; }
}

/// <summary>
/// ClipboardEvent
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Returns an object containing the data affected by the clipboard operation
	/// </summary>
	/// <value>The clipboard data.</value>
	void* ClipboardEvent::clipboardData() { return nullptr; }
}

/// <summary>
/// DragEvent
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Returns the data that is dragged/dropped
	/// </summary>
	/// <value>The data transfer.</value>
	void* DragEvent::dataTransfer() { return nullptr; }
}

/// <summary>
/// FocusEvent
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Returns the element related to the element that triggered the event
	/// </summary>
	/// <value>The related target.</value>
	void* FocusEvent::relatedTarget() { return nullptr; }
}

/// <summary>
/// HashChangeEvent
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Returns the URL of the document, after the hash has been changed
	/// </summary>
	/// <value>The new URL.</value>
	wchar_t* HashChangeEvent::newURL() { return nullptr; }

	/// <summary>
	/// Returns the URL of the document, before the hash was changed
	/// </summary>
	/// <value>The old URL.</value>
	wchar_t* HashChangeEvent::oldURL() { return nullptr; }
}

/// <summary>
/// InputEvent
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Returns the inserted characters
	/// </summary>
	/// <value>The data.</value>
	void* InputEvent::data() { return nullptr; }

	/// <summary>
	/// Returns an object containing information about the inserted/deleted data
	/// </summary>
	/// <value>The data transfer.</value>
	void* InputEvent::dataTransfer() { return nullptr; }

	/// <summary>
	/// Returns an array containing target ranges that will be affected by the insertion/deletion
	/// </summary>
	/// <returns>System.String[].</returns>
	/// <exception cref="NotImplementedException"></exception>
	wchar_t** InputEvent::getTargetRanges() { return nullptr; }

	/// <summary>
	/// Returns the type of the change (i.e "inserting" or "deleting")
	/// </summary>
	/// <value>The type of the input.</value>
	string InputEvent::inputType() { return ""; }

	/// <summary>
	/// Returns whether the state of the event is composing or not
	/// </summary>
	/// <value>The is composing.</value>
	string InputEvent::isComposing() { return ""; }
}

/// <summary>
/// KeyboardEvent
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Returns whether the "ALT" key was pressed when the key event was triggered
	/// </summary>
	/// <value><c>true</c> if [alt key]; otherwise, <c>false</c>.</value>
	bool KeyboardEvent::altKey() { return false; }

	/// <summary>
	/// Returns the Unicode character code of the key that triggered the event
	/// </summary>
	/// <value>The character code.</value>
	int KeyboardEvent::charCode() { return 0; }

	/// <summary>
	/// Returns the code of the key that triggered the event
	/// </summary>
	/// <value>The code.</value>
	wchar_t* KeyboardEvent::code() { return nullptr; }

	/// <summary>
	/// Returns whether the "CTRL" key was pressed when the key event was triggered
	/// </summary>
	/// <value><c>true</c> if [control key]; otherwise, <c>false</c>.</value>
	bool KeyboardEvent::ctrlKey() { return false; }

	/// <summary>
	/// Returns true if the specified key is activated
	/// </summary>
	/// <param name="modifierKey">The modifier key.</param>
	/// <returns><c>true</c> if XXXX, <c>false</c> otherwise.</returns>
	/// <exception cref="System.NotImplementedException"></exception>
	bool KeyboardEvent::getModifierState(wchar_t* modifierKey) { return false; }

	/// <summary>
	/// Returns whether the state of the event is composing or not
	/// </summary>
	/// <value><c>true</c> if this instance is composing; otherwise, <c>false</c>.</value>
	bool KeyboardEvent::isComposing() { return false; }

	/// <summary>
	/// Returns the key value of the key represented by the event
	/// </summary>
	/// <value>The key.</value>
	wchar_t* KeyboardEvent::key() { return nullptr; }

	/// <summary>
	/// Returns the Unicode character code of the key that triggered the onkeypress event, or the Unicode key code of the key that triggered the onkeydown or onkeyup event
	/// </summary>
	/// <value>The key code.</value>
	int KeyboardEvent::keyCode() { return 0; }

	/// <summary>
	/// Returns the location of a key on the keyboard or device
	/// </summary>
	/// <value>The location.</value>
	int KeyboardEvent::location() { return 0; }

	/// <summary>
	/// Returns whether the "meta" key was pressed when the key event was triggered
	/// </summary>
	/// <value><c>true</c> if [meta key]; otherwise, <c>false</c>.</value>
	bool KeyboardEvent::metaKey() { return false; }

	/// <summary>
	/// Returns whether a key is being hold down repeatedly, or not
	/// </summary>
	/// <value><c>true</c> if repeat; otherwise, <c>false</c>.</value>
	bool KeyboardEvent::repeat() { return false; }

	/// <summary>
	/// Returns whether the "SHIFT" key was pressed when the key event was triggered
	/// </summary>
	/// <value><c>true</c> if [shift key]; otherwise, <c>false</c>.</value>
	bool KeyboardEvent::shiftKey() { return false; }

	/// <summary>
	/// Returns the Unicode character code of the key that triggered the onkeypress event, or the Unicode key code of the key that triggered the onkeydown or onkeyup event
	/// </summary>
	/// <value>The which.</value>
	int KeyboardEvent::which() { return 0; }
}

/// <summary>
/// PageTransitionEvent
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Returns whether the webpage was cached by the browser
	/// </summary>
	/// <value><c>true</c> if persisted; otherwise, <c>false</c>.</value>
	bool PageTransitionEvent::persisted() { return false; }
}

/// <summary>
/// PlatformKeyboardEvent
/// </summary>
namespace litehtml
{
}

/// <summary>
/// PlatformMouseEvent
/// </summary>
namespace litehtml
{
}

/// <summary>
/// PlatformWheelEvent
/// </summary>
namespace litehtml
{
	bool PlatformWheelEvent::deltaX() { return false; }
	bool PlatformWheelEvent::deltaY() { return false; }
	void PlatformWheelEvent::deltaX(bool value) { }
	void PlatformWheelEvent::deltaY(bool value) { }
}

/// <summary>
/// PopStateEvent
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Returns an object containing a copy of the history entries
	/// </summary>
	/// <value>The state.</value>
	void* PopStateEvent::state() { return nullptr; }
}

/// <summary>
/// ProgressEvent
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Returns whether the length of the progress can be computable or not
	/// </summary>
	/// <value><c>true</c> if [length computable]; otherwise, <c>false</c>.</value>
	bool ProgressEvent::lengthComputable() { return false; }

	/// <summary>
	/// Returns how much work has been loaded
	/// </summary>
	/// <value>The loaded.</value>
	int ProgressEvent::loaded() { return 0; }

	/// <summary>
	/// Returns the total amount of work that will be loaded
	/// </summary>
	/// <value>The total.</value>
	int ProgressEvent::total() { return 0; }
}

/// <summary>
/// StorageEvent
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Returns the key of the changed storage item
	/// </summary>
	/// <value>The key.</value>
	wchar_t* StorageEvent::key() { return nullptr; }

	/// <summary>
	/// Returns the new value of the changed storage item
	/// </summary>
	/// <value>The new value.</value>
	wchar_t* StorageEvent::newValue() { return nullptr; }

	/// <summary>
	/// Returns the old value of the changed storage item
	/// </summary>
	/// <value>The old value.</value>
	wchar_t* StorageEvent::oldValue() { return nullptr; }

	/// <summary>
	/// Returns an object representing the affected storage object
	/// </summary>
	/// <value>The storage area.</value>
	void* StorageEvent::storageArea() { return nullptr; }

	/// <summary>
	/// Returns the URL of the changed item's document
	/// </summary>
	/// <value>The URL.</value>
	wchar_t* StorageEvent::url() { return nullptr; }
}

/// <summary>
/// TouchEvent
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Returns whether the "ALT" key was pressed when the touch event was triggered
	/// </summary>
	/// <value><c>true</c> if [alt key]; otherwise, <c>false</c>.</value>
	bool TouchEvent::altKey() { return false; }

	/// <summary>
	/// Returns a list of all the touch objects whose state changed between the previous touch and this touch
	/// </summary>
	/// <value>The changed touched.</value>
	void** TouchEvent::changedTouched() { return nullptr; }

	/// <summary>
	/// Returns whether the "CTRL" key was pressed when the touch event was triggered
	/// </summary>
	/// <value><c>true</c> if [control key]; otherwise, <c>false</c>.</value>
	bool TouchEvent::ctrlKey() { return false; }

	/// <summary>
	/// Returns whether the "meta" key was pressed when the touch event was triggered
	/// </summary>
	/// <value><c>true</c> if [meta key]; otherwise, <c>false</c>.</value>
	bool TouchEvent::metaKey() { return false; }

	/// <summary>
	/// Returns whether the "SHIFT" key was pressed when the touch event was triggered
	/// </summary>
	/// <value><c>true</c> if [shift key]; otherwise, <c>false</c>.</value>
	bool TouchEvent::shiftKey() { return false; }

	/// <summary>
	/// Returns a list of all the touch objects that are in contact with the surface and where the touchstart event occured on the same target element as the current target element
	/// </summary>
	/// <value>The target touches.</value>
	void** TouchEvent::targetTouches() { return nullptr; }

	/// <summary>
	/// Returns a list of all the touch objects that are currently in contact with the surface
	/// </summary>
	/// <value>The touches.</value>
	void** TouchEvent::touches() { return nullptr; }
}

/// <summary>
/// TransitionEvent
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Returns the name of the transition
	/// </summary>
	/// <value>The name of the property.</value>
	string propertyName() { return ""; }

	/// <summary>
	/// Returns the number of seconds a transition has been running
	/// </summary>
	/// <value>The elapsed time.</value>
	int elapsedTime() { return 0; }

	/// <summary>
	/// Returns the name of the pseudo-element of the transition
	/// </summary>
	/// <value>The pseudo element.</value>
	wchar_t* pseudoElement() { return nullptr; }
}

/// <summary>
/// WheelEvent
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Returns the horizontal scroll amount of a mouse wheel (x-axis)
	/// </summary>
	/// <value>The delta x.</value>
	int WheelEvent::deltaX() { return 0; }

	/// <summary>
	/// Returns the vertical scroll amount of a mouse wheel (y-axis)
	/// </summary>
	/// <value>The delta y.</value>
	int WheelEvent::deltaY() { return 0; }

	/// <summary>
	/// Returns the scroll amount of a mouse wheel for the z-axis
	/// </summary>
	/// <value>The delta z.</value>
	int WheelEvent::deltaZ() { return 0; }

	/// <summary>
	/// Returns a number that represents the unit of measurements for delta values (pixels, lines or pages)
	/// </summary>
	/// <value>The delta mode.</value>
	int WheelEvent::deltaMode() { return 0; }
}
