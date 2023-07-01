#include "html.h"

/// <summary>
/// HTMLAnchorElement
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Is a DOMString that reflects the href HTML attribute, containing a valid URL of a linked resource.
	/// </summary>
	string HTMLAnchorElement::href() { return ""; }
	void HTMLAnchorElement::href(string value) { }

	/// <summary>
	/// Is a DOMString representing the fragment identifier, including the leading hash mark ('#'), if any, in the referenced URL.
	/// </summary>
	string HTMLAnchorElement::hash() { return ""; }
	void HTMLAnchorElement::hash(string value) { }

	/// <summary>
	/// Is a DOMString representing the hostname and port (if it's not the default port) in the referenced URL.
	/// </summary>
	string HTMLAnchorElement::host() { return ""; }
	void HTMLAnchorElement::host(string value) { }

	/// <summary>
	/// Is a DOMString representing the hostname and port (if it's not the default port) in the referenced URL.
	/// </summary>
	string HTMLAnchorElement::hostname() { return ""; }
	void HTMLAnchorElement::hostname(string value) { }

	/// <summary>
	/// Is a DOMString that reflects the rel HTML attribute, specifying the relationship of the target object to the linked object.
	/// </summary>
	string HTMLAnchorElement::rel() { return ""; }
	void HTMLAnchorElement::rel(string value) { }

	/// <summary>
	/// Is a DOMString representing the path name component, if any, of the referenced URL.
	/// </summary>
	string HTMLAnchorElement::pathname() { return ""; }
	void HTMLAnchorElement::pathname(string value) { }

	/// <summary>
	/// Is a DOMString representing the protocol component, including trailing colon (':'), of the referenced URL.
	/// </summary>
	string HTMLAnchorElement::protocol() { return ""; }
	void HTMLAnchorElement::protocol(string value) { }
}

/// <summary>
/// HTMLDocumentElement
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Sets inner HTML and moves elements up if first created child is html.
	/// </summary>
	string HTMLDocumentElement::innerHTML() { return ""; }
	void HTMLDocumentElement::innerHTML(string value) { }
}

/// <summary>
/// HTMLMetaElement
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Gets or sets the value of meta-data property.
	/// </summary>
	string HTMLMetaElement::content() { return ""; }
	void HTMLMetaElement::content(string value) { }

	/// <summary>
	/// Gets or sets the name of an HTTP response header to define for a document.
	/// </summary>
	string HTMLMetaElement::httpEquiv() { return ""; }
	void HTMLMetaElement::httpEquiv(string value) { }

	/// <summary>
	/// Gets or sets the name of a meta-data property to define for a document.
	/// </summary>
	string HTMLMetaElement::name() { return ""; }
	void HTMLMetaElement::name(string value) { }
}

/// <summary>
/// HTMLOptionElement
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Contains the initial value of the selected HTML attribute, indicating whether the option is selected by default or not.
	/// </summary>
	string HTMLOptionElement::defaultSelected() { return ""; }
	void HTMLOptionElement::defaultSelected(string value) { }

	/// <summary>
	/// Reflects the value of the disabled HTML attribute, which indicates that the option is unavailable to be selected. An option can also be disabled if it is a child of an optgroup element that is disabled.
	/// </summary>
	bool HTMLOptionElement::disabled() { return false; }
	void HTMLOptionElement::disabled(bool value) { }

	/// <summary>
	/// If the option is a descendant of a select element, then this property has the same value as the form property of the corresponding HTMLSelectElement object; otherwise, it is null.
	/// </summary>
	string form() { return ""; }
	void form(string value) { }

	/// <summary>
	/// The position of the option within the list of options it belongs to, in tree-order. If the option is not part of a list of options, like when it is part of the datalist element, the value is 0.
	/// </summary>
	int HTMLOptionElement::index() { return 0; }
	void HTMLOptionElement::index(int value) { }

	/// <summary>
	/// Reflects the value of the label HTML attribute, which provides a label for the option. If this attribute isn't specifically set, reading it returns the element's text content.
	/// </summary>
	string HTMLOptionElement::label() { return ""; }
	void HTMLOptionElement::label(string value) { }

	/// <summary>
	/// Indicates whether the option is currently selected.
	/// </summary>
	bool HTMLOptionElement::selected() { return ""; }
	void HTMLOptionElement::selected(bool value) { }

	/// <summary>
	/// Contains the text content of the element.
	/// </summary>
	string HTMLOptionElement::text() { return ""; }
	void HTMLOptionElement::text(string value) { }

	/// <summary>
	/// Reflects the value of the value HTML attribute, if it exists; otherwise reflects value of the Node.textContent property.
	/// </summary>
	string HTMLOptionElement::value() { return ""; }
	void HTMLOptionElement::value(string value) { }
}

/// <summary>
/// HTMLSelectElement
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Is a Boolean that reflects the autofocus HTML attribute, which indicates whether the control should have input focus when the page loads,
	/// unless the user overrides it, for example by typing in a different control. Only one form - associated element in a document can have this attribute specified
	/// </summary>
	bool HTMLSelectElement::autoFocus() { return false; }
	void HTMLSelectElement::autoFocus(bool value) { }

	/// <summary>
	/// Is a Boolean that reflects the disabled HTML attribute, which indicates whether the control is disabled. If it is disabled, it does not accept clicks.
	/// </summary>
	bool HTMLSelectElement::disabled() { return false; }
	void HTMLSelectElement::disabled(bool value) { }

	/// <summary>
	/// The form that this element is associated with. If this element is a descendant of a form element, then this attribute is the ID of that form element.
	/// If the element is not a descendant of a form element, then: The attribute can be the ID of any form element in the same document.
	/// </summary>
	string HTMLSelectElement::form() { return ""; }
	void HTMLSelectElement::form(string value) { }

	/// <summary>
	/// The number of option elements in this select element.
	/// </summary>
	string HTMLSelectElement::labels() { return ""; }
	void HTMLSelectElement::labels(string value) { }

	/// <summary>
	/// Reflects the multiple HTML attribute, which indicates whether multiple items can be selected.
	/// </summary>
	string HTMLSelectElement::multiple() { return ""; }
	void HTMLSelectElement::multiple(string value) { }

	/// <summary>
	/// Reflects the name HTML attribute, containing the name of this control used by servers and DOM search functions.
	/// </summary>
	string HTMLSelectElement::name() { return ""; }
	void HTMLSelectElement::name(string value) { }

	/// <summary>
	/// The set of option elements contained by this element.
	/// </summary>
	std::vector<Element::ptr> HTMLSelectElement::options() { return std::vector<Element::ptr>(); }
	void HTMLSelectElement::options(std::vector<Element::ptr> value) { }

	/// <summary>
	/// Reflects the required HTML attribute, which indicates whether the user is required to select a value before submitting the form
	/// </summary>
	bool HTMLSelectElement::required() { return false; }
	void HTMLSelectElement::required(bool value) { }

	/// <summary>
	/// The index of the first selected option element. The value - 1 is returned if no element is selected.
	/// </summary>
	int HTMLSelectElement::selectedIndex() { return 0; }
	void HTMLSelectElement::selectedIndex(int value) { }

	/// <summary>
	/// The set of options that are selected.
	/// </summary>
	std::vector<Element::ptr> HTMLSelectElement::selectedOptions() { return std::vector<Element::ptr>(); }

	/// <summary>
	/// The first selected option.
	/// </summary>
	HTMLOptionElement::ptr HTMLSelectElement::selectedOption() { return nullptr; }

	/// <summary>
	/// Reflects the size HTML attribute, which contains the number of visible items in the control. The default is 1, unless multiple is true, in which case it is 4.
	/// </summary>
	int HTMLSelectElement::size() { return 0; }
	void HTMLSelectElement::size(int value) { }

	/// <summary>
	/// The form control's type. When multiple is true, it returns select-multiple; otherwise, it returns select-one. Read only.
	/// </summary>
	string HTMLSelectElement::type() { return ""; }
	void HTMLSelectElement::type(string value) { }

	string HTMLSelectElement::validationMessage() { return ""; }
	void HTMLSelectElement::validationMessage(string value) { }

	string HTMLSelectElement::validity() { return ""; }
	void HTMLSelectElement::validity(string value) { }

	/// <summary>
	/// The value of this form control, that is, of the first selected option.
	/// </summary>
	string HTMLSelectElement::value() { return ""; }
	void HTMLSelectElement::value(string value) { }

	string HTMLSelectElement::willValidate() { return ""; }
	void HTMLSelectElement::willValidate(string value) { }

	/// <summary>
	/// Gets an item from the options collection for this select element.
	/// </summary>
	HTMLSelectElement::ptr HTMLSelectElement::item(int index) { return nullptr; }

	/// <summary>
	/// Gets the item in the options collection with the specified name. The name string can match either the id or the name attribute of an option node
	/// </summary>
	HTMLSelectElement::ptr HTMLSelectElement::namedItem(string name) { return nullptr; }

	/// <summary>
	/// Removes the element at the specified index from the options collection for this select element.
	/// </summary>
	void HTMLSelectElement::remove(int index) { }
}

/// <summary>
/// HTMLTableCaptionElement
/// </summary>
namespace litehtml
{
}

/// <summary>
/// HTMLTableElement
/// </summary>
namespace litehtml
{
	/// <summary>
/// Is an {@link HTMLTableCaptionElement} representing the first &lt;caption&gt; that is a child of the element, or null if none is found.
/// When set, if the object doesn't represent a &lt;caption&gt;, a <see cref="DOMException" /> with the HierarchyRequestError name is thrown.
/// If a correct object is given, it is inserted in the tree as the first child of this element and the first& lt; caption& gt; that is a child of this element is removed from the tree, if any.
/// </summary>
	string HTMLTableElement::caption() { return ""; }
	void HTMLTableElement::caption(string value) { }

	/// <summary>
	/// Is an {@link HTMLTableSectionElement} representing the first &lt;thead&gt; that is a child of the element, or null if none is found.
	/// When set, if the object doesn't represent a &lt;thead&gt;, a <see cref="DOMException" /> with the HierarchyRequestError name is thrown.
	/// If a correct object is given, it is inserted in the tree immediately before the first element that is neither a& lt; caption& gt; , nor a& lt; colgroup& gt; , or as the last child if there is no such element, and the first& lt; thead& gt; that is a child of this element is removed from the tree, if any.
	/// </summary>
	string HTMLTableElement::tHead() { return ""; }
	void HTMLTableElement::tHead(string value) { }

	/// <summary>
	/// Is an <see cref="HTMLTableSectionElement" /> representing the first &lt;tfoot&gt; that is a child of the element, or null if none is found.
	/// When set, if the object doesn't represent a &lt;tfoot&gt;, a <see cref="DOMException" /> with the HierarchyRequestError name is thrown.
	/// If a correct object is given, it is inserted in the tree immediately before the first element that is neither a& lt; caption& gt; , a& lt; colgroup& gt; , nor a& lt; thead& gt; , or as the last child
	/// if there is no such element, and the first& lt; tfoot& gt; that is a child of this element is removed from the tree, if any.
	/// </summary>
	string HTMLTableElement::tFoot() { return ""; }
	void HTMLTableElement::tFoot(string value) { }

	/// <summary>
	/// Returns a live <see cref="HTMLCollection" /> containing all the rows of the element, that is all& lt; tr& gt; that are a child of the element,
	/// or a child or one of its & lt; thead& gt; , & lt; tbody& gt; and &lt; tfoot& gt; children.
	/// The rows members of a& lt; thead& gt; appear first, in tree order, and those members of a& lt; tbody& gt; last, also in tree order.
	/// The HTMLCollection is live and is automatically updated when the HTMLTableElement changes.
	/// </summary>
	std::vector<Element::ptr> HTMLTableElement::rows() { return std::vector<Element::ptr>(); }

	/// <summary>
	/// Returns a live <see cref="HTMLCollection" /> containing all the &lt;tbody&gt; of the element. The HTMLCollection is live and is automatically updated when the HTMLTableElement changes.
	/// </summary>
	std::vector<Element::ptr> HTMLTableElement::tBodies() { return std::vector<Element::ptr>(); }

	/// <summary>
	/// Returns an <see cref="HTMLElement" /> representing the first &lt;thead&gt; that is a child of the element.
	/// If none is found, a new one is created and inserted in the tree immediately before the first element
	/// that is neither a& lt; caption& gt; , nor a& lt; colgroup& gt; , or as the last child if there is no such element.
	/// </summary>
	HTMLElement::ptr HTMLTableElement::createTHead() { return nullptr; }

	/// <summary>
	/// Removes the first &lt;thead&gt; that is a child of the element.
	/// </summary>
	void HTMLTableElement::deleteTHead() { }

	/// <summary>
	/// Returns an <see cref="HTMLElement" /> representing the first &lt;tfoot&gt; that is a child of the element.
	/// If none is found, a new one is created and inserted in the tree immediately before the first element
	/// that is neither a& lt; caption& gt; , nor a& lt; colgroup& gt; , or as the last child if there is no such element.
	/// </summary>
	HTMLElement::ptr HTMLTableElement::createTFoot() { return nullptr; }

	/// <summary>
	/// Removes the first &lt;tfoot&gt; that is a child of the element.
	/// </summary>
	void HTMLTableElement::deleteTFoot() { }

	/// <summary>
	/// Returns an <see cref="HTMLElement" /> representing the first &lt;caption&gt; that is a child of the element.
	/// If none is found, a new one is created and inserted in the tree as the first child of the &lt;table&gt; element.
	/// </summary>
	HTMLElement::ptr HTMLTableElement::createCaption() { return nullptr; }

	/// <summary>
	/// Removes the first &lt;caption&gt; that is a child of the element.
	/// </summary>
	void HTMLTableElement::deleteCaption() { }

	/// <summary>
	/// Returns an <see cref="HTMLElement" /> representing a new row of the table. It inserts it in the rows collection
	/// immediately before the &lt;tr&gt; element at the given index position. If necessary a &lt;tbody&gt; is created.
	/// If the index is - 1, the new row is appended to the collection.If the index is smaller than - 1 or greater than
	/// the number of rows in the collection, a{ @link DOMException } with the value IndexSizeError is raised.
	/// </summary>
	HTMLElement::ptr HTMLTableElement::insertRow(int index/* = -1*/) { return nullptr; }
}

/// <summary>
/// HTMLTableRowElement
/// </summary>
namespace litehtml
{
	/// <summary>
/// Returns a live HTMLCollection containing the cells in the row. The HTMLCollection is live and is automatically
/// updated when rows are added or removed.
/// </summary>
	HTMLCollection HTMLTableRowElement::cells() { return HTMLCollection(); }

	/// <summary>
	/// Is a DOMString containing one single character. This character is the one to align all the cell of a column on.
	/// It reflects the char and default to the decimal points associated with the language, e.g. '.' for English, or ','
	/// for French. This property was optional and was not very well supported.
	/// </summary>
	string HTMLTableRowElement::ch() { return ""; }

	/// <summary>
	/// Is a DOMString containing a integer indicating how many characters must be left at the right (for left-to-right
	/// scripts; or at the left for right-to-left scripts) of the character defined by HTMLTableRowElement.ch. This
	/// property was optional and was not very well supported.
	/// </summary>
	int HTMLTableRowElement::chOff() { return 0; }

	/// <summary>
	/// Is a DOMString representing an enumerated value indicating how the content of the cell must be vertically
	/// aligned. It reflects the valign attribute and can have one of the following values: "top", "middle", "bottom", or "baseline".
	/// </summary>
	string HTMLTableRowElement::vAlign() { return ""; }
	void HTMLTableRowElement::vAlign(string value) { }

	/// <summary>
	/// Is a DOMString containing an enumerated value reflecting the align attribute. It indicates the alignment of the
	/// element's contents with respect to the surrounding context. The possible values are "left", "right", and "center".
	/// </summary>
	string HTMLTableRowElement::align() { return ""; }
	void HTMLTableRowElement::align(string value) { }

	/// <summary>
	/// Returns a long value which gives the logical position of the row within the table section it belongs to.
	/// If the row is not part of a section, returns -1.
	/// </summary>
	int HTMLTableRowElement::sectionRowIndex() { return 0; }

	/// <summary>
	/// Returns a long value which gives the logical position of the row within the entire table. If the row is not part
	/// of a table, returns -1.
	/// </summary>
	int HTMLTableRowElement::rowIndex() { return 0; }

	/// <summary>
	/// Method creates new &lt;td&gt; element and adds it to row.
	/// </summary>
	void HTMLTableRowElement::insertCell(int index/* = -1*/) { }

	/// <summary>
	/// Removes the cell at the given position in the section. If the given position is greater (or equal as it starts
	/// at zero) than the amount of rows in the section, or is smaller than 0, it raises a DOMException with the
	/// IndexSizeError value.
	/// </summary>
	void HTMLTableRowElement::deleteCell(int index) { }
}

/// <summary>
/// HTMLTableSectionElement
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Gets or sets the align of element content.
	/// </summary>
	string HTMLTableSectionElement::align() { return ""; }
	void HTMLTableSectionElement::align(string value) { }

	/// <summary>
	/// Returns a live HTMLCollection containing the rows in the section. The HTMLCollection is live and is automatically
	/// updated when rows are added or removed.
	/// </summary>
	HTMLCollection HTMLTableSectionElement::rows() { return HTMLCollection(); }

	/// <summary>
	/// Is a DOMString containing one single chararcter.This character is the one to align all the cell of a column on.
	/// It reflects the char and default to the decimal points associated with the language, e.g. '.' for English, or ','
	/// for French.This property was optional and was not very well supported.
	/// </summary>
	string HTMLTableSectionElement::ch() { return ""; }

	/// <summary>
	/// Is a DOMString containing a integer indicating how many characters must be left at the right (for left-to-right
	/// scripts; or at the left for right-to-left scripts) of the character defined by HTMLTableRowElement.ch. This
	/// property was optional and was not very well supported.
	/// </summary>
	int HTMLTableSectionElement::chOff() { return 0; }

	/// <summary>
	/// Is a DOMString representing an enumerated value indicating how the content of the cell must be vertically
	/// aligned. It reflects the valign attribute and can have one of the following values: "top", "middle", "bottom", or "baseline".
	/// </summary>
	string HTMLTableSectionElement::vAlign() { return ""; }
	void HTMLTableSectionElement::vAlign(string value) { }

	/// <summary>
	/// Method creates new &lt;tr&gt; element and adds it to section.
	/// </summary>
	HTMLElement::ptr HTMLTableSectionElement::insertRow(int index/* = -1*/) { return nullptr; }

	/// <summary>
	/// Removes the row at the given position in the section. If the given position is greater (or equal as it starts
	/// at zero) than the amount of rows in the section, or is smaller than 0, it raises a DOMException with the IndexSizeError value.
	/// </summary>
	void HTMLTableSectionElement::deleteRow(int index) { }
}

/// <summary>
/// HTMLIFrameElement
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Gets the content window.
	/// </summary>
	Window::ptr HTMLIFrameElement::contentWindow() { return nullptr; }

	/// <summary>
	/// Gets the content document.
	/// </summary>
	Document::ptr HTMLIFrameElement::contentDocument() { return nullptr; }

	/// <summary>
	/// Gets or sets the src.
	/// </summary>
	string HTMLIFrameElement::src() { return ""; }
	void HTMLIFrameElement::src(string value) { }
}

/// <summary>
/// HTMLImageElement
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Gets or sets the src.
	/// </summary>
	string HTMLImageElement::src() { return ""; }
	void HTMLImageElement::src(string value) { }
}

/// <summary>
/// HTMLInputElement
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Gets the type.
	/// </summary>
	string HTMLInputElement::type() { return ""; }

	/// <summary>
	/// Gets or sets the checked.
	/// </summary>
	bool HTMLInputElement::checked() { return false; }
	void HTMLInputElement::checked(bool value) { }

	/// <summary>
	/// Gets or sets the value.
	/// </summary>
	string HTMLInputElement::value() { return ""; }
	void HTMLInputElement::value(string value) { }
}

/// <summary>
/// HTMLFormElement
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Gets the length.
	/// </summary>
	HTMLCollection HTMLFormElement::elements() { return HTMLCollection(); }

	/// <summary>
	/// Gets the length.
	/// </summary>
	int HTMLFormElement::length() { return 0; }
}

/// <summary>
/// HTMLScriptElement
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Gets or sets the text.
	/// </summary>
	string HTMLScriptElement::text() { return ""; }
	void HTMLScriptElement::text(string value) { }
}