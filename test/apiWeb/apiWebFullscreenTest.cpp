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

TEST(WebFulscreen, Test) {
	auto g = MakeWindow("", R"xyz(
<html>
<body>
	<h1>HTML DOM Attributes</h1>
	<p id="demo"></p>
	<video width="100%" controls id="myvideo">
	  <source src="rain.mp4" type="video/mp4">
	  <source src="rain.ogg" type="video/ogg">
	  Your browser does not support the video tag.
	</video>
</body>
</html>)xyz");
	auto document = g->document();

	// Fullscreen API - https://www.w3schools.com/jsref/api_fullscreen.asp
	{
		//: Show a <video> element in fullscreen mode:
		{
			/* Get the element you want displayed in fullscreen */
			auto elem = document->getElementById("myvideo");

			/* Function to open fullscreen mode */
			tfunc openFullscreen = _f([elem]() {
				elem->requestFullscreen();
				});

			openFullscreen();
		}
	}

	// exitFullscreen() - https://www.w3schools.com/jsref/met_element_exitfullscreen.asp
	{
		//: Open the HTML page in fullscreen mode, and close it with a click of a button:
		{
			auto elem = document->documentElement();
			tfunc openFullscreen = _f([elem]() {
				elem->requestFullscreen();
				});

			tfunc closeFullscreen = _f([document]() {
				document->exitFullscreen();
				});

			openFullscreen();
			closeFullscreen();
		}
		//: You can use CSS to style the page when it is in fullscreen mode:
		{
			auto elem = document->documentElement();
			tfunc openFullscreen = _f([elem]() {
				elem->requestFullscreen();
				});

			tfunc closeFullscreen = _f([document]() {
				document->exitFullscreen();
				});

			openFullscreen();
			closeFullscreen();
		}

		// fullscreenElement - https://www.w3schools.com/jsref/prop_document_fullscreenelement.asp
		{
			//: Get the element that is currently in fullscreen mode:
			{
				auto elem = document->fullscreenElement();
			}
			//: Using prefixes for cross-browser code:
			{
				if (
					document->fullscreenElement() /* Standard syntax */
					) {
				}
			}
		}
		// fullscreenEnabled() - https://www.w3schools.com/jsref/met_document_fullscreenenabled.asp
		{
			//: Show a <video> element in fullscreen mode:
			{
				/* Get the element you want displayed in fullscreen */
				auto elem = document->getElementById("myvideo");

				/* Function to open fullscreen mode */
				tfunc openFullscreen = _f([document, elem]() {
					/* If fullscreen mode is available, show the element in fullscreen */
					if (
						document->fullscreenEnabled() /* Standard syntax */
						) {

						/* Show the element in fullscreen */
						elem->requestFullscreen(); /* Standard syntax */
					}
					});

				openFullscreen();
			}
			//: Using prefixes for cross-browser code:
			{
				/* Get the element you want displayed in fullscreen */
				auto elem = document->getElementById("myvideo");

				/* Function to open fullscreen mode */
				tfunc openFullscreen = _f([document, elem]() {
					/* If fullscreen mode is available, show the element in fullscreen */
					if (
						document->fullscreenEnabled() /* Standard syntax */
						) {

						/* Show the element in fullscreen */
						elem->requestFullscreen(); /* Standard syntax */
					}
					});

				openFullscreen();
			}
		}

		// requestFullscreen() - https://www.w3schools.com/jsref/met_element_requestfullscreen.asp
		{
			//: Show a <video> element in fullscreen mode:
			{
				/* Get the element you want displayed in fullscreen */
				auto elem = document->getElementById("myvideo");

				/* Function to open fullscreen mode */
				tfunc openFullscreen = _f([elem]() {
					elem->requestFullscreen();
					});

				openFullscreen();
			}
			//: To open the HTML page in fullscreen, use the document.documentElement instead of document.getElementById("element"). In this example, we also use a close function to close the fullscreen:
			{
				auto elem = document->documentElement();
				tfunc openFullscreen = _f([elem]() {
					elem->requestFullscreen();
					});

				tfunc closeFullscreen = _f([document]() {
					document->exitFullscreen();
					});

				openFullscreen();
				closeFullscreen();
			}
			//: You can also use CSS to style the page when it is in fullscreen mode:
			{
				auto elem = document->documentElement();
				tfunc openFullscreen = ([elem]() {
					elem->requestFullscreen();
					});

				tfunc closeFullscreen = _f([document]() {
					document->exitFullscreen();
					});

				openFullscreen();
				closeFullscreen();
			}
		}
	}
}
