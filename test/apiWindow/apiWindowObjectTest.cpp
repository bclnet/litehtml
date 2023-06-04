#include <gtest/gtest.h>

#include <assert.h>
#include "litehtml.h"
#include "../containers/test/test_container.h"
using namespace litehtml;
using namespace std;

static test_container container(800, 600, ".");
static Window::ptr MakeWindow(string url, char* source) {
	Document::ptr document = document::createFromString(source, &container);
	return new Window();
}

TEST(WindowObject, Test) {
	auto g = MakeWindow("", R"xyz(
<html>
<body>
	<h1The Window Object</h1>
	<p id="demo"></p>
	<iframe style="width:100%;height:100px"></iframe>
	<iframe style="width:100%;height:100px"></iframe>
	<iframe style="width:100%;height:100px"></iframe>
	<p id="demo1"></p>
	<p id="demo2" style="color:red"></p>
	<div id="txt"></div>
</body>
</html>)xyz");
	auto window = g;
	auto document = g->document();

	// addEventListener() - https://www.w3schools.com/jsref/met_win_addeventlistener.asp
	{
		//: Add a click event handler to the window:
		{
			function<void()> myFunction = [document]()
			{
				document->getElementById("demo")->innerHTML("Hello World");
			};
			window->addEventListener("click", myFunction);
		}
		//: Simpler syntax:
		{
			window->addEventListener("click", [document]() {
				document->getElementById("demo")->innerHTML("Hello World!");
				});
		}
		//: You can add many event listeners to a window:
		{
			function<void()> myFunction1 = [document]() {
				document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + "First function was executed! ");
			};

			function<void()> myFunction2 = [document]() {
				document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + "Second function was executed! ");
			};

			window->addEventListener("click", myFunction1);
			window->addEventListener("click", myFunction2);
		}
		//: You can add different types of events:
		{
			function<void()> myFunction = [document]() {
				document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + "Moused over! ");
			};

			function<void()> mySecondFunction = [document]() {

				document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + "Clicked! ");
			};

			function<void()> myThirdFunction = [document]() {
				document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + "Moused out! ");
			};

			window->addEventListener("mouseover", myFunction);
			window->addEventListener("click", mySecondFunction);
			window->addEventListener("mouseout", myThirdFunction);
		}
		//: When passing parameters, use an "anonymous function" to call a function with the parameters:
		{
			auto p1 = 5;
			auto p2 = 7;

			function<void(tany, tany)> myFunction = [document](a, b) {
				auto result = a * b;
				document->getElementById("demo")->innerHTML(to_string(result));
			};

			window->addEventListener("click", [myFunction]() {
				myFunction(p1, p2);
				});
		}
		//: Change the background color of a document:
		{
			document->addEventListener("click", [document]() {
				document->body()->style()->backgroundColor("red");
				});
		}
		//: Using the removeEventListener() method:
		{
			function<void()> myFunction = [document]() {
				document->getElementById("demo")->innerHTML(Math.random());
			};

			function<void()> removeHandler = [window]() {
				window->removeEventListener("mousemove", myFunction);
			};

			window->addEventListener("mousemove", myFunction);

			removeHandler();
		}
	}

	// alert() - https://www.w3schools.com/jsref/met_win_alert.asp
	{
		//: Display an alert box:
		{
			function<void()> myFunction = [g]() {
				g->alert("Hello! I am an alert box!");
			};

			myFunction();
		}
		//: Alert box with line-breaks:
		{
			function<void()> myFunction = [g]() {
				g->alert("Hello\nHow are you?");
			};

			myFunction();
		}
		//: Alert the hostname of the current URL:
		{
			function<void()> myFunction = [g]() {
				g->alert(g->location().hostname());
			};

			myFunction();
		}
	}

	// atob() - https://www.w3schools.com/jsref/met_win_atob.asp
	{
		//: Decode a base-64 encoded string:
		{
			auto text = "Hello World!";
			auto encoded = window->btoa(text);
			auto decoded = window->atob(encoded);

			document->getElementById("demo")->innerHTML("Encoded: " + encoded + "<br>" + "Decoded: " + decoded);
		}
	}

	// blur() - https://www.w3schools.com/jsref/met_win_blur.asp
	{
		//: Open a new window and blur it:
		{
			function<void()> myFunction = [window]() {
				auto myWindow = window->open("", "", "width=200, height=100");
				myWindow->blur();
			};

			myFunction();
		}
		//: Open a new window and set focus to it:
		{
			function<void()> myFunction = [window]() {
				auto myWindow = window->open("", "", "width=200,height=100");
				myWindow->focus();
			}

			myFunction();
		}
	}

	// bota() - https://www.w3schools.com/jsref/met_win_btoa.asp
	{
		//: Encode a string in base-64:
		{
			auto text = "Hello World!";
			auto encoded = window->btoa(text);

			document->getElementById("demo")->innerHTML("Original: " + text + "<br>Encoded: " + encoded);
		}
	}

	// clearInterval() - https://www.w3schools.com/jsref/met_win_clearinterval.asp
	{
		//: Display the time once every second. Use clearInterval() to stop the time:
		{
			function<void()> myTimer = [document]() {
				auto date = new Date();
				document->getElementById("demo")->innerHTML(date.toLocaleTimeString());
			}

			auto myInterval = setInterval(myTimer, 1000);

			function<void()> myStop = [g, myInterval]() {
				g->clearInterval(myInterval);
			};

			myStop();
		}
		//: Toggle between two background colors once every 500 milliseconds:
		{
			function<void()> setColor = [document]() {
				auto x = document->body();
				x->style->backgroundColor(x->style()->backgroundColor() == "yellow" ? "pink" : "yellow");
			};

			auto myInterval = g->setInterval(setColor, 500);

			function<void()> stopColor = [g, myInterval]() {
				g->clearInterval(myInterval);
			};

			stopColor();
		}
		//: Using setInterval() and clearInterval() to create a dynamic progress bar:
		{
			function<void()> move = [g, document]() {
				auto element = document->getElementById("myBar");
				auto width = 0;
				function<void()> frame = [g, element, width]() {
					if (width == 100) {
						g->clearInterval(id);
					}
					else {
						width++;
						element->style()->width(width + '%');
					}
				};
				auto id = g->setInterval(frame, 10);
			}

			move();
		}
	}

	// clearTimeout() - https://www.w3schools.com/jsref/met_win_cleartimeout.asp
	{
		//: How to prevent myGreeting() to execute:
		{
			function<void()> myGreeting = [document]() {
				document->getElementById("demo")->innerHTML("Happy Birthday!");
			};

			auto myTimeout = g->setTimeout(myGreeting, 3000);

			function<void()> myStopFunction = [g, myTimeout]() {
				g->clearTimeout(myTimeout);
			};

			myStopFunction();
		}
		//: This example has a "Start" button to start a timer, an input field for a counter, and a "Stop" button to stop the timer:
		{
			auto counter = 0;
			auto timeout;
			auto timer_on = 0;

			function<void()> timedCount = [g, document, counter, timeout]() {
				document->getElementById("demo").value(counter);
				counter++;
				timeout = g->setTimeout(timedCount, 1000);
			};

			function<void()> startCount = [timer_on, timedCount]() {
				if (!timer_on) {
					timer_on = 1;
					timedCount();
				}
			};

			function<void()> stopCount = [g, timeout, timer_on]() {
				g->clearTimeout(timeout);
				timer_on = 0;
			};

			startCount();
			stopCount();
		}
	}

	// close() - https://www.w3schools.com/jsref/met_win_close.asp
	{
		//: Use open() to open a window and close() to close the window:
		{
			Window::ptr myWindow;

			function<void()> openWin = [window, myWindow]() {
				myWindow = window->open("", "", "width=200,height=100");
			};

			function<void()> closeWin = [myWindow]() {
				myWindow->close();
			};

			openWin();
			closeWin();
		}
		//: Open "www.w3schools.com" in a new window, and use close() to close it:
		{
			Window::ptr myWindow;

			function<void()> openWin = [window, myWindow]() {
				myWindow = window->open("https://www.w3schools.com", "_blank", "width=500, height=500");
			}

				function<void()> closeWin = [myWindow]() {
				myWindow->close();
			};

			openWin();
			closeWin();
		}
	}

	// closed - https://www.w3schools.com/jsref/prop_win_closed.asp
	{
		//: A function to check if a window is closed:
		{
			Window::ptr myWindow;

			function<void()> openWin = [myWindow]() {
				myWindow = window->open("", "myWindow", "width=400,height=200");
			};

			function<void()> closeWin = []() {
				if (myWindow) {
					myWindow.close();
				}
			};

			function<void()> checkWin() {
				string text = "";
				if (!myWindow) {
					text = "It has never been opened!";
				}
				else {
					if (myWindow->closed()) {
						text = "It is closed.";
					}
					else {
						text = "It is open.";
					}
				}
				document->getElementById("demo")->innerHTML(text);
			};

			openWin();
			checkWin();
			closeWin();
		}
	}

	// confirm() - https://www.w3schools.com/jsref/met_win_confirm.asp
	{
		//: Display a confirmation box:
		{
			function<void()> myFunction = [g]() {
				g->confirm("Press a button!");
			}
			myFunction();
		}
		//: Confirmation box with line-breaks:
		{
			function<void()> myFunction = [g]() {
				string text = "Press a button!\nEither OK or Cancel.";
				if (g->confirm(text) == true) {
					text = "You pressed OK!";
				}
				else {
					text = "You canceled!";
				}
				document->getElementById("demo")->innerHTML(text);
			}
			myFunction();
		}
		//: Display a confirmation box, and output what the user clicked:
		{
			function<void()> myFunction = [g]() {
				string text;
				if (g->confirm("Press a button!") == true) {
					text = "You pressed OK!";
				}
				else {
					text = "You canceled!";
				}
				document->getElementById("demo")->innerHTML(text);
			}
			myFunction();
		}
	}

	// console* - https://www.w3schools.com/jsref/prop_win_console.asp
	{
		//:
		{
			window->console()->error("You made a mistake");
		}
		//:
		{
			g->console->error("You made a mistake");
		}
	}

	// defaultStatus *Deprecated* - https://www.w3schools.com/jsref/prop_win_defaultstatus.asp
	{
		// DEPRECATED
	}

	// document* - https://www.w3schools.com/jsref/prop_win_document.asp
	{
		//:
		{
			auto url = window->document->URL();
			document->getElementById("demo")->innerHTML(url);
		}
		//:
		{
			auto url = document->URL();
			document->getElementById("demo")->innerHTML(url);
		}
	}

	// focus() - https://www.w3schools.com/jsref/met_win_focus.asp
	{
		//: Open a new window and set focus to it:
		{
			function<void()> myFunction = [window]() {
				auto myWindow = window->open("", "", "width=200,height=100");
				myWindow->focus();
			}
			myFunction();
		}
		//: Open a new window and blur it:
		{
			function<void()> myFunction = [window]() {
				auto myWindow = window->open("", "", "width=200, height=100");
				myWindow->blur();
			}
			myFunction();
		}
	}

	// frameElement - https://www.w3schools.com/jsref/prop_win_frameelement.asp
	{
		//: Is the current window in a frame?
		{
			auto answer = "NO";

			if (window->frameElement()) {
				answer = "YES";
			}

			document->getElementById("demo")->innerHTML(answer);
		}
		//: If the window is in a frame, change the URL to "w3schools.com":
		{
			auto frame = window->frameElement();
			if (frame) {
				frame->src("https://www.w3schools.com/");
			}
		}
	}

	// frames - https://www.w3schools.com/jsref/prop_win_frames.asp
	{
		//: Change the location of the first frame:
		{
			function<void()> myFunction = [window]() {
				window->frames[0]->location("https://www.w3schools.com/jsref/");
			}
			myFunction();
		}
		//: Loop through all frames and change the color:
		{
			auto frames = window->frames();
			for (auto i = 0; i < frames().length; i++) {
				frames[i]->document()->body()->style()->background("red");
			}
		}
	}

	// history* - https://www.w3schools.com/jsref/prop_win_history.asp
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

	// getComputedStyle() - https://www.w3schools.com/jsref/jsref_getcomputedstyle.asp
	{
		//: Get the computed background color of an element:
		{
			auto element = document->getElementById("test");
			auto cssObj = window->getComputedStyle(element, null);

			auto bgColor = cssObj->getPropertyValue("background-color");
			document->getElementById("demo")->innerHTML(bgColor);
		}
		//: Get all the computed styles from an element:
		{
			auto element = document->getElementById("test");
			auto cssObj = window->getComputedStyle(element, null);

			auto text = "";
			for (x in cssObj) {
				cssObjProp = cssObj.item(x);
				text += cssObjProp + " = " + cssObj->getPropertyValue(cssObjProp) + "<br>";
			}

			document->getElementById("demo")->innerHTML(text);
		}
		//: Get computed font size of the first letter in an element (using pseudo-element):
		{
			auto element = document->getElementById("test");
			auto cssObj = window->getComputedStyle(element, ":first-letter");

			auto size = cssObj->getPropertyValue("font-size");
			document->getElementById("demo")->innerHTML(size);
		}
	}

	// innerHeight - https://www.w3schools.com/jsref/prop_win_innerheight.asp
	{
		//: Get the window height:
		{
			auto w = window->innerWidth();
			auto h = window->innerHeight();
			document->getElementById("demo")->innerHTML("Width: " + w + "<br>Height: " + h);
		}
		//:
		{
			auto w = g->innerWidth();
			auto h = g->innerHeight();
			document->getElementById("demo")->innerHTML("Width: " + w + "<br>Height: " + h);
		}
		//: All height and width properties:
		{
			auto text =
				"<p>innerWidth: " + window->innerWidth() + "</p>" +
				"<p>innerHeight: " + window->innerHeight() + "</p>" +
				"<p>outerWidth: " + window->outerWidth() + "</p>" +
				"<p>outerHeight: " + window->outerHeight() + "</p>";

			document->getElementById("demo")->innerHTML(text);
		}
		//:
		{
			auto w = g->innerWidth();
			auto h = g->innerHeight();
			document->getElementById("demo")->innerHTML("Width: " + w + "<br>Height: " + h);
		}
		//: All height and width properties:
		{
			auto text =
				"<p>innerWidth: " + window->innerWidth() + "</p>" +
				"<p>innerHeight: " + window->innerHeight() + "</p>" +
				"<p>outerWidth: " + window->outerWidth() + "</p>" +
				"<p>outerHeight: " + window->outerHeight() + "</p>";

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// innerWidth - https://www.w3schools.com/jsref/prop_win_innerwidth.asp
	{
		//: Get window width:
		{
			auto w = window->innerWidth();
			auto h = window->innerHeight();
			document->getElementById("demo")->innerHTML("Width: " + w + "<br>Height: " + h);
		}
		//:
		{
			auto w = g->innerWidth();
			auto h = g->innerHeight();
			document->getElementById("demo")->innerHTML("Width: " + w + "<br>Height: " + h);
		}
		//: All height and width properties:
		{
			auto text =
				"<p>innerWidth: " + window->innerWidth() + "</p>" +
				"<p>innerHeight: " + window->innerHeight() + "</p>" +
				"<p>outerWidth: " + window->outerWidth() + "</p>" +
				"<p>outerHeight: " + window->outerHeight() + "</p>";

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// length - https://www.w3schools.com/jsref/prop_win_length.asp
	{
		//: How many windows are in the window:
		{
			auto length = window->length();
			document->getElementById("demo")->innerHTML(to_string(length));
			assert(length == 3);
		}
		//: Loop through all frames and change the color:
		{
			auto frames = window->frames();
			for (auto i = 0; i < frames->length(); i++) {
				frames[i]->document()->body()->style()->background("red");
			}
		}
	}

	// localStorage* - https://www.w3schools.com/jsref/prop_win_localstorage.asp
	{
		//: Set and retrieve localStorage name/value pair:
		{
			// Set Item
			g->localStorage->setItem("lastname", "Smith");
			// Retrieve
			document->getElementById("demo")->innerHTML(g->localStorage->getItem("lastname"));
		}
		//: Count the number of times a user has clicked a button:
		{
			function<void()> clickCounter = []() = > {
				if (localStorage["clickcount"]) {
					localStorage["clickcount"] = Number(g->localStorage["clickcount"]) + 1;
				}
				else {
					localStorage["clickcount"] = 1;
				}
				document->getElementById("demo")->innerHTML(g->localStorage["clickcount"]);
			};
			clickCounter();
		}
	}

	// location* - https://www.w3schools.com/jsref/prop_win_location.asp
	{
		//:
		{
			auto origin = window->location()->origin();
			document->getElementById("demo")->innerHTML(origin);
		}
		//:
		{
			auto origin = g->location()->origin();
			document->getElementById("demo")->innerHTML(origin);
		}
	}

	// matchMedia() - https://www.w3schools.com/jsref/met_win_matchmedia.asp
	{
		//: Is the screen/viewport greater than 700 pixels wide:
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
			g->matchMedia("(max-height: 480px)")->matches();
		}
		//:
		{
			g->matchMedia("(max-width: 640px)")->matches();
		}
		//: If the viewport is less or equal to 500 pixels wide, set background color to yellow, otherwise to pink:
		{
			// Create a match Function
			function<void(MediaQueryList::ptr)> myFunction = [document](MediaQueryList::ptr x) = > {
				if (x->matches()) {
					document->body()->style->backgroundColor("yellow");
				}
				else {
					document->body()->style()->backgroundColor("pink");
				}
			};

			// Create a MediaQueryList object
			auto mmObj = window->matchMedia("(max-width: 500px)");

			// Call the match function at run time:
			myFunction(mmObj);

			// Add the match function as a listener for state changes:
			mmObj->addListener(myFunction);
		}
	}

	// moveBy() - https://www.w3schools.com/jsref/met_win_moveby.asp
	{
		//: Open a new window and move it 250px relative to its current position:
		{
			Window::ptr myWindow;

			function<void()> openWin = [myWindow]() {
				myWindow = window->open("", "", "width=400, height=400");
			};

			function<void()> moveWin = [myWindow]() {
				myWindow->moveBy(250, 250);
			};

			openWin();
			moveWin();
		}
		//: Using moveBy() together with moveTo():
		{
			Window::ptr myWindow;

			function<void()> openWin = [myWindow]() {
				myWindow = window->open("", "", "width=400, height=400");
			};

			function<void()> moveWinTo = [myWindow]() {
				myWindow->moveTo(150, 150);
			};

			function<void()> moveWinBy = [myWindow]() {
				myWindow->moveBy(75, 75);
			};

			openWin();
			moveWinTo();
			moveWinBy();
		}
	}

	// moveTo() - https://www.w3schools.com/jsref/met_win_moveto.asp
	{
		//: Open a new window, and move it to position 500 x 100:
		{
			Window::ptr myWindow;

			function<void()> openWin = [myWindow]() {
				myWindow = window->open("", "", "width=400, height=200");
			};

			function<void()> moveWin = [myWindow]() {
				myWindow->moveTo(500, 100);
			};

			openWin();
			moveWin();
		}
		//: Using moveTo() together with moveBy():
		{
			Window::ptr myWindow;

			function<void()> openWin = [myWindow]() {
				myWindow = window->open("", "", "width=400, height=400");
			};

			function<void()> moveWinTo = [myWindow]() {
				myWindow->moveTo(150, 150);
			};

			function<void()> moveWinBy = [myWindow]() {
				myWindow->moveBy(75, 75);
			};

			openWin();
			moveWinTo();
			moveWinBy();
		}
	}

	// name - https://www.w3schools.com/jsref/prop_win_name.asp
	{
		//: Get window name:
		{
			auto name = window->name();
			document->getElementById("demo")->innerHTML(name);
		}
		//: Set window name:
		{
			window->name("myWindowName");
			document->getElementById("demo")->innerHTML(window->name());
		}
		//: Open a frame with a special name:
		{
			auto otherWindow = window->open();
			otherWindow->name("Butterfly");
		}
	}

	// navigator* - https://www.w3schools.com/jsref/prop_win_navigator.asp
	{
		//:
		{
			auto language = window->navigator()->language();
			document->getElementById("demo")->innerHTML("Browser language: " + language);
		}
		//:
		{
			auto language = navigator()->language();
			document->getElementById("demo")->innerHTML("Browser language: " + language);
		}
	}

	// open() - https://www.w3schools.com/jsref/met_win_open.asp
	{
		//: Open "www.w3schools.com" in a new browser tab:
		{
			function<void()> myFunction = [window]() {
				window->open("https://www.w3schools.com");
			};

			myFunction();
		}
		//: Open an about:blank page in a new window/tab:
		{
			function<void()> myFunction = [window]() {
				auto myWindow = window->open("", "", "width=200,height=100");
			};

			myFunction();
		}
		//: Open a new window called "MsgWindow", and write some text into it:
		{
			function<void()> myFunction = [window]() {
				auto myWindow = window->open("", "MsgWindow", "width=200,height=100");
				myWindow->document->write("<p>This is 'MsgWindow'. I am 200px wide and 100px tall!</p>");
			};

			myFunction();
		}
		//: Replace the current window with a new window:
		{
			function<void()> myFunction = [window]() {
				auto myWindow = window->open("", "_self");
				myWindow->document->write("<p>I replaced the current window.</p>");
			};

			myFunction();
		}
		//: Open a new window and control its appearance:
		{
			function<void()> myFunction = [window]() {
				window->open("https://www.w3schools.com", "_blank", "toolbar=yes,scrollbars=yes,resizable=yes,top=500,left=500,width=400,height=400");
			};

			myFunction();
		}
		//: Open multiple tabs:
		{
			function<void()> myFunction = [window]() {
				window->open("http://www.google.com/");
				window->open("https://www.w3schools.com/");
			};

			myFunction();
		}
		//: Open a new window. Use close() to close the new window:
		{
			Window::ptr myWindow;

			function<void()> openWin = [window, myWindow]() {
				myWindow = window->open("", "", "width=200,height=100");
			};

			function<void()> closeWin = [window]() {
				myWindow->close();
			};

			openWin();
			closeWin();
		}
		//: Open a new window. Use the name property to return the name of the new window:
		{
			auto name = window->name();
			document->getElementById("demo")->innerHTML(name);
		}
		//: Using the opener property to return a reference to the window that created the new window:
		{
			function<void()> myFunction = [window]() {
				auto myWindow = window->open("", "", "width=300,height=300");
				myWindow->opener()->document()->getElementById("demo")->innerHTML("HELLO!");
			};

			myFunction();
		}
	}

	// opener - https://www.w3schools.com/jsref/prop_win_opener.asp
	{
		//: Open a window and write some text in the opener window:
		{
			function<void()> myFunction = [window]() {
				auto myWindow = window->open("", "", "width=300,height=300");
				myWindow->opener->document->getElementById("demo")->innerHTML("HELLO!");
			};
			myFunction();
		}
	}

	// outerHeight - https://www.w3schools.com/jsref/prop_win_outerheight.asp
	{
		//: Get the browser window's height and width:
		{
			auto w = window->outerWidth();
			auto h = window->outerHeight();
			document->getElementById("demo")->innerHTML("Width: " + w + "<br>Height: " + h);
		}
		//:
		{
			auto w = g->outerWidth();
			auto h = g->outerHeight();
			document->getElementById("demo")->innerHTML("Width: " + w + "<br>Height: " + h);
		}
		//: All height and width properties:
		{
			auto text =
				"<p>innerWidth: " + window->innerWidth() + "</p>" +
				"<p>innerHeight: " + window->innerHeight() + "</p>" +
				"<p>outerWidth: " + window->outerWidth() + "</p>" +
				"<p>outerHeight: " + window->outerHeight() + "</p>";

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// outerWidth - https://www.w3schools.com/jsref/prop_win_outerwidth.asp
	{
		//: Get the browser window's height and width:
		{
			auto w = window->outerWidth();
			auto h = window->outerHeight();
			document->getElementById("demo")->innerHTML("Width: " + w + "<br>Height: " + h);
		}
		//:
		{
			auto w = g->outerWidth();
			auto h = g->outerHeight();
			document->getElementById("demo")->innerHTML("Width: " + w + "<br>Height: " + h);
		}
		//: All height and width properties:
		{
			auto text =
				"<p>innerWidth: " + window->innerWidth() + "</p>" +
				"<p>innerHeight: " + window->innerHeight() + "</p>" +
				"<p>outerWidth: " + window->outerWidth() + "</p>" +
				"<p>outerHeight: " + window->outerHeight() + "</p>";

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// pageXOffset - https://www.w3schools.com/jsref/prop_win_pagexoffset.asp
	{
		//: Scroll the content by 100 pixels, and alert the pageXOffset and pageYOffset:
		{
			function<void()> myFunction = [window]() {
				window->scrollBy(100, 100);
				g->alert("pageXOffset: " + window->pageXOffset() + ", pageYOffset: " + window->pageYOffset());
			};
			myFunction();
		}
		//: Create a sticky navigation bar:
		{
			auto navbar = document->getElementById("navbar");
			auto sticky = navbar->offsetTop();

			function<void()> myFunction = [window, sticky]() {
				if (window->pageYOffset() >= sticky) {
					navbar->classList->add("sticky");
				}
				else {
					navbar->classList->remove("sticky");
				}
			}
			myFunction();
		}
	}

	// pageYOffset - https://www.w3schools.com/jsref/prop_win_pageyoffset.asp
	{
		//: Scroll the content by 100 pixels, and alert the pageXOffset and pageYOffset:
		{
			function<void()> myFunction = [window]() {
				window->scrollBy(100, 100);
				g->alert("pageXOffset: " + window->pageXOffset() + ", pageYOffset: " + window->pageYOffset());
			};
			myFunction();
		}
		//: Create a sticky navigation bar:
		{
			auto navbar = document->getElementById("navbar");
			auto sticky = navbar->offsetTop();

			function<void()> myFunction = [window, sticky]() {
				if (window->pageYOffset() >= sticky) {
					navbar->classList->add("sticky");
				}
				else {
					navbar->classList->remove("sticky");
				}
			}
			myFunction();
		}
	}

	// parent - https://www.w3schools.com/jsref/prop_win_parent.asp
	{
		//: Change the background-color of the parent:
		{
			// TODO
		}
		//: The location of the parent window:
		{
			document->getElementById("demo")->innerHTML(window->parent->location());
		}
	}

	// print() - https://www.w3schools.com/jsref/met_win_print.asp
	{
		//: Print the current page:
		{
			window->print();
		}
	}

	// prompt() - https://www.w3schools.com/jsref/met_win_prompt.asp
	{
		//: Prompt for a user name and output a message:
		{
			function<void()> myFunction = [g, document]() {
				auto person = g->prompt("Please enter your name", "Harry Potter");
				if (person != null) {
					document->getElementById("demo")->innerHTML("Hello " + person + "! How are you today?");
				}
			};
			myFunction();
		}
		//: Prompt for his favourite drink:
		{
			function<void()> myFunction = [g, document]() {
				string text;
				auto favDrink = g->prompt("What's your favorite drink?", "Coca-Cola");
				switch (favDrink) {
				case "Coca-Cola":
					text = "Excellent choice. Coca-Cola is good for your soul.";
					break;
				case "Pepsi":
					text = "Pepsi is my favorite too!";
					break;
				case "Sprite":
					text = "Really? Are you sure the Sprite is your favorite?";
					break;
				default:
					text = "I have never heard of that one..";
				}
				document->getElementById("demo")->innerHTML(text);
			};
			myFunction();
		}
	}

	// removeEventListener() - https://www.w3schools.com/jsref/met_win_removeeventlistener.asp
	{
		//: Remove a "mousemove" event handler:
		{
			window->addEventListener("mousemove", myFunction);

			function<void()> myFunction = [document]() {
				document->getElementById("demo")->innerHTML(Math.random());
			};

			function<void()> removeHandler = []() {
				window->removeEventListener("mousemove", myFunction);
			};

			removeHandler();
		}
	}

	// resizeBy() - https://www.w3schools.com/jsref/met_win_resizeby.asp
	{
		//: Open a new window, and resize (increase) the width and height:
		{
			Window::ptr myWindow;

			function<void()> openWin = [myWindow]() {
				myWindow = window->open("", "", "width=100, height=100");
			};

			function<void()> resizeWin = [myWindow]() {
				myWindow->resizeBy(250, 250);
			};

			openWin();
			resizeWin();
		}
		//: Open a new window, and decrease the width by 50px and increase the height by 50px:
		{
			Window::ptr myWindow;

			function<void()> openWin = [myWindow]() {
				myWindow = window->open("", "", "width=500, height=500");
			};

			function<void()> resizeWin = [myWindow]() {
				myWindow->resizeBy(-50, 50);
			};

			openWin();
			resizeWin();
		}
		//: Using resizeBy() with resizeTo():
		{
			Window::ptr myWindow;

			function<void()> openWin = [myWindow]() {
				myWindow = window->open("", "", "width=250, height=250");
			};

			function<void()> resizeWinTo = [myWindow]() {
				myWindow->resizeBy(800, 600);
			};

			function<void()> resizeWinBy = [myWindow]() {
				myWindow->resizeBy(-100, -50);
			};

			openWin();
			resizeWinTo();
			resizeWinBy();
		}
	}

	// resizeTo() - https://www.w3schools.com/jsref/met_win_resizeto.asp
	{
		//: Open a new window, and resize it to 300 x 300:
		{
			Window::ptr myWindow;

			function<void()> openWin = [myWindow]() {
				myWindow = window->open("", "", "width=200, height=100");
			};

			function<void()> resizeWin = [myWindow]() {
				myWindow->resizeTo(300, 300);
			};

			openWin();
			resizeWin();
		}
		//: Using resizeTo() with resizeBy():
		{
			Window::ptr myWindow;

			function<void()> openWin = [myWindow]() {
				myWindow = window->open("", "", "width=250, height=250");
			};

			function<void()> resizeWinTo = [myWindow]() {
				myWindow->resizeBy(800, 600);
			};

			function<void()> resizeWinBy = [myWindow]() {
				myWindow->resizeBy(-100, -50);
			};

			openWin();
			resizeWinTo();
			resizeWinBy();
		}
	}

	// screen* - https://www.w3schools.com/jsref/prop_win_screen.asp
	{
		// LEFT INTENTIONALLY BLANK
	}

	// screenLeft - https://www.w3schools.com/jsref/prop_win_screenleft.asp
	{
		//: Return the x and y coordinates of the window:
		{
			auto x = window->screenLeft();
			auto y = window->screenTop();
			document->getElementById("demo")->innerHTML("Left: " + x + ", Top: " + y);
		}
	}

	// screenTop - https://www.w3schools.com/jsref/prop_win_screentop.asp
	{
		//: Return the x and y coordinates of the window:
		{
			auto x = window->screenLeft();
			auto y = window->screenTop();
			document->getElementById("demo")->innerHTML("Left: " + x + ", Top: " + y);
		}
	}

	// screenX - https://www.w3schools.com/jsref/prop_win_screenx.asp
	{
		//: Open a new window with a specified left and top position, and return its coordinates:
		{
			function<void()> myFunction = [document]() {
				auto myWin = window->open("", "", "left=700, top=350, width=200, height=100");
				auto x = myWin->screenX();
				auto y = myWin->screenY();
				document->getElementById("demo")->innerHTML("myWin.screenX= " + x + "<br>myWin.screenY= " + y);
			};
			myFunction();
		}
		//: Open a new window and return its coordinates:
		{
			function<void()> myFunction = [document]() {
				auto myWin = window->open("", "", "width=200, height=100");
				auto x = myWin->screenX();
				auto y = myWin->screenY();
				document->getElementById("demo")->innerHTML("myWin.screenX= " + x + "<br>myWin.screenY= " + y);
			};
			myFunction();
		}
	}

	// screenY - https://www.w3schools.com/jsref/prop_win_screeny.asp
	{
		//: Open a new window with a specified left and top position, and return its coordinates:
		{
			function<void()> myFunction = [document]() {
				auto myWin = window->open("", "", "left=700, top=350, width=200, height=100");
				auto x = myWin->screenX();
				auto y = myWin->screenY();
				document.getElementById("demo").innerHTML("myWin.screenX= " + x + "<br>myWin.screenY= " + y);
			};
			myFunction();
		}
		//: Open a new window and return its coordinates:
		{
			function<void()> myFunction = [document]() {
				auto myWin = window->open("", "", "width=200, height=100");
				auto x = myWin->screenX();
				auto y = myWin->screenY();
				document->getElementById("demo")->innerHTML("myWin.screenX= " + x + "<br>myWin.screenY= " + y);
			};
			myFunction();
		}
	}

	// scrollBy() - https://www.w3schools.com/jsref/met_win_scrollby.asp
	{
		//: Scroll the document 100px horizontally:
		{
			function<void()> scrollWin = [window]() {
				window->scrollBy(100, 0);
			};
			scrollWin();
		}
		//: Scroll the document 100px vertically:
		{
			function<void()> scrollWin = [window]() {
				window->scrollBy(0, 100);
			};
			scrollWin();
		}
		//: Scroll the document up and down:
		{
			function<void(int, int)> scrollWin = [window](int x, int y) {
				window->scrollBy(x, y);
			};
			scrollWin(0, 50);
			scrollWin(0, -50);
		}
		//: Scroll the document right and left:
		{
			function<void(int, int)> scrollWin = [window](int x, int y) {
				window->scrollBy(x, y);
			};
			scrollWin(100, 0);
			scrollWin(-100, 0);
		}
	}

	// scrollTo() - https://www.w3schools.com/jsref/met_win_scrollto.asp
	{
		//: Scroll the document to the horizontal position 500:
		{
			function<void()> scrollWin = [window]() {
				window->scrollTo(200, 0);
			};
			scrollWin();
		}
		//: Scroll the document to the vertical position 500:
		{
			function<void()> scrollWin = [window]() {
				window->scrollTo(0, 500);
			};
			scrollWin();
		}
		//: Scroll the document to position 300 horizontally and 500 vertically:
		{
			function<void()> scrollWin = [window]() {
				window->scrollTo(300, 500);
			};
			scrollWin();
		}
	}

	// scrollX - https://www.w3schools.com/jsref/prop_win_scrollx.asp
	{
		//: Scroll the content by 100 pixels, and alert the scrollX and scrollY:
		{
			function<void()> myFunction = [g, window]() {
				window->scrollBy(100, 100);
				g->alert("pageXOffset: " + window->scrollX() + ", scrollY: " + window->scrollY());
			}
			myFunction();
		}
		//: Create a sticky navigation bar:
		{
			auto navbar = document->getElementById("navbar");
			auto sticky = navbar->offsetTop();

			function<void()> myFunction = [window, navbar]() {
				if (window->scrollY() >= sticky) {
					navbar->classList->add("sticky")
				}
				else {
					navbar->classList->remove("sticky");
				}
			}
			myFunction();
		}
	}

	// scrollY - https://www.w3schools.com/jsref/prop_win_scrolly.asp
	{
		//: Scroll the content by 100 pixels, and alert the scrollX and scrollY:
		{
			function<void()> myFunction = [g, window]() {
				window->scrollBy(100, 100);
				g->alert("pageXOffset: " + window->scrollX() + ", scrollY: " + window->scrollY());
			}
			myFunction();
		}
		//: Create a sticky navigation bar:
		{
			auto navbar = document->getElementById("navbar");
			auto sticky = navbar->offsetTop();

			function<void()> myFunction = [window, navbar]() {
				if (window->scrollY() >= sticky) {
					navbar->classList->add("sticky")
				}
				else {
					navbar->classList->remove("sticky");
				}
			}
			myFunction();
		}
	}

	// sessionStorage* - https://www.w3schools.com/jsref/prop_win_sessionstorage.asp
	{
		//: Set and retrieve a sessionStorage name/value pair:
		{
			g->sessionStorage->setItem("lastname", "Smith");
			auto personName = g->sessionStorage->getItem("lastname");
			document->getElementById("demo")->innerHTML(personName);
		}
		//: Count the number of times a user has clicked a button:
		{
			function<void()> clickCounter = [g, document]() {
				if (g->sessionStorage["clickcount"]) {
					g->sessionStorage["clickcount"] = Number(g->sessionStorage["clickcount"]) + 1;
				}
				else {
					g->sessionStorage["clickcount"] = 1;
				}
				document->getElementById("demo")->innerHTML(g->sessionStorage['clickcount']);
			};
			clickCounter();
		}
	}

	// self - https://www.w3schools.com/jsref/prop_win_self.asp
	{
		//: Is this window the topmost window:
		{
			string text;
			if (window->top() != window->self()) {
				text = "This is not the topmost window! Am I in a frame?";
			}
			else {
				text = "This is the topmost window!";
			}
			document->getElementById("demo")->innerHTML(text);
		}
	}

	// setInterval() - https://www.w3schools.com/jsref/met_win_setinterval.asp
	{
		//: Display "Hello" every second (1000 milliseconds):
		{
			auto element = document->getElementById("demo");
			g->setInterval([element]() { element->innerHTML(element->innerHTML() + "Hello"); }, 1000);
		}
		//: Call displayHello every second:
		{
			function<void()> displayHello = [document]() {
				document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML + "Hello");
			};
			g->setInterval(displayHello, 1000);
		}
		//: Display the time like a digital watch:
		{
			function<void()> myTimer = [document]() {
				auto date = new Date();
				document->getElementById("demo")->innerHTML(date->toLocaleTimeString());
			};
			g->setInterval(myTimer, 1000);
		}
		//: Using clearInterval() to stop the digital watch:
		{
			function<void()> myTimer = [document]() {
				auto date = new Date();
				document->getElementById("demo")->innerHTML(date->toLocaleTimeString());
			};
			auto myInterval = g->setInterval(myTimer, 1000);

			function<void()> myStopFunction = [g, myInterval]() {
				g->clearInterval(myInterval);
			};
			myStopFunction();
		}
		//: Using setInterval() and clearInterval() to create a dynamic progress bar:
		{
			function<void()> move = [g, document]() {
				auto element = document->getElementById("myBar");
				auto width = 0;
				function<void()> frame = (g, element, width)[]() {
					if (width == 100) {
						g->clearInterval(id);
					}
					else {
						width++;
						element->style()->width(width + '%');
					}
				};
				auto id = g->setInterval(frame, 10);
			};
			move();
		}
		//: Toggle between two background colors once every 500 milliseconds:
		{
			function<void()> setColor = [document]() {
				auto x = document->body();
				x->style().backgroundColor(x->style()->backgroundColor() == "yellow" ? "pink" : "yellow");
			};
			auto myInterval = g->setInterval(setColor, 500);

			function<void()> stopColor = [g, myInterval]() {
				g->clearInterval(myInterval);
			};
			stopColor();
		}
		//: Pass parameters to the function (does not work in IE9 and earlier):
		{
			function<void(tany, tany)> myFunc = [document](tany p1, tany p2) {
				document->getElementById("demo1")->innerHTML(document->getElementById("demo1")->innerHTML() + "Hello");
				document->getElementById("demo2")->innerHTML("Parameters passed: " + p1 + " " + p2);
			};

			g->setInterval(myFunc, 2000, "param1", "param2");
		}
		//: However, if you use an anonymous function it works in all browsers:
		{
			function<void(tany, tany)> myFunc = [document](tany p1, tany p2) {
				document->getElementById("demo1")->innerHTML(document->getElementById("demo1")->innerHTML() + "Hello");
				document->getElementById("demo2")->innerHTML("Parameters passed: " + p1 + " " + p2);
			};

			g->setInterval(() { myFunc("param1", "param2"); }, 2000);
		}
	}

	// setTimeout() - https://www.w3schools.com/jsref/met_win_settimeout.asp
	{
		//: Wait 5 seconds for the greeting:
		{
			function<void()> myGreeting = [document]() {
				document->getElementById("demo")->innerHTML("Happy Birthday!");
			};

			auto myTimeout = g->setTimeout(myGreeting, 5000);
		}
		//: Use clearTimeout(myTimeout) to prevent myGreeting from running:
		{
			function<void()> myGreeting = [document]() {
				document->getElementById("demo")->innerHTML("Happy Birthday!");
			};

			auto myTimeout = g->setTimeout(myGreeting, 5000);

			function<void()> myStopFunction = [g, myTimeout]() {
				g->clearTimeout(myTimeout);
			};

			myStopFunction();
		}
		//: Display an alert box after 3 seconds (3000 milliseconds):
		{
			int timeout;

			function<void()> alertFunc = (){
				g->alert("Hello!");
			};
			function<void()> myFunction = [g, timeout, alertFunc]() {
				timeout = g->setTimeout(alertFunc, 3000);
			};

			myFunction();
		}
		//: Display a timed text:
		{
			auto x = document->getElementById("txt");
			g->setTimeout([x]() { x->value("2 seconds"); }, 2000);
			g->setTimeout([x]() { x->value("4 seconds"); }, 4000);
			g->setTimeout([x]() { x->value("6 seconds"); }, 6000);
		}
		//: Open a new window and close the window after three seconds (3000 milliseconds):
		{
			function<void()> openWin = [g, window]() {
				auto myWindow = window->open("", "", "width=200, height=100");
				g->setTimeout([myWindow]() { myWindow->close(); }, 3000);
			};

			openWin()
		}
		//: Count forever - but with the ability to stop the count:
		{
			int counter = 0;
			int timeout;
			int timer_on = 0;

			function<void()> timedCount = [g, document, counter]() {
				document->getElementById("demo")->value(to_string(counter));
				counter++;
				timeout = g->setTimeout(timedCount, 1000);
			};

			function<void()> startCount = [timer_on, timer_on, timedCount]() {
				if (!timer_on) {
					timer_on = 1;
					timedCount();
				}
			};

			function<void()> stopCount = [g, timeout, timer_on]() {
				g->clearTimeout(timeout);
				timer_on = 0;
			};

			startCount();
			stopCount();
		}
		//: A clock created with timing events:
		{
			function<void()> startTime = [g, document]() {
				auto date = new Date();
				document->getElementById("demo").innerHTML = date.toLocaleTimeString();
				g->setTimeout(function() { startTime() }, 1000);
			};

			startTime();
		}
		//: Pass parameters to the function (does not work in IE9 and earlier):
		{
			function<void(tany, tany)> myFunc = [document](tany p1, tany p2) {
				document->getElementById("demo")->innerHTML("Parameters: " + p1 + " " + p2);
			}

			g->setTimeout(myFunc, 2000, "param1", "param2");
		}
		//: However, if you use an anonymous function, it will work in all browsers:
		{
			function<void(tany, tany)> myFunc = [document](tany p1, tany p2) {
				document->getElementById("demo")->innerHTML("Parameters: " + p1 + " " + p2);
			};
			g->setTimeout([myFunc]() { myFunc("param1", "param2"); }, 2000);
		}
	}

	// status (deprecated) - https://www.w3schools.com/jsref/prop_win_status.asp
	{
		//: Set the text in the status bar:
		{
			window->status("Some text in the status bar.");
		}
	}

	// stop() - https://www.w3schools.com/jsref/met_win_stop.asp
	{
		//: Stop the loading of a window:
		{
			window->stop();
		}
	}

	// top - https://www.w3schools.com/jsref/prop_win_top.asp
	{
		//: Is this window the topmost window:
		{
			string text;
			if (window->top() != window->self()) {
				text = "This is not the topmost window! Am I in a frame?";
			}
			else {
				text = "This is the topmost window!";
			}
			document->getElementById("demo")->innerHTML(text);
		}
	}
}