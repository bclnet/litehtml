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

TEST(WindowScreen, Test) {
	auto g = MakeWindow("", R"xyz(
<html>
<body>
	<h1>The Window Screen Object</h1>
	<p id="demo"></p>
</body>
</html>)xyz");
	auto document = g->document();
	auto screen = g->screen();

	// screen.availHeight - https://www.w3schools.com/jsref/prop_screen_availheight.asp
	{
		//: Get the available height of your screen:
		{
			auto height = screen->availHeight();
			document->getElementById("demo")->innerHTML(height + "px");
		}
		//: All screen properties:
		{
			auto text = "Total width/height: " + to_string(screen->width()) + "*" + to_string(screen->height()) + "<br>" +
				"Available width/height: " + to_string(screen->availWidth()) + "*" + to_string(screen->availHeight()) + "<br>" +
				"Color depth: " + to_string(screen->colorDepth()) + "<br>" +
				"Color resolution: " + to_string(screen->pixelDepth());

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// screen.availWidth - https://www.w3schools.com/jsref/prop_screen_availwidth.asp
	{
		//: Get the available width of your screen:
		{
			auto width = screen->availWidth();
			document->getElementById("demo")->innerHTML(width + "px");
		}
		//: All screen properties:
		{
			auto text = "Total width/height: " + to_string(screen->width()) + "*" + to_string(screen->height()) + "<br>" +
				"Available width/height: " + to_string(screen->availWidth()) + "*" + to_string(screen->availHeight()) + "<br>" +
				"Color depth: " + to_string(screen->colorDepth()) + "<br>" +
				"Color resolution: " + to_string(screen->pixelDepth());

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// screen.colorDepth - https://www.w3schools.com/jsref/prop_screen_colordepth.asp
	{
		//: Get the bit depth of the color palette:
		{
			auto depth = screen->colorDepth();
			document->getElementById("demo")->innerHTML(depth + " bits per pixel");
		}
		//: Display an alternate background color for 8 bit screens (to avoid that 8 bit screens, which do not support the modern color, uses an ugly substitute color instead):
		{
			if (screen->colorDepth() <= 8)
				//simple blue background color for 8 bit screens
				document->body()->style_()->background("#0000FF");
			else
				//fancy blue background color for modern screens
				document->body()->style_()->background("#87CEFA");
		} 
		//: All screen properties:
		{
			auto text = "Total width/height: " + to_string(screen->width()) + "*" + to_string(screen->height()) + "<br>" +
				"Available width/height: " + to_string(screen->availWidth()) + "*" + to_string(screen->availHeight()) + "<br>" +
				"Color depth: " + to_string(screen->colorDepth()) + "<br>" +
				"Color resolution: " + to_string(screen->pixelDepth());

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// screen.height - https://www.w3schools.com/jsref/prop_screen_height.asp
	{
		//: Get the total height of your screen:
		{
			auto height = screen->height();
			document->getElementById("demo")->innerHTML(height + "px");
		}
		//: All screen properties:
		{
			auto text = "Total width/height: " + to_string(screen->width()) + "*" + to_string(screen->height()) + "<br>" +
				"Available width/height: " + to_string(screen->availWidth()) + "*" + to_string(screen->availHeight()) + "<br>" +
				"Color depth: " + to_string(screen->colorDepth()) + "<br>" +
				"Color resolution: " + to_string(screen->pixelDepth());

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// screen.pixelDepth - https://www.w3schools.com/jsref/prop_screen_pixeldepth.asp
	{
		//: Get the color resolution of your screen:
		{
			auto depth = screen->pixelDepth();
			document->getElementById("demo")->innerHTML(depth + " bits per pixel");
		}
		//: All screen properties:
		{
			auto text = "Total width/height: " + to_string(screen->width()) + "*" + to_string(screen->height()) + "<br>" +
				"Available width/height: " + to_string(screen->availWidth()) + "*" + to_string(screen->availHeight()) + "<br>" +
				"Color depth: " + to_string(screen->colorDepth()) + "<br>" +
				"Color resolution: " + to_string(screen->pixelDepth());

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// screen.width - https://www.w3schools.com/jsref/prop_screen_width.asp
	{
		//: Get the total width of your screen:
		{
			auto width = screen->width();
			document->getElementById("demo")->innerHTML(width + "px");
		}
		//: All screen properties:
		{
			auto text = "Total width/height: " + to_string(screen->width()) + "*" + to_string(screen->height()) + "<br>" +
				"Available width/height: " + to_string(screen->availWidth()) + "*" + to_string(screen->availHeight()) + "<br>" +
				"Color depth: " + to_string(screen->colorDepth()) + "<br>" +
				"Color resolution: " + to_string(screen->pixelDepth());

			document->getElementById("demo")->innerHTML(text);
		}
	}
}