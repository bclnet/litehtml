#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#ifdef _WIN32
	#include "dirent.h"
#else
	#include <dirent.h>
#endif
#include "test_directory.h"
using namespace std;

const char* test_dir;
const char* test_dirs[] = {
	"../test/render/",			// ctest is run from litehtml/build
	"../../../test/render/",	// ctest is run from litehtml/out/build/*/
	NULL
};

const char* font_dir;
const char* font_dirs[] = {
	"../containers/test/fonts/",		// ctest is run from litehtml/build
	"../../../containers/test/fonts/",	// ctest is run from litehtml/build
	NULL
};

void find_test_dir()
{
	int i = 0;
	for (const char* path = test_dirs[0]; path; path = test_dirs[++i])
	{
		DIR* dir = opendir(path);
		if (dir)
		{
			closedir(dir);
			test_dir = path;
			return;
		}
	}
	puts("Cannot find test directory!");
	exit(1);
}

void find_font_dir()
{
	int i = 0;
	for (const char* path = font_dirs[0]; path; path = font_dirs[++i])
	{
		DIR* dir = opendir(path);
		if (dir)
		{
			closedir(dir);
			font_dir = path;
			return;
		}
	}
	puts("Cannot find font directory!");
	exit(1);
}