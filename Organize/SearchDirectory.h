#pragma once

#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <string>
#include <fstream>
#include <minwinbase.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class SearchDirectory
{
	int countDir = 0, countFiles = 0;
public:
	SearchDirectory();
	~SearchDirectory();
	bool dirSearch(wchar_t *dirName_in, string diretorio);
	int Get_nDir()
	{
		return this->countDir;
	}
	int Get_nFiles()
	{
		return this->countFiles;
	}
};

