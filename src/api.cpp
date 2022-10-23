#include "html.h"
#include "document.h"

/// <summary>
/// Console
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Writes an error message to the console if the assertion is false
	/// </summary>
	/// <param name="assertion">The assertion.</param>
	/// <param name="message">The message.</param>
	void Console::assert_(bool assertion, tany message) { }

	/// <summary>
	/// Clears the console
	/// </summary>
	void Console::clear() { }

	/// <summary>
	/// Logs the number of times that this particular call to count() has been called
	/// </summary>
	/// <param name="label">The label.</param>
	void Console::count(tstring label /*= _tdefault*/) { }

	/// <summary>
	/// Outputs an error message to the console
	/// </summary>
	/// <param name="message">The message.</param>
	void Console::error(tany message) { }

	/// <summary>
	/// Creates a new inline group in the console. This indents following console messages by an additional level, until console.groupEnd() is called
	/// </summary>
	/// <param name="label">The label.</param>
	void Console::group(tstring label /*= _tdefault*/) { }

	/// <summary>
	/// Creates a new inline group in the console. However, the new group is created collapsed. The user will need to use the disclosure button to expand it
	/// </summary>
	/// <param name="label">The label.</param>
	void Console::groupCollapsed(tstring label /*= _tdefault*/) { }

	/// <summary>
	/// Exits the current inline group in the console
	/// </summary>
	void Console::groupEnd() { }

	/// <summary>
	/// Outputs an informational message to the console
	/// </summary>
	/// <param name="message">The message.</param>
	void Console::info(tany message) { }

	/// <summary>
	/// Outputs a message to the console
	/// </summary>
	/// <param name="message">The message.</param>
	void Console::log(tany message) { }

	/// <summary>
	/// Displays tabular data as a table
	/// </summary>
	/// <param name="tabledata">The tabledata.</param>
	/// <param name="tablecolumns">The tablecolumns.</param>
	void Console::table(void* tabledata, tstring tablecolumns[] /*= nullptr*/) { }

	/// <summary>
	/// Starts a timer (can track how long an operation takes)
	/// </summary>
	/// <param name="label">The label.</param>
	void Console::time(tstring label /*= _tdefault*/) { }

	/// <summary>
	/// Stops a timer that was previously started by console.time()
	/// </summary>
	/// <param name="label">The label.</param>
	void Console::timeEnd(tstring label /*= _tdefault*/) { }

	/// <summary>
	/// Outputs a stack trace to the console
	/// </summary>
	/// <param name="label">The label.</param>
	void Console::trace(tstring label /*= _tdefault*/) { }

	/// <summary>
	/// Outputs a warning message to the console
	/// </summary>
	/// <param name="message">The message.</param>
	void Console::warn(tany message) { }
};

/// <summary>
/// Document
/// </summary>
namespace litehtml
{
	Document::Document() { _doc = static_cast<document*>(this); }

	/// <summary>
	/// Returns the currently focused element in the document
	/// </summary>
	/// <value>
	/// The active element.
	/// </value>
	Element* Document::activeElement() { return nullptr; }

	/// <summary>
	/// Attaches an event handler to the document
	/// </summary>
	/// <param name="event">The event.</param>
	/// <param name="function">The function.</param>
	/// <param name="useCapture">if set to <c>true</c> [use capture].</param>
	void Document::addEventListener(tstring event, tstring function, bool useCapture) { }

	/// <summary>
	/// Adopts a node from another document
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns></returns>
	Node* Document::adoptNode(Node* node) { return nullptr; }

	/// <summary>
	/// Returns a collection of all <a> elements in the document that have a name attribute
	/// </summary>
	/// <value>
	/// The anchors.
	/// </value>
	HTMLCollection& Document::anchors() { return HTMLCollection(); }

	/// <summary>
	/// Adds a new child node, to an element, as the last child node
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns></returns>
	Node* Document::appendChild(Node* node) //: Node
	{
		return nullptr;
	}

	/// <summary>
	/// Returns a collection of all <applet> elements in the document
	/// </summary>
	/// <value>
	/// The applets.
	/// </value>
	HTMLCollection& Document::applets() { return HTMLCollection(); }

	/// <summary>
	/// NotSupported - Returns a NamedNodeMap of an element's attributes
	/// </summary>
	/// <value>
	/// The attributes.
	/// </value>
	NamedNodeMap Document::attributes() { throw; } //: Node

	/// <summary>
	/// Returns the absolute base URI of a document
	/// </summary>
	/// <value>
	/// The base URI.
	/// </value>
	tstring Document::baseURI() { return nullptr; } //: Node

	/// <summary>
	/// Sets or returns the document's body (the <body> element)
	/// </summary>
	/// <value>
	/// The body.
	/// </value>
	Element* Document::body() { return nullptr; }
	void Document::body(Element* value) { }

	/// <summary>
	/// Returns the character encoding for the document
	/// </summary>
	/// <value>
	/// The character set.
	/// </value>
	tstring Document::characterSet() { return _t("UTF-8"); }

	/// <summary>
	/// Returns a collection of an element's child nodes (including text and comment nodes)
	/// </summary>
	NodeList<Node> Document::childNodes() { return NodeList<Node>(_doc->m_root->m_children); } //: Node

	/// <summary>
	/// Clones an element
	/// </summary>
	/// <param name="deep">if set to <c>true</c> [deep].</param>
	/// <returns></returns>
	Node* Document::cloneNode(bool deep /*= false*/) { return nullptr; } //: Node

	/// <summary>
	/// Closes the output stream previously opened with document.open()
	/// </summary>
	void Document::close() { }

	/// <summary>
	/// Compares the document position of two elements
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns></returns>
	int Document::compareDocumentPosition(Node* node) { return 0; } //: Node

	/// <summary>
	/// Returns all name/value pairs of cookies in the document
	/// </summary>
	/// <value>
	/// The cookie.
	/// </value>
	tstring Document::cookie() { return nullptr; }
	void Document::cookie(tstring value) { }

	/// <summary>
	/// Creates an attribute node
	/// </summary>
	/// <param name="attributename">The attributename.</param>
	/// <returns></returns>
	Attr::ptr Document::createAttribute(tstring attributename) { return std::make_shared<Attr>(nullptr, attributename.c_str()); }

	/// <summary>
	/// Creates a Comment node with the specified text
	/// </summary>
	/// <param name="text">The text.</param>
	/// <returns></returns>
	Node* Document::createComment(tstring text) { return nullptr; } //: IComment

	/// <summary>
	/// Creates an empty DocumentFragment node
	/// </summary>
	/// <returns></returns>
	DocumentFragment* Document::createDocumentFragment() { return nullptr; }

	/// <summary>
	/// Creates an Element node
	/// </summary>
	/// <param name="nodename">The nodename.</param>
	/// <returns></returns>
	Element* Document::createElement(tstring nodename) { return nullptr; }

	/// <summary>
	/// Creates a new event
	/// </summary>
	/// <param name="type">The type.</param>
	/// <returns></returns>
	Event* Document::createEvent(tstring type) { return nullptr; }

	/// <summary>
	/// Creates a Text node
	/// </summary>
	/// <param name="text">The text.</param>
	/// <returns></returns>
	Node* Document::createTextNode(tstring text) { return nullptr; } //: IText

	/// <summary>
	/// Returns the window object associated with a document, or nullptr if none is available.
	/// </summary>
	/// <value>
	/// The default view.
	/// </value>
	Window* Document::defaultView() { return nullptr; }

	/// <summary>
	/// Controls whether the entire document should be editable or not.
	/// </summary>
	/// <value>
	/// The design mode.
	/// </value>
	tstring Document::designMode() { return _t("off"); }
	void Document::designMode(tstring value) { throw; }

	/// <summary>
	/// Returns the Document Type Declaration associated with the document
	/// </summary>
	/// <value>
	/// The doctype.
	/// </value>
	DocumentType* Document::doctype() { return nullptr; }

	/// <summary>
	/// Returns the Document Element of the document (the <html> element)
	/// </summary>
	/// <value>
	/// The document element.
	/// </value>
	Element* Document::documentElement() { return nullptr; }

	/// <summary>
	/// Sets or returns the location of the document
	/// </summary>
	/// <value>
	/// The document URI.
	/// </value>
	tstring Document::documentURI() { return nullptr; }
	void Document::documentURI(tstring value) { }

	/// <summary>
	/// Returns the domain name of the server that loaded the document
	/// </summary>
	/// <value>
	/// The domain.
	/// </value>
	tstring Document::domain() { return nullptr; }

	/// <summary>
	/// Returns a collection of all <embed> elements the document
	/// </summary>
	/// <value>
	/// The embeds.
	/// </value>
	HTMLCollection& Document::embeds() { return HTMLCollection(); }

	/// <summary>
	/// Invokes the specified clipboard operation on the element currently having focus.
	/// </summary>
	/// <param name="command">The command.</param>
	/// <param name="showUI">if set to <c>true</c> [show UI].</param>
	/// <param name="value">The value.</param>
	/// <returns></returns>
	bool Document::execCommand(tstring command, bool showUI, void* value) { return false; }

	/// <summary>
	/// Returns the first child node of an element
	/// </summary>
	/// <value>
	/// The first child.
	/// </value>
	Node* Document::firstChild() { return _doc->m_root->m_children[0].get(); } //: Node

	/// <summary>
	/// Returns a collection of all <form> elements in the document
	/// </summary>
	/// <value>
	/// The forms.
	/// </value>
	HTMLCollection& Document::forms() { return HTMLCollection(); }

	/// <summary>
	/// Returns the current element that is displayed in fullscreen mode
	/// </summary>
	/// <value>
	/// The fullscreen element.
	/// </value>
	Element* Document::fullscreenElement() { return nullptr; }

	/// <summary>
	/// Returns a Boolean value indicating whether the document can be viewed in fullscreen mode
	/// </summary>
	/// <returns></returns>
	bool Document::fullscreenEnabled() { return false; }

	/// <summary>
	/// Returns the element that has the ID attribute with the specified value
	/// </summary>
	/// <param name="elementID">The element identifier.</param>
	/// <returns></returns>
	Element* Document::getElementById(tstring elementID)
	{
		css_element_selector elem;
		css_attribute_selector attr;
		attr.val = elementID;
		attr.condition = select_equal;
		attr.attribute = _t("id");
		elem.m_attrs.push_back(attr);
		css_selector sel(elem);
		return _doc->m_root->select_one(sel).get();
	}

	/// <summary>
	/// Returns a NodeList containing all elements with the specified class name
	/// </summary>
	/// <param name="classname">The classname.</param>
	/// <returns></returns>
	NodeList<Element> Document::getElementsByClassName(tstring classname) { return _doc->m_root->getElementsByClassName(classname); }

	/// <summary>
	/// Returns a NodeList containing all elements with a specified name
	/// </summary>
	/// <param name="name">The name.</param>
	/// <returns></returns>
	NodeList<Element> Document::getElementsByName(tstring name)
	{
		css_element_selector elem;
		css_attribute_selector attr;
		attr.val = name;
		attr.condition = select_equal;
		attr.attribute = _t("name");
		elem.m_attrs.push_back(attr);
		css_selector sel(elem);
		return NodeList<Element>(_doc->m_root->select_all(sel));
	}

	/// <summary>
	/// Returns a NodeList containing all elements with the specified tag name
	/// </summary>
	/// <param name="tagname">The tagname.</param>
	/// <returns></returns>
	NodeList<Element> Document::getElementsByTagName(tstring tagname) { return _doc->m_root->getElementsByTagName(tagname); }

	/// <summary>
	/// Not Supported - Returns true if the specified node has any attributes, otherwise false
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance has attributes; otherwise, <c>false</c>.
	/// </returns>
	bool Document::hasAttributes() { throw; } //: Node

	/// <summary>
	/// Returns true if an element has any child nodes, otherwise false
	/// </summary>
	/// <returns>
	///   <c>true</c> if [has child nodes]; otherwise, <c>false</c>.
	/// </returns>
	bool Document::hasChildNodes() { return _doc->m_root->m_children.size() > 0; } //: Node

	/// <summary>
	/// Returns a Boolean value indicating whether the document has focus
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance has focus; otherwise, <c>false</c>.
	/// </returns>
	bool Document::hasFocus() { return false; }

	/// <summary>
	/// Returns the <head> element of the document
	/// </summary>
	/// <value>
	/// The head.
	/// </value>
	Element* Document::head() { return nullptr; }

	/// <summary>
	///Returns a collection of all <img> elements in the document
	/// </summary>
	/// <value>
	/// The images.
	/// </value>
	HTMLCollection& Document::images() { return HTMLCollection(); }

	/// <summary>
	/// Returns the DOMImplementation object that handles this document
	/// </summary>
	/// <value>
	/// The implementation.
	/// </value>
	DocumentImplementation* Document::implementation() { return nullptr; }

	/// <summary>
	/// Imports a node from another document
	/// </summary>
	/// <param name="node">The node.</param>
	/// <param name="deep">if set to <c>true</c> [deep].</param>
	/// <returns></returns>
	Node* Document::importNode(Node* node, bool deep) { return nullptr; }

	/// <summary>
	/// Returns the encoding, character set, used for the document
	/// </summary>
	/// <value>
	/// The input encoding.
	/// </value>
	tstring Document::inputEncoding() { return _t("UTF-8"); }

	/// <summary>
	/// Returns true if a specified namespaceURI is the default, otherwise false
	/// </summary>
	/// <param name="namespaceURI">The namespace URI.</param>
	/// <returns>
	///   <c>true</c> if [is default namespace] [the specified namespace URI]; otherwise, <c>false</c>.
	/// </returns>
	bool Document::isDefaultNamespace(tstring namespaceURI) { return false; } //: Node

	/// <summary>
	/// Checks if two elements are equal
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns>
	///   <c>true</c> if [is equal node] [the specified node]; otherwise, <c>false</c>.
	/// </returns>
	bool Document::isEqualNode(Node* node) { return false; } //: Node

	/// <summary>
	/// Checks if two elements are the same node
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns>
	///   <c>true</c> if [is same node] [the specified node]; otherwise, <c>false</c>.
	/// </returns>
	bool Document::isSameNode(Node* node) { return false; } //: Node

	/// <summary>
	/// Returns the last child node of an element
	/// </summary>
	/// <value>
	/// The last child.
	/// </value>
	Node* Document::lastChild() { auto children = _doc->m_root->m_children; return children.size() > 0 ? children[children.size() - 1].get() : nullptr; } //: Node

	/// <summary>
	/// Returns the date and time the document was last modified
	/// </summary>
	/// <value>
	/// The last modified.
	/// </value>
	int64_t Document::lastModified() { return 0; }

	/// <summary>
	/// Returns a collection of all <a> and <area> elements in the document that have a href attribute
	/// </summary>
	/// <value>
	/// The links.
	/// </value>
	HTMLCollection& Document::links() { return HTMLCollection(); }

	/// <summary>
	/// Returns the next node at the same node tree level
	/// </summary>
	/// <value>
	/// The next sibling.
	/// </value>
	Node* Document::nextSibling() { return nullptr; } //: Node

	/// <summary>
	/// Returns the name of a node
	/// </summary>
	/// <value>
	/// The name of the node.
	/// </value>
	tstring Document::nodeName() { return _t("#document"); } //: Node

	/// <summary>
	/// Returns the node type of a node
	/// </summary>
	/// <value>
	/// The type of the node.
	/// </value>
	int Document::nodeType() { return 9; } //: Node

	/// <summary>
	/// Sets or returns the value of a node
	/// </summary>
	/// <value>
	/// The node value.
	/// </value>
	tstring Document::nodeValue() { return nullptr; }  //: Node
	void Document::nodeValue(tstring value) { } //: Node

	/// <summary>
	/// Removes empty Text nodes, and joins adjacent nodes
	/// </summary>
	void Document::normalize() { } //: Node

	/// <summary>
	/// Opens an HTML output stream to collect output from document.write()
	/// </summary>
	/// <param name="MIMEtype">The mim etype.</param>
	/// <param name="replace">The replace.</param>
	void Document::open(tstring MIMEtype, tstring replace) { }

	/// <summary>
	/// Returns the root element (document object) for an element
	/// </summary>
	/// <value>
	/// The owner document.
	/// </value>
	Document* Document::ownerDocument() { return nullptr; } //: Node

	/// <summary>
	/// Returns the parent node of an element
	/// </summary>
	/// <value>
	/// The parent node.
	/// </value>
	Node* Document::parentNode() { return nullptr; } //: Node

	/// <summary>
	/// Returns the previous node at the same node tree level
	/// </summary>
	/// <value>
	/// The previous sibling.
	/// </value>
	Node* Document::previousSibling() { return nullptr; } //: Node

	/// <summary>
	/// Returns the first element that matches a specified CSS selector(s) in the document
	/// </summary>
	/// <param name="selectors">The selectors.</param>
	/// <returns></returns>
	Element* Document::querySelector(tstring selectors) { return nullptr; }

	/// <summary>
	/// Returns a static NodeList containing all elements that matches a specified CSS selector(s) in the document
	/// </summary>
	/// <param name="selectors">The selectors.</param>
	/// <returns></returns>
	NodeList<Element> Document::querySelectorAll(tstring selectors) { return NodeList<Element>(); }

	/// <summary>
	/// Returns the (loading) status of the document
	/// </summary>
	/// <value>
	/// The state of the ready.
	/// </value>
	tstring Document::readyState() { return nullptr; }

	/// <summary>
	/// Returns the URL of the document that loaded the current document
	/// </summary>
	/// <value>
	/// The referrer.
	/// </value>
	tstring Document::referrer() { return nullptr; }

	/// <summary>
	/// Removes a child node from an element
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns></returns>
	Node* Document::removeChild(Node* node) { return nullptr; } //: Node

	/// <summary>
	/// Removes an event handler from the document (that has been attached with the addEventListener() method)
	/// </summary>
	/// <param name="event">The event.</param>
	/// <param name="function">The function.</param>
	/// <param name="useCapture">if set to <c>true</c> [use capture].</param>
	void Document::removeEventListener(tstring event, tstring function, bool useCapture) { }

	/// <summary>
	/// NotSupported - Renames the specified node
	/// </summary>
	/// <param name="node">The node.</param>
	/// <param name="namespaceURI">The namespace URI.</param>
	/// <param name="nodename">The nodename.</param>
	/// <returns></returns>
	Node* Document::renameNode(Node* node, tstring namespaceURI, tstring nodename) { return nullptr; }

	/// <summary>
	/// Replaces a child node in an element
	/// </summary>
	/// <param name="newnode">The newnode.</param>
	/// <param name="oldnode">The oldnode.</param>
	/// <returns></returns>
	Node* Document::replaceChild(Node* newnode, Node* oldnode) { return nullptr; } //: Node

	/// <summary>
	/// Returns a collection of <script> elements in the document
	/// </summary>
	/// <value>
	/// The scripts.
	/// </value>
	HTMLCollection& Document::scripts() { return HTMLCollection(); }

	/// <summary>
	/// Sets or returns the textual content of a node and its descendants
	/// </summary>
	/// <value>
	/// The content of the text.
	/// </value>
	tstring Document::textContent() { return nullptr; } //: Node
	void Document::textContent(tstring value) { } //: Node

	/// <summary>
	/// Sets or returns the title of the document
	/// </summary>
	/// <value>
	/// The title.
	/// </value>
	tstring Document::title() { return nullptr; }
	void Document::title(tstring value) { }

	/// <summary>
	/// Returns the full URL of the HTML document
	/// </summary>
	/// <value>
	/// The URL.
	/// </value>
	tstring Document::URL() { return nullptr; }

	/// <summary>
	/// Writes HTML expressions or JavaScript code to a document
	/// </summary>
	/// <param name="args">The arguments.</param>
	void Document::write(void** args) { }

	/// <summary>
	/// Same as write(), but adds a newline character after each statement
	/// </summary>
	/// <param name="args">The arguments.</param>
	void Document::writeln(void** args) { }
}

/// <summary>
/// Element
/// </summary>
namespace litehtml
{
	Element::Element() { _elem = static_cast<element*>(this); }

	/// <summary>
	/// Gets or sets the access key.
	/// </summary>
	/// <value>
	/// The access key.
	/// </value>
	char Element::accessKey() { return ' '; }
	void Element::accessKey(char value) { }

	/// <summary>
	/// Adds the event listener.
	/// </summary>
	/// <param name="event">The event.</param>
	/// <param name="function">The function.</param>
	/// <param name="useCapture">if set to <c>true</c> [use capture].</param>
	void Element::addEventListener(tstring event, tstring function, bool useCapture) { }

	/// <summary>
	/// Adds a new child node, to an element, as the last child node
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns></returns>
	Node* Element::appendChild(Node* node) //: Node
	{
		return nullptr;
	}

	/// <summary>
	/// Returns a NamedNodeMap of an element's attributes
	/// </summary>
	/// <value>
	/// The attributes.
	/// </value>
	NamedNodeMap Element::attributes() { return NamedNodeMap(dynamic_cast<html_tag*>(_elem)->m_attrs); } //: Node
	
	/// <summary>
	/// Returns the absolute base URI of a node
	/// </summary>
	/// <value>
	/// The base URI.
	/// </value>
	tstring Element::baseURI() { return _t("base"); } //: Node

	/// <summary>
	/// Removes focus from an element
	/// </summary>
	void Element::blur()
	{
	}

	/// <summary>
	/// Returns the number of child elements an element has
	/// </summary>
	/// <value>
	/// The child element count.
	/// </value>
	int Element::childElementCount() { return _elem->m_children.size(); }

	/// <summary>
	/// Returns a collection of an element's child nodes (including text and comment nodes)
	/// </summary>
	NodeList<Node> Element::childNodes() { return NodeList<Node>(_elem->m_children); } //: Node

	/// <summary>
	/// Returns a collection of an element's child element (excluding text and comment nodes)
	/// </summary>
	HTMLCollection& Element::children() { return HTMLCollection(); } // (_elem->_children)

	/// <summary>
	/// Returns the class name(s) of an element
	/// </summary>
	/// <value>
	/// The class list.
	/// </value>
	DOMTokenList& Element::classList() { return DOMTokenList(); }

	/// <summary>
	/// Sets or returns the value of the class attribute of an element
	/// </summary>
	/// <value>
	/// The name of the class.
	/// </value>
	tstring Element::className() { return _elem->get_attr(_t("class")); }
	void Element::className(tstring value) { _elem->set_attr(_t("class"), value.c_str()); }

	/// <summary>
	/// Simulates a mouse-click on an element
	/// </summary>
	void Element::click() { }

	/// <summary>
	/// Returns the height of an element, including padding
	/// </summary>
	/// <value>
	/// The height of the client.
	/// </value>
	int Element::clientHeight() { return 0; }

	/// <summary>
	/// Returns the width of the left border of an element
	/// </summary>
	/// <value>
	/// The client left.
	/// </value>
	int Element::clientLeft() { return 0; }

	/// <summary>
	/// Returns the width of the top border of an element
	/// </summary>
	/// <value>
	/// The client top.
	/// </value>
	int Element::clientTop() { return 0; }

	/// <summary>
	/// Returns the width of an element, including padding
	/// </summary>
	/// <value>
	/// The width of the client.
	/// </value>
	int Element::clientWidth() { return 0; }

	/// <summary>
	/// Clones an element
	/// </summary>
	/// <param name="deep">if set to <c>true</c> [deep].</param>
	/// <returns></returns>
	Node* Element::cloneNode(bool deep /*= false*/) //: Node
	{
		return nullptr;
	}

	/// <summary>
	/// Compares the document position of two elements
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns></returns>
	int Element::compareDocumentPosition(Node* node) //: Node
	{
		return 0;
	}

	/// <summary>
	/// Returns true if a node is a descendant of a node, otherwise false
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns>
	///   <c>true</c> if [contains] [the specified node]; otherwise, <c>false</c>.
	/// </returns>
	bool Element::contains(Node* node) { return false; }

	/// <summary>
	/// Sets or returns whether the content of an element is editable or not
	/// </summary>
	/// <value>
	/// The content editable.
	/// </value>
	tstring Element::contentEditable() { return nullptr; }
	void Element::contentEditable(tstring value) { }

	/// <summary>
	/// Sets or returns the value of the dir attribute of an element
	/// </summary>
	/// <value>
	/// The dir.
	/// </value>
	tstring Element::dir() { return nullptr; }
	void Element::dir(tstring value) { }

	/// <summary>
	/// Cancels an element in fullscreen mode
	/// </summary>
	void Element::exitFullscreen() { }

	/// <summary>
	/// Returns the first child node of an element
	/// </summary>
	/// <value>
	/// The first child.
	/// </value>
	Node* Element::firstChild() { return _elem->m_children[0].get(); } //: Node
	
	/// <summary>
	/// Returns the first child element of an element
	/// </summary>
	/// <value>
	/// The first element child.
	/// </value>
	Element* Element::firstElementChild() { return !_elem->m_children.empty() ? _elem->m_children[0].get() : nullptr; }

	/// <summary>
	/// Gives focus to an element
	/// </summary>
	void Element::focus() { }

	/// <summary>
	/// Returns the specified attribute value of an element node
	/// </summary>
	/// <param name="attributename">The attributename.</param>
	/// <returns></returns>
	tstring Element::getAttribute(tstring attributename) { return _elem->get_attr(attributename.c_str()); }

	/// <summary>
	/// Returns the specified attribute node
	/// </summary>
	/// <param name="attributename">The attributename.</param>
	/// <returns></returns>
	Attr::ptr Element::getAttributeNode(tstring attributename) { return std::make_shared<Attr>(&dynamic_cast<html_tag*>(_elem)->m_attrs, attributename); }

	/// <summary>
	/// Returns the size of an element and its position relative to the viewport
	/// </summary>
	/// <returns></returns>
	Rect* Element::getBoundingClientRect() { return nullptr; }

	/// <summary>
	/// Returns a collection of all child elements with the specified class name
	/// </summary>
	/// <param name="classname">The classname.</param>
	/// <returns></returns>
	NodeList<Element> Element::getElementsByClassName(tstring classname)
	{
		css_element_selector elem;
		css_attribute_selector attr;
		attr.val = classname;
		attr.condition = select_equal;
		attr.attribute = _t("class");
		elem.m_attrs.push_back(attr);
		css_selector sel(elem);
		return NodeList<Element>(_elem->select_all(sel));
	}

	/// <summary>
	/// Returns a collection of all child elements with the specified tag name
	/// </summary>
	/// <param name="tagname">The tagname.</param>
	/// <returns></returns>
	NodeList<Element> Element::getElementsByTagName(tstring tagname)
	{
		css_element_selector elem;
		elem.m_tag = tagname;
		litehtml::lcase(elem.m_tag);
		css_selector sel(elem);
		return NodeList<Element>(_elem->select_all(sel));
	}

	/// <summary>
	/// Returns true if an element has the specified attribute, otherwise false
	/// </summary>
	/// <param name="attributename">The attributename.</param>
	/// <returns>
	///   <c>true</c> if the specified attributename has attribute; otherwise, <c>false</c>.
	/// </returns>
	bool Element::hasAttribute(tstring attributename) { return false; } //: Node
	

	/// <summary>
	/// Returns true if an element has any attributes, otherwise false
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance has attributes; otherwise, <c>false</c>.
	/// </returns>
	bool Element::hasAttributes() { return false; }

	/// <summary>
	/// Returns true if an element has any child nodes, otherwise false
	/// </summary>
	/// <returns>
	///   <c>true</c> if [has child nodes]; otherwise, <c>false</c>.
	/// </returns>
	bool Element::hasChildNodes() { return !_elem->m_children.empty(); } //: Node
	
	/// <summary>
	/// Sets or returns the value of the id attribute of an element
	/// </summary>
	/// <value>
	/// The identifier.
	/// </value>
	tstring Element::id() { return _elem->get_attr(_t("id")); }
	void Element::id(tstring value) { _elem->set_attr(_t("id"), value.c_str()); }

	/// <summary>
	/// Sets or returns the content of an element
	/// </summary>
	/// <value>
	/// The inner HTML.
	/// </value>
	tstring Element::innerHTML() { return nullptr; }
	void Element::innerHTML(tstring value) { }

	/// <summary>
	/// Sets or returns the text content of a node and its descendants
	/// </summary>
	/// <value>
	/// The inner text.
	/// </value>
	tstring Element::innerText() { return nullptr; }
	void Element::innerText(tstring value) { }

	/// <summary>
	/// Inserts a HTML element at the specified position relative to the current element
	/// </summary>
	/// <param name="position">The position.</param>
	/// <param name="element">The element.</param>
	void Element::insertAdjacentElement(tstring position, Element* element) { }

	/// <summary>
	/// Inserts a HTML formatted text at the specified position relative to the current element
	/// </summary>
	/// <param name="position">The position.</param>
	/// <param name="text">The text.</param>
	void Element::insertAdjacentHTML(tstring position, tstring text) { }

	/// <summary>
	/// Inserts text into the specified position relative to the current element
	/// </summary>
	/// <param name="position">The position.</param>
	/// <param name="text">The text.</param>
	void Element::insertAdjacentText(tstring position, tstring text) { }

	/// <summary>
	/// Inserts a new child node before a specified, existing, child node
	/// </summary>
	/// <param name="newnode">The newnode.</param>
	/// <param name="existingnode">The existingnode.</param>
	Node* Element::insertBefore(Node* newnode, Node* existingnode) { return nullptr; }

	/// <summary>
	/// Returns true if the content of an element is editable, otherwise false
	/// </summary>
	/// <value>
	///   <c>true</c> if this instance is content editable; otherwise, <c>false</c>.
	/// </value>
	bool Element::isContentEditable() { return false; }

	/// <summary>
	/// Returns true if a specified namespaceURI is the default, otherwise false
	/// </summary>
	/// <param name="namespaceURI">The namespace URI.</param>
	/// <returns>
	///   <c>true</c> if [is default namespace] [the specified namespace URI]; otherwise, <c>false</c>.
	/// </returns>
	bool Element::isDefaultNamespace(tstring namespaceURI) { return false; } //: Node

	/// <summary>
	/// Checks if two elements are equal
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns>
	///   <c>true</c> if [is equal node] [the specified node]; otherwise, <c>false</c>.
	/// </returns>
	bool Element::isEqualNode(Node* node) { return false; } //: Node

	/// <summary>
	/// Checks if two elements are the same node
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns>
	///   <c>true</c> if [is same node] [the specified node]; otherwise, <c>false</c>.
	/// </returns>
	bool Element::isSameNode(Node* node) { return false; } //: Node

	/// <summary>
	/// Sets or returns the value of the lang attribute of an element
	/// </summary>
	/// <value>
	/// The language.
	/// </value>
	tstring Element::lang() { return nullptr; }
	void Element::lang(tstring value) { }

	/// <summary>
	/// Returns the last child node of an element
	/// </summary>
	/// <value>
	/// The last child.
	/// </value>
	Node* Element::lastChild() { return !_elem->m_children.empty() ? _elem->m_children[_elem->m_children.size() - 1].get() : nullptr; } //: Node

	/// <summary>
	/// Returns the last child element of an element
	/// </summary>
	/// <value>
	/// The last element child.
	/// </value>
	Element* Element::lastElementChild() { return !_elem->m_children.empty() ? _elem->m_children[_elem->m_children.size() - 1].get() : nullptr; }

	/// <summary>
	/// Returns the namespace URI of an element
	/// </summary>
	/// <value>
	/// The namespace URI.
	/// </value>
	tstring Element::namespaceURI() { return nullptr; }

	/// <summary>
	/// Returns the next node at the same node tree level
	/// </summary>
	/// <value>
	/// The next sibling.
	/// </value>
	Node* Element::nextSibling() { return nullptr; } //: Node

	/// <summary>
	/// Returns the next element at the same node tree level
	/// </summary>
	/// <value>
	/// The next element sibling.
	/// </value>
	Element* Element::nextElementSibling() { return nullptr; }

	/// <summary>
	/// Returns the name of a node
	/// </summary>
	/// <value>
	/// The name of the node.
	/// </value>
	tstring Element::nodeName() { return nullptr; } //: Node

	/// <summary>
	/// Returns the node type of a node
	/// </summary>
	/// <value>
	/// The type of the node.
	/// </value>
	int Element::nodeType() { return 0; } //: Node

	/// <summary>
	/// Sets or returns the value of a node
	/// </summary>
	/// <value>
	/// The node value.
	/// </value>
	tstring Element::nodeValue() { return nullptr; } //: Node
	void Element::nodeValue(tstring value) { } //: Node

	/// <summary>
	/// Joins adjacent text nodes and removes empty text nodes in an element
	/// </summary>
	void Element::normalize() { } //: Node

	/// <summary>
	/// Returns the height of an element, including padding, border and scrollbar
	/// </summary>
	/// <value>
	/// The height of the offset.
	/// </value>
	int Element::offsetHeight() { return 0; }

	/// <summary>
	/// Returns the width of an element, including padding, border and scrollbar
	/// </summary>
	/// <value>
	/// The width of the offset.
	/// </value>
	int Element::offsetWidth() { return 0; }

	/// <summary>
	/// Returns the horizontal offset position of an element
	/// </summary>
	/// <value>
	/// The offset left.
	/// </value>
	int Element::offsetLeft() { return 0; }

	/// <summary>
	/// Returns the offset container of an element
	/// </summary>
	/// <value>
	/// The offset parent.
	/// </value>
	Node* Element::offsetParent() { return nullptr; }

	/// <summary>
	/// Returns the vertical offset position of an element
	/// </summary>
	/// <value>
	/// The offset top.
	/// </value>
	int Element::offsetTop() { return 0; }

	/// <summary>
	/// Returns the root element (document object) for an element
	/// </summary>
	/// <value>
	/// The owner document.
	/// </value>
	Document* Element::ownerDocument() { return nullptr; } //: Node

	/// <summary>
	/// Returns the parent node of an element
	/// </summary>
	/// <value>
	/// The parent node.
	/// </value>
	Node* Element::parentNode() { return nullptr; } //: Node

	/// <summary>
	/// Returns the parent element node of an element
	/// </summary>
	/// <value>
	/// The parent element.
	/// </value>
	Element* Element::parentElement() { return nullptr; }

	/// <summary>
	/// Returns the previous node at the same node tree level
	/// </summary>
	/// <value>
	/// The previous sibling.
	/// </value>
	Node* Element::previousSibling() { return nullptr; } //: Node

	/// <summary>
	/// Returns the previous element at the same node tree level
	/// </summary>
	/// <value>
	/// The previous element sibling.
	/// </value>
	Element* Element::previousElementSibling() { return nullptr; }

	/// <summary>
	/// Returns the first child element that matches a specified CSS selector(s) of an element
	/// </summary>
	/// <param name="selectors">The selectors.</param>
	/// <returns></returns>
	Element* Element::querySelector(tstring selectors) { return _elem->select_one(selectors).get(); }

	/// <summary>
	/// Returns all child elements that matches a specified CSS selector(s) of an element
	/// </summary>
	/// <param name="selectors">The selectors.</param>
	/// <returns></returns>
	NodeList<Element> Element::querySelectorAll(tstring selectors) { return NodeList<Element>(); }

	/// <summary>
	/// Removes a specified attribute from an element
	/// </summary>
	/// <param name="attributename">The attributename.</param>
	void Element::removeAttribute(tstring attributename) { }

	/// <summary>
	/// Removes a specified attribute node, and returns the removed node
	/// </summary>
	/// <param name="attributenode">The attributenode.</param>
	/// <returns></returns>
	Attr::ptr Element::removeAttributeNode(Attr::ptr attributenode) { return nullptr; }

	/// <summary>
	/// Removes a child node from an element
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns></returns>
	Node* Element::removeChild(Node* node) { return nullptr; } //: Node

	/// <summary>
	/// Removes an event handler that has been attached with the addEventListener() method
	/// </summary>
	/// <param name="event">The event.</param>
	/// <param name="function">The function.</param>
	/// <param name="useCapture">if set to <c>true</c> [use capture].</param>
	void Element::removeEventListener(tstring event, tstring function, bool useCapture) { }

	/// <summary>
	/// Shows an element in fullscreen mode
	/// </summary>
	void Element::requestFullscreen() { }

	/// <summary>
	/// Replaces a child node in an element
	/// </summary>
	/// <param name="newnode">The newnode.</param>
	/// <param name="oldnode">The oldnode.</param>
	/// <returns></returns>
	Node* Element::replaceChild(Node* newnode, Node* oldnode) { return nullptr; } //: Node

	/// <summary>
	/// Returns the entire height of an element, including padding
	/// </summary>
	/// <value>
	/// The height of the scroll.
	/// </value>
	int Element::scrollHeight() { return 0; }

	/// <summary>
	/// Scrolls the specified element into the visible area of the browser window
	/// </summary>
	/// <param name="alignTo">The align to.</param>
	void Element::scrollIntoView(bool alignTo) { }

	/// <summary>
	/// Sets or returns the number of pixels an element's content is scrolled horizontally
	/// </summary>
	/// <value>
	/// The scroll left.
	/// </value>
	int Element::scrollLeft() { return 0; }
	void Element::scrollLeft(int value) { }

	/// <summary>
	/// Sets or returns the number of pixels an element's content is scrolled vertically
	/// </summary>
	/// <value>
	/// The scroll top.
	/// </value>
	int Element::scrollTop() { return 0; }
	void Element::scrollTop(int value) { }

	/// <summary>
	/// Returns the entire width of an element, including padding
	/// </summary>
	/// <value>
	/// The width of the scroll.
	/// </value>
	int Element::scrollWidth() { return 0; }

	/// <summary>
	/// Sets or changes the specified attribute, to the specified value
	/// </summary>
	/// <param name="attributename">The attributename.</param>
	/// <param name="attributevalue">The attributevalue.</param>
	void Element::setAttribute(tstring attributename, tstring attributevalue) { }

	/// <summary>
	/// Sets or changes the specified attribute node
	/// </summary>
	/// <param name="attributenode">The attributenode.</param>
	/// <returns></returns>
	Attr::ptr Element::setAttributeNode(Attr::ptr attributenode) { return nullptr; }

	/// <summary>
	/// Sets or returns the value of the style attribute of an element
	/// </summary>
	/// <value>
	/// The style.
	/// </value>
	Style* Element::style() { return nullptr; }

	/// <summary>
	/// Sets or returns the value of the tabindex attribute of an element
	/// </summary>
	/// <value>
	/// The index of the tab.
	/// </value>
	tstring Element::tabIndex() { return 0; }
	void Element::tabIndex(tstring value) { }

	/// <summary>
	/// Returns the tag name of an element
	/// </summary>
	/// <value>
	/// The name of the tag.
	/// </value>
	tstring Element::tagName() { return nullptr; }

	/// <summary>
	/// Sets or returns the textual content of a node and its descendants
	/// </summary>
	/// <value>
	/// The content of the text.
	/// </value>
	tstring Element::textContent() { return nullptr; } //: Node
	void Element::textContent(tstring value) { } //: Node

	/// <summary>
	/// Sets or returns the value of the title attribute of an element
	/// </summary>
	/// <value>
	/// The title.
	/// </value>
	tstring Element::title() { return nullptr; }
	void Element::title(tstring value) { }

	/// <summary>
	/// Converts an element to a string
	/// </summary>
	tstring Element::toString() { return nullptr; }
}
