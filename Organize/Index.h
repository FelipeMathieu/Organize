#pragma once

#include "mPaths.h"

class Index
{
private:
	int qtdeArq = 0;
public:
	Index(int n)
	{
		this->qtdeArq = n;
	}
	int Get_qtdeArq();
	void geraDF(int tamanho);
};

