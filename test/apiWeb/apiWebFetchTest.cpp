#if false
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

TEST(WebFetch, Test) {
	auto g = MakeWindow("", R"xyz(
<html>
<body>
	<h1>HTML DOM Attributes</h1>
	<p id="demo"></p>
</body>
</html>)xyz");
	auto document = g->document();

	// Fetch API - https://www.w3schools.com/jsref/api_fetch.asp
	{
		//:
		{
			//let file = "fetch_info.txt"
			//	fetch(file)
			//	.then(x = > x.text())
			//	.then(y = > document.getElementById("demo").innerHTML = y);
		}
		//: Fetch is based on async and await. The example might be easier to understand like this:
		{
			//getText("fetch_info.txt");

			//async function getText(file) {
			//	let x = await fetch(file);
			//	let y = await x.text();
			//	document.getElementById("demo").innerHTML = y;
			//}
		}
		//: Use understandable names instead of x and y:
		{
			//getText("fetch_info.txt");

			//async function getText(file) {
			//	let myObject = await fetch(file);
			//	let myText = await myObject.text();
			//	document.getElementById("demo").innerHTML = myText;
			//}
		}
	}
}
#endif