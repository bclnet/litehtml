#include <gtest/gtest.h>

#include <assert.h>
#include "litehtml.h"
#include "../containers/test/test_container.h"
using namespace litehtml;

static test_container container(800, 600, ".");
static document::ptr MakeDocument(char* source) { return document::createFromString(source, &container); }

TEST(Storage, Test) {
	auto document = MakeDocument("<html>Body</html>");
	document->render(50, render_all);
}