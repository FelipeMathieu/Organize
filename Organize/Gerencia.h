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

class Gerencia
{
private:
	vector<string> nameFiles;
	vector<double> IDFg;
	vector<string> words;
	pair<vector<string>, vector<vector<double>>> Ug;
	pair<vector<string>, vector<vector<int>>> freqWords;

	vector<string> split(const string &s);
public:
	Gerencia();
	~Gerencia();
	int GerenciaFiles(wchar_t *wC, string diretorio);
	Gerencia *newG();
	int GetSize()
	{
		return this->nameFiles.size();
	}
	vector<string> Get_NameFiles()
	{
		return this->nameFiles;
	}
	vector<double> Get_IDFg()
	{
		return this->IDFg;
	}
	vector<string> Get_WordsG()
	{
		return this->words;
	}
	pair<vector<string>, vector<vector<double>>> Get_Ug()
	{
		return this->Ug;
	}
	pair<vector<string>, vector<vector<int>>> Get_FreqG()
	{
		return this->freqWords;
	}
};

