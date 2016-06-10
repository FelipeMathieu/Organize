#pragma once

#include "mPaths.h"
#include "Gerencia.h"
#include <math.h>

class Index
{
private:
	int qtdeArq = 0;
	vector<double> IDF;
	pair<vector<string>, vector<vector<double>>> U;
	vector<string> words;
	vector<string> nomeArquivo;
	pair<vector<string>, vector<vector<int>>> freqWords;
	int wordSize;

	vector<string> split(const string &s);

public:
	void IndexS(int n, mPaths m)
	{
		this->qtdeArq = n;
		this->U.second = vector<vector<double>>(this->qtdeArq);
		this->IDF = vector<double>(m.Get_Words().size());
		this->words = m.Get_Words();
		this->nomeArquivo = m.GetNameOfFiles();
		this->freqWords = m.GetfreqWords();
	}
	void IndexG(int n, Gerencia g)
	{
		this->qtdeArq = n;
		this->U = g.Get_Ug();
		this->IDF = g.Get_IDFg();
		this->words = g.Get_WordsG();
		this->nomeArquivo = g.Get_NameFiles();
		this->freqWords = g.Get_FreqG();
		//this->U.first = g.Get_NameFiles();
	}
	int Get_qtdeArq();
	void geraDF(int tamanho);
	void geraIDF(vector<int> df);
	void geraU();
	vector<double> Get_IDF()
	{
		return this->IDF;
	}
	pair<vector<string>, vector<vector<double>>> Get_U()
	{
		return this->U;
	}
	vector<string> GetNameOfFiles()
	{
		return this->nomeArquivo;
	}
	pair<vector<string>, vector<vector<int>>> GetfreqWords()
	{
		return this->freqWords;
	}
	vector<string> Get_Words()
	{
		return this->words;
	}
};

