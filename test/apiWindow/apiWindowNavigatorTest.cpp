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

TEST(WindowNavigator, Test) {
	auto g = new MakeWindow("", R"xyz(
<html>
<body>
	<h1>The Window Navigator Object</h1>
	<p id="demo"></p>
</body>
</html>)xyz");
	auto document = g.document();
	auto navigator = g.navigator();

	// navigator.appCodeName - https://www.w3schools.com/jsref/prop_nav_appcodename.asp
	{
		//: Get browser code name:
		{
			auto browser = navigator->appCodeName();
			document->getElementById("demo")->innerHTML("Browser code name is : " + browser);
		}
		//: Display all navigator properties:
		{
			auto text = "<p>Browser CodeName: " + navigator->appCodeName() + "</p>" +
				"<p>Browser Name: " + navigator->appName() + "</p>" +
				"<p>Browser Version: " + navigator->appVersion() + "</p>" +
				"<p>Cookies Enabled: " + navigator->cookieEnabled() + "</p>" +
				"<p>Browser Language: " + navigator->language() + "</p>" +
				"<p>Browser Online: " + navigator->onLine() + "</p>" +
				"<p>Platform: " + navigator->platform() + "</p>" +
				"<p>User-agent header: " + navigator->userAgent() + "</p>";

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// navigator.appName - https://www.w3schools.com/jsref/prop_nav_appname.asp
	{
		//: Get browser name:
		{
			auto browser = navigator->appName();
			document->getElementById("demo")->innerHTML("Browser Name: " + browser);
		}
		//: Display all navigator properties:
		{
			auto text = "<p>Browser CodeName: " + navigator->appCodeName() + "</p>" +
				"<p>Browser Name: " + navigator->appName() + "</p>" +
				"<p>Browser Version: " + navigator->appVersion() + "</p>" +
				"<p>Cookies Enabled: " + navigator->cookieEnabled() + "</p>" +
				"<p>Browser Language: " + navigator->language() + "</p>" +
				"<p>Browser Online: " + navigator->onLine() + "</p>" +
				"<p>Platform: " + navigator->platform() + "</p>" +
				"<p>User-agent header: " + navigator->userAgent() + "</p>";

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// navigator.appVersion - https://www.w3schools.com/jsref/prop_nav_appversion.asp
	{
		//: Get browser version:
		{
			auto version = navigator->appVersion();
			document->getElementById("demo")->innerHTML("Browser version:<br>" + version);
		}
		//: Display all navigator properties:
		{
			auto text = "<p>Browser CodeName: " + navigator->appCodeName() + "</p>" +
				"<p>Browser Name: " + navigator->appName() + "</p>" +
				"<p>Browser Version: " + navigator->appVersion() + "</p>" +
				"<p>Cookies Enabled: " + navigator->cookieEnabled() + "</p>" +
				"<p>Browser Language: " + navigator->language() + "</p>" +
				"<p>Browser Online: " + navigator->onLine() + "</p>" +
				"<p>Platform: " + navigator->platform() + "</p>" +
				"<p>User-agent header: " + navigator->userAgent() + "</p>";

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// navigator.cookieEnabled - https://www.w3schools.com/jsref/prop_nav_cookieenabled.asp
	{
		//: Cookies enabled in your browser?
		{
			auto cookies = navigator->cookieEnabled();
			document->getElementById("demo")->innerHTML("Cookies enabled: " + cookies);
		}
		//: Display all navigator properties:
		{
			auto text = "<p>Browser CodeName: " + navigator->appCodeName() + "</p>" +
				"<p>Browser Name: " + navigator->appName() + "</p>" +
				"<p>Browser Version: " + navigator->appVersion() + "</p>" +
				"<p>Cookies Enabled: " + navigator->cookieEnabled() + "</p>" +
				"<p>Browser Language: " + navigator->language() + "</p>" +
				"<p>Browser Online: " + navigator->onLine() + "</p>" +
				"<p>Platform: " + navigator->platform() + "</p>" +
				"<p>User-agent header: " + navigator->userAgent() + "</p>";

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// navigator.geolocation - https://www.w3schools.com/jsref/prop_nav_geolocation.asp
	{
		//: Get the latitude and longitude of the user's position:
		{
			function<void(tany)> showPosition = [document](tany position) {
				document->getElementById("demo")->innerHTML(
					"Latitude: " + position->coords()->latitude() + "<br>" +
					"Longitude: " + position->coords()->longitude());
			};

			if (navigator->geolocation()) {
				navigator->geolocation()->getCurrentPosition(showPosition);
			}
			else {
				document->getElementById("demo").innerHTML("Geolocation is not supported by this browser.");
			}
		}
	}

	// navigator.javaEnabled() - https://www.w3schools.com/jsref/met_nav_javaenabled.asp
	{
		//: Is Java enabled in your browser?
		{
			auto java = navigator->javaEnabled();
			document->getElementById("demo")->innerHTML("Java Enabled: " + java);
		}
	}

	// navigator.language - https://www.w3schools.com/jsref/prop_nav_language.asp
	{
		//: Get the browser language:
		{
			auto language = navigator->language();
			document->getElementById("demo")->innerHTML("Browser language: " + language);
		}
		//: Display all navigator properties:
		{
			auto text = "<p>Browser CodeName: " + navigator->appCodeName() + "</p>" +
				"<p>Browser Name: " + navigator->appName() + "</p>" +
				"<p>Browser Version: " + navigator->appVersion() + "</p>" +
				"<p>Cookies Enabled: " + navigator->cookieEnabled() + "</p>" +
				"<p>Browser Language: " + navigator->language() + "</p>" +
				"<p>Browser Online: " + navigator->onLine() + "</p>" +
				"<p>Platform: " + navigator->platform() + "</p>" +
				"<p>User-agent header: " + navigator->userAgent() + "</p>";

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// navigator.onLine - https://www.w3schools.com/jsref/prop_nav_online.asp
	{
		//: Is the browser online?
		{
			auto online = navigator->onLine();
			document->getElementById("demo")->innerHTML("Browser online: " + online);
		}
		//: Display all navigator properties:
		{
			auto text = "<p>Browser CodeName: " + navigator->appCodeName() + "</p>" +
				"<p>Browser Name: " + navigator->appName() + "</p>" +
				"<p>Browser Version: " + navigator->appVersion() + "</p>" +
				"<p>Cookies Enabled: " + navigator->cookieEnabled() + "</p>" +
				"<p>Browser Language: " + navigator->language() + "</p>" +
				"<p>Browser Online: " + navigator->onLine() + "</p>" +
				"<p>Platform: " + navigator->platform() + "</p>" +
				"<p>User-agent header: " + navigator->userAgent() + "</p>";

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// navigator.platform - https://www.w3schools.com/jsref/prop_nav_platform.asp
	{
		//: Get the browser version:
		{
			auto platform = navigator->platform();
			document->getElementById("demo")->innerHTML("Platform: " + platform);
		}
		//: Display all navigator properties:
		{
			auto text = "<p>Browser CodeName: " + navigator->appCodeName() + "</p>" +
				"<p>Browser Name: " + navigator->appName() + "</p>" +
				"<p>Browser Version: " + navigator->appVersion() + "</p>" +
				"<p>Cookies Enabled: " + navigator->cookieEnabled() + "</p>" +
				"<p>Browser Language: " + navigator->language() + "</p>" +
				"<p>Browser Online: " + navigator->onLine() + "</p>" +
				"<p>Platform: " + navigator->platform() + "</p>" +
				"<p>User-agent header: " + navigator->userAgent() + "</p>";

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// navigator.product - https://www.w3schools.com/jsref/prop_nav_product.asp
	{
		//: Get the navigator.product:
		{
			auto product = navigator->product();
			document->getElementById("demo")->innerHTML("Browser product: " + product);
		}
		//: Display all navigator properties:
		{
			auto text = "<p>Browser CodeName: " + navigator->appCodeName() + "</p>" +
				"<p>Browser Name: " + navigator->appName() + "</p>" +
				"<p>Browser Version: " + navigator->appVersion() + "</p>" +
				"<p>Cookies Enabled: " + navigator->cookieEnabled() + "</p>" +
				"<p>Browser Language: " + navigator->language() + "</p>" +
				"<p>Browser Online: " + navigator->onLine() + "</p>" +
				"<p>Platform: " + navigator->platform() + "</p>" +
				"<p>User-agent header: " + navigator->userAgent() + "</p>";

			document->getElementById("demo")->innerHTML(text);
		}
	}

	// navigator.userAgent - https://www.w3schools.com/jsref/prop_nav_useragent.asp
	{
		//: Get navigator.userAgent:
		{
			auto agent = navigator->userAgent();
			document->getElementById("demo")->innerHTML("User-agent:<br>" + agent);
		}
		//: Display all navigator properties:
		{
			auto text = "<p>Browser CodeName: " + navigator->appCodeName() + "</p>" +
				"<p>Browser Name: " + navigator->appName() + "</p>" +
				"<p>Browser Version: " + navigator->appVersion() + "</p>" +
				"<p>Cookies Enabled: " + navigator->cookieEnabled() + "</p>" +
				"<p>Browser Language: " + navigator->language() + "</p>" +
				"<p>Browser Online: " + navigator->onLine() + "</p>" +
				"<p>Platform: " + navigator->platform() + "</p>" +
				"<p>User-agent header: " + navigator->userAgent() + "</p>";

			document->getElementById("demo")->innerHTML(text);
		}
	}
}