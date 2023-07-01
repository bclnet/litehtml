#define _CRT_SECURE_NO_WARNINGS
#include <gtest/gtest.h>
#include <fstream>
#ifdef _WIN32
#include "dirent.h"
#else
#include <dirent.h>
#endif
#include "../containers/test/test_utils.h"
#include "../containers/test/test_container.h"
#include "../containers/graph/graph_container.h"
#include "../containers/test/Bitmap.h"
using namespace std;

static vector<string> find_htm_files();
static void test(string filename);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
using render_graph_test = testing::TestWithParam<string>;

TEST_P(render_graph_test, _)
{
	test(test_dir + GetParam());
}

INSTANTIATE_TEST_SUITE_P(, render_graph_test, testing::ValuesIn(find_htm_files()));
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

static vector<string> find_htm_files()
{
	find_test_dirs();

	DIR* dir = opendir(test_dir);
	if (!dir) error("Cannot read test directory!");
	vector<string> ret;
	while (dirent* ent = readdir(dir))
	{
		if (ent->d_type != DT_REG) continue; // if not regular file
		string name = ent->d_name;
		if (name[0] != '-' && name.size() > 4 && name.substr(name.size() - 4) == ".htm") {
			ret.push_back(name);
			break;
		}
	}
	closedir(dir);
	sort(ret.begin(), ret.end());
	return ret;
}

static Bitmap draw(document::ptr doc, litehtml::size sz)
{
	Bitmap bmp(sz.width, sz.height);
	position clip(point_zero, sz);

	doc->draw((uint_ptr)&bmp, point_zero, &clip);

	bmp.resize(sz.width, sz.height);

	return bmp;
}

static void test(string filename)
{
	string html = readfile(filename);

	int width = 800, height = 1600, depth = 2000; // image will be cropped to content_width/content_height
	test_container container(width, height, test_dir);
	graph_container gcontainer(SIZE(width, height, depth), &container);

	auto doc = document::createFromString(html.c_str(), &gcontainer);
	doc->render(width);
	Bitmap bmp = draw(doc, doc->content_size());
	//bmp.save(filename + "-graph-FAILED.png");
}
