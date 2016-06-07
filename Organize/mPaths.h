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
	int meAjuda = 0;
	int nFiles;

public:
	int countPath(wchar_t *wC, string diretorio);
	int countWordFile(string name);
	int Get_nWords()
	{
		return this->words.size();
	}
	int Get_meAjuda()
	{
		return this->meAjuda;
	}
	void gravaPalavras();
	string filtraPalavra(string p);
	int verificaPalavra(string p);
	void comparaPalavras(wchar_t *wC, string diretorio);
	map<string, int> countFreq(string nomeArquivo);
	vector<string> GetNameOfFiles()
	{
		return this->nomeArquivo;
	}

	mPaths();
	~mPaths();
};
