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

TEST(WebHistory, Test) {
	auto g = MakeWindow("", R"xyz(
<html>
<body>
	<h1>HTML DOM Attributes</h1>
	<p id="demo"></p>
</body>
</html>)xyz");
	auto window = g;
	auto document = g->document();
	auto history = g->history();

	// History API - https://www.w3schools.com/jsref/api_history.asp
	{
		//:
		{
			auto length = history->length();
			document->getElementById("demo")->innerHTML(to_string(length));
		}
		//:
		{
			auto length = window->history()->length();
			document->getElementById("demo")->innerHTML(to_string(length));
		}
	}
}
