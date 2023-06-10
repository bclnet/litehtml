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

TEST(WindowHistory, Test) {
	auto g = MakeWindow("", R"xyz(
<html>
<body>
	<h1>The Window History Object</h1>
	<p id="demo"></p>
</body>
</html>)xyz");
	auto window = g;
	auto document = g->document();
	auto history = g->history();

	// history.back() - https://www.w3schools.com/jsref/met_his_back.asp
	{
		//: Create a back button on a page:
		{
			history->back();
		}
	}

	// history.forward() - https://www.w3schools.com/jsref/met_his_forward.asp
	{
		//: Create a forward button on a page:
		{
			history->forward();
		}
	}

	// history.go() - https://www.w3schools.com/jsref/met_his_go.asp
	{
		//: Create a button to go back two pages:
		{
			history->go(-2);
		}
	}

	// history.length - https://www.w3schools.com/jsref/prop_his_length.asp
	{
		//: Get the number of URLs in the history list:
		{
			auto length = window->history()->length();
			document->getElementById("demo")->innerHTML(to_string(length));
		}
	}
}