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

using namespace std;

class mPaths
{
private:
	int nPath;
	vector<string> words;
	int meAjuda = 0;

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

	mPaths();
	~mPaths();
};

