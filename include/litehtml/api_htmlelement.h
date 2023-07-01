#ifndef LH_API_HTMLELEMENT_H
#define LH_API_HTMLELEMENT_H

// https://microsoft.github.io/PowerBI-JavaScript/interfaces/_node_modules_typedoc_node_modules_typescript_lib_lib_dom_d_.htmlelement.html
// https://html-document.github.io/html-document/docs/source.html
// https://github.com/html-document/html-document/tree/master/src
namespace litehtml
{
	/// <summary>
	/// HTMLElement
	/// https://html-document.github.io/html-document/docs/file/src/HTMLElement.js.html#errorLines=15,78
	/// </summary>
	class HTMLElement : public Element
	{
	public:
		typedef std::shared_ptr<HTMLElement> ptr;

		/// <summary>
		/// The class of the element.
		/// </summary>
		string className();
		void className(string value);
	};

	/// <summary>
	/// HTMLAnchorElement
	/// https://html-document.github.io/html-document/docs/file/src/HTMLElement/elements/HTMLAnchorElement.js.html
	/// </summary>
	class HTMLAnchorElement : public HTMLElement
	{
	public:
		typedef std::shared_ptr<HTMLAnchorElement> ptr;

		/// <summary>
		/// Is a DOMString that reflects the href HTML attribute, containing a valid URL of a linked resource.
		/// </summary>
		string href();
		void href(string value);

		/// <summary>
		/// Is a DOMString representing the fragment identifier, including the leading hash mark ('#'), if any, in the referenced URL.
		/// </summary>
		string hash();
		void hash(string value);

		/// <summary>
		/// Is a DOMString representing the hostname and port (if it's not the default port) in the referenced URL.
		/// </summary>
		string host();
		void host(string value);

		/// <summary>
		/// Is a DOMString representing the hostname and port (if it's not the default port) in the referenced URL.
		/// </summary>
		string hostname();
		void hostname(string value);

		/// <summary>
		/// Is a DOMString that reflects the rel HTML attribute, specifying the relationship of the target object to the linked object.
		/// </summary>
		string rel();
		void rel(string value);

		/// <summary>
		/// Is a DOMString representing the path name component, if any, of the referenced URL.
		/// </summary>
		string pathname();
		void pathname(string value);

		/// <summary>
		/// Is a DOMString representing the protocol component, including trailing colon (':'), of the referenced URL.
		/// </summary>
		string protocol();
		void protocol(string value);
	};

	/// <summary>
	/// HTMLDocumentElement
	/// https://html-document.github.io/html-document/docs/file/src/HTMLElement/elements/HTMLDocumentElement.js.html
	/// </summary>
	class HTMLDocumentElement : public HTMLElement
	{
	public:
		typedef std::shared_ptr<HTMLDocumentElement> ptr;

		/// <summary>
		/// Sets inner HTML and moves elements up if first created child is html.
		/// </summary>
		string innerHTML();
		void innerHTML(string value);
	};

	/// <summary>
	/// HTMLMetaElement
	/// https://html-document.github.io/html-document/docs/file/src/HTMLElement/elements/HTMLMetaElement.js.html
	/// </summary>
	class HTMLMetaElement : public HTMLElement
	{
	public:
		typedef std::shared_ptr<HTMLMetaElement> ptr;

		/// <summary>
		/// Gets or sets the value of meta-data property.
		/// </summary>
		string content();
		void content(string value);

		/// <summary>
		/// Gets or sets the name of an HTTP response header to define for a document.
		/// </summary>
		string httpEquiv();
		void httpEquiv(string value);

		/// <summary>
		/// Gets or sets the name of a meta-data property to define for a document.
		/// </summary>
		string name();
		void name(string value);
	};

	/// <summary>
	/// HTMLOptionElement
	/// https://html-document.github.io/html-document/docs/file/src/HTMLElement/elements/HTMLOptionElement.js.html
	/// </summary>
	class HTMLOptionElement : public HTMLElement
	{
	public:
		typedef std::shared_ptr<HTMLOptionElement> ptr;

		/// <summary>
		/// Contains the initial value of the selected HTML attribute, indicating whether the option is selected by default or not.
		/// </summary>
		string defaultSelected();
		void defaultSelected(string value);

		/// <summary>
		/// Reflects the value of the disabled HTML attribute, which indicates that the option is unavailable to be selected. An option can also be disabled if it is a child of an optgroup element that is disabled.
		/// </summary>
		bool disabled();
		void disabled(bool value);

		/// <summary>
		/// If the option is a descendant of a select element, then this property has the same value as the form property of the corresponding HTMLSelectElement object; otherwise, it is null.
		/// </summary>
		string form();
		void form(string value);

		/// <summary>
		/// The position of the option within the list of options it belongs to, in tree-order. If the option is not part of a list of options, like when it is part of the datalist element, the value is 0.
		/// </summary>
		int index();
		void index(int value);

		/// <summary>
		/// Reflects the value of the label HTML attribute, which provides a label for the option. If this attribute isn't specifically set, reading it returns the element's text content.
		/// </summary>
		string label();
		void label(string value);

		/// <summary>
		/// Indicates whether the option is currently selected.
		/// </summary>
		bool selected();
		void selected(bool value);

		/// <summary>
		/// Contains the text content of the element.
		/// </summary>
		string text();
		void text(string value);

		/// <summary>
		/// Reflects the value of the value HTML attribute, if it exists; otherwise reflects value of the Node.textContent property.
		/// </summary>
		string value();
		void value(string value);
	};

	/// <summary>
	/// HTMLSelectElement
	/// https://html-document.github.io/html-document/docs/file/src/HTMLElement/elements/HTMLSelectElement.js.html
	/// </summary>
	class HTMLSelectElement : public HTMLElement
	{
	public:
		typedef std::shared_ptr<HTMLSelectElement> ptr;

		/// <summary>
		/// Is a Boolean that reflects the autofocus HTML attribute, which indicates whether the control should have input focus when the page loads,
		/// unless the user overrides it, for example by typing in a different control. Only one form - associated element in a document can have this attribute specified
		/// </summary>
		bool autoFocus();
		void autoFocus(bool value);

		/// <summary>
		/// Is a Boolean that reflects the disabled HTML attribute, which indicates whether the control is disabled. If it is disabled, it does not accept clicks.
		/// </summary>
		bool disabled();
		void disabled(bool value);

		/// <summary>
		/// The form that this element is associated with. If this element is a descendant of a form element, then this attribute is the ID of that form element.
		/// If the element is not a descendant of a form element, then: The attribute can be the ID of any form element in the same document.
		/// </summary>
		string form();
		void form(string value);

		/// <summary>
		/// The number of option elements in this select element.
		/// </summary>
		string labels();
		void labels(string value);

		/// <summary>
		/// Reflects the multiple HTML attribute, which indicates whether multiple items can be selected.
		/// </summary>
		string multiple();
		void multiple(string value);

		/// <summary>
		/// Reflects the name HTML attribute, containing the name of this control used by servers and DOM search functions.
		/// </summary>
		string name();
		void name(string value);

		/// <summary>
		/// The set of option elements contained by this element.
		/// </summary>
		std::vector<Element::ptr> options();
		void options(std::vector<Element::ptr> value);

		/// <summary>
		/// Reflects the required HTML attribute, which indicates whether the user is required to select a value before submitting the form
		/// </summary>
		bool required();
		void required(bool value);

		/// <summary>
		/// The index of the first selected option element. The value - 1 is returned if no element is selected.
		/// </summary>
		int selectedIndex();
		void selectedIndex(int value);

		/// <summary>
		/// The set of options that are selected.
		/// </summary>
		std::vector<Element::ptr> selectedOptions();

		/// <summary>
		/// The first selected option.
		/// </summary>
		HTMLOptionElement::ptr selectedOption();

		/// <summary>
		/// Reflects the size HTML attribute, which contains the number of visible items in the control. The default is 1, unless multiple is true, in which case it is 4.
		/// </summary>
		int size();
		void size(int value);

		/// <summary>
		/// The form control's type. When multiple is true, it returns select-multiple; otherwise, it returns select-one. Read only.
		/// </summary>
		string type();
		void type(string value);

		string validationMessage();
		void validationMessage(string value);

		string validity();
		void validity(string value);

		/// <summary>
		/// The value of this form control, that is, of the first selected option.
		/// </summary>
		string value();
		void value(string value);

		string willValidate();
		void willValidate(string value);

		/// <summary>
		/// Gets an item from the options collection for this select element.
		/// </summary>
		HTMLSelectElement::ptr item(int index);

		/// <summary>
		/// Gets the item in the options collection with the specified name. The name string can match either the id or the name attribute of an option node
		/// </summary>
		HTMLSelectElement::ptr namedItem(string name);

		/// <summary>
		/// Removes the element at the specified index from the options collection for this select element.
		/// </summary>
		void remove(int index);
	};

	/// <summary>
	/// HTMLTableCaptionElement
	/// https://html-document.github.io/html-document/docs/file/src/HTMLElement/elements/HTMLTableCaptionElement.js.html
	/// </summary>
	class HTMLTableCaptionElement : public HTMLElement
	{
	public:
		typedef std::shared_ptr<HTMLTableCaptionElement> ptr;
	};

	/// <summary>
	/// HTMLTableElement
	/// https://html-document.github.io/html-document/docs/file/src/HTMLElement/elements/HTMLTableElement.js.html
	/// </summary>
	class HTMLTableElement : public HTMLElement
	{
	public:
		typedef std::shared_ptr<HTMLTableElement> ptr;

		/// <summary>
		/// Is an {@link HTMLTableCaptionElement} representing the first &lt;caption&gt; that is a child of the element, or null if none is found.
		/// When set, if the object doesn't represent a &lt;caption&gt;, a <see cref="DOMException" /> with the HierarchyRequestError name is thrown.
		/// If a correct object is given, it is inserted in the tree as the first child of this element and the first& lt; caption& gt; that is a child of this element is removed from the tree, if any.
		/// </summary>
		string caption();
		void caption(string value);

		/// <summary>
		/// Is an {@link HTMLTableSectionElement} representing the first &lt;thead&gt; that is a child of the element, or null if none is found.
		/// When set, if the object doesn't represent a &lt;thead&gt;, a <see cref="DOMException" /> with the HierarchyRequestError name is thrown.
		/// If a correct object is given, it is inserted in the tree immediately before the first element that is neither a& lt; caption& gt; , nor a& lt; colgroup& gt; , or as the last child if there is no such element, and the first& lt; thead& gt; that is a child of this element is removed from the tree, if any.
		/// </summary>
		string tHead();
		void tHead(string value);

		/// <summary>
		/// Is an <see cref="HTMLTableSectionElement" /> representing the first &lt;tfoot&gt; that is a child of the element, or null if none is found.
		/// When set, if the object doesn't represent a &lt;tfoot&gt;, a <see cref="DOMException" /> with the HierarchyRequestError name is thrown.
		/// If a correct object is given, it is inserted in the tree immediately before the first element that is neither a& lt; caption& gt; , a& lt; colgroup& gt; , nor a& lt; thead& gt; , or as the last child
		/// if there is no such element, and the first& lt; tfoot& gt; that is a child of this element is removed from the tree, if any.
		/// </summary>
		string tFoot();
		void tFoot(string value);

		/// <summary>
		/// Returns a live <see cref="HTMLCollection" /> containing all the rows of the element, that is all& lt; tr& gt; that are a child of the element,
		/// or a child or one of its & lt; thead& gt; , & lt; tbody& gt; and &lt; tfoot& gt; children.
		/// The rows members of a& lt; thead& gt; appear first, in tree order, and those members of a& lt; tbody& gt; last, also in tree order.
		/// The HTMLCollection is live and is automatically updated when the HTMLTableElement changes.
		/// </summary>
		std::vector<Element::ptr> rows();

		/// <summary>
		/// Returns a live <see cref="HTMLCollection" /> containing all the &lt;tbody&gt; of the element. The HTMLCollection is live and is automatically updated when the HTMLTableElement changes.
		/// </summary>
		std::vector<Element::ptr> tBodies();

		/// <summary>
		/// Returns an <see cref="HTMLElement" /> representing the first &lt;thead&gt; that is a child of the element.
		/// If none is found, a new one is created and inserted in the tree immediately before the first element
		/// that is neither a& lt; caption& gt; , nor a& lt; colgroup& gt; , or as the last child if there is no such element.
		/// </summary>
		HTMLElement::ptr createTHead();

		/// <summary>
		/// Removes the first &lt;thead&gt; that is a child of the element.
		/// </summary>
		void deleteTHead();

		/// <summary>
		/// Returns an <see cref="HTMLElement" /> representing the first &lt;tfoot&gt; that is a child of the element.
		/// If none is found, a new one is created and inserted in the tree immediately before the first element
		/// that is neither a& lt; caption& gt; , nor a& lt; colgroup& gt; , or as the last child if there is no such element.
		/// </summary>
		HTMLElement::ptr createTFoot();

		/// <summary>
		/// Removes the first &lt;tfoot&gt; that is a child of the element.
		/// </summary>
		void deleteTFoot();

		/// <summary>
		/// Returns an <see cref="HTMLElement" /> representing the first &lt;caption&gt; that is a child of the element.
		/// If none is found, a new one is created and inserted in the tree as the first child of the &lt;table&gt; element.
		/// </summary>
		HTMLElement::ptr createCaption();

		/// <summary>
		/// Removes the first &lt;caption&gt; that is a child of the element.
		/// </summary>
		void deleteCaption();

		/// <summary>
		/// Returns an <see cref="HTMLElement" /> representing a new row of the table. It inserts it in the rows collection
		/// immediately before the &lt;tr&gt; element at the given index position. If necessary a &lt;tbody&gt; is created.
		/// If the index is - 1, the new row is appended to the collection.If the index is smaller than - 1 or greater than
		/// the number of rows in the collection, a{ @link DOMException } with the value IndexSizeError is raised.
		/// </summary>
		HTMLElement::ptr insertRow(int index = -1);

		//override void appendChild(Element::ptr element);
	};

	/// <summary>
	/// HTMLTableRowElement
	/// https://html-document.github.io/html-document/docs/file/src/HTMLElement/elements/HTMLTableRowElement.js.html#errorLines=3,4
	/// </summary>
	class HTMLTableRowElement : public HTMLElement
	{
	public:
		typedef std::shared_ptr<HTMLTableRowElement> ptr;

		/// <summary>
		/// Returns a live HTMLCollection containing the cells in the row. The HTMLCollection is live and is automatically
		/// updated when rows are added or removed.
		/// </summary>
		HTMLCollection cells();

		/// <summary>
		/// Is a DOMString containing one single character. This character is the one to align all the cell of a column on.
		/// It reflects the char and default to the decimal points associated with the language, e.g. '.' for English, or ','
		/// for French. This property was optional and was not very well supported.
		/// </summary>
		string ch();

		/// <summary>
		/// Is a DOMString containing a integer indicating how many characters must be left at the right (for left-to-right
		/// scripts; or at the left for right-to-left scripts) of the character defined by HTMLTableRowElement.ch. This
		/// property was optional and was not very well supported.
		/// </summary>
		int chOff();

		/// <summary>
		/// Is a DOMString representing an enumerated value indicating how the content of the cell must be vertically
		/// aligned. It reflects the valign attribute and can have one of the following values: "top", "middle", "bottom", or "baseline".
		/// </summary>
		string vAlign();
		void vAlign(string value);

		/// <summary>
		/// Is a DOMString containing an enumerated value reflecting the align attribute. It indicates the alignment of the
		/// element's contents with respect to the surrounding context. The possible values are "left", "right", and "center".
		/// </summary>
		string align();
		void align(string value);

		/// <summary>
		/// Returns a long value which gives the logical position of the row within the table section it belongs to.
		/// If the row is not part of a section, returns -1.
		/// </summary>
		int sectionRowIndex();

		/// <summary>
		/// Returns a long value which gives the logical position of the row within the entire table. If the row is not part
		/// of a table, returns -1.
		/// </summary>
		int rowIndex();

		/// <summary>
		/// Method creates new &lt;td&gt; element and adds it to row.
		/// </summary>
		void insertCell(int index = -1);

		/// <summary>
		/// Removes the cell at the given position in the section. If the given position is greater (or equal as it starts
		/// at zero) than the amount of rows in the section, or is smaller than 0, it raises a DOMException with the
		/// IndexSizeError value.
		/// </summary>
		void deleteCell(int index);
	};

	/// <summary>
	/// HTMLTableSectionElement
	/// https://html-document.github.io/html-document/docs/file/src/HTMLElement/elements/HTMLTableSectionElement.js.html
	/// </summary>
	class HTMLTableSectionElement : public HTMLElement
	{
	public:
		typedef std::shared_ptr<HTMLTableSectionElement> ptr;

		/// <summary>
		/// Gets or sets the align of element content.
		/// </summary>
		string align();
		void align(string value);

		/// <summary>
		/// Returns a live HTMLCollection containing the rows in the section. The HTMLCollection is live and is automatically
		/// updated when rows are added or removed.
		/// </summary>
		HTMLCollection rows();

		/// <summary>
		/// Is a DOMString containing one single chararcter.This character is the one to align all the cell of a column on.
		/// It reflects the char and default to the decimal points associated with the language, e.g. '.' for English, or ','
		/// for French.This property was optional and was not very well supported.
		/// </summary>
		string ch();

		/// <summary>
		/// Is a DOMString containing a integer indicating how many characters must be left at the right (for left-to-right
		/// scripts; or at the left for right-to-left scripts) of the character defined by HTMLTableRowElement.ch. This
		/// property was optional and was not very well supported.
		/// </summary>
		int chOff();

		/// <summary>
		/// Is a DOMString representing an enumerated value indicating how the content of the cell must be vertically
		/// aligned. It reflects the valign attribute and can have one of the following values: "top", "middle", "bottom", or "baseline".
		/// </summary>
		string vAlign();
		void vAlign(string value);

		/// <summary>
		/// Method creates new &lt;tr&gt; element and adds it to section.
		/// </summary>
		HTMLElement::ptr insertRow(int index = -1);

		/// <summary>
		/// Removes the row at the given position in the section. If the given position is greater (or equal as it starts
		/// at zero) than the amount of rows in the section, or is smaller than 0, it raises a DOMException with the IndexSizeError value.
		/// </summary>
		void deleteRow(int index);
	};

	/// <summary>
	/// HTMLIFrameElement
	/// https://github.com/WebKit/WebKit/blob/main/Source/WebCore/html/HTMLIFrameElement.h
	/// </summary>
	class HTMLIFrameElement : public HTMLElement
	{
	public:
		typedef std::shared_ptr<HTMLIFrameElement> ptr;

		/// <summary>
		/// Gets the content window.
		/// </summary>
		Window::ptr contentWindow();

		/// <summary>
		/// Gets the content document.
		/// </summary>
		Document::ptr contentDocument();

		/// <summary>
		/// Gets or sets the src.
		/// </summary>
		string src();
		void src(string value);
	};

	/// <summary>
	/// HTMLImageElement
	/// https://github.com/WebKit/WebKit/blob/main/Source/WebCore/html/HTMLImageElement.h
	/// </summary>
	class HTMLImageElement : public HTMLElement
	{
	public:
		typedef std::shared_ptr<HTMLImageElement> ptr;

		/// <summary>
		/// Gets or sets the source.
		/// </summary>
		string src();
		void src(string value);
	};

	/// <summary>
	/// HTMLInputElement
	/// https://github.com/WebKit/WebKit/blob/main/Source/WebCore/html/HTMLInputElement.h
	/// </summary>
	class HTMLInputElement : public HTMLElement
	{
	public:
		typedef std::shared_ptr<HTMLInputElement> ptr;

		/// <summary>
		/// Gets the type.
		/// </summary>
		string type();

		/// <summary>
		/// Gets or sets the checked.
		/// </summary>
		bool checked();
		void checked(bool value);

		/// <summary>
		/// Gets or sets the value.
		/// </summary>
		string value();
		void value(string value);
	};

	/// <summary>
	/// HTMLFormElement
	/// https://github.com/WebKit/WebKit/blob/main/Source/WebCore/html/HTMLFormElement.h
	/// </summary>
	class HTMLFormElement : public HTMLElement
	{
	public:
		typedef std::shared_ptr<HTMLFormElement> ptr;

		/// <summary>
		/// Gets the type.
		/// </summary>
		HTMLCollection elements();

		/// <summary>
		/// Gets the length.
		/// </summary>
		int length();
	};

	/// <summary>
	/// HTMLScriptElement
	/// https://github.com/WebKit/WebKit/blob/main/Source/WebCore/html/HTMLScriptElement.h
	/// </summary>
	class HTMLScriptElement : public HTMLElement
	{
	public:
		typedef std::shared_ptr<HTMLScriptElement> ptr;

		/// <summary>
		/// Gets or sets the text.
		/// </summary>
		string text();
		void text(string value);
	};
}

#endif  // LH_API_HTMLELEMENT_H
