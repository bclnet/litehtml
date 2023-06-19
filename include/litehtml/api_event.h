#ifndef LH_EVENTS_H
#define LH_EVENTS_H

#include <string>

namespace litehtml
{
	// prototypes
	class Window;
	class Element;

	/// <summary>
	/// EventListenerOptions
	/// </summary>
	class EventListenerOptions
	{
	public:
		bool capture;
		bool passive;
		bool once;
	};

	/// <summary>
	/// EventTarget
	/// </summary>
	class EventTarget
	{
	protected:
		EventTarget();
	public:
		typedef std::unique_ptr<EventTarget> ptr;

		/// <summary>
		/// Attaches an event handler to the document
		/// </summary>
		/// <param name="evnt">The event.</param>
		/// <param name="function">The function.</param>
		/// <param name="useCapture">if set to <c>true</c> [use capture].</param>
		void addEventListener(string evnt, tfunc function, bool useCapture = false);
		
		void dispatchEvent(EventTarget::ptr evnt);

		/// <summary>
		/// Removes an event handler from the document (that has been attached with the addEventListener() method)
		/// </summary>
		/// <param name="evnt">The event.</param>
		/// <param name="function">The function.</param>
		/// <param name="useCapture">if set to <c>true</c> [use capture].</param>
		void removeEventListener(string evnt, tfunc function, bool useCapture = false);
	};

	/// <summary>
	/// Event
	/// https://www.w3schools.com/jsref/obj_event.asp
	/// </summary>
	class Event
	{
	public:
		typedef std::unique_ptr<Event> ptr;

		/// <summary>
		/// Returns whether or not a specific event is a bubbling event
		/// </summary>
		/// <value>
		///   <c>true</c> if bubbles; otherwise, <c>false</c>.
		/// </value>
		bool bubbles();

		/// <summary>
		/// Sets or returns whether the event should propagate up the hierarchy or not
		/// </summary>
		/// <value>
		///   <c>true</c> if [cancel bubble]; otherwise, <c>false</c>.
		/// </value>
		bool cancelBubble();

		/// <summary>
		/// Returns whether or not an event can have its default action prevented
		/// </summary>
		/// <value>
		///   <c>true</c> if cancelable; otherwise, <c>false</c>.
		/// </value>
		bool cancelable();

		/// <summary>
		/// Returns whether the event is composed or not
		/// </summary>
		/// <value>
		///   <c>true</c> if composed; otherwise, <c>false</c>.
		/// </value>
		bool composed();

		//public Event createEvent(string type) => throw new NotImplementedException();

		/// <summary>
		/// Returns the event's path
		/// </summary>
		/// <returns></returns>
		/// <exception cref="NotImplementedException"></exception>
		Element* composedPath();

		/// <summary>
		/// Returns the element whose event listeners triggered the event
		/// </summary>
		/// <value>
		/// Returns the element whose event listeners triggered the event
		/// </value>
		Element* currentTarget();

		/// <summary>
		/// Returns whether or not the preventDefault() method was called for the event
		/// </summary>
		/// <value>
		///   <c>true</c> if [default prevented]; otherwise, <c>false</c>.
		/// </value>
		bool defaultPrevented();

		/// <summary>
		/// Returns which phase of the event flow is currently being evaluated
		/// </summary>
		/// <value>
		/// The event phase.
		/// </value>
		int eventPhase();

		/// <summary>
		/// Returns whether or not an event is trusted
		/// </summary>
		/// <value>
		///   <c>true</c> if this instance is trusted; otherwise, <c>false</c>.
		/// </value>
		bool isTrusted();

		/// <summary>
		/// Cancels the event if it is cancelable, meaning that the default action that belongs to the event will not occur
		/// </summary>
		/// <exception cref="NotImplementedException"></exception>
		void preventDefault();

		/// <summary>
		/// Prevents other listeners of the same event from being called
		/// </summary>
		/// <exception cref="NotImplementedException"></exception>
		void stopImmediatePropagation();

		/// <summary>
		/// Returns the element that triggered the event
		/// </summary>
		/// <value>
		/// The target.
		/// </value>
		Element* target();

		/// <summary>
		/// Returns the time (in milliseconds relative to the epoch) at which the event was created
		/// </summary>
		/// <value>
		/// The time stamp.
		/// </value>
		int64_t timeStamp();

		/// <summary>
		/// Returns the name of the event
		/// </summary>
		/// <value>
		/// The type.
		/// </value>
		wchar_t* type();
	};

	/// <summary>
	/// UiEvent
	/// events: abort, beforeunload, error, load, resize, scroll, select, unload
	/// </summary>
	class UiEvent : public Event
	{
	public:
		/// <summary>
		/// Returns a number with details about the event
		/// </summary>
		/// <value>The detail.</value>
		int detail();

		/// <summary>
		/// Returns a reference to the Window object where the event occurred
		/// </summary>
		/// <value>The view.</value>
		Window* view();
	};

	/// <summary>
	/// MouseEvent
	/// events: onclick, oncontextmenu, ondblclick, onmousedown, onmouseenter, on mouseleave, onmousemove, onmouseout, onmouseover, onmouseup
	/// </summary>
	class MouseEvent : public UiEvent
	{
	public:
		/// <summary>
		/// Returns whether the "ALT" key was pressed when the mouse event was triggered
		/// </summary>
		/// <value><c>true</c> if [alt key]; otherwise, <c>false</c>.</value>
		bool altKey();

		/// <summary>
		/// Returns which mouse button was pressed when the mouse event was triggered
		/// </summary>
		/// <value>The button.</value>
		int button();

		/// <summary>
		/// Returns which mouse buttons were pressed when the mouse event was triggered
		/// </summary>
		/// <value>The buttons.</value>
		int buttons();

		/// <summary>
		/// Returns the horizontal coordinate of the mouse pointer, relative to the current window, when the mouse event was triggered
		/// </summary>
		/// <value>The client x.</value>
		int clientX();

		/// <summary>
		/// Returns the vertical coordinate of the mouse pointer, relative to the current window, when the mouse event was triggered
		/// </summary>
		/// <value>The client y.</value>
		int clientY();

		/// <summary>
		/// Returns whether the "CTRL" key was pressed when the mouse event was triggered
		/// </summary>
		/// <value>The control key.</value>
		int ctrlKey();

		/// <summary>
		/// Returns true if the specified key is activated
		/// </summary>
		/// <param name="modifierKey">The modifier key.</param>
		/// <returns><c>true</c> if XXXX, <c>false</c> otherwise.</returns>
		/// <exception cref="System.NotImplementedException"></exception>
		bool getModifierState(wchar_t* modifierKey);

		/// <summary>
		/// Returns whether the "META" key was pressed when an event was triggered
		/// </summary>
		/// <value><c>true</c> if [meta key]; otherwise, <c>false</c>.</value>
		bool metaKey();

		/// <summary>
		/// Returns the horizontal coordinate of the mouse pointer relative to the position of the last mousemove event
		/// </summary>
		/// <value>The movement x.</value>
		int movementX();

		/// <summary>
		/// Returns the vertical coordinate of the mouse pointer relative to the position of the last mousemove event
		/// </summary>
		/// <value>The movement y.</value>
		int movementY();

		/// <summary>
		/// Returns the horizontal coordinate of the mouse pointer relative to the position of the edge of the target element
		/// </summary>
		/// <value>The offset x.</value>
		int offsetX();

		/// <summary>
		/// Returns the vertical coordinate of the mouse pointer relative to the position of the edge of the target element
		/// </summary>
		/// <value>The offset y.</value>
		int offsetY();

		/// <summary>
		/// Returns the horizontal coordinate of the mouse pointer, relative to the document, when the mouse event was triggered
		/// </summary>
		/// <value>The page x.</value>
		int pageX();

		/// <summary>
		/// Returns the vertical coordinate of the mouse pointer, relative to the document, when the mouse event was triggered
		/// </summary>
		/// <value>The page y.</value>
		int pageY();

		/// <summary>
		/// Gets the region.
		/// </summary>
		/// <value>The region.</value>
		wchar_t* region();

		/// <summary>
		/// Returns the element related to the element that triggered the mouse event
		/// </summary>
		/// <value>The related target.</value>
		Element* relatedTarget();

		/// <summary>
		/// Returns the horizontal coordinate of the mouse pointer, relative to the screen, when an event was triggered
		/// </summary>
		/// <value>The screen x.</value>
		int screenX();

		/// <summary>
		/// Returns the vertical coordinate of the mouse pointer, relative to the screen, when an event was triggered
		/// </summary>
		/// <value>The screen y.</value>
		int screenY();

		/// <summary>
		/// Returns whether the "SHIFT" key was pressed when an event was triggered
		/// </summary>
		/// <value><c>true</c> if [shift key]; otherwise, <c>false</c>.</value>
		bool shiftKey();

		/// <summary>
		/// Returns which mouse button was pressed when the mouse event was triggered
		/// </summary>
		/// <value>The which.</value>
		int which();
	};

	/// <summary>
	/// AnimationEvent
	/// events: animationend, animationiteration, animationstart
	/// </summary>
	class AnimationEvent : public Event
	{
	public:
		/// <summary>
		/// Returns the name of the animation
		/// </summary>
		/// <value>The name of the animation.</value>
		wchar_t* animationName();

		/// <summary>
		/// Returns the number of seconds an animation has been running
		/// </summary>
		/// <value>The elapsed time.</value>
		int elapsedTime();

		/// <summary>
		/// Returns the name of the pseudo-element of the animation
		/// </summary>
		/// <value>The pseudo element.</value>
		wchar_t* pseudoElement();
	};

	/// <summary>
	/// ClipboardEvent
	/// events: oncopy, oncut, onpaste
	/// </summary>
	class ClipboardEvent : public Event
	{
	public:
		/// <summary>
		/// Returns an object containing the data affected by the clipboard operation
		/// </summary>
		/// <value>The clipboard data.</value>
		void* clipboardData();
	};

	/// <summary>
	/// DragEvent
	/// events: ondrag, ondragend, ondragenter, ondragleave, ondragover, ondragstart, ondrop
	/// </summary>
	class DragEvent : public MouseEvent
	{
	public:
		/// <summary>
		/// Returns the data that is dragged/dropped
		/// </summary>
		/// <value>The data transfer.</value>
		void* dataTransfer();
	};

	/// <summary>
	/// FocusEvent
	/// events: onblur, onfocus, onfocusin, onfocusout
	/// </summary>
	class FocusEvent : public UiEvent
	{
	public:
		/// <summary>
		/// Returns the element related to the element that triggered the event
		/// </summary>
		/// <value>The related target.</value>
		void* relatedTarget();
	};

	/// <summary>
	/// HashChangeEvent
	/// events: onhashchange
	/// </summary>
	class HashChangeEvent : public Event
	{
	public:
		/// <summary>
		/// Returns the URL of the document, after the hash has been changed
		/// </summary>
		/// <value>The new URL.</value>
		wchar_t* newURL();

		/// <summary>
		/// Returns the URL of the document, before the hash was changed
		/// </summary>
		/// <value>The old URL.</value>
		wchar_t* oldURL();
	};

	/// <summary>
	/// InputEvent
	/// </summary>
	class InputEvent : public Event
	{
	public:
		/// <summary>
		/// Returns the inserted characters
		/// </summary>
		/// <value>The data.</value>
		void* data();

		/// <summary>
		/// Returns an object containing information about the inserted/deleted data
		/// </summary>
		/// <value>The data transfer.</value>
		void* dataTransfer();

		/// <summary>
		/// Returns an array containing target ranges that will be affected by the insertion/deletion
		/// </summary>
		/// <returns>System.String[].</returns>
		/// <exception cref="NotImplementedException"></exception>
		wchar_t** getTargetRanges();

		/// <summary>
		/// Returns the type of the change (i.e "inserting" or "deleting")
		/// </summary>
		/// <value>The type of the input.</value>
		wchar_t* inputType();

		/// <summary>
		/// Returns whether the state of the event is composing or not
		/// </summary>
		/// <value>The is composing.</value>
		wchar_t* isComposing();
	};

	/// <summary>
	/// KeyboardEvent
	/// events: onkeydown, onkeypress, onkeyup
	/// </summary>
	class KeyboardEvent : public UiEvent
	{
	public:
		/// <summary>
		/// Returns whether the "ALT" key was pressed when the key event was triggered
		/// </summary>
		/// <value><c>true</c> if [alt key]; otherwise, <c>false</c>.</value>
		bool altKey();

		/// <summary>
		/// Returns the Unicode character code of the key that triggered the event
		/// </summary>
		/// <value>The character code.</value>
		int charCode();

		/// <summary>
		/// Returns the code of the key that triggered the event
		/// </summary>
		/// <value>The code.</value>
		wchar_t* code();

		/// <summary>
		/// Returns whether the "CTRL" key was pressed when the key event was triggered
		/// </summary>
		/// <value><c>true</c> if [control key]; otherwise, <c>false</c>.</value>
		bool ctrlKey();

		/// <summary>
		/// Returns true if the specified key is activated
		/// </summary>
		/// <param name="modifierKey">The modifier key.</param>
		/// <returns><c>true</c> if XXXX, <c>false</c> otherwise.</returns>
		/// <exception cref="System.NotImplementedException"></exception>
		bool getModifierState(wchar_t* modifierKey);

		/// <summary>
		/// Returns whether the state of the event is composing or not
		/// </summary>
		/// <value><c>true</c> if this instance is composing; otherwise, <c>false</c>.</value>
		bool isComposing();

		/// <summary>
		/// Returns the key value of the key represented by the event
		/// </summary>
		/// <value>The key.</value>
		wchar_t* key();

		/// <summary>
		/// Returns the Unicode character code of the key that triggered the onkeypress event, or the Unicode key code of the key that triggered the onkeydown or onkeyup event
		/// </summary>
		/// <value>The key code.</value>
		int keyCode();

		/// <summary>
		/// Returns the location of a key on the keyboard or device
		/// </summary>
		/// <value>The location.</value>
		int location();

		/// <summary>
		/// Returns whether the "meta" key was pressed when the key event was triggered
		/// </summary>
		/// <value><c>true</c> if [meta key]; otherwise, <c>false</c>.</value>
		bool metaKey();

		/// <summary>
		/// Returns whether a key is being hold down repeatedly, or not
		/// </summary>
		/// <value><c>true</c> if repeat; otherwise, <c>false</c>.</value>
		bool repeat();

		/// <summary>
		/// Returns whether the "SHIFT" key was pressed when the key event was triggered
		/// </summary>
		/// <value><c>true</c> if [shift key]; otherwise, <c>false</c>.</value>
		bool shiftKey();

		/// <summary>
		/// Returns the Unicode character code of the key that triggered the onkeypress event, or the Unicode key code of the key that triggered the onkeydown or onkeyup event
		/// </summary>
		/// <value>The which.</value>
		int which();
	};

	/// <summary>
	/// PageTransitionEvent
	/// events: pagehide, pageshow
	/// </summary>
	class PageTransitionEvent : public Event
	{
	public:
		/// <summary>
		/// Returns whether the webpage was cached by the browser
		/// </summary>
		/// <value><c>true</c> if persisted; otherwise, <c>false</c>.</value>
		bool persisted();
	};

	/// <summary>
	/// PlatformKeyboardEvent
	/// </summary>
	class PlatformKeyboardEvent
	{
	};

	/// <summary>
	/// PlatformMouseEvent
	/// </summary>
	class PlatformMouseEvent
	{
	};

	/// <summary>
	/// PlatformWheelEvent
	/// </summary>
	class PlatformWheelEvent
	{
	public:
		bool deltaX();
		bool deltaY();
	private:
		void deltaX(bool value);
		void deltaY(bool value);
	};

	/// <summary>
	/// PopStateEvent
	/// events: popstate
	/// </summary>
	class PopStateEvent : public Event
	{
	public:
		/// <summary>
		/// Returns an object containing a copy of the history entries
		/// </summary>
		/// <value>The state.</value>
		void* state();
	};

	/// <summary>
	/// ProgressEvent
	/// events: onerror, onloadstart
	/// </summary>
	class ProgressEvent : public Event
	{
	public:
		/// <summary>
		/// Returns whether the length of the progress can be computable or not
		/// </summary>
		/// <value><c>true</c> if [length computable]; otherwise, <c>false</c>.</value>
		bool lengthComputable();

		/// <summary>
		/// Returns how much work has been loaded
		/// </summary>
		/// <value>The loaded.</value>
		int loaded();

		/// <summary>
		/// Returns the total amount of work that will be loaded
		/// </summary>
		/// <value>The total.</value>
		int total();
	};

	/// <summary>
	/// StorageEvent
	/// events: storage
	/// </summary>
	class StorageEvent : public Event
	{
	public:
		/// <summary>
		/// Returns the key of the changed storage item
		/// </summary>
		/// <value>The key.</value>
		wchar_t* key();

		/// <summary>
		/// Returns the new value of the changed storage item
		/// </summary>
		/// <value>The new value.</value>
		wchar_t* newValue();

		/// <summary>
		/// Returns the old value of the changed storage item
		/// </summary>
		/// <value>The old value.</value>
		wchar_t* oldValue();

		/// <summary>
		/// Returns an object representing the affected storage object
		/// </summary>
		/// <value>The storage area.</value>
		void* storageArea();

		/// <summary>
		/// Returns the URL of the changed item's document
		/// </summary>
		/// <value>The URL.</value>
		wchar_t* url();
	};

	/// <summary>
	/// TouchEvent
	/// events: ontouchcancel, ontouchend, ontouchmove, ontouchstart
	/// </summary>
	class TouchEvent : public UiEvent
	{
	public:
		/// <summary>
				/// Returns whether the "ALT" key was pressed when the touch event was triggered
				/// </summary>
				/// <value><c>true</c> if [alt key]; otherwise, <c>false</c>.</value>
		bool altKey();

		/// <summary>
		/// Returns a list of all the touch objects whose state changed between the previous touch and this touch
		/// </summary>
		/// <value>The changed touched.</value>
		void** changedTouched();

		/// <summary>
		/// Returns whether the "CTRL" key was pressed when the touch event was triggered
		/// </summary>
		/// <value><c>true</c> if [control key]; otherwise, <c>false</c>.</value>
		bool ctrlKey();

		/// <summary>
		/// Returns whether the "meta" key was pressed when the touch event was triggered
		/// </summary>
		/// <value><c>true</c> if [meta key]; otherwise, <c>false</c>.</value>
		bool metaKey();

		/// <summary>
		/// Returns whether the "SHIFT" key was pressed when the touch event was triggered
		/// </summary>
		/// <value><c>true</c> if [shift key]; otherwise, <c>false</c>.</value>
		bool shiftKey();

		/// <summary>
		/// Returns a list of all the touch objects that are in contact with the surface and where the touchstart event occured on the same target element as the current target element
		/// </summary>
		/// <value>The target touches.</value>
		void** targetTouches();

		/// <summary>
		/// Returns a list of all the touch objects that are currently in contact with the surface
		/// </summary>
		/// <value>The touches.</value>
		void** touches();
	};

	/// <summary>
	/// TransitionEvent
	/// events: transitionend
	/// </summary>
	class TransitionEvent : public Event
	{
	public:
		/// <summary>
		/// Returns the name of the transition
		/// </summary>
		/// <value>The name of the property.</value>
		wchar_t* propertyName();

		/// <summary>
		/// Returns the number of seconds a transition has been running
		/// </summary>
		/// <value>The elapsed time.</value>
		int elapsedTime();

		/// <summary>
		/// Returns the name of the pseudo-element of the transition
		/// </summary>
		/// <value>The pseudo element.</value>
		wchar_t* pseudoElement();
	};

	/// <summary>
	/// WheelEvent
	/// events: onwheel
	/// </summary>
	class WheelEvent : public Event
	{
	public:
		/// <summary>
		/// Returns the horizontal scroll amount of a mouse wheel (x-axis)
		/// </summary>
		/// <value>The delta x.</value>
		int deltaX();

		/// <summary>
		/// Returns the vertical scroll amount of a mouse wheel (y-axis)
		/// </summary>
		/// <value>The delta y.</value>
		int deltaY();

		/// <summary>
		/// Returns the scroll amount of a mouse wheel for the z-axis
		/// </summary>
		/// <value>The delta z.</value>
		int deltaZ();

		/// <summary>
		/// Returns a number that represents the unit of measurements for delta values (pixels, lines or pages)
		/// </summary>
		/// <value>The delta mode.</value>
		int deltaMode();
	};
}

#endif  // LH_EVENTS_H
