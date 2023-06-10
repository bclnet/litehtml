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

TEST(WindowLocation, Test) {
	auto g = MakeWindow("", R"xyz(
<html>
<body>
	<h1>The Window Location Object</h1>
	<p id="demo"></p>
	<p><a id="w3s" href="/js/js_es6.asp#mark_array_from">JavaScript 2015 Array.from()</a><p>
</body>
</html>)xyz");
	auto document = g->document();
	auto location = g->location();

	// location.assign() - https://www.w3schools.com/jsref/met_loc_assign.asp
	{
		//: Load a new document:
		{
			function<void()> myFunction = [location]() {
				location->assign("https://www.w3schools.com");
			};

			myFunction();
		}
	}

	// location.hash - https://www.w3schools.com/jsref/prop_loc_hash.asp
	{
		//: Get the anchor part of the URL:
#if false
		{
			auto url = document->getElementById("w3s");
			document->getElementById("demo")->innerHTML("The anchor portion of the URL is: " + url->hash());
		}
#endif
		//: Set the anchor part:
		{
			location->hash("mark_array_find");
			document->getElementById("demo")->innerHTML("The anchor part is now: " + location->hash());
		}
	}

	// location.host - https://www.w3schools.com/jsref/prop_loc_host.asp
	{
		//: Get the host and port of the current URL:
		{
			auto host = location->host();
			document->getElementById("demo")->innerHTML(host);
		}
	}

	// location.hostname - https://www.w3schools.com/jsref/prop_loc_hostname.asp
	{
		//: Return the hostname of the current URL:
		{
			auto hostname = location->hostname();
			document->getElementById("demo")->innerHTML(hostname);
		}
	}

	// location.href - https://www.w3schools.com/jsref/prop_loc_href.asp
	{
		//: Get the URL of the current page:
		{
			auto url = location->href();
			document->getElementById("demo")->innerHTML(url);
		}
		//: Set the URL of the current page:
		{
			function<void()> myFunction = [location]() {
				location->href("https://www.w3schools.com");
			};

			myFunction();
		}
		//: Set the href value to point to an anchor within a page:
		{
			function<void()> myFunction = [location]() {
				location->href("#top");
			};

			myFunction();
		}
		//: Set the href value to point to an email address (will open and create a new email message):
		{
			function<void()> myFunction = [location]() {
				location->href("mailto:someone@example.com");
			};

			myFunction();
		}
	}

	// location.origin - https://www.w3schools.com/jsref/prop_loc_origin.asp
	{
		//: Get the protocol, hostname and port number of the URL:
		{
			auto origin = location->origin();
			document->getElementById("demo")->innerHTML(origin);
		}
	}

	// location.pathname - https://www.w3schools.com/jsref/prop_loc_pathname.asp
	{
		//: Get the current path:
		{
			auto path = location->pathname();
			document->getElementById("demo")->innerHTML(path);
		}
	}

	// location.port - https://www.w3schools.com/jsref/prop_loc_port.asp
	{
		//: Get the port number of the current URL:
		{
			auto port = location->port();
			document->getElementById("demo")->innerHTML("The port number of the current page is: " + port);
		}
	}

	// location.protocol - https://www.w3schools.com/jsref/prop_loc_protocol.asp
	{
		//: Return the protocol of the current URL:
		{
			auto protocol = location->protocol();
			document->getElementById("demo")->innerHTML(protocol);
		}
	}

	// location.reload() - https://www.w3schools.com/jsref/met_loc_reload.asp
	{
		//: Reload the current document:
		{
			location->reload();
		}
	}

	// location.replace() - https://www.w3schools.com/jsref/met_loc_replace.asp
	{
		//: Replace the current document:
		{
			function<void()> myFunction = [location]() {
				location->replace("https://www.w3schools.com");
			};

			myFunction();
		}
	}

	// location.search - https://www.w3schools.com/jsref/prop_loc_search.asp
	{
		//: Return the querystring part of a URL:
#if false
		{
			auto anchor = document->getElementById("w3s");
			auto query = anchor->search();

			document->getElementById("demo")->innerHTML("The query portion of the URL is: " + query);
		}
#endif
	}
}