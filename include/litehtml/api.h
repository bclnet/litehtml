#ifndef LH_API_H
#define LH_API_H

#include <memory>
#include "api_any.h"
#include "api_event.h"
#include "api_node.h"
#include "api_service.h"
#include "script_engine.h"

namespace litehtml
{
	class document;
	class HTMLCollection;
	class Style;
	class Storage;
	class Element;

	/// <summary>
	/// Rect
	/// </summary>
	class Rect
	{
	public:
		typedef std::unique_ptr<Rect> ptr;
	public:
		int left();
		int top();
		int right();
		int bottom();
		int x();
		int y();
		int width();
		int height();
	};

	/// <summary>
	/// DocumentFragment
	/// </summary>
	class DocumentFragment : public Node
	{
	public:
		typedef std::unique_ptr<DocumentFragment> ptr;
	};

	/// <summary>
	/// DocumentType
	/// </summary>
	class DocumentType
	{
	public:
		typedef std::unique_ptr<DocumentType> ptr;
	};

	/// <summary>
	/// DocumentImplementation
	/// </summary>
	class DocumentImplementation
	{
	public:
		typedef std::unique_ptr<DocumentImplementation> ptr;

		bool hasFeature(string x, string y);
	};

	/// <summary>
	/// Console
	/// https://www.w3schools.com/jsref/obj_console.asp
	/// </summary>
	class Console
	{
	public:
		typedef std::shared_ptr<Console> ptr;

		/// <summary>
		/// Writes an error message to the console if the assertion is false
		/// </summary>
		/// <param name="assertion">The assertion.</param>
		/// <param name="message">The message.</param>
		void assert_(bool assertion, tany message);

		/// <summary>
		/// Clears the console
		/// </summary>
		void clear();

		/// <summary>
		/// Logs the number of times that this particular call to count() has been called
		/// </summary>
		/// <param name="label">The label.</param>
		void count(string label = _tdefault);

		/// <summary>
		/// Outputs an error message to the console
		/// </summary>
		/// <param name="message">The message.</param>
		void error(tany message);

		/// <summary>
		/// Creates a new inline group in the console. This indents following console messages by an additional level, until console.groupEnd() is called
		/// </summary>
		/// <param name="label">The label.</param>
		void group(string label = _tdefault);

		/// <summary>
		/// Creates a new inline group in the console. However, the new group is created collapsed. The user will need to use the disclosure button to expand it
		/// </summary>
		/// <param name="label">The label.</param>
		void groupCollapsed(string label = _tdefault);

		/// <summary>
		/// Exits the current inline group in the console
		/// </summary>
		void groupEnd();

		/// <summary>
		/// Outputs an informational message to the console
		/// </summary>
		/// <param name="message">The message.</param>
		void info(tany message);

		/// <summary>
		/// Outputs a message to the console
		/// </summary>
		/// <param name="message">The message.</param>
		void log(tany message);

		/// <summary>
		/// Displays tabular data as a table
		/// </summary>
		/// <param name="tabledata">The tabledata.</param>
		/// <param name="tablecolumns">The tablecolumns.</param>
		void table(void* tabledata, string tablecolumns[] = nullptr);

		/// <summary>
		/// Starts a timer (can track how long an operation takes)
		/// </summary>
		/// <param name="label">The label.</param>
		void time(string label = _tdefault);

		/// <summary>
		/// Stops a timer that was previously started by console.time()
		/// </summary>
		/// <param name="label">The label.</param>
		void timeEnd(string label = _tdefault);

		/// <summary>
		/// Outputs a stack trace to the console
		/// </summary>
		/// <param name="label">The label.</param>
		void trace(string label = _tdefault);

		/// <summary>
		/// Outputs a warning message to the console
		/// </summary>
		/// <param name="message">The message.</param>
		void warn(tany message);
	};

	/// <summary>
	/// Document
	/// https://www.w3schools.com/jsref/dom_obj_document.asp
	/// </summary>
	class Document : public Node, public EventTarget
	{
	protected:
		document* _doc;
	public:
		typedef std::shared_ptr<Document> ptr;
		Document();
		//Document(std::shared_ptr<document> doc);

		/// <summary>
		/// Returns the currently focused element in the document
		/// </summary>
		/// <value>
		/// The active element.
		/// </value>
		std::shared_ptr<Element> activeElement();

		/// <summary>
		/// Attaches an event handler to the document
		/// </summary>
		/// <param name="event">The event.</param>
		/// <param name="function">The function.</param>
		/// <param name="useCapture">if set to <c>true</c> [use capture].</param>
		//void addEventListener(string event, void* function, bool useCapture = false); //: EventTarget

		/// <summary>
		/// Adopts a node from another document
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns></returns>
		Node::ptr adoptNode(Node::ptr node);

		/// <summary>
		/// Returns a collection of all <a> elements in the document that have a name attribute
		/// </summary>
		/// <value>
		/// The anchors.
		/// </value>
		HTMLCollection anchors();

		/// <summary>
		/// Adds a new child node, to an element, as the last child node
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns></returns>
		virtual Node::ptr appendChild(Node::ptr node) override; //: Node

		/// <summary>
		/// Returns a collection of all <applet> elements in the document
		/// </summary>
		/// <value>
		/// The applets.
		/// </value>
		HTMLCollection applets();

		/// <summary>
		/// NotSupported - Returns a NamedNodeMap of an element's attributes
		/// </summary>
		/// <value>
		/// The attributes.
		/// </value>
		virtual NamedNodeMap attributes() override; //: Node

		/// <summary>
		/// Returns the absolute base URI of a document
		/// </summary>
		/// <value>
		/// The base URI.
		/// </value>
		virtual string baseURI() override; //: Node

		/// <summary>
		/// Sets or returns the document's body (the <body> element)
		/// </summary>
		/// <value>
		/// The body.
		/// </value>
		std::shared_ptr<Element> body();
		void body(Element* value);
		
		/// <summary>
		/// Returns the character encoding for the document
		/// </summary>
		/// <value>
		/// The character set.
		/// </value>
		string charset();

		/// <summary>
		/// Returns the character encoding for the document
		/// </summary>
		/// <value>
		/// The character set.
		/// </value>
		string characterSet();

		/// <summary>
		/// Returns a collection of an element's child nodes (including text and comment nodes)
		/// </summary>
		virtual NodeList<Node> childNodes() override; //: Node

		/// <summary>
		/// Clones an element
		/// </summary>
		/// <param name="deep">if set to <c>true</c> [deep].</param>
		/// <returns></returns>
		virtual Node::ptr cloneNode(bool deep = false) override; //: Node

		/// <summary>
		/// Closes the output stream previously opened with document.open()
		/// </summary>
		void close();

		/// <summary>
		/// Compares the document position of two elements
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns></returns>
		virtual int compareDocumentPosition(Node::ptr node) override; //: Node

		/// <summary>
		/// Returns all name/value pairs of cookies in the document
		/// </summary>
		/// <value>
		/// The cookie.
		/// </value>
		string cookie();
		void cookie(string value);

		/// <summary>
		/// Creates an attribute node
		/// </summary>
		/// <param name="attributename">The attributename.</param>
		/// <returns></returns>
		Attr::ptr createAttribute(string attributename);

		/// <summary>
		/// Creates a Comment node with the specified text
		/// </summary>
		/// <param name="text">The text.</param>
		/// <returns></returns>
		Node::ptr createComment(string text); //: IComment

		/// <summary>
		/// Creates an empty DocumentFragment node
		/// </summary>
		/// <returns></returns>
		DocumentFragment::ptr createDocumentFragment();

		/// <summary>
		/// Creates an Element node
		/// </summary>
		/// <param name="nodename">The nodename.</param>
		/// <returns></returns>
		std::shared_ptr<Element> createElement(string nodename);

		/// <summary>
		/// Creates a new event
		/// </summary>
		/// <param name="type">The type.</param>
		/// <returns></returns>
		Event::ptr createEvent(string type);

		/// <summary>
		/// Creates a Text node
		/// </summary>
		/// <param name="text">The text.</param>
		/// <returns></returns>
		Node::ptr createTextNode(string text); //: IText

		/// <summary>
		/// Returns the window object associated with a document, or nullptr if none is available.
		/// </summary>
		/// <value>
		/// The default view.
		/// </value>
		std::shared_ptr<Window> defaultView();

		/// <summary>
		/// Controls whether the entire document should be editable or not.
		/// </summary>
		/// <value>
		/// The design mode.
		/// </value>
		string designMode();
		void designMode(string value);

		/// <summary>
		/// Returns the Document Type Declaration associated with the document
		/// </summary>
		/// <value>
		/// The doctype.
		/// </value>
		DocumentType::ptr doctype();

		/// <summary>
		/// Returns the Document Element of the document (the <html> element)
		/// </summary>
		/// <value>
		/// The document element.
		/// </value>
		std::shared_ptr<Element> documentElement();

		/// <summary>
		/// Sets or returns the location of the document
		/// </summary>
		/// <value>
		/// The document URI.
		/// </value>
		string documentURI();
		void documentURI(string value);

		/// <summary>
		/// Returns the domain name of the server that loaded the document
		/// </summary>
		/// <value>
		/// The domain.
		/// </value>
		string domain();

		/// <summary>
		/// Returns a collection of all <embed> elements the document
		/// </summary>
		/// <value>
		/// The embeds.
		/// </value>
		HTMLCollection embeds();

		/// <summary>
		/// Invokes the specified clipboard operation on the element currently having focus.
		/// </summary>
		/// <param name="command">The command.</param>
		/// <param name="showUI">if set to <c>true</c> [show UI].</param>
		/// <param name="value">The value.</param>
		/// <returns></returns>
		bool execCommand(string command, bool showUI, void* value = nullptr);

		/// <summary>
		/// Returns the first child node of an element
		/// </summary>
		/// <value>
		/// The first child.
		/// </value>
		virtual Node::ptr firstChild() override; //: Node

		/// <summary>
		/// Returns a collection of all <form> elements in the document
		/// </summary>
		/// <value>
		/// The forms.
		/// </value>
		HTMLCollection forms();

		/// <summary>
		/// Returns the current element that is displayed in fullscreen mode
		/// </summary>
		/// <value>
		/// The fullscreen element.
		/// </value>
		std::shared_ptr<Element> fullscreenElement();

		/// <summary>
		/// Returns a Boolean value indicating whether the document can be viewed in fullscreen mode
		/// </summary>
		/// <returns></returns>
		bool fullscreenEnabled();

		/// <summary>
		/// Returns the element that has the ID attribute with the specified value
		/// </summary>
		/// <param name="elementID">The element identifier.</param>
		/// <returns></returns>
		std::shared_ptr<Element> getElementById(string elementID);

		/// <summary>
		/// Returns a NodeList containing all elements with the specified class name
		/// </summary>
		/// <param name="classname">The classname.</param>
		/// <returns></returns>
		NodeList<Element> getElementsByClassName(string classname);

		/// <summary>
		/// Returns a NodeList containing all elements with a specified name
		/// </summary>
		/// <param name="name">The name.</param>
		/// <returns></returns>
		NodeList<Element> getElementsByName(string name);

		/// <summary>
		/// Returns a NodeList containing all elements with the specified tag name
		/// </summary>
		/// <param name="tagname">The tagname.</param>
		/// <returns></returns>
		NodeList<Element> getElementsByTagName(string tagname);

		/// <summary>
		/// Not Supported - Returns true if the specified node has any attributes, otherwise false
		/// </summary>
		/// <returns>
		///   <c>true</c> if this instance has attributes; otherwise, <c>false</c>.
		/// </returns>
		virtual bool hasAttributes() override; //: Node

		/// <summary>
		/// Returns true if an element has any child nodes, otherwise false
		/// </summary>
		/// <returns>
		///   <c>true</c> if [has child nodes]; otherwise, <c>false</c>.
		/// </returns>
		virtual bool hasChildNodes() override; //: Node

		/// <summary>
		/// Returns a Boolean value indicating whether the document has focus
		/// </summary>
		/// <returns>
		///   <c>true</c> if this instance has focus; otherwise, <c>false</c>.
		/// </returns>
		bool hasFocus();

		/// <summary>
		/// Returns the <head> element of the document
		/// </summary>
		/// <value>
		/// The head.
		/// </value>
		std::shared_ptr<Element> head();

		/// <summary>
		///Returns a collection of all <img> elements in the document
		/// </summary>
		/// <value>
		/// The images.
		/// </value>
		HTMLCollection images();

		/// <summary>
		/// Returns the DOMImplementation object that handles this document
		/// </summary>
		/// <value>
		/// The implementation.
		/// </value>
		DocumentImplementation::ptr implementation();

		/// <summary>
		/// Imports a node from another document
		/// </summary>
		/// <param name="node">The node.</param>
		/// <param name="deep">if set to <c>true</c> [deep].</param>
		/// <returns></returns>
		Node::ptr importNode(Node::ptr node, bool deep);

		/// <summary>
		/// Returns the encoding, character set, used for the document
		/// </summary>
		/// <value>
		/// The input encoding.
		/// </value>
		string inputEncoding();

		/// <summary>
		/// Returns true if a specified namespaceURI is the default, otherwise false
		/// </summary>
		/// <param name="namespaceURI">The namespace URI.</param>
		/// <returns>
		///   <c>true</c> if [is default namespace] [the specified namespace URI]; otherwise, <c>false</c>.
		/// </returns>
		virtual bool isDefaultNamespace(string namespaceURI) override; //: Node

		/// <summary>
		/// Checks if two elements are equal
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns>
		///   <c>true</c> if [is equal node] [the specified node]; otherwise, <c>false</c>.
		/// </returns>
		virtual bool isEqualNode(Node::ptr node) override; //: Node

		/// <summary>
		/// Checks if two elements are the same node
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns>
		///   <c>true</c> if [is same node] [the specified node]; otherwise, <c>false</c>.
		/// </returns>
		virtual bool isSameNode(Node::ptr node) override; //: Node

		/// <summary>
		/// Returns the last child node of an element
		/// </summary>
		/// <value>
		/// The last child.
		/// </value>
		virtual Node::ptr lastChild() override; //: Node

		/// <summary>
		/// Returns the date and time the document was last modified
		/// </summary>
		/// <value>
		/// The last modified.
		/// </value>
		int64_t lastModified(); //: string

		/// <summary>
		/// Returns a collection of all <a> and <area> elements in the document that have a href attribute
		/// </summary>
		/// <value>
		/// The links.
		/// </value>
		HTMLCollection links();

		/// <summary>
		/// Returns the next node at the same node tree level
		/// </summary>
		/// <value>
		/// The next sibling.
		/// </value>
		virtual Node::ptr nextSibling() override; //: Node

		/// <summary>
		/// Returns the name of a node
		/// </summary>
		/// <value>
		/// The name of the node.
		/// </value>
		virtual string nodeName() override; //: Node

		/// <summary>
		/// Returns the node type of a node
		/// </summary>
		/// <value>
		/// The type of the node.
		/// </value>
		virtual int nodeType() override; //: Node

		/// <summary>
		/// Sets or returns the value of a node
		/// </summary>
		/// <value>
		/// The node value.
		/// </value>
		virtual string nodeValue() override; //: Node
		virtual void nodeValue(string value) override; //: Node

		/// <summary>
		/// Removes empty Text nodes, and joins adjacent nodes
		/// </summary>
		virtual void normalize() override; //: Node

		/// <summary>
		/// Opens an HTML output stream to collect output from document.write()
		/// </summary>
		/// <param name="MIMEtype">The mim etype.</param>
		/// <param name="replace">The replace.</param>
		void open(string MIMEtype = nullptr, string replace = nullptr);

		/// <summary>
		/// Returns the root element (document object) for an element
		/// </summary>
		/// <value>
		/// The owner document.
		/// </value>
		virtual Document::ptr ownerDocument() override; //: Node

		/// <summary>
		/// Returns the parent node of an element
		/// </summary>
		/// <value>
		/// The parent node.
		/// </value>
		virtual Node::ptr parentNode() override; //: Node

		/// <summary>
		/// Returns the previous node at the same node tree level
		/// </summary>
		/// <value>
		/// The previous sibling.
		/// </value>
		virtual Node::ptr previousSibling() override; //: Node

		/// <summary>
		/// Returns the first element that matches a specified CSS selector(s) in the document
		/// </summary>
		/// <param name="selectors">The selectors.</param>
		/// <returns></returns>
		std::shared_ptr<Element> querySelector(string selectors);

		/// <summary>
		/// Returns a static NodeList containing all elements that matches a specified CSS selector(s) in the document
		/// </summary>
		/// <param name="selectors">The selectors.</param>
		/// <returns></returns>
		NodeList<Element> querySelectorAll(string selectors);

		/// <summary>
		/// Returns the (loading) status of the document
		/// </summary>
		/// <value>
		/// The state of the ready.
		/// </value>
		string readyState();

		/// <summary>
		/// Returns the URL of the document that loaded the current document
		/// </summary>
		/// <value>
		/// The referrer.
		/// </value>
		string referrer();

		/// <summary>
		/// Removes a child node from an element
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns></returns>
		virtual Node::ptr removeChild(Node::ptr node) override; //: Node

		/// <summary>
		/// Removes an event handler from the document (that has been attached with the addEventListener() method)
		/// </summary>
		/// <param name="event">The event.</param>
		/// <param name="function">The function.</param>
		/// <param name="useCapture">if set to <c>true</c> [use capture].</param>
		//void removeEventListener(string event, void* function, bool useCapture = false); //: EventTarget

		/// <summary>
		/// NotSupported - Renames the specified node
		/// </summary>
		/// <param name="node">The node.</param>
		/// <param name="namespaceURI">The namespace URI.</param>
		/// <param name="nodename">The nodename.</param>
		/// <returns></returns>
		Node::ptr renameNode(Node::ptr node, string namespaceURI, string nodename);

		/// <summary>
		/// Replaces a child node in an element
		/// </summary>
		/// <param name="newnode">The newnode.</param>
		/// <param name="oldnode">The oldnode.</param>
		/// <returns></returns>
		virtual Node::ptr replaceChild(Node::ptr newnode, Node::ptr oldnode) override; //: Node

		/// <summary>
		/// Returns a collection of <script> elements in the document
		/// </summary>
		/// <value>
		/// The scripts.
		/// </value>
		HTMLCollection scripts();

		/// <summary>
		/// Sets or returns the textual content of a node and its descendants
		/// </summary>
		/// <value>
		/// The content of the text.
		/// </value>
		virtual string textContent() override; //: Node
		virtual void textContent(string value) override; //: Node

		/// <summary>
		/// Sets or returns the title of the document
		/// </summary>
		/// <value>
		/// The title.
		/// </value>
		string title();
		void title(string value);

		/// <summary>
		/// Returns the full URL of the HTML document
		/// </summary>
		/// <value>
		/// The URL.
		/// </value>
		string URL();

		/// <summary>
		/// Writes HTML expressions or JavaScript code to a document
		/// </summary>
		/// <param name="args">The arguments.</param>
		void write(void** args);

		/// <summary>
		/// Same as write(), but adds a newline character after each statement
		/// </summary>
		/// <param name="args">The arguments.</param>
		void writeln(void** args);
	};

	/// <summary>
	/// Element
	/// https://www.w3schools.com/jsref/dom_obj_all.asp
	/// </summary>
	class Element : public Node, public EventTarget
	{
	protected:
		element* _elem;
	public:
		typedef std::shared_ptr<Element> ptr;
		Element();
		Element(std::shared_ptr<element>& elem);

		/// <summary>
		/// Gets or sets the access key.
		/// </summary>
		/// <value>
		/// The access key.
		/// </value>
		char accessKey();
		void accessKey(char value);

		/// <summary>
		/// Adds the event listener.
		/// </summary>
		/// <param name="event">The event.</param>
		/// <param name="function">The function.</param>
		/// <param name="useCapture">if set to <c>true</c> [use capture].</param>
		//void addEventListener(string event, void* function, bool useCapture = false); //: EventTarget

		/// <summary>
		/// Adds a new child node, to an element, as the last child node
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns></returns>
		virtual Node::ptr appendChild(Node::ptr node) override; //: Node

		/// <summary>
		/// Returns a NamedNodeMap of an element's attributes
		/// </summary>
		/// <value>
		/// The attributes.
		/// </value>
		virtual NamedNodeMap attributes() override; //: Node

		/// <summary>
		/// Returns the absolute base URI of a node
		/// </summary>
		/// <value>
		/// The base URI.
		/// </value>
		virtual string baseURI() override; //: Node

		/// <summary>
		/// Removes focus from an element
		/// </summary>
		void blur();

		/// <summary>
		/// Returns the number of child elements an element has
		/// </summary>
		/// <value>
		/// The child element count.
		/// </value>
		int childElementCount();

		/// <summary>
		/// Returns a collection of an element's child nodes (including text and comment nodes)
		/// </summary>
		virtual NodeList<Node> childNodes() override; //: Node

		/// <summary>
		/// Returns a collection of an element's child element (excluding text and comment nodes)
		/// </summary>
		HTMLCollection children();

		/// <summary>
		/// Returns the class name(s) of an element
		/// </summary>
		/// <value>
		/// The class list.
		/// </value>
		DOMTokenList::ptr classList();

		/// <summary>
		/// Sets or returns the value of the class attribute of an element
		/// </summary>
		/// <value>
		/// The name of the class.
		/// </value>
		string className();
		void className(string value);

		/// <summary>
		/// Simulates a mouse-click on an element
		/// </summary>
		void click();

		/// <summary>
		/// Returns the height of an element, including padding
		/// </summary>
		/// <value>
		/// The height of the client.
		/// </value>
		int clientHeight();

		/// <summary>
		/// Returns the width of the left border of an element
		/// </summary>
		/// <value>
		/// The client left.
		/// </value>
		int clientLeft();

		/// <summary>
		/// Returns the width of the top border of an element
		/// </summary>
		/// <value>
		/// The client top.
		/// </value>
		int clientTop();

		/// <summary>
		/// Returns the width of an element, including padding
		/// </summary>
		/// <value>
		/// The width of the client.
		/// </value>
		int clientWidth();

		/// <summary>
		/// Clones an element
		/// </summary>
		/// <param name="deep">if set to <c>true</c> [deep].</param>
		/// <returns></returns>
		virtual Node::ptr cloneNode(bool deep = false) override; //: Node

		/// <summary>
		/// Compares the document position of two elements
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns></returns>
		virtual int compareDocumentPosition(Node::ptr node) override; //: Node

		/// <summary>
		/// Returns true if a node is a descendant of a node, otherwise false
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns>
		///   <c>true</c> if [contains] [the specified node]; otherwise, <c>false</c>.
		/// </returns>
		bool contains(Node::ptr node);

		/// <summary>
		/// Sets or returns whether the content of an element is editable or not
		/// </summary>
		/// <value>
		/// The content editable.
		/// </value>
		string contentEditable();
		void contentEditable(string value);

		/// <summary>
		/// Sets or returns the value of the dir attribute of an element
		/// </summary>
		/// <value>
		/// The dir.
		/// </value>
		string dir();
		void dir(string value);

		/// <summary>
		/// Cancels an element in fullscreen mode
		/// </summary>
		void exitFullscreen();

		/// <summary>
		/// Returns the first child node of an element
		/// </summary>
		/// <value>
		/// The first child.
		/// </value>
		virtual Node::ptr firstChild() override; //: Node

		/// <summary>
		/// Returns the first child element of an element
		/// </summary>
		/// <value>
		/// The first element child.
		/// </value>
		std::shared_ptr<Element> firstElementChild();

		/// <summary>
		/// Gives focus to an element
		/// </summary>
		void focus();

		/// <summary>
		/// Returns the specified attribute value of an element node
		/// </summary>
		/// <param name="attributename">The attributename.</param>
		/// <returns></returns>
		string getAttribute(string attributename);

		/// <summary>
		/// Returns the specified attribute node
		/// </summary>
		/// <param name="attributename">The attributename.</param>
		/// <returns></returns>
		Attr::ptr getAttributeNode(string attributename);

		/// <summary>
		/// Returns the size of an element and its position relative to the viewport
		/// </summary>
		/// <returns></returns>
		Rect::ptr getBoundingClientRect();

		/// <summary>
		/// Returns a collection of all child elements with the specified class name
		/// </summary>
		/// <param name="classname">The classname.</param>
		/// <returns></returns>
		NodeList<Element> getElementsByClassName(string classname);

		/// <summary>
		/// Returns a collection of all child elements with the specified tag name
		/// </summary>
		/// <param name="tagname">The tagname.</param>
		/// <returns></returns>
		NodeList<Element> getElementsByTagName(string tagname);

		/// <summary>
		/// Returns true if an element has the specified attribute, otherwise false
		/// </summary>
		/// <param name="attributename">The attributename.</param>
		/// <returns>
		///   <c>true</c> if the specified attributename has attribute; otherwise, <c>false</c>.
		/// </returns>
		bool hasAttribute(string attributename);

		/// <summary>
		/// Returns true if an element has any attributes, otherwise false
		/// </summary>
		/// <returns>
		///   <c>true</c> if this instance has attributes; otherwise, <c>false</c>.
		/// </returns>
		virtual bool hasAttributes() override; //: Node

		/// <summary>
		/// Returns true if an element has any child nodes, otherwise false
		/// </summary>
		/// <returns>
		///   <c>true</c> if [has child nodes]; otherwise, <c>false</c>.
		/// </returns>
		virtual bool hasChildNodes() override; //: Node

		/// <summary>
		/// Sets or returns the value of the id attribute of an element
		/// </summary>
		/// <value>
		/// The identifier.
		/// </value>
		string id();
		void id(string value);

		/// <summary>
		/// Sets or returns the content of an element
		/// </summary>
		/// <value>
		/// The inner HTML.
		/// </value>
		string innerHTML();
		void innerHTML(string value);

		/// <summary>
		/// Sets or returns the text content of a node and its descendants
		/// </summary>
		/// <value>
		/// The inner text.
		/// </value>
		string innerText();
		void innerText(string value);

		/// <summary>
		/// Inserts a HTML element at the specified position relative to the current element
		/// </summary>
		/// <param name="position">The position.</param>
		/// <param name="element">The element.</param>
		void insertAdjacentElement(string position, Element* element);

		/// <summary>
		/// Inserts a HTML formatted text at the specified position relative to the current element
		/// </summary>
		/// <param name="position">The position.</param>
		/// <param name="text">The text.</param>
		void insertAdjacentHTML(string position, string text);

		/// <summary>
		/// Inserts text into the specified position relative to the current element
		/// </summary>
		/// <param name="position">The position.</param>
		/// <param name="text">The text.</param>
		void insertAdjacentText(string position, string text);

		/// <summary>
		/// Inserts a new child node before a specified, existing, child node
		/// </summary>
		/// <param name="newnode">The newnode.</param>
		/// <param name="existingnode">The existingnode.</param>
		Node::ptr insertBefore(Node::ptr newnode, Node::ptr existingnode);

		/// <summary>
		/// Returns true if the content of an element is editable, otherwise false
		/// </summary>
		/// <value>
		///   <c>true</c> if this instance is content editable; otherwise, <c>false</c>.
		/// </value>
		bool isContentEditable();

		/// <summary>
		/// Returns true if a specified namespaceURI is the default, otherwise false
		/// </summary>
		/// <param name="namespaceURI">The namespace URI.</param>
		/// <returns>
		///   <c>true</c> if [is default namespace] [the specified namespace URI]; otherwise, <c>false</c>.
		/// </returns>
		virtual bool isDefaultNamespace(string namespaceURI) override; //: Node

		/// <summary>
		/// Checks if two elements are equal
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns>
		///   <c>true</c> if [is equal node] [the specified node]; otherwise, <c>false</c>.
		/// </returns>
		virtual bool isEqualNode(Node::ptr node) override; //: Node

		/// <summary>
		/// Checks if two elements are the same node
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns>
		///   <c>true</c> if [is same node] [the specified node]; otherwise, <c>false</c>.
		/// </returns>
		virtual bool isSameNode(Node::ptr node) override; //: Node

		/// <summary>
		/// Sets or returns the value of the lang attribute of an element
		/// </summary>
		/// <value>
		/// The language.
		/// </value>
		string lang();
		void lang(string value);

		/// <summary>
		/// Returns the last child node of an element
		/// </summary>
		/// <value>
		/// The last child.
		/// </value>
		virtual Node::ptr lastChild() override; //: Node

		/// <summary>
		/// Returns the last child element of an element
		/// </summary>
		/// <value>
		/// The last element child.
		/// </value>
		std::shared_ptr<Element> lastElementChild();

		/// <summary>
		/// Returns the local name of an element
		/// </summary>
		/// <value>
		/// The local name.
		/// </value>
		string localName();

		/// <summary>
		/// Returns the namespace URI of an element
		/// </summary>
		/// <value>
		/// The namespace URI.
		/// </value>
		string namespaceURI();

		/// <summary>
		/// Returns the next node at the same node tree level
		/// </summary>
		/// <value>
		/// The next sibling.
		/// </value>
		virtual Node::ptr nextSibling() override; //: Node

		/// <summary>
		/// Returns the next element at the same node tree level
		/// </summary>
		/// <value>
		/// The next element sibling.
		/// </value>
		std::shared_ptr<Element> nextElementSibling();

		/// <summary>
		/// Returns the name of a node
		/// </summary>
		/// <value>
		/// The name of the node.
		/// </value>
		virtual string nodeName() override; //: Node

		/// <summary>
		/// Returns the node type of a node
		/// </summary>
		/// <value>
		/// The type of the node.
		/// </value>
		virtual int nodeType() override; //: Node

		/// <summary>
		/// Sets or returns the value of a node
		/// </summary>
		/// <value>
		/// The node value.
		/// </value>
		virtual string nodeValue() override; //: Node
		virtual void nodeValue(string value) override; //: Node

		/// <summary>
		/// Joins adjacent text nodes and removes empty text nodes in an element
		/// </summary>
		virtual void normalize() override; //: Node

		/// <summary>
		/// Returns the height of an element, including padding, border and scrollbar
		/// </summary>
		/// <value>
		/// The height of the offset.
		/// </value>
		int offsetHeight();

		/// <summary>
		/// Returns the width of an element, including padding, border and scrollbar
		/// </summary>
		/// <value>
		/// The width of the offset.
		/// </value>
		int offsetWidth();

		/// <summary>
		/// Returns the horizontal offset position of an element
		/// </summary>
		/// <value>
		/// The offset left.
		/// </value>
		int offsetLeft();

		/// <summary>
		/// Returns the offset container of an element
		/// </summary>
		/// <value>
		/// The offset parent.
		/// </value>
		Node::ptr offsetParent();

		/// <summary>
		/// Returns the vertical offset position of an element
		/// </summary>
		/// <value>
		/// The offset top.
		/// </value>
		int offsetTop();

		/// <summary>
		/// Returns the root element (document object) for an element
		/// </summary>
		/// <value>
		/// The owner document.
		/// </value>
		virtual Document::ptr ownerDocument() override; //: Node

		/// <summary>
		/// Returns the parent node of an element
		/// </summary>
		/// <value>
		/// The parent node.
		/// </value>
		virtual Node::ptr parentNode() override; //: Node

		/// <summary>
		/// Returns the parent element node of an element
		/// </summary>
		/// <value>
		/// The parent element.
		/// </value>
		std::shared_ptr<Element> parentElement();

		/// <summary>
		/// Returns the previous node at the same node tree level
		/// </summary>
		/// <value>
		/// The previous sibling.
		/// </value>
		virtual Node::ptr previousSibling() override; //: Node

		/// <summary>
		/// Returns the previous element at the same node tree level
		/// </summary>
		/// <value>
		/// The previous element sibling.
		/// </value>
		std::shared_ptr<Element> previousElementSibling();

		/// <summary>
		/// Returns the first child element that matches a specified CSS selector(s) of an element
		/// </summary>
		/// <param name="selectors">The selectors.</param>
		/// <returns></returns>
		std::shared_ptr<Element> querySelector(string selectors);

		/// <summary>
		/// Returns all child elements that matches a specified CSS selector(s) of an element
		/// </summary>
		/// <param name="selectors">The selectors.</param>
		/// <returns></returns>
		NodeList<Element> querySelectorAll(string selectors);

		/// <summary>
		/// Removes a specified attribute from an element
		/// </summary>
		/// <param name="attributename">The attributename.</param>
		void removeAttribute(string attributename);

		/// <summary>
		/// Removes a specified attribute node, and returns the removed node
		/// </summary>
		/// <param name="attributenode">The attributenode.</param>
		/// <returns></returns>
		Attr::ptr removeAttributeNode(Attr::ptr attributenode);

		/// <summary>
		/// Removes a child node from an element
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns></returns>
		virtual Node::ptr removeChild(Node::ptr node) override; //: Node

		/// <summary>
		/// Removes an event handler that has been attached with the addEventListener() method
		/// </summary>
		/// <param name="event">The event.</param>
		/// <param name="function">The function.</param>
		/// <param name="useCapture">if set to <c>true</c> [use capture].</param>
		//void removeEventListener(string event, void* function, bool useCapture = false); //: EventTarget

		/// <summary>
		/// Replaces a child node in an element
		/// </summary>
		/// <param name="newnode">The newnode.</param>
		/// <param name="oldnode">The oldnode.</param>
		/// <returns></returns>
		virtual Node::ptr replaceChild(Node::ptr newnode, Node::ptr oldnode) override; //: Node

		/// <summary>
		/// Shows an element in fullscreen mode
		/// </summary>
		void requestFullscreen();

		/// <summary>
		/// Returns the entire height of an element, including padding
		/// </summary>
		/// <value>
		/// The height of the scroll.
		/// </value>
		int scrollHeight();

		/// <summary>
		/// Scrolls the specified element into the visible area of the browser window
		/// </summary>
		/// <param name="alignTo">The align to.</param>
		void scrollIntoView(bool alignTo = false);

		/// <summary>
		/// Sets or returns the number of pixels an element's content is scrolled horizontally
		/// </summary>
		/// <value>
		/// The scroll left.
		/// </value>
		int scrollLeft();
		void scrollLeft(int value);

		/// <summary>
		/// Sets or returns the number of pixels an element's content is scrolled vertically
		/// </summary>
		/// <value>
		/// The scroll top.
		/// </value>
		int scrollTop();
		void scrollTop(int value);

		/// <summary>
		/// Returns the entire width of an element, including padding
		/// </summary>
		/// <value>
		/// The width of the scroll.
		/// </value>
		int scrollWidth();

		/// <summary>
		/// Sets or changes the specified attribute, to the specified value
		/// </summary>
		/// <param name="attributename">The attributename.</param>
		/// <param name="attributevalue">The attributevalue.</param>
		void setAttribute(string attributename, string attributevalue);

		/// <summary>
		/// Sets or changes the specified attribute node
		/// </summary>
		/// <param name="attributenode">The attributenode.</param>
		/// <returns></returns>
		Attr::ptr setAttributeNode(Attr::ptr attributenode);

		/// <summary>
		/// Sets or returns the value of the style attribute of an element
		/// </summary>
		/// <value>
		/// The style.
		/// </value>
		std::unique_ptr<Style> style();

		/// <summary>
		/// Sets or returns the value of the tabindex attribute of an element
		/// </summary>
		/// <value>
		/// The index of the tab.
		/// </value>
		string tabIndex();
		void tabIndex(string value);

		/// <summary>
		/// Returns the tag name of an element
		/// </summary>
		/// <value>
		/// The name of the tag.
		/// </value>
		string tagName();

		/// <summary>
		/// Sets or returns the textual content of a node and its descendants
		/// </summary>
		/// <value>
		/// The content of the text.
		/// </value>
		virtual string textContent() override; //: Node
		virtual void textContent(string value) override; //: Node

		/// <summary>
		/// Sets or returns the value of the title attribute of an element
		/// </summary>
		/// <value>
		/// The title.
		/// </value>
		string title();
		void title(string value);

		/// <summary>
		/// Converts an element to a string
		/// </summary>
		string toString();
	};

	/// <summary>
	/// Geolocation
	/// https://www.w3schools.com/jsref/obj_geolocation.asp
	/// </summary>
	class Geolocation
	{
	public:
		typedef std::unique_ptr<Geolocation> ptr;

		/// <summary>
		/// Returns the position and altitude of the device on Earth
		/// </summary>
		/// <value>The coordinates.</value>
		/// <exception cref="NotImplementedException"></exception>
		void* coordinates();

		/// <summary>
		/// Returns the position of the concerned device at a given time
		/// </summary>
		/// <value>The position.</value>
		/// <exception cref="System.NotImplementedException"></exception>
		void* position();

		/// <summary>
		/// Returns the reason of an error occurring when using the geolocating device
		/// </summary>
		/// <value>The position error.</value>
		string positionError();

		/// <summary>
		/// Describes an object containing option properties to pass as a parameter of Geolocation.getCurrentPosition() and Geolocation.watchPosition()
		/// </summary>
		/// <value>The position options.</value>
		void* positionOptions();

		/// <summary>
		/// Unregister location/error monitoring handlers previously installed using Geolocation.watchPosition()
		/// </summary>
		/// <exception cref="System.NotImplementedException"></exception>
		void clearWatch();

		/// <summary>
		/// Returns the current position of the device
		/// </summary>
		/// <returns>System.Object.</returns>
		/// <exception cref="System.NotImplementedException"></exception>
		void* getCurrentPosition();

		/// <summary>
		/// Returns a watch ID value that then can be used to unregister the handler by passing it to the Geolocation.clearWatch() method
		/// </summary>
		/// <returns>System.Int32.</returns>
		/// <exception cref="System.NotImplementedException"></exception>
		int watchPosition();
	};

	/// <summary>
	/// History
	/// https://www.w3schools.com/jsref/obj_history.asp
	/// </summary>
	class History
	{
	public:
		typedef std::unique_ptr<History> ptr;

		/// <summary>
		/// Returns the number of URLs in the history list
		/// </summary>
		int length();

		/// <summary>
		/// Loads the previous URL in the history list
		/// </summary>
		void back();

		/// <summary>
		/// Loads the next URL in the history list
		/// </summary>
		void forward();

		/// <summary>
		/// Loads the next URL in the history list
		/// </summary>
		void go(int numberURL);
	};

	/// <summary>
	/// HTMLCollection
	/// https://www.w3schools.com/jsref/dom_obj_htmlcollection.asp
	/// </summary>
	class HTMLCollection
	{
		elements_vector _elems;
	public:
		HTMLCollection();
		HTMLCollection(elements_vector& elements);

		/// <summary>
		/// Returns the number of elements in an HTMLCollection
		/// </summary>
		/// <value>
		/// The length.
		/// </value>
		int length();

		/// <summary>
		/// Gets the <see cref="System.Object" /> with the specified index.
		/// </summary>
		/// <value>
		/// The <see cref="System.Object" />.
		/// </value>
		/// <param name="index">The index.</param>
		/// <returns></returns>
		std::shared_ptr<Element> operator[](int index);

		/// <summary>
		/// Returns the element at the specified index in an HTMLCollection
		/// </summary>
		/// <param name="index">The index.</param>
		/// <returns></returns>
		std::shared_ptr<Element> item(int index);

		/// <summary>
		/// Returns the element with the specified ID, or name, in an HTMLCollection
		/// </summary>
		/// <param name="name">The name.</param>
		/// <returns></returns>
		std::shared_ptr<Element> namedItem(string name);
	};

	/// <summary>
	/// Location
	/// https://www.w3schools.com/jsref/obj_location.asp
	/// </summary>
	class Location
	{
	public:
		typedef std::shared_ptr<Location> ptr;

		/// <summary>
		/// Sets or returns the anchor part (#) of a URL
		/// </summary>
		/// <value>
		/// The hash.
		/// </value>
		string hash();
		void hash(string value);

		/// <summary>
		/// Sets or returns the hostname and port number of a URL
		/// </summary>
		/// <value>
		/// The host.
		/// </value>
		string host();
		void host(string value);

		/// <summary>
		/// Sets or returns the hostname of a URL
		/// </summary>
		/// <value>
		/// The hostname.
		/// </value>
		string hostname();
		void hostname(string value);

		/// <summary>
		/// Sets or returns the entire URL
		/// </summary>
		/// <value>
		/// The href.
		/// </value>
		string href();
		void href(string value);

		/// <summary>
		/// Returns the protocol, hostname and port number of a URL
		/// </summary>
		/// <value>
		/// The origin.
		/// </value>
		string origin();

		/// <summary>
		/// Sets or returns the path name of a URL
		/// </summary>
		/// <value>
		/// The pathname.
		/// </value>
		string pathname();
		void pathname(string value);

		/// <summary>
		/// Sets or returns the port number of a URL
		/// </summary>
		/// <value>
		/// The port.
		/// </value>
		string port();
		void port(string value);

		/// <summary>
		/// Sets or returns the protocol of a URL
		/// </summary>
		/// <value>
		/// The protocol.
		/// </value>
		string protocol();
		void protocol(string value);

		/// <summary>
		/// Sets or returns the querystring part of a URL
		/// </summary>
		/// <value>
		/// The search.
		/// </value>
		string search();
		void search(string value);

		/// <summary>
		/// Loads a new document
		/// </summary>
		/// <param name="URL">The URL.</param>
		void assign(string URL);

		/// <summary>
		/// Reloads the current document
		/// </summary>
		/// <param name="forceGet">if set to <c>true</c> [force get].</param>
		void reload(bool forceGet = false);

		/// <summary>
		/// Replaces the current document with a new one
		/// </summary>
		/// <param name="newURL">The new URL.</param>
		void replace(string newURL);
	};

	/// <summary>
	/// MediaQueryList
	/// https://www.w3schools.com/jsref/met_win_matchmedia.asp
	/// </summary>
	class MediaQueryList
	{
	public:
		typedef std::unique_ptr<MediaQueryList> ptr;

		/// <summary>
		/// Used to check the results of a query. Returns a boolean value: true if the document matches the media query list, otherwise false
		/// </summary>
		/// <value>
		/// The matches.
		/// </value>
		void* matches();

		/// <summary>
		/// A String, representing the serialized media query list
		/// </summary>
		/// <value>
		/// The media.
		/// </value>
		string media();

		/// <summary>
		/// Adds a new listener function, which is executed whenever the media query's evaluated result changes
		/// </summary>
		/// <param name="functionref">The functionref.</param>
		/// <exception cref="NotImplementedException"></exception>
		void addListener(void* functionref);

		/// <summary>
		/// Removes a previously added listener function from the media query list. Does nothing if the specified listener is not already in the list
		/// </summary>
		/// <param name="functionref">The functionref.</param>
		/// <exception cref="NotImplementedException"></exception>
		void removeListener(void* functionref);
	};

	/// <summary>
	/// Navigator
	/// https://www.w3schools.com/jsref/obj_navigator.asp
	/// </summary>
	class Navigator
	{
	public:
		typedef std::unique_ptr<Navigator> ptr;

		/// <summary>
	    /// Returns the code name of the browser
	    /// </summary>
	    /// <value>
	    /// The name of the application code.
	    /// </value>
		string appCodeName();

		/// <summary>
		/// Returns the name of the browser
		/// </summary>
		/// <value>
		/// The name of the application.
		/// </value>
		string appName();

		/// <summary>
		/// Returns the version information of the browser
		/// </summary>
		/// <value>
		/// The application version.
		/// </value>
		string appVersion();

		/// <summary>
		/// Determines whether cookies are enabled in the browser
		/// </summary>
		/// <value>
		///   <c>true</c> if [cookie enabled]; otherwise, <c>false</c>.
		/// </value>
		bool cookieEnabled();

		/// <summary>
		/// Returns a Geolocation object that can be used to locate the user's position
		/// </summary>
		/// <value>
		/// The geolocation.
		/// </value>
		Geolocation::ptr geolocation();

		/// <summary>
		/// Returns the language of the browser
		/// </summary>
		/// <value>
		/// The language.
		/// </value>
		string language();

		/// <summary>
		/// Determines whether the browser is online
		/// </summary>
		/// <value>
		///   <c>true</c> if [on line]; otherwise, <c>false</c>.
		/// </value>
		bool onLine();

		/// <summary>
		/// Returns for which platform the browser is compiled
		/// </summary>
		/// <value>
		/// The platform.
		/// </value>
		string platform();

		/// <summary>
		/// Returns the engine name of the browser
		/// </summary>
		/// <value>
		/// The product.
		/// </value>
		string product();

		/// <summary>
		/// Returns the user-agent header sent by the browser to the server
		/// </summary>
		/// <value>
		/// The user agent.
		/// </value>
		string userAgent();

		/// <summary>
		/// Specifies whether or not the browser has Java enabled
		/// </summary>
		/// <returns></returns>
		bool javaEnabled();
	};

	/// <summary>
	/// Screen
	/// https://www.w3schools.com/jsref/obj_screen.asp
	/// </summary>
	class Screen
	{
	public:
		typedef std::unique_ptr<Screen> ptr;

		/// <summary>
		/// Returns the height of the screen (excluding the Windows Taskbar)
		/// </summary>
		/// <value>
		/// The height of the avail.
		/// </value>
		int availHeight();

		/// <summary>
		/// Returns the width of the screen (excluding the Windows Taskbar)
		/// </summary>
		/// <value>
		/// The width of the avail.
		/// </value>
		int availWidth();

		/// <summary>
		/// Returns the bit depth of the color palette for displaying images
		/// </summary>
		/// <value>
		/// The color depth.
		/// </value>
		int colorDepth();

		/// <summary>
		/// Returns the total height of the screen
		/// </summary>
		/// <value>
		/// The height.
		/// </value>
		int height();

		/// <summary>
		/// Returns the color resolution (in bits per pixel) of the screen
		/// </summary>
		/// <value>
		/// The pixel depth.
		/// </value>
		int pixelDepth();

		/// <summary>
		/// Returns the total width of the screen
		/// </summary>
		/// <value>
		/// The width.
		/// </value>
		int width();
	};

	/// <summary>
	/// Style
	/// https://www.w3schools.com/jsref/dom_obj_style.asp
	/// </summary>
	class Style
	{
	public:
		typedef std::unique_ptr<Style> ptr;

		/// <summary>
		/// Sets or returns the alignment between the lines inside a flexible container when the items do not use all available space
		/// </summary>
		/// <value>The content of the align.</value>
		string alignContent();
		void alignContent(string value);

		/// <summary>
		/// Sets or returns the alignment for items inside a flexible container
		/// </summary>
		/// <value>
		/// The align items.
		/// </value>
		string alignItems();
		void alignItems(string value);

		/// <summary>
		/// Sets or returns the alignment for selected items inside a flexible container
		/// </summary>
		/// <value>
		/// The align self.
		/// </value>
		string alignSelf();
		void alignSelf(string value);

		/// <summary>
		/// A shorthand property for all the animation properties below, except the animationPlayState property
		/// </summary>
		/// <value>
		/// The animation.
		/// </value>
		string animation();
		void animation(string value);

		/// <summary>
		/// Sets or returns when the animation will start
		/// </summary>
		/// <value>
		/// The animation delay.
		/// </value>
		string animationDelay();
		void animationDelay(string value);

		/// <summary>
		/// Sets or returns whether or not the animation should play in reverse on alternate cycles
		/// </summary>
		/// <value>
		/// The animation direction.
		/// </value>
		string animationDirection();
		void animationDirection(string value);

		/// <summary>
		/// Sets or returns how many seconds or milliseconds an animation takes to complete one cycle
		/// </summary>
		/// <value>
		/// The duration of the animation.
		/// </value>
		string animationDuration();
		void animationDuration(string value);

		/// <summary>
		/// Sets or returns what values are applied by the animation outside the time it is executing
		/// </summary>
		/// <value>
		/// The animation fill mode.
		/// </value>
		string animationFillMode();
		void animationFillMode(string value);

		/// <summary>
		/// Sets or returns the number of times an animation should be played
		/// </summary>
		/// <value>
		/// The animation iteration count.
		/// </value>
		string animationIterationCount();
		void animationIterationCount(string value);

		/// <summary>
		/// Sets or returns a name for the @keyframes animation
		/// </summary>
		/// <value>
		/// The name of the animation.
		/// </value>
		string animationName();
		void animationName(string value);

		/// <summary>
		/// Sets or returns the speed curve of the animation
		/// </summary>
		/// <value>
		/// The animation timing function.
		/// </value>
		string animationTimingFunction();
		void animationTimingFunction(string value);

		/// <summary>
		/// Sets or returns whether the animation is running or paused
		/// </summary>
		/// <value>
		/// The state of the animation play.
		/// </value>
		string animationPlayState();
		void animationPlayState(string value);

		/// <summary>
		/// Sets or returns all the background properties in one declaration
		/// </summary>
		/// <value>
		/// The background.
		/// </value>
		string background();
		void background(string value);

		/// <summary>
		/// Sets or returns whether a background-image is fixed or scrolls with the page
		/// </summary>
		/// <value>
		/// The background attachment.
		/// </value>
		string backgroundAttachment();
		void backgroundAttachment(string value);

		/// <summary>
		/// Sets or returns the background-color of an element
		/// </summary>
		/// <value>
		/// The color of the background.
		/// </value>
		string backgroundColor();
		void backgroundColor(string value);

		/// <summary>
		/// Sets or returns the background-image for an element
		/// </summary>
		/// <value>
		/// The background image.
		/// </value>
		string backgroundImage();
		void backgroundImage(string value);

		/// <summary>
		/// Sets or returns the starting position of a background-image
		/// </summary>
		/// <value>
		/// The background position.
		/// </value>
		string backgroundPosition();
		void backgroundPosition(string value);

		/// <summary>
		/// Sets or returns how to repeat (tile) a background-image
		/// </summary>
		/// <value>
		/// The background repeat.
		/// </value>
		string backgroundRepeat();
		void backgroundRepeat(string value);

		/// <summary>
		/// Sets or returns the painting area of the background
		/// </summary>
		/// <value>
		/// The background clip.
		/// </value>
		string backgroundClip();
		void backgroundClip(string value);

		/// <summary>
		/// Sets or returns the positioning area of the background images
		/// </summary>
		/// <value>
		/// The background origin.
		/// </value>
		string backgroundOrigin();
		void backgroundOrigin(string value);

		/// <summary>
		/// Sets or returns the size of the background image
		/// </summary>
		/// <value>
		/// The size of the background.
		/// </value>
		string backgroundSize();
		void backgroundSize(string value);

		/// <summary>
		/// Sets or returns whether or not an element should be visible when not facing the screen
		/// </summary>
		/// <value>
		/// The backface visibility.
		/// </value>
		string backfaceVisibility();
		void backfaceVisibility(string value);

		/// <summary>
		/// Sets or returns borderWidth, borderStyle, and borderColor in one declaration
		/// </summary>
		/// <value>
		/// The border.
		/// </value>
		string border();
		void border(string value);

		/// <summary>
		/// Sets or returns all the borderBottom properties in one declaration
		/// </summary>
		/// <value>
		/// The border bottom.
		/// </value>
		string borderBottom();
		void borderBottom(string value);

		/// <summary>
		/// Sets or returns the color of the bottom border
		/// </summary>
		/// <value>
		/// The border bottom.
		/// </value>
		string borderBottomColor();
		void borderBottomColor(string value);

		/// <summary>
		/// Sets or returns the shape of the border of the bottom-left corner
		/// </summary>
		/// <value>
		/// The border bottom.
		/// </value>
		string borderBottomLeftRadius();
		void borderBottomLeftRadius(string value);

		/// <summary>
		/// Sets or returns the shape of the border of the bottom-right corner
		/// </summary>
		/// <value>
		/// The border bottom.
		/// </value>
		string borderBottomRightRadius();
		void borderBottomRightRadius(string value);

		/// <summary>
		/// Sets or returns the style of the bottom border
		/// </summary>
		/// <value>
		/// The border bottom.
		/// </value>
		string borderBottomStyle();
		void borderBottomStyle(string value);

		/// <summary>
		/// Sets or returns the width of the bottom border
		/// </summary>
		/// <value>
		/// The border bottom.
		/// </value>
		string borderBottomWidth();
		void borderBottomWidth(string value);

		/// <summary>
		/// Sets or returns whether the table border should be collapsed into a single border, or not
		/// </summary>
		/// <value>
		/// The border collapse.
		/// </value>
		string borderCollapse();
		void borderCollapse(string value);

		/// <summary>
		/// Sets or returns the color of an element's border (can have up to four values)
		/// </summary>
		/// <value>
		/// The color of the border.
		/// </value>
		string borderColor();
		void borderColor(string value);

		/// <summary>
		/// A shorthand property for setting or returning all the borderImage properties
		/// </summary>
		/// <value>
		/// The border image.
		/// </value>
		string borderImage();
		void borderImage(string value);

		/// <summary>
		/// Sets or returns the amount by which the border image area extends beyond the border box
		/// </summary>
		/// <value>
		/// The border image outset.
		/// </value>
		string borderImageOutset();
		void borderImageOutset(string value);

		/// <summary>
		/// Sets or returns whether the image-border should be repeated, rounded or stretched
		/// </summary>
		/// <value>
		/// The border image repeat.
		/// </value>
		string borderImageRepeat();
		void borderImageRepeat(string value);

		/// <summary>
		/// Sets or returns the inward offsets of the image-border
		/// </summary>
		/// <value>
		/// The border image slice.
		/// </value>
		string borderImageSlice();
		void borderImageSlice(string value);

		/// <summary>
		/// Sets or returns the image to be used as a border
		/// </summary>
		/// <value>
		/// The border image source.
		/// </value>
		string borderImageSource();
		void borderImageSource(string value);

		/// <summary>
		/// Sets or returns the widths of the image-border
		/// </summary>
		/// <value>
		/// The width of the border image.
		/// </value>
		string borderImageWidth();
		void borderImageWidth(string value);

		/// <summary>
		/// Sets or returns all the borderLeft properties in one declaration
		/// </summary>
		/// <value>
		/// The border left.
		/// </value>
		string borderLeft();
		void borderLeft(string value);

		/// <summary>
		/// Sets or returns the color of the left border
		/// </summary>
		/// <value>
		/// The color of the border left.
		/// </value>
		string borderLeftColor();
		void borderLeftColor(string value);

		/// <summary>
		/// Sets or returns the style of the left border
		/// </summary>
		/// <value>
		/// The border left style.
		/// </value>
		string borderLeftStyle();
		void borderLeftStyle(string value);

		/// <summary>
		/// Sets or returns the width of the left border
		/// </summary>
		/// <value>
		/// The width of the border left.
		/// </value>
		string borderLeftWidth();
		void borderLeftWidth(string value);

		/// <summary>
		/// A shorthand property for setting or returning all the four borderRadius properties
		/// </summary>
		/// <value>
		/// The border radius.
		/// </value>
		string borderRadius();
		void borderRadius(string value);

		/// <summary>
		/// Sets or returns all the borderRight properties in one declaration
		/// </summary>
		/// <value>
		/// The border right.
		/// </value>
		string borderRight();
		void borderRight(string value);

		/// <summary>
		/// Sets or returns the color of the right border
		/// </summary>
		/// <value>
		/// The color of the border right.
		/// </value>
		string borderRightColor();
		void borderRightColor(string value);

		/// <summary>
		/// Sets or returns the style of the right border
		/// </summary>
		/// <value>
		/// The border right style.
		/// </value>
		string borderRightStyle();
		void borderRightStyle(string value);

		/// <summary>
		/// Sets or returns the width of the right border
		/// </summary>
		/// <value>
		/// The width of the border right.
		/// </value>
		string borderRightWidth();
		void borderRightWidth(string value);

		/// <summary>
		/// Sets or returns the space between cells in a table
		/// </summary>
		/// <value>
		/// The border spacing.
		/// </value>
		string borderSpacing();
		void borderSpacing(string value);

		/// <summary>
		/// Sets or returns the style of an element's border (can have up to four values)
		/// </summary>
		/// <value>
		/// The border style.
		/// </value>
		string borderStyle();
		void borderStyle(string value);

		/// <summary>
		/// Sets or returns all the borderTop properties in one declaration
		/// </summary>
		/// <value>
		/// The border top.
		/// </value>
		string borderTop();
		void borderTop(string value);

		/// <summary>
		/// Sets or returns the color of the top border
		/// </summary>
		/// <value>
		/// The color of the border top.
		/// </value>
		string borderTopColor();
		void borderTopColor(string value);

		/// <summary>
		/// Sets or returns the shape of the border of the top-left corner
		/// </summary>
		/// <value>
		/// The border top left radius.
		/// </value>
		string borderTopLeftRadius();
		void borderTopLeftRadius(string value);

		/// <summary>
		/// Sets or returns the shape of the border of the top-right corner
		/// </summary>
		/// <value>
		/// The border top right radius.
		/// </value>
		string borderTopRightRadius();
		void borderTopRightRadius(string value);

		/// <summary>
		/// Sets or returns the style of the top border
		/// </summary>
		/// <value>
		/// The border top style.
		/// </value>
		string borderTopStyle();
		void borderTopStyle(string value);

		/// <summary>
		/// Sets or returns the width of the top border
		/// </summary>
		/// <value>
		/// The width of the border top.
		/// </value>
		string borderTopWidth();
		void borderTopWidth(string value);

		/// <summary>
		/// Sets or returns the width of an element's border (can have up to four values)
		/// </summary>
		/// <value>
		/// The width of the border.
		/// </value>
		string borderWidth();
		void borderWidth(string value);

		/// <summary>
		/// Sets or returns the bottom position of a positioned element
		/// </summary>
		/// <value>
		/// The bottom.
		/// </value>
		string bottom();
		void bottom(string value);

		/// <summary>
		/// Sets or returns the behaviour of the background and border of an element at page-break, or, for in-line elements, at line-break.
		/// </summary>
		/// <value>
		/// The box decoration break.
		/// </value>
		string boxDecorationBreak();
		void boxDecorationBreak(string value);

		/// <summary>
		/// Attaches one or more drop-shadows to the box
		/// </summary>
		/// <value>
		/// The box shadow.
		/// </value>
		string boxShadow();
		void boxShadow(string value);

		/// <summary>
		/// Allows you to define certain elements to fit an area in a certain way
		/// </summary>
		/// <value>
		/// The box sizing.
		/// </value>
		string boxSizing();
		void boxSizing(string value);

		/// <summary>
		/// Sets or returns the position of the table caption
		/// </summary>
		/// <value>
		/// The caption side.
		/// </value>
		string captionSide();
		void captionSide(string value);

		/// <summary>
		/// Sets or returns the position of the element relative to floating objects
		/// </summary>
		/// <value>
		/// The clear.
		/// </value>
		string clear();
		void clear(string value);

		/// <summary>
		/// Sets or returns which part of a positioned element is visible
		/// </summary>
		/// <value>
		/// The clip.
		/// </value>
		string clip();
		void clip(string value);

		/// <summary>
		/// Sets or returns the color of the text
		/// </summary>
		/// <value>
		/// The color.
		/// </value>
		string color();
		void color(string value);

		/// <summary>
		/// Sets or returns the number of columns an element should be divided into
		/// </summary>
		/// <value>
		/// The column count.
		/// </value>
		string columnCount();
		void columnCount(string value);

		/// <summary>
		/// Sets or returns how to fill columns
		/// </summary>
		/// <value>
		/// The column fill.
		/// </value>
		string columnFill();
		void columnFill(string value);

		/// <summary>
		/// Sets or returns the gap between the columns
		/// </summary>
		/// <value>
		/// The column gap.
		/// </value>
		string columnGap();
		void columnGap(string value);

		/// <summary>
		/// A shorthand property for setting or returning all the columnRule properties
		/// </summary>
		/// <value>
		/// The column rule.
		/// </value>
		string columnRule();
		void columnRule(string value);

		/// <summary>
		/// Sets or returns the color of the rule between columns
		/// </summary>
		/// <value>
		/// The color of the column rule.
		/// </value>
		string columnRuleColor();
		void columnRuleColor(string value);

		/// <summary>
		/// Sets or returns the style of the rule between columns
		/// </summary>
		/// <value>
		/// The column rule style.
		/// </value>
		string columnRuleStyle();
		void columnRuleStyle(string value);

		/// <summary>
		/// Sets or returns the width of the rule between columns
		/// </summary>
		/// <value>
		/// The width of the column rule.
		/// </value>
		string columnRuleWidth();
		void columnRuleWidth(string value);

		/// <summary>
		/// A shorthand property for setting or returning columnWidth and columnCount
		/// </summary>
		/// <value>
		/// The columns.
		/// </value>
		string columns();
		void columns(string value);

		/// <summary>
		/// Sets or returns how many columns an element should span across
		/// </summary>
		/// <value>
		/// The column span.
		/// </value>
		string columnSpan();
		void columnSpan(string value);

		/// <summary>
		/// Sets or returns the width of the columns
		/// </summary>
		/// <value>
		/// The width of the column.
		/// </value>
		string columnWidth();
		void columnWidth(string value);

		/// <summary>
		/// Used with the :before and :after pseudo-elements, to insert generated content
		/// </summary>
		/// <value>
		/// The content.
		/// </value>
		string content();
		void content(string value);

		/// <summary>
		/// Increments one or more counters
		/// </summary>
		/// <value>
		/// The counter increment.
		/// </value>
		string counterIncrement();
		void counterIncrement(string value);

		/// <summary>
		/// Creates or resets one or more counters
		/// </summary>
		/// <value>
		/// The counter reset.
		/// </value>
		string counterReset();
		void counterReset(string value);

		/// <summary>
		/// Sets or returns the type of cursor to display for the mouse pointer
		/// </summary>
		/// <value>
		/// The cursor.
		/// </value>
		string cursor();
		void cursor(string value);

		/// <summary>
		/// Sets or returns the text direction
		/// </summary>
		/// <value>
		/// The direction.
		/// </value>
		string direction();
		void direction(string value);

		/// <summary>
		/// Sets or returns an element's display type
		/// </summary>
		/// <value>
		/// The display.
		/// </value>
		string display();
		void display(string value);

		/// <summary>
		/// Sets or returns whether to show the border and background of empty cells, or not
		/// </summary>
		/// <value>
		/// The empty cells.
		/// </value>
		string emptyCells();
		void emptyCells(string value);

		/// <summary>
		/// Sets or returns image filters (visual effects, like blur and saturation)
		/// </summary>
		/// <value>
		/// The filter.
		/// </value>
		string filter();
		void filter(string value);

		/// <summary>
		/// Sets or returns the length of the item, relative to the rest
		/// </summary>
		/// <value>
		/// The flex.
		/// </value>
		string flex();
		void flex(string value);

		/// <summary>
		/// Sets or returns the initial length of a flexible item
		/// </summary>
		/// <value>
		/// The flex basis.
		/// </value>
		string flexBasis();
		void flexBasis(string value);

		/// <summary>
		/// Sets or returns the direction of the flexible items
		/// </summary>
		/// <value>
		/// The flex direction.
		/// </value>
		string flexDirection();
		void flexDirection(string value);

		/// <summary>
		/// A shorthand property for the flexDirection and the flexWrap properties
		/// </summary>
		/// <value>
		/// The flex flow.
		/// </value>
		string flexFlow();
		void flexFlow(string value);

		/// <summary>
		/// Sets or returns how much the item will grow relative to the rest
		/// </summary>
		/// <value>
		/// The flex grow.
		/// </value>
		string flexGrow();
		void flexGrow(string value);

		/// <summary>
		/// Sets or returns how the item will shrink relative to the rest
		/// </summary>
		/// <value>
		/// The flex shrink.
		/// </value>
		string flexShrink();
		void flexShrink(string value);

		/// <summary>
		/// Sets or returns whether the flexible items should wrap or not
		/// </summary>
		/// <value>
		/// The flex wrap.
		/// </value>
		string flexWrap();
		void flexWrap(string value);

		/// <summary>
		/// Sets or returns the horizontal alignment of an element
		/// </summary>
		/// <value>
		/// The CSS float.
		/// </value>
		string cssFloat();
		void cssFloat(string value);

		/// <summary>
		/// Sets or returns fontStyle, fontVariant, fontWeight, fontSize, lineHeight, and fontFamily in one declaration
		/// </summary>
		/// <value>
		/// The font.
		/// </value>
		string font();
		void font(string value);

		/// <summary>
		/// Sets or returns the font family for text
		/// </summary>
		/// <value>
		/// The font family.
		/// </value>
		string fontFamily();
		void fontFamily(string value);

		/// <summary>
		/// Sets or returns the font size of the text
		/// </summary>
		/// <value>
		/// The size of the font.
		/// </value>
		string fontSize();
		void fontSize(string value);

		/// <summary>
		/// Sets or returns whether the style of the font is normal, italic or oblique
		/// </summary>
		/// <value>
		/// The font style.
		/// </value>
		string fontStyle();
		void fontStyle(string value);

		/// <summary>
		/// Sets or returns whether the font should be displayed in small capital letters
		/// </summary>
		/// <value>
		/// The font variant.
		/// </value>
		string fontVariant();
		void fontVariant(string value);

		/// <summary>
		/// Sets or returns the boldness of the font
		/// </summary>
		/// <value>
		/// The font weight.
		/// </value>
		string fontWeight();
		void fontWeight(string value);

		/// <summary>
		/// Preserves the readability of text when font fallback occurs
		/// </summary>
		/// <value>
		/// The font size adjust.
		/// </value>
		string fontSizeAdjust();
		void fontSizeAdjust(string value);

		/// <summary>
		/// Selects a normal, condensed, or expanded face from a font family
		/// </summary>
		/// <value>
		/// The font stretch.
		/// </value>
		string fontStretch();
		void fontStretch(string value);

		/// <summary>
		/// Specifies whether a punctuation character may be placed outside the line box
		/// </summary>
		/// <value>
		/// The hanging punctuation.
		/// </value>
		string hangingPunctuation();
		void hangingPunctuation(string value);

		/// <summary>
		/// Sets or returns the height of an element
		/// </summary>
		/// <value>
		/// The height.
		/// </value>
		string height();
		void height(string value);

		/// <summary>
		/// Sets how to split words to improve the layout of paragraphs
		/// </summary>
		/// <value>
		/// The hyphens.
		/// </value>
		string hyphens();
		void hyphens(string value);

		/// <summary>
		/// Provides the author the ability to style an element with an iconic equivalent
		/// </summary>
		/// <value>
		/// The icon.
		/// </value>
		string icon();
		void icon(string value);

		/// <summary>
		/// Specifies a rotation in the right or clockwise direction that a user agent applies to an image
		/// </summary>
		/// <value>
		/// The image orientation.
		/// </value>
		string imageOrientation();
		void imageOrientation(string value);

		/// <summary>
		/// Defines whether an element must create a new stacking content
		/// </summary>
		/// <value>
		/// The isolation.
		/// </value>
		string isolation();
		void isolation(string value);

		/// <summary>
		/// Sets or returns the alignment between the items inside a flexible container when the items do not use all available space.
		/// </summary>
		/// <value>
		/// The content of the justify.
		/// </value>
		string justifyContent();
		void justifyContent(string value);

		/// <summary>
		/// Sets or returns the left position of a positioned element
		/// </summary>
		/// <value>
		/// The left.
		/// </value>
		string left();
		void left(string value);

		/// <summary>
		/// Sets or returns the space between characters in a text
		/// </summary>
		/// <value>
		/// The letter spacing.
		/// </value>
		string letterSpacing();
		void letterSpacing(string value);

		/// <summary>
		/// Sets or returns the distance between lines in a text
		/// </summary>
		/// <value>
		/// The height of the line.
		/// </value>
		string lineHeight();
		void lineHeight(string value);

		/// <summary>
		/// Sets or returns listStyleImage, listStylePosition, and listStyleType in one declaration
		/// </summary>
		/// <value>
		/// The list style.
		/// </value>
		string listStyle();
		void listStyle(string value);

		/// <summary>
		/// Sets or returns an image as the list-item marker
		/// </summary>
		/// <value>
		/// The list style image.
		/// </value>
		string listStyleImage();
		void listStyleImage(string value);

		/// <summary>
		/// Sets or returns the position of the list-item marker
		/// </summary>
		/// <value>
		/// The list style position.
		/// </value>
		string listStylePosition();
		void listStylePosition(string value);

		/// <summary>
		/// Sets or returns the list-item marker type
		/// </summary>
		/// <value>
		/// The type of the list style.
		/// </value>
		string listStyleType();
		void listStyleType(string value);

		/// <summary>
		/// Sets or returns the margins of an element (can have up to four values)
		/// </summary>
		/// <value>
		/// The margin.
		/// </value>
		string margin();
		void margin(string value);

		/// <summary>
		/// Sets or returns the bottom margin of an element
		/// </summary>
		/// <value>
		/// The margin bottom.
		/// </value>
		string marginBottom();
		void marginBottom(string value);

		/// <summary>
		/// Sets or returns the left margin of an element
		/// </summary>
		/// <value>
		/// The margin left.
		/// </value>
		string marginLeft();
		void marginLeft(string value);

		/// <summary>
		/// Sets or returns the right margin of an element
		/// </summary>
		/// <value>
		/// The margin right.
		/// </value>
		string marginRight();
		void marginRight(string value);

		/// <summary>
		/// Sets or returns the top margin of an element
		/// </summary>
		/// <value>
		/// The margin top.
		/// </value>
		string marginTop();
		void marginTop(string value);

		/// <summary>
		/// Sets or returns the maximum height of an element
		/// </summary>
		/// <value>
		/// The maximum height.
		/// </value>
		string maxHeight();
		void maxHeight(string value);

		/// <summary>
		/// Sets or returns the maximum width of an element
		/// </summary>
		/// <value>
		/// The maximum width.
		/// </value>
		string maxWidth();
		void maxWidth(string value);

		/// <summary>
		/// Sets or returns the minimum height of an element
		/// </summary>
		/// <value>
		/// The minimum height.
		/// </value>
		string minHeight();
		void minHeight(string value);

		/// <summary>
		/// Sets or returns the minimum width of an element
		/// </summary>
		/// <value>
		/// The minimum width.
		/// </value>
		string minWidth();
		void minWidth(string value);

		/// <summary>
		/// Sets or returns where to navigate when using the arrow-down navigation key
		/// </summary>
		/// <value>
		/// The nav down.
		/// </value>
		string navDown();
		void navDown(string value);

		/// <summary>
		/// Sets or returns the tabbing order for an element
		/// </summary>
		/// <value>
		/// The index of the nav.
		/// </value>
		string navIndex();
		void navIndex(string value);

		/// <summary>
		/// Sets or returns where to navigate when using the arrow-left navigation key
		/// </summary>
		/// <value>
		/// The nav left.
		/// </value>
		string navLeft();
		void navLeft(string value);

		/// <summary>
		/// Sets or returns where to navigate when using the arrow-right navigation key
		/// </summary>
		/// <value>
		/// The nav right.
		/// </value>
		string navRight();
		void navRight(string value);

		/// <summary>
		/// Sets or returns where to navigate when using the arrow-up navigation key
		/// </summary>
		/// <value>
		/// The nav up.
		/// </value>
		string navUp();
		void navUp(string value);

		/// <summary>
		/// Specifies how the contents of a replaced element should be fitted to the box established by its used height and width
		/// </summary>
		/// <value>
		/// The object fit.
		/// </value>
		string objectFit();
		void objectFit(string value);

		/// <summary>
		/// Specifies the alignment of the replaced element inside its box
		/// </summary>
		/// <value>
		/// The object position.
		/// </value>
		string objectPosition();
		void objectPosition(string value);

		/// <summary>
		/// Sets or returns the opacity level for an element
		/// </summary>
		/// <value>
		/// The opacity.
		/// </value>
		string opacity();
		void opacity(string value);

		/// <summary>
		/// Sets or returns the order of the flexible item, relative to the rest
		/// </summary>
		/// <value>
		/// The order.
		/// </value>
		string order();
		void order(string value);

		/// <summary>
		/// Sets or returns the minimum number of lines for an element that must be left at the bottom of a page when a page break occurs inside an element
		/// </summary>
		/// <value>
		/// The orphans.
		/// </value>
		string orphans();
		void orphans(string value);

		/// <summary>
		/// Sets or returns all the outline properties in one declaration
		/// </summary>
		/// <value>
		/// The outline.
		/// </value>
		string outline();
		void outline(string value);

		/// <summary>
		/// Sets or returns the color of the outline around a element
		/// </summary>
		/// <value>
		/// The color of the outline.
		/// </value>
		string outlineColor();
		void outlineColor(string value);

		/// <summary>
		/// Offsets an outline, and draws it beyond the border edge
		/// </summary>
		/// <value>
		/// The outline offset.
		/// </value>
		string outlineOffset();
		void outlineOffset(string value);

		/// <summary>
		/// Sets or returns the style of the outline around an element
		/// </summary>
		/// <value>
		/// The outline style.
		/// </value>
		string outlineStyle();
		void outlineStyle(string value);

		/// <summary>
		/// Sets or returns the width of the outline around an element
		/// </summary>
		/// <value>
		/// The width of the outline.
		/// </value>
		string outlineWidth();
		void outlineWidth(string value);

		/// <summary>
		/// Sets or returns what to do with content that renders outside the element box
		/// </summary>
		/// <value>
		/// The overflow.
		/// </value>
		string overflow();
		void overflow(string value);

		/// <summary>
		/// Specifies what to do with the left/right edges of the content, if it overflows the element's content area
		/// </summary>
		/// <value>
		/// The overflow x.
		/// </value>
		string overflowX();
		void overflowX(string value);

		/// <summary>
		/// Specifies what to do with the top/bottom edges of the content, if it overflows the element's content area
		/// </summary>
		/// <value>
		/// The overflow y.
		/// </value>
		string overflowY();
		void overflowY(string value);

		/// <summary>
		/// Sets or returns the padding of an element (can have up to four values)
		/// </summary>
		/// <value>
		/// The padding.
		/// </value>
		string padding();
		void padding(string value);

		/// <summary>
		/// Sets or returns the bottom padding of an element
		/// </summary>
		/// <value>
		/// The padding bottom.
		/// </value>
		string paddingBottom();
		void paddingBottom(string value);

		/// <summary>
		/// Sets or returns the left padding of an element
		/// </summary>
		/// <value>
		/// The padding left.
		/// </value>
		string paddingLeft();
		void paddingLeft(string value);

		/// <summary>
		/// Sets or returns the right padding of an element
		/// </summary>
		/// <value>
		/// The padding right.
		/// </value>
		string paddingRight();
		void paddingRight(string value);

		/// <summary>
		/// Sets or returns the top padding of an element
		/// </summary>
		/// <value>
		/// The padding top.
		/// </value>
		string paddingTop();
		void paddingTop(string value);

		/// <summary>
		/// Sets or returns the page-break behavior after an element
		/// </summary>
		/// <value>
		/// The page break after.
		/// </value>
		string pageBreakAfter();
		void pageBreakAfter(string value);

		/// <summary>
		/// Sets or returns the page-break behavior before an element
		/// </summary>
		/// <value>
		/// The page break before.
		/// </value>
		string pageBreakBefore();
		void pageBreakBefore(string value);

		/// <summary>
		/// Sets or returns the page-break behavior inside an element
		/// </summary>
		/// <value>
		/// The page break inside.
		/// </value>
		string pageBreakInside();
		void pageBreakInside(string value);

		/// <summary>
		/// Sets or returns the perspective on how 3D elements are viewed
		/// </summary>
		/// <value>
		/// The perspective.
		/// </value>
		string perspective();
		void perspective(string value);

		/// <summary>
		/// Sets or returns the bottom position of 3D elements
		/// </summary>
		/// <value>
		/// The perspective origin.
		/// </value>
		string perspectiveOrigin();
		void perspectiveOrigin(string value);

		/// <summary>
		/// Sets or returns the type of positioning method used for an element (static, relative, absolute or fixed)
		/// </summary>
		/// <value>
		/// The position.
		/// </value>
		string position();
		void position(string value);

		/// <summary>
		/// Sets or returns the type of quotation marks for embedded quotations
		/// </summary>
		/// <value>
		/// The quotes.
		/// </value>
		string quotes();
		void quotes(string value);

		/// <summary>
		/// Sets or returns whether or not an element is resizable by the user
		/// </summary>
		/// <value>
		/// The resize.
		/// </value>
		string resize();
		void resize(string value);

		/// <summary>
		/// Sets or returns the right position of a positioned element
		/// </summary>
		/// <value>
		/// The right.
		/// </value>
		string right();
		void right(string value);

		/// <summary>
		/// Sets or returns the way to lay out table cells, rows, and columns
		/// </summary>
		/// <value>
		/// The table layout.
		/// </value>
		string tableLayout();
		void tableLayout(string value);

		/// <summary>
		/// Sets or returns the length of the tab-character
		/// </summary>
		/// <value>
		/// The size of the tab.
		/// </value>
		string tabSize();
		void tabSize(string value);

		/// <summary>
		/// Sets or returns the horizontal alignment of text
		/// </summary>
		/// <value>
		/// The text align.
		/// </value>
		string textAlign();
		void textAlign(string value);

		/// <summary>
		/// Sets or returns how the last line of a block or a line right before a forced line break is aligned when text-align is "justify"
		/// </summary>
		/// <value>
		/// The text align last.
		/// </value>
		string textAlignLast();
		void textAlignLast(string value);

		/// <summary>
		/// Sets or returns the decoration of a text
		/// </summary>
		/// <value>
		/// The text decoration.
		/// </value>
		string textDecoration();
		void textDecoration(string value);

		/// <summary>
		/// Sets or returns the color of the text-decoration
		/// </summary>
		/// <value>
		/// The color of the text decoration.
		/// </value>
		string textDecorationColor();
		void textDecorationColor(string value);

		/// <summary>
		/// Sets or returns the type of line in a text-decoration
		/// </summary>
		/// <value>
		/// The text decoration line.
		/// </value>
		string textDecorationLine();
		void textDecorationLine(string value);

		/// <summary>
		/// Sets or returns the style of the line in a text decoration
		/// </summary>
		/// <value>
		/// The text decoration style.
		/// </value>
		string textDecorationStyle();
		void textDecorationStyle(string value);

		/// <summary>
		/// Sets or returns the indentation of the first line of text
		/// </summary>
		/// <value>
		/// The text indent.
		/// </value>
		string textIndent();
		void textIndent(string value);

		/// <summary>
		/// Sets or returns the justification method used when text-align is "justify"
		/// </summary>
		/// <value>
		/// The text justify.
		/// </value>
		string textJustify();
		void textJustify(string value);

		/// <summary>
		/// Sets or returns what should happen when text overflows the containing element
		/// </summary>
		/// <value>
		/// The text overflow.
		/// </value>
		string textOverflow();
		void textOverflow(string value);

		/// <summary>
		/// Sets or returns the shadow effect of a text
		/// </summary>
		/// <value>
		/// The text shadow.
		/// </value>
		string textShadow();
		void textShadow(string value);

		/// <summary>
		/// Sets or returns the capitalization of a text
		/// </summary>
		/// <value>
		/// The text transform.
		/// </value>
		string textTransform();
		void textTransform(string value);

		/// <summary>
		/// Sets or returns the top position of a positioned element
		/// </summary>
		/// <value>
		/// The top.
		/// </value>
		string top();
		void top(string value);

		/// <summary>
		/// Applies a 2D or 3D transformation to an element
		/// </summary>
		/// <value>
		/// The transform.
		/// </value>
		string transform();
		void transform(string value);

		/// <summary>
		/// Sets or returns the position of transformed elements
		/// </summary>
		/// <value>
		/// The transform origin.
		/// </value>
		string transformOrigin();
		void transformOrigin(string value);

		/// <summary>
		/// Sets or returns how nested elements are rendered in 3D space
		/// </summary>
		/// <value>
		/// The transform style.
		/// </value>
		string transformStyle();
		void transformStyle(string value);

		/// <summary>
		/// A shorthand property for setting or returning the four transition properties
		/// </summary>
		/// <value>
		/// The transition.
		/// </value>
		string transition();
		void transition(string value);

		/// <summary>
		/// Sets or returns the CSS property that the transition effect is for
		/// </summary>
		/// <value>
		/// The transition property.
		/// </value>
		string transitionProperty();
		void transitionProperty(string value);

		/// <summary>
		/// Sets or returns how many seconds or milliseconds a transition effect takes to complete
		/// </summary>
		/// <value>
		/// The duration of the transition.
		/// </value>
		string transitionDuration();
		void transitionDuration(string value);

		/// <summary>
		/// Sets or returns the speed curve of the transition effect
		/// </summary>
		/// <value>
		/// The transition timing function.
		/// </value>
		string transitionTimingFunction();
		void transitionTimingFunction(string value);

		/// <summary>
		/// Sets or returns when the transition effect will start
		/// </summary>
		/// <value>
		/// The transition delay.
		/// </value>
		string transitionDelay();
		void transitionDelay(string value);

		/// <summary>
		/// Sets or returns whether the text should be overridden to support multiple languages in the same document
		/// </summary>
		/// <value>
		/// The unicode bidi.
		/// </value>
		string unicodeBidi();
		void unicodeBidi(string value);

		/// <summary>
		/// Sets or returns whether the text of an element can be selected or not
		/// </summary>
		/// <value>
		/// The user select.
		/// </value>
		string userSelect();
		void userSelect(string value);

		/// <summary>
		/// Sets or returns the vertical alignment of the content in an element
		/// </summary>
		/// <value>
		/// The vertical align.
		/// </value>
		string verticalAlign();
		void verticalAlign(string value);

		/// <summary>
		/// Sets or returns whether an element should be visible
		/// </summary>
		/// <value>
		/// The visibility.
		/// </value>
		string visibility();
		void visibility(string value);

		/// <summary>
		/// Sets or returns how to handle tabs, line breaks and whitespace in a text
		/// </summary>
		/// <value>
		/// The white space.
		/// </value>
		string whiteSpace();
		void whiteSpace(string value);

		/// <summary>
		/// Sets or returns the width of an element
		/// </summary>
		/// <value>
		/// The width.
		/// </value>
		string width();
		void width(string value);

		/// <summary>
		/// Sets or returns line breaking rules for non-CJK scripts
		/// </summary>
		/// <value>
		/// The word break.
		/// </value>
		string wordBreak();
		void wordBreak(string value);

		/// <summary>
		/// Sets or returns the spacing between words in a text
		/// </summary>
		/// <value>
		/// The word spacing.
		/// </value>
		string wordSpacing();
		void wordSpacing(string value);

		/// <summary>
		/// Allows long, unbreakable words to be broken and wrap to the next line
		/// </summary>
		/// <value>
		/// The word wrap.
		/// </value>
		string wordWrap();
		void wordWrap(string value);

		/// <summary>
		/// Sets or returns the minimum number of lines for an element that must be visible at the top of a page
		/// </summary>
		/// <value>
		/// The widows.
		/// </value>
		string widows();
		void widows(string value);

		/// <summary>
		/// Sets or returns the stack order of a positioned element
		/// </summary>
		/// <value>
		/// The index of the z.
		/// </value>
		string zIndex();
		void zIndex(string value);
	};

	/// <summary>
	/// Window
	/// https://www.w3schools.com/jsref/obj_window.asp
	/// </summary>
	class Window : public EventTarget
	{
	public:
		typedef std::shared_ptr<Window> ptr;
		Window();
		//Window(std::shared_ptr<document> doc);

		/// <summary>
		/// Returns a Boolean value indicating whether a window has been closed or not
		/// </summary>
		/// <value>
		///   <c>true</c> if closed; otherwise, <c>false</c>.
		/// </value>
		bool closed();

		/// <summary>
		/// Returns a reference to the Console object, which provides methods for logging information to the browser's console (See Console object)
		/// </summary>
		/// <value>
		/// The console.
		/// </value>
		Console::ptr console();

		/// <summary>
		/// Sets or returns the default text in the statusbar of a window
		/// </summary>
		/// <value>
		/// The default status.
		/// </value>
		string defaultStatus();
		void defaultStatus(string value);

		/// <summary>
		/// Returns the Document object for the window (See Document object)
		/// </summary>
		/// <value>
		/// The document.
		/// </value>
		Document::ptr document();

		/// <summary>
		/// Returns the <iframe> element in which the current window is inserted
		/// </summary>
		/// <value>
		/// The frame element.
		/// </value>
		std::shared_ptr<Element> frameElement();

		/// <summary>
		/// Returns all <iframe> elements in the current window
		/// </summary>
		/// <value>
		/// The frames.
		/// </value>
		std::vector<std::shared_ptr<Element>> frames();

		/// <summary>
		/// Returns the History object for the window (See History object)
		/// </summary>
		/// <value>
		/// The history.
		/// </value>
		History::ptr history();

		/// <summary>
		/// Returns the height of the window's content area (viewport) including scrollbars
		/// </summary>
		/// <value>
		/// The height of the inner.
		/// </value>
		int innerHeight();

		/// <summary>
		/// Returns the width of a window's content area (viewport) including scrollbars
		/// </summary>
		/// <value>
		/// The width of the inner.
		/// </value>
		int innerWidth();

		/// <summary>
		/// Returns the number of <iframe> elements in the current window
		/// </summary>
		/// <value>
		/// The length.
		/// </value>
		int length();

		/// <summary>
		/// Allows to save key/value pairs in a web browser. Stores the data with no expiration date
		/// </summary>
		/// <value>
		/// The local storage.
		/// </value>
		std::unique_ptr<Storage> localStorage();

		/// <summary>
		/// Returns the Location object for the window (See Location object)
		/// </summary>
		/// <value>
		/// The location.
		/// </value>
		Location::ptr location();

		/// <summary>
		/// Sets or returns the name of a window
		/// </summary>
		/// <value>
		/// The name.
		/// </value>
		string name();
		void name(string value);

		/// <summary>
		/// Returns the Navigator object for the window (See Navigator object)
		/// </summary>
		/// <value>
		/// The navigator.
		/// </value>
		Navigator::ptr navigator();

		/// <summary>
		/// Returns a reference to the window that created the window
		/// </summary>
		/// <value>
		/// The opener.
		/// </value>
		Window::ptr opener();

		/// <summary>
		/// Returns the height of the browser window, including toolbars/scrollbars
		/// </summary>
		/// <value>
		/// The height of the outer.
		/// </value>
		int outerHeight();

		/// <summary>
		/// Returns the width of the browser window, including toolbars/scrollbars
		/// </summary>
		/// <value>
		/// The width of the outer.
		/// </value>
		int outerWidth();

		/// <summary>
		/// Returns the pixels the current document has been scrolled (horizontally) from the upper left corner of the window
		/// </summary>
		/// <value>
		/// The page x offset.
		/// </value>
		int pageXOffset();

		/// <summary>
		/// Returns the pixels the current document has been scrolled (vertically) from the upper left corner of the window
		/// </summary>
		/// <value>
		/// The page y offset.
		/// </value>
		int pageYOffset();

		/// <summary>
		/// Returns the parent window of the current window
		/// </summary>
		/// <value>
		/// The parent.
		/// </value>
		Window::ptr parent();

		/// <summary>
		/// Returns the Screen object for the window (See Screen object)
		/// </summary>
		/// <value>
		/// The screen.
		/// </value>
		Screen::ptr screen();

		/// <summary>
		/// Returns the horizontal coordinate of the window relative to the screen
		/// </summary>
		/// <value>
		/// The screen left.
		/// </value>
		int screenLeft();

		/// <summary>
		/// Returns the vertical coordinate of the window relative to the screen
		/// </summary>
		/// <value>
		/// The screen top.
		/// </value>
		int screenTop();

		/// <summary>
		/// Returns the horizontal coordinate of the window relative to the screen
		/// </summary>
		/// <value>
		/// The screen x.
		/// </value>
		int screenX();

		/// <summary>
		/// Returns the vertical coordinate of the window relative to the screen
		/// </summary>
		/// <value>
		/// The screen y.
		/// </value>
		int screenY();

		/// <summary>
		/// Allows to save key/value pairs in a web browser. Stores the data for one session
		/// </summary>
		/// <value>
		/// The session storage.
		/// </value>
		std::unique_ptr<Storage> sessionStorage();

		/// <summary>
		/// An alias of pageXOffset
		/// </summary>
		/// <value>
		/// The scroll x.
		/// </value>
		int scrollX();

		/// <summary>
		/// An alias of pageYOffset
		/// </summary>
		/// <value>
		/// The scroll y.
		/// </value>
		int scrollY();

		/// <summary>
		/// Returns the current window
		/// </summary>
		/// <value>
		/// The self.
		/// </value>
		Window::ptr self();

		/// <summary>
		/// Sets or returns the text in the statusbar of a window
		/// </summary>
		/// <value>
		/// The status.
		/// </value>
		string status();
		void status(string value);

		/// <summary>
		/// Returns the topmost browser window
		/// </summary>
		/// <value>
		/// The top.
		/// </value>
		Window::ptr top();

		/// <summary>
		/// Displays an alert box with a message and an OK button
		/// </summary>
		/// <param name="message">The message.</param>
		void alert(string message);

		/// <summary>
		/// Decodes a base-64 encoded string
		/// </summary>
		/// <param name="encodedStr">The encoded string.</param>
		/// <returns></returns>
		string atob(string encodedStr);

		/// <summary>
		/// Removes focus from the current window
		/// </summary>
		void blur();

		/// <summary>
		/// Encodes a string in base-64
		/// </summary>
		/// <param name="str">The string.</param>
		/// <returns></returns>
		string btoa(string str);

		/// <summary>
		/// Clears a timer set with setInterval()
		/// </summary>
		/// <param name="var">The variable.</param>
		void clearInterval(string var);

		/// <summary>
		/// Clears a timer set with setTimeout()
		/// </summary>
		/// <param name="id_of_settimeout">The identifier of settimeout.</param>
		void clearTimeout(string id_of_settimeout);

		/// <summary>
		/// Closes the current window
		/// </summary>
		void close();

		/// <summary>
		/// Displays a dialog box with a message and an OK and a Cancel button
		/// </summary>
		/// <param name="message">The message.</param>
		/// <returns></returns>
		bool confirm(string message);

		/// <summary>
		/// Sets focus to the current window
		/// </summary>
		void focus();

		/// <summary>
		/// Gets the current computed CSS styles applied to an element
		/// </summary>
		/// <param name="element">The element.</param>
		/// <param name="pseudoElement">The pseudo element.</param>
		/// <returns></returns>
		std::unique_ptr<Style> getComputedStyle(string element, string pseudoElement);

		/// <summary>
		/// Returns a Selection object representing the range of text selected by the user
		/// </summary>
		/// <returns></returns>
		void* getSelection();

		/// <summary>
		/// Returns a MediaQueryList object representing the specified CSS media query string
		/// </summary>
		/// <param name="mediaQueryString">The media query string.</param>
		/// <returns></returns>
		MediaQueryList::ptr matchMedia(string mediaQueryString);

		/// <summary>
		/// Moves a window relative to its current position
		/// </summary>
		/// <param name="x">The x.</param>
		/// <param name="y">The y.</param>
		void moveBy(int x, int y);

		/// <summary>
		/// Moves a window to the specified position
		/// </summary>
		/// <param name="x">The x.</param>
		/// <param name="y">The y.</param>
		void moveTo(int x, int y);

		/// <summary>
		/// Opens a new browser window
		/// </summary>
		/// <param name="URL">The URL.</param>
		/// <param name="name">The name.</param>
		/// <param name="specs">The specs.</param>
		/// <param name="replace">The replace.</param>
		/// <returns></returns>
		Window::ptr open(string URL = nullptr, string name = nullptr, string specs = nullptr, bool replace = true);

		/// <summary>
		/// Prints the content of the current window
		/// </summary>
		void print();

		/// <summary>
		/// Displays a dialog box that prompts the visitor for input
		/// </summary>
		/// <param name="text">The text.</param>
		/// <param name="defaultText">The default text.</param>
		/// <returns></returns>
		string prompt(string text, string defaultText = nullptr);

		/// <summary>
		/// Requests the browser to call a function to update an animation before the next repaint
		/// </summary>
		/// <returns></returns>
		void* requestAnimationFrame();

		/// <summary>
		/// Resizes the window by the specified pixels
		/// </summary>
		/// <param name="width">The width.</param>
		/// <param name="height">The height.</param>
		void resizeBy(int width, int height);

		/// <summary>
		/// Resizes the window to the specified width and height
		/// </summary>
		/// <param name="width">The width.</param>
		/// <param name="height">The height.</param>
		void resizeTo(int width, int height);

		/// <summary>
		/// Scrolls the document by the specified number of pixels
		/// </summary>
		/// <param name="xnum">The xnum.</param>
		/// <param name="ynum">The ynum.</param>
		void scrollBy(int xnum, int ynum);

		/// <summary>
		/// Scrolls the document to the specified coordinates
		/// </summary>
		/// <param name="xpos">The xpos.</param>
		/// <param name="ypos">The ypos.</param>
		void scrollTo(int xpos, int ypos);

		/// <summary>
		/// Calls a function or evaluates an expression at specified intervals (in milliseconds)
		/// </summary>
		/// <param name="function">The function.</param>
		/// <param name="milliseconds">The milliseconds.</param>
		/// <param name="args">The arguments.</param>
		/// <returns></returns>
		int setInterval(string function, int milliseconds, ...);

		/// <summary>
		/// Calls a function or evaluates an expression after a specified number of milliseconds
		/// </summary>
		/// <param name="function">The function.</param>
		/// <param name="milliseconds">The milliseconds.</param>
		/// <param name="args">The arguments.</param>
		/// <returns></returns>
		int setTimeout(string function, int milliseconds, ...);

		/// <summary>
		/// Stops the window from loading
		/// </summary>
		void stop();
	};

	/// <summary>
	/// Storage
	/// https://www.w3schools.com/jsref/obj_storage.asp
	/// </summary>
	class Storage
	{
	public:
		typedef std::unique_ptr<Storage> ptr;

		/// <summary>
		/// Returns the name of the nth key in the storage
		/// </summary>
		/// <param name="index">The index.</param>
		/// <returns></returns>
		string key(int index);

		/// <summary>
		/// Returns the number of data items stored in the Storage object
		/// </summary>
		/// <value>
		/// The length.
		/// </value>
		int length();

		/// <summary>
		/// Returns the value of the specified key name
		/// </summary>
		/// <param name="keyname">The keyname.</param>
		/// <returns></returns>
		string getItem(string keyname);

		/// <summary>
		/// Adds that key to the storage, or update that key's value if it already exists
		/// </summary>
		/// <param name="keyname">The keyname.</param>
		/// <param name="value">The value.</param>
		/// <returns></returns>
		string setItem(string keyname, string value);

		/// <summary>
		/// Removes that key from the storage
		/// </summary>
		/// <param name="keyname">The keyname.</param>
		void removeItem(string keyname);

		/// <summary>
		/// Empty all key out of the storage
		/// </summary>
		void clear();
	};
}

#endif  // LH_API_H
