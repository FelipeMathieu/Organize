#pragma once

#include"mPaths.h"
#include"Index.h"

class SearchFile
{
private:
	vector<string> pesquisa;
public:
	SearchFile(string p);
	~SearchFile();
	vector<string> split(const string &s);
};

