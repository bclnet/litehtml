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

TEST(WebValidation, Test) {
	auto g = MakeWindow("", R"xyz(
<html>
<body>
	<h1>HTML DOM Attributes</h1>
	<p id="demo"></p>
</body>
</html>)xyz");
	auto document = g->document();

	// Validation API - https://www.w3schools.com/jsref/api_validation.asp
	{
		//: The checkValidity() Method
		{
			tfunc myFunction = _f([document]() {
				auto inpObj = document->getElementById("id1");
				if (!inpObj->checkValidity()) {
					document->getElementById("demo")->innerHTML(inpObj->validationMessage());
				}
				else {
					document->getElementById("demo")->innerHTML("Input OK");
				}
				});

			myFunction();
		}
		//: The rangeOverflow Property
		{
			tfunc myFunction = _f([document]() {
				string text;
				if (document->getElementById("id1")->validity()->rangeOverflow()) {
					text = "Value too large";
				}
				else {
					text = "Input OK";
				}
				document->getElementById("demo")->innerHTML(text);
				});

			myFunction();
		}
		//: The rangeUnderflow Property
		{
			tfunc myFunction = _f([document]() {
				string text;
				if (document->getElementById("id1")->validity()->rangeUnderflow()) {
					text = "Value too small";
				}
				else {
					text = "Input OK";
				}
				document->getElementById("demo")->innerHTML(text);
				});

			myFunction();
		}
	}
}
#endif