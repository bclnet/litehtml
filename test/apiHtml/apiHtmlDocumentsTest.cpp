#include <gtest/gtest.h>

#include <assert.h>
#include "litehtml.h"
#include "../apiTestUtil.h"
#include "../containers/test/test_container.h"
using namespace litehtml;
using namespace std;

static test_container container(800, 600, ".");
static Window::ptr MakeWindow(string url, char* source) {
	Document::ptr document = document::createFromString(source, &container);
	return nullptr; // new Window();
}

TEST(HtmlDocuments, Test) {
	auto g = MakeWindow("", R"xyz(
<html>
<head>
  <title>My title</title>
</head>
<body>
	<h1>The Document Object</h1>
	<p id="demo"></p>
	<iframe id="myFrame" src="/default.asp" style="height:380px;width:520px;"></iframe>
	<a id="myAnchor">Go to W3schools.com</a>
	<ul id="myList"></ul>
	<ul id="myList2"><li>Apple</li><li>Pear</li></ul>
	<embed type="image/jpg" src="pic_trulli.jpg">
	<embed type="image/jpg" src="pic_trulli.jpg">
	<form id="myCarForm"></form>
	<div class="example">Element1</div>
	<div class="example">Element2</div>
	<p>First Name: <input name="fname" type="text" value="Michael"></p>
	<p>First Name: <input name="fname" type="text" value="Doug"></p>
	<input name="animal" type="checkbox" value="Cats">
	<input name="animal" type="checkbox" value="Dogs">
	<img src="klematis.jpg" alt="flower" width="150" height="113">
	<img src="klematis2.jpg" alt="flower" width="152" height="128">
	<img src="smiley.gif" alt="Smiley face" width="42" height="42">
</body>
</html>)xyz");
	auto window = g;
	auto document = g->document();

	// activeElement - https://www.w3schools.com/jsref/prop_document_activeelement.asp
	{
		//: Get the currently focused element:
		{
			tfunc myFunction = _f([document]() {
				auto element = document->activeElement()->tagName();
				document->getElementById("demo")->innerHTML(element);
				});

			myFunction();
		}
	}

	// addEventListener() - https://www.w3schools.com/jsref/met_document_addeventlistener.asp
	{
		//: Add a click event to the document:
		{
			tfunc myFunction = _f([document]() {
				document->getElementById("demo")->innerHTML("Hello World");
				});

			document->addEventListener("click", myFunction);

		}
		//: Simpler syntax:
		{
			document->addEventListener("click", [document]() {
				document->getElementById("demo")->innerHTML("Hello World!");
				});
		}
		//: You can add many event listeners to the document:
		{
			tfunc myFunction1 = _f([document]() {
				document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + "First function was executed! ");
				});

			tfunc myFunction2 = _f([document]() {
				document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + "Second function was executed! ");
				});

			document->addEventListener("click", myFunction1);
			document->addEventListener("click", myFunction2);
		}
		//: You can add different types of events:
		{
			tfunc myFunction = _f([document]() {
				document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + "Moused over!");
				});

			tfunc mySecondFunction = _f([document]() {
				document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + "Clicked!<br>");
				});

			tfunc myThirdFunction = _f([document]() {
				document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + "Moused out!<br>");
				});

			document->addEventListener("mouseover", myFunction);
			document->addEventListener("click", mySecondFunction);
			document->addEventListener("mouseout", myThirdFunction);
		}
		//: When passing parameters, use an "anonymous function" to call a function with the parameters:
		{
			auto p1 = 5;
			auto p2 = 7;

			_f2<int, int> myFunction = _f2<int, int>([document](int a, int b) {
				auto result = a * b;
				document->getElementById("demo")->innerHTML(to_string(result));
				});

			document->addEventListener("click", [myFunction, p1, p2]() {
				myFunction(p1, p2);
				});
		}
		//: Change the background color of the document:
		{
			document->addEventListener("click", [document]() {
				document->body()->style_()->backgroundColor("red");
				});
		}
		//: Using the removeEventListener() method:
		{

			tfunc myFunction = [document]() {
				document->getElementById("demo")->innerHTML(to_string(Math::random()));
			};

			tfunc removeHandler = [document, myFunction]() {
				document->removeEventListener("mousemove", myFunction);
			};

			document->addEventListener("mousemove", myFunction);
		}
	}

	// adoptNode() - https://www.w3schools.com/jsref/met_document_adoptnode.asp
	{
		//: Adopt the first <h1> element that appears in an iframe (another document):
		{
			tfunc myFunction = _f([document]() {
				auto frame = static_pointer_cast<HTMLIFrameElement>(document->getElementById("myFrame"));
				auto h1 = frame->contentWindow()->document()->getElementsByTagName("H1")[0];
				auto node = document->adoptNode(h1);
				document->body()->appendChild(node);
				});

			myFunction();
		}
	}

	// anchors *Deprecated* - https://www.w3schools.com/jsref/coll_doc_anchors.asp
	{
		// DEPRECATED
	}

	// applets *Deprecated* - https://www.w3schools.com/jsref/coll_doc_applets.asp
	{
		// DEPRECATED
	}

	// baseURI - https://www.w3schools.com/jsref/prop_doc_baseuri.asp
	{
		//: Get the baseURI of the document:
		{
			auto base = document->baseURI();
			document->getElementById("demo")->innerHTML(base);
		}
	}

	// body - https://www.w3schools.com/jsref/prop_doc_body.asp
	{
		//: Get the HTML content of a document:
		{
			auto myBody = document->body()->innerHTML();
			document->getElementById("demo")->innerHTML(myBody);
		}
		//: Change the background color of a document:
		{
			document->body()->style_()->backgroundColor("yellow");
			assert("yellow" == document->body()->style_()->backgroundColor());
		}
		//: Change the <body> of a document (overwrite all existing content):
		{
			document->body()->innerHTML("Some new HTML content");
			assert("Some new HTML content" == document->body()->innerHTML());
		}
		//: Create a <p> element and append it to the document's body:
		{
			tfunc myFunction = [document]() {
				auto para = document->createElement("p");
				auto node = document->createTextNode("This is a paragraph.");

				para->appendChild(node);
				document->body()->appendChild(para);
			};

			myFunction();
		}
	}

	// charset - https://www.w3schools.com/jsref/prop_document_charset.asp
	{
		//: Get the character encoding for a document:
		{
			auto encoding = document->charset();
			document->getElementById("demo")->innerHTML(encoding);
			assert("UTF-8" == document->getElementById("demo")->innerHTML());
		}
	}

	// characterSet - https://www.w3schools.com/jsref/prop_document_characterset.asp
	{
		//: Get the character encoding for a document:
		{
			auto encoding = document->characterSet();
			document->getElementById("demo")->innerHTML(encoding);
			assert("UTF-8" == document->getElementById("demo")->innerHTML());
		}
	}

	// close() - https://www.w3schools.com/jsref/met_doc_close.asp
	{
		//: Open a document, write some text to it, and close it:
		{
			tfunc myFunction = _f([document]() {
				document->open();
				document->write("<h1>Hello World</h1>");
				document->write("<p>Open a document owerwrites the original content.</p>");
				document->close();
				});

			myFunction();
		}
		//: Open a new window, then open a document, write some text to it, and close it:
		{
			tfunc myFunction = _f([window]() {
				auto myWindow = window->open();
				myWindow->document()->open();
				myWindow->document()->write("<h1>Hello World!</h1>");
				myWindow->document()->close();
				});

			myFunction();
		}
	}

	// cookie - https://www.w3schools.com/jsref/prop_doc_cookie.asp
	{
		//: Get all cookies associated with this document:
		{
			auto allCookies = document->cookie();
			document->getElementById("demo")->innerHTML(allCookies);
		}
	}

	// createAttribute() - https://www.w3schools.com/jsref/met_document_createattribute.asp
	{
		//:
		{
			tfunc myFunction = _f([document]() {
				// Create a class attribute:
				auto att = document->createAttribute("class");

				// Set a value of the class attribute
				att->value("democlass");

				// Add the class attribute to the first h1;
				document->getElementsByTagName("h1")[0]->setAttributeNode(att);
				});

			myFunction();
		}
		//:
		{
			// Create a class attribute:
			auto att = document->createAttribute("style");

			// Set the value of the class attribute
			att->value("color:red");

			// Add the class attribute to the first h1;
			auto h1 = document->getElementsByTagName("h1")[0];
			h1->setAttributeNode(att);
		}
		//: Add a href="www.w3schools.com" attribute an anchor element:
		{
			tfunc myFunction = _f([document]() {
				// Create a href attribute:
				auto attr = document->createAttribute("href");

				// Set the value of the href attribute:
				attr->value("https://www.w3schools.com");

				// Add the href attribute to an element:
				document->getElementById("myAnchor")->setAttributeNode(attr);
				});

			myFunction();
		}
	}

	// createComment() - https://www.w3schools.com/jsref/met_document_createcomment.asp
	{
		//: Create a comment node, and add it to the document:
		{
			auto comment = document->createComment("My personal comments");
			document->body()->appendChild(comment);
			document->getElementById("demo")->innerHTML(
				"A comment was added to this document, but as you know, comments are invisible.");
			assert("A comment was added to this document, but as you know, comments are invisible." == document->getElementById("demo")->innerHTML());
		}
	}

	// createDocumentFragment() - https://www.w3schools.com/jsref/met_document_createdocumentfragment.asp
	{
		//: Add elements to an empty list:
		{
			vector<string> fruits = { "Banana", "Orange", "Mango" };

			// Create a document fragment:
			auto dFrag = document->createDocumentFragment();
			for (auto x : fruits) {
				auto li = document->createElement("li");
				li->textContent(x);
				dFrag->appendChild(li);
			}

			// Add fragment to a list: 
			document->getElementById("myList")->appendChild(dFrag);
		}
		//: Add elements to an existing list:
		{
			vector<string> fruits = { "Banana", "Orange", "Mango" };

			// Create a document fragment:
			auto dFrag = document->createDocumentFragment();
			for (auto x : fruits) {
				auto li = document->createElement("li");
				li->textContent(x);
				dFrag->appendChild(li);
			}

			// Add fragment to a list: 
			document->getElementById("myList2")->appendChild(dFrag);
		}
	}

	// createElement() - https://www.w3schools.com/jsref/met_document_createelement.asp
	{
		//: Create a <p> element and append it to the document:
		{
			// Create element:
			auto para = document->createElement("p");
			para->innerText("This is a paragraph.");

			// Append to body:
			document->body()->appendChild(para);
		}
		//: Create a <p> element and append it to an element:
		{
			// Create element:
			auto para = document->createElement("p");
			para->innerHTML("This is a paragraph.");

			// Append to another element:
			document->getElementById("myDIV")->appendChild(para);
		}
		//: Create a button:
		{
			auto btn = document->createElement("button");
			btn->innerHTML("Hello Button");
			document->body()->appendChild(btn);
		}
	}

	// createEvent() - https://www.w3schools.com/jsref/event_createevent.asp
	{
		//: Simulate a mouseover event:
		{
			tfunc1<Event::ptr> myFunction = _f1<Event::ptr>([document, window](Event::ptr evnt) {
				auto ev = static_pointer_cast<MouseEvent, Event>(document->createEvent("MouseEvent"));
				ev->initMouseEvent("mouseover", true, true, window, 0, 0, 0, 0, 0, false, false, false, false, 0, nullptr);

				document->getElementById("myDiv")->dispatchEvent(ev);
				});

			myFunction(nullptr);
		}
	}

	// createTextNode() - https://www.w3schools.com/jsref/met_document_createtextnode.asp
	{
		//: Create a text node and append it to the document:
		{
			auto textNode = document->createTextNode("Hello World");
			document->body()->appendChild(textNode);
		}
		//: Create a <h1> element with a text node:
		{
			auto h1 = document->createElement("H1");
			auto textNode = document->createTextNode("Hello World");
			h1->appendChild(textNode);
			document->body()->appendChild(h1);
		}
		//: Create a <p> element with a text node:
		{
			auto h1 = document->createElement("H1");
			auto textNode = document->createTextNode("Hello World");
			h1->appendChild(textNode);
			document->body()->appendChild(h1);
		}
	}

	// defaultView - https://www.w3schools.com/jsref/prop_document_defaultview.asp
	{
		//: Get the document's window object:
		{
			auto view = document->defaultView();
			document->getElementById("demo")->innerHTML(to_string(view));
		}
		//: Get the size of the window:
		{
			auto view = document->defaultView();
			auto width = view->innerWidth();
			auto height = view->innerHeight();
			document->getElementById("demo")->innerHTML(width + "x" + height);
		}
	}

	// designMode - https://www.w3schools.com/jsref/prop_document_designmode.asp
	{
		//: Get the designMode:
		{
			document->getElementById("demo")->innerHTML(document->designMode());
		}
		//: Make the document editable:
		{
			document->designMode("on");
		}
	}

	// doctype - https://www.w3schools.com/jsref/prop_document_doctype.asp
	{
		//: Get the doctype name of an HTML document:
		{
			auto doctypeObj = document->doctype();
			document->getElementById("demo")->innerHTML(doctypeObj->name());
		}
	}

	// documentElement - https://www.w3schools.com/jsref/prop_document_documentelement.asp
	{
		//: Get the name of the document element node:
		{
			document->getElementById("demo")->innerHTML(document->documentElement()->nodeName());
		}
	}

	// documentMode *Deprecated* - https://www.w3schools.com/jsref/prop_doc_documentmode.asp
	{
		// DEPRECATED
	}

	// documentURI - https://www.w3schools.com/jsref/prop_document_documenturi.asp
	{
		//: Get the location URI of the document:
		{
			auto uri = document->documentURI();
			document->getElementById("demo")->innerHTML(uri);
		}
	}

	// domain - https://www.w3schools.com/jsref/prop_doc_domain.asp
	{
		//: The domain name of the server that loaded this document:
		{
			auto myDomain = document->domain();
			document->getElementById("demo")->innerHTML(myDomain);
		}
	}

	// domConfig *Deprecated* - https://www.w3schools.com/jsref/prop_document_domconfig.asp
	{
		// DEPRECATED
	}

	// embeds - https://www.w3schools.com/jsref/coll_doc_embeds.asp
	{
		//: Number of <embed> elements in a document:
		{
			auto num = document->embeds().length();
			document->getElementById("demo")->innerHTML(to_string(num));
		}
	}

	// execCommand() *Deprecated* - https://www.w3schools.com/jsref/met_document_execcommand.asp
	{
		// DEPRECATED
	}

	// forms - https://www.w3schools.com/jsref/coll_doc_forms.asp
	{
		//: Number of <form> elements in the document:
		{
			auto num = document->forms().length();
			document->getElementById("demo")->innerHTML(to_string(num));
		}
		//: Get the id of the first <form> element:
		{
			auto id = document->forms()[0]->id();
			document->getElementById("demo")->innerHTML(id);
		}
		//: Get the id of the first <form> element:
		{
			auto id = document->forms().item(0)->id();
			document->getElementById("demo")->innerHTML(id);
		}
		//: Get the HTML content of the <form> element with id="myCarForm":
		{
			auto html = document->forms().namedItem("myCarForm")->innerHTML();
			document->getElementById("demo")->innerHTML(html);
		}
		//: Loop through all <form> elements and output the id of each form:
		{
			auto forms = document->forms();
			string text = "";
			for (auto i = 0; i < forms.length(); i++) {
				text += forms[i]->id() + "<br>";
			}
			document->getElementById("demo")->innerHTML(text);
		}
		//: Using the form.elements collection to get the value of each element in the form:
		{
			auto form = static_pointer_cast<HTMLFormElement>(document->forms()[0]);
			string text = "";
			for (auto i = 0; i < form->length(); i++) {
				text += static_pointer_cast<HTMLInputElement>(form->elements()[i])->value() + "<br>";
			}
			document->getElementById("demo")->innerHTML(text);
		}
	}

	// getElementById() - https://www.w3schools.com/jsref/met_document_getelementbyid.asp
	{
		//: Get the element with the specified id:
		{
			document->getElementById("demo")->innerHTML("Hello World");
		}
		//: Get the element and change its color:
		{
			auto myElement = document->getElementById("demo");
			myElement->style_()->color("red");
		}
		//: Or just change its color:
		{
			document->getElementById("demo")->style_()->color("red");
		}
	}

	// getElementsByClassName() - https://www.w3schools.com/jsref/met_document_getelementsbyclassname.asp
	{
		//: Get all elements with class="example":
		{
			auto collection = document->getElementsByClassName("example");
			collection[0]->innerHTML("Hello World!");
		}
		//: Get all elements with both the "example" and "color" classes:
		{
			auto collection = document->getElementsByClassName("example color");
			collection[0]->style_()->backgroundColor("red");
		}
		//: Number of elements with class="example":
		{
			auto numb = document->getElementsByClassName("example").length();
			document->getElementById("demo")->innerHTML(to_string(numb));
		}
		//: Change the background color of all elements with class="example":
		{
			auto collection = document->getElementsByClassName("example");
			for (auto i = 0; i < collection.length(); i++) {
				collection[i]->style_()->backgroundColor("red");
			}
		}
	}

	// getElementsByName() - https://www.w3schools.com/jsref/met_doc_getelementsbyname.asp
	{
		//: Get all elements with the name "fname":
		{
			auto elements = document->getElementsByName("fname");
			document->getElementById("demo")->innerHTML(elements[0]->tagName());
		}
		//: Number of elements with name="animal":
		{
			auto num = document->getElementsByName("animal").length();
			document->getElementById("demo")->innerHTML(to_string(num));
		}
		//: Check all <input> elements with type="checkbox" that have the name "animal":
		{
			auto collection = document->getElementsByName("animal");
			for (auto i = 0; i < collection.length(); i++) {
				if (static_pointer_cast<HTMLInputElement>(collection[i])->type() == "checkbox") {
					static_pointer_cast<HTMLInputElement>(collection[i])->checked(true);
				}
			}
		}
	}

	// getElementsByTagName() - https://www.w3schools.com/jsref/met_document_getelementsbytagname.asp
	{
		//: Get all elements with the tag name "li":
		{
			auto collection = document->getElementsByTagName("li");
			document->getElementById("demo")->innerHTML(collection[1]->innerHTML());
		}
		//: Get all elements in the document:
		{
			auto collection = document->getElementsByTagName("*");
			string text = "";
			for (auto i = 0; i < collection.length(); i++) {
				text += collection[i]->tagName() + "<br>";
			}
			document->getElementById("demo")->innerHTML(text);
		}
		//: Change the inner HTML of the first <p> element in the document:
		{
			document->getElementsByTagName("p")[0]->innerHTML("Hello World!");
		}
		//: The number of <li> elements in the document:
		{
			auto collection = document->getElementsByTagName("li");
			document->getElementById("demo")->innerHTML(to_string(collection.length()));
		}
		//: Change the background color of all <p> elements:
		{
			auto collection = document->getElementsByTagName("P");
			for (auto i = 0; i < collection.length(); i++) {
				collection[i]->style_()->backgroundColor("red");
			}
		}
	}

	// hasFocus() - https://www.w3schools.com/jsref/met_document_hasfocus.asp
	{
		//: Display if the document has focus:
		{
			tfunc myFunction = _f([document]() {
				string text;
				if (document->hasFocus()) {
					text = "The document has focus.";
				}
				else {
					text = "The document does NOT have focus.";
				}
				document->getElementById("demo")->innerHTML(text);
				});

			g->setInterval(myFunction, 1);
		}
	}

	// head - https://www.w3schools.com/jsref/prop_doc_head.asp
	{
		//: Get the tag name of the the <head> element:
		{
			auto tag = document->head()->tagName();
			document->getElementById("demo")->innerHTML(tag);
		}
		//: Try with a document without a <head> element:
		{
			auto tag = document->head()->tagName();
			document->getElementById("demo")->innerHTML(tag);
		}
		//: Get the tag name of the the first child element of the <head> element:
		{
			auto tag = document->head()->firstElementChild()->tagName();
			document->getElementById("demo")->innerHTML(tag);
		}
		//: You can also access the <head> element with getElementsByTagName("head"):
		{
			auto tag = document->getElementsByTagName("head")[0]->tagName();
			document->getElementById("demo")->innerHTML(tag);
		}
	}

	// images - https://www.w3schools.com/jsref/coll_doc_images.asp
	{
		//: The number of <img> elements in the document:
		{
			auto numb = document->images().length();
			document->getElementById("demo")->innerHTML(to_string(numb));
		}
		//: Loop over all <img> elements, and output the URL (src) of each:
		{
			auto myImages = document->images();
			string text = "";
			for (auto i = 0; i < myImages.length(); i++) {
				text += static_pointer_cast<HTMLImageElement>(myImages[i])->src() + "<br>";
			}
			document->getElementById("demo")->innerHTML(text);
		}
		//: The URL of the first <img> element is:
		{
			auto src = static_pointer_cast<HTMLImageElement>(document->images()[0])->src();
			document->getElementById("demo")->innerHTML(src);
		}
		//: The URL of the first <img> element is:
		{
			auto src = static_pointer_cast<HTMLImageElement>(document->images().item(0))->src();
			document->getElementById("demo")->innerHTML(src);
		}
		//: The URL of the <img> element with id="myImg" is:
		{
			auto src = static_pointer_cast<HTMLImageElement>(document->images().namedItem("myImg"))->src();
			document->getElementById("demo")->innerHTML(src);
		}
		//: Add a black border to the first <img> element:
		{
			auto src = static_pointer_cast<HTMLImageElement>(document->images().namedItem("myImg"))->src();
			document->getElementById("demo")->innerHTML(src);
		}
	}

	// implementation - https://www.w3schools.com/jsref/prop_document_implementation.asp
	{
		//: Does this document has the feature DOM 1.0?
		{
			auto answer = document->implementation()->hasFeature("DOM", "1.0");
			document->getElementById("demo")->innerHTML(to_string(answer));
		}
		//: Does this document has the feature TESLA X?
		{
			auto answer = document->implementation()->hasFeature("TESLA", "X");
			document->getElementById("demo")->innerHTML(to_string(answer));
		}
	}

	// importNode() - https://www.w3schools.com/jsref/met_document_importnode.asp
	{
		//: Import the first <h1> element from an iframe (another document):
		{
			tfunc myFunction = _f([document]() {
				auto frame = static_pointer_cast<HTMLIFrameElement>(document->getElementById("myFrame"));
				auto h1 = frame->contentWindow()->document()->getElementsByTagName("H1")[0];
				auto node = document->importNode(h1, true);
				document->body()->appendChild(node);
				});

			myFunction();
		}
	}

	// inputEncoding *Deprecated* - https://www.w3schools.com/jsref/prop_document_inputencoding.asp
	{
		// DEPRECATED
	}

	// lastModified - https://www.w3schools.com/jsref/prop_doc_lastmodified.asp
	{
		//: Get the date and time the document was last modified:
		{
			auto text = document->lastModified();
			document->getElementById("demo")->innerHTML(to_string(text));
		}
		//: Convert the lastModified property into a date object:
		{
			Date date(document->lastModified());
			document->getElementById("demo")->innerHTML(to_string(date));
		}
	}

	// links - https://www.w3schools.com/jsref/coll_doc_links.asp
	{
		//: Number of links in the document:
		{
			auto numb = document->links().length();
			document->getElementById("demo")->innerHTML(to_string(numb));
		}
		//: Get the URL of the first link in the document:
		{
			auto url = static_pointer_cast<HTMLAnchorElement>(document->links()[0])->href();
			document->getElementById("demo")->innerHTML(url);
		}
		//: Get the URL of the first link in the document:
		{
			auto url = static_pointer_cast<HTMLAnchorElement>(document->links().item(0))->href();
			document->getElementById("demo")->innerHTML(url);
		}
		//: Get the URL of the element with id="myLink":
		{
			auto url = static_pointer_cast<HTMLAnchorElement>(document->links().namedItem("myLink"))->href();
			document->getElementById("demo")->innerHTML(url);
		}
		//: Add a red border to the first link in the document:
		{
			document->links()[0]->style_()->border("5px solid red");
		}
		//: Loop over all links and output the URL (href) of each:
		{
			auto links = document->links();
			string text = "";
			for (int i = 0; i < links.length(); i++) {
				text += static_pointer_cast<HTMLAnchorElement>(links[i])->href() + "<br>";
			}
			document->getElementById("demo")->innerHTML(text);
		}
	}

	// normalize() *Deprecated* - https://www.w3schools.com/jsref/met_document_normalize.asp
	{
		// DEPRECATED
	}

	// open() - https://www.w3schools.com/jsref/met_doc_open.asp
	{
		//: Open this document, write some text, and close:
		{
			tfunc myFunction = _f([document]() {
				document->open();
				document->write("<h1>Hello World</h1>");
				document->close();
				});

			myFunction();
		}
		//: Using document.open() in a new window:
		{
			tfunc myFunction = _f([window]() {
				auto myWindow = window->open();
				myWindow->document()->open();
				myWindow->document()->write("<h1>Hello World!</h1>");
				myWindow->document()->close();
				});

			myFunction();
		}
		//: If document.write() is used on a closed document, document.open() is automatically called. This will delete existing content.
		{
			tfunc myFunction = _f([document]() {
				document->write("<h1>Hello World</h1>");
				});

			myFunction();
		}
	}

	// querySelector() - https://www.w3schools.com/jsref/met_document_queryselector.asp
	{
		//: Get the first <p> element:
		{
			document->querySelector("p")->style_()->backgroundColor("red");
		}
		//: Get the first element with class="example":
		{
			document->querySelector(".example")->style_()->backgroundColor("red");
		}
		//: Get the first <p> element in with class="example":
		{
			document->querySelector("p.example")->style_()->backgroundColor("red");
		}
		//: Change the text of the element with id="demo":
		{
			document->querySelector("#demo")->innerHTML("Hello World!");
		}
		//: Select the first <p> element with the parent is a <div> element.
		{
			document->querySelector("#demo")->innerHTML("Hello World!");
		}
		//: Select the first <a> element that has a "target" attribute:
		{
			tfunc myFunction = _f([document]() {
				auto x = document->querySelector("div > p");
				x->style_()->backgroundColor("red");
				});

			myFunction();
		}
		//: Select the first <h3> or the first <h4>:
		{
			document->querySelector("h3, h4")->style_()->backgroundColor("red");
		}
		//: Select the first <h3> or the first <h4>:
		{
			document->querySelector("h3, h4")->style_()->backgroundColor("red");
		}
	}

	// querySelectorAll() - https://www.w3schools.com/jsref/met_document_queryselectorall.asp
	{
		//: Select all elements with class="example":
		{
			auto nodeList = document->querySelectorAll(".example");
			for (int i = 0; i < nodeList.length(); i++) {
				nodeList[i]->style_()->backgroundColor("red");
			}
		}
		//: Add a background color to the first <p> element:
		{
			auto nodeList = document->querySelectorAll("p");
			nodeList[0]->style_()->backgroundColor("red");
		}
		//: Add a background color to the first <p> element with class="example":
		{
			auto nodeList = document->querySelectorAll("p.example");
			nodeList[0]->style_()->backgroundColor("red");
		}
		//: Number of elements with class="example":
		{
			auto nodeList = document->querySelectorAll(".example");
			document->getElementById("demo")->innerHTML(to_string(nodeList.length()));
		}
		//: Set the background color of all elements with class="example":
		{
			auto nodeList = document->querySelectorAll(".example");
			for (int i = 0; i < nodeList.length(); i++) {
				nodeList[i]->style_()->backgroundColor("red");
			}
		}
		//: Set the background color of all <p> elements:
		{
			auto nodeList = document->querySelectorAll("p");
			for (int i = 0; i < nodeList.length(); i++) {
				nodeList[i]->style_()->backgroundColor("red");
			}
		}
		//: Set the border of all <a> elements with a "target" attribute:
		{
			auto nodeList = document->querySelectorAll("a[target]");
			for (int i = 0; i < nodeList.length(); i++) {
				nodeList[i]->style_()->border("10px solid red");
			}
		}
		//: Set the background color of every <p> element where the parent is a <div> element:
		{
			auto nodeList = document->querySelectorAll("div > p");
			for (int i = 0; i < nodeList.length(); i++) {
				nodeList[i]->style_()->backgroundColor("red");
			}
		}
		//: Set the background color of all <h3>, <div> and <span> elements:
		{
			auto nodeList = document->querySelectorAll("h3, div, span");
			for (int i = 0; i < nodeList.length(); i++) {
				nodeList[i]->style_()->backgroundColor("red");
			}
		}
	}

	// readyState - https://www.w3schools.com/jsref/prop_doc_readystate.asp
	{
		//: Return the loading status of the document:
		{
			document->getElementById("demo")->innerHTML(document->readyState());
		}
	}

	// referrer - https://www.w3schools.com/jsref/prop_doc_referrer.asp
	{
		//: Return the referrer of the document:
		{
			document->getElementById("demo")->innerHTML(document->referrer());
		}
	}

	// removeEventListener() - https://www.w3schools.com/jsref/met_document_removeeventlistener.asp
	{
		//: Remove a "mousemove" event handler:
		{
			tfunc myFunction = _f([document]() {
				document->getElementById("demo")->innerHTML(to_string(Math::random()));
				});

			document->addEventListener("mousemove", myFunction);

			tfunc removeHandler = _f([document, myFunction]() {
				document->removeEventListener("mousemove", myFunction);
				});

			removeHandler();
		}
	}

	// renameNode() *Deprecated* - https://www.w3schools.com/jsref/met_document_renamenode.asp
	{
		// DEPRECATED
	}

	// scripts - https://www.w3schools.com/jsref/coll_doc_scripts.asp
	{
		//: Number of <script> elements in the document:
		{
			document->getElementById("demo")->innerHTML(to_string(document->scripts().length()));
		}
		//: Return the content of the first <script> element:
		{
			document->getElementById("demo")->innerHTML(static_pointer_cast<HTMLScriptElement>(document->scripts()[0])->text());
		}
		//: Return the content of the first <script> element:
		{
			document->getElementById("demo")->innerHTML(static_pointer_cast<HTMLScriptElement>(document->scripts().item(0))->text());
		}
		//: Return the content of the <script> element with id="myScript":
		{
			auto text = static_pointer_cast<HTMLScriptElement>(document->scripts().namedItem("myScript"))->text();
			document->getElementById("demo")->innerHTML(text);
		}
		//: Loop over all <script> elements and output each id:
		{
			auto collection = document->scripts();
			string text = "";
			for (int i = 0; i < collection.length(); i++) {
				text += collection[i]->id() + "<br>";
			}
			document->getElementById("demo")->innerHTML(text);
		}
	}

	// strictErrorChecking() *Deprecated* - https://www.w3schools.com/jsref/prop_document_stricterrorchecking.asp
	{
		// DEPRECATED
	}

	// title - https://www.w3schools.com/jsref/prop_doc_title.asp
	{
		//: Return the title of the document:
		{
			document->getElementById("demo")->innerHTML(document->title());
		}
		//: Change the title of the document:
		{
			document->title("A new title");
			document->getElementById("demo")->innerHTML(document->title());
		}
	}

	// URL - https://www.w3schools.com/jsref/prop_doc_url.asp
	{
		//: Return the full URL of the document:
		{
			auto url = document->URL();
			document->getElementById("demo")->innerHTML(url);
		}
	}

	// write() - https://www.w3schools.com/jsref/met_doc_write.asp
	{
		//: Write some text directly to the HTML output:
		{
			document->write("Hello World!");
		}
		//: Write some HTML elements directly to the HTML output:
		{
			document->write("<h2>Hello World!</h2><p>Have a nice day!</p>");
		}
		//: Using document.write() after a document is loaded, deletes all existing HTML:
		{
			tfunc myFunction = _f([document]() {
				document->write("Hello World");
				});

			myFunction();
		}
		//: Write a date object directly to the HTML ouput:
		{
			document->write((void*)to_string(Date()).c_str());
		}
		//: Open an output stream, add some HTML, then close the output stream:
		{
			tfunc myFunction = _f([document]() {
				document->open();
				document->write("<h1>Hello World</h1>");
				document->close();
				});

			myFunction();
		}
		//: Open a new window and write some HTML into it:
		{
			tfunc myFunction = _f([window]() {
				auto myWindow = window->open();
				myWindow->document()->write("<h1>New Window</h1>");
				myWindow->document()->write("<p>Hello World!</p>");
				});

			myFunction();
		}
		//: The writeln( ) method is only useful when writing to text documents (type=".txt").
		{
			document->write("Hello World!");
			document->write("Have a nice day!");
			document->write("<br>");
			document->writeln("Hello World!");
			document->writeln("Have a nice day!");
		}
		//:
		{
			document->write("Hello World!");
			document->write("<br>");
			document->write("Have a nice day!");
		}
		//:
		{
			document->write("<p>Hello World!</p>");
			document->write("<p>Have a nice day!</p>");
		}
	}

	// writeln() - https://www.w3schools.com/jsref/met_doc_writeln.asp
	{
		//:
		{
			document->write("Hello World!");
			document->write("Have a nice day!");
			document->write("<br>");
			document->writeln("Hello World!");
			document->writeln("Have a nice day!");
		}
		//: writeln() adds a newline character after each statement. write() does not.
		{
			document->write("Hello World!");
			document->write("Have a nice day!");
			document->write("<br>");
			document->writeln("Hello World!");
			document->writeln("Have a nice day!");
		}
		//:
		{
			document->write("Hello World!");
			document->write("<br>");
			document->write("Have a nice day!");
		}
		//:
		{
			document->write("<p>Hello World!</p>");
			document->write("<p>Have a nice day!</p>");
		}
	}
}
