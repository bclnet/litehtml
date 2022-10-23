#ifndef LH_API_H
#define LH_API_H

#include "api_any.h"
#include "api_event.h"
#include "api_node.h"
#include "api_service.h"
#include "script_engine.h"

namespace litehtml
{
	class HTMLCollection;
	class Style;
	class Storage;

	/// <summary>
	/// Rect
	/// </summary>
	class Rect
	{
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
	class DocumentFragment
	{
	public:
	};

	/// <summary>
	/// DocumentType
	/// </summary>
	class DocumentType
	{
	public:
	};

	/// <summary>
	/// DocumentImplementation
	/// </summary>
	class DocumentImplementation
	{
	public:
	};

	/// <summary>
	/// Console
	/// https://www.w3schools.com/jsref/obj_console.asp
	/// </summary>
	class Console
	{
	public:
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
		void count(tstring label = _tdefault);

		/// <summary>
		/// Outputs an error message to the console
		/// </summary>
		/// <param name="message">The message.</param>
		void error(tany message);

		/// <summary>
		/// Creates a new inline group in the console. This indents following console messages by an additional level, until console.groupEnd() is called
		/// </summary>
		/// <param name="label">The label.</param>
		void group(tstring label = _tdefault);

		/// <summary>
		/// Creates a new inline group in the console. However, the new group is created collapsed. The user will need to use the disclosure button to expand it
		/// </summary>
		/// <param name="label">The label.</param>
		void groupCollapsed(tstring label = _tdefault);

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
		void table(void* tabledata, tstring tablecolumns[] = nullptr);

		/// <summary>
		/// Starts a timer (can track how long an operation takes)
		/// </summary>
		/// <param name="label">The label.</param>
		void time(tstring label = _tdefault);

		/// <summary>
		/// Stops a timer that was previously started by console.time()
		/// </summary>
		/// <param name="label">The label.</param>
		void timeEnd(tstring label = _tdefault);

		/// <summary>
		/// Outputs a stack trace to the console
		/// </summary>
		/// <param name="label">The label.</param>
		void trace(tstring label = _tdefault);

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
	class Document : public Node
	{
	protected:
		document* _doc;
	public:
		Document();

		/// <summary>
		/// Returns the currently focused element in the document
		/// </summary>
		/// <value>
		/// The active element.
		/// </value>
		Element* activeElement();

		/// <summary>
		/// Attaches an event handler to the document
		/// </summary>
		/// <param name="event">The event.</param>
		/// <param name="function">The function.</param>
		/// <param name="useCapture">if set to <c>true</c> [use capture].</param>
		void addEventListener(tstring event, tstring function, bool useCapture = false);

		/// <summary>
		/// Adopts a node from another document
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns></returns>
		Node* adoptNode(Node* node);

		/// <summary>
		/// Returns a collection of all <a> elements in the document that have a name attribute
		/// </summary>
		/// <value>
		/// The anchors.
		/// </value>
		HTMLCollection& anchors();

		/// <summary>
		/// Adds a new child node, to an element, as the last child node
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns></returns>
		virtual Node* appendChild(Node* node) override; //: Node

		/// <summary>
		/// Returns a collection of all <applet> elements in the document
		/// </summary>
		/// <value>
		/// The applets.
		/// </value>
		HTMLCollection& applets();

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
		virtual tstring baseURI() override; //: Node

		/// <summary>
		/// Sets or returns the document's body (the <body> element)
		/// </summary>
		/// <value>
		/// The body.
		/// </value>
		Element* body();
		void body(Element* value);

		/// <summary>
		/// Returns the character encoding for the document
		/// </summary>
		/// <value>
		/// The character set.
		/// </value>
		tstring characterSet();

		/// <summary>
		/// Returns a collection of an element's child nodes (including text and comment nodes)
		/// </summary>
		virtual NodeList<Node> childNodes() override; //: Node

		/// <summary>
		/// Clones an element
		/// </summary>
		/// <param name="deep">if set to <c>true</c> [deep].</param>
		/// <returns></returns>
		virtual Node* cloneNode(bool deep = false) override; //: Node

		/// <summary>
		/// Closes the output stream previously opened with document.open()
		/// </summary>
		void close();

		/// <summary>
		/// Compares the document position of two elements
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns></returns>
		virtual int compareDocumentPosition(Node* node) override; //: Node

		/// <summary>
		/// Returns all name/value pairs of cookies in the document
		/// </summary>
		/// <value>
		/// The cookie.
		/// </value>
		tstring cookie();
		void cookie(tstring value);

		/// <summary>
		/// Creates an attribute node
		/// </summary>
		/// <param name="attributename">The attributename.</param>
		/// <returns></returns>
		Attr::ptr createAttribute(tstring attributename);

		/// <summary>
		/// Creates a Comment node with the specified text
		/// </summary>
		/// <param name="text">The text.</param>
		/// <returns></returns>
		Node* createComment(tstring text); //: IComment

		/// <summary>
		/// Creates an empty DocumentFragment node
		/// </summary>
		/// <returns></returns>
		DocumentFragment* createDocumentFragment();

		/// <summary>
		/// Creates an Element node
		/// </summary>
		/// <param name="nodename">The nodename.</param>
		/// <returns></returns>
		Element* createElement(tstring nodename);

		/// <summary>
		/// Creates a new event
		/// </summary>
		/// <param name="type">The type.</param>
		/// <returns></returns>
		Event* createEvent(tstring type);

		/// <summary>
		/// Creates a Text node
		/// </summary>
		/// <param name="text">The text.</param>
		/// <returns></returns>
		Node* createTextNode(tstring text); //: IText

		/// <summary>
		/// Returns the window object associated with a document, or nullptr if none is available.
		/// </summary>
		/// <value>
		/// The default view.
		/// </value>
		Window* defaultView();

		/// <summary>
		/// Controls whether the entire document should be editable or not.
		/// </summary>
		/// <value>
		/// The design mode.
		/// </value>
		tstring designMode(); //= "off"
		void designMode(tstring value);

		/// <summary>
		/// Returns the Document Type Declaration associated with the document
		/// </summary>
		/// <value>
		/// The doctype.
		/// </value>
		DocumentType* doctype();

		/// <summary>
		/// Returns the Document Element of the document (the <html> element)
		/// </summary>
		/// <value>
		/// The document element.
		/// </value>
		Element* documentElement();

		/// <summary>
		/// Sets or returns the location of the document
		/// </summary>
		/// <value>
		/// The document URI.
		/// </value>
		tstring documentURI();
		void documentURI(tstring value);

		/// <summary>
		/// Returns the domain name of the server that loaded the document
		/// </summary>
		/// <value>
		/// The domain.
		/// </value>
		tstring domain();

		/// <summary>
		/// Returns a collection of all <embed> elements the document
		/// </summary>
		/// <value>
		/// The embeds.
		/// </value>
		HTMLCollection& embeds();

		/// <summary>
		/// Invokes the specified clipboard operation on the element currently having focus.
		/// </summary>
		/// <param name="command">The command.</param>
		/// <param name="showUI">if set to <c>true</c> [show UI].</param>
		/// <param name="value">The value.</param>
		/// <returns></returns>
		bool execCommand(tstring command, bool showUI, void* value = nullptr);

		/// <summary>
		/// Returns the first child node of an element
		/// </summary>
		/// <value>
		/// The first child.
		/// </value>
		virtual Node* firstChild() override; //: Node

		/// <summary>
		/// Returns a collection of all <form> elements in the document
		/// </summary>
		/// <value>
		/// The forms.
		/// </value>
		HTMLCollection& forms();

		/// <summary>
		/// Returns the current element that is displayed in fullscreen mode
		/// </summary>
		/// <value>
		/// The fullscreen element.
		/// </value>
		Element* fullscreenElement();

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
		Element* getElementById(tstring elementID);

		/// <summary>
		/// Returns a NodeList containing all elements with the specified class name
		/// </summary>
		/// <param name="classname">The classname.</param>
		/// <returns></returns>
		NodeList<Element> getElementsByClassName(tstring classname);

		/// <summary>
		/// Returns a NodeList containing all elements with a specified name
		/// </summary>
		/// <param name="name">The name.</param>
		/// <returns></returns>
		NodeList<Element> getElementsByName(tstring name);

		/// <summary>
		/// Returns a NodeList containing all elements with the specified tag name
		/// </summary>
		/// <param name="tagname">The tagname.</param>
		/// <returns></returns>
		NodeList<Element> getElementsByTagName(tstring tagname);

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
		Element* head();

		/// <summary>
		///Returns a collection of all <img> elements in the document
		/// </summary>
		/// <value>
		/// The images.
		/// </value>
		HTMLCollection& images();

		/// <summary>
		/// Returns the DOMImplementation object that handles this document
		/// </summary>
		/// <value>
		/// The implementation.
		/// </value>
		DocumentImplementation* implementation();

		/// <summary>
		/// Imports a node from another document
		/// </summary>
		/// <param name="node">The node.</param>
		/// <param name="deep">if set to <c>true</c> [deep].</param>
		/// <returns></returns>
		Node* importNode(Node* node, bool deep);

		/// <summary>
		/// Returns the encoding, character set, used for the document
		/// </summary>
		/// <value>
		/// The input encoding.
		/// </value>
		tstring inputEncoding();

		/// <summary>
		/// Returns true if a specified namespaceURI is the default, otherwise false
		/// </summary>
		/// <param name="namespaceURI">The namespace URI.</param>
		/// <returns>
		///   <c>true</c> if [is default namespace] [the specified namespace URI]; otherwise, <c>false</c>.
		/// </returns>
		virtual bool isDefaultNamespace(tstring namespaceURI) override; //: Node

		/// <summary>
		/// Checks if two elements are equal
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns>
		///   <c>true</c> if [is equal node] [the specified node]; otherwise, <c>false</c>.
		/// </returns>
		virtual bool isEqualNode(Node* node) override; //: Node

		/// <summary>
		/// Checks if two elements are the same node
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns>
		///   <c>true</c> if [is same node] [the specified node]; otherwise, <c>false</c>.
		/// </returns>
		virtual bool isSameNode(Node* node) override; //: Node

		/// <summary>
		/// Returns the last child node of an element
		/// </summary>
		/// <value>
		/// The last child.
		/// </value>
		virtual Node* lastChild() override; //: Node

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
		HTMLCollection& links();

		/// <summary>
		/// Returns the next node at the same node tree level
		/// </summary>
		/// <value>
		/// The next sibling.
		/// </value>
		virtual Node* nextSibling() override; //: Node

		/// <summary>
		/// Returns the name of a node
		/// </summary>
		/// <value>
		/// The name of the node.
		/// </value>
		virtual tstring nodeName() override; //: Node

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
		virtual tstring nodeValue() override; //: Node
		virtual void nodeValue(tstring value) override; //: Node

		/// <summary>
		/// Removes empty Text nodes, and joins adjacent nodes
		/// </summary>
		virtual void normalize() override; //: Node

		/// <summary>
		/// Opens an HTML output stream to collect output from document.write()
		/// </summary>
		/// <param name="MIMEtype">The mim etype.</param>
		/// <param name="replace">The replace.</param>
		void open(tstring MIMEtype = nullptr, tstring replace = nullptr);

		/// <summary>
		/// Returns the root element (document object) for an element
		/// </summary>
		/// <value>
		/// The owner document.
		/// </value>
		virtual Document* ownerDocument() override; //: Node

		/// <summary>
		/// Returns the parent node of an element
		/// </summary>
		/// <value>
		/// The parent node.
		/// </value>
		virtual Node* parentNode() override; //: Node

		/// <summary>
		/// Returns the previous node at the same node tree level
		/// </summary>
		/// <value>
		/// The previous sibling.
		/// </value>
		virtual Node* previousSibling() override; //: Node

		/// <summary>
		/// Returns the first element that matches a specified CSS selector(s) in the document
		/// </summary>
		/// <param name="selectors">The selectors.</param>
		/// <returns></returns>
		Element* querySelector(tstring selectors);

		/// <summary>
		/// Returns a static NodeList containing all elements that matches a specified CSS selector(s) in the document
		/// </summary>
		/// <param name="selectors">The selectors.</param>
		/// <returns></returns>
		NodeList<Element> querySelectorAll(tstring selectors);

		/// <summary>
		/// Returns the (loading) status of the document
		/// </summary>
		/// <value>
		/// The state of the ready.
		/// </value>
		tstring readyState();

		/// <summary>
		/// Returns the URL of the document that loaded the current document
		/// </summary>
		/// <value>
		/// The referrer.
		/// </value>
		tstring referrer();

		/// <summary>
		/// Removes a child node from an element
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns></returns>
		virtual Node* removeChild(Node* node) override; //: Node

		/// <summary>
		/// Removes an event handler from the document (that has been attached with the addEventListener() method)
		/// </summary>
		/// <param name="event">The event.</param>
		/// <param name="function">The function.</param>
		/// <param name="useCapture">if set to <c>true</c> [use capture].</param>
		void removeEventListener(tstring event, tstring function, bool useCapture = false);

		/// <summary>
		/// NotSupported - Renames the specified node
		/// </summary>
		/// <param name="node">The node.</param>
		/// <param name="namespaceURI">The namespace URI.</param>
		/// <param name="nodename">The nodename.</param>
		/// <returns></returns>
		Node* renameNode(Node* node, tstring namespaceURI, tstring nodename);

		/// <summary>
		/// Replaces a child node in an element
		/// </summary>
		/// <param name="newnode">The newnode.</param>
		/// <param name="oldnode">The oldnode.</param>
		/// <returns></returns>
		virtual Node* replaceChild(Node* newnode, Node* oldnode) override; //: Node

		/// <summary>
		/// Returns a collection of <script> elements in the document
		/// </summary>
		/// <value>
		/// The scripts.
		/// </value>
		HTMLCollection& scripts();

		/// <summary>
		/// Sets or returns the textual content of a node and its descendants
		/// </summary>
		/// <value>
		/// The content of the text.
		/// </value>
		virtual tstring textContent() override; //: Node
		virtual void textContent(tstring value) override; //: Node

		/// <summary>
		/// Sets or returns the title of the document
		/// </summary>
		/// <value>
		/// The title.
		/// </value>
		tstring title();
		void title(tstring value);

		/// <summary>
		/// Returns the full URL of the HTML document
		/// </summary>
		/// <value>
		/// The URL.
		/// </value>
		tstring URL();

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
	class Element : public Node
	{
	protected:
		element* _elem;
	public:
		Element();

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
		void addEventListener(tstring event, tstring function, bool useCapture = false);

		/// <summary>
		/// Adds a new child node, to an element, as the last child node
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns></returns>
		virtual Node* appendChild(Node* node) override; //: Node

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
		virtual tstring baseURI() override; //: Node

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
		HTMLCollection& children();

		/// <summary>
		/// Returns the class name(s) of an element
		/// </summary>
		/// <value>
		/// The class list.
		/// </value>
		DOMTokenList& classList();

		/// <summary>
		/// Sets or returns the value of the class attribute of an element
		/// </summary>
		/// <value>
		/// The name of the class.
		/// </value>
		tstring className();
		void className(tstring value);

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
		virtual Node* cloneNode(bool deep = false) override; //: Node

		/// <summary>
		/// Compares the document position of two elements
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns></returns>
		virtual int compareDocumentPosition(Node* node) override; //: Node

		/// <summary>
		/// Returns true if a node is a descendant of a node, otherwise false
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns>
		///   <c>true</c> if [contains] [the specified node]; otherwise, <c>false</c>.
		/// </returns>
		bool contains(Node* node);

		/// <summary>
		/// Sets or returns whether the content of an element is editable or not
		/// </summary>
		/// <value>
		/// The content editable.
		/// </value>
		tstring contentEditable();
		void contentEditable(tstring value);

		/// <summary>
		/// Sets or returns the value of the dir attribute of an element
		/// </summary>
		/// <value>
		/// The dir.
		/// </value>
		tstring dir();
		void dir(tstring value);

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
		virtual Node* firstChild() override; //: Node

		/// <summary>
		/// Returns the first child element of an element
		/// </summary>
		/// <value>
		/// The first element child.
		/// </value>
		Element* firstElementChild();

		/// <summary>
		/// Gives focus to an element
		/// </summary>
		void focus();

		/// <summary>
		/// Returns the specified attribute value of an element node
		/// </summary>
		/// <param name="attributename">The attributename.</param>
		/// <returns></returns>
		tstring getAttribute(tstring attributename);

		/// <summary>
		/// Returns the specified attribute node
		/// </summary>
		/// <param name="attributename">The attributename.</param>
		/// <returns></returns>
		Attr::ptr getAttributeNode(tstring attributename);

		/// <summary>
		/// Returns the size of an element and its position relative to the viewport
		/// </summary>
		/// <returns></returns>
		Rect* getBoundingClientRect();

		/// <summary>
		/// Returns a collection of all child elements with the specified class name
		/// </summary>
		/// <param name="classname">The classname.</param>
		/// <returns></returns>
		NodeList<Element> getElementsByClassName(tstring classname);

		/// <summary>
		/// Returns a collection of all child elements with the specified tag name
		/// </summary>
		/// <param name="tagname">The tagname.</param>
		/// <returns></returns>
		NodeList<Element> getElementsByTagName(tstring tagname);

		/// <summary>
		/// Returns true if an element has the specified attribute, otherwise false
		/// </summary>
		/// <param name="attributename">The attributename.</param>
		/// <returns>
		///   <c>true</c> if the specified attributename has attribute; otherwise, <c>false</c>.
		/// </returns>
		bool hasAttribute(tstring attributename);

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
		tstring id();
		void id(tstring value);

		/// <summary>
		/// Sets or returns the content of an element
		/// </summary>
		/// <value>
		/// The inner HTML.
		/// </value>
		tstring innerHTML();
		void innerHTML(tstring value);

		/// <summary>
		/// Sets or returns the text content of a node and its descendants
		/// </summary>
		/// <value>
		/// The inner text.
		/// </value>
		tstring innerText();
		void innerText(tstring value);

		/// <summary>
		/// Inserts a HTML element at the specified position relative to the current element
		/// </summary>
		/// <param name="position">The position.</param>
		/// <param name="element">The element.</param>
		void insertAdjacentElement(tstring position, Element* element);

		/// <summary>
		/// Inserts a HTML formatted text at the specified position relative to the current element
		/// </summary>
		/// <param name="position">The position.</param>
		/// <param name="text">The text.</param>
		void insertAdjacentHTML(tstring position, tstring text);

		/// <summary>
		/// Inserts text into the specified position relative to the current element
		/// </summary>
		/// <param name="position">The position.</param>
		/// <param name="text">The text.</param>
		void insertAdjacentText(tstring position, tstring text);

		/// <summary>
		/// Inserts a new child node before a specified, existing, child node
		/// </summary>
		/// <param name="newnode">The newnode.</param>
		/// <param name="existingnode">The existingnode.</param>
		Node* insertBefore(Node* newnode, Node* existingnode);

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
		virtual bool isDefaultNamespace(tstring namespaceURI) override; //: Node

		/// <summary>
		/// Checks if two elements are equal
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns>
		///   <c>true</c> if [is equal node] [the specified node]; otherwise, <c>false</c>.
		/// </returns>
		virtual bool isEqualNode(Node* node) override; //: Node

		/// <summary>
		/// Checks if two elements are the same node
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns>
		///   <c>true</c> if [is same node] [the specified node]; otherwise, <c>false</c>.
		/// </returns>
		virtual bool isSameNode(Node* node) override; //: Node

		/// <summary>
		/// Sets or returns the value of the lang attribute of an element
		/// </summary>
		/// <value>
		/// The language.
		/// </value>
		tstring lang();
		void lang(tstring value);

		/// <summary>
		/// Returns the last child node of an element
		/// </summary>
		/// <value>
		/// The last child.
		/// </value>
		virtual Node* lastChild() override; //: Node

		/// <summary>
		/// Returns the last child element of an element
		/// </summary>
		/// <value>
		/// The last element child.
		/// </value>
		Element* lastElementChild();

		/// <summary>
		/// Returns the namespace URI of an element
		/// </summary>
		/// <value>
		/// The namespace URI.
		/// </value>
		tstring namespaceURI();

		/// <summary>
		/// Returns the next node at the same node tree level
		/// </summary>
		/// <value>
		/// The next sibling.
		/// </value>
		virtual Node* nextSibling() override; //: Node

		/// <summary>
		/// Returns the next element at the same node tree level
		/// </summary>
		/// <value>
		/// The next element sibling.
		/// </value>
		Element* nextElementSibling();

		/// <summary>
		/// Returns the name of a node
		/// </summary>
		/// <value>
		/// The name of the node.
		/// </value>
		virtual tstring nodeName() override; //: Node

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
		virtual tstring nodeValue() override; //: Node
		virtual void nodeValue(tstring value) override; //: Node

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
		Node* offsetParent();

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
		virtual Document* ownerDocument() override; //: Node

		/// <summary>
		/// Returns the parent node of an element
		/// </summary>
		/// <value>
		/// The parent node.
		/// </value>
		virtual Node* parentNode() override; //: Node

		/// <summary>
		/// Returns the parent element node of an element
		/// </summary>
		/// <value>
		/// The parent element.
		/// </value>
		Element* parentElement();

		/// <summary>
		/// Returns the previous node at the same node tree level
		/// </summary>
		/// <value>
		/// The previous sibling.
		/// </value>
		virtual Node* previousSibling() override; //: Node

		/// <summary>
		/// Returns the previous element at the same node tree level
		/// </summary>
		/// <value>
		/// The previous element sibling.
		/// </value>
		Element* previousElementSibling();

		/// <summary>
		/// Returns the first child element that matches a specified CSS selector(s) of an element
		/// </summary>
		/// <param name="selectors">The selectors.</param>
		/// <returns></returns>
		Element* querySelector(tstring selectors);

		/// <summary>
		/// Returns all child elements that matches a specified CSS selector(s) of an element
		/// </summary>
		/// <param name="selectors">The selectors.</param>
		/// <returns></returns>
		NodeList<Element> querySelectorAll(tstring selectors);

		/// <summary>
		/// Removes a specified attribute from an element
		/// </summary>
		/// <param name="attributename">The attributename.</param>
		void removeAttribute(tstring attributename);

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
		virtual Node* removeChild(Node* node) override; //: Node

		/// <summary>
		/// Removes an event handler that has been attached with the addEventListener() method
		/// </summary>
		/// <param name="event">The event.</param>
		/// <param name="function">The function.</param>
		/// <param name="useCapture">if set to <c>true</c> [use capture].</param>
		void removeEventListener(tstring event, tstring function, bool useCapture = false);

		/// <summary>
		/// Replaces a child node in an element
		/// </summary>
		/// <param name="newnode">The newnode.</param>
		/// <param name="oldnode">The oldnode.</param>
		/// <returns></returns>
		virtual Node* replaceChild(Node* newnode, Node* oldnode) override; //: Node

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
		void setAttribute(tstring attributename, tstring attributevalue);

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
		Style* style();

		/// <summary>
		/// Sets or returns the value of the tabindex attribute of an element
		/// </summary>
		/// <value>
		/// The index of the tab.
		/// </value>
		tstring tabIndex();
		void tabIndex(tstring value);

		/// <summary>
		/// Returns the tag name of an element
		/// </summary>
		/// <value>
		/// The name of the tag.
		/// </value>
		tstring tagName();

		/// <summary>
		/// Sets or returns the textual content of a node and its descendants
		/// </summary>
		/// <value>
		/// The content of the text.
		/// </value>
		virtual tstring textContent() override; //: Node
		virtual void textContent(tstring value) override; //: Node

		/// <summary>
		/// Sets or returns the value of the title attribute of an element
		/// </summary>
		/// <value>
		/// The title.
		/// </value>
		tstring title();
		void title(tstring value);

		/// <summary>
		/// Converts an element to a string
		/// </summary>
		tstring toString();
	};

	/// <summary>
	/// Geolocation
	/// https://www.w3schools.com/jsref/obj_geolocation.asp
	/// </summary>
	class Geolocation
	{
	public:
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
		tstring positionError();

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
	public:
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
		Element* operator[](int index);

		/// <summary>
		/// Returns the element at the specified index in an HTMLCollection
		/// </summary>
		/// <param name="index">The index.</param>
		/// <returns></returns>
		Element* item(int index);

		/// <summary>
		/// Returns the element with the specified ID, or name, in an HTMLCollection
		/// </summary>
		/// <param name="name">The name.</param>
		/// <returns></returns>
		Element* namedItem(tstring name);
	};

	/// <summary>
	/// Location
	/// https://www.w3schools.com/jsref/obj_location.asp
	/// </summary>
	class Location
	{
	public:
		/// <summary>
		/// Sets or returns the anchor part (#) of a URL
		/// </summary>
		/// <value>
		/// The hash.
		/// </value>
		tstring hash();
		void hash(tstring value);

		/// <summary>
		/// Sets or returns the hostname and port number of a URL
		/// </summary>
		/// <value>
		/// The host.
		/// </value>
		tstring host();
		void host(tstring value);

		/// <summary>
		/// Sets or returns the hostname of a URL
		/// </summary>
		/// <value>
		/// The hostname.
		/// </value>
		tstring hostname();
		void hostname(tstring value);

		/// <summary>
		/// Sets or returns the entire URL
		/// </summary>
		/// <value>
		/// The href.
		/// </value>
		tstring href();
		void href(tstring value);

		/// <summary>
		/// Returns the protocol, hostname and port number of a URL
		/// </summary>
		/// <value>
		/// The origin.
		/// </value>
		tstring origin();

		/// <summary>
		/// Sets or returns the path name of a URL
		/// </summary>
		/// <value>
		/// The pathname.
		/// </value>
		tstring pathname();
		void pathname(tstring value);

		/// <summary>
		/// Sets or returns the port number of a URL
		/// </summary>
		/// <value>
		/// The port.
		/// </value>
		tstring port();
		void port(tstring value);

		/// <summary>
		/// Sets or returns the protocol of a URL
		/// </summary>
		/// <value>
		/// The protocol.
		/// </value>
		tstring protocol();
		void protocol(tstring value);

		/// <summary>
		/// Sets or returns the querystring part of a URL
		/// </summary>
		/// <value>
		/// The search.
		/// </value>
		tstring search();
		void search(tstring value);

		/// <summary>
		/// Loads a new document
		/// </summary>
		/// <param name="URL">The URL.</param>
		void assign(tstring URL);

		/// <summary>
		/// Reloads the current document
		/// </summary>
		/// <param name="forceGet">if set to <c>true</c> [force get].</param>
		void reload(bool forceGet = false);

		/// <summary>
		/// Replaces the current document with a new one
		/// </summary>
		/// <param name="newURL">The new URL.</param>
		void replace(tstring newURL);
	};

	/// <summary>
	/// MediaQueryList
	/// https://www.w3schools.com/jsref/met_win_matchmedia.asp
	/// </summary>
	class MediaQueryList
	{
	public:
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
		tstring media();

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
		/// <summary>
	   /// Returns the code name of the browser
	   /// </summary>
	   /// <value>
	   /// The name of the application code.
	   /// </value>
		tstring appCodeName();

		/// <summary>
		/// Returns the name of the browser
		/// </summary>
		/// <value>
		/// The name of the application.
		/// </value>
		tstring appName();

		/// <summary>
		/// Returns the version information of the browser
		/// </summary>
		/// <value>
		/// The application version.
		/// </value>
		tstring appVersion();

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
		Geolocation* geolocation();

		/// <summary>
		/// Returns the language of the browser
		/// </summary>
		/// <value>
		/// The language.
		/// </value>
		tstring language();

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
		tstring platform();

		/// <summary>
		/// Returns the engine name of the browser
		/// </summary>
		/// <value>
		/// The product.
		/// </value>
		tstring product();

		/// <summary>
		/// Returns the user-agent header sent by the browser to the server
		/// </summary>
		/// <value>
		/// The user agent.
		/// </value>
		tstring userAgent();

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
		/// <summary>
		/// Sets or returns the alignment between the lines inside a flexible container when the items do not use all available space
		/// </summary>
		/// <value>The content of the align.</value>
		tstring alignContent();
		void alignContent(tstring value);

		/// <summary>
		/// Sets or returns the alignment for items inside a flexible container
		/// </summary>
		/// <value>
		/// The align items.
		/// </value>
		tstring alignItems();
		void alignItems(tstring value);

		/// <summary>
		/// Sets or returns the alignment for selected items inside a flexible container
		/// </summary>
		/// <value>
		/// The align self.
		/// </value>
		tstring alignSelf();
		void alignSelf(tstring value);

		/// <summary>
		/// A shorthand property for all the animation properties below, except the animationPlayState property
		/// </summary>
		/// <value>
		/// The animation.
		/// </value>
		tstring animation();
		void animation(tstring value);

		/// <summary>
		/// Sets or returns when the animation will start
		/// </summary>
		/// <value>
		/// The animation delay.
		/// </value>
		tstring animationDelay();
		void animationDelay(tstring value);

		/// <summary>
		/// Sets or returns whether or not the animation should play in reverse on alternate cycles
		/// </summary>
		/// <value>
		/// The animation direction.
		/// </value>
		tstring animationDirection();
		void animationDirection(tstring value);

		/// <summary>
		/// Sets or returns how many seconds or milliseconds an animation takes to complete one cycle
		/// </summary>
		/// <value>
		/// The duration of the animation.
		/// </value>
		tstring animationDuration();
		void animationDuration(tstring value);

		/// <summary>
		/// Sets or returns what values are applied by the animation outside the time it is executing
		/// </summary>
		/// <value>
		/// The animation fill mode.
		/// </value>
		tstring animationFillMode();
		void animationFillMode(tstring value);

		/// <summary>
		/// Sets or returns the number of times an animation should be played
		/// </summary>
		/// <value>
		/// The animation iteration count.
		/// </value>
		tstring animationIterationCount();
		void animationIterationCount(tstring value);

		/// <summary>
		/// Sets or returns a name for the @keyframes animation
		/// </summary>
		/// <value>
		/// The name of the animation.
		/// </value>
		tstring animationName();
		void animationName(tstring value);

		/// <summary>
		/// Sets or returns the speed curve of the animation
		/// </summary>
		/// <value>
		/// The animation timing function.
		/// </value>
		tstring animationTimingFunction();
		void animationTimingFunction(tstring value);

		/// <summary>
		/// Sets or returns whether the animation is running or paused
		/// </summary>
		/// <value>
		/// The state of the animation play.
		/// </value>
		tstring animationPlayState();
		void animationPlayState(tstring value);

		/// <summary>
		/// Sets or returns all the background properties in one declaration
		/// </summary>
		/// <value>
		/// The background.
		/// </value>
		tstring background();
		void background(tstring value);

		/// <summary>
		/// Sets or returns whether a background-image is fixed or scrolls with the page
		/// </summary>
		/// <value>
		/// The background attachment.
		/// </value>
		tstring backgroundAttachment();
		void backgroundAttachment(tstring value);

		/// <summary>
		/// Sets or returns the background-color of an element
		/// </summary>
		/// <value>
		/// The color of the background.
		/// </value>
		tstring backgroundColor();
		void backgroundColor(tstring value);

		/// <summary>
		/// Sets or returns the background-image for an element
		/// </summary>
		/// <value>
		/// The background image.
		/// </value>
		tstring backgroundImage();
		void backgroundImage(tstring value);

		/// <summary>
		/// Sets or returns the starting position of a background-image
		/// </summary>
		/// <value>
		/// The background position.
		/// </value>
		tstring backgroundPosition();
		void backgroundPosition(tstring value);

		/// <summary>
		/// Sets or returns how to repeat (tile) a background-image
		/// </summary>
		/// <value>
		/// The background repeat.
		/// </value>
		tstring backgroundRepeat();
		void backgroundRepeat(tstring value);

		/// <summary>
		/// Sets or returns the painting area of the background
		/// </summary>
		/// <value>
		/// The background clip.
		/// </value>
		tstring backgroundClip();
		void backgroundClip(tstring value);

		/// <summary>
		/// Sets or returns the positioning area of the background images
		/// </summary>
		/// <value>
		/// The background origin.
		/// </value>
		tstring backgroundOrigin();
		void backgroundOrigin(tstring value);

		/// <summary>
		/// Sets or returns the size of the background image
		/// </summary>
		/// <value>
		/// The size of the background.
		/// </value>
		tstring backgroundSize();
		void backgroundSize(tstring value);

		/// <summary>
		/// Sets or returns whether or not an element should be visible when not facing the screen
		/// </summary>
		/// <value>
		/// The backface visibility.
		/// </value>
		tstring backfaceVisibility();
		void backfaceVisibility(tstring value);

		/// <summary>
		/// Sets or returns borderWidth, borderStyle, and borderColor in one declaration
		/// </summary>
		/// <value>
		/// The border.
		/// </value>
		tstring border();
		void border(tstring value);

		/// <summary>
		/// Sets or returns all the borderBottom properties in one declaration
		/// </summary>
		/// <value>
		/// The border bottom.
		/// </value>
		tstring borderBottom();
		void borderBottom(tstring value);

		/// <summary>
		/// Sets or returns the color of the bottom border
		/// </summary>
		/// <value>
		/// The border bottom.
		/// </value>
		tstring borderBottomColor();
		void borderBottomColor(tstring value);

		/// <summary>
		/// Sets or returns the shape of the border of the bottom-left corner
		/// </summary>
		/// <value>
		/// The border bottom.
		/// </value>
		tstring borderBottomLeftRadius();
		void borderBottomLeftRadius(tstring value);

		/// <summary>
		/// Sets or returns the shape of the border of the bottom-right corner
		/// </summary>
		/// <value>
		/// The border bottom.
		/// </value>
		tstring borderBottomRightRadius();
		void borderBottomRightRadius(tstring value);

		/// <summary>
		/// Sets or returns the style of the bottom border
		/// </summary>
		/// <value>
		/// The border bottom.
		/// </value>
		tstring borderBottomStyle();
		void borderBottomStyle(tstring value);

		/// <summary>
		/// Sets or returns the width of the bottom border
		/// </summary>
		/// <value>
		/// The border bottom.
		/// </value>
		tstring borderBottomWidth();
		void borderBottomWidth(tstring value);

		/// <summary>
		/// Sets or returns whether the table border should be collapsed into a single border, or not
		/// </summary>
		/// <value>
		/// The border collapse.
		/// </value>
		tstring borderCollapse();
		void borderCollapse(tstring value);

		/// <summary>
		/// Sets or returns the color of an element's border (can have up to four values)
		/// </summary>
		/// <value>
		/// The color of the border.
		/// </value>
		tstring borderColor();
		void borderColor(tstring value);

		/// <summary>
		/// A shorthand property for setting or returning all the borderImage properties
		/// </summary>
		/// <value>
		/// The border image.
		/// </value>
		tstring borderImage();
		void borderImage(tstring value);

		/// <summary>
		/// Sets or returns the amount by which the border image area extends beyond the border box
		/// </summary>
		/// <value>
		/// The border image outset.
		/// </value>
		tstring borderImageOutset();
		void borderImageOutset(tstring value);

		/// <summary>
		/// Sets or returns whether the image-border should be repeated, rounded or stretched
		/// </summary>
		/// <value>
		/// The border image repeat.
		/// </value>
		tstring borderImageRepeat();
		void borderImageRepeat(tstring value);

		/// <summary>
		/// Sets or returns the inward offsets of the image-border
		/// </summary>
		/// <value>
		/// The border image slice.
		/// </value>
		tstring borderImageSlice();
		void borderImageSlice(tstring value);

		/// <summary>
		/// Sets or returns the image to be used as a border
		/// </summary>
		/// <value>
		/// The border image source.
		/// </value>
		tstring borderImageSource();
		void borderImageSource(tstring value);

		/// <summary>
		/// Sets or returns the widths of the image-border
		/// </summary>
		/// <value>
		/// The width of the border image.
		/// </value>
		tstring borderImageWidth();
		void borderImageWidth(tstring value);

		/// <summary>
		/// Sets or returns all the borderLeft properties in one declaration
		/// </summary>
		/// <value>
		/// The border left.
		/// </value>
		tstring borderLeft();
		void borderLeft(tstring value);

		/// <summary>
		/// Sets or returns the color of the left border
		/// </summary>
		/// <value>
		/// The color of the border left.
		/// </value>
		tstring borderLeftColor();
		void borderLeftColor(tstring value);

		/// <summary>
		/// Sets or returns the style of the left border
		/// </summary>
		/// <value>
		/// The border left style.
		/// </value>
		tstring borderLeftStyle();
		void borderLeftStyle(tstring value);

		/// <summary>
		/// Sets or returns the width of the left border
		/// </summary>
		/// <value>
		/// The width of the border left.
		/// </value>
		tstring borderLeftWidth();
		void borderLeftWidth(tstring value);

		/// <summary>
		/// A shorthand property for setting or returning all the four borderRadius properties
		/// </summary>
		/// <value>
		/// The border radius.
		/// </value>
		tstring borderRadius();
		void borderRadius(tstring value);

		/// <summary>
		/// Sets or returns all the borderRight properties in one declaration
		/// </summary>
		/// <value>
		/// The border right.
		/// </value>
		tstring borderRight();
		void borderRight(tstring value);

		/// <summary>
		/// Sets or returns the color of the right border
		/// </summary>
		/// <value>
		/// The color of the border right.
		/// </value>
		tstring borderRightColor();
		void borderRightColor(tstring value);

		/// <summary>
		/// Sets or returns the style of the right border
		/// </summary>
		/// <value>
		/// The border right style.
		/// </value>
		tstring borderRightStyle();
		void borderRightStyle(tstring value);

		/// <summary>
		/// Sets or returns the width of the right border
		/// </summary>
		/// <value>
		/// The width of the border right.
		/// </value>
		tstring borderRightWidth();
		void borderRightWidth(tstring value);

		/// <summary>
		/// Sets or returns the space between cells in a table
		/// </summary>
		/// <value>
		/// The border spacing.
		/// </value>
		tstring borderSpacing();
		void borderSpacing(tstring value);

		/// <summary>
		/// Sets or returns the style of an element's border (can have up to four values)
		/// </summary>
		/// <value>
		/// The border style.
		/// </value>
		tstring borderStyle();
		void borderStyle(tstring value);

		/// <summary>
		/// Sets or returns all the borderTop properties in one declaration
		/// </summary>
		/// <value>
		/// The border top.
		/// </value>
		tstring borderTop();
		void borderTop(tstring value);

		/// <summary>
		/// Sets or returns the color of the top border
		/// </summary>
		/// <value>
		/// The color of the border top.
		/// </value>
		tstring borderTopColor();
		void borderTopColor(tstring value);

		/// <summary>
		/// Sets or returns the shape of the border of the top-left corner
		/// </summary>
		/// <value>
		/// The border top left radius.
		/// </value>
		tstring borderTopLeftRadius();
		void borderTopLeftRadius(tstring value);

		/// <summary>
		/// Sets or returns the shape of the border of the top-right corner
		/// </summary>
		/// <value>
		/// The border top right radius.
		/// </value>
		tstring borderTopRightRadius();
		void borderTopRightRadius(tstring value);

		/// <summary>
		/// Sets or returns the style of the top border
		/// </summary>
		/// <value>
		/// The border top style.
		/// </value>
		tstring borderTopStyle();
		void borderTopStyle(tstring value);

		/// <summary>
		/// Sets or returns the width of the top border
		/// </summary>
		/// <value>
		/// The width of the border top.
		/// </value>
		tstring borderTopWidth();
		void borderTopWidth(tstring value);

		/// <summary>
		/// Sets or returns the width of an element's border (can have up to four values)
		/// </summary>
		/// <value>
		/// The width of the border.
		/// </value>
		tstring borderWidth();
		void borderWidth(tstring value);

		/// <summary>
		/// Sets or returns the bottom position of a positioned element
		/// </summary>
		/// <value>
		/// The bottom.
		/// </value>
		tstring bottom();
		void bottom(tstring value);

		/// <summary>
		/// Sets or returns the behaviour of the background and border of an element at page-break, or, for in-line elements, at line-break.
		/// </summary>
		/// <value>
		/// The box decoration break.
		/// </value>
		tstring boxDecorationBreak();
		void boxDecorationBreak(tstring value);

		/// <summary>
		/// Attaches one or more drop-shadows to the box
		/// </summary>
		/// <value>
		/// The box shadow.
		/// </value>
		tstring boxShadow();
		void boxShadow(tstring value);

		/// <summary>
		/// Allows you to define certain elements to fit an area in a certain way
		/// </summary>
		/// <value>
		/// The box sizing.
		/// </value>
		tstring boxSizing();
		void boxSizing(tstring value);

		/// <summary>
		/// Sets or returns the position of the table caption
		/// </summary>
		/// <value>
		/// The caption side.
		/// </value>
		tstring captionSide();
		void captionSide(tstring value);

		/// <summary>
		/// Sets or returns the position of the element relative to floating objects
		/// </summary>
		/// <value>
		/// The clear.
		/// </value>
		tstring clear();
		void clear(tstring value);

		/// <summary>
		/// Sets or returns which part of a positioned element is visible
		/// </summary>
		/// <value>
		/// The clip.
		/// </value>
		tstring clip();
		void clip(tstring value);

		/// <summary>
		/// Sets or returns the color of the text
		/// </summary>
		/// <value>
		/// The color.
		/// </value>
		tstring color();
		void color(tstring value);

		/// <summary>
		/// Sets or returns the number of columns an element should be divided into
		/// </summary>
		/// <value>
		/// The column count.
		/// </value>
		tstring columnCount();
		void columnCount(tstring value);

		/// <summary>
		/// Sets or returns how to fill columns
		/// </summary>
		/// <value>
		/// The column fill.
		/// </value>
		tstring columnFill();
		void columnFill(tstring value);

		/// <summary>
		/// Sets or returns the gap between the columns
		/// </summary>
		/// <value>
		/// The column gap.
		/// </value>
		tstring columnGap();
		void columnGap(tstring value);

		/// <summary>
		/// A shorthand property for setting or returning all the columnRule properties
		/// </summary>
		/// <value>
		/// The column rule.
		/// </value>
		tstring columnRule();
		void columnRule(tstring value);

		/// <summary>
		/// Sets or returns the color of the rule between columns
		/// </summary>
		/// <value>
		/// The color of the column rule.
		/// </value>
		tstring columnRuleColor();
		void columnRuleColor(tstring value);

		/// <summary>
		/// Sets or returns the style of the rule between columns
		/// </summary>
		/// <value>
		/// The column rule style.
		/// </value>
		tstring columnRuleStyle();
		void columnRuleStyle(tstring value);

		/// <summary>
		/// Sets or returns the width of the rule between columns
		/// </summary>
		/// <value>
		/// The width of the column rule.
		/// </value>
		tstring columnRuleWidth();
		void columnRuleWidth(tstring value);

		/// <summary>
		/// A shorthand property for setting or returning columnWidth and columnCount
		/// </summary>
		/// <value>
		/// The columns.
		/// </value>
		tstring columns();
		void columns(tstring value);

		/// <summary>
		/// Sets or returns how many columns an element should span across
		/// </summary>
		/// <value>
		/// The column span.
		/// </value>
		tstring columnSpan();
		void columnSpan(tstring value);

		/// <summary>
		/// Sets or returns the width of the columns
		/// </summary>
		/// <value>
		/// The width of the column.
		/// </value>
		tstring columnWidth();
		void columnWidth(tstring value);

		/// <summary>
		/// Used with the :before and :after pseudo-elements, to insert generated content
		/// </summary>
		/// <value>
		/// The content.
		/// </value>
		tstring content();
		void content(tstring value);

		/// <summary>
		/// Increments one or more counters
		/// </summary>
		/// <value>
		/// The counter increment.
		/// </value>
		tstring counterIncrement();
		void counterIncrement(tstring value);

		/// <summary>
		/// Creates or resets one or more counters
		/// </summary>
		/// <value>
		/// The counter reset.
		/// </value>
		tstring counterReset();
		void counterReset(tstring value);

		/// <summary>
		/// Sets or returns the type of cursor to display for the mouse pointer
		/// </summary>
		/// <value>
		/// The cursor.
		/// </value>
		tstring cursor();
		void cursor(tstring value);

		/// <summary>
		/// Sets or returns the text direction
		/// </summary>
		/// <value>
		/// The direction.
		/// </value>
		tstring direction();
		void direction(tstring value);

		/// <summary>
		/// Sets or returns an element's display type
		/// </summary>
		/// <value>
		/// The display.
		/// </value>
		tstring display();
		void display(tstring value);

		/// <summary>
		/// Sets or returns whether to show the border and background of empty cells, or not
		/// </summary>
		/// <value>
		/// The empty cells.
		/// </value>
		tstring emptyCells();
		void emptyCells(tstring value);

		/// <summary>
		/// Sets or returns image filters (visual effects, like blur and saturation)
		/// </summary>
		/// <value>
		/// The filter.
		/// </value>
		tstring filter();
		void filter(tstring value);

		/// <summary>
		/// Sets or returns the length of the item, relative to the rest
		/// </summary>
		/// <value>
		/// The flex.
		/// </value>
		tstring flex();
		void flex(tstring value);

		/// <summary>
		/// Sets or returns the initial length of a flexible item
		/// </summary>
		/// <value>
		/// The flex basis.
		/// </value>
		tstring flexBasis();
		void flexBasis(tstring value);

		/// <summary>
		/// Sets or returns the direction of the flexible items
		/// </summary>
		/// <value>
		/// The flex direction.
		/// </value>
		tstring flexDirection();
		void flexDirection(tstring value);

		/// <summary>
		/// A shorthand property for the flexDirection and the flexWrap properties
		/// </summary>
		/// <value>
		/// The flex flow.
		/// </value>
		tstring flexFlow();
		void flexFlow(tstring value);

		/// <summary>
		/// Sets or returns how much the item will grow relative to the rest
		/// </summary>
		/// <value>
		/// The flex grow.
		/// </value>
		tstring flexGrow();
		void flexGrow(tstring value);

		/// <summary>
		/// Sets or returns how the item will shrink relative to the rest
		/// </summary>
		/// <value>
		/// The flex shrink.
		/// </value>
		tstring flexShrink();
		void flexShrink(tstring value);

		/// <summary>
		/// Sets or returns whether the flexible items should wrap or not
		/// </summary>
		/// <value>
		/// The flex wrap.
		/// </value>
		tstring flexWrap();
		void flexWrap(tstring value);

		/// <summary>
		/// Sets or returns the horizontal alignment of an element
		/// </summary>
		/// <value>
		/// The CSS float.
		/// </value>
		tstring cssFloat();
		void cssFloat(tstring value);

		/// <summary>
		/// Sets or returns fontStyle, fontVariant, fontWeight, fontSize, lineHeight, and fontFamily in one declaration
		/// </summary>
		/// <value>
		/// The font.
		/// </value>
		tstring font();
		void font(tstring value);

		/// <summary>
		/// Sets or returns the font family for text
		/// </summary>
		/// <value>
		/// The font family.
		/// </value>
		tstring fontFamily();
		void fontFamily(tstring value);

		/// <summary>
		/// Sets or returns the font size of the text
		/// </summary>
		/// <value>
		/// The size of the font.
		/// </value>
		tstring fontSize();
		void fontSize(tstring value);

		/// <summary>
		/// Sets or returns whether the style of the font is normal, italic or oblique
		/// </summary>
		/// <value>
		/// The font style.
		/// </value>
		tstring fontStyle();
		void fontStyle(tstring value);

		/// <summary>
		/// Sets or returns whether the font should be displayed in small capital letters
		/// </summary>
		/// <value>
		/// The font variant.
		/// </value>
		tstring fontVariant();
		void fontVariant(tstring value);

		/// <summary>
		/// Sets or returns the boldness of the font
		/// </summary>
		/// <value>
		/// The font weight.
		/// </value>
		tstring fontWeight();
		void fontWeight(tstring value);

		/// <summary>
		/// Preserves the readability of text when font fallback occurs
		/// </summary>
		/// <value>
		/// The font size adjust.
		/// </value>
		tstring fontSizeAdjust();
		void fontSizeAdjust(tstring value);

		/// <summary>
		/// Selects a normal, condensed, or expanded face from a font family
		/// </summary>
		/// <value>
		/// The font stretch.
		/// </value>
		tstring fontStretch();
		void fontStretch(tstring value);

		/// <summary>
		/// Specifies whether a punctuation character may be placed outside the line box
		/// </summary>
		/// <value>
		/// The hanging punctuation.
		/// </value>
		tstring hangingPunctuation();
		void hangingPunctuation(tstring value);

		/// <summary>
		/// Sets or returns the height of an element
		/// </summary>
		/// <value>
		/// The height.
		/// </value>
		tstring height();
		void height(tstring value);

		/// <summary>
		/// Sets how to split words to improve the layout of paragraphs
		/// </summary>
		/// <value>
		/// The hyphens.
		/// </value>
		tstring hyphens();
		void hyphens(tstring value);

		/// <summary>
		/// Provides the author the ability to style an element with an iconic equivalent
		/// </summary>
		/// <value>
		/// The icon.
		/// </value>
		tstring icon();
		void icon(tstring value);

		/// <summary>
		/// Specifies a rotation in the right or clockwise direction that a user agent applies to an image
		/// </summary>
		/// <value>
		/// The image orientation.
		/// </value>
		tstring imageOrientation();
		void imageOrientation(tstring value);

		/// <summary>
		/// Defines whether an element must create a new stacking content
		/// </summary>
		/// <value>
		/// The isolation.
		/// </value>
		tstring isolation();
		void isolation(tstring value);

		/// <summary>
		/// Sets or returns the alignment between the items inside a flexible container when the items do not use all available space.
		/// </summary>
		/// <value>
		/// The content of the justify.
		/// </value>
		tstring justifyContent();
		void justifyContent(tstring value);

		/// <summary>
		/// Sets or returns the left position of a positioned element
		/// </summary>
		/// <value>
		/// The left.
		/// </value>
		tstring left();
		void left(tstring value);

		/// <summary>
		/// Sets or returns the space between characters in a text
		/// </summary>
		/// <value>
		/// The letter spacing.
		/// </value>
		tstring letterSpacing();
		void letterSpacing(tstring value);

		/// <summary>
		/// Sets or returns the distance between lines in a text
		/// </summary>
		/// <value>
		/// The height of the line.
		/// </value>
		tstring lineHeight();
		void lineHeight(tstring value);

		/// <summary>
		/// Sets or returns listStyleImage, listStylePosition, and listStyleType in one declaration
		/// </summary>
		/// <value>
		/// The list style.
		/// </value>
		tstring listStyle();
		void listStyle(tstring value);

		/// <summary>
		/// Sets or returns an image as the list-item marker
		/// </summary>
		/// <value>
		/// The list style image.
		/// </value>
		tstring listStyleImage();
		void listStyleImage(tstring value);

		/// <summary>
		/// Sets or returns the position of the list-item marker
		/// </summary>
		/// <value>
		/// The list style position.
		/// </value>
		tstring listStylePosition();
		void listStylePosition(tstring value);

		/// <summary>
		/// Sets or returns the list-item marker type
		/// </summary>
		/// <value>
		/// The type of the list style.
		/// </value>
		tstring listStyleType();
		void listStyleType(tstring value);

		/// <summary>
		/// Sets or returns the margins of an element (can have up to four values)
		/// </summary>
		/// <value>
		/// The margin.
		/// </value>
		tstring margin();
		void margin(tstring value);

		/// <summary>
		/// Sets or returns the bottom margin of an element
		/// </summary>
		/// <value>
		/// The margin bottom.
		/// </value>
		tstring marginBottom();
		void marginBottom(tstring value);

		/// <summary>
		/// Sets or returns the left margin of an element
		/// </summary>
		/// <value>
		/// The margin left.
		/// </value>
		tstring marginLeft();
		void marginLeft(tstring value);

		/// <summary>
		/// Sets or returns the right margin of an element
		/// </summary>
		/// <value>
		/// The margin right.
		/// </value>
		tstring marginRight();
		void marginRight(tstring value);

		/// <summary>
		/// Sets or returns the top margin of an element
		/// </summary>
		/// <value>
		/// The margin top.
		/// </value>
		tstring marginTop();
		void marginTop(tstring value);

		/// <summary>
		/// Sets or returns the maximum height of an element
		/// </summary>
		/// <value>
		/// The maximum height.
		/// </value>
		tstring maxHeight();
		void maxHeight(tstring value);

		/// <summary>
		/// Sets or returns the maximum width of an element
		/// </summary>
		/// <value>
		/// The maximum width.
		/// </value>
		tstring maxWidth();
		void maxWidth(tstring value);

		/// <summary>
		/// Sets or returns the minimum height of an element
		/// </summary>
		/// <value>
		/// The minimum height.
		/// </value>
		tstring minHeight();
		void minHeight(tstring value);

		/// <summary>
		/// Sets or returns the minimum width of an element
		/// </summary>
		/// <value>
		/// The minimum width.
		/// </value>
		tstring minWidth();
		void minWidth(tstring value);

		/// <summary>
		/// Sets or returns where to navigate when using the arrow-down navigation key
		/// </summary>
		/// <value>
		/// The nav down.
		/// </value>
		tstring navDown();
		void navDown(tstring value);

		/// <summary>
		/// Sets or returns the tabbing order for an element
		/// </summary>
		/// <value>
		/// The index of the nav.
		/// </value>
		tstring navIndex();
		void navIndex(tstring value);

		/// <summary>
		/// Sets or returns where to navigate when using the arrow-left navigation key
		/// </summary>
		/// <value>
		/// The nav left.
		/// </value>
		tstring navLeft();
		void navLeft(tstring value);

		/// <summary>
		/// Sets or returns where to navigate when using the arrow-right navigation key
		/// </summary>
		/// <value>
		/// The nav right.
		/// </value>
		tstring navRight();
		void navRight(tstring value);

		/// <summary>
		/// Sets or returns where to navigate when using the arrow-up navigation key
		/// </summary>
		/// <value>
		/// The nav up.
		/// </value>
		tstring navUp();
		void navUp(tstring value);

		/// <summary>
		/// Specifies how the contents of a replaced element should be fitted to the box established by its used height and width
		/// </summary>
		/// <value>
		/// The object fit.
		/// </value>
		tstring objectFit();
		void objectFit(tstring value);

		/// <summary>
		/// Specifies the alignment of the replaced element inside its box
		/// </summary>
		/// <value>
		/// The object position.
		/// </value>
		tstring objectPosition();
		void objectPosition(tstring value);

		/// <summary>
		/// Sets or returns the opacity level for an element
		/// </summary>
		/// <value>
		/// The opacity.
		/// </value>
		tstring opacity();
		void opacity(tstring value);

		/// <summary>
		/// Sets or returns the order of the flexible item, relative to the rest
		/// </summary>
		/// <value>
		/// The order.
		/// </value>
		tstring order();
		void order(tstring value);

		/// <summary>
		/// Sets or returns the minimum number of lines for an element that must be left at the bottom of a page when a page break occurs inside an element
		/// </summary>
		/// <value>
		/// The orphans.
		/// </value>
		tstring orphans();
		void orphans(tstring value);

		/// <summary>
		/// Sets or returns all the outline properties in one declaration
		/// </summary>
		/// <value>
		/// The outline.
		/// </value>
		tstring outline();
		void outline(tstring);

		/// <summary>
		/// Sets or returns the color of the outline around a element
		/// </summary>
		/// <value>
		/// The color of the outline.
		/// </value>
		tstring outlineColor();
		void outlineColor(tstring value);

		/// <summary>
		/// Offsets an outline, and draws it beyond the border edge
		/// </summary>
		/// <value>
		/// The outline offset.
		/// </value>
		tstring outlineOffset();
		void outlineOffset(tstring value);

		/// <summary>
		/// Sets or returns the style of the outline around an element
		/// </summary>
		/// <value>
		/// The outline style.
		/// </value>
		tstring outlineStyle();
		void outlineStyle(tstring value);

		/// <summary>
		/// Sets or returns the width of the outline around an element
		/// </summary>
		/// <value>
		/// The width of the outline.
		/// </value>
		tstring outlineWidth();
		void outlineWidth(tstring value);

		/// <summary>
		/// Sets or returns what to do with content that renders outside the element box
		/// </summary>
		/// <value>
		/// The overflow.
		/// </value>
		tstring overflow();
		void overflow(tstring value);

		/// <summary>
		/// Specifies what to do with the left/right edges of the content, if it overflows the element's content area
		/// </summary>
		/// <value>
		/// The overflow x.
		/// </value>
		tstring overflowX();
		void overflowX(tstring value);

		/// <summary>
		/// Specifies what to do with the top/bottom edges of the content, if it overflows the element's content area
		/// </summary>
		/// <value>
		/// The overflow y.
		/// </value>
		tstring overflowY();
		void overflowY(tstring value);

		/// <summary>
		/// Sets or returns the padding of an element (can have up to four values)
		/// </summary>
		/// <value>
		/// The padding.
		/// </value>
		tstring padding();
		void padding(tstring value);

		/// <summary>
		/// Sets or returns the bottom padding of an element
		/// </summary>
		/// <value>
		/// The padding bottom.
		/// </value>
		tstring paddingBottom();
		void paddingBottom(tstring value);

		/// <summary>
		/// Sets or returns the left padding of an element
		/// </summary>
		/// <value>
		/// The padding left.
		/// </value>
		tstring paddingLeft();
		void paddingLeft(tstring value);

		/// <summary>
		/// Sets or returns the right padding of an element
		/// </summary>
		/// <value>
		/// The padding right.
		/// </value>
		tstring paddingRight();
		void paddingRight(tstring value);

		/// <summary>
		/// Sets or returns the top padding of an element
		/// </summary>
		/// <value>
		/// The padding top.
		/// </value>
		tstring paddingTop();
		void paddingTop(tstring value);

		/// <summary>
		/// Sets or returns the page-break behavior after an element
		/// </summary>
		/// <value>
		/// The page break after.
		/// </value>
		tstring pageBreakAfter();
		void pageBreakAfter(tstring value);

		/// <summary>
		/// Sets or returns the page-break behavior before an element
		/// </summary>
		/// <value>
		/// The page break before.
		/// </value>
		tstring pageBreakBefore();
		void pageBreakBefore(tstring value);

		/// <summary>
		/// Sets or returns the page-break behavior inside an element
		/// </summary>
		/// <value>
		/// The page break inside.
		/// </value>
		tstring pageBreakInside();
		void pageBreakInside(tstring value);

		/// <summary>
		/// Sets or returns the perspective on how 3D elements are viewed
		/// </summary>
		/// <value>
		/// The perspective.
		/// </value>
		tstring perspective();
		void perspective(tstring value);

		/// <summary>
		/// Sets or returns the bottom position of 3D elements
		/// </summary>
		/// <value>
		/// The perspective origin.
		/// </value>
		tstring perspectiveOrigin();
		void perspectiveOrigin(tstring value);

		/// <summary>
		/// Sets or returns the type of positioning method used for an element (static, relative, absolute or fixed)
		/// </summary>
		/// <value>
		/// The position.
		/// </value>
		tstring position();
		void position(tstring value);

		/// <summary>
		/// Sets or returns the type of quotation marks for embedded quotations
		/// </summary>
		/// <value>
		/// The quotes.
		/// </value>
		tstring quotes();
		void quotes(tstring value);

		/// <summary>
		/// Sets or returns whether or not an element is resizable by the user
		/// </summary>
		/// <value>
		/// The resize.
		/// </value>
		tstring resize();
		void resize(tstring value);

		/// <summary>
		/// Sets or returns the right position of a positioned element
		/// </summary>
		/// <value>
		/// The right.
		/// </value>
		tstring right();
		void right(tstring value);

		/// <summary>
		/// Sets or returns the way to lay out table cells, rows, and columns
		/// </summary>
		/// <value>
		/// The table layout.
		/// </value>
		tstring tableLayout();
		void tableLayout(tstring value);

		/// <summary>
		/// Sets or returns the length of the tab-character
		/// </summary>
		/// <value>
		/// The size of the tab.
		/// </value>
		tstring tabSize();
		void tabSize(tstring value);

		/// <summary>
		/// Sets or returns the horizontal alignment of text
		/// </summary>
		/// <value>
		/// The text align.
		/// </value>
		tstring textAlign();
		void textAlign(tstring value);

		/// <summary>
		/// Sets or returns how the last line of a block or a line right before a forced line break is aligned when text-align is "justify"
		/// </summary>
		/// <value>
		/// The text align last.
		/// </value>
		tstring textAlignLast();
		void textAlignLast(tstring value);

		/// <summary>
		/// Sets or returns the decoration of a text
		/// </summary>
		/// <value>
		/// The text decoration.
		/// </value>
		tstring textDecoration();
		void textDecoration(tstring value);

		/// <summary>
		/// Sets or returns the color of the text-decoration
		/// </summary>
		/// <value>
		/// The color of the text decoration.
		/// </value>
		tstring textDecorationColor();
		void textDecorationColor(tstring value);

		/// <summary>
		/// Sets or returns the type of line in a text-decoration
		/// </summary>
		/// <value>
		/// The text decoration line.
		/// </value>
		tstring textDecorationLine();
		void textDecorationLine(tstring value);

		/// <summary>
		/// Sets or returns the style of the line in a text decoration
		/// </summary>
		/// <value>
		/// The text decoration style.
		/// </value>
		tstring textDecorationStyle();
		void textDecorationStyle(tstring value);

		/// <summary>
		/// Sets or returns the indentation of the first line of text
		/// </summary>
		/// <value>
		/// The text indent.
		/// </value>
		tstring textIndent();
		void textIndent(tstring value);

		/// <summary>
		/// Sets or returns the justification method used when text-align is "justify"
		/// </summary>
		/// <value>
		/// The text justify.
		/// </value>
		tstring textJustify();
		void textJustify(tstring value);

		/// <summary>
		/// Sets or returns what should happen when text overflows the containing element
		/// </summary>
		/// <value>
		/// The text overflow.
		/// </value>
		tstring textOverflow();
		void textOverflow(tstring value);

		/// <summary>
		/// Sets or returns the shadow effect of a text
		/// </summary>
		/// <value>
		/// The text shadow.
		/// </value>
		tstring textShadow();
		void textShadow(tstring value);

		/// <summary>
		/// Sets or returns the capitalization of a text
		/// </summary>
		/// <value>
		/// The text transform.
		/// </value>
		tstring textTransform();
		void textTransform(tstring value);

		/// <summary>
		/// Sets or returns the top position of a positioned element
		/// </summary>
		/// <value>
		/// The top.
		/// </value>
		tstring top();
		void top(tstring value);

		/// <summary>
		/// Applies a 2D or 3D transformation to an element
		/// </summary>
		/// <value>
		/// The transform.
		/// </value>
		tstring transform();
		void transform(tstring value);

		/// <summary>
		/// Sets or returns the position of transformed elements
		/// </summary>
		/// <value>
		/// The transform origin.
		/// </value>
		tstring transformOrigin();
		void transformOrigin(tstring value);

		/// <summary>
		/// Sets or returns how nested elements are rendered in 3D space
		/// </summary>
		/// <value>
		/// The transform style.
		/// </value>
		tstring transformStyle();
		void transformStyle(tstring value);

		/// <summary>
		/// A shorthand property for setting or returning the four transition properties
		/// </summary>
		/// <value>
		/// The transition.
		/// </value>
		tstring transition();
		void transition(tstring value);

		/// <summary>
		/// Sets or returns the CSS property that the transition effect is for
		/// </summary>
		/// <value>
		/// The transition property.
		/// </value>
		tstring transitionProperty();
		void transitionProperty(tstring value);

		/// <summary>
		/// Sets or returns how many seconds or milliseconds a transition effect takes to complete
		/// </summary>
		/// <value>
		/// The duration of the transition.
		/// </value>
		tstring transitionDuration();
		void transitionDuration(tstring value);

		/// <summary>
		/// Sets or returns the speed curve of the transition effect
		/// </summary>
		/// <value>
		/// The transition timing function.
		/// </value>
		tstring transitionTimingFunction();
		void transitionTimingFunction(tstring value);

		/// <summary>
		/// Sets or returns when the transition effect will start
		/// </summary>
		/// <value>
		/// The transition delay.
		/// </value>
		tstring transitionDelay();
		void transitionDelay(tstring value);

		/// <summary>
		/// Sets or returns whether the text should be overridden to support multiple languages in the same document
		/// </summary>
		/// <value>
		/// The unicode bidi.
		/// </value>
		tstring unicodeBidi();
		void unicodeBidi(tstring value);

		/// <summary>
		/// Sets or returns whether the text of an element can be selected or not
		/// </summary>
		/// <value>
		/// The user select.
		/// </value>
		tstring userSelect();
		void userSelect(tstring value);

		/// <summary>
		/// Sets or returns the vertical alignment of the content in an element
		/// </summary>
		/// <value>
		/// The vertical align.
		/// </value>
		tstring verticalAlign();
		void verticalAlign(tstring value);

		/// <summary>
		/// Sets or returns whether an element should be visible
		/// </summary>
		/// <value>
		/// The visibility.
		/// </value>
		tstring visibility();
		void visibility(tstring value);

		/// <summary>
		/// Sets or returns how to handle tabs, line breaks and whitespace in a text
		/// </summary>
		/// <value>
		/// The white space.
		/// </value>
		tstring whiteSpace();
		void whiteSpace(tstring value);

		/// <summary>
		/// Sets or returns the width of an element
		/// </summary>
		/// <value>
		/// The width.
		/// </value>
		tstring width();
		void width(tstring value);

		/// <summary>
		/// Sets or returns line breaking rules for non-CJK scripts
		/// </summary>
		/// <value>
		/// The word break.
		/// </value>
		tstring wordBreak();
		void wordBreak(tstring value);

		/// <summary>
		/// Sets or returns the spacing between words in a text
		/// </summary>
		/// <value>
		/// The word spacing.
		/// </value>
		tstring wordSpacing();
		void wordSpacing(tstring value);

		/// <summary>
		/// Allows long, unbreakable words to be broken and wrap to the next line
		/// </summary>
		/// <value>
		/// The word wrap.
		/// </value>
		tstring wordWrap();
		void wordWrap(tstring value);

		/// <summary>
		/// Sets or returns the minimum number of lines for an element that must be visible at the top of a page
		/// </summary>
		/// <value>
		/// The widows.
		/// </value>
		tstring widows();
		void widows(tstring value);

		/// <summary>
		/// Sets or returns the stack order of a positioned element
		/// </summary>
		/// <value>
		/// The index of the z.
		/// </value>
		tstring zIndex();
		void zIndex(tstring value);
	};

	/// <summary>
	/// Window
	/// https://www.w3schools.com/jsref/obj_window.asp
	/// </summary>
	class Window
	{
	public:
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
		Console* console();

		/// <summary>
		/// Sets or returns the default text in the statusbar of a window
		/// </summary>
		/// <value>
		/// The default status.
		/// </value>
		tstring defaultStatus();
		void defaultStatus(tstring value);

		/// <summary>
		/// Returns the Document object for the window (See Document object)
		/// </summary>
		/// <value>
		/// The document.
		/// </value>
		Document* document();

		/// <summary>
		/// Returns the <iframe> element in which the current window is inserted
		/// </summary>
		/// <value>
		/// The frame element.
		/// </value>
		Element* frameElement();

		/// <summary>
		/// Returns all <iframe> elements in the current window
		/// </summary>
		/// <value>
		/// The frames.
		/// </value>
		std::vector<Element*> frames();

		/// <summary>
		/// Returns the History object for the window (See History object)
		/// </summary>
		/// <value>
		/// The history.
		/// </value>
		History* history();

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
		Storage* localStorage();

		/// <summary>
		/// Returns the Location object for the window (See Location object)
		/// </summary>
		/// <value>
		/// The location.
		/// </value>
		Location* location();

		/// <summary>
		/// Sets or returns the name of a window
		/// </summary>
		/// <value>
		/// The name.
		/// </value>
		tstring name();
		void name(tstring value);

		/// <summary>
		/// Returns the Navigator object for the window (See Navigator object)
		/// </summary>
		/// <value>
		/// The navigator.
		/// </value>
		Navigator* navigator();

		/// <summary>
		/// Returns a reference to the window that created the window
		/// </summary>
		/// <value>
		/// The opener.
		/// </value>
		Window* opener();

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
		Window* parent();

		/// <summary>
		/// Returns the Screen object for the window (See Screen object)
		/// </summary>
		/// <value>
		/// The screen.
		/// </value>
		Screen* screen();

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
		Storage* sessionStorage();

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
		Window* self();

		/// <summary>
		/// Sets or returns the text in the statusbar of a window
		/// </summary>
		/// <value>
		/// The status.
		/// </value>
		tstring status();
		void status(tstring value);

		/// <summary>
		/// Returns the topmost browser window
		/// </summary>
		/// <value>
		/// The top.
		/// </value>
		Window* top();

		/// <summary>
		/// Displays an alert box with a message and an OK button
		/// </summary>
		/// <param name="message">The message.</param>
		void alert(tstring message);

		/// <summary>
		/// Decodes a base-64 encoded string
		/// </summary>
		/// <param name="encodedStr">The encoded string.</param>
		/// <returns></returns>
		tstring atob(tstring encodedStr);

		/// <summary>
		/// Removes focus from the current window
		/// </summary>
		void blur();

		/// <summary>
		/// Encodes a string in base-64
		/// </summary>
		/// <param name="str">The string.</param>
		/// <returns></returns>
		tstring btoa(tstring str);

		/// <summary>
		/// Clears a timer set with setInterval()
		/// </summary>
		/// <param name="var">The variable.</param>
		void clearInterval(tstring var);

		/// <summary>
		/// Clears a timer set with setTimeout()
		/// </summary>
		/// <param name="id_of_settimeout">The identifier of settimeout.</param>
		void clearTimeout(tstring id_of_settimeout);

		/// <summary>
		/// Closes the current window
		/// </summary>
		void close();

		/// <summary>
		/// Displays a dialog box with a message and an OK and a Cancel button
		/// </summary>
		/// <param name="message">The message.</param>
		/// <returns></returns>
		bool confirm(tstring message);

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
		Style* getComputedStyle(tstring element, tstring pseudoElement);

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
		MediaQueryList& matchMedia(tstring mediaQueryString);

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
		Window* open(tstring URL = nullptr, tstring name = nullptr, tstring specs = nullptr, bool replace = true);

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
		tstring prompt(tstring text, tstring defaultText = nullptr);

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
		int setInterval(tstring function, int milliseconds, ...);

		/// <summary>
		/// Calls a function or evaluates an expression after a specified number of milliseconds
		/// </summary>
		/// <param name="function">The function.</param>
		/// <param name="milliseconds">The milliseconds.</param>
		/// <param name="args">The arguments.</param>
		/// <returns></returns>
		int setTimeout(tstring function, int milliseconds, ...);

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
		/// <summary>
		/// Returns the name of the nth key in the storage
		/// </summary>
		/// <param name="index">The index.</param>
		/// <returns></returns>
		tstring key(int index);

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
		tstring getItem(tstring keyname);

		/// <summary>
		/// Adds that key to the storage, or update that key's value if it already exists
		/// </summary>
		/// <param name="keyname">The keyname.</param>
		/// <param name="value">The value.</param>
		/// <returns></returns>
		tstring setItem(tstring keyname, tstring value);

		/// <summary>
		/// Removes that key from the storage
		/// </summary>
		/// <param name="keyname">The keyname.</param>
		void removeItem(tstring keyname);

		/// <summary>
		/// Empty all key out of the storage
		/// </summary>
		void clear();
	};
}

#endif  // LH_API_H
