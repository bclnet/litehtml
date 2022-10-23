#include <gtest/gtest.h>

#include <assert.h>
#include "litehtml.h"
#include "test/container_test.h"
using namespace litehtml;

static context ctx;
static container_test container;
static document::ptr MakeDocument(char* source) { return document::createFromString(source, &container, &ctx); }

TEST(Console, Test) {
	auto console = new Console();
	//document::ptr thedoc;
	// https://www.w3schools.com/jsref/met_console_assert.asp
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
			std::map<string, string> myObj = { {"firstname", "John"}, {"lastname", "Doe"} };
			console->assert_(x + y == 11, myObj);
		}

		auto document = MakeDocument(R"xyz(
<html>
<body>
<p id="demo"></p>
</body>
</html>)xyz");
		//: Check for an element:
		{
			console->assert_(document->getElementById("demo"), "You have no element with ID 'demo'");
		}
		//: Write an array to the console:
		{
			auto x = 5;
			auto y = 5;
			string myArr[] = { "Orange", "Banana", "Mango", "Kiwi" };
			console->assert_(x + y == 11, myArr);
		}
	}

	// https://www.w3schools.com/jsref/met_console_clear.asp
	{
		//: Clear all messages in the console:
		{
			console->clear();
		}
	}

	// https://www.w3schools.com/jsref/met_console_count.asp
	{
		//: Call console.count() 5 times: 
		{
			for (auto i = 0; i < 5; i++)
			{
				console->count();
			}
		}
		//: Call console.count() 5 times, with a label: 
		{
			for (auto i = 0; i < 5; i++)
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

	// https://www.w3schools.com/jsref/met_console_error.asp
	{
		//: Write an error to the console:
		{
			console->error("You made a mistake");
		}
		//: Use an object as the error message:
		{
			std::map<string, string> myObj = { {"firstname", "John"}, {"lastname", "Doe"} };
			console->error(myObj);
		}
		//: Use an array as the error message:
		{
			string myArr[] = { "Orange", "Banana", "Mango", "Kiwi" };
			console->error(myArr);
		}
	}

	// https://www.w3schools.com/jsref/met_console_group.asp
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

	// https://www.w3schools.com/jsref/met_console_groupcollapsed.asp
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

	// https://www.w3schools.com/jsref/met_console_groupend.asp
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

	// https://www.w3schools.com/jsref/met_console_info.asp
	{
		//: Write a message to the console:
		{
			console->info("Hello world!");
		}
		//: Using an object as the message:
		{
			std::map<string, string> myObj = { {"firstname", "John"}, {"lastname", "Doe"} };
			console->info(myObj);
		}
		//: Using an array as the message:
		{
			string myArr[] = { "Orange", "Banana", "Mango", "Kiwi" };
			console->info(myArr);
		}
	}

	// https://www.w3schools.com/jsref/met_console_log.asp
	{
		//: Write to the console:
		{
			console->log("Hello world!");
		}
		//: Write an object to the console:
		{
			std::map<string, string> myObj = { {"firstname", "John"}, {"lastname", "Doe"} };
			console->log(myObj);
		}
		//: Write an array to the console:
		{
			string myArr[] = { "Orange", "Banana", "Mango", "Kiwi" };
			console->log(myArr);
		}
	}

	// https://www.w3schools.com/jsref/met_console_table.asp
	{
		//: Write an array as a table in the console:
		{
			string p0[] = { "Audi", "Volvo", "Ford" };
			console->table(p0);
		}
		//: Write an object as a table in the console:
		{
			std::map<string, string> myObj = { {"firstname", "John"}, {"lastname", "Doe"} };
			console->table(&myObj);
		}
		//: Using an array of objects:
		{
			std::map<string, string> car1 = { {"name", "Audi"}, {"model", "A4"} };
			std::map<string, string> car2 = { {"name", "Volvo"}, {"model", "XC90"} };
			std::map<string, string> car3 = { {"name", "Ford"}, {"model", "Fusion"} };

			std::map<string, string> p0[] = { car1, car2, car3 };
			console->table(p0);
		}
		//: Only include the "model" column in the table:
		{
			std::map<string, string> car1 = { {"name", "Audi"}, {"model", "A4"} };
			std::map<string, string> car2 = { {"name", "Volvo"}, {"model", "XC90"} };
			std::map<string, string> car3 = { {"name", "Ford"}, {"model", "Fusion"} };

			std::map<string, string> p0[] = { car1, car2, car3 }; string p1[] = { "model" };
			console->table(p0, p1);
		}
	}

	// https://www.w3schools.com/jsref/met_console_time.asp
	{
		{
			console->time();
			for (int i = 0; i < 100000; i++)
			{
				// some code
			}
			console->timeEnd();
		}
		{
			console->time("test1");
			for (int i = 0; i < 100000; i++)
			{
				// some code
			}
			console->timeEnd("test1");
		}
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

	// https://www.w3schools.com/jsref/met_console_timeend.asp
	{
		{
			console->time();
			for (int i = 0; i < 100000; i++)
			{
				// some code
			}
			console->timeEnd();
		}
		{
			console->time("test1");
			for (int i = 0; i < 100000; i++)
			{
				// some code
			}
			console->timeEnd("test1");
		}
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

	// https://www.w3schools.com/jsref/met_console_trace.asp
	{
		{
			std::function<void()> myOtherFunction;

			std::function<void()> myFunction = [myOtherFunction]()
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

	// https://www.w3schools.com/jsref/met_console_warn.asp
	{
		{
			console->warn("This is a warning!");
		}
		{
			std::map<string, string> myObj = { {"firstname", "John"}, {"lastname", "Doe"} };
			console->warn(myObj);
		}
		{
			string myArr[] = { "Orange", "Banana", "Mango", "Kiwi" };
			console->warn(myArr);
		}
	}
}
