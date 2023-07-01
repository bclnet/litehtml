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

TEST(Web, Test) {
	auto g = MakeWindow("", R"xyz(
<html>
<body>
	<h1>JavaScript Crypto API</h1>
	<p id="demo"></p>
</body>
</html>)xyz");
	auto document = g->document();

	// Web API - https://www.w3schools.com/jsref/api_web.asp
	{
		//:
		{
			auto myArray = Uint32Array(10);
			string text = "";
			crypto::getRandomValues(&myArray);

			for (auto num : myArray) {
				text += to_string(num) + "<br>";
			}
			document->getElementById("demo")->innerHTML(text);
		}
	}

	// crypto.getRandomValues() - https://www.w3schools.com/jsref/met_crypto_getrandomvalues.asp
	{
		//:
		{
			auto myArray = Uint32Array(10);
			string text = "";
			crypto::getRandomValues(&myArray);

			for (auto num : myArray) {
				text += to_string(num) + "<br>";
			}
			document->getElementById("demo")->innerHTML(text);
		}
	}
}