#pragma once

#include"mPaths.h"
#include"Index.h"

class SearchFile
{
private:
	vector<string> pesquisa;
	mPaths m;
	Index in;
	vector<double> V;

	vector<string> split(const string &s);

public:
	SearchFile(string p, mPaths m, Index in);
	~SearchFile();
	void geraV(map<string, int> fPalavras);
	void freqPesquisa();
};

