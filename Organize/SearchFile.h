#pragma once

#include"mPaths.h"
#include"Index.h"
#include <iomanip>


class SearchFile
{
private:
	vector<string> pesquisa;
	Index in;
	pair<vector<string>, vector<double>> V;
	vector<string> split(const string &s);

	string filtraPalavra(string p);

public:
	SearchFile(string p, Index in);
	~SearchFile();
	void geraV(map<string, int> fPalavras);
	void freqPesquisa();
	void calcSim();
	double cosine_similarity(vector<double> A, vector<double> B, unsigned int Vector_Length);
};

