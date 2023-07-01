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

TEST(WebStorage, Test) {
	auto g = MakeWindow("", R"xyz(
<html>
<body>
	<h1>HTML DOM Attributes</h1>
	<p id="demo"></p>
</body>
</html>)xyz");
	auto document = g->document();
	auto localStorage = g->localStorage();
	auto sessionStorage = g->sessionStorage();

	// Storage API - https://www.w3schools.com/jsref/api_storage.asp
	{
	}

	// clear() - https://www.w3schools.com/jsref/met_storage_clear.asp
	{
		//: Remove all local storage items:
		{
			tfunc createItems = _f([localStorage]() {
				localStorage->setItem("mytime", Date::now());
				localStorage->setItem("myname", "John");
				localStorage->setItem("myage", 36);
				});

			tfunc deleteItems = _f([localStorage]() {
				localStorage->clear();
				});

			tfunc displayItems = _f([document, localStorage]() {
				document->getElementById("demo")->innerHTML("");
				for (int i = 0; i < localStorage->length(); i++) {
					auto x = localStorage->key(i);
					document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + x + "<br>");
				}
				});
		}
		//: Remove all session items:
		{
			tfunc createItems = _f([sessionStorage]() {
				sessionStorage->setItem("mytime", Date::now());
				sessionStorage->setItem("myname", "John");
				sessionStorage->setItem("myage", 36);
				});

			tfunc deleteItems = _f([sessionStorage]() {
				sessionStorage->clear();
				});

			tfunc displayItems = _f([document, sessionStorage]() {
				document->getElementById("demo")->innerHTML();
				for (int i = 0; i < sessionStorage->length(); i++) {
					auto x = sessionStorage->key(i);
					document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + x + "<br>");
				}
				});
		}
	}

	// getItem() - https://www.w3schools.com/jsref/met_storage_getitem.asp
	{
		//: Get the value of the specified local storage item:
		{
			tfunc createItem = _f([localStorage]() {
				(*localStorage)["mytime"] = Date::now();
				});

			tfunc myFunction = _f([document, localStorage]() {
				auto x = localStorage->getItem("mytime");
				document->getElementById("demo")->innerHTML(x);
				});

		}
		//: Get the value of the specified session storage item:
		{
			tfunc createItem = _f([sessionStorage]() {
				(*sessionStorage)["test1"] = "hello";
				});

			tfunc myFunction = _f([document, sessionStorage]() {
				auto x = sessionStorage->getItem("test1");
				document->getElementById("demo")->innerHTML(x);
				});
		}
		//: You can also get the value by using dot notation (obj.key):
		{
			tfunc createItem = _f([sessionStorage]() {
				(*sessionStorage)["test1"] = "hello";
				});

			tfunc myFunction = _f([document, sessionStorage]() {
				auto x = (*sessionStorage)["test1"];
				document->getElementById("demo")->innerHTML(to_string(x));
				});
		}
		//: You can also get the value like this:
		{
			tfunc createItem = _f([sessionStorage]() {
				(*sessionStorage)["test1"] = "hello";
				});

			tfunc myFunction = _f([document, sessionStorage]() {
				auto x = (*sessionStorage)["test1"];
				document->getElementById("demo")->innerHTML(to_string(x));
				});
		}
	}

	// key() - https://www.w3schools.com/jsref/met_storage_key.asp
	{
		//: Get the name of the first local storage item:
		{
			tfunc myFunction = _f([document, localStorage]() {
				auto x = localStorage->key(0);
				document->getElementById("demo")->innerHTML(x);
				});
		}
		//: Get the name of the first storage item:
		{
			tfunc createItems = _f([sessionStorage]() {
				(*sessionStorage)["test1"] = "hello";
				(*sessionStorage)["test2"] = "Jim";
				(*sessionStorage)["test3"] = 358;
				});

			tfunc myFunction = _f([document, sessionStorage]() {
				auto x = sessionStorage->key(0);
				document->getElementById("demo")->innerHTML(x);
				});
		}
		//: Loop through each local storage item and display the names:
		{
			tfunc createItems = _f([localStorage]() {
				localStorage->setItem("mytime", Date::now());
				localStorage->setItem("myname", "John");
				localStorage->setItem("myage", 36);
				});

			tfunc displayItems = _f([document, localStorage]() {
				document->getElementById("demo")->innerHTML("");
				for (int i = 0; i < localStorage->length(); i++) {
					auto x = localStorage->key(i);
					document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + x + "<br>");
				}
				});
		}
	}

	// length - https://www.w3schools.com/jsref/prop_storage_length.asp
	{
		//: Get the number of local storage item for this domain:
		{
			tfunc myFunction = _f([document, localStorage]() {
				auto x = localStorage->length();
				document->getElementById("demo")->innerHTML(to_string(x));
				});
		}
		//: Get the number of session storage item for this domain:
		{
			tfunc createItems = _f([sessionStorage]() {
				(*sessionStorage)["test1"] = "hello";
				(*sessionStorage)["test2"] = "Jim";
				(*sessionStorage)["test3"] = 358;
				});

			tfunc myFunction = _f([document, sessionStorage]() {
				auto x = sessionStorage->length();
				document->getElementById("demo")->innerHTML(to_string(x));
				});
		}
		//: Loop through each local storage item and display the names:
		{
			tfunc createItems = _f([localStorage]() {
				localStorage->setItem("mytime", Date::now());
				localStorage->setItem("myname", "John");
				localStorage->setItem("myage", 36);
				});

			tfunc displayItems = _f([document, localStorage]() {
				document->getElementById("demo")->innerHTML("");
				for (int i = 0; i < localStorage->length(); i++) {
					auto x = localStorage->key(i);
					document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + x + "<br>");
				}
				});
		}
	}

	// removeItem() - https://www.w3schools.com/jsref/met_storage_removeitem.asp
	{
		//: Remove the the specified local storage item:
		{
			tfunc createItem = _f([localStorage]() {
				(*localStorage)["mytime"] = Date::now();
				});

			tfunc deleteItem = _f([localStorage]() {
				localStorage->removeItem("mytime");
				});

			tfunc displayItem = _f([document, localStorage]() {
				auto x = localStorage->getItem("mytime");
				document->getElementById("demo")->innerHTML(x);
				});
		}
		//: Remove the specified session storage item:
		{
			tfunc createItem = _f([sessionStorage]() {
				sessionStorage->setItem("test1", "hello");
				});

			tfunc deleteItem = _f([sessionStorage]() {
				sessionStorage->removeItem("test1");
				});

			tfunc displayItem = _f([document, sessionStorage]() {
				auto x = sessionStorage->getItem("test1");
				document->getElementById("demo")->innerHTML(x);
				});
		}
	}

	// setItem() - https://www.w3schools.com/jsref/met_storage_setitem.asp
	{
		//: Set the value of the specified local storage item:
		{
			tfunc createItem = _f([localStorage]() {
				localStorage->setItem("mytime", Date::now());
				});

			tfunc readValue = _f([document, localStorage]() {
				auto x = localStorage->getItem("mytime");
				document->getElementById("demo")->innerHTML(x);
				});
		}
		//: Set the value of the specified session storage item:
		{
			tfunc createItem = _f([sessionStorage]() {
				sessionStorage->setItem("test1", "Lorem ipsum");
				});

			tfunc readValue = _f([document, sessionStorage]() {
				auto x = sessionStorage->getItem("test1");
				document->getElementById("demo")->innerHTML(x);
				});
		}
		//: You can also set the value by using dot notation (obj.key):
		{
			tfunc createItem = _f([sessionStorage]() {
				(*sessionStorage)["test1"] = "hello";
				});

			tfunc myFunction = _f([document, sessionStorage]() {
				auto x = (*sessionStorage)["test1"];
				document->getElementById("demo")->innerHTML(to_string(x));
				});
		}
		//: You can also set the value like this:
		{
			tfunc createItem = _f([sessionStorage]() {
				(*sessionStorage)["test1"] = "hello";
				});

			tfunc myFunction = _f([document, sessionStorage]() {
				auto x = (*sessionStorage)["test1"];
				document->getElementById("demo")->innerHTML(to_string(x));
				});
		}
	}
}