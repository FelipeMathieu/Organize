#pragma once

#include "mPaths.h"
#include <math.h>

class Index
{
private:
	int qtdeArq = 0;
	vector<double> IDF;
	pair<vector<string>, vector<vector<double>>> U;
	int wordSize;

	vector<string> split(const string &s);

public:
	void IndexS(int n, mPaths m)
	{
		this->qtdeArq = n;
		this->U.second = vector<vector<double>>(this->qtdeArq);
		this->IDF = vector<double>(m.Get_Words().size());
	}
	int Get_qtdeArq();
	void geraDF(int tamanho, mPaths m);
	void geraIDF(vector<int> df, mPaths m);
	void geraU(mPaths m);
	vector<double> Get_IDF()
	{
		return this->IDF;
	}
	pair<vector<string>, vector<vector<double>>> Get_U()
	{
		return this->U;
	}
};

