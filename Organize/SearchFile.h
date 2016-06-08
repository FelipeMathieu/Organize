#pragma once

#include"mPaths.h"
#include"Index.h"
#include <iomanip>


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
	void calcSim();
	double cosine_similarity(vector<double> A, vector<double> B, unsigned int Vector_Length);
};

