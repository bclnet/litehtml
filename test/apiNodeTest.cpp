#include <gtest/gtest.h>

#include <assert.h>
#include "litehtml.h"
#include "../containers/test/test_container.h"
using namespace std;
using namespace litehtml;

static test_container container(800, 600, ".");
static document::ptr MakeDocument(char* source) { return document::createFromString(source, &container); }

TEST(Node, Attrib) {
	auto document = MakeDocument(R"xyz(
<html>
<body>
	<button onclick="myFunction()">Try it</button>
	<p id="demo"></p>
	<div class="w3-code notranslate">
		<img src="pic_bulboff.gif" width="100" height="180">
	</div>
</body>
</html>)xyz");

	// https://www.w3schools.com/jsref/prop_attr_name.asp
	{
		auto x = document->getElementsByTagName("BUTTON")[0]->attributes()[0]->name();
		assert(!strcmp("onclick", x.c_str()));
	}

	// https://www.w3schools.com/jsref/prop_attr_value.asp
	{
		auto x = document->getElementsByTagName("BUTTON")[0]->attributes()[0]->value();
		assert(!strcmp("myFunction()", x.c_str()));
	}
	{
		auto x = document->getElementsByTagName("IMG")[0];
		x->getAttributeNode("src")->value("pic_bulbon.gif");
		assert(!strcmp("pic_bulbon.gif", x->getAttributeNode("src")->value().c_str()));
	}

	// https://www.w3schools.com/jsref/prop_attr_specified.asp
	{
		auto x = document->getElementById("demo")->attributes()[0]->specified();
		assert(x);
	}
}

TEST(Node, Nodemap) {
	auto document = MakeDocument(R"xyz(
<html>
<body>
	<h1>Hello World</h1>
	<input type="button" value="OK" />
	<img id="myImg" alt="Flower" src="klematis.jpg" width="150" height="113">
	<button id="myBtn" onclick="myFunction()" class="example">Try it</button>
	<p id="demo"></p>
</body>
</html>)xyz");

	// https://www.w3schools.com/jsref/met_namednodemap_getnameditem.asp
	{
		auto btn = document->getElementsByTagName("BUTTON")[0];
		auto x = btn->attributes().getNamedItem("onclick")->value();
		assert(!strcmp("myFunction()", x.c_str()));
	}

	// https://www.w3schools.com/jsref/met_namednodemap_item.asp
	{
		auto x = document->getElementsByTagName("BUTTON")[0]->attributes().item(0)->nodeName();
		assert(!strcmp("class", x.c_str()));
	}
	{
		auto x = document->getElementsByTagName("BUTTON")[0]->attributes().item(1);   // The 2nd attribute
		assert(x != nullptr);
	}
	{
		auto x = document->getElementsByTagName("BUTTON")[0]->attributes()[1];		// The 2nd attribute
		assert(x != nullptr);
	}
	{
		document->getElementsByTagName("BUTTON")[0]->attributes()[1]->value("newClass");
	}

	// https://www.w3schools.com/jsref/prop_namednodemap_length.asp
	{
		auto x = document->getElementsByTagName("BUTTON")[0]->attributes().length();
		assert(x == 3);
	}
	{
		auto txt = string();
		auto x = document->getElementById("myBtn")->attributes();

		for (auto i = 0; i < x.length(); i++)
		{
			txt += "Attribute name: " + string(x[i]->name()) + "<br>";
		}
		assert(!strcmp("Attribute name: class<br>Attribute name: id<br>Attribute name: onclick<br>", txt.c_str()));
	}
	{
		auto x = document->getElementById("myImg")->attributes().length();
		assert(x == 5);
	}
	{
		auto txt = string();
		auto x = document->getElementById("myImg");

		for (auto i = 0; i < x->attributes().length(); i++)
		{
			txt = txt + string(x->attributes()[i]->name()) + " = " + string(x->attributes()[i]->value()) + "<br>";
		}
		assert(!strcmp("alt = Flower<br>height = 113<br>id = myImg<br>src = klematis.jpg<br>width = 150<br>", txt.c_str()));
	}

	// https://www.w3schools.com/jsref/met_namednodemap_removenameditem.asp
	{
		auto btn = document->getElementsByTagName("INPUT")[0];
		btn->attributes().removeNamedItem("type");
	}

	// https://www.w3schools.com/jsref/met_namednodemap_setnameditem.asp
	{
		auto h = document->getElementsByTagName("H1")[0];
		auto typ = document->createAttribute("class");
		//typ->value("democlass");
		//h->attributes().setNamedItem(typ);
	}
}

TEST(Node, Property) {
	auto document = MakeDocument(R"xyz(
<html>
<body>
	<p id="demo"></p>
</body>
</html>)xyz");

	// https://www.w3schools.com/xml/prop_node_baseuri.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books_ns.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			NodeList<Element> x; int i; Document* xmlDoc; string txt;
			xmlDoc = xml->responseXML();
			txt = "";
			x = xmlDoc->getElementsByTagName("title");
			for (i = 0; i < x.length(); i++)
			{
				txt += "Base URI: " + x.item(i)->baseURI() + "<br>";
			}
			document->getElementById("demo")->innerHTML(txt);
		};

		//wait
//		assert(!t_strcmp(
//			R"xyz(Base URI: https://www.w3schools.com/xml/books_ns.xml
//Base URI : https://www.w3schools.com/xml/books_ns.xml
//")xyz"), document.getElementById("demo").innerHTML.c_str());
	}

	// https://www.w3schools.com/xml/prop_node_childnodes.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			NodeList<Node> x; int i; Document* xmlDoc; string txt;
			xmlDoc = xml->responseXML();
			txt = "";
			x = xmlDoc->childNodes();
			for (i = 0; i < x.length(); i++)
			{
				txt += "Nodename: " + x[i]->nodeName() +
					" (nodetype: " + std::to_string(x[i]->nodeType()) + ")";
			}
			document->getElementById("demo")->innerHTML(txt);
		};

		//wait
		//Assert.AreEqual("Nodename: bookstore (nodetype: 1)", document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/prop_node_firstchild.asp
	{
		std::function<Node*(Document*)> get_firstchild;
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		// Check if the first node is an element node
		get_firstchild = [](Document* n)->Node*
		{
			auto x = n->firstChild();
			while (x->nodeType() != 1)
			{
				x = x->nextSibling();
			}
			return x;
		};

		myFunction = [get_firstchild, document](XMLHttpRequest* xml)
		{
			auto xmlDoc = xml->responseXML();
			auto x = get_firstchild(xmlDoc);
			document->getElementById("demo")->innerHTML(
				"Nodename: " + x->nodeName() +
				" (nodetype: " + std::to_string(x->nodeType()) + ")<br>");
		};

		//wait
		//Assert.AreEqual("Nodename: bookstore (nodetype: 1)", document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/prop_node_lastchild.asp
	{
		std::function<Node*(Document*)> get_lastchild;
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		// Check if the last node is an element node
		get_lastchild = [](Document* n)->Node*
		{
			auto x = n->lastChild();
			while (x->nodeType() != 1)
			{
				x = x->previousSibling();
			}
			return x;
		};

		myFunction = [get_lastchild, document](XMLHttpRequest* xml)
		{
			auto xmlDoc = xml->responseXML();
			auto x = get_lastchild(xmlDoc);
			document->getElementById("demo")->innerHTML(
				"Nodename: " + x->nodeName() +
				" (nodetype: " + std::to_string(x->nodeType()) + ")<br>");
		};

		//wait
		//Assert.AreEqual("Nodename: bookstore (nodetype: 1)", document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/prop_node_nextsibling.asp
	{
		std::function<Node*(Node*)> get_nextsibling;
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		// Check if the next sibling node is an element node
		get_nextsibling = [](Node* n)->Node*
		{
			auto x = n->nextSibling();
			while (x->nodeType() != 1)
			{
				x = x->nextSibling();
			}
			return x;
		};

		myFunction = [get_nextsibling, document](XMLHttpRequest* xml)
		{
			auto xmlDoc = xml->responseXML();
			auto x = xmlDoc->getElementsByTagName("title")[0];
			auto y = get_nextsibling(x);
			document->getElementById("demo")->innerHTML(x->nodeName() + " = " +
				x->childNodes()[0]->nodeValue() +
				"<br>Next sibling: " + y->nodeName() + " = " +
				y->childNodes()[0]->nodeValue());
		};

		//wait
		//Assert.AreEqual(
		//	@"title = Everyday Italian
		//	Next sibling : author = Giada De Laurentiis".Replace("\n", "<br>"), document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/prop_node_nodename.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			auto xmlDoc = xml->responseXML();
			document->getElementById("demo")->innerHTML(
				"Nodename: " + xmlDoc->nodeName() +
				" (nodetype: " + std::to_string(xmlDoc->nodeType()) + ")");
		};

		//wait
		//Assert.AreEqual("Nodename: #document (nodetype: 9)", document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/prop_node_nodetype.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			auto xmlDoc = xml->responseXML();
			document->getElementById("demo")->innerHTML(
				"Nodename: " + xmlDoc->nodeName() +
				" (nodetype: " + std::to_string(xmlDoc->nodeType()) + ")");
		};

		//wait
		//Assert.AreEqual("Nodename: #document (nodetype: 9)", document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/prop_node_nodevalue.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			auto xmlDoc = xml->responseXML();
			document->getElementById("demo")->innerHTML(
				"Nodename: " + xmlDoc->nodeName() +
				(" (value: " + xmlDoc->childNodes()[0]->nodeValue()) + ")");
		};

		//wait
		//Assert.AreEqual("Nodename: #document (value: null)", document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/prop_node_ownerdocument.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			auto xmlDoc = xml->responseXML();
			auto x = xmlDoc->getElementsByTagName("title")[0]->ownerDocument();
			document->getElementById("demo")->innerHTML(
				"Nodename: " + x->nodeName() +
				" (nodetype: " + std::to_string(x->nodeType()) + ")");
		};

		//wait
		//Assert.AreEqual("Nodename: #document (nodetype: 9)", document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/prop_node_parentnode.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			auto xmlDoc = xml->responseXML();
			auto x = xmlDoc->getElementsByTagName("title")[0];
			document->getElementById("demo")->innerHTML(
				"Parent node: " + x->parentNode()->nodeName());
		};

		//wait
		//Assert.AreEqual("Parent node: book", document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/prop_node_prefix.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books_ns.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			NodeList<Element> x; int i; Document* xmlDoc; string txt;
			xmlDoc = xml->responseXML();
			txt = "";
			x = xmlDoc->getElementsByTagName("title");
			for (i = 0; i < x.length(); i++)
			{
				txt += "Prefix: " + x.item(i)->prefix() + "<br>";
			}
			document->getElementById("demo")->innerHTML(txt);
		};

		//wait
		//Assert.AreEqual(
		//	@"Prefix: c
		//	Prefix : x
		//	".Replace("\n", "<br>"), document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/prop_node_previoussibling.asp
	{
		std::function<Node*(Node*)> get_previoussibling;
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		// Check if the previous sibling node is an element node
		get_previoussibling = [](Node* n)->Node*
		{
			auto x = n->previousSibling();
			while (x->nodeType() != 1)
			{
				x = x->previousSibling();
			}
			return x;
		};

		myFunction = [get_previoussibling, document](XMLHttpRequest* xml)
		{
			auto xmlDoc = xml->responseXML();
			auto x = xmlDoc->getElementsByTagName("author")[0];
			auto y = get_previoussibling(x);
			document->getElementById("demo")->innerHTML(x->nodeName() + " = " +
				x->childNodes()[0]->nodeValue() +
				"<br>Previous sibling: " + y->nodeName() + " = " +
				y->childNodes()[0]->nodeValue());
		};

		//wait
		//Assert.AreEqual(
		//	@"author = Giada De Laurentiis
		//	Previous sibling : title = Everyday Italian".Replace("\n", "<br>"), document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/prop_node_textcontent.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			NodeList<Element> x; int i; Document* xmlDoc; string txt;
			xmlDoc = xml->responseXML();
			txt = "";
			x = xmlDoc->getElementsByTagName("book");
			for (i = 0; i < x.length(); i++)
			{
				txt += x.item(i)->textContent() + "<br>";
			}
			document->getElementById("demo")->innerHTML(txt);
		};

		//wait
		//Assert.AreEqual(
		//	@"Everyday Italian Giada De Laurentiis 2005 30.00
		//	Harry Potter J K.Rowling 2005 29.99
		//	XQuery Kick Start James McGovern Per Bothner Kurt Cagle James Linn
		//	Vaidyanathan Nagarajan 2003 49.99
		//	Learning XML Erik T.Ray 2003 39.95
		//	".Replace("\n", "<br>"), document.getElementById("demo").innerHTML);
	}
}

TEST(Node, Method) {
	auto document = MakeDocument(R"xyz(
<html>
<body>
	<p id="demo"></p>
</body>
</html>)xyz");

	// https://www.w3schools.com/xml/met_node_appendchild.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			auto xmlDoc = xml->responseXML();
			auto newel = xmlDoc->createElement("edition");
			auto x = (Element*)xmlDoc->getElementsByTagName("book")[0];
			x->appendChild(newel);
			document->getElementById("demo")->innerHTML(
				x->getElementsByTagName("edition")[0]->nodeName());
		};

		//wait
		//Assert.AreEqual("edition", document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/met_node_clonenode.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			Node* x; NodeList<Element> y; Node* cloneNode; int i; Document* xmlDoc; string txt;
			xmlDoc = xml->responseXML();
			txt = "";
			x = xmlDoc->getElementsByTagName("book")[0];
			cloneNode = x->cloneNode(true);
			xmlDoc->documentElement()->appendChild(cloneNode);

			// Output all titles
			y = xmlDoc->getElementsByTagName("title");
			for (i = 0; i < y.length(); i++)
			{
				txt += y[i]->childNodes()[0]->nodeValue() + "<br>";
			}
			document->getElementById("demo")->innerHTML(txt);
		};

		//wait
		//Assert.AreEqual(
		//	@"Everyday Italian
		//	Harry Potter
		//	XQuery Kick Start
		//	Learning XML
		//	Everyday Italian
		//	".Replace("\n", "<br>"), document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/met_node_comparedocumentposition.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			auto xmlDoc = xml->responseXML();
			auto x = xmlDoc->getElementsByTagName("book")[0];
			auto y = xmlDoc->getElementsByTagName("book")[2];
			document->getElementById("demo")->innerHTML(
				std::to_string(x->compareDocumentPosition(y)));
		};

		//wait
		//Assert.AreEqual("4", document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/met_node_hasattributes.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			auto xmlDoc = xml->responseXML();
			auto x = xmlDoc->getElementsByTagName("book")[0];
			document->getElementById("demo")->innerHTML(
				x->hasAttributes() ? "true" : "false");
		};

		//wait
		//Assert.AreEqual("true", document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/met_node_haschildnodes.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			auto xmlDoc = xml->responseXML();
			auto x = xmlDoc->getElementsByTagName("book")[0];
			document->getElementById("demo")->innerHTML(
				x->hasChildNodes() ? "true" : "false");
		};

		//wait
		//Assert.AreEqual("true", document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/met_node_insertbefore.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			auto xmlDoc = xml->responseXML();
			auto newNode = xmlDoc->createElement("book");
			auto x = xmlDoc->documentElement();
			auto y = xmlDoc->getElementsByTagName("book");
			document->getElementById("demo")->innerHTML(
				"Book elements before: " + std::to_string(y.length()) + "<br>");

			x->insertBefore(newNode, y[3]);
			document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() +
				"Book elements after: " + std::to_string(y.length()));
		};

		//wait
		//Assert.AreEqual(
		//	@"Book elements before : 4
		//	Book elements after : 5".Replace("\n", "<br>"), document.getElementById("demo").innerHTML);
	}

	// isDefaultNamespace(URI)
	{
		// none
	}

	// https://www.w3schools.com/xml/met_node_isequalnode.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			auto xmlDoc = xml->responseXML();
			auto x = xmlDoc->getElementsByTagName("book")[0];
			auto y = xmlDoc->getElementsByTagName("book")[2];
			document->getElementById("demo")->innerHTML(
				x->isEqualNode(y) ? "true" : "false");
		};

		//wait
		//Assert.AreEqual("true", document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/met_node_issamenode.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			auto xmlDoc = xml->responseXML();
			auto x = xmlDoc->getElementsByTagName("book")[1];
			auto y = xmlDoc->getElementsByTagName("book")[1];
			document->getElementById("demo")->innerHTML(
				x->isSameNode(y) ? "true" : "false");
		};

		//wait
		//Assert.AreEqual("true", document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/met_node_lookupnamespaceuri.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books_ns.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			auto xmlDoc = xml->responseXML();
			auto x = xmlDoc->getElementsByTagName("book")[0];
			document->getElementById("demo")->innerHTML(
				x->lookupNamespaceURI("c"));
		};

		//wait
		//Assert.AreEqual("https://www.w3schools.com/children/", document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/met_node_lookupprefix.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books_ns.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			auto xmlDoc = xml->responseXML();
			auto x = xmlDoc->getElementsByTagName("book")[0];
			document->getElementById("demo")->innerHTML(
				x->lookupPrefix("https://www.w3schools.com/children/"));
		};

		//wait
		//Assert.AreEqual("c", document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/met_node_normalize.asp
	{
		// none
	}

	// https://www.w3schools.com/xml/met_node_removechild.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			auto xmlDoc = xml->responseXML();
			auto root = xmlDoc->documentElement();
			auto currNode = root->childNodes()[1];
			auto removedNode = currNode->removeChild(currNode->childNodes()[1]);
			document->getElementById("demo")->innerHTML(
				"Removed node: " + removedNode->nodeName());
		};

		//wait
		//Assert.AreEqual("Removed node: title", document.getElementById("demo").innerHTML);
	}

	// https://www.w3schools.com/xml/met_node_replacechild.asp
	{
		std::function<void(XMLHttpRequest*)> myFunction;

		auto xhttp = new XMLHttpRequest();
		xhttp->onreadystatechange = [myFunction](XMLHttpRequest* _this)
		{
			if (_this->readyState() == 4 && _this->status() == 200)
			{
				myFunction(_this);
			}
		};
		xhttp->open("GET", "books.xml", true);
		xhttp->send();

		myFunction = [document](XMLHttpRequest* xml)
		{
			Element* x; Node* y; NodeList<Element> z; int i; Element* newNode; Element* newTitle; Node* newText; Document* xmlDoc; string txt;
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
			for (i = 0; i < z.length(); i++)
			{
				txt += z[i]->childNodes()[0]->nodeValue() + "<br>";
			}
			document->getElementById("demo")->innerHTML(txt);
		};

		//wait
		//Assert.AreEqual(
		//	@"A Notebook
		//	Harry Potter
		//	XQuery Kick Start
		//	Learning XML
		//	", document.getElementById("demo").innerHTML);
	}
}
