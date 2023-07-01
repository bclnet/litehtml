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

TEST(WebConsole, Test) {
	auto g = MakeWindow("", R"xyz(
<html>
<body>
	<h1>The Console Object</h1>
	<p id="demo"></p>
</body>
</html>)xyz");
	auto window = g;
	auto console = g->console();

	// Console API - https://www.w3schools.com/jsref/api_console.asp
	{
		//:
		{
			window->console()->error("You made a mistake");
		}
		//:
		{
			console->error("You made a mistake");
		}
	}
}
