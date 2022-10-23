#include <gtest/gtest.h>

#include <assert.h>
#include "litehtml.h"
#include "test/container_test.h"
using namespace litehtml;

TEST(Rect, Test) {
	context ctx;
	container_test container;
	litehtml::document::ptr doc = document::createFromString("<html>Body</html>", &container, &ctx);
	doc->render(50, render_all);
}