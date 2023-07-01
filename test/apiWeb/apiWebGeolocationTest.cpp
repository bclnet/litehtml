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

TEST(WebGeolocation, Test) {
	auto g = MakeWindow("", R"xyz(
<html>
<body>
	<h1>HTML DOM Attributes</h1>
	<p id="demo"></p>
</body>
</html>)xyz");
	auto document = g->document();
	auto navigator = g->navigator();

	// Geolocation API - https://www.w3schools.com/jsref/api_geolocation.asp
	{
	}

	// coordinates - https://www.w3schools.com/jsref/prop_geo_coordinates.asp
	{
		//: Get the latitude and longitude of the user's position:
		{
			auto x = document->getElementById("demo");

			tfunc1<Geolocation::Position::ptr> showPosition = _f1<Geolocation::Position::ptr>([x](Geolocation::Position::ptr position) {
				x->innerHTML("Latitude: " + to_string(position->coords()->latitude()) +
					"<br>Longitude: " + to_string(position->coords()->longitude()));
				});

			tfunc getLocation = _f([navigator, x, showPosition]() {
				if (navigator->geolocation()) {
					navigator->geolocation()->getCurrentPosition(showPosition);
				}
				else {
					x->innerHTML("Geolocation is not supported by this browser.");
				}
				});

			getLocation();
		}
	}

	// getCurrentPosition() - https://www.w3schools.com/jsref/met_geo_getcurrentposition.asp
	{
		//: Get the latitude and longitude of the user's position:
		{
			auto x = document->getElementById("demo");

			tfunc1<Geolocation::Position::ptr> showPosition = _f1<Geolocation::Position::ptr>([x](Geolocation::Position::ptr position) {
				x->innerHTML("Latitude: " + to_string(position->coords()->latitude()) +
					"<br>Longitude: " + to_string(position->coords()->longitude()));
				});

			tfunc getLocation = _f([navigator, x, showPosition]() {
				if (navigator->geolocation()) {
					navigator->geolocation()->getCurrentPosition(showPosition);
				}
				else {
					x->innerHTML("Geolocation is not supported by this browser.");
				}
				});

			getLocation();
		}
	}

	// position - https://www.w3schools.com/jsref/prop_geo_position.asp
	{
		//: Get the latitude and longitude of the user's position:
		{
			auto x = document->getElementById("demo");

			tfunc1<Geolocation::Position::ptr> showPosition = _f1<Geolocation::Position::ptr>([x](Geolocation::Position::ptr position) {
				x->innerHTML("Latitude: " + to_string(position->coords()->latitude()) +
					"<br>Longitude: " + to_string(position->coords()->longitude()));
				});

			tfunc getLocation = _f([navigator, x, showPosition]() {
				if (navigator->geolocation()) {
					navigator->geolocation()->getCurrentPosition(showPosition);
				}
				else {
					x->innerHTML("Geolocation is not supported by this browser.");
				}
				});

			getLocation();
		}
	}
}