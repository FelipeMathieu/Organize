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

class mPaths
{
private:
	int nPath;
	vector<string> words;
	vector<string> nomeArquivo;
	pair<vector<string>, vector<vector<int>>> freqWords;
	int meAjuda = 0;
	int nFiles;

public:
	int countPath(wchar_t *wC, string diretorio);
	int countWordFile(string name);
	int Get_meAjuda()
	{
		return this->meAjuda;
	}
	void gravaPalavras();
	string filtraPalavra(string p);
	int verificaPalavra(string p);
	void comparaPalavras(wchar_t *wC, string diretorio);
	vector<int> countFreq(string nomeArquivo);
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

	mPaths();
	~mPaths();
};
