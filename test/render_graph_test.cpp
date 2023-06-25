#define _CRT_SECURE_NO_WARNINGS
#include <gtest/gtest.h>
#include <fstream>
#ifdef _WIN32
#include "dirent.h"
#else
#include <dirent.h>
#endif
#include "../containers/test/location.h"
#include "../containers/test/test_container.h"
#include "../containers/graph/graph_container.h"
using namespace std;

vector<string> find_htm_files();
void test(string filename);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
using render_test = testing::TestWithParam<string>;

TEST_P(render_test, _)
{
	test(test_dir + GetParam());
}

INSTANTIATE_TEST_SUITE_P(, render_test, testing::ValuesIn(find_htm_files()));
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void error(const char* msg) { puts(msg); exit(1); }

vector<string> find_htm_files()
{
	find_test_dirs();

	DIR* dir = opendir(test_dir);
	if (!dir) error("Cannot read test directory!");
	vector<string> ret;
	while (dirent* ent = readdir(dir))
	{
		if (ent->d_type != DT_REG) continue; // if not regular file
		string name = ent->d_name;
		if (name[0] != '-' && name.size() > 4 && name.substr(name.size() - 4) == ".htm")
			ret.push_back(name);
	}
	closedir(dir);
	sort(ret.begin(), ret.end());
	return ret;
}

string readfile(string filename)
{
	stringstream ss;
	ifstream(filename) >> ss.rdbuf();
	return ss.str();
}

void* draw(document::ptr doc, litehtml::size sz)
{
	//Bitmap bmp(sz.width, sz.height);
	position clip(point_zero, sz);

	doc->draw(0, point_zero, &clip);

	//bmp.resize(sz.width, sz.height);

	return 0;
}

void test(string filename)
{
	string html = readfile(filename);

	int width = 800, height = 1600, depth = 2000; // image will be cropped to content_width/content_height
	test_container container(width, height, test_dir);
	graph_container gcontainer(SIZE(width, height, depth), &container);

	auto doc = document::createFromString(html.c_str(), &gcontainer);
	doc->render(width);
	void* graph = draw(doc, doc->content_size());
}
