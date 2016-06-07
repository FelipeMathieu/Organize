#include "SearchFile.h"

SearchFile::SearchFile(string p, mPaths m, Index in)
{
	string aux;

	this->m = m;
	aux = this->m.filtraPalavra(p);
	this->pesquisa = split(aux);
	this->in = in;
}

SearchFile::~SearchFile()
{
}

vector<string> SearchFile::split(const string &s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	// invariant: we have processed characters [original value of i, i) 
	while (i != s.size())
	{
		// ignore leading blanks
		// invariant: characters in range [original i, current i) are all spaces
		while (i != s.size() && isspace(s[i]))
			++i;

		// find end of next word
		string_size j = i;
		// invariant: none of the characters in range [original j, current j)is a space
		while (j != s.size() && !isspace(s[j]))
			j++;
		// if we found some nonwhitespace characters 
		if (i != j) {
			// copy from s starting at i and taking j - i chars
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return ret;
}

void SearchFile::freqPesquisa()
{
	map<string, int> freqP;
	int j = 0;
	int count = 0;

	for (int i = 0; i < this->m.Get_Words().size(); i++)
	{
		for (int j = 0; j < this->pesquisa.size(); j++)
		{
			if (this->pesquisa.at(j) == this->m.Get_Words().at(i))
			{
				count += 1;
			}
		}
		freqP.insert(make_pair(this->m.Get_Words().at(i), count));
		count = 0;
	}

	geraV(freqP);
}

void SearchFile::geraV(map<string, int> fPalavras)
{
	for (int i = 0; i < fPalavras.size(); i++)
	{
		this->V.push_back(this->in.Get_IDF().at(i)*fPalavras[this->m.Get_Words().at(i)]);
	}
}