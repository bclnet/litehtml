#include <gtest/gtest.h>

#include <assert.h>
#include "litehtml.h"
#include "../containers/test/test_container.h"
using namespace litehtml;
using namespace std;

static test_container container(800, 600, ".");
static Window::ptr MakeWindow(string url, char* source) {
	Document::ptr document = document::createFromString(source, &container);
	return nullptr; // new Window();
}

TEST(HtmlNode, Test) {
	auto g = MakeWindow("", R"xyz(
<html>
<body>
	<h1>HTML DOM Attributes</h1>
	<p id="demo"></p>
</body>
</html>)xyz");
	auto document = g->document();

	// appendChild() - https://www.w3schools.com/xml/met_node_appendchild.asp
	{
		//: The following code fragment loads "books.xml" into xmlDoc and creates a node (<edition>), and appends it after the last child of the first <book> node:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				Element::ptr x; Node::ptr y; int i; Element::ptr newElement; string txt; Document::ptr xmlDoc;
				xmlDoc = xml->responseXML();
				newElement = xmlDoc->createElement("edition");
				x = xmlDoc->getElementsByTagName("book")[0];
				x->appendChild(newElement);

				// Display all elements
				auto xlen = x->childNodes().length();
				y = x->firstChild();
				txt = "";
				for (i = 0; i < xlen; i++) {
					if (y->nodeType() == 1) {
						txt += y->nodeName() + "<br>";
					}
					y = y->nextSibling();
				}
				document->getElementById("demo")->innerHTML(txt);
				assert("edition" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// attributes - NA
	{
	}

	// baseURI - https://www.w3schools.com/xml/prop_node_baseuri.asp
	{
		//: The following code fragment loads "books_ns.xml" into xmlDoc and returns the base URI of the <title> elements:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				NodeList<Element> x; int i; Document::ptr xmlDoc; string txt;
				xmlDoc = xml->responseXML();
				txt = "";
				x = xmlDoc->getElementsByTagName("title");
				for (i = 0; i < x.length(); i++) {
					txt += "<p>Prefix: " + x.item(i)->prefix() +
						"<br>Local name: " + x.item(i)->localName() +
						"<br>Namespace URI: " + x.item(i)->namespaceURI() +
						"<br>Base URI: " + x.item(i)->baseURI() + "</p>";
				}
				document->getElementById("demo")->innerHTML(txt);
				assert("Base URI: https://www.w3schools.com/xml/books_ns.xml<br>Base URI : https://www.w3schools.com/xml/books_ns.xml" == txt);
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books_ns.xml", true);
			xhttp->send();
		}
	}

	// childNodes - https://www.w3schools.com/xml/prop_node_childnodes.asp
	{
		//: The following code fragment loads "books.xml" into xmlDoc and displays the child nodes of the XML document:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				NodeList<Node> x; int i; Document::ptr xmlDoc; string txt;
				xmlDoc = xml->responseXML();
				txt = "";
				x = xmlDoc->childNodes();
				for (i = 0; i < x.length(); i++) {
					txt += "Nodename: " + x[i]->nodeName() +
						" (nodetype: " + to_string(x[i]->nodeType()) + ")<br>";
				}
				document->getElementById("demo")->innerHTML(txt);
				assert("Nodename: bookstore (nodetype: 1)" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// cloneNode() - https://www.w3schools.com/xml/met_node_clonenode.asp
	{
		//: The following code fragment loads "books.xml", clones the first <book> node and then adds it to the end of the node list:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				Node::ptr x; NodeList<Element> y; Node::ptr cloneNode; int i; Document::ptr xmlDoc; string txt;
				xmlDoc = xml->responseXML();
				txt = "";
				x = xmlDoc->getElementsByTagName("book")[0];
				cloneNode = x->cloneNode(true);
				xmlDoc->documentElement()->appendChild(cloneNode);

				// Output all titles
				y = xmlDoc->getElementsByTagName("title");
				for (i = 0; i < y.length(); i++) {
					txt += y[i]->childNodes()[0]->nodeValue() + "<br>";
				}
				document->getElementById("demo")->innerHTML(txt);
				assert("Everyday Italian<br>Harry Potter<br>XQuery Kick Start<br>Learning XML<br>Everyday Italian <br>" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// compareDocumentPosition() - https://www.w3schools.com/xml/met_node_comparedocumentposition.asp
	{
		//: The following code fragment loads "books.xml" into xmlDoc and compares the placement of two nodes (the first and the third <book> element) in the DOM hierarchy:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				auto xmlDoc = xml->responseXML();
				auto x = xmlDoc->getElementsByTagName("book")[0];
				auto y = xmlDoc->getElementsByTagName("book")[2];
				document->getElementById("demo")->innerHTML(
					to_string(x->compareDocumentPosition(y)));
				assert("4" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// firstChild - https://www.w3schools.com/xml/prop_node_firstchild.asp
	{
		//: The following code fragment loads "books.xml" into xmlDoc and displays the node name of the first child node:
		{
			// Check if the first node is an element node
			function<Node::ptr(Node::ptr)> get_firstchild = [](Node::ptr n)->Node::ptr {
				auto x = n->firstChild();
				while (x->nodeType() != 1) {
					x = x->nextSibling();
				}
				return x;
			};

			function<void(XMLHttpRequest::ptr)> myFunction = [get_firstchild, document](XMLHttpRequest::ptr xml) {
				auto xmlDoc = xml->responseXML();
				// Get the first child node of the document
				auto x = get_firstchild(xmlDoc);
				// Get the first child node of the root element
				auto y = get_firstchild(xmlDoc->documentElement());
				document->getElementById("demo")->innerHTML(
					"Nodename: " + x->nodeName() +
					" (nodetype: " + to_string(x->nodeType()) + ")<br>" +
					"Nodename: " + y->nodeName() +
					" (nodetype: " + to_string(y->nodeType()) + ")<br>");
				assert("Nodename: bookstore (nodetype: 1)<br>Nodename: book (nodetype: 1)<br>" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// getFeature(feature,version) - NA
	{
	}

	// getUserData(key) - NA
	{
	}

	// hasAttributes() - https://www.w3schools.com/xml/met_node_hasattributes.asp
	{
		//: The following code fragment loads "books.xml" into xmlDoc and returns whether the first <book> element has any attributes:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				auto xmlDoc = xml->responseXML();
				auto x = xmlDoc->getElementsByTagName("book")[0];
				document->getElementById("demo")->innerHTML(
					x->hasAttributes() ? "true" : "false");
				assert("true" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// hasChildNodes() - https://www.w3schools.com/xml/met_node_haschildnodes.asp
	{
		//: The following code fragment loads "books.xml" into xmlDoc and returns whether the first <book> element has any child nodes:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				auto xmlDoc = xml->responseXML();
				auto x = xmlDoc->getElementsByTagName("book")[0];
				document->getElementById("demo")->innerHTML(
					x->hasChildNodes() ? "true" : "false");
				assert("true" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// insertBefore() - https://www.w3schools.com/xml/met_node_insertbefore.asp
	{
		//: The following code fragment loads "books.xml", creates a new <book> node and inserts it before the last <book> node:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				auto xmlDoc = xml->responseXML();
				auto newNode = xmlDoc->createElement("book");
				auto x = xmlDoc->documentElement();
				auto y = xmlDoc->getElementsByTagName("book");
				document->getElementById("demo")->innerHTML(
					"Book elements before: " + to_string(y.length()) + "<br>");

				x->insertBefore(newNode, y[3]);
				document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() +
					"Book elements after: " + to_string(y.length()));
				assert("Book elements before : 4<br>Book elements after : 5<br>" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// isDefaultNamespace(URI) - NA
	{
	}

	// isEqualNode() - https://www.w3schools.com/xml/met_node_isequalnode.asp
	{
		//: The following code fragment loads "books.xml" into xmlDoc and returns whether two nodes are equal:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				auto xmlDoc = xml->responseXML();
				auto x = xmlDoc->getElementsByTagName("book")[0];
				auto y = xmlDoc->getElementsByTagName("book")[2];
				document->getElementById("demo")->innerHTML(
					x->isEqualNode(y) ? "true" : "false");
				assert("true" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// isSameNode() - https://www.w3schools.com/xml/met_node_issamenode.asp
	{
		//: The following code fragment loads "books.xml" into xmlDoc and tests whether the two nodes are the same node:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				auto xmlDoc = xml->responseXML();
				auto x = xmlDoc->getElementsByTagName("book")[1];
				auto y = xmlDoc->getElementsByTagName("book")[1];
				document->getElementById("demo")->innerHTML(
					x->isSameNode(y) ? "true" : "false");
				assert("true" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// lastChild - https://www.w3schools.com/xml/prop_node_lastchild.asp
	{
		//: The following code fragment loads "books.xml" into xmlDoc and displays the node name of the last child node of the document:
		{
			// Check if the last node is an element node
			function<Node::ptr(Node::ptr)> get_lastchild = [](Node::ptr n)->Node::ptr {
				auto x = n->lastChild();
				while (x->nodeType() != 1) {
					x = x->previousSibling();
				}
				return x;
			};

			function<void(XMLHttpRequest::ptr)> myFunction = [get_lastchild, document](XMLHttpRequest::ptr xml) {
				auto xmlDoc = xml->responseXML();
				// Get the last child node of the document
				auto x = get_lastchild(xmlDoc);
				// Get the last child node of the root element
				auto y = get_lastchild(xmlDoc->documentElement());
				document->getElementById("demo")->innerHTML(
					"Nodename: " + x->nodeName() +
					" (nodetype: " + to_string(x->nodeType()) + ")<br>" +
					"Nodename: " + y->nodeName() +
					" (nodetype: " + to_string(y->nodeType()) + ")<br>");
				assert("Nodename: bookstore (nodetype: 1)<br>Nodename: book (nodetype: 1)<br>" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// lookupNamespaceURI() - https://www.w3schools.com/xml/met_node_lookupnamespaceuri.asp
	{
		//: The following code fragment loads "books_ns.xml" into xmlDoc and finds the namespace URI for the given "c" prefix:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				auto xmlDoc = xml->responseXML();
				auto x = xmlDoc->getElementsByTagName("book")[0];
				document->getElementById("demo")->innerHTML(
					x->lookupNamespaceURI("c"));
				assert("https://www.w3schools.com/children/" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books_ns.xml", true);
			xhttp->send();
		}
	}

	// lookupPrefix() - https://www.w3schools.com/xml/met_node_lookupprefix.asp
	{
		//: The following code fragment loads "books_ns.xml" into xmlDoc and finds the prefix for the given namespace URI:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				auto xmlDoc = xml->responseXML();
				auto x = xmlDoc->getElementsByTagName("book")[0];
				document->getElementById("demo")->innerHTML(
					x->lookupPrefix("https://www.w3schools.com/children/"));
				assert("c" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books_ns.xml", true);
			xhttp->send();
		}
	}

	// nextSibling - https://www.w3schools.com/xml/prop_node_nextsibling.asp
	{
		//: The following code fragment loads "books.xml" into xmlDoc and gets the next sibling node from the first <title> element:
		{
			// Check if the next sibling node is an element node
			function<Node::ptr(Node::ptr)> get_nextsibling = [](Node::ptr n)->Node::ptr {
				auto x = n->nextSibling();
				while (x->nodeType() != 1) {
					x = x->nextSibling();
				}
				return x;
			};

			function<void(XMLHttpRequest::ptr)> myFunction = [get_nextsibling, document](XMLHttpRequest::ptr xml) {
				auto xmlDoc = xml->responseXML();
				auto x = xmlDoc->getElementsByTagName("title")[0];
				auto y = get_nextsibling(x);
				document->getElementById("demo")->innerHTML(x->nodeName() + " = " +
					x->childNodes()[0]->nodeValue() +
					"<br>Next sibling: " + y->nodeName() + " = " +
					y->childNodes()[0]->nodeValue());
				assert("title = Everyday Italian<br>Next sibling: author = Giada De Laurentiis<br>" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// nodeName - https://www.w3schools.com/xml/prop_node_nodename.asp
	{
		//: The following code fragment loads "books.xml" into xmlDoc and displays the node name and node type of the root node:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				Element::ptr x; NodeList<Node> y; int i; Document::ptr xmlDoc; string txt;
				xmlDoc = xml->responseXML();
				txt = "";
				x = xmlDoc->documentElement();
				y = x->childNodes();
				for (i = 0; i < y.length(); i++) {
					txt += "Nodename: " + y[i]->nodeName() +
						" (nodetype: " + to_string(y[i]->nodeType()) + ")<br>";
					for (auto z = 0; z < y[i]->childNodes().length(); z++) {
						txt += "Nodename: " + y[i]->childNodes()[z]->nodeName() +
							" (nodetype: " + to_string(y[i]->childNodes()[z]->nodeType()) + ")<br>";
					}
				}
				document->getElementById("demo")->innerHTML(
					"Nodename: " + xmlDoc->nodeName() +
					" (nodetype: " + to_string(xmlDoc->nodeType()) + ")<br>" +
					"Nodename: " + x->nodeName() +
					" (nodetype: " + to_string(x->nodeType()) + ")<br>" +
					txt);
				assert(document->getElementById("demo")->innerHTML().length() > 10);
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// nodeType - https://www.w3schools.com/xml/prop_node_nodetype.asp
	{
		//: The following code fragment loads "books.xml" into xmlDoc and displays the node name and node type of the root node:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				Element::ptr x; NodeList<Node> y; int i; Document::ptr xmlDoc; string txt;
				xmlDoc = xml->responseXML();
				txt = "";
				x = xmlDoc->documentElement();
				y = x->childNodes();
				for (i = 0; i < y.length(); i++) {
					txt += "Nodename: " + y[i]->nodeName() +
						" (nodetype: " + to_string(y[i]->nodeType()) + ")<br>";
					for (auto z = 0; z < y[i]->childNodes().length(); z++) {
						txt += "Nodename: " + y[i]->childNodes()[z]->nodeName() +
							" (nodetype: " + to_string(y[i]->childNodes()[z]->nodeType()) + ")<br>";
					}
				}
				document->getElementById("demo")->innerHTML(
					"Nodename: " + xmlDoc->nodeName() +
					" (nodetype: " + to_string(xmlDoc->nodeType()) + ")<br>" +
					"Nodename: " + x->nodeName() +
					" (nodetype: " + to_string(x->nodeType()) + ")<br>");
				assert(document->getElementById("demo")->innerHTML().length() > 10);
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// nodeValue - https://www.w3schools.com/xml/prop_node_nodevalue.asp
	{
		//: The following code fragment loads "books.xml" into xmlDoc and displays the node name and node value of the root node:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				Element::ptr x; NodeList<Node> y; int i; Document::ptr xmlDoc; string txt;
				xmlDoc = xml->responseXML();
				txt = "";
				x = xmlDoc->documentElement();
				y = xmlDoc->documentElement()->childNodes();
				for (i = 0; i < y.length(); i++) {
					if (y[i]->nodeType() != 3) {
						txt += "Nodename: " + y[i]->nodeName() +
							" (value: " + y[i]->childNodes()[0]->nodeValue() + ")<br>";
					}
					for (auto z = 0; z < y[i]->childNodes().length(); z++) {
						if (y[i]->childNodes()[z]->nodeType() != 3) {
							txt += "Nodename: " + y[i]->childNodes()[z]->nodeName() +
								" (value: " + y[i]->childNodes()[z]->childNodes()[0]->nodeValue() + ")<br>";
						}
					}
				}
				document->getElementById("demo")->innerHTML(
					"Nodename: " + xmlDoc->nodeName() +
					" (value: " + xmlDoc->childNodes()[0]->nodeValue() + ")<br>" +
					"Nodename: " + x->nodeName() +
					" (value: " + x->childNodes()[0]->nodeValue() + ")<br>" +
					txt);
				assert(document->getElementById("demo")->innerHTML().length() > 10);
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// normalize() - https://www.w3schools.com/xml/met_node_normalize.asp
	{
	}

	// ownerDocument - https://www.w3schools.com/xml/prop_node_ownerdocument.asp
	{
		//: The following code fragment loads "books.xml" into xmlDoc and returns the root element of the first <title> node:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				auto xmlDoc = xml->responseXML();
				auto x = xmlDoc->getElementsByTagName("title")[0]->ownerDocument();
				document->getElementById("demo")->innerHTML(
					"Nodename: " + x->nodeName() +
					" (nodetype: " + to_string(x->nodeType()) + ")");
				assert("Nodename: #document (nodetype: 9)" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// parentNode - https://www.w3schools.com/xml/prop_node_parentnode.asp
	{
		//: The following code fragment loads "books.xml" into xmlDoc and returns the parent node of the first <title> element:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				auto xmlDoc = xml->responseXML();
				auto x = xmlDoc->getElementsByTagName("title")[0];
				document->getElementById("demo")->innerHTML(
					"Parent node: " + x->parentNode()->nodeName());
				assert("Parent node: book" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// prefix - https://www.w3schools.com/xml/prop_node_prefix.asp
	{
		//: The following code fragment loads "books_ns.xml" into xmlDoc and returns the namespace prefix of the <title> elements:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				NodeList<Element> x; int i; Document::ptr xmlDoc; string txt;
				xmlDoc = xml->responseXML();
				txt = "";
				x = xmlDoc->getElementsByTagName("title");
				for (i = 0; i < x.length(); i++) {
					txt += "<p>Prefix: " + x.item(i)->prefix() +
						"<br>Local name: " + x.item(i)->localName() +
						"<br>Namespace URI: " + x.item(i)->namespaceURI() +
						"<br>Base URI: " + x.item(i)->baseURI() + "</p>";
				}
				document->getElementById("demo")->innerHTML(txt);
				assert("Prefix: c<br>Prefix : x<br>" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books_ns.xml", true);
			xhttp->send();
		}
	}

	// previousSibling - https://www.w3schools.com/xml/prop_node_previoussibling.asp
	{
		//: The following code fragment loads "books.xml" into xmlDoc and gets the previous sibling node from the first <author> element:
		{
			// Check if the previous sibling node is an element node
			function<Node::ptr(Node::ptr)> get_previoussibling = [](Node::ptr n)->Node::ptr {
				auto x = n->previousSibling();
				while (x->nodeType() != 1) {
					x = x->previousSibling();
				}
				return x;
			};

			function<void(XMLHttpRequest::ptr)> myFunction = [get_previoussibling, document](XMLHttpRequest::ptr xml) {
				auto xmlDoc = xml->responseXML();
				auto x = xmlDoc->getElementsByTagName("author")[0];
				auto y = get_previoussibling(x);
				document->getElementById("demo")->innerHTML(x->nodeName() + " = " +
					x->childNodes()[0]->nodeValue() +
					"<br>Previous sibling: " + y->nodeName() + " = " +
					y->childNodes()[0]->nodeValue());
				assert("author = Giada De Laurentiis<br>Previous sibling: title = Everyday Italian<br>" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// removeChild() - https://www.w3schools.com/xml/met_node_removechild.asp
	{
		//: The following code fragment loads "books.xml" into xmlDoc and removes the first child node in the first <book> node:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				auto xmlDoc = xml->responseXML();
				auto root = xmlDoc->documentElement();
				auto currNode = root->childNodes()[1];
				auto removedNode = currNode->removeChild(currNode->childNodes()[1]);
				document->getElementById("demo")->innerHTML(
					"Removed node: " + removedNode->nodeName());
				assert("Removed node: title" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// replaceChild() - https://www.w3schools.com/xml/met_node_replacechild.asp
	{
		//: The following code fragment loads "books.xml" into xmlDoc and replaces the first <book> element:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				Element::ptr x; Node::ptr y; NodeList<Element> z; int i; Element::ptr newNode; Element::ptr newTitle; Node::ptr newText; Document::ptr xmlDoc; string txt;
				xmlDoc = xml->responseXML();
				txt = "";
				x = xmlDoc->documentElement();

				// Create a book element, title element and a text node
				newNode = xmlDoc->createElement("book");
				newTitle = xmlDoc->createElement("title");
				newText = xmlDoc->createTextNode("A Notebook");

				// Add a text node to the title node
				newTitle->appendChild(newText);

				// Add the title node to the book node
				newNode->appendChild(newTitle);

				y = xmlDoc->getElementsByTagName("book")[0];

				// Replace the first book node with the new book node
				x->replaceChild(newNode, y);

				z = xmlDoc->getElementsByTagName("title");
				// Output all titles
				for (i = 0; i < z.length(); i++) {
					txt += z[i]->childNodes()[0]->nodeValue() + "<br>";
				}
				document->getElementById("demo")->innerHTML(txt);
				assert("A Notebook<br>Harry Potter<br>XQuery Kick Start<<br>Learning XML<br>" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}

	// setUserData(key,data,handler) - NA
	{
	}

	// textContent - https://www.w3schools.com/xml/prop_node_textcontent.asp
	{
		//: The following code fragment loads "books.xml" into xmlDoc and returns the textual content of the <book> elements:
		{
			function<void(XMLHttpRequest::ptr)> myFunction = [document](XMLHttpRequest::ptr xml) {
				NodeList<Element> x; int i; Document::ptr xmlDoc; string txt;
				xmlDoc = xml->responseXML();
				txt = "";
				x = xmlDoc->getElementsByTagName("book");
				for (i = 0; i < x.length(); i++) {
					txt += x.item(i)->textContent() + "<br>";
				}
				document->getElementById("demo")->innerHTML(txt);
				assert("Everyday Italian Giada De Laurentiis 2005 30.00<br>Harry Potter J K.Rowling 2005 29.99<br>XQuery Kick Start James McGovern Per Bothner Kurt Cagle James Linn<br>Vaidyanathan Nagarajan 2003 49.99<br>Learning XML Erik T.Ray 2003 39.95<br>" == document->getElementById("demo")->innerHTML());
			};

			auto xhttp = new XMLHttpRequest();
			xhttp->onreadystatechange = [myFunction](XMLHttpRequest::ptr _this) {
				if (_this->readyState() == 4 && _this->status() == 200) {
					myFunction(move(_this));
				}
			};
			xhttp->open("GET", "books.xml", true);
			xhttp->send();
		}
	}
}
