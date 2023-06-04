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

TEST(WindowConsole, Test) {
	auto g = MakeWindow("", R"xyz(
<html>
<body>
	<h1>The Console Object</h1>
	<p id="demo"></p>
</body>
</html>)xyz");
	auto document = g->document();
	auto console = g->console();

	// assert() - https://www.w3schools.com/jsref/met_console_assert.asp
	{
		//: Write a message to the console:
		{
			auto x = 5;
			auto y = 5;
			console->assert_(x + y == 11, "Expression returned false");
		}
		//: Write an object to the console:
		{
			auto x = 5;
			auto y = 5;
			map<string, string> myObj = { {"firstname", "John"}, {"lastname", "Doe"} };
			console->assert_(x + y == 11, myObj);
		}
		//: Check for an element:
		{
			console->assert_(!!document->getElementById("demo"), "You have no element with ID 'demo'");
		}
		//: Write an array to the console:
		{
			auto x = 5;
			auto y = 5;
			string myArr[] = { "Orange", "Banana", "Mango", "Kiwi" };
			console->assert_(x + y == 11, myArr);
		}
	}

	// clear() - https://www.w3schools.com/jsref/met_console_clear.asp
	{
		//: Clear all messages in the console:
		{
			console->clear();
		}
	}

	// count() - https://www.w3schools.com/jsref/met_console_count.asp
	{
		//: Call console.count() 5 times: 
		{
			for (int i = 0; i < 5; i++)
			{
				console->count();
			}
		}
		//: Call console.count() 5 times, with a label: 
		{
			for (int i = 0; i < 5; i++)
			{
				console->count("myLabel");
			}
		}
		//: Call console.count() two times:
		{
			console->count();
			console->count();
		}
		// Call console.count two times, with a label:
		{
			console->count("myLabel");
			console->count("myLabel");
		}
		//: To remove the label, use "" as a parameter:
		{
			console->count("");
			console->count("");
		}
	}

	// error() - https://www.w3schools.com/jsref/met_console_error.asp
	{
		//: Write an error to the console:
		{
			console->error("You made a mistake");
		}
		//: Use an object as the error message:
		{
			map<string, string> myObj = { {"firstname", "John"}, {"lastname", "Doe"} };
			console->error(myObj);
		}
		//: Use an array as the error message:
		{
			string myArr[] = { "Orange", "Banana", "Mango", "Kiwi" };
			console->error(myArr);
		}
	}

	// group() - https://www.w3schools.com/jsref/met_console_group.asp
	{
		//: Create a group of messages in the console:
		{
			console->log("Hello world!");
			console->group();
			console->log("Hello again, this time inside a group!");
		}
		//: End a group with console.groupEnd():
		{
			console->log("Hello world!");
			console->group();
			console->log("Hello again, this time inside a group!");
			console->groupEnd();
			console->log("and we are back.");
		}
		//: Specify a label for the group:
		{
			console->log("Hello world!");
			console->group("myLabel");
			console->log("Hello again, this time inside a group, with a label!");
		}
	}

	// groupCollapsed() - https://www.w3schools.com/jsref/met_console_groupcollapsed.asp
	{
		//: Create a collapsed group of messages in the console:
		{
			console->log("Hello world!");
			console->groupCollapsed();
			console->log("Hello again, this time inside a collapsed group!");
		}
		//: End a group with console.groupEnd():
		{
			console->log("Hello world!");
			console->groupCollapsed();
			console->log("Hello again, this time inside a collapsed group!");
			console->groupEnd();
			console->log("and we are back.");
		}
		//: Specify a label for the collapsed group:
		{
			console->log("Hello world!");
			console->groupCollapsed("myLabel");
			console->log("Hello again, this time inside a collapsed group, with a label!");
		}
	}

	// groupEnd() - https://www.w3schools.com/jsref/met_console_groupend.asp
	{
		//: End a message group with console.groupEnd():
		{
			console->log("Hello world!");
			console->group();
			console->log("Hello again, this time inside a group!");
			console->groupEnd();
			console->log("and we are back.");
		}
	}

	// info() - https://www.w3schools.com/jsref/met_console_info.asp
	{
		//: Write a message to the console:
		{
			console->info("Hello world!");
		}
		//: Using an object as the message:
		{
			map<string, string> myObj = { {"firstname", "John"}, {"lastname", "Doe"} };
			console->info(myObj);
		}
		//: Using an array as the message:
		{
			string myArr[] = { "Orange", "Banana", "Mango", "Kiwi" };
			console->info(myArr);
		}
	}

	// log() - https://www.w3schools.com/jsref/met_console_log.asp
	{
		//: Write to the console:
		{
			console->log("Hello world!");
		}
		//: Write an object to the console:
		{
			map<string, string> myObj = { {"firstname", "John"}, {"lastname", "Doe"} };
			console->log(myObj);
		}
		//: Write an array to the console:
		{
			string myArr[] = { "Orange", "Banana", "Mango", "Kiwi" };
			console->log(myArr);
		}
	}

	// table() - https://www.w3schools.com/jsref/met_console_table.asp
	{
		//: Write an array as a table in the console:
		{
			string p0[] = { "Audi", "Volvo", "Ford" };
			console->table(p0);
		}
		//: Write an object as a table in the console:
		{
			map<string, string> myObj = { {"firstname", "John"}, {"lastname", "Doe"} };
			console->table(&myObj);
		}
		//: Using an array of objects:
		{
			map<string, string> car1 = { {"name", "Audi"}, {"model", "A4"} };
			map<string, string> car2 = { {"name", "Volvo"}, {"model", "XC90"} };
			map<string, string> car3 = { {"name", "Ford"}, {"model", "Fusion"} };

			map<string, string> p0[] = { car1, car2, car3 };
			console->table(p0);
		}
		//: Only include the "model" column in the table:
		{
			map<string, string> car1 = { {"name", "Audi"}, {"model", "A4"} };
			map<string, string> car2 = { {"name", "Volvo"}, {"model", "XC90"} };
			map<string, string> car3 = { {"name", "Ford"}, {"model", "Fusion"} };

			map<string, string> p0[] = { car1, car2, car3 }; string p1[] = { "model" };
			console->table(p0, p1);
		}
	}

	// time() - https://www.w3schools.com/jsref/met_console_time.asp
	{
		//: The time it takes to run a for-loop 100.000 times:
		{
			console->time();
			for (int i = 0; i < 100000; i++)
			{
				// some code
			}
			console->timeEnd();
		}
		//: Using the label parameter:
		{
			console->time("test1");
			for (int i = 0; i < 100000; i++)
			{
				// some code
			}
			console->timeEnd("test1");
		}
		//: Which is fastest, the for loop or the while loop?
		{
			int i;
			console->time("test for loop");
			for (i = 0; i < 100000; i++)
			{
				// some code
			}
			console->timeEnd("test for loop");

			i = 0;
			console->time("test while loop");
			while (i < 1000000)
			{
				i++;
			}
			console->timeEnd("test while loop");
		}
	}

	// timeEnd() - https://www.w3schools.com/jsref/met_console_timeend.asp
	{
		//: How long does it take to perform a for-loop 100.000 times:
		{
			console->time();
			for (int i = 0; i < 100000; i++)
			{
				// some code
			}
			console->timeEnd();
		}
		//: Using the label parameter:
		{
			console->time("test1");
			for (int i = 0; i < 100000; i++)
			{
				// some code
			}
			console->timeEnd("test1");
		}
		//: Which is fastest, the for loop or the while loop?
		{
			int i;
			console->time("test for loop");
			for (i = 0; i < 100000; i++)
			{
				// some code
			}
			console->timeEnd("test for loop");

			i = 0;
			console->time("test while loop");
			while (i < 1000000)
			{
				i++;
			}
			console->timeEnd("test while loop");
		}
	}

	// trace() - https://www.w3schools.com/jsref/met_console_trace.asp
	{
		//: Show how the code ended up here:
		{
			function<void()> myOtherFunction;

			function<void()> myFunction = [myOtherFunction]()
			{
				myOtherFunction();
			};

			myOtherFunction = [console]()
			{
				console->trace();
			};

			//myFunction();
		}
	}

	// warn() - https://www.w3schools.com/jsref/met_console_warn.asp
	{
		//: Write a warning to the console:
		{
			console->warn("This is a warning!");
		}
		//: Use an object as the warning message:
		{
			map<string, string> myObj = { {"firstname", "John"}, {"lastname", "Doe"} };
			console->warn(myObj);
		}
		//: Use an array as the warning message:
		{
			string myArr[] = { "Orange", "Banana", "Mango", "Kiwi" };
			console->warn(myArr);
		}
	}
}
