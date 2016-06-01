#pragma once

#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <string>
#include <fstream>
#include <minwinbase.h>
#include <sstream>

using namespace std;

class mPaths
{
private:
	int nPath;

public:

	int countPath(wchar_t *wC);

	mPaths();
	~mPaths();
};

