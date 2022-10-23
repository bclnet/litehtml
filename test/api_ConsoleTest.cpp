#include <gtest/gtest.h>

#include <assert.h>
#include "litehtml.h"
#include "test/container_test.h"
using namespace litehtml;

static context ctx;
static container_test container;
static document::ptr MakeDocument(wchar_t* source) { return document::createFromString(source, &container, &ctx); }

TEST(Console, Test) {
	auto console = new Console();
	//document::ptr thedoc;
	// https://www.w3schools.com/jsref/met_console_assert.asp
	{
		//: Write a message to the console:
		{
			auto x = 5;
			auto y = 5;
			console->assert_(x + y == 11, _t("Expression returned false"));
		}
		//: Write an object to the console:
		{
			auto x = 5;
			auto y = 5;
			std::map<tstring, tstring> myObj = { {_t("firstname"), _t("John")}, {_t("lastname"), _t("Doe")} };
			console->assert_(x + y == 11, myObj);
		}

		auto document = MakeDocument(LR"xyz(
<html>
<body>
<p id="demo"></p>
</body>
</html>)xyz");
		//: Check for an element:
		{
			console->assert_(document->getElementById(_t("demo")), _t("You have no element with ID 'demo'"));
		}
		//: Write an array to the console:
		{
			auto x = 5;
			auto y = 5;
			tstring myArr[] = { _t("Orange"), _t("Banana"), _t("Mango"), _t("Kiwi") };
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
				console->count(_t("myLabel"));
			}
		}
		//: Call console.count() two times:
		{
			console->count();
			console->count();
		}
		// Call console.count two times, with a label:
		{
			console->count(_t("myLabel"));
			console->count(_t("myLabel"));
		}
		//: To remove the label, use "" as a parameter:
		{
			console->count(_t(""));
			console->count(_t(""));
		}
	}

	// https://www.w3schools.com/jsref/met_console_error.asp
	{
		//: Write an error to the console:
		{
			console->error(_t("You made a mistake"));
		}
		//: Use an object as the error message:
		{
			std::map<tstring, tstring> myObj = { {_t("firstname"), _t("John")}, {_t("lastname"), _t("Doe")} };
			console->error(myObj);
		}
		//: Use an array as the error message:
		{
			tstring myArr[] = { _t("Orange"), _t("Banana"), _t("Mango"), _t("Kiwi") };
			console->error(myArr);
		}
	}

	// https://www.w3schools.com/jsref/met_console_group.asp
	{
		//: Create a group of messages in the console:
		{
			console->log(_t("Hello world!"));
			console->group();
			console->log(_t("Hello again, this time inside a group!"));
		}
		//: End a group with console.groupEnd():
		{
			console->log(_t("Hello world!"));
			console->group();
			console->log(_t("Hello again, this time inside a group!"));
			console->groupEnd();
			console->log(_t("and we are back."));
		}
		//: Specify a label for the group:
		{
			console->log(_t("Hello world!"));
			console->group(_t("myLabel"));
			console->log(_t("Hello again, this time inside a group, with a label!"));
		}
	}

	// https://www.w3schools.com/jsref/met_console_groupcollapsed.asp
	{
		//: Create a collapsed group of messages in the console:
		{
			console->log(_t("Hello world!"));
			console->groupCollapsed();
			console->log(_t("Hello again, this time inside a collapsed group!"));
		}
		//: End a group with console.groupEnd():
		{
			console->log(_t("Hello world!"));
			console->groupCollapsed();
			console->log(_t("Hello again, this time inside a collapsed group!"));
			console->groupEnd();
			console->log(_t("and we are back."));
		}
		//: Specify a label for the collapsed group:
		{
			console->log(_t("Hello world!"));
			console->groupCollapsed(_t("myLabel"));
			console->log(_t("Hello again, this time inside a collapsed group, with a label!"));
		}
	}

	// https://www.w3schools.com/jsref/met_console_groupend.asp
	{
		//: End a message group with console.groupEnd():
		{
			console->log(_t("Hello world!"));
			console->group();
			console->log(_t("Hello again, this time inside a group!"));
			console->groupEnd();
			console->log(_t("and we are back."));
		}
	}

	// https://www.w3schools.com/jsref/met_console_info.asp
	{
		//: Write a message to the console:
		{
			console->info(_t("Hello world!"));
		}
		//: Using an object as the message:
		{
			std::map<tstring, tstring> myObj = { {_t("firstname"), _t("John")}, {_t("lastname"), _t("Doe")} };
			console->info(myObj);
		}
		//: Using an array as the message:
		{
			tstring myArr[] = { _t("Orange"), _t("Banana"), _t("Mango"), _t("Kiwi") };
			console->info(myArr);
		}
	}

	// https://www.w3schools.com/jsref/met_console_log.asp
	{
		//: Write to the console:
		{
			console->log(_t("Hello world!"));
		}
		//: Write an object to the console:
		{
			std::map<tstring, tstring> myObj = { {_t("firstname"), _t("John")}, {_t("lastname"), _t("Doe")} };
			console->log(myObj);
		}
		//: Write an array to the console:
		{
			tstring myArr[] = { _t("Orange"), _t("Banana"), _t("Mango"), _t("Kiwi") };
			console->log(myArr);
		}
	}

	// https://www.w3schools.com/jsref/met_console_table.asp
	{
		//: Write an array as a table in the console:
		{
			tstring p0[] = { _t("Audi"), _t("Volvo"), _t("Ford") };
			console->table(p0);
		}
		//: Write an object as a table in the console:
		{
			std::map<tstring, tstring> myObj = { { _t("firstname"), _t("John") }, { _t("lastname"), _t("Doe") } };
			console->table(&myObj);
		}
		//: Using an array of objects:
		{
			std::map<tstring, tstring> car1 = { {_t("name"), _t("Audi")}, {_t("model"), _t("A4")} };
			std::map<tstring, tstring> car2 = { {_t("name"), _t("Volvo")}, {_t("model"), _t("XC90")} };
			std::map<tstring, tstring> car3 = { {_t("name"), _t("Ford")}, {_t("model"), _t("Fusion")} };

			std::map<tstring, tstring> p0[] = { car1, car2, car3 };
			console->table(p0);
		}
		//: Only include the "model" column in the table:
		{
			std::map<tstring, tstring> car1 = { {_t("name"), _t("Audi")}, {_t("model"), _t("A4")} };
			std::map<tstring, tstring> car2 = { {_t("name"), _t("Volvo")}, {_t("model"), _t("XC90")} };
			std::map<tstring, tstring> car3 = { {_t("name"), _t("Ford")}, {_t("model"), _t("Fusion")} };

			std::map<tstring, tstring> p0[] = { car1, car2, car3 }; tstring p1[] = { _t("model") };
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
			console->time(_t("test1"));
			for (int i = 0; i < 100000; i++)
			{
				// some code
			}
			console->timeEnd(_t("test1"));
		}
		{
			int i;
			console->time(_t("test for loop"));
			for (i = 0; i < 100000; i++)
			{
				// some code
			}
			console->timeEnd(_t("test for loop"));

			i = 0;
			console->time(_t("test while loop"));
			while (i < 1000000)
			{
				i++;
			}
			console->timeEnd(_t("test while loop"));
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
			console->time(_t("test1"));
			for (int i = 0; i < 100000; i++)
			{
				// some code
			}
			console->timeEnd(_t("test1"));
		}
		{
			int i;
			console->time(_t("test for loop"));
			for (i = 0; i < 100000; i++)
			{
				// some code
			}
			console->timeEnd(_t("test for loop"));

			i = 0;
			console->time(_t("test while loop"));
			while (i < 1000000)
			{
				i++;
			}
			console->timeEnd(_t("test while loop"));
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
			console->warn(_t("This is a warning!"));
		}
		{
			std::map<tstring, tstring> myObj = { { _t("firstname"), _t("John") }, { _t("lastname"), _t("Doe") } };
			console->warn(myObj);
		}
		{
			tstring myArr[] = { _t("Orange"), _t("Banana"), _t("Mango"), _t("Kiwi") };
			console->warn(myArr);
		}
	}
}
