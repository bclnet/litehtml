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
			tfunc myFunction = _f([document]() {
				document->getElementById("demo")->innerHTML("Hello World");
				});
			window->addEventListener("click", myFunction);
		}
		//: Simpler syntax:
		{
			window->addEventListener("click", _f([document]() {
				document->getElementById("demo")->innerHTML("Hello World!");
				}));
		}
		//: You can add many event listeners to a window:
		{
			tfunc myFunction1 = _f([document]() {
				document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + "First function was executed! ");
				});

			tfunc myFunction2 = _f([document]() {
				document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + "Second function was executed! ");
				});

			window->addEventListener("click", myFunction1);
			window->addEventListener("click", myFunction2);
		}
		//: You can add different types of events:
		{
			tfunc myFunction = _f([document]() {
				document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + "Moused over! ");
				});

			tfunc mySecondFunction = _f([document]() {

				document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + "Clicked! ");
				});

			tfunc myThirdFunction = _f([document]() {
				document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + "Moused out! ");
				});

			window->addEventListener("mouseover", myFunction);
			window->addEventListener("click", mySecondFunction);
			window->addEventListener("mouseout", myThirdFunction);
		}
		//: When passing parameters, use an "anonymous function" to call a function with the parameters:
		{
			auto p1 = 5;
			auto p2 = 7;

			auto myFunction = _f2<int, int>([document](int a, int b) {
				auto result = a * b;
				document->getElementById("demo")->innerHTML(to_string(result));
				});

			window->addEventListener("click", _f([myFunction, p1, p2]() {
				myFunction(p1, p2);
				}));
		}
		//: Change the background color of a document:
		{
			document->addEventListener("click", _f([document]() {
				document->body()->style_()->backgroundColor("red");
				}));
		}
		//: Using the removeEventListener() method:
		{
			tfunc myFunction = _f([document]() {
				document->getElementById("demo")->innerHTML(to_string(Math::random()));
				});

			tfunc removeHandler = _f([window, myFunction]() {
				window->removeEventListener("mousemove", myFunction);
				});

			window->addEventListener("mousemove", myFunction);

			removeHandler();
		}
	}

	// alert() - https://www.w3schools.com/jsref/met_win_alert.asp
	{
		//: Display an alert box:
		{
			tfunc myFunction = _f([g]() {
				g->alert("Hello! I am an alert box!");
				});

			myFunction();
		}
		//: Alert box with line-breaks:
		{
			tfunc myFunction = _f([g]() {
				g->alert("Hello\nHow are you?");
				});

			myFunction();
		}
		//: Alert the hostname of the current URL:
		{
			tfunc myFunction = _f([g]() {
				g->alert(g->location()->hostname());
				});

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
			tfunc myFunction = _f([window]() {
				auto myWindow = window->open("", "", "width=200, height=100");
				myWindow->blur();
				});

			myFunction();
		}
		//: Open a new window and set focus to it:
		{
			tfunc myFunction = _f([window]() {
				auto myWindow = window->open("", "", "width=200,height=100");
				myWindow->focus();
				});

			myFunction();
		}
	}

	// bota() - https://www.w3schools.com/jsref/met_win_btoa.asp
	{
		//: Encode a string in base-64:
		{
			string text = "Hello World!";
			auto encoded = window->btoa(text);

			document->getElementById("demo")->innerHTML("Original: " + text + "<br>Encoded: " + encoded);
		}
	}

	// clearInterval() - https://www.w3schools.com/jsref/met_win_clearinterval.asp
	{
		//: Display the time once every second. Use clearInterval() to stop the time:
		{
			tfunc myTimer = _f([document]() {
				Date date;
				document->getElementById("demo")->innerHTML(date.toLocaleTimeString());
				});

			auto myInterval = g->setInterval(myTimer, 1000);

			tfunc myStop = _f([g, myInterval]() {
				g->clearInterval(myInterval);
				});

			myStop();
		}
		//: Toggle between two background colors once every 500 milliseconds:
		{
			tfunc setColor = _f([document]() {
				auto x = document->body();
				x->style_()->backgroundColor(x->style_()->backgroundColor() == "yellow" ? "pink" : "yellow");
				});

			auto myInterval = g->setInterval(_f(setColor), 500);

			tfunc stopColor = _f([g, myInterval]() {
				g->clearInterval(myInterval);
				});

			stopColor();
		}
		//: Using setInterval() and clearInterval() to create a dynamic progress bar:
		{
			tfunc move = _f([g, document]() {
				auto element = document->getElementById("myBar");
				auto width = 0;
				int id;
				tfunc frame = [g, element, &width, id]() {
					if (width == 100) {
						g->clearInterval(id);
					}
					else {
						width++;
						element->style_()->width(to_string(width) + '%');
					}
				};
				id = g->setInterval(_f(frame), 10);
				});

			move();
		}
	}

	// clearTimeout() - https://www.w3schools.com/jsref/met_win_cleartimeout.asp
	{
		//: How to prevent myGreeting() to execute:
		{
			tfunc myGreeting = _f([document]() {
				document->getElementById("demo")->innerHTML("Happy Birthday!");
				});

			auto myTimeout = g->setTimeout(myGreeting, 3000);

			tfunc myStopFunction = _f([g, myTimeout]() {
				g->clearTimeout(myTimeout);
				});

			myStopFunction();
		}
		//: This example has a "Start" button to start a timer, an input field for a counter, and a "Stop" button to stop the timer:
		{
			auto counter = 0;
			int timeout;
			auto timer_on = 0;

			tfunc timedCount = _f([g, document, &counter, &timeout, timedCount]() {
				static_pointer_cast<HTMLInputElement>(document->getElementById("demo"))->value(to_string(counter));
				counter++;
				timeout = g->setTimeout(timedCount, 1000);
				});

			tfunc startCount = _f([&timer_on, timedCount]() {
				if (!timer_on) {
					timer_on = 1;
					timedCount();
				}
				});

			tfunc stopCount = _f([g, timeout, &timer_on]() {
				g->clearTimeout(timeout);
				timer_on = 0;
				});

			startCount();
			stopCount();
		}
	}

	// close() - https://www.w3schools.com/jsref/met_win_close.asp
	{
		//: Use open() to open a window and close() to close the window:
		{
			Window::ptr myWindow;

			tfunc openWin = _f([window, &myWindow]() {
				myWindow = window->open("", "", "width=200,height=100");
				});

			tfunc closeWin = _f([myWindow]() {
				myWindow->close();
				});

			openWin();
			closeWin();
		}
		//: Open "www.w3schools.com" in a new window, and use close() to close it:
		{
			Window::ptr myWindow;

			tfunc openWin = _f([window, &myWindow]() {
				myWindow = window->open("https://www.w3schools.com", "_blank", "width=500, height=500");
				});

			tfunc closeWin = _f([myWindow]() {
				myWindow->close();
				});

			openWin();
			closeWin();
		}
	}

	// closed - https://www.w3schools.com/jsref/prop_win_closed.asp
	{
		//: A function to check if a window is closed:
		{
			Window::ptr myWindow;

			tfunc openWin = _f([window, &myWindow]() {
				myWindow = window->open("", "myWindow", "width=400,height=200");
				});

			tfunc closeWin = _f([myWindow]() {
				if (myWindow) {
					myWindow->close();
				}
				});

			tfunc checkWin = _f([document, myWindow]() {
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
				});

			openWin();
			checkWin();
			closeWin();
		}
	}

	// confirm() - https://www.w3schools.com/jsref/met_win_confirm.asp
	{
		//: Display a confirmation box:
		{
			tfunc myFunction = _f([g]() {
				g->confirm("Press a button!");
				});
			myFunction();
		}
		//: Confirmation box with line-breaks:
		{
			tfunc myFunction = _f([g, document]() {
				string text = "Press a button!\nEither OK or Cancel.";
				if (g->confirm(text) == true) {
					text = "You pressed OK!";
				}
				else {
					text = "You canceled!";
				}
				document->getElementById("demo")->innerHTML(text);
				});
			myFunction();
		}
		//: Display a confirmation box, and output what the user clicked:
		{
			tfunc myFunction = _f([g, document]() {
				string text;
				if (g->confirm("Press a button!") == true) {
					text = "You pressed OK!";
				}
				else {
					text = "You canceled!";
				}
				document->getElementById("demo")->innerHTML(text);
				});
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
			g->console()->error("You made a mistake");
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
			auto url = window->document()->URL();
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
			tfunc myFunction = _f([window]() {
				auto myWindow = window->open("", "", "width=200,height=100");
				myWindow->focus();
				});
			myFunction();
		}
		//: Open a new window and blur it:
		{
			tfunc myFunction = _f([window]() {
				auto myWindow = window->open("", "", "width=200, height=100");
				myWindow->blur();
				});
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
			auto frame = static_pointer_cast<HTMLIFrameElement>(window->frameElement());
			if (frame) {
				frame->src("https://www.w3schools.com/");
			}
		}
	}

	// frames - https://www.w3schools.com/jsref/prop_win_frames.asp
	{
		//: Change the location of the first frame:
		{
			tfunc myFunction = _f([window]() {
				window->frames()[0]->location("https://www.w3schools.com/jsref/");
				});
			myFunction();
		}
		//: Loop through all frames and change the color:
		{
			auto frames = window->frames();
			for (auto i = 0; i < frames.size(); i++) {
				frames[i]->document()->body()->style_()->background("red");
			}
		}
	}

	// history* - https://www.w3schools.com/jsref/prop_win_history.asp
	{
		//:
		{
			auto length = g->history()->length();
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
			auto cssObj = window->getComputedStyle(element, nullptr);

			auto bgColor = cssObj->getPropertyValue("background-color");
			document->getElementById("demo")->innerHTML(bgColor);
		}
		//: Get all the computed styles from an element:
		{
			auto element = document->getElementById("test");
			auto cssObj = window->getComputedStyle(element, nullptr);

			string text = "";
			for (auto x = 0; x < cssObj->length(); x++) {
				auto cssObjProp = cssObj->item(x);
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
			document->getElementById("demo")->innerHTML("Width: " + to_string(w) + "<br>Height: " + to_string(h));
		}
		//:
		{
			auto w = g->innerWidth();
			auto h = g->innerHeight();
			document->getElementById("demo")->innerHTML("Width: " + to_string(w) + "<br>Height: " + to_string(h));
		}
		//: All height and width properties:
		{
			auto text =
				"<p>innerWidth: " + to_string(window->innerWidth()) + "</p>" +
				"<p>innerHeight: " + to_string(window->innerHeight()) + "</p>" +
				"<p>outerWidth: " + to_string(window->outerWidth()) + "</p>" +
				"<p>outerHeight: " + to_string(window->outerHeight()) + "</p>";

			document->getElementById("demo")->innerHTML(text);
		}
		//:
		{
			auto w = g->innerWidth();
			auto h = g->innerHeight();
			document->getElementById("demo")->innerHTML("Width: " + to_string(w) + "<br>Height: " + to_string(h));
		}
		//: All height and width properties:
		{
			auto text =
				"<p>innerWidth: " + to_string(window->innerWidth()) + "</p>" +
				"<p>innerHeight: " + to_string(window->innerHeight()) + "</p>" +
				"<p>outerWidth: " + to_string(window->outerWidth()) + "</p>" +
				"<p>outerHeight: " + to_string(window->outerHeight()) + "</p>";

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// innerWidth - https://www.w3schools.com/jsref/prop_win_innerwidth.asp
	{
		//: Get window width:
		{
			auto w = window->innerWidth();
			auto h = window->innerHeight();
			document->getElementById("demo")->innerHTML("Width: " + to_string(w) + "<br>Height: " + to_string(h));
		}
		//:
		{
			auto w = g->innerWidth();
			auto h = g->innerHeight();
			document->getElementById("demo")->innerHTML("Width: " + to_string(w) + "<br>Height: " + to_string(h));
		}
		//: All height and width properties:
		{
			auto text =
				"<p>innerWidth: " + to_string(window->innerWidth()) + "</p>" +
				"<p>innerHeight: " + to_string(window->innerHeight()) + "</p>" +
				"<p>outerWidth: " + to_string(window->outerWidth()) + "</p>" +
				"<p>outerHeight: " + to_string(window->outerHeight()) + "</p>";

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
			for (auto i = 0; i < frames.size(); i++) {
				frames[i]->document()->body()->style_()->background("red");
			}
		}
	}

	// localStorage* - https://www.w3schools.com/jsref/prop_win_localstorage.asp
	{
		auto localStorage = g->localStorage();
		//: Set and retrieve localStorage name/value pair:
		{
			// Set Item
			localStorage->setItem("lastname", "Smith");
			// Retrieve
			document->getElementById("demo")->innerHTML(localStorage->getItem("lastname"));
		}
		//: Count the number of times a user has clicked a button:
		{
			tfunc clickCounter = _f([document, localStorage]() {
				if ((*localStorage)["clickcount"].type() != typeid(int)) {
					(*localStorage)["clickcount"] = Number((*localStorage)["clickcount"]) + 1;
				}
				else {
					(*localStorage)["clickcount"] = 1;
				}
				document->getElementById("demo")->innerHTML(to_string((*localStorage)["clickcount"]));
				});
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
			tfunc1<MediaQueryList::ptr> myFunction = _f1<MediaQueryList::ptr>([document](MediaQueryList::ptr x) {
				if (x->matches()) {
					document->body()->style_()->backgroundColor("yellow");
				}
				else {
					document->body()->style_()->backgroundColor("pink");
				}
				});

			// Create a MediaQueryList object
			auto mmObj = window->matchMedia("(max-width: 500px)");

			// Call the match function at run time:
			myFunction(mmObj);

			// Add the match function as a listener for state changes:
			mmObj->addListener(to_func(myFunction));
		}
	}

	// moveBy() - https://www.w3schools.com/jsref/met_win_moveby.asp
	{
		//: Open a new window and move it 250px relative to its current position:
		{
			Window::ptr myWindow;

			tfunc openWin = _f([window, &myWindow]() {
				myWindow = window->open("", "", "width=400, height=400");
				});

			tfunc moveWin = _f([myWindow]() {
				myWindow->moveBy(250, 250);
				});

			openWin();
			moveWin();
		}
		//: Using moveBy() together with moveTo():
		{
			Window::ptr myWindow;

			tfunc openWin = _f([window, &myWindow]() {
				myWindow = window->open("", "", "width=400, height=400");
				});

			tfunc moveWinTo = _f([myWindow]() {
				myWindow->moveTo(150, 150);
				});

			tfunc moveWinBy = _f([myWindow]() {
				myWindow->moveBy(75, 75);
				});

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

			tfunc openWin = _f([window, &myWindow]() {
				myWindow = window->open("", "", "width=400, height=200");
				});

			tfunc moveWin = _f([myWindow]() {
				myWindow->moveTo(500, 100);
				});

			openWin();
			moveWin();
		}
		//: Using moveTo() together with moveBy():
		{
			Window::ptr myWindow;

			tfunc openWin = _f([window, &myWindow]() {
				myWindow = window->open("", "", "width=400, height=400");
				});

			tfunc moveWinTo = _f([myWindow]() {
				myWindow->moveTo(150, 150);
				});

			tfunc moveWinBy = _f([myWindow]() {
				myWindow->moveBy(75, 75);
				});

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
			auto language = g->navigator()->language();
			document->getElementById("demo")->innerHTML("Browser language: " + language);
		}
	}

	// open() - https://www.w3schools.com/jsref/met_win_open.asp
	{
		//: Open "www.w3schools.com" in a new browser tab:
		{
			tfunc myFunction = _f([window]() {
				window->open("https://www.w3schools.com");
				});

			myFunction();
		}
		//: Open an about:blank page in a new window/tab:
		{
			tfunc myFunction = _f([window]() {
				auto myWindow = window->open("", "", "width=200,height=100");
				});

			myFunction();
		}
		//: Open a new window called "MsgWindow", and write some text into it:
		{
			tfunc myFunction = _f([window]() {
				auto myWindow = window->open("", "MsgWindow", "width=200,height=100");
				myWindow->document()->write("<p>This is 'MsgWindow'. I am 200px wide and 100px tall!</p>");
				});

			myFunction();
		}
		//: Replace the current window with a new window:
		{
			tfunc myFunction = _f([window]() {
				auto myWindow = window->open("", "_self");
				myWindow->document()->write("<p>I replaced the current window.</p>");
				});

			myFunction();
		}
		//: Open a new window and control its appearance:
		{
			tfunc myFunction = _f([window]() {
				window->open("https://www.w3schools.com", "_blank", "toolbar=yes,scrollbars=yes,resizable=yes,top=500,left=500,width=400,height=400");
				});

			myFunction();
		}
		//: Open multiple tabs:
		{
			tfunc myFunction = _f([window]() {
				window->open("http://www.google.com/");
				window->open("https://www.w3schools.com/");
				});

			myFunction();
		}
		//: Open a new window. Use close() to close the new window:
		{
			Window::ptr myWindow;

			tfunc openWin = _f([window, &myWindow]() {
				myWindow = window->open("", "", "width=200,height=100");
				});

			tfunc closeWin = _f([myWindow]() {
				myWindow->close();
				});

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
			tfunc myFunction = _f([window]() {
				auto myWindow = window->open("", "", "width=300,height=300");
				myWindow->opener()->document()->getElementById("demo")->innerHTML("HELLO!");
				});

			myFunction();
		}
	}

	// opener - https://www.w3schools.com/jsref/prop_win_opener.asp
	{
		//: Open a window and write some text in the opener window:
		{
			tfunc myFunction = _f([window]() {
				auto myWindow = window->open("", "", "width=300,height=300");
				myWindow->opener()->document()->getElementById("demo")->innerHTML("HELLO!");
				});
			myFunction();
		}
	}

	// outerHeight - https://www.w3schools.com/jsref/prop_win_outerheight.asp
	{
		//: Get the browser window's height and width:
		{
			auto w = window->outerWidth();
			auto h = window->outerHeight();
			document->getElementById("demo")->innerHTML("Width: " + to_string(w) + "<br>Height: " + to_string(h));
		}
		//:
		{
			auto w = g->outerWidth();
			auto h = g->outerHeight();
			document->getElementById("demo")->innerHTML("Width: " + to_string(w) + "<br>Height: " + to_string(h));
		}
		//: All height and width properties:
		{
			auto text =
				"<p>innerWidth: " + to_string(window->innerWidth()) + "</p>" +
				"<p>innerHeight: " + to_string(window->innerHeight()) + "</p>" +
				"<p>outerWidth: " + to_string(window->outerWidth()) + "</p>" +
				"<p>outerHeight: " + to_string(window->outerHeight()) + "</p>";

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// outerWidth - https://www.w3schools.com/jsref/prop_win_outerwidth.asp
	{
		//: Get the browser window's height and width:
		{
			auto w = window->outerWidth();
			auto h = window->outerHeight();
			document->getElementById("demo")->innerHTML("Width: " + to_string(w) + "<br>Height: " + to_string(h));
		}
		//:
		{
			auto w = g->outerWidth();
			auto h = g->outerHeight();
			document->getElementById("demo")->innerHTML("Width: " + to_string(w) + "<br>Height: " + to_string(h));
		}
		//: All height and width properties:
		{
			auto text =
				"<p>innerWidth: " + to_string(window->innerWidth()) + "</p>" +
				"<p>innerHeight: " + to_string(window->innerHeight()) + "</p>" +
				"<p>outerWidth: " + to_string(window->outerWidth()) + "</p>" +
				"<p>outerHeight: " + to_string(window->outerHeight()) + "</p>";

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// pageXOffset - https://www.w3schools.com/jsref/prop_win_pagexoffset.asp
	{
		//: Scroll the content by 100 pixels, and alert the pageXOffset and pageYOffset:
		{
			tfunc myFunction = _f([g, window]() {
				window->scrollBy(100, 100);
				g->alert("pageXOffset: " + to_string(window->pageXOffset()) + ", pageYOffset: " + to_string(window->pageYOffset()));
				});
			myFunction();
		}
		//: Create a sticky navigation bar:
		{
			auto navbar = document->getElementById("navbar");
			auto sticky = navbar->offsetTop();

			tfunc myFunction = _f([window, navbar, sticky]() {
				if (window->pageYOffset() >= sticky) {
					navbar->classList()->add("sticky");
				}
				else {
					navbar->classList()->remove("sticky");
				}
				});
			myFunction();
		}
	}

	// pageYOffset - https://www.w3schools.com/jsref/prop_win_pageyoffset.asp
	{
		//: Scroll the content by 100 pixels, and alert the pageXOffset and pageYOffset:
		{
			tfunc myFunction = _f([g, window]() {
				window->scrollBy(100, 100);
				g->alert("pageXOffset: " + to_string(window->pageXOffset()) + ", pageYOffset: " + to_string(window->pageYOffset()));
				});
			myFunction();
		}
		//: Create a sticky navigation bar:
		{
			auto navbar = document->getElementById("navbar");
			auto sticky = navbar->offsetTop();

			tfunc myFunction = _f([window, navbar, sticky]() {
				if (window->pageYOffset() >= sticky) {
					navbar->classList()->add("sticky");
				}
				else {
					navbar->classList()->remove("sticky");
				}
				});
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
			document->getElementById("demo")->innerHTML(to_string(window->parent()->location()));
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
			tfunc myFunction = _f([g, document]() {
				auto person = g->prompt("Please enter your name", "Harry Potter");
				if (!person.empty()) {
					document->getElementById("demo")->innerHTML("Hello " + person + "! How are you today?");
				}
				});
			myFunction();
		}
		//: Prompt for his favourite drink:
		{
			tfunc myFunction = _f([g, document]() {
				string text;
				auto favDrink = g->prompt("What's your favorite drink?", "Coca-Cola");
				switch (string_hash(favDrink)) {
				case "Coca-Cola"_sh:
					text = "Excellent choice. Coca-Cola is good for your soul.";
					break;
				case "Pepsi"_sh:
					text = "Pepsi is my favorite too!";
					break;
				case "Sprite"_sh:
					text = "Really? Are you sure the Sprite is your favorite?";
					break;
				default:
					text = "I have never heard of that one..";
				}
				document->getElementById("demo")->innerHTML(text);
				});
			myFunction();
		}
	}

	// removeEventListener() - https://www.w3schools.com/jsref/met_win_removeeventlistener.asp
	{
		//: Remove a "mousemove" event handler:
		{
			tfunc myFunction = _f([document]() {
				document->getElementById("demo")->innerHTML(to_string(Math::random()));
				});

			window->addEventListener("mousemove", myFunction);

			tfunc removeHandler = _f([window, myFunction]() {
				window->removeEventListener("mousemove", myFunction);
				});

			removeHandler();
		}
	}

	// resizeBy() - https://www.w3schools.com/jsref/met_win_resizeby.asp
	{
		//: Open a new window, and resize (increase) the width and height:
		{
			Window::ptr myWindow;

			tfunc openWin = _f([window, &myWindow]() {
				myWindow = window->open("", "", "width=100, height=100");
				});

			tfunc resizeWin = _f([myWindow]() {
				myWindow->resizeBy(250, 250);
				});

			openWin();
			resizeWin();
		}
		//: Open a new window, and decrease the width by 50px and increase the height by 50px:
		{
			Window::ptr myWindow;

			tfunc openWin = _f([window, &myWindow]() {
				myWindow = window->open("", "", "width=500, height=500");
				});

			tfunc resizeWin = _f([myWindow]() {
				myWindow->resizeBy(-50, 50);
				});

			openWin();
			resizeWin();
		}
		//: Using resizeBy() with resizeTo():
		{
			Window::ptr myWindow;

			tfunc openWin = _f([window, &myWindow]() {
				myWindow = window->open("", "", "width=250, height=250");
				});

			tfunc resizeWinTo = _f([myWindow]() {
				myWindow->resizeBy(800, 600);
				});

			tfunc resizeWinBy = _f([myWindow]() {
				myWindow->resizeBy(-100, -50);
				});

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

			tfunc openWin = _f([window, &myWindow]() {
				myWindow = window->open("", "", "width=200, height=100");
				});

			tfunc resizeWin = _f([myWindow]() {
				myWindow->resizeTo(300, 300);
				});

			openWin();
			resizeWin();
		}
		//: Using resizeTo() with resizeBy():
		{
			Window::ptr myWindow;

			tfunc openWin = _f([window, &myWindow]() {
				myWindow = window->open("", "", "width=250, height=250");
				});

			tfunc resizeWinTo = _f([myWindow]() {
				myWindow->resizeBy(800, 600);
				});

			tfunc resizeWinBy = _f([myWindow]() {
				myWindow->resizeBy(-100, -50);
				});

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
			document->getElementById("demo")->innerHTML("Left: " + to_string(x) + ", Top: " + to_string(y));
		}
	}

	// screenTop - https://www.w3schools.com/jsref/prop_win_screentop.asp
	{
		//: Return the x and y coordinates of the window:
		{
			auto x = window->screenLeft();
			auto y = window->screenTop();
			document->getElementById("demo")->innerHTML("Left: " + to_string(x) + ", Top: " + to_string(y));
		}
	}

	// screenX - https://www.w3schools.com/jsref/prop_win_screenx.asp
	{
		//: Open a new window with a specified left and top position, and return its coordinates:
		{
			tfunc myFunction = _f([window, document]() {
				auto myWin = window->open("", "", "left=700, top=350, width=200, height=100");
				auto x = myWin->screenX();
				auto y = myWin->screenY();
				document->getElementById("demo")->innerHTML("myWin.screenX= " + to_string(x) + "<br>myWin.screenY= " + to_string(y));
				});
			myFunction();
		}
		//: Open a new window and return its coordinates:
		{
			tfunc myFunction = _f([window, document]() {
				auto myWin = window->open("", "", "width=200, height=100");
				auto x = myWin->screenX();
				auto y = myWin->screenY();
				document->getElementById("demo")->innerHTML("myWin.screenX= " + to_string(x) + "<br>myWin.screenY= " + to_string(y));
				});
			myFunction();
		}
	}

	// screenY - https://www.w3schools.com/jsref/prop_win_screeny.asp
	{
		//: Open a new window with a specified left and top position, and return its coordinates:
		{
			tfunc myFunction = _f([window, document]() {
				auto myWin = window->open("", "", "left=700, top=350, width=200, height=100");
				auto x = myWin->screenX();
				auto y = myWin->screenY();
				document->getElementById("demo")->innerHTML("myWin.screenX= " + to_string(x) + "<br>myWin.screenY= " + to_string(y));
				});
			myFunction();
		}
		//: Open a new window and return its coordinates:
		{
			tfunc myFunction = _f([window, document]() {
				auto myWin = window->open("", "", "width=200, height=100");
				auto x = myWin->screenX();
				auto y = myWin->screenY();
				document->getElementById("demo")->innerHTML("myWin.screenX= " + to_string(x) + "<br>myWin.screenY= " + to_string(y));
				});
			myFunction();
		}
	}

	// scrollBy() - https://www.w3schools.com/jsref/met_win_scrollby.asp
	{
		//: Scroll the document 100px horizontally:
		{
			tfunc scrollWin = _f([window]() {
				window->scrollBy(100, 0);
				});
			scrollWin();
		}
		//: Scroll the document 100px vertically:
		{
			tfunc scrollWin = _f([window]() {
				window->scrollBy(0, 100);
				});
			scrollWin();
		}
		//: Scroll the document up and down:
		{
			tfunc2<int, int> scrollWin = _f2<int, int>([window](int x, int y) {
				window->scrollBy(x, y);
				});
			scrollWin(0, 50);
			scrollWin(0, -50);
		}
		//: Scroll the document right and left:
		{
			tfunc2<int, int> scrollWin = _f2<int, int>([window](int x, int y) {
				window->scrollBy(x, y);
				});
			scrollWin(100, 0);
			scrollWin(-100, 0);
		}
	}

	// scrollTo() - https://www.w3schools.com/jsref/met_win_scrollto.asp
	{
		//: Scroll the document to the horizontal position 500:
		{
			tfunc scrollWin = _f([window]() {
				window->scrollTo(200, 0);
				});
			scrollWin();
		}
		//: Scroll the document to the vertical position 500:
		{
			tfunc scrollWin = _f([window]() {
				window->scrollTo(0, 500);
				});
			scrollWin();
		}
		//: Scroll the document to position 300 horizontally and 500 vertically:
		{
			tfunc scrollWin = _f([window]() {
				window->scrollTo(300, 500);
				});
			scrollWin();
		}
	}

	// scrollX - https://www.w3schools.com/jsref/prop_win_scrollx.asp
	{
		//: Scroll the content by 100 pixels, and alert the scrollX and scrollY:
		{
			tfunc myFunction = _f([g, window]() {
				window->scrollBy(100, 100);
				g->alert("pageXOffset: " + to_string(window->scrollX()) + ", scrollY: " + to_string(window->scrollY()));
				});
			myFunction();
		}
		//: Create a sticky navigation bar:
		{
			auto navbar = document->getElementById("navbar");
			auto sticky = navbar->offsetTop();

			tfunc myFunction = _f([window, navbar, sticky]() {
				if (window->scrollY() >= sticky) {
					navbar->classList()->add("sticky");
				}
				else {
					navbar->classList()->remove("sticky");
				}
				});
			myFunction();
		}
	}

	// scrollY - https://www.w3schools.com/jsref/prop_win_scrolly.asp
	{
		//: Scroll the content by 100 pixels, and alert the scrollX and scrollY:
		{
			tfunc myFunction = _f([g, window]() {
				window->scrollBy(100, 100);
				g->alert("pageXOffset: " + to_string(window->scrollX()) + ", scrollY: " + to_string(window->scrollY()));
				});
			myFunction();
		}
		//: Create a sticky navigation bar:
		{
			auto navbar = document->getElementById("navbar");
			auto sticky = navbar->offsetTop();

			tfunc myFunction = _f([window, navbar, sticky]() {
				if (window->scrollY() >= sticky) {
					navbar->classList()->add("sticky");
				}
				else {
					navbar->classList()->remove("sticky");
				}
				});
			myFunction();
		}
	}

	// sessionStorage* - https://www.w3schools.com/jsref/prop_win_sessionstorage.asp
	{
		auto sessionStorage = g->sessionStorage();
		//: Set and retrieve a sessionStorage name/value pair:
		{
			sessionStorage->setItem("lastname", "Smith");
			auto personName = sessionStorage->getItem("lastname");
			document->getElementById("demo")->innerHTML(personName);
		}
		//: Count the number of times a user has clicked a button:
		{
			tfunc clickCounter = _f([g, document, sessionStorage]() {
				if ((*sessionStorage)["clickcount"].type() != typeid(int)) {
					(*sessionStorage)["clickcount"] = Number((*sessionStorage)["clickcount"]) + 1;
				}
				else {
					(*sessionStorage)["clickcount"] = 1;
				}
				document->getElementById("demo")->innerHTML(to_string((*sessionStorage)["clickcount"]));
				});
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
			g->setInterval(_f([element]() { element->innerHTML(element->innerHTML() + "Hello"); }), 1000);
		}
		//: Call displayHello every second:
		{
			tfunc displayHello = _f([document]() {
				document->getElementById("demo")->innerHTML(document->getElementById("demo")->innerHTML() + "Hello");
				});
			g->setInterval(displayHello, 1000);
		}
		//: Display the time like a digital watch:
		{
			tfunc myTimer = _f([document]() {
				auto date = new Date();
				document->getElementById("demo")->innerHTML(date->toLocaleTimeString());
				});
			g->setInterval(myTimer, 1000);
		}
		//: Using clearInterval() to stop the digital watch:
		{
			tfunc myTimer = _f([document]() {
				auto date = new Date();
				document->getElementById("demo")->innerHTML(date->toLocaleTimeString());
				});
			auto myInterval = g->setInterval(myTimer, 1000);

			tfunc myStopFunction = _f([g, myInterval]() {
				g->clearInterval(myInterval);
				});
			myStopFunction();
		}
		//: Using setInterval() and clearInterval() to create a dynamic progress bar:
		{
			tfunc move = _f([g, document]() {
				auto element = document->getElementById("myBar");
				auto width = 0;
				int id;
				tfunc frame = [g, element, &width, id]() {
					if (width == 100) {
						g->clearInterval(id);
					}
					else {
						width++;
						element->style_()->width(to_string(width) + '%');
					}
				};
				id = g->setInterval(frame, 10);
				});
			move();
		}
		//: Toggle between two background colors once every 500 milliseconds:
		{
			tfunc setColor = _f([document]() {
				auto x = document->body();
				x->style_()->backgroundColor(x->style_()->backgroundColor() == "yellow" ? "pink" : "yellow");
				});
			auto myInterval = g->setInterval(_f(setColor), 500);

			tfunc stopColor = _f([g, myInterval]() {
				g->clearInterval(myInterval);
				});
			stopColor();
		}
		//: Pass parameters to the function (does not work in IE9 and earlier):
		{
			tfunc2<tany, tany> myFunc = _f2<tany, tany>([document](tany p1, tany p2) {
				document->getElementById("demo1")->innerHTML(document->getElementById("demo1")->innerHTML() + "Hello");
				document->getElementById("demo2")->innerHTML("Parameters passed: " + to_string(p1) + " " + to_string(p2));
				});

			g->setInterval(to_func(myFunc), 2000, "param1", "param2");
		}
		//: However, if you use an anonymous function it works in all browsers:
		{
			tfunc2<tany, tany> myFunc = _f2<tany, tany>([document](tany p1, tany p2) {
				document->getElementById("demo1")->innerHTML(document->getElementById("demo1")->innerHTML() + "Hello");
				document->getElementById("demo2")->innerHTML("Parameters passed: " + to_string(p1) + " " + to_string(p2));
				});

			g->setInterval(_f([myFunc]() { myFunc("param1", "param2"); }), 2000);
		}
	}

	// setTimeout() - https://www.w3schools.com/jsref/met_win_settimeout.asp
	{
		//: Wait 5 seconds for the greeting:
		{
			tfunc myGreeting = _f([document]() {
				document->getElementById("demo")->innerHTML("Happy Birthday!");
				});

			auto myTimeout = g->setTimeout(myGreeting, 5000);
		}
		//: Use clearTimeout(myTimeout) to prevent myGreeting from running:
		{
			tfunc myGreeting = _f([document]() {
				document->getElementById("demo")->innerHTML("Happy Birthday!");
				});

			auto myTimeout = g->setTimeout(myGreeting, 5000);

			tfunc myStopFunction = _f([g, myTimeout]() {
				g->clearTimeout(myTimeout);
				});

			myStopFunction();
		}
		//: Display an alert box after 3 seconds (3000 milliseconds):
		{
			int timeout;

			tfunc alertFunc = _f([g]() {
				g->alert("Hello!");
				});
			tfunc myFunction = _f([g, &timeout, alertFunc]() {
				timeout = g->setTimeout(alertFunc, 3000);
				});

			myFunction();
		}
		//: Display a timed text:
		{
			auto x = static_pointer_cast<HTMLInputElement>(document->getElementById("txt"));
			g->setTimeout(_f([x]() { x->value("2 seconds"); }), 2000);
			g->setTimeout(_f([x]() { x->value("4 seconds"); }), 4000);
			g->setTimeout(_f([x]() { x->value("6 seconds"); }), 6000);
		}
		//: Open a new window and close the window after three seconds (3000 milliseconds):
		{
			tfunc openWin = _f([g, window]() {
				auto myWindow = window->open("", "", "width=200, height=100");
				g->setTimeout([myWindow]() { myWindow->close(); }, 3000);
				});

			openWin();
		}
		//: Count forever - but with the ability to stop the count:
		{
			int counter = 0;
			int timeout;
			int timer_on = 0;

			tfunc timedCount = _f([g, document, &counter, timedCount, &timeout]() {
				static_pointer_cast<HTMLInputElement>(document->getElementById("demo"))->value(to_string(counter));
				counter++;
				timeout = g->setTimeout(timedCount, 1000);
				});

			tfunc startCount = _f([&timer_on, timedCount]() {
				if (!timer_on) {
					timer_on = 1;
					timedCount();
				}
				});

			tfunc stopCount = _f([g, timeout, &timer_on]() {
				g->clearTimeout(timeout);
				timer_on = 0;
				});

			startCount();
			stopCount();
		}
		//: A clock created with timing events:
		{
			tfunc startTime = _f([g, document, startTime]() {
				Date date;
				document->getElementById("demo")->innerHTML(date.toLocaleTimeString());
				g->setTimeout([startTime]() { startTime(); }, 1000);
				});

			startTime();
		}
		//: Pass parameters to the function (does not work in IE9 and earlier):
		{
			tfunc2<tany, tany> myFunc = _f2<tany, tany>([document](tany p1, tany p2) {
				document->getElementById("demo")->innerHTML("Parameters: " + to_string(p1) + " " + to_string(p2));
				});

			g->setTimeout(to_func(myFunc), 2000, "param1", "param2");
		}
		//: However, if you use an anonymous function, it will work in all browsers:
		{
			tfunc2<tany, tany> myFunc = _f2<tany, tany>([document](tany p1, tany p2) {
				document->getElementById("demo")->innerHTML("Parameters: " + to_string(p1) + " " + to_string(p2));
				});
			g->setTimeout(_f([myFunc]() { myFunc("param1", "param2"); }), 2000);
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