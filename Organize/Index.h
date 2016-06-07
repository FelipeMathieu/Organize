#pragma once

#include "mPaths.h"
#include <math.h>

class Index
{
private:
	int qtdeArq = 0;
	vector<double> IDF;
	map<string, vector<double>> U;
	int wordSize;

public:
	Index(int n)
	{
		this->qtdeArq = n;
	}
	int Get_qtdeArq();
	void geraDF(int tamanho, mPaths m);
	void geraIDF(vector<int> df, mPaths m);
	void geraU(mPaths m);
};

