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

TEST(HtmlAttributes, Test) {
	auto g = MakeWindow("", R"xyz(
<html>
<body>
	<h1>HTML DOM Attributes</h1>
	<p id="demo"></p>
	<img id="light" src="pic_bulbon.gif" width="100" height="180">
	<button id="myButton" onclick="myFunction() class="example"">Get it</button>
	<div id="myDiv" style="background-color:red;width:50px;height:50px"></div>
	<div id="myDiv2" class="class1"></div>
	<button id="myBtn" onclick="myFunction()" class="example">Try it</button>
	<img id="myImg" alt="Flower" src="klematis.jpg" width="150" height="113">
	<input id="myInput" type="button" value="OK">
</body>
</html>)xyz");
	auto document = g->document();

	// getNamedItem() - https://www.w3schools.com/jsref/met_namednodemap_getnameditem.asp
	{
		//: Get the value of the scr attribute of an image:
		{
			auto nodeMap = document->getElementById("light")->attributes();
			auto value = nodeMap.getNamedItem("src")->value();

			document->getElementById("demo")->innerHTML(value);
			assert("pic_bulbon.gif" == value);
		}
		//: Get the value of the onclick attribute of a button:
		{
			auto nodeMap = document->getElementById("myButton")->attributes();
			auto value = nodeMap.getNamedItem("onclick")->value();

			document->getElementById("demo")->innerHTML(value);
			assert("myFunction() class=" == value);
		}
	}

	// isId *Deprecated* - https://www.w3schools.com/jsref/prop_attr_isid.asp
	{
		// DEPRECATED
	}

	// item() - https://www.w3schools.com/jsref/met_namednodemap_item.asp
	{
		//: Get the name of the first attributes of an element:
		{
			auto nodeMap = document->getElementById("myDiv")->attributes();
			auto name1 = nodeMap.item(0)->name();
			auto name2 = nodeMap.item(1)->name();

			document->getElementById("demo")->innerHTML(
				"First attribute is: " + name1 +
				"<br>Second is: " + name2);
			assert("id" == name1);
			assert("style" == name2);
		}
		//:
		{
			auto nodeMap = document->getElementById("myDiv2")->attributes();
			auto name1 = nodeMap[0]->name();
			auto name2 = nodeMap[1]->name();

			document->getElementById("demo")->innerHTML(
				"First attribute is: " + name1 +
				"<br>Second is: " + name2);
			assert("id" != name1);
			assert("style" != name2);
		}
		//: Change the class (the color) of an element:
		{
			function<void()> myFunction = [document]() {
				document->getElementById("myDiv2")->attributes().item(1)->value("class2");
				assert("class2" == document->getElementById("myDiv2")->attributes().item(1)->value());
			};

			myFunction();
		}
		//: Change the class (the color) of an element:
		{
			function<void()> myFunction = [document]() {
				document->getElementById("myDiv2")->attributes()[1]->value("class2");
				assert("class2" == document->getElementById("myDiv2")->attributes()[1]->value());
			};

			myFunction();
		}
	}

	// length - https://www.w3schools.com/jsref/prop_namednodemap_length.asp
	{
		//: Get the number of attributes of an HTML element:
		{
			auto num = document->getElementById("myButton")->attributes().length();
			document->getElementById("demo")->innerHTML(to_string(num));
			assert(num == 3);
		}
		//: Get the name of all attributes:
		{
			string text = "";
			auto nodeMap = document->getElementById("myBtn")->attributes();
			for (auto i = 0; i < nodeMap.length(); i++) {
				text += nodeMap[i]->name() + "<br>";
			}
			document->getElementById("demo")->innerHTML(text);
			assert("class<br>id<br>onclick<br>" == text);
		}
		//: How many attributes does "myImg" have:
		{
			auto num = document->getElementById("myImg")->attributes().length();
			document->getElementById("demo")->innerHTML(to_string(num));
			assert(num == 5);
		}
		//: Get all attributes:
		{
			auto nodeMap = document->getElementById("myImg")->attributes();
			auto text = string();
			for (auto i = 0; i < nodeMap.length(); i++) {
				text += nodeMap[i]->name() + " = " + nodeMap[i]->value() + "<br>";
			}
			document->getElementById("demo")->innerHTML(text);
			assert("alt = Flower<br>height = 113<br>id = myImg<br>src = klematis.jpg<br>width = 150<br>" == text);
		}
	}

	// name - https://www.w3schools.com/jsref/prop_attr_name.asp
	{
		//: Get the name of an attribute:
		{
			auto element = document->getElementById("demo");
			auto aName = element->attributes()[0]->name();

			document->getElementById("demo")->innerHTML(aName);
			assert("id" == aName);
		}
	}

	// removeNamedItem() - https://www.w3schools.com/jsref/met_namednodemap_removenameditem.asp
	{
		//: Remove the type attribute from an input button:
		{
			function<void()> myFunction = [document]() {
				auto nodeMap = document->getElementById("myInput")->attributes();
				nodeMap.removeNamedItem("type");
				assert(2 == nodeMap.length());
			};

			myFunction();
		}
	}

	// setNamedItem() - https://www.w3schools.com/jsref/met_namednodemap_setnameditem.asp
	{
		//: Set a H1's class attribute:
		{
			auto nodeMap = document->getElementsByTagName("H1")[0]->attributes();
			auto node = document->createAttribute("class");
			node->value("democlass");
			nodeMap.setNamedItem(node);
			assert(1 == nodeMap.length());
		}
		//: It is easier to use element.setAttribute():
		{
			auto element = document->getElementsByTagName("H1")[0];
			element->setAttribute("class", "democlass");
			assert("democlass" == element->getAttribute("class"));
		}
	}

	// specified - https://www.w3schools.com/jsref/prop_attr_specified.asp
	{
		//: Is the style attribute specified?:
		{
			auto specified = document->getElementById("myDiv")->getAttributeNode("style")->specified();
			document->getElementById("demo")->innerHTML(to_string(specified));
			assert(specified);
		}
	}

	// value - https://www.w3schools.com/jsref/prop_attr_value.asp
	{
		//: Get the value of the first attribute:
		{
			auto element = document->getElementById("demo");
			auto value = element->attributes()[0]->value();

			document->getElementById("demo")->innerHTML(value);
			assert("demo" == value);
		}
		//: Get the value of the "id" attribute:
		{
			auto element = document->getElementById("demo");
			auto value = element->getAttributeNode("id")->value();

			document->getElementById("demo")->innerHTML(value);
			assert("demo" == value);
		}
		//: Use the getNamedItem() method:
		{
			function<void()> myFunction = [document]() {
				auto nodeMap = document->getElementById("light")->attributes();
				nodeMap.getNamedItem("src")->value("pic_bulbon.gif");
				assert("pic_bulbon.gif" == nodeMap.getNamedItem("src")->value());
			};

			myFunction();
		}
		//: Use the getAttributeNode() method:
		{
			function<void()> myFunction = [document]() {
				auto element = document->getElementById("light");
				element->getAttributeNode("src")->value("pic_bulbon.gif");
				assert("pic_bulbon.gif" == element->getAttributeNode("src")->value());
			};

			myFunction();
		}
	}
}
