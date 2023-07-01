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

TEST(WebMediaQueryList, Test) {
	auto g = MakeWindow("", R"xyz(
<html>
<body>
	<h1>HTML DOM Attributes</h1>
	<p id="demo"></p>
</body>
</html>)xyz");
	auto window = g;
	auto document = g->document();

	// MediaQueryList API - https://www.w3schools.com/jsref/api_mediaquerylist.asp
	{
		//:
		{
			string text;
			if (window->matchMedia("(max-width: 700px)")->matches()) {
				text = "The screen is less or equal to, 700 pixels wide.";
			}
			else {
				text = "The screen is at least 700 pixels wide.";
			}
			document->getElementById("demo")->innerHTML(text);
		}
		//:
		{
			string text;
			if (g->matchMedia("(max-width: 700px)")->matches()) {
				text = "The screen is less or equal to, 700 pixels wide.";
			}
			else {
				text = "The screen is at least 700 pixels wide.";
			}
			document->getElementById("demo")->innerHTML(text);
		}
		//:
		{
			g->matchMedia("(max-height: 480px)")->matches();
		}
		//:
		{
			g->matchMedia("(max-width: 640px)")->matches();
		}
	}
}