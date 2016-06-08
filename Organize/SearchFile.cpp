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

	this->calcSim();
}

void SearchFile::calcSim()
{
	map<string, double> sim;
	vector<double> aux = this->V, aux2;
	double result = 0.0;

	for (int i = 0; i < this->in.Get_qtdeArq(); i++)
	{
		sim[this->m.GetNameOfFiles().at(i)] = 0.0;
	}

	for (int i = 0; i < this->m.GetNameOfFiles().size(); i++)
	{
		aux2 = this->in.Get_U()[this->m.GetNameOfFiles().at(i)];

		sim[this->m.GetNameOfFiles().at(i)] = cosine_similarity(aux, aux2, aux.size());
	}

	cout << endl << "Arquivos compativeis: " << endl;
	for (int i = 0; i < sim.size(); i++)
	{
		if (sim[this->m.GetNameOfFiles().at(i)] > 0.0)
		{
			cout << this->m.GetNameOfFiles().at(i) << " --> " << setiosflags(ios::fixed) << setprecision(2) << (sim[this->m.GetNameOfFiles().at(i)] * 100) << "%" << endl;
		}
	}
}

double SearchFile::cosine_similarity(vector<double> A, vector<double> B, unsigned int Vector_Length)
{
	double dot = 0.0, denom_a = 0.0, denom_b = 0.0;
	for (unsigned int i = 0u; i < Vector_Length; ++i) {
		dot += A.at(i) * B.at(i);
		denom_a += A.at(i) * A.at(i);
		denom_b += B.at(i) * B.at(i);
	}
	return dot / (sqrt(denom_a) * sqrt(denom_b));
}