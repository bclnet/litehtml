#include "html.h"
#include "document.h"
#include <iterator>
using namespace std;

/// <summary>
/// Rect
/// </summary>
namespace litehtml
{
};

/// <summary>
/// DocumentFragment
/// </summary>
namespace litehtml
{
};

/// <summary>
/// DocumentType
/// </summary>
namespace litehtml
{
	//DocumentType::_toHTML() { return "<!DOCTYPE html>"; }
};

/// <summary>
/// DocumentImplementation
/// </summary>
namespace litehtml
{
};

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
	void Console::assert_(bool assertion, tany message) { if (!assertion) throw exception("error"); }

	/// <summary>
	/// Clears the console
	/// </summary>
	void Console::clear() { }

	/// <summary>
	/// Logs the number of times that this particular call to count() has been called
	/// </summary>
	/// <param name="label">The label.</param>
	void Console::count(string label /*= _tdefault*/) { }

	/// <summary>
	/// Outputs an error message to the console
	/// </summary>
	/// <param name="message">The message.</param>
	void Console::error(tany message) { }

	/// <summary>
	/// Creates a new inline group in the console. This indents following console messages by an additional level, until console.groupEnd() is called
	/// </summary>
	/// <param name="label">The label.</param>
	void Console::group(string label /*= _tdefault*/) { }

	/// <summary>
	/// Creates a new inline group in the console. However, the new group is created collapsed. The user will need to use the disclosure button to expand it
	/// </summary>
	/// <param name="label">The label.</param>
	void Console::groupCollapsed(string label /*= _tdefault*/) { }

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
	void Console::table(void* tabledata, string tablecolumns[] /*= nullptr*/) { }

	/// <summary>
	/// Starts a timer (can track how long an operation takes)
	/// </summary>
	/// <param name="label">The label.</param>
	void Console::time(string label /*= _tdefault*/) { }

	/// <summary>
	/// Stops a timer that was previously started by console.time()
	/// </summary>
	/// <param name="label">The label.</param>
	void Console::timeEnd(string label /*= _tdefault*/) { }

	/// <summary>
	/// Outputs a stack trace to the console
	/// </summary>
	/// <param name="label">The label.</param>
	void Console::trace(string label /*= _tdefault*/) { }

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
	Element::ptr Document::activeElement() { return nullptr; }

	/// <summary>
	/// Attaches an event handler to the document
	/// </summary>
	/// <param name="event">The event.</param>
	/// <param name="function">The function.</param>
	/// <param name="useCapture">if set to <c>true</c> [use capture].</param>
	//void Document::addEventListener(string event, void* function, bool useCapture) { } //: EventTarget

	/// <summary>
	/// Adopts a node from another document
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns></returns>
	Node::ptr Document::adoptNode(Node::ptr node) { return nullptr; }

	/// <summary>
	/// Returns a collection of all <a> elements in the document that have a name attribute
	/// </summary>
	/// <value>
	/// The anchors.
	/// </value>
	HTMLCollection Document::anchors() {
		auto s = elements_list();
		return s;
	}

	/// <summary>
	/// Adds a new child node, to an element, as the last child node
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns></returns>
	Node::ptr Document::appendChild(Node::ptr node) { //: Node
		return nullptr;
	}

	/// <summary>
	/// Returns a collection of all <applet> elements in the document
	/// </summary>
	/// <value>
	/// The applets.
	/// </value>
	HTMLCollection Document::applets() {
		auto s = elements_list();
		return s;
	}

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
	string Document::baseURI() { return ""; } //: Node

	/// <summary>
	/// Sets or returns the document's body (the <body> element)
	/// </summary>
	/// <value>
	/// The body.
	/// </value>
	Element::ptr Document::body() { return nullptr; }
	void Document::body(Element* value) { }

	/// <summary>
	/// Returns the character encoding for the document
	/// </summary>
	/// <value>
	/// The character set.
	/// </value>
	string Document::charset() { return "UTF-8"; }

	/// <summary>
	/// Returns the character encoding for the document
	/// </summary>
	/// <value>
	/// The character set.
	/// </value>
	string Document::characterSet() { return "UTF-8"; }

	/// <summary>
	/// Returns a collection of an element's child nodes (including text and comment nodes)
	/// </summary>
	NodeList<Node> Document::childNodes() { return _doc->m_root->m_children; } //: Node

	/// <summary>
	/// Clones an element
	/// </summary>
	/// <param name="deep">if set to <c>true</c> [deep].</param>
	/// <returns></returns>
	Node::ptr Document::cloneNode(bool deep /*= false*/) { return nullptr; } //: Node

	/// <summary>
	/// Closes the output stream previously opened with document.open()
	/// </summary>
	void Document::close() { }

	/// <summary>
	/// Compares the document position of two elements
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns></returns>
	int Document::compareDocumentPosition(Node::ptr node) { return 0; } //: Node

	/// <summary>
	/// Returns all name/value pairs of cookies in the document
	/// </summary>
	/// <value>
	/// The cookie.
	/// </value>
	string Document::cookie() { return ""; }
	void Document::cookie(string value) { }

	/// <summary>
	/// Creates an attribute node
	/// </summary>
	/// <param name="attributename">The attributename.</param>
	/// <returns></returns>
	Attr::ptr Document::createAttribute(string attributename) { return std::make_shared<Attr>(new string_map(), attributename.c_str()); }

	/// <summary>
	/// Creates a Comment node with the specified text
	/// </summary>
	/// <param name="text">The text.</param>
	/// <returns></returns>
	Node::ptr Document::createComment(string text) { return nullptr; } //: IComment

	/// <summary>
	/// Creates an empty DocumentFragment node
	/// </summary>
	/// <returns></returns>
	DocumentFragment::ptr Document::createDocumentFragment() { return nullptr; }

	/// <summary>
	/// Creates an Element node
	/// </summary>
	/// <param name="nodename">The nodename.</param>
	/// <returns></returns>
	Element::ptr Document::createElement(string nodename) { return nullptr; }

	/// <summary>
	/// Creates a new event
	/// </summary>
	/// <param name="type">The type.</param>
	/// <returns></returns>
	Event::ptr Document::createEvent(string type) { return nullptr; }

	/// <summary>
	/// Creates a Text node
	/// </summary>
	/// <param name="text">The text.</param>
	/// <returns></returns>
	Node::ptr Document::createTextNode(string text) { return nullptr; } //: IText

	/// <summary>
	/// Returns the window object associated with a document, or nullptr if none is available.
	/// </summary>
	/// <value>
	/// The default view.
	/// </value>
	Window::ptr Document::defaultView() { return nullptr; }

	/// <summary>
	/// Controls whether the entire document should be editable or not.
	/// </summary>
	/// <value>
	/// The design mode.
	/// </value>
	string Document::designMode() { return "off"; }
	void Document::designMode(string value) { throw; }

	/// <summary>
	/// Returns the Document Type Declaration associated with the document
	/// </summary>
	/// <value>
	/// The doctype.
	/// </value>
	DocumentType::ptr Document::doctype() { return nullptr; }

	/// <summary>
	/// Returns the Document Element of the document (the <html> element)
	/// </summary>
	/// <value>
	/// The document element.
	/// </value>
	Element::ptr Document::documentElement() { return nullptr; }

	/// <summary>
	/// Sets or returns the location of the document
	/// </summary>
	/// <value>
	/// The document URI.
	/// </value>
	string Document::documentURI() { return ""; }
	void Document::documentURI(string value) { }

	/// <summary>
	/// Returns the domain name of the server that loaded the document
	/// </summary>
	/// <value>
	/// The domain.
	/// </value>
	string Document::domain() { return ""; }

	/// <summary>
	/// Returns a collection of all <embed> elements the document
	/// </summary>
	/// <value>
	/// The embeds.
	/// </value>
	HTMLCollection Document::embeds() {
		auto s = elements_list();
		return s;
	}

	/// <summary>
	/// Invokes the specified clipboard operation on the element currently having focus.
	/// </summary>
	/// <param name="command">The command.</param>
	/// <param name="showUI">if set to <c>true</c> [show UI].</param>
	/// <param name="value">The value.</param>
	/// <returns></returns>
	bool Document::execCommand(string command, bool showUI, void* value) { return false; }

	/// <summary>
	/// Returns the first child node of an element
	/// </summary>
	/// <value>
	/// The first child.
	/// </value>
	Node::ptr Document::firstChild() { return _doc->m_root->m_children.front(); } //: Node

	/// <summary>
	/// Returns a collection of all &lt;form&gt; elements in the document
	/// </summary>
	/// <value>
	/// The forms.
	/// </value>
	HTMLCollection Document::forms() {
		auto s = elements_list();
		return s;
	}

	/// <summary>
	/// Returns the current element that is displayed in fullscreen mode
	/// </summary>
	/// <value>
	/// The fullscreen element.
	/// </value>
	Element::ptr Document::fullscreenElement() { return nullptr; }

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
	Element::ptr Document::getElementById(string elementID) {
		//TODO return this._childNodesRecursiveFind(node = > node instanceof Element && node.getAttribute('id') == = id) || null;
		litehtml::lcase(elementID);
		css_element_selector elem;
		elem.m_tag = _id("*");
		css_attribute_selector attr;
		attr.type = select_id;
		attr.name = _id(elementID);
		elem.m_attrs.push_back(attr);
		css_selector sel(elem);
		return _doc->m_root->select_one(sel);
	}

	/// <summary>
	/// Returns a NodeList containing all elements with the specified class name
	/// </summary>
	/// <param name="classname">The classname.</param>
	/// <returns></returns>
	NodeList<Element> Document::getElementsByClassName(string classname) { return _doc->m_root->getElementsByClassName(classname); }

	/// <summary>
	/// Returns a NodeList containing all elements with a specified name
	/// </summary>
	/// <param name="name">The name.</param>
	/// <returns></returns>
	NodeList<Element> Document::getElementsByName(string name) {
		litehtml::lcase(name);
		css_element_selector elem;
		elem.m_tag = _id("*");
		css_attribute_selector attr;
		attr.type = select_equal;
		attr.name = _id("name");
		attr.val = name;
		elem.m_attrs.push_back(attr);
		css_selector sel(elem);
		return _doc->m_root->select_all(sel);
	}

	/// <summary>
	/// Returns a NodeList containing all elements with the specified tag name
	/// </summary>
	/// <param name="tagname">The tagname.</param>
	/// <returns></returns>
	NodeList<Element> Document::getElementsByTagName(string tagname) {
		//TODO
		//if (!tagName) {
		//	return this._createCollection(child = > true);
		//}

		//tagName = tagName.toLowerCase();
		//return this._createCollection(child = > child.nodeName.toLowerCase() == = tagName);
		return _doc->m_root->getElementsByTagName(tagname);
	}

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
	/// Returns the &lt;head&gt; element of the document
	/// </summary>
	/// <value>
	/// The head.
	/// </value>
	Element::ptr Document::head() { return nullptr; }

	/// <summary>
	///Returns a collection of all <img> elements in the document
	/// </summary>
	/// <value>
	/// The images.
	/// </value>
	HTMLCollection Document::images() {
		auto s = elements_list();
		return s;
	}

	/// <summary>
	/// Returns the DOMImplementation object that handles this document
	/// </summary>
	/// <value>
	/// The implementation.
	/// </value>
	DocumentImplementation::ptr Document::implementation() { return nullptr; }

	/// <summary>
	/// Imports a node from another document
	/// </summary>
	/// <param name="node">The node.</param>
	/// <param name="deep">if set to <c>true</c> [deep].</param>
	/// <returns></returns>
	Node::ptr Document::importNode(Node::ptr node, bool deep) { return nullptr; }

	/// <summary>
	/// Returns the encoding, character set, used for the document
	/// </summary>
	/// <value>
	/// The input encoding.
	/// </value>
	string Document::inputEncoding() { return "UTF-8"; }

	/// <summary>
	/// Returns true if a specified namespaceURI is the default, otherwise false
	/// </summary>
	/// <param name="namespaceURI">The namespace URI.</param>
	/// <returns>
	///   <c>true</c> if [is default namespace] [the specified namespace URI]; otherwise, <c>false</c>.
	/// </returns>
	bool Document::isDefaultNamespace(string namespaceURI) { return false; } //: Node

	/// <summary>
	/// Checks if two elements are equal
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns>
	///   <c>true</c> if [is equal node] [the specified node]; otherwise, <c>false</c>.
	/// </returns>
	bool Document::isEqualNode(Node::ptr node) { return false; } //: Node

	/// <summary>
	/// Checks if two elements are the same node
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns>
	///   <c>true</c> if [is same node] [the specified node]; otherwise, <c>false</c>.
	/// </returns>
	bool Document::isSameNode(Node::ptr node) { return false; } //: Node

	/// <summary>
	/// Returns the last child node of an element
	/// </summary>
	/// <value>
	/// The last child.
	/// </value>
	Node::ptr Document::lastChild() { auto children = _doc->m_root->m_children; return children.size() > 0 ? children.back() : nullptr; } //: Node

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
	HTMLCollection Document::links() {
		auto s = elements_list();
		return s;
	}

	/// <summary>
	/// Returns the next node at the same node tree level
	/// </summary>
	/// <value>
	/// The next sibling.
	/// </value>
	Node::ptr Document::nextSibling() { return nullptr; } //: Node

	/// <summary>
	/// Returns the name of a node
	/// </summary>
	/// <value>
	/// The name of the node.
	/// </value>
	string Document::nodeName() { return "#document"; } //: Node

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
	string Document::nodeValue() { return ""; }  //: Node
	void Document::nodeValue(string value) { } //: Node

	/// <summary>
	/// Removes empty Text nodes, and joins adjacent nodes
	/// </summary>
	void Document::normalize() { } //: Node

	/// <summary>
	/// Opens an HTML output stream to collect output from document.write()
	/// </summary>
	/// <param name="MIMEtype">The mim etype.</param>
	/// <param name="replace">The replace.</param>
	void Document::open(string MIMEtype, string replace) { }

	/// <summary>
	/// Returns the root element (document object) for an element
	/// </summary>
	/// <value>
	/// The owner document.
	/// </value>
	Document::ptr Document::ownerDocument() { return nullptr; } //: Node

	/// <summary>
	/// Returns the parent node of an element
	/// </summary>
	/// <value>
	/// The parent node.
	/// </value>
	Node::ptr Document::parentNode() { return nullptr; } //: Node

	/// <summary>
	/// Returns the previous node at the same node tree level
	/// </summary>
	/// <value>
	/// The previous sibling.
	/// </value>
	Node::ptr Document::previousSibling() { return nullptr; } //: Node

	/// <summary>
	/// Returns the first element that matches a specified CSS selector(s) in the document
	/// </summary>
	/// <param name="selectors">The selectors.</param>
	/// <returns></returns>
	Element::ptr Document::querySelector(string selectors) { return nullptr; }

	/// <summary>
	/// Returns a static NodeList containing all elements that matches a specified CSS selector(s) in the document
	/// </summary>
	/// <param name="selectors">The selectors.</param>
	/// <returns></returns>
	NodeList<Element> Document::querySelectorAll(string selectors) { return NodeList<Element>(); }

	/// <summary>
	/// Returns the (loading) status of the document
	/// </summary>
	/// <value>
	/// The state of the ready.
	/// </value>
	string Document::readyState() { return ""; }

	/// <summary>
	/// Returns the URL of the document that loaded the current document
	/// </summary>
	/// <value>
	/// The referrer.
	/// </value>
	string Document::referrer() { return ""; }

	/// <summary>
	/// Removes a child node from an element
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns></returns>
	Node::ptr Document::removeChild(Node::ptr node) { return nullptr; } //: Node

	/// <summary>
	/// Removes an event handler from the document (that has been attached with the addEventListener() method)
	/// </summary>
	/// <param name="event">The event.</param>
	/// <param name="function">The function.</param>
	/// <param name="useCapture">if set to <c>true</c> [use capture].</param>
	//void Document::removeEventListener(string event, void* function, bool useCapture) { } //: EventTarget

	/// <summary>
	/// NotSupported - Renames the specified node
	/// </summary>
	/// <param name="node">The node.</param>
	/// <param name="namespaceURI">The namespace URI.</param>
	/// <param name="nodename">The nodename.</param>
	/// <returns></returns>
	Node::ptr Document::renameNode(Node::ptr node, string namespaceURI, string nodename) { return nullptr; }

	/// <summary>
	/// Replaces a child node in an element
	/// </summary>
	/// <param name="newnode">The newnode.</param>
	/// <param name="oldnode">The oldnode.</param>
	/// <returns></returns>
	Node::ptr Document::replaceChild(Node::ptr newnode, Node::ptr oldnode) { return nullptr; } //: Node

	/// <summary>
	/// Returns a collection of <script> elements in the document
	/// </summary>
	/// <value>
	/// The scripts.
	/// </value>
	HTMLCollection Document::scripts() {
		auto s = elements_list();
		return s;
	}

	/// <summary>
	/// Sets or returns the textual content of a node and its descendants
	/// </summary>
	/// <value>
	/// The content of the text.
	/// </value>
	string Document::textContent() { return ""; } //: Node
	void Document::textContent(string value) { } //: Node

	/// <summary>
	/// Sets or returns the title of the document
	/// </summary>
	/// <value>
	/// The title.
	/// </value>
	string Document::title() { return ""; }
	void Document::title(string value) { }

	/// <summary>
	/// Returns the full URL of the HTML document
	/// </summary>
	/// <value>
	/// The URL.
	/// </value>
	string Document::URL() { return ""; }

	/// <summary>
	/// Writes HTML expressions or JavaScript code to a document
	/// </summary>
	/// <param name="args">The arguments.</param>
	void Document::write(void* args) { }

	/// <summary>
	/// Same as write(), but adds a newline character after each statement
	/// </summary>
	/// <param name="args">The arguments.</param>
	void Document::writeln(void* args) { }
}

/// <summary>
/// Element
/// </summary>
namespace litehtml
{
	Element::Element() { _elem = static_cast<element*>(this); }
	Element::Element(element::ptr& elem) : _elem(elem.get()) { }

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
	//void Element::addEventListener(string event, void* function, bool useCapture) { } //: EventTarget

	/// <summary>
	/// Adds a new child node, to an element, as the last child node
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns></returns>
	Node::ptr Element::appendChild(Node::ptr node) { //: Node
		return nullptr;
	}

	/// <summary>
	/// Returns a NamedNodeMap of an element's attributes
	/// </summary>
	/// <value>
	/// The attributes.
	/// </value>
	NamedNodeMap Element::attributes() { return dynamic_cast<html_tag*>(_elem)->m_attrs; } //: Node

	/// <summary>
	/// Returns the absolute base URI of a node
	/// </summary>
	/// <value>
	/// The base URI.
	/// </value>
	string Element::baseURI() { return "base"; } //: Node

	/// <summary>
	/// Removes focus from an element
	/// </summary>
	void Element::blur() { }

	/// <summary>
	/// Returns the number of child elements an element has
	/// </summary>
	/// <value>
	/// The child element count.
	/// </value>
	int Element::childElementCount() {
		return (int)_elem->m_children.size();
	}

	/// <summary>
	/// Returns a collection of an element's child nodes (including text and comment nodes)
	/// </summary>
	NodeList<Node> Element::childNodes() { return _elem->m_children; } //: Node

	/// <summary>
	/// Returns a collection of an element's child element (excluding text and comment nodes)
	/// </summary>
	HTMLCollection Element::children() {
		elements_list out;
		copy_if(begin(_elem->m_children), end(_elem->m_children), std::back_inserter(out), [](element::ptr node) { return node->nodeType() == 0; });
		return out;
	}

	/// <summary>
	/// Returns the class name(s) of an element
	/// </summary>
	/// <value>
	/// The class list.
	/// </value>
	DOMTokenList::ptr Element::classList() {
		DOMTokenList::ptr s(new DOMTokenList());
		return s;
	}

	/// <summary>
	/// Sets or returns the value of the class attribute of an element
	/// </summary>
	/// <value>
	/// The name of the class.
	/// </value>
	string Element::className() { return _elem->get_attr("class"); }
	void Element::className(string value) { _elem->set_attr("class", value.c_str()); }

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
	Node::ptr Element::cloneNode(bool deep /*= false*/) { //: Node
		return nullptr;
	}

	/// <summary>
	/// Compares the document position of two elements
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns></returns>
	int Element::compareDocumentPosition(Node::ptr node) { //: Node
		return 0;
	}

	/// <summary>
	/// Returns true if a node is a descendant of a node, otherwise false
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns>
	///   <c>true</c> if [contains] [the specified node]; otherwise, <c>false</c>.
	/// </returns>
	bool Element::contains(Node::ptr node) { return false; }

	/// <summary>
	/// Sets or returns whether the content of an element is editable or not
	/// </summary>
	/// <value>
	/// The content editable.
	/// </value>
	string Element::contentEditable() { return ""; }
	void Element::contentEditable(string value) { }

	/// <summary>
	/// Sets or returns the value of the dir attribute of an element
	/// </summary>
	/// <value>
	/// The dir.
	/// </value>
	string Element::dir() { return ""; }
	void Element::dir(string value) { }

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
	Node::ptr Element::firstChild() { return _elem->m_children.front(); } //: Node

	/// <summary>
	/// Returns the first child element of an element
	/// </summary>
	/// <value>
	/// The first element child.
	/// </value>
	Element::ptr Element::firstElementChild() {
		return !_elem->m_children.empty() ? _elem->m_children.front() : nullptr;
	}

	/// <summary>
	/// Gives focus to an element
	/// </summary>
	void Element::focus() { }

	/// <summary>
	/// Returns the specified attribute value of an element node
	/// </summary>
	/// <param name="attributename">The attributename.</param>
	/// <returns></returns>
	string Element::getAttribute(string attributename) { return _elem->get_attr(attributename.c_str()); }

	/// <summary>
	/// Returns the specified attribute node
	/// </summary>
	/// <param name="attributename">The attributename.</param>
	/// <returns></returns>
	Attr::ptr Element::getAttributeNode(string attributename) { return std::make_shared<Attr>(&dynamic_cast<html_tag*>(_elem)->m_attrs, attributename); }

	/// <summary>
	/// Returns the size of an element and its position relative to the viewport
	/// </summary>
	/// <returns></returns>
	Rect::ptr Element::getBoundingClientRect() { return nullptr; }

	/// <summary>
	/// Returns a collection of all child elements with the specified class name
	/// </summary>
	/// <param name="classname">The classname.</param>
	/// <returns></returns>
	NodeList<Element> Element::getElementsByClassName(string classnames) {
		//TODO
		//const classes = names.split(' ');
		//return this._createCollection(child = > classes.every(token = > child.classList.contains(token)));
		litehtml::lcase(classnames);
		css_element_selector elem;
		elem.m_tag = _id("*");
		css_attribute_selector attr;
		attr.type = select_class;
		attr.name = _id(classnames);
		elem.m_attrs.push_back(attr);
		css_selector sel(elem);
		return _elem->select_all(sel);
	}

	/// <summary>
	/// Returns a collection of all child elements with the specified tag name
	/// </summary>
	/// <param name="tagname">The tagname.</param>
	/// <returns></returns>
	NodeList<Element> Element::getElementsByTagName(string tagname) {
		litehtml::lcase(tagname);
		css_element_selector elem;
		elem.m_tag = _id(tagname);
		css_selector sel(elem);
		return _elem->select_all(sel);
	}

	/// <summary>
	/// Returns true if an element has the specified attribute, otherwise false
	/// </summary>
	/// <param name="attributename">The attributename.</param>
	/// <returns>
	///   <c>true</c> if the specified attributename has attribute; otherwise, <c>false</c>.
	/// </returns>
	bool Element::hasAttribute(string attributename) { return false; } //: Node

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
	string Element::id() { return getAttribute("id"); }
	void Element::id(string id) { setAttribute("id", id); }

	/// <summary>
	/// Sets or returns the content of an element
	/// </summary>
	/// <value>
	/// The inner HTML.
	/// </value>
	string Element::innerHTML() { return ""; }
	void Element::innerHTML(string value) { }

	/// <summary>
	/// Sets or returns the text content of a node and its descendants
	/// </summary>
	/// <value>
	/// The inner text.
	/// </value>
	string Element::innerText() { return ""; }
	void Element::innerText(string value) { }

	/// <summary>
	/// Inserts a HTML element at the specified position relative to the current element
	/// </summary>
	/// <param name="position">The position.</param>
	/// <param name="element">The element.</param>
	void Element::insertAdjacentElement(string position, Element* element) { }

	/// <summary>
	/// Inserts a HTML formatted text at the specified position relative to the current element
	/// </summary>
	/// <param name="position">The position.</param>
	/// <param name="text">The text.</param>
	void Element::insertAdjacentHTML(string position, string text) { }

	/// <summary>
	/// Inserts text into the specified position relative to the current element
	/// </summary>
	/// <param name="position">The position.</param>
	/// <param name="text">The text.</param>
	void Element::insertAdjacentText(string position, string text) { }

	/// <summary>
	/// Inserts a new child node before a specified, existing, child node
	/// </summary>
	/// <param name="newnode">The newnode.</param>
	/// <param name="existingnode">The existingnode.</param>
	Node::ptr Element::insertBefore(Node::ptr newnode, Node::ptr existingnode) { return nullptr; }

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
	bool Element::isDefaultNamespace(string namespaceURI) { return false; } //: Node

	/// <summary>
	/// Checks if two elements are equal
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns>
	///   <c>true</c> if [is equal node] [the specified node]; otherwise, <c>false</c>.
	/// </returns>
	bool Element::isEqualNode(Node::ptr node) { return false; } //: Node

	/// <summary>
	/// Checks if two elements are the same node
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns>
	///   <c>true</c> if [is same node] [the specified node]; otherwise, <c>false</c>.
	/// </returns>
	bool Element::isSameNode(Node::ptr node) { return false; } //: Node

	/// <summary>
	/// Sets or returns the value of the lang attribute of an element
	/// </summary>
	/// <value>
	/// The language.
	/// </value>
	string Element::lang() { return ""; }
	void Element::lang(string value) { }

	/// <summary>
	/// Returns the last child node of an element
	/// </summary>
	/// <value>
	/// The last child.
	/// </value>
	Node::ptr Element::lastChild() {
		return _elem->m_children.empty() ? nullptr : _elem->m_children.back();
	} //: Node

	/// <summary>
	/// Returns the last child element of an element
	/// </summary>
	/// <value>
	/// The last element child.
	/// </value>
	Element::ptr Element::lastElementChild() {
		return _elem->m_children.empty() ? nullptr : _elem->m_children.back();
	}

	/// <summary>
	/// Returns the local name of an element
	/// </summary>
	/// <value>
	/// The local name.
	/// </value>
	string Element::localName() { return ""; }

	/// <summary>
	/// Returns the namespace URI of an element
	/// </summary>
	/// <value>
	/// The namespace URI.
	/// </value>
	string Element::namespaceURI() { return ""; }

	/// <summary>
	/// Returns the next node at the same node tree level
	/// </summary>
	/// <value>
	/// The next sibling.
	/// </value>
	Node::ptr Element::nextSibling() { return nullptr; } //: Node

	/// <summary>
	/// Returns the next element at the same node tree level
	/// </summary>
	/// <value>
	/// The next element sibling.
	/// </value>
	Element::ptr Element::nextElementSibling() {
		auto siblings = _elem->m_parent.lock()->m_children;
		//if (siblings && siblings.size() > 1) {
		//	let index = siblings.indexOf(this);
		//	if (index + 1 < siblings.length) {
		//		return siblings[index + 1];
		//	}
		//}

		return nullptr;
	}

	/// <summary>
	/// Returns the name of a node
	/// </summary>
	/// <value>
	/// The name of the node.
	/// </value>
	string Element::nodeName() { return ""; } //: Node

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
	string Element::nodeValue() { return ""; } //: Node
	void Element::nodeValue(string value) { } //: Node

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
	Node::ptr Element::offsetParent() { return nullptr; }

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
	Document::ptr Element::ownerDocument() { return nullptr; } //: Node

	/// <summary>
	/// Returns the parent node of an element
	/// </summary>
	/// <value>
	/// The parent node.
	/// </value>
	Node::ptr Element::parentNode() { return nullptr; } //: Node

	/// <summary>
	/// Returns the parent element node of an element
	/// </summary>
	/// <value>
	/// The parent element.
	/// </value>
	Element::ptr Element::parentElement() { return nullptr; }

	/// <summary>
	/// Returns the previous node at the same node tree level
	/// </summary>
	/// <value>
	/// The previous sibling.
	/// </value>
	Node::ptr Element::previousSibling() { return nullptr; } //: Node

	/// <summary>
	/// Returns the previous element at the same node tree level
	/// </summary>
	/// <value>
	/// The previous element sibling.
	/// </value>
	Element::ptr Element::previousElementSibling() {
		auto siblings = _elem->m_parent.lock()->m_children;
		//if (siblings && siblings.length > 1) {
		//	let index = siblings.indexOf(this);
		//	if (index != = 0) {
		//		return siblings[index - 1];
		//	}
		//}

		return nullptr;
	}

	/// <summary>
	/// Returns the first child element that matches a specified CSS selector(s) of an element
	/// </summary>
	/// <param name="selectors">The selectors.</param>
	/// <returns></returns>
	Element::ptr Element::querySelector(string selectors) {
		//TODO
		//return _querySelector(this, query);
		return _elem->select_one(selectors);
	}

	/// <summary>
	/// Returns all child elements that matches a specified CSS selector(s) of an element
	/// </summary>
	/// <param name="selectors">The selectors.</param>
	/// <returns></returns>
	NodeList<Element> Element::querySelectorAll(string selectors) {
		//TODO
		//return _querySelectorAll(this, query);
		return NodeList<Element>();
	}

	/// <summary>
	/// Removes a specified attribute from an element
	/// </summary>
	/// <param name="attributename">The attributename.</param>
	void Element::removeAttribute(string attributename) { }

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
	Node::ptr Element::removeChild(Node::ptr node) { return nullptr; } //: Node

	/// <summary>
	/// Removes an event handler that has been attached with the addEventListener() method
	/// </summary>
	/// <param name="event">The event.</param>
	/// <param name="function">The function.</param>
	/// <param name="useCapture">if set to <c>true</c> [use capture].</param>
	//void Element::removeEventListener(string event, void* function, bool useCapture) { } //: EventTarget

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
	Node::ptr Element::replaceChild(Node::ptr newnode, Node::ptr oldnode) { return nullptr; } //: Node

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
	void Element::setAttribute(string attributename, string attributevalue) { _elem->set_attr(attributename.c_str(), attributevalue.c_str()); }

	/// <summary>
	/// Sets or changes the specified attribute node
	/// </summary>
	/// <param name="attributenode">The attributenode.</param>
	/// <returns></returns>
	Attr::ptr Element::setAttributeNode(Attr::ptr attributenode) { return nullptr; }

	/// <summary>
	/// Returns the value of the style attribute of an element
	/// </summary>
	/// <value>
	/// The style.
	/// </value>
	Style::ptr Element::style_() { return nullptr; }

	/// <summary>
	/// Sets or returns the value of the tabindex attribute of an element
	/// </summary>
	/// <value>
	/// The index of the tab.
	/// </value>
	string Element::tabIndex() { return "0"; }
	void Element::tabIndex(string value) { }

	/// <summary>
	/// Returns the tag name of an element
	/// </summary>
	/// <value>
	/// The name of the tag.
	/// </value>
	string Element::tagName() { return nodeName(); }

	/// <summary>
	/// Sets or returns the textual content of a node and its descendants
	/// </summary>
	/// <value>
	/// The content of the text.
	/// </value>
	string Element::textContent() { return ""; } //: Node
	void Element::textContent(string value) { } //: Node

	/// <summary>
	/// Sets or returns the value of the title attribute of an element
	/// </summary>
	/// <value>
	/// The title.
	/// </value>
	string Element::title() { return ""; }
	void Element::title(string value) { }

	/// <summary>
	/// Converts an element to a string
	/// </summary>
	string Element::toString() { return ""; }
}

/// <summary>
/// Geolocation
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Returns the position's latitude in decimal degrees
	/// </summary>
	int Geolocation::Coordinates::latitude() { return 0; }
	/// <summary>
	/// Returns the position's longitude in decimal degrees
	/// </summary>
	int Geolocation::Coordinates::longitude() { return 0; }
	/// <summary>
	/// Returns the position's altitude in meters, relative to sea level
	/// </summary>
	int Geolocation::Coordinates::altitude() { return 0; }
	/// <summary>
	/// Returns the accuracy of the latitude and longitude properties in meters
	/// </summary>
	int Geolocation::Coordinates::accuracy() { return 0; }
	/// <summary>
	/// Returns the accuracy of the altitude property in meters
	/// </summary>
	int Geolocation::Coordinates::altitudeAccuracy() { return 0; }
	/// <summary>
	/// Returns the direction in which the device is traveling. This value, specified in degrees, indicates how far off from heading true north the device is. 0 degrees represents true north, and the direction is determined clockwise (east is 90 degrees and west is 270 degrees). If speed is 0, heading is NaN. If the device is unable to provide heading information, this value is null
	/// </summary>
	int Geolocation::Coordinates::heading() { return 0; }
	/// <summary>
	/// Returns the velocity of the device in meters per second. This value can be null
	/// </summary>
	int Geolocation::Coordinates::speed() { return 0; }

	/// <summary>
	/// Returns a Coordinates object that defines the current location
	/// </summary>
	Geolocation::Coordinates::ptr Geolocation::Position::coords() { return nullptr; }
	/// <summary>
	/// Returns a DOMTimeStamp representing the time at which the location was retrieved
	/// </summary>
	int64_t Geolocation::Position::timestamp() { return 0; }

	/// <summary>
	/// Returns the position and altitude of the device on Earth
	/// </summary>
	/// <value>The coordinates.</value>
	Geolocation::Coordinates::ptr Geolocation::coordinates() { return nullptr; }

	/// <summary>
	/// Returns the position of the concerned device at a given time
	/// </summary>
	/// <value>The position.</value>
	Geolocation::Position::ptr Geolocation::position() { return nullptr; }

	/// <summary>
	/// Returns the reason of an error occurring when using the geolocating device
	/// </summary>
	/// <value>The position error.</value>
	string Geolocation::positionError() { return ""; }

	/// <summary>
	/// Describes an object containing option properties to pass as a parameter of Geolocation.getCurrentPosition() and Geolocation.watchPosition()
	/// </summary>
	/// <value>The position options.</value>
	void* Geolocation::positionOptions() { return nullptr; }

	/// <summary>
	/// Unregister location/error monitoring handlers previously installed using Geolocation.watchPosition()
	/// </summary>
	void Geolocation::clearWatch() { }

	/// <summary>
	/// Returns the current position of the device
	/// </summary>
	void Geolocation::getCurrentPosition(function<void(Position::ptr)> success, function<void(string)> error /*= nullptr*/, function<void(tany)> options /*= nullptr*/) { }

	/// <summary>
	/// Returns a watch ID value that then can be used to unregister the handler by passing it to the Geolocation.clearWatch() method
	/// </summary>
	int Geolocation::watchPosition() { return 0; }
}

/// <summary>
/// History
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Returns the number of URLs in the history list
	/// </summary>
	int History::length() { return 0; }

	/// <summary>
	/// Loads the previous URL in the history list
	/// </summary>
	void History::back() { }

	/// <summary>
	/// Loads the next URL in the history list
	/// </summary>
	/// <value>The position error.</value>
	void History::forward() { }

	/// <summary>
	/// Loads the next URL in the history list
	/// </summary>
	void History::go(int numberURL) { }
}

/// <summary>
/// HTMLCollection
/// </summary>
namespace litehtml
{
	HTMLCollection::HTMLCollection() { }
	HTMLCollection::HTMLCollection(elements_list& elements) : _elems(elements) { }

	/// <summary>
	/// Returns the number of elements in an HTMLCollection
	/// </summary>
	/// <value>
	/// The length.
	/// </value>
	int HTMLCollection::length() { return 0; }

	/// <summary>
	/// Gets the <see cref="System.Object" /> with the specified index.
	/// </summary>
	/// <value>
	/// The <see cref="System.Object" />.
	/// </value>
	/// <param name="index">The index.</param>
	/// <returns></returns>
	//Element::ptr HTMLCollection::operator[](int index);

	/// <summary>
	/// Returns the element at the specified index in an HTMLCollection
	/// </summary>
	/// <param name="index">The index.</param>
	/// <returns></returns>
	Element::ptr HTMLCollection::item(int index) {
		return nullptr;
	}

	/// <summary>
	/// Returns the element with the specified ID, or name, in an HTMLCollection
	/// </summary>
	/// <param name="name">The name.</param>
	/// <returns></returns>
	Element::ptr HTMLCollection::namedItem(string name) {
		return nullptr;
	}
}

/// <summary>
/// Location
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Sets or returns the anchor part (#) of a URL
	/// </summary>
	/// <value>
	/// The hash.
	/// </value>
	string Location::hash() { return ""; }
	void Location::hash(string value) { }

	/// <summary>
	/// Sets or returns the hostname and port number of a URL
	/// </summary>
	/// <value>
	/// The host.
	/// </value>
	string Location::host() { return ""; }
	void Location::host(string value) { }

	/// <summary>
	/// Sets or returns the hostname of a URL
	/// </summary>
	/// <value>
	/// The hostname.
	/// </value>
	string Location::hostname() { return ""; }
	void Location::hostname(string value) { }

	/// <summary>
	/// Sets or returns the entire URL
	/// </summary>
	/// <value>
	/// The href.
	/// </value>
	string Location::href() { return ""; }
	void Location::href(string value) { }

	/// <summary>
	/// Returns the protocol, hostname and port number of a URL
	/// </summary>
	/// <value>
	/// The origin.
	/// </value>
	string Location::origin() { return ""; }

	/// <summary>
	/// Sets or returns the path name of a URL
	/// </summary>
	/// <value>
	/// The pathname.
	/// </value>
	string Location::pathname() { return ""; }
	void Location::pathname(string value) { }

	/// <summary>
	/// Sets or returns the port number of a URL
	/// </summary>
	/// <value>
	/// The port.
	/// </value>
	string Location::port() { return ""; }
	void Location::port(string value) { }

	/// <summary>
	/// Sets or returns the protocol of a URL
	/// </summary>
	/// <value>
	/// The protocol.
	/// </value>
	string Location::protocol() { return ""; }
	void Location::protocol(string value) { }

	/// <summary>
	/// Sets or returns the querystring part of a URL
	/// </summary>
	/// <value>
	/// The search.
	/// </value>
	string Location::search() { return ""; }
	void Location::search(string value) { }

	/// <summary>
	/// Loads a new document
	/// </summary>
	/// <param name="URL">The URL.</param>
	void Location::assign(string URL) { }

	/// <summary>
	/// Reloads the current document
	/// </summary>
	/// <param name="forceGet">if set to <c>true</c> [force get].</param>
	void Location::reload(bool forceGet /*= false*/) { }

	/// <summary>
	/// Replaces the current document with a new one
	/// </summary>
	/// <param name="newURL">The new URL.</param>
	void Location::replace(string newURL) { }
}

/// <summary>
/// MediaQueryList
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Used to check the results of a query. Returns a boolean value: true if the document matches the media query list, otherwise false
	/// </summary>
	/// <value>
	/// The matches.
	/// </value>
	void* MediaQueryList::matches() { return nullptr; }

	/// <summary>
	/// A String, representing the serialized media query list
	/// </summary>
	/// <value>
	/// The media.
	/// </value>
	string MediaQueryList::media() { return ""; }

	/// <summary>
	/// Adds a new listener function, which is executed whenever the media query's evaluated result changes
	/// </summary>
	/// <param name="functionref">The functionref.</param>
	/// <exception cref="NotImplementedException"></exception>
	void MediaQueryList::addListener(tfunc functionref) { }

	/// <summary>
	/// Removes a previously added listener function from the media query list. Does nothing if the specified listener is not already in the list
	/// </summary>
	/// <param name="functionref">The functionref.</param>
	/// <exception cref="NotImplementedException"></exception>
	void MediaQueryList::removeListener(tfunc functionref) { }
}

/// <summary>
/// Navigator
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Returns the code name of the browser
	/// </summary>
	/// <value>
	/// The name of the application code.
	/// </value>
	string Navigator::appCodeName() { return ""; }

	/// <summary>
	/// Returns the name of the browser
	/// </summary>
	/// <value>
	/// The name of the application.
	/// </value>
	string Navigator::appName() { return ""; }

	/// <summary>
	/// Returns the version information of the browser
	/// </summary>
	/// <value>
	/// The application version.
	/// </value>
	string Navigator::appVersion() { return ""; }

	/// <summary>
	/// Determines whether cookies are enabled in the browser
	/// </summary>
	/// <value>
	///   <c>true</c> if [cookie enabled]; otherwise, <c>false</c>.
	/// </value>
	bool Navigator::cookieEnabled() { return false; }

	/// <summary>
	/// Returns a Geolocation object that can be used to locate the user's position
	/// </summary>
	/// <value>
	/// The geolocation.
	/// </value>
	Geolocation::ptr Navigator::geolocation() { return nullptr; }

	/// <summary>
	/// Returns the language of the browser
	/// </summary>
	/// <value>
	/// The language.
	/// </value>
	string Navigator::language() { return ""; }

	/// <summary>
	/// Determines whether the browser is online
	/// </summary>
	/// <value>
	///   <c>true</c> if [on line]; otherwise, <c>false</c>.
	/// </value>
	bool Navigator::onLine() { return false; }

	/// <summary>
	/// Returns for which platform the browser is compiled
	/// </summary>
	/// <value>
	/// The platform.
	/// </value>
	string Navigator::platform() { return ""; }

	/// <summary>
	/// Returns the engine name of the browser
	/// </summary>
	/// <value>
	/// The product.
	/// </value>
	string Navigator::product() { return ""; }

	/// <summary>
	/// Returns the user-agent header sent by the browser to the server
	/// </summary>
	/// <value>
	/// The user agent.
	/// </value>
	string Navigator::userAgent() { return ""; }

	/// <summary>
	/// Specifies whether or not the browser has Java enabled
	/// </summary>
	/// <returns></returns>
	bool Navigator::javaEnabled() { return false; }
}

/// <summary>
/// Screen
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Returns the height of the screen (excluding the Windows Taskbar)
	/// </summary>
	/// <value>
	/// The height of the avail.
	/// </value>
	int Screen::availHeight() { return 0; }

	/// <summary>
	/// Returns the width of the screen (excluding the Windows Taskbar)
	/// </summary>
	/// <value>
	/// The width of the avail.
	/// </value>
	int Screen::availWidth() { return 0; }

	/// <summary>
	/// Returns the bit depth of the color palette for displaying images
	/// </summary>
	/// <value>
	/// The color depth.
	/// </value>
	int Screen::colorDepth() { return 0; }

	/// <summary>
	/// Returns the total height of the screen
	/// </summary>
	/// <value>
	/// The height.
	/// </value>
	int Screen::height() { return 0; }

	/// <summary>
	/// Returns the color resolution (in bits per pixel) of the screen
	/// </summary>
	/// <value>
	/// The pixel depth.
	/// </value>
	int Screen::pixelDepth() { return 0; }

	/// <summary>
	/// Returns the total width of the screen
	/// </summary>
	/// <value>
	/// The width.
	/// </value>
	int Screen::width() { return 0; }
}

/// <summary>
/// Style
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Sets or returns the alignment between the lines inside a flexible container when the items do not use all available space
	/// </summary>
	/// <value>The content of the align.</value>
	string Style::alignContent() { return ""; }
	void Style::alignContent(string value) { }

	/// <summary>
	/// Sets or returns the alignment for items inside a flexible container
	/// </summary>
	/// <value>
	/// The align items.
	/// </value>
	string Style::alignItems() { return ""; }
	void Style::alignItems(string value) { }

	/// <summary>
	/// Sets or returns the alignment for selected items inside a flexible container
	/// </summary>
	/// <value>
	/// The align self.
	/// </value>
	string Style::alignSelf() { return ""; }
	void Style::alignSelf(string value) { }

	/// <summary>
	/// A shorthand property for all the animation properties below, except the animationPlayState property
	/// </summary>
	/// <value>
	/// The animation.
	/// </value>
	string Style::animation() { return ""; }
	void Style::animation(string value) { }

	/// <summary>
	/// Sets or returns when the animation will start
	/// </summary>
	/// <value>
	/// The animation delay.
	/// </value>
	string Style::animationDelay() { return ""; }
	void Style::animationDelay(string value) { }

	/// <summary>
	/// Sets or returns whether or not the animation should play in reverse on alternate cycles
	/// </summary>
	/// <value>
	/// The animation direction.
	/// </value>
	string Style::animationDirection() { return ""; }
	void Style::animationDirection(string value) { }

	/// <summary>
	/// Sets or returns how many seconds or milliseconds an animation takes to complete one cycle
	/// </summary>
	/// <value>
	/// The duration of the animation.
	/// </value>
	string Style::animationDuration() { return ""; }
	void Style::animationDuration(string value) { }

	/// <summary>
	/// Sets or returns what values are applied by the animation outside the time it is executing
	/// </summary>
	/// <value>
	/// The animation fill mode.
	/// </value>
	string Style::animationFillMode() { return ""; }
	void Style::animationFillMode(string value) { }

	/// <summary>
	/// Sets or returns the number of times an animation should be played
	/// </summary>
	/// <value>
	/// The animation iteration count.
	/// </value>
	string Style::animationIterationCount() { return ""; }
	void Style::animationIterationCount(string value) { }

	/// <summary>
	/// Sets or returns a name for the @keyframes animation
	/// </summary>
	/// <value>
	/// The name of the animation.
	/// </value>
	string Style::animationName() { return ""; }
	void Style::animationName(string value) { }

	/// <summary>
	/// Sets or returns the speed curve of the animation
	/// </summary>
	/// <value>
	/// The animation timing function.
	/// </value>
	string Style::animationTimingFunction() { return ""; }
	void Style::animationTimingFunction(string value) { }

	/// <summary>
	/// Sets or returns whether the animation is running or paused
	/// </summary>
	/// <value>
	/// The state of the animation play.
	/// </value>
	string Style::animationPlayState() { return ""; }
	void Style::animationPlayState(string value) { }

	/// <summary>
	/// Sets or returns all the background properties in one declaration
	/// </summary>
	/// <value>
	/// The background.
	/// </value>
	string Style::background() { return ""; }
	void Style::background(string value) { }

	/// <summary>
	/// Sets or returns whether a background-image is fixed or scrolls with the page
	/// </summary>
	/// <value>
	/// The background attachment.
	/// </value>
	string Style::backgroundAttachment() { return ""; }
	void Style::backgroundAttachment(string value) { }

	/// <summary>
	/// Sets or returns the background-color of an element
	/// </summary>
	/// <value>
	/// The color of the background.
	/// </value>
	string Style::backgroundColor() { return ""; }
	void Style::backgroundColor(string value) { }

	/// <summary>
	/// Sets or returns the background-image for an element
	/// </summary>
	/// <value>
	/// The background image.
	/// </value>
	string Style::backgroundImage() { return ""; }
	void Style::backgroundImage(string value) { }

	/// <summary>
	/// Sets or returns the starting position of a background-image
	/// </summary>
	/// <value>
	/// The background position.
	/// </value>
	string Style::backgroundPosition() { return ""; }
	void Style::backgroundPosition(string value) { }

	/// <summary>
	/// Sets or returns how to repeat (tile) a background-image
	/// </summary>
	/// <value>
	/// The background repeat.
	/// </value>
	string Style::backgroundRepeat() { return ""; }
	void Style::backgroundRepeat(string value) { }

	/// <summary>
	/// Sets or returns the painting area of the background
	/// </summary>
	/// <value>
	/// The background clip.
	/// </value>
	string Style::backgroundClip() { return ""; }
	void Style::backgroundClip(string value) { }

	/// <summary>
	/// Sets or returns the positioning area of the background images
	/// </summary>
	/// <value>
	/// The background origin.
	/// </value>
	string Style::backgroundOrigin() { return ""; }
	void Style::backgroundOrigin(string value) { }

	/// <summary>
	/// Sets or returns the size of the background image
	/// </summary>
	/// <value>
	/// The size of the background.
	/// </value>
	string Style::backgroundSize() { return ""; }
	void Style::backgroundSize(string value) { }

	/// <summary>
	/// Sets or returns whether or not an element should be visible when not facing the screen
	/// </summary>
	/// <value>
	/// The backface visibility.
	/// </value>
	string Style::backfaceVisibility() { return ""; }
	void Style::backfaceVisibility(string value) { }

	/// <summary>
	/// Sets or returns borderWidth, borderStyle, and borderColor in one declaration
	/// </summary>
	/// <value>
	/// The border.
	/// </value>
	string Style::border() { return ""; }
	void Style::border(string value) { }

	/// <summary>
	/// Sets or returns all the borderBottom properties in one declaration
	/// </summary>
	/// <value>
	/// The border bottom.
	/// </value>
	string Style::borderBottom() { return ""; }
	void Style::borderBottom(string value) { }

	/// <summary>
	/// Sets or returns the color of the bottom border
	/// </summary>
	/// <value>
	/// The border bottom.
	/// </value>
	string Style::borderBottomColor() { return ""; }
	void Style::borderBottomColor(string value) { }

	/// <summary>
	/// Sets or returns the shape of the border of the bottom-left corner
	/// </summary>
	/// <value>
	/// The border bottom.
	/// </value>
	string Style::borderBottomLeftRadius() { return ""; }
	void Style::borderBottomLeftRadius(string value) { }

	/// <summary>
	/// Sets or returns the shape of the border of the bottom-right corner
	/// </summary>
	/// <value>
	/// The border bottom.
	/// </value>
	string Style::borderBottomRightRadius() { return ""; }
	void Style::borderBottomRightRadius(string value) { }

	/// <summary>
	/// Sets or returns the style of the bottom border
	/// </summary>
	/// <value>
	/// The border bottom.
	/// </value>
	string Style::borderBottomStyle() { return ""; }
	void Style::borderBottomStyle(string value) { }

	/// <summary>
	/// Sets or returns the width of the bottom border
	/// </summary>
	/// <value>
	/// The border bottom.
	/// </value>
	string Style::borderBottomWidth() { return ""; }
	void Style::borderBottomWidth(string value) { }

	/// <summary>
	/// Sets or returns whether the table border should be collapsed into a single border, or not
	/// </summary>
	/// <value>
	/// The border collapse.
	/// </value>
	string Style::borderCollapse() { return ""; }
	void Style::borderCollapse(string value) { }

	/// <summary>
	/// Sets or returns the color of an element's border (can have up to four values)
	/// </summary>
	/// <value>
	/// The color of the border.
	/// </value>
	string Style::borderColor() { return ""; }
	void Style::borderColor(string value) { }

	/// <summary>
	/// A shorthand property for setting or returning all the borderImage properties
	/// </summary>
	/// <value>
	/// The border image.
	/// </value>
	string Style::borderImage() { return ""; }
	void Style::borderImage(string value) { }

	/// <summary>
	/// Sets or returns the amount by which the border image area extends beyond the border box
	/// </summary>
	/// <value>
	/// The border image outset.
	/// </value>
	string Style::borderImageOutset() { return ""; }
	void Style::borderImageOutset(string value) { }

	/// <summary>
	/// Sets or returns whether the image-border should be repeated, rounded or stretched
	/// </summary>
	/// <value>
	/// The border image repeat.
	/// </value>
	string Style::borderImageRepeat() { return ""; }
	void Style::borderImageRepeat(string value) { }

	/// <summary>
	/// Sets or returns the inward offsets of the image-border
	/// </summary>
	/// <value>
	/// The border image slice.
	/// </value>
	string Style::borderImageSlice() { return ""; }
	void Style::borderImageSlice(string value) { }

	/// <summary>
	/// Sets or returns the image to be used as a border
	/// </summary>
	/// <value>
	/// The border image source.
	/// </value>
	string Style::borderImageSource() { return ""; }
	void Style::borderImageSource(string value) { }

	/// <summary>
	/// Sets or returns the widths of the image-border
	/// </summary>
	/// <value>
	/// The width of the border image.
	/// </value>
	string Style::borderImageWidth() { return ""; }
	void Style::borderImageWidth(string value) { }

	/// <summary>
	/// Sets or returns all the borderLeft properties in one declaration
	/// </summary>
	/// <value>
	/// The border left.
	/// </value>
	string Style::borderLeft() { return ""; }
	void Style::borderLeft(string value) { }

	/// <summary>
	/// Sets or returns the color of the left border
	/// </summary>
	/// <value>
	/// The color of the border left.
	/// </value>
	string Style::borderLeftColor() { return ""; }
	void Style::borderLeftColor(string value) { }

	/// <summary>
	/// Sets or returns the style of the left border
	/// </summary>
	/// <value>
	/// The border left style.
	/// </value>
	string Style::borderLeftStyle() { return ""; }
	void Style::borderLeftStyle(string value) { }

	/// <summary>
	/// Sets or returns the width of the left border
	/// </summary>
	/// <value>
	/// The width of the border left.
	/// </value>
	string Style::borderLeftWidth() { return ""; }
	void Style::borderLeftWidth(string value) { }

	/// <summary>
	/// A shorthand property for setting or returning all the four borderRadius properties
	/// </summary>
	/// <value>
	/// The border radius.
	/// </value>
	string Style::borderRadius() { return ""; }
	void Style::borderRadius(string value) { }

	/// <summary>
	/// Sets or returns all the borderRight properties in one declaration
	/// </summary>
	/// <value>
	/// The border right.
	/// </value>
	string Style::borderRight() { return ""; }
	void Style::borderRight(string value) { }

	/// <summary>
	/// Sets or returns the color of the right border
	/// </summary>
	/// <value>
	/// The color of the border right.
	/// </value>
	string Style::borderRightColor() { return ""; }
	void Style::borderRightColor(string value) { }

	/// <summary>
	/// Sets or returns the style of the right border
	/// </summary>
	/// <value>
	/// The border right style.
	/// </value>
	string Style::borderRightStyle() { return ""; }
	void Style::borderRightStyle(string value) { }

	/// <summary>
	/// Sets or returns the width of the right border
	/// </summary>
	/// <value>
	/// The width of the border right.
	/// </value>
	string Style::borderRightWidth() { return ""; }
	void Style::borderRightWidth(string value) { }

	/// <summary>
	/// Sets or returns the space between cells in a table
	/// </summary>
	/// <value>
	/// The border spacing.
	/// </value>
	string Style::borderSpacing() { return ""; }
	void Style::borderSpacing(string value) { }

	/// <summary>
	/// Sets or returns the style of an element's border (can have up to four values)
	/// </summary>
	/// <value>
	/// The border style.
	/// </value>
	string Style::borderStyle() { return ""; }
	void Style::borderStyle(string value) { }

	/// <summary>
	/// Sets or returns all the borderTop properties in one declaration
	/// </summary>
	/// <value>
	/// The border top.
	/// </value>
	string Style::borderTop() { return ""; }
	void Style::borderTop(string value) { }

	/// <summary>
	/// Sets or returns the color of the top border
	/// </summary>
	/// <value>
	/// The color of the border top.
	/// </value>
	string Style::borderTopColor() { return ""; }
	void Style::borderTopColor(string value) { }

	/// <summary>
	/// Sets or returns the shape of the border of the top-left corner
	/// </summary>
	/// <value>
	/// The border top left radius.
	/// </value>
	string Style::borderTopLeftRadius() { return ""; }
	void Style::borderTopLeftRadius(string value) { }

	/// <summary>
	/// Sets or returns the shape of the border of the top-right corner
	/// </summary>
	/// <value>
	/// The border top right radius.
	/// </value>
	string Style::borderTopRightRadius() { return ""; }
	void Style::borderTopRightRadius(string value) { }

	/// <summary>
	/// Sets or returns the style of the top border
	/// </summary>
	/// <value>
	/// The border top style.
	/// </value>
	string Style::borderTopStyle() { return ""; }
	void Style::borderTopStyle(string value) { }

	/// <summary>
	/// Sets or returns the width of the top border
	/// </summary>
	/// <value>
	/// The width of the border top.
	/// </value>
	string Style::borderTopWidth() { return ""; }
	void Style::borderTopWidth(string value) { }

	/// <summary>
	/// Sets or returns the width of an element's border (can have up to four values)
	/// </summary>
	/// <value>
	/// The width of the border.
	/// </value>
	string Style::borderWidth() { return ""; }
	void Style::borderWidth(string value) { }

	/// <summary>
	/// Sets or returns the bottom position of a positioned element
	/// </summary>
	/// <value>
	/// The bottom.
	/// </value>
	string Style::bottom() { return ""; }
	void Style::bottom(string value) { }

	/// <summary>
	/// Sets or returns the behaviour of the background and border of an element at page-break, or, for in-line elements, at line-break.
	/// </summary>
	/// <value>
	/// The box decoration break.
	/// </value>
	string Style::boxDecorationBreak() { return ""; }
	void Style::boxDecorationBreak(string value) { }

	/// <summary>
	/// Attaches one or more drop-shadows to the box
	/// </summary>
	/// <value>
	/// The box shadow.
	/// </value>
	string Style::boxShadow() { return ""; }
	void Style::boxShadow(string value) { }

	/// <summary>
	/// Allows you to define certain elements to fit an area in a certain way
	/// </summary>
	/// <value>
	/// The box sizing.
	/// </value>
	string Style::boxSizing() { return ""; }
	void Style::boxSizing(string value) { }

	/// <summary>
	/// Sets or returns the position of the table caption
	/// </summary>
	/// <value>
	/// The caption side.
	/// </value>
	string Style::captionSide() { return ""; }
	void Style::captionSide(string value) { }

	/// <summary>
	/// Sets or returns the position of the element relative to floating objects
	/// </summary>
	/// <value>
	/// The clear.
	/// </value>
	string Style::clear() { return ""; }
	void Style::clear(string value) { }

	/// <summary>
	/// Sets or returns which part of a positioned element is visible
	/// </summary>
	/// <value>
	/// The clip.
	/// </value>
	string Style::clip() { return ""; }
	void Style::clip(string value) { }

	/// <summary>
	/// Sets or returns the color of the text
	/// </summary>
	/// <value>
	/// The color.
	/// </value>
	string Style::color() { return ""; }
	void Style::color(string value) { }

	/// <summary>
	/// Sets or returns the number of columns an element should be divided into
	/// </summary>
	/// <value>
	/// The column count.
	/// </value>
	string Style::columnCount() { return ""; }
	void Style::columnCount(string value) { }

	/// <summary>
	/// Sets or returns how to fill columns
	/// </summary>
	/// <value>
	/// The column fill.
	/// </value>
	string Style::columnFill() { return ""; }
	void Style::columnFill(string value) { }

	/// <summary>
	/// Sets or returns the gap between the columns
	/// </summary>
	/// <value>
	/// The column gap.
	/// </value>
	string Style::columnGap() { return ""; }
	void Style::columnGap(string value) { }

	/// <summary>
	/// A shorthand property for setting or returning all the columnRule properties
	/// </summary>
	/// <value>
	/// The column rule.
	/// </value>
	string Style::columnRule() { return ""; }
	void Style::columnRule(string value) { }

	/// <summary>
	/// Sets or returns the color of the rule between columns
	/// </summary>
	/// <value>
	/// The color of the column rule.
	/// </value>
	string Style::columnRuleColor() { return ""; }
	void Style::columnRuleColor(string value) { }

	/// <summary>
	/// Sets or returns the style of the rule between columns
	/// </summary>
	/// <value>
	/// The column rule style.
	/// </value>
	string Style::columnRuleStyle() { return ""; }
	void Style::columnRuleStyle(string value) { }

	/// <summary>
	/// Sets or returns the width of the rule between columns
	/// </summary>
	/// <value>
	/// The width of the column rule.
	/// </value>
	string Style::columnRuleWidth() { return ""; }
	void Style::columnRuleWidth(string value) { }

	/// <summary>
	/// A shorthand property for setting or returning columnWidth and columnCount
	/// </summary>
	/// <value>
	/// The columns.
	/// </value>
	string Style::columns() { return ""; }
	void Style::columns(string value) { }

	/// <summary>
	/// Sets or returns how many columns an element should span across
	/// </summary>
	/// <value>
	/// The column span.
	/// </value>
	string Style::columnSpan() { return ""; }
	void Style::columnSpan(string value) { }

	/// <summary>
	/// Sets or returns the width of the columns
	/// </summary>
	/// <value>
	/// The width of the column.
	/// </value>
	string Style::columnWidth() { return ""; }
	void Style::columnWidth(string value) { }

	/// <summary>
	/// Used with the :before and :after pseudo-elements, to insert generated content
	/// </summary>
	/// <value>
	/// The content.
	/// </value>
	string Style::content() { return ""; }
	void Style::content(string value) { }

	/// <summary>
	/// Increments one or more counters
	/// </summary>
	/// <value>
	/// The counter increment.
	/// </value>
	string Style::counterIncrement() { return ""; }
	void Style::counterIncrement(string value) { }

	/// <summary>
	/// Creates or resets one or more counters
	/// </summary>
	/// <value>
	/// The counter reset.
	/// </value>
	string Style::counterReset() { return ""; }
	void Style::counterReset(string value) { }

	/// <summary>
	/// Sets or returns the type of cursor to display for the mouse pointer
	/// </summary>
	/// <value>
	/// The cursor.
	/// </value>
	string Style::cursor() { return ""; }
	void Style::cursor(string value) { }

	/// <summary>
	/// Sets or returns the text direction
	/// </summary>
	/// <value>
	/// The direction.
	/// </value>
	string Style::direction() { return ""; }
	void Style::direction(string value) { }

	/// <summary>
	/// Sets or returns an element's display type
	/// </summary>
	/// <value>
	/// The display.
	/// </value>
	string Style::display() { return ""; }
	void Style::display(string value) { }

	/// <summary>
	/// Sets or returns whether to show the border and background of empty cells, or not
	/// </summary>
	/// <value>
	/// The empty cells.
	/// </value>
	string Style::emptyCells() { return ""; }
	void Style::emptyCells(string value) { }

	/// <summary>
	/// Sets or returns image filters (visual effects, like blur and saturation)
	/// </summary>
	/// <value>
	/// The filter.
	/// </value>
	string Style::filter() { return ""; }
	void Style::filter(string value) { }

	/// <summary>
	/// Sets or returns the length of the item, relative to the rest
	/// </summary>
	/// <value>
	/// The flex.
	/// </value>
	string Style::flex() { return ""; }
	void Style::flex(string value) { }

	/// <summary>
	/// Sets or returns the initial length of a flexible item
	/// </summary>
	/// <value>
	/// The flex basis.
	/// </value>
	string Style::flexBasis() { return ""; }
	void Style::flexBasis(string value) { }

	/// <summary>
	/// Sets or returns the direction of the flexible items
	/// </summary>
	/// <value>
	/// The flex direction.
	/// </value>
	string Style::flexDirection() { return ""; }
	void Style::flexDirection(string value) { }

	/// <summary>
	/// A shorthand property for the flexDirection and the flexWrap properties
	/// </summary>
	/// <value>
	/// The flex flow.
	/// </value>
	string Style::flexFlow() { return ""; }
	void Style::flexFlow(string value) { }

	/// <summary>
	/// Sets or returns how much the item will grow relative to the rest
	/// </summary>
	/// <value>
	/// The flex grow.
	/// </value>
	string Style::flexGrow() { return ""; }
	void Style::flexGrow(string value) { }

	/// <summary>
	/// Sets or returns how the item will shrink relative to the rest
	/// </summary>
	/// <value>
	/// The flex shrink.
	/// </value>
	string Style::flexShrink() { return ""; }
	void Style::flexShrink(string value) { }

	/// <summary>
	/// Sets or returns whether the flexible items should wrap or not
	/// </summary>
	/// <value>
	/// The flex wrap.
	/// </value>
	string Style::flexWrap() { return ""; }
	void Style::flexWrap(string value) { }

	/// <summary>
	/// Sets or returns the horizontal alignment of an element
	/// </summary>
	/// <value>
	/// The CSS float.
	/// </value>
	string Style::cssFloat() { return ""; }
	void Style::cssFloat(string value) { }

	/// <summary>
	/// Sets or returns fontStyle, fontVariant, fontWeight, fontSize, lineHeight, and fontFamily in one declaration
	/// </summary>
	/// <value>
	/// The font.
	/// </value>
	string Style::font() { return ""; }
	void Style::font(string value) { }

	/// <summary>
	/// Sets or returns the font family for text
	/// </summary>
	/// <value>
	/// The font family.
	/// </value>
	string Style::fontFamily() { return ""; }
	void Style::fontFamily(string value) { }

	/// <summary>
	/// Sets or returns the font size of the text
	/// </summary>
	/// <value>
	/// The size of the font.
	/// </value>
	string Style::fontSize() { return ""; }
	void Style::fontSize(string value) { }

	/// <summary>
	/// Sets or returns whether the style of the font is normal, italic or oblique
	/// </summary>
	/// <value>
	/// The font style.
	/// </value>
	string Style::fontStyle() { return ""; }
	void Style::fontStyle(string value) { }

	/// <summary>
	/// Sets or returns whether the font should be displayed in small capital letters
	/// </summary>
	/// <value>
	/// The font variant.
	/// </value>
	string Style::fontVariant() { return ""; }
	void Style::fontVariant(string value) { }

	/// <summary>
	/// Sets or returns the boldness of the font
	/// </summary>
	/// <value>
	/// The font weight.
	/// </value>
	string Style::fontWeight() { return ""; }
	void Style::fontWeight(string value) { }

	/// <summary>
	/// Preserves the readability of text when font fallback occurs
	/// </summary>
	/// <value>
	/// The font size adjust.
	/// </value>
	string Style::fontSizeAdjust() { return ""; }
	void Style::fontSizeAdjust(string value) { }

	/// <summary>
	/// Selects a normal, condensed, or expanded face from a font family
	/// </summary>
	/// <value>
	/// The font stretch.
	/// </value>
	string Style::fontStretch() { return ""; }
	void Style::fontStretch(string value) { }

	/// <summary>
	/// Specifies whether a punctuation character may be placed outside the line box
	/// </summary>
	/// <value>
	/// The hanging punctuation.
	/// </value>
	string Style::hangingPunctuation() { return ""; }
	void Style::hangingPunctuation(string value) { }

	/// <summary>
	/// Sets or returns the height of an element
	/// </summary>
	/// <value>
	/// The height.
	/// </value>
	string Style::height() { return ""; }
	void Style::height(string value) { }

	/// <summary>
	/// Sets how to split words to improve the layout of paragraphs
	/// </summary>
	/// <value>
	/// The hyphens.
	/// </value>
	string Style::hyphens() { return ""; }
	void Style::hyphens(string value) { }

	/// <summary>
	/// Provides the author the ability to style an element with an iconic equivalent
	/// </summary>
	/// <value>
	/// The icon.
	/// </value>
	string Style::icon() { return ""; }
	void Style::icon(string value) { }

	/// <summary>
	/// Specifies a rotation in the right or clockwise direction that a user agent applies to an image
	/// </summary>
	/// <value>
	/// The image orientation.
	/// </value>
	string Style::imageOrientation() { return ""; }
	void Style::imageOrientation(string value) { }

	/// <summary>
	/// Defines whether an element must create a new stacking content
	/// </summary>
	/// <value>
	/// The isolation.
	/// </value>
	string Style::isolation() { return ""; }
	void Style::isolation(string value) { }

	/// <summary>
	/// Sets or returns the alignment between the items inside a flexible container when the items do not use all available space.
	/// </summary>
	/// <value>
	/// The content of the justify.
	/// </value>
	string justifyContent() { return ""; }
	void justifyContent(string value) { }

	/// <summary>
	/// Sets or returns the left position of a positioned element
	/// </summary>
	/// <value>
	/// The left.
	/// </value>
	string Style::left() { return ""; }
	void Style::left(string value) { }

	/// <summary>
	/// Sets or returns the space between characters in a text
	/// </summary>
	/// <value>
	/// The letter spacing.
	/// </value>
	string Style::letterSpacing() { return ""; }
	void Style::letterSpacing(string value) { }

	/// <summary>
	/// Sets or returns the distance between lines in a text
	/// </summary>
	/// <value>
	/// The height of the line.
	/// </value>
	string Style::lineHeight() { return ""; }
	void Style::lineHeight(string value) { }

	/// <summary>
	/// Sets or returns listStyleImage, listStylePosition, and listStyleType in one declaration
	/// </summary>
	/// <value>
	/// The list style.
	/// </value>
	string Style::listStyle() { return ""; }
	void Style::listStyle(string value) { }

	/// <summary>
	/// Sets or returns an image as the list-item marker
	/// </summary>
	/// <value>
	/// The list style image.
	/// </value>
	string Style::listStyleImage() { return ""; }
	void Style::listStyleImage(string value) { }

	/// <summary>
	/// Sets or returns the position of the list-item marker
	/// </summary>
	/// <value>
	/// The list style position.
	/// </value>
	string Style::listStylePosition() { return ""; }
	void Style::listStylePosition(string value) { }

	/// <summary>
	/// Sets or returns the list-item marker type
	/// </summary>
	/// <value>
	/// The type of the list style.
	/// </value>
	string Style::listStyleType() { return ""; }
	void Style::listStyleType(string value) { }

	/// <summary>
	/// Sets or returns the margins of an element (can have up to four values)
	/// </summary>
	/// <value>
	/// The margin.
	/// </value>
	string Style::margin() { return ""; }
	void Style::margin(string value) { }

	/// <summary>
	/// Sets or returns the bottom margin of an element
	/// </summary>
	/// <value>
	/// The margin bottom.
	/// </value>
	string Style::marginBottom() { return ""; }
	void Style::marginBottom(string value) { }

	/// <summary>
	/// Sets or returns the left margin of an element
	/// </summary>
	/// <value>
	/// The margin left.
	/// </value>
	string Style::marginLeft() { return ""; }
	void Style::marginLeft(string value) { }

	/// <summary>
	/// Sets or returns the right margin of an element
	/// </summary>
	/// <value>
	/// The margin right.
	/// </value>
	string Style::marginRight() { return ""; }
	void Style::marginRight(string value) { }

	/// <summary>
	/// Sets or returns the top margin of an element
	/// </summary>
	/// <value>
	/// The margin top.
	/// </value>
	string Style::marginTop() { return ""; }
	void Style::marginTop(string value) { }

	/// <summary>
	/// Sets or returns the maximum height of an element
	/// </summary>
	/// <value>
	/// The maximum height.
	/// </value>
	string Style::maxHeight() { return ""; }
	void Style::maxHeight(string value) { }

	/// <summary>
	/// Sets or returns the maximum width of an element
	/// </summary>
	/// <value>
	/// The maximum width.
	/// </value>
	string Style::maxWidth() { return ""; }
	void Style::maxWidth(string value) { }

	/// <summary>
	/// Sets or returns the minimum height of an element
	/// </summary>
	/// <value>
	/// The minimum height.
	/// </value>
	string Style::minHeight() { return ""; }
	void Style::minHeight(string value) { }

	/// <summary>
	/// Sets or returns the minimum width of an element
	/// </summary>
	/// <value>
	/// The minimum width.
	/// </value>
	string Style::minWidth() { return ""; }
	void Style::minWidth(string value) { }

	/// <summary>
	/// Sets or returns where to navigate when using the arrow-down navigation key
	/// </summary>
	/// <value>
	/// The nav down.
	/// </value>
	string Style::navDown() { return ""; }
	void Style::navDown(string value) { }

	/// <summary>
	/// Sets or returns the tabbing order for an element
	/// </summary>
	/// <value>
	/// The index of the nav.
	/// </value>
	string Style::navIndex() { return ""; }
	void Style::navIndex(string value) { }

	/// <summary>
	/// Sets or returns where to navigate when using the arrow-left navigation key
	/// </summary>
	/// <value>
	/// The nav left.
	/// </value>
	string Style::navLeft() { return ""; }
	void Style::navLeft(string value) { }

	/// <summary>
	/// Sets or returns where to navigate when using the arrow-right navigation key
	/// </summary>
	/// <value>
	/// The nav right.
	/// </value>
	string Style::navRight() { return ""; }
	void Style::navRight(string value) { }

	/// <summary>
	/// Sets or returns where to navigate when using the arrow-up navigation key
	/// </summary>
	/// <value>
	/// The nav up.
	/// </value>
	string Style::navUp() { return ""; }
	void Style::navUp(string value) { }

	/// <summary>
	/// Specifies how the contents of a replaced element should be fitted to the box established by its used height and width
	/// </summary>
	/// <value>
	/// The object fit.
	/// </value>
	string Style::objectFit() { return ""; }
	void Style::objectFit(string value) { }

	/// <summary>
	/// Specifies the alignment of the replaced element inside its box
	/// </summary>
	/// <value>
	/// The object position.
	/// </value>
	string Style::objectPosition() { return ""; }
	void Style::objectPosition(string value) { }

	/// <summary>
	/// Sets or returns the opacity level for an element
	/// </summary>
	/// <value>
	/// The opacity.
	/// </value>
	string Style::opacity() { return ""; }
	void Style::opacity(string value) { }

	/// <summary>
	/// Sets or returns the order of the flexible item, relative to the rest
	/// </summary>
	/// <value>
	/// The order.
	/// </value>
	string Style::order() { return ""; }
	void Style::order(string value) { }

	/// <summary>
	/// Sets or returns the minimum number of lines for an element that must be left at the bottom of a page when a page break occurs inside an element
	/// </summary>
	/// <value>
	/// The orphans.
	/// </value>
	string Style::orphans() { return ""; }
	void Style::orphans(string value) { }

	/// <summary>
	/// Sets or returns all the outline properties in one declaration
	/// </summary>
	/// <value>
	/// The outline.
	/// </value>
	string Style::outline() { return ""; }
	void Style::outline(string value) { }

	/// <summary>
	/// Sets or returns the color of the outline around a element
	/// </summary>
	/// <value>
	/// The color of the outline.
	/// </value>
	string Style::outlineColor() { return ""; }
	void Style::outlineColor(string value) { }

	/// <summary>
	/// Offsets an outline, and draws it beyond the border edge
	/// </summary>
	/// <value>
	/// The outline offset.
	/// </value>
	string Style::outlineOffset() { return ""; }
	void Style::outlineOffset(string value) { }

	/// <summary>
	/// Sets or returns the style of the outline around an element
	/// </summary>
	/// <value>
	/// The outline style.
	/// </value>
	string Style::outlineStyle() { return ""; }
	void Style::outlineStyle(string value) { }

	/// <summary>
	/// Sets or returns the width of the outline around an element
	/// </summary>
	/// <value>
	/// The width of the outline.
	/// </value>
	string Style::outlineWidth() { return ""; }
	void Style::outlineWidth(string value) { }

	/// <summary>
	/// Sets or returns what to do with content that renders outside the element box
	/// </summary>
	/// <value>
	/// The overflow.
	/// </value>
	string Style::overflow() { return ""; }
	void Style::overflow(string value) { }

	/// <summary>
	/// Specifies what to do with the left/right edges of the content, if it overflows the element's content area
	/// </summary>
	/// <value>
	/// The overflow x.
	/// </value>
	string Style::overflowX() { return ""; }
	void Style::overflowX(string value) { }

	/// <summary>
	/// Specifies what to do with the top/bottom edges of the content, if it overflows the element's content area
	/// </summary>
	/// <value>
	/// The overflow y.
	/// </value>
	string Style::overflowY() { return ""; }
	void Style::overflowY(string value) { }

	/// <summary>
	/// Sets or returns the padding of an element (can have up to four values)
	/// </summary>
	/// <value>
	/// The padding.
	/// </value>
	string Style::padding() { return ""; }
	void Style::padding(string value) { }

	/// <summary>
	/// Sets or returns the bottom padding of an element
	/// </summary>
	/// <value>
	/// The padding bottom.
	/// </value>
	string Style::paddingBottom() { return ""; }
	void Style::paddingBottom(string value) { }

	/// <summary>
	/// Sets or returns the left padding of an element
	/// </summary>
	/// <value>
	/// The padding left.
	/// </value>
	string Style::paddingLeft() { return ""; }
	void Style::paddingLeft(string value) { }

	/// <summary>
	/// Sets or returns the right padding of an element
	/// </summary>
	/// <value>
	/// The padding right.
	/// </value>
	string Style::paddingRight() { return ""; }
	void Style::paddingRight(string value) { }

	/// <summary>
	/// Sets or returns the top padding of an element
	/// </summary>
	/// <value>
	/// The padding top.
	/// </value>
	string Style::paddingTop() { return ""; }
	void Style::paddingTop(string value) { }

	/// <summary>
	/// Sets or returns the page-break behavior after an element
	/// </summary>
	/// <value>
	/// The page break after.
	/// </value>
	string Style::pageBreakAfter() { return ""; }
	void Style::pageBreakAfter(string value) { }

	/// <summary>
	/// Sets or returns the page-break behavior before an element
	/// </summary>
	/// <value>
	/// The page break before.
	/// </value>
	string Style::pageBreakBefore() { return ""; }
	void Style::pageBreakBefore(string value) { }

	/// <summary>
	/// Sets or returns the page-break behavior inside an element
	/// </summary>
	/// <value>
	/// The page break inside.
	/// </value>
	string Style::pageBreakInside() { return ""; }
	void Style::pageBreakInside(string value) { }

	/// <summary>
	/// Sets or returns the perspective on how 3D elements are viewed
	/// </summary>
	/// <value>
	/// The perspective.
	/// </value>
	string Style::perspective() { return ""; }
	void Style::perspective(string value) { }

	/// <summary>
	/// Sets or returns the bottom position of 3D elements
	/// </summary>
	/// <value>
	/// The perspective origin.
	/// </value>
	string Style::perspectiveOrigin() { return ""; }
	void Style::perspectiveOrigin(string value) { }

	/// <summary>
	/// Sets or returns the type of positioning method used for an element (static, relative, absolute or fixed)
	/// </summary>
	/// <value>
	/// The position.
	/// </value>
	string Style::position() { return ""; }
	void Style::position(string value) { }

	/// <summary>
	/// Sets or returns the type of quotation marks for embedded quotations
	/// </summary>
	/// <value>
	/// The quotes.
	/// </value>
	string Style::quotes() { return ""; }
	void Style::quotes(string value) { }

	/// <summary>
	/// Sets or returns whether or not an element is resizable by the user
	/// </summary>
	/// <value>
	/// The resize.
	/// </value>
	string Style::resize() { return ""; }
	void Style::resize(string value) { }

	/// <summary>
	/// Sets or returns the right position of a positioned element
	/// </summary>
	/// <value>
	/// The right.
	/// </value>
	string Style::right() { return ""; }
	void Style::right(string value) { }

	/// <summary>
	/// Sets or returns the way to lay out table cells, rows, and columns
	/// </summary>
	/// <value>
	/// The table layout.
	/// </value>
	string Style::tableLayout() { return ""; }
	void Style::tableLayout(string value) { }

	/// <summary>
	/// Sets or returns the length of the tab-character
	/// </summary>
	/// <value>
	/// The size of the tab.
	/// </value>
	string Style::tabSize() { return ""; }
	void Style::tabSize(string value) { }

	/// <summary>
	/// Sets or returns the horizontal alignment of text
	/// </summary>
	/// <value>
	/// The text align.
	/// </value>
	string Style::textAlign() { return ""; }
	void Style::textAlign(string value) { }

	/// <summary>
	/// Sets or returns how the last line of a block or a line right before a forced line break is aligned when text-align is "justify"
	/// </summary>
	/// <value>
	/// The text align last.
	/// </value>
	string Style::textAlignLast() { return ""; }
	void Style::textAlignLast(string value) { }

	/// <summary>
	/// Sets or returns the decoration of a text
	/// </summary>
	/// <value>
	/// The text decoration.
	/// </value>
	string Style::textDecoration() { return ""; }
	void Style::textDecoration(string value) { }

	/// <summary>
	/// Sets or returns the color of the text-decoration
	/// </summary>
	/// <value>
	/// The color of the text decoration.
	/// </value>
	string Style::textDecorationColor() { return ""; }
	void Style::textDecorationColor(string value) { }

	/// <summary>
	/// Sets or returns the type of line in a text-decoration
	/// </summary>
	/// <value>
	/// The text decoration line.
	/// </value>
	string Style::textDecorationLine() { return ""; }
	void Style::textDecorationLine(string value) { }

	/// <summary>
	/// Sets or returns the style of the line in a text decoration
	/// </summary>
	/// <value>
	/// The text decoration style.
	/// </value>
	string Style::textDecorationStyle() { return ""; }
	void Style::textDecorationStyle(string value) { }

	/// <summary>
	/// Sets or returns the indentation of the first line of text
	/// </summary>
	/// <value>
	/// The text indent.
	/// </value>
	string Style::textIndent() { return ""; }
	void Style::textIndent(string value) { }

	/// <summary>
	/// Sets or returns the justification method used when text-align is "justify"
	/// </summary>
	/// <value>
	/// The text justify.
	/// </value>
	string Style::textJustify() { return ""; }
	void Style::textJustify(string value) { }

	/// <summary>
	/// Sets or returns what should happen when text overflows the containing element
	/// </summary>
	/// <value>
	/// The text overflow.
	/// </value>
	string Style::textOverflow() { return ""; }
	void Style::textOverflow(string value) { }

	/// <summary>
	/// Sets or returns the shadow effect of a text
	/// </summary>
	/// <value>
	/// The text shadow.
	/// </value>
	string Style::textShadow() { return ""; }
	void Style::textShadow(string value) { }

	/// <summary>
	/// Sets or returns the capitalization of a text
	/// </summary>
	/// <value>
	/// The text transform.
	/// </value>
	string Style::textTransform() { return ""; }
	void Style::textTransform(string value) { }

	/// <summary>
	/// Sets or returns the top position of a positioned element
	/// </summary>
	/// <value>
	/// The top.
	/// </value>
	string Style::top() { return ""; }
	void Style::top(string value) { }

	/// <summary>
	/// Applies a 2D or 3D transformation to an element
	/// </summary>
	/// <value>
	/// The transform.
	/// </value>
	string Style::transform() { return ""; }
	void Style::transform(string value) { }

	/// <summary>
	/// Sets or returns the position of transformed elements
	/// </summary>
	/// <value>
	/// The transform origin.
	/// </value>
	string Style::transformOrigin() { return ""; }
	void Style::transformOrigin(string value) { }

	/// <summary>
	/// Sets or returns how nested elements are rendered in 3D space
	/// </summary>
	/// <value>
	/// The transform style.
	/// </value>
	string Style::transformStyle() { return ""; }
	void Style::transformStyle(string value) { }

	/// <summary>
	/// A shorthand property for setting or returning the four transition properties
	/// </summary>
	/// <value>
	/// The transition.
	/// </value>
	string Style::transition() { return ""; }
	void Style::transition(string value) { }

	/// <summary>
	/// Sets or returns the CSS property that the transition effect is for
	/// </summary>
	/// <value>
	/// The transition property.
	/// </value>
	string Style::transitionProperty() { return ""; }
	void Style::transitionProperty(string value) { }

	/// <summary>
	/// Sets or returns how many seconds or milliseconds a transition effect takes to complete
	/// </summary>
	/// <value>
	/// The duration of the transition.
	/// </value>
	string Style::transitionDuration() { return ""; }
	void Style::transitionDuration(string value) { }

	/// <summary>
	/// Sets or returns the speed curve of the transition effect
	/// </summary>
	/// <value>
	/// The transition timing function.
	/// </value>
	string Style::transitionTimingFunction() { return ""; }
	void Style::transitionTimingFunction(string value) { }

	/// <summary>
	/// Sets or returns when the transition effect will start
	/// </summary>
	/// <value>
	/// The transition delay.
	/// </value>
	string Style::transitionDelay() { return ""; }
	void Style::transitionDelay(string value) { }

	/// <summary>
	/// Sets or returns whether the text should be overridden to support multiple languages in the same document
	/// </summary>
	/// <value>
	/// The unicode bidi.
	/// </value>
	string Style::unicodeBidi() { return ""; }
	void Style::unicodeBidi(string value) { }

	/// <summary>
	/// Sets or returns whether the text of an element can be selected or not
	/// </summary>
	/// <value>
	/// The user select.
	/// </value>
	string Style::userSelect() { return ""; }
	void Style::userSelect(string value) { }

	/// <summary>
	/// Sets or returns the vertical alignment of the content in an element
	/// </summary>
	/// <value>
	/// The vertical align.
	/// </value>
	string Style::verticalAlign() { return ""; }
	void Style::verticalAlign(string value) { }

	/// <summary>
	/// Sets or returns whether an element should be visible
	/// </summary>
	/// <value>
	/// The visibility.
	/// </value>
	string Style::visibility() { return ""; }
	void Style::visibility(string value) { }

	/// <summary>
	/// Sets or returns how to handle tabs, line breaks and whitespace in a text
	/// </summary>
	/// <value>
	/// The white space.
	/// </value>
	string Style::whiteSpace() { return ""; }
	void Style::whiteSpace(string value) { }

	/// <summary>
	/// Sets or returns the width of an element
	/// </summary>
	/// <value>
	/// The width.
	/// </value>
	string Style::width() { return ""; }
	void Style::width(string value) { }

	/// <summary>
	/// Sets or returns line breaking rules for non-CJK scripts
	/// </summary>
	/// <value>
	/// The word break.
	/// </value>
	string Style::wordBreak() { return ""; }
	void Style::wordBreak(string value) { }

	/// <summary>
	/// Sets or returns the spacing between words in a text
	/// </summary>
	/// <value>
	/// The word spacing.
	/// </value>
	string Style::wordSpacing() { return ""; }
	void Style::wordSpacing(string value) { }

	/// <summary>
	/// Allows long, unbreakable words to be broken and wrap to the next line
	/// </summary>
	/// <value>
	/// The word wrap.
	/// </value>
	string Style::wordWrap() { return ""; }
	void Style::wordWrap(string value) { }

	/// <summary>
	/// Sets or returns the minimum number of lines for an element that must be visible at the top of a page
	/// </summary>
	/// <value>
	/// The widows.
	/// </value>
	string Style::widows() { return ""; }
	void Style::widows(string value) { }

	/// <summary>
	/// Sets or returns the stack order of a positioned element
	/// </summary>
	/// <value>
	/// The index of the z.
	/// </value>
	string Style::zIndex() { return ""; }
	void Style::zIndex(string value) { }
}

/// <summary>
/// Window
/// </summary>
namespace litehtml
{
	Window::Window() { }

	/// <summary>
	/// Returns a Boolean value indicating whether a window has been closed or not
	/// </summary>
	/// <value>
	///   <c>true</c> if closed; otherwise, <c>false</c>.
	/// </value>
	bool Window::closed() { return false; }

	/// <summary>
	/// Returns a reference to the Console object, which provides methods for logging information to the browser's console (See Console object)
	/// </summary>
	/// <value>
	/// The console.
	/// </value>
	Console::ptr Window::console() { return nullptr; }

	/// <summary>
	/// Sets or returns the default text in the statusbar of a window
	/// </summary>
	/// <value>
	/// The default status.
	/// </value>
	string Window::defaultStatus() { return ""; }
	void Window::defaultStatus(string value) { }

	/// <summary>
	/// Returns the Document object for the window (See Document object)
	/// </summary>
	/// <value>
	/// The document.
	/// </value>
	Document::ptr Window::document() { return nullptr; }

	/// <summary>
	/// Returns the <iframe> element in which the current window is inserted
	/// </summary>
	/// <value>
	/// The frame element.
	/// </value>
	Element::ptr Window::frameElement() { return nullptr; }

	/// <summary>
	/// Returns all <iframe> elements in the current window
	/// </summary>
	/// <value>
	/// The frames.
	/// </value>
	std::vector<Window::ptr> Window::frames() {
		std::vector<Window::ptr> s;
		return s;
	}

	/// <summary>
	/// Returns the History object for the window (See History object)
	/// </summary>
	/// <value>
	/// The history.
	/// </value>
	History::ptr Window::history() { return nullptr; }

	/// <summary>
	/// Returns the height of the window's content area (viewport) including scrollbars
	/// </summary>
	/// <value>
	/// The height of the inner.
	/// </value>
	int Window::innerHeight() { return 0; }

	/// <summary>
	/// Returns the width of a window's content area (viewport) including scrollbars
	/// </summary>
	/// <value>
	/// The width of the inner.
	/// </value>
	int Window::innerWidth() { return 0; }

	/// <summary>
	/// Returns the number of <iframe> elements in the current window
	/// </summary>
	/// <value>
	/// The length.
	/// </value>
	int Window::length() { return 0; }

	/// <summary>
	/// Allows to save key/value pairs in a web browser. Stores the data with no expiration date
	/// </summary>
	/// <value>
	/// The local storage.
	/// </value>
	Storage::ptr Window::localStorage() { return nullptr; }

	/// <summary>
	/// Returns the Location object for the window (See Location object)
	/// </summary>
	/// <value>
	/// The location.
	/// </value>
	Location::ptr Window::location() { return nullptr; }
	void Window::location(string value) { }

	/// <summary>
	/// Sets or returns the name of a window
	/// </summary>
	/// <value>
	/// The name.
	/// </value>
	string Window::name() { return ""; }
	void Window::name(string value) { }

	/// <summary>
	/// Returns the Navigator object for the window (See Navigator object)
	/// </summary>
	/// <value>
	/// The navigator.
	/// </value>
	Navigator::ptr Window::navigator() { return nullptr; }

	/// <summary>
	/// Returns a reference to the window that created the window
	/// </summary>
	/// <value>
	/// The opener.
	/// </value>
	Window::ptr Window::opener() { return nullptr; }

	/// <summary>
	/// Returns the height of the browser window, including toolbars/scrollbars
	/// </summary>
	/// <value>
	/// The height of the outer.
	/// </value>
	int Window::outerHeight() { return 0; }

	/// <summary>
	/// Returns the width of the browser window, including toolbars/scrollbars
	/// </summary>
	/// <value>
	/// The width of the outer.
	/// </value>
	int Window::outerWidth() { return 0; }

	/// <summary>
	/// Returns the pixels the current document has been scrolled (horizontally) from the upper left corner of the window
	/// </summary>
	/// <value>
	/// The page x offset.
	/// </value>
	int Window::pageXOffset() { return 0; }

	/// <summary>
	/// Returns the pixels the current document has been scrolled (vertically) from the upper left corner of the window
	/// </summary>
	/// <value>
	/// The page y offset.
	/// </value>
	int Window::pageYOffset() { return 0; }

	/// <summary>
	/// Returns the parent window of the current window
	/// </summary>
	/// <value>
	/// The parent.
	/// </value>
	Window::ptr Window::parent() { return nullptr; }

	/// <summary>
	/// Returns the Screen object for the window (See Screen object)
	/// </summary>
	/// <value>
	/// The screen.
	/// </value>
	Screen::ptr Window::screen() { return nullptr; }

	/// <summary>
	/// Returns the horizontal coordinate of the window relative to the screen
	/// </summary>
	/// <value>
	/// The screen left.
	/// </value>
	int Window::screenLeft() { return 0; }

	/// <summary>
	/// Returns the vertical coordinate of the window relative to the screen
	/// </summary>
	/// <value>
	/// The screen top.
	/// </value>
	int Window::screenTop() { return 0; }

	/// <summary>
	/// Returns the horizontal coordinate of the window relative to the screen
	/// </summary>
	/// <value>
	/// The screen x.
	/// </value>
	int Window::screenX() { return 0; }

	/// <summary>
	/// Returns the vertical coordinate of the window relative to the screen
	/// </summary>
	/// <value>
	/// The screen y.
	/// </value>
	int Window::screenY() { return 0; }

	/// <summary>
	/// Allows to save key/value pairs in a web browser. Stores the data for one session
	/// </summary>
	/// <value>
	/// The session storage.
	/// </value>
	Storage::ptr Window::sessionStorage() { return nullptr; }

	/// <summary>
	/// An alias of pageXOffset
	/// </summary>
	/// <value>
	/// The scroll x.
	/// </value>
	int Window::scrollX() { return 0; }

	/// <summary>
	/// An alias of pageYOffset
	/// </summary>
	/// <value>
	/// The scroll y.
	/// </value>
	int Window::scrollY() { return 0; }

	/// <summary>
	/// Returns the current window
	/// </summary>
	/// <value>
	/// The self.
	/// </value>
	Window::ptr Window::self() { return nullptr; }

	/// <summary>
	/// Sets or returns the text in the statusbar of a window
	/// </summary>
	/// <value>
	/// The status.
	/// </value>
	string Window::status() { return ""; }
	void Window::status(string value) { }

	/// <summary>
	/// Returns the topmost browser window
	/// </summary>
	/// <value>
	/// The top.
	/// </value>
	Window::ptr Window::top() { return nullptr; }

	/// <summary>
	/// Displays an alert box with a message and an OK button
	/// </summary>
	/// <param name="message">The message.</param>
	void Window::alert(string message) { }

	/// <summary>
	/// Decodes a base-64 encoded string
	/// </summary>
	/// <param name="encodedStr">The encoded string.</param>
	/// <returns></returns>
	string Window::atob(string encodedStr) { return ""; }

	/// <summary>
	/// Removes focus from the current window
	/// </summary>
	void Window::blur() { }

	/// <summary>
	/// Encodes a string in base-64
	/// </summary>
	/// <param name="str">The string.</param>
	/// <returns></returns>
	string Window::btoa(string str) { return ""; }

	/// <summary>
	/// Clears a timer set with setInterval()
	/// </summary>
	/// <param name="var">The variable.</param>
	void Window::clearInterval(int var) { }

	/// <summary>
	/// Clears a timer set with setTimeout()
	/// </summary>
	/// <param name="id_of_settimeout">The identifier of settimeout.</param>
	void Window::clearTimeout(int id_of_settimeout) { }

	/// <summary>
	/// Closes the current window
	/// </summary>
	void Window::close() { }

	/// <summary>
	/// Displays a dialog box with a message and an OK and a Cancel button
	/// </summary>
	/// <param name="message">The message.</param>
	/// <returns></returns>
	bool Window::confirm(string message) { return false; }

	/// <summary>
	/// Sets focus to the current window
	/// </summary>
	void Window::focus() { }

	/// <summary>
	/// Gets the current computed CSS styles applied to an element
	/// </summary>
	/// <param name="element">The element.</param>
	/// <param name="pseudoElement">The pseudo element.</param>
	/// <returns></returns>
	CSSStyleDeclaration::ptr Window::getComputedStyle(Element::ptr element, string pseudoElement) { return nullptr; }

	/// <summary>
	/// Returns a Selection object representing the range of text selected by the user
	/// </summary>
	/// <returns></returns>
	void* Window::getSelection() { return nullptr; }

	/// <summary>
	/// Returns a MediaQueryList object representing the specified CSS media query string
	/// </summary>
	/// <param name="mediaQueryString">The media query string.</param>
	/// <returns></returns>
	MediaQueryList::ptr Window::matchMedia(string mediaQueryString) { return nullptr; }

	/// <summary>
	/// Moves a window relative to its current position
	/// </summary>
	/// <param name="x">The x.</param>
	/// <param name="y">The y.</param>
	void Window::moveBy(int x, int y) { }

	/// <summary>
	/// Moves a window to the specified position
	/// </summary>
	/// <param name="x">The x.</param>
	/// <param name="y">The y.</param>
	void Window::moveTo(int x, int y) { }

	/// <summary>
	/// Opens a new browser window
	/// </summary>
	/// <param name="URL">The URL.</param>
	/// <param name="name">The name.</param>
	/// <param name="specs">The specs.</param>
	/// <param name="replace">The replace.</param>
	/// <returns></returns>
	Window::ptr Window::open(string URL /*= nullptr*/, string name /*= nullptr*/, string specs /*= nullptr*/, bool replace /*= true*/) { return nullptr; }

	/// <summary>
	/// Prints the content of the current window
	/// </summary>
	void Window::print() { }

	/// <summary>
	/// Displays a dialog box that prompts the visitor for input
	/// </summary>
	/// <param name="text">The text.</param>
	/// <param name="defaultText">The default text.</param>
	/// <returns></returns>
	string Window::prompt(string text, string defaultText /*= nullptr*/) { return ""; }

	/// <summary>
	/// Requests the browser to call a function to update an animation before the next repaint
	/// </summary>
	/// <returns></returns>
	void* Window::requestAnimationFrame() { return nullptr; }

	/// <summary>
	/// Resizes the window by the specified pixels
	/// </summary>
	/// <param name="width">The width.</param>
	/// <param name="height">The height.</param>
	void Window::resizeBy(int width, int height) { }

	/// <summary>
	/// Resizes the window to the specified width and height
	/// </summary>
	/// <param name="width">The width.</param>
	/// <param name="height">The height.</param>
	void Window::resizeTo(int width, int height) { }

	/// <summary>
	/// Scrolls the document by the specified number of pixels
	/// </summary>
	/// <param name="xnum">The xnum.</param>
	/// <param name="ynum">The ynum.</param>
	void Window::scrollBy(int xnum, int ynum) { }

	/// <summary>
	/// Scrolls the document to the specified coordinates
	/// </summary>
	/// <param name="xpos">The xpos.</param>
	/// <param name="ypos">The ypos.</param>
	void Window::scrollTo(int xpos, int ypos) { }

	/// <summary>
	/// Calls a function or evaluates an expression at specified intervals (in milliseconds)
	/// </summary>
	/// <param name="function">The function.</param>
	/// <param name="milliseconds">The milliseconds.</param>
	/// <param name="args">The arguments.</param>
	/// <returns></returns>
	int Window::setInterval(tfunc function, int milliseconds, ...) { return 0; }

	/// <summary>
	/// Calls a function or evaluates an expression after a specified number of milliseconds
	/// </summary>
	/// <param name="function">The function.</param>
	/// <param name="milliseconds">The milliseconds.</param>
	/// <param name="args">The arguments.</param>
	/// <returns></returns>
	int Window::setTimeout(tfunc function, int milliseconds, ...) { return 0; }

	/// <summary>
	/// Stops the window from loading
	/// </summary>
	void Window::stop() { }
}

/// <summary>
/// Storage
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Overloading [] operator to access elements in array style
	/// </summary>
	tany Storage::operator[](string key) { return tany(); }

	/// <summary>
	/// Returns the name of the nth key in the storage
	/// </summary>
	/// <param name="index">The index.</param>
	/// <returns></returns>
	string Storage::key(int index) { return ""; }

	/// <summary>
	/// Returns the number of data items stored in the Storage object
	/// </summary>
	/// <value>
	/// The length.
	/// </value>
	int Storage::length() { return 0; }

	/// <summary>
	/// Returns the value of the specified key name
	/// </summary>
	/// <param name="keyname">The keyname.</param>
	/// <returns></returns>
	string Storage::getItem(string keyname) { return ""; }

	/// <summary>
	/// Adds that key to the storage, or update that key's value if it already exists
	/// </summary>
	/// <param name="keyname">The keyname.</param>
	/// <param name="value">The value.</param>
	/// <returns></returns>
	string Storage::setItem(string keyname, string value) { return ""; }

	/// <summary>
	/// Removes that key from the storage
	/// </summary>
	/// <param name="keyname">The keyname.</param>
	void Storage::removeItem(string keyname) { }

	/// <summary>
	/// Empty all key out of the storage
	/// </summary>
	void Storage::clear() { }
}

/// <summary>
/// CSSStyleDeclaration
/// </summary>
namespace litehtml
{
	/// <summary>
	/// Sets or returns the textual representation of a CSS declaration block
	/// </summary>
	string CSSStyleDeclaration::cssText() { return ""; }
	void CSSStyleDeclaration::cssText(string value) { }

	/// <summary>
	/// Returns whether or not the specified CSS property has the "important!" priority set
	/// </summary>
	string CSSStyleDeclaration::getPropertyPriority(string propertyName) { return ""; }

	/// <summary>
	/// Returns the value of the specified CSS property
	/// </summary>
	string CSSStyleDeclaration::getPropertyValue(string propertyName) { return ""; }

	/// <summary>
	/// Returns the CSS property name from a CSS declaration block, by index
	/// </summary>
	string CSSStyleDeclaration::item(int index) { return ""; }

	/// <summary>
/// Returns the number of style declarations in a CSS declaration block
/// </summary>
	int CSSStyleDeclaration::length() { return 0; }

	/// <summary>
	/// Returns a CSS rule that is the parent of the style block
	/// </summary>
	void* CSSStyleDeclaration::parentRule() { return nullptr; }

	/// <summary>
	/// Removes a CSS property from a CSS declaration block
	/// </summary>
	void CSSStyleDeclaration::removeProperty(string propertyName) { }

	/// <summary>
	/// Sets a new or modifies an existing CSS property in a CSS declaration block
	/// </summary>
	void CSSStyleDeclaration::setProperty(string propertyName, string value, string important) { }
}