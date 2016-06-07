#pragma once

#include "mPaths.h"
#include <math.h>

class Index
{
private:
	int qtdeArq = 0;
	vector<double> IDF;
	int wordSize;

public:
	Index(int n)
	{
		this->qtdeArq = n;
	}
	int Get_qtdeArq();
	void geraDF(int tamanho);
	void geraIDF(vector<int> df);
	void geraU();
};

