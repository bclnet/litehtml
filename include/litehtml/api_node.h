#ifndef LH_API_NODE_H
#define LH_API_NODE_H

#include <string>

namespace litehtml
{
	class Document;
	class Attr;
	template<class TNode> class NodeList;
	class NamedNodeMap;
	class element;
	class html_tag;
	typedef std::map<litehtml::tstring, litehtml::tstring> string_map;
	typedef std::vector<std::shared_ptr<litehtml::element>> elements_vector;

	/// <summary>
	/// Node
	/// </summary>
	class Node
	{
	public:
		Node();

		/// <summary>
		/// Adds a new child node, to an element, as the last child node
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns></returns>
		virtual Node* appendChild(Node* node) = 0;

		/// <summary>
		/// Returns a NamedNodeMap of an element's attributes
		/// </summary>
		/// <value>
		/// The attributes.
		/// </value>
		virtual NamedNodeMap attributes() = 0;

		/// <summary>
		/// Returns the absolute base URI of a node
		/// </summary>
		/// <value>
		/// The base URI.
		/// </value>
		virtual tstring baseURI() = 0;

		/// <summary>
		/// Returns a collection of an element's child nodes (including text and comment nodes)
		/// </summary>
		virtual NodeList<Node> childNodes() = 0;

		/// <summary>
		/// Clones an element
		/// </summary>
		/// <param name="deep">if set to <c>true</c> [deep].</param>
		/// <returns></returns>
		virtual Node* cloneNode(bool deep = false) = 0;

		/// <summary>
		/// Compares the document position of two elements
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns></returns>
		virtual int compareDocumentPosition(Node* node) = 0;

		/// <summary>
		/// Returns the first child node of an element
		/// </summary>
		/// <value>
		/// The first child.
		/// </value>
		virtual Node* firstChild() = 0;

		/// <summary>
		/// Returns true if the specified node has any attributes, otherwise false
		/// </summary>
		/// <returns>
		///   <c>true</c> if this instance has attributes; otherwise, <c>false</c>.
		/// </returns>
		virtual bool hasAttributes() = 0;

		/// <summary>
		/// Returns true if an element has any child nodes, otherwise false
		/// </summary>
		/// <returns>
		///   <c>true</c> if [has child nodes]; otherwise, <c>false</c>.
		/// </returns>
		virtual bool hasChildNodes() = 0;

		/// <summary>
		/// Returns true if a specified namespaceURI is the default, otherwise false
		/// </summary>
		/// <param name="namespaceURI">The namespace URI.</param>
		/// <returns>
		///   <c>true</c> if [is default namespace] [the specified namespace URI]; otherwise, <c>false</c>.
		/// </returns>
		virtual bool isDefaultNamespace(tstring namespaceURI) = 0;

		/// <summary>
		/// Checks if two elements are equal
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns>
		///   <c>true</c> if [is equal node] [the specified node]; otherwise, <c>false</c>.
		/// </returns>
		virtual bool isEqualNode(Node* node) = 0;

		/// <summary>
		/// Checks if two elements are the same node
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns>
		///   <c>true</c> if [is same node] [the specified node]; otherwise, <c>false</c>.
		/// </returns>
		virtual bool isSameNode(Node* node) = 0;

		/// <summary>
		/// Returns the last child node of an element
		/// </summary>
		/// <value>
		/// The last child.
		/// </value>
		virtual Node* lastChild() = 0;

		/// <summary>
		/// Returns the namespace URI associated with a given prefix
		/// </summary>
		/// <param name="prefix">The prefix.</param>
		/// <returns></returns>
		tstring lookupNamespaceURI(tstring prefix); //: Base

		/// <summary>
		/// Returns the prefix associated with a given namespace URI
		/// </summary>
		/// <param name="namespaceURI">The namespace URI.</param>
		/// <returns></returns>
		tstring lookupPrefix(tstring namespaceURI); //: Base

		/// <summary>
		/// Returns the next node at the same node tree level
		/// </summary>
		/// <value>
		/// The next sibling.
		/// </value>
		virtual Node* nextSibling() = 0;

		/// <summary>
		/// Returns the name of a node
		/// </summary>
		/// <value>
		/// The name of the node.
		/// </value>
		virtual tstring nodeName() = 0;

		/// <summary>
		/// Returns the node type of a node
		/// </summary>
		/// <value>
		/// The type of the node.
		/// </value>
		virtual int nodeType() = 0;

		/// <summary>
		/// Sets or returns the value of a node
		/// </summary>
		/// <value>
		/// The node value.
		/// </value>
		virtual tstring nodeValue() = 0;
		virtual void nodeValue(tstring value) = 0;

		/// <summary>
		/// Joins adjacent text nodes and removes empty text nodes in an element
		/// </summary>
		virtual void normalize() = 0;

		/// <summary>
		/// Returns the root element (document object) for an element
		/// </summary>
		/// <value>
		/// The owner document.
		/// </value>
		virtual Document* ownerDocument() = 0;

		/// <summary>
		/// Returns the parent node of an element
		/// </summary>
		/// <value>
		/// The parent node.
		/// </value>
		virtual Node* parentNode() = 0;

		/// <summary>
		/// Sets or returns the namespace prefix of a node
		/// </summary>
		/// <value>
		/// The prefix.
		/// </value>
		tstring prefix(); //: Base
		void prefix(tstring value); //: Base

		/// <summary>
		/// Returns the previous node at the same node tree level
		/// </summary>
		/// <value>
		/// The previous sibling.
		/// </value>
		virtual Node* previousSibling() = 0;

		/// <summary>
		/// Removes a child node from an element
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns></returns>
		virtual Node* removeChild(Node* node) = 0;

		/// <summary>
		/// Replaces a child node in an element
		/// </summary>
		/// <param name="newnode">The newnode.</param>
		/// <param name="oldnode">The oldnode.</param>
		/// <returns></returns>
		virtual Node* replaceChild(Node* newnode, Node* oldnode) = 0;

		/// <summary>
		/// Sets or returns the textual content of a node and its descendants
		/// </summary>
		/// <value>
		/// The content of the text.
		/// </value>
		virtual tstring textContent() = 0;
		virtual void textContent(tstring value) = 0;
	};

	/// <summary>
	/// Attr
	/// https://www.w3schools.com/jsref/dom_obj_attributes.asp
	/// </summary>
	class Attr : public Node
	{
		string_map* _attrs;
		tstring _name;
	public:
		typedef std::shared_ptr<Attr> ptr;
	public:
		Attr(string_map* attrs, tstring name);

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
		/// Returns a collection of an element's child nodes (including text and comment nodes)
		/// </summary>
		virtual NodeList<Node> childNodes() override; //: Node

		/// <summary>
		/// Clones an element
		/// </summary>
		/// <param name="deep">if set to <c>true</c> [deep].</param>
		/// <returns></returns>
		virtual Node* cloneNode(bool deep) override; //: Node

		/// <summary>
		/// Compares the document position of two elements
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns></returns>
		virtual int compareDocumentPosition(Node* node) override; //: Node

		/// <summary>
		/// Returns the first child node of an element
		/// </summary>
		/// <value>
		/// The first child.
		/// </value>
		virtual Node* firstChild() override; //: Node

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
		
		///// <summary>
		///// Returns the namespace URI associated with a given prefix
		///// </summary>
		///// <param name="prefix">The prefix.</param>
		///// <returns></returns>
		//virtual tstring lookupNamespaceURI(tstring prefix) override; //: Node

		///// <summary>
		///// Returns the prefix associated with a given namespace URI
		///// </summary>
		///// <param name="namespaceURI">The namespace URI.</param>
		///// <returns></returns>
		//virtual tstring lookupPrefix(tstring namespaceURI) override; //: Node

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
		/// Joins adjacent text nodes and removes empty text nodes in an element
		/// </summary>
		virtual void normalize() override; //: Node

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

		///// <summary>
		///// Sets or returns the namespace prefix of a node
		///// </summary>
		///// <value>
		///// The prefix.
		///// </value>
		//virtual tstring prefix() override; //: Node
		//virtual void prefix(tstring value) override; //: Node

		/// <summary>
		/// Returns the previous node at the same node tree level
		/// </summary>
		/// <value>
		/// The previous sibling.
		/// </value>
		virtual Node* previousSibling() override; //: Node

		/// <summary>
		/// Removes a child node from an element
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns></returns>
		virtual Node* removeChild(Node* node) override; //: Node

		/// <summary>
		/// Replaces a child node in an element
		/// </summary>
		/// <param name="newnode">The newnode.</param>
		/// <param name="oldnode">The oldnode.</param>
		/// <returns></returns>
		virtual Node* replaceChild(Node* newnode, Node* oldnode) override; //: Node

		/// <summary>
		/// Sets or returns the textual content of a node and its descendants
		/// </summary>
		/// <value>
		/// The content of the text.
		/// </value>
		virtual tstring textContent() override; //: Node
		virtual void textContent(tstring value) override; //: Node

		/// <summary>
		/// Returns the name of an attribute
		/// </summary>
		/// <value>
		/// The name.
		/// </value>
		tstring name();

		/// <summary>
		/// Sets or returns the value of the attribute
		/// </summary>
		/// <value>
		/// The value.
		/// </value>
		tstring value();
		void value(tstring value);

		/// <summary>
		/// Returns true if the attribute has been specified, otherwise it returns false
		/// </summary>
		/// <value>
		///   <c>true</c> if specified; otherwise, <c>false</c>.
		/// </value>
		bool specified();
	};

	/// <summary>
	/// NodeList
	/// </summary>
	template<class TNode>
	class NodeList
	{
		elements_vector list;
	public:
		NodeList();
		NodeList(elements_vector& elements);
		~NodeList();
		TNode* operator[](int index);
		TNode* item(int index);
		int length();
	};

	/// <summary>
	/// NamedNodeMap
	/// </summary>
	class NamedNodeMap
	{
		string_map m_attrs;
	public:
		static NamedNodeMap Empty;
		NamedNodeMap(string_map& attrs);

		/// <summary>
		/// Returns a specified attribute node from a NamedNodeMap
		/// </summary>
		Attr::ptr getNamedItem(tstring nodename);

		/// <summary>
		/// Gets the <see cref="Node"/> with the specified index.
		/// </summary>
		/// <value>
		/// The <see cref="Node"/>.
		/// </value>
		/// <param name="index">The index.</param>
		/// <returns></returns>
		// Overloading [] operator to access elements in array style 
		Attr::ptr operator[](int index);

		/// <summary>
		/// Returns the attribute node at a specified index in a NamedNodeMap
		/// </summary>
		/// <param name="index">The index.</param>
		/// <returns></returns>
		Attr::ptr item(int index);

		/// <summary>
		/// Returns the number of attribute nodes in a NamedNodeMap
		/// </summary>
		/// <value>
		/// The length.
		/// </value>
		int length();

		/// <summary>
		/// Removes a specified attribute node
		/// </summary>
		/// <param name="nodename">The nodename.</param>
		/// <returns></returns>
		/// <exception cref="NotImplementedException"></exception>
		Attr::ptr removeNamedItem(tstring nodename);

		/// <summary>
		/// Sets the specified attribute node (by name)
		/// </summary>
		/// <param name="node">The node.</param>
		/// <returns></returns>
		/// <exception cref="NotImplementedException"></exception>
		Attr::ptr setNamedItem(Attr::ptr node);
	};

	/// <summary>
	/// DOMTokenList
	/// </summary>
	class DOMTokenList
	{
	public:
		/// <summary>
		/// Returns the number of classes in the list.
		/// </summary>
		/// <value>
		/// The length.
		/// </value>
		int length();

		/// <summary>
		/// Returns a collection of an element's child nodes (including text and comment nodes)
		/// </summary>
		/// <param name="classes">The classes.</param>
		void add(...);

		/// <summary>
		/// Returns a Boolean value, indicating whether an element has the specified class name.
		/// </summary>
		/// <param name="class">The class.</param>
		/// <returns>
		///   <c>true</c> if [contains] [the specified class]; otherwise, <c>false</c>.
		/// </returns>
		bool contains(tstring class_);

		/// <summary>
		/// Returns the class name with a specified index number from an element
		/// </summary>
		/// <param name="index">The index.</param>
		/// <returns></returns>
		tstring item(int index);

		/// <summary>
		/// Removes one or more class names from an element.
		/// </summary>
		/// <param name="classes">The classes.</param>
		void remove(...);

		/// <summary>
		/// Toggles between a class name for an element.
		/// </summary>
		/// <param name="class">The class.</param>
		/// <param name="value">if set to <c>true</c> [value].</param>
		void toggle(tstring class_, bool value);
	};
}

#endif  // LH_API_NODE_H
