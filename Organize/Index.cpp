#include "Index.h"

int Index::Get_qtdeArq()
{
	return this->qtdeArq;
}

void Index::geraDF(int tamanho, mPaths m)
{
	this->wordSize = tamanho;
	this->U.first = m.GetNameOfFiles();
	ifstream arq("Save/Freq_Palavras.txt");
	//ofstream d("Save/DF.txt");
	int i = 0;
	vector<int> DF(this->wordSize);
	int freq = 0;
	string word;
	vector<string> auxVector;

	if (arq.is_open())
	{
		while (getline(arq, word).good())
		{
			//arq >> word;
			//cin.ignore(256, '\n');
			//getline(arq, word);
			auxVector = this->split(word);

			for (int i = 0; i < DF.size(); i++)
			{
				freq = stoi(auxVector.at(i), nullptr, 10);
				if (freq > 0)
				{
					DF.at(i)++;
				}
			}

			/*if (word.compare("BILL") != 0)
			{
				freq = stoi(word, nullptr, 10);
				if (freq > 0)
				{
					DF.at(i) += 1;
				}
				i++;
			}
			else
			{
				i = 0;
			}*/
		}
	}
	else
	{
		cout << "Erro ao abrir o arquivo !" << endl;
	}

	arq.close();

	geraIDF(DF, m);
}

void Index::geraIDF(vector<int> df, mPaths m)
{
	int j = 0;
	double aux = 0.0;

	//this->IDF = vector<double>(this->wordSize);

	for (int i = 0; i < this->wordSize; i++)
	{
		aux = log2(((double)this->qtdeArq) / ((double)df.at(i)));
		this->IDF.at(i) = aux;
		aux = 0.0;
	}

	geraU(m);
}

void Index::geraU(mPaths m)
{
	ifstream freq("Save/Freq_Palavras.txt");
	//ofstream U("Save/TF_IDF.txt");
	string word, nameFile;
	int i = 0, aux = 0, j = 0, k = 0;
	vector<string> auxVector;

	if (freq.is_open())
	{
		while (getline(freq, word).good())
		{
			//freq >> word;
			//cin.ignore(256, '\n');
			//getline(freq, word);
			auxVector = this->split(word);

			for (int i = 0; i < auxVector.size(); i++)
			{
				/*if (j1 != j)
				{
				nameFile = m.GetNameOfFiles().at(j1);
				U << nameFile << " ---> ";
				j1++;
				}*/

				aux = stoi(auxVector.at(i), nullptr, 10);
				j = find(this->U.first.begin(), this->U.first.end(), m.GetNameOfFiles().at(k)) - this->U.first.begin();
				this->U.second.at(j).push_back(this->IDF.at(i) * aux);

				//U << this->IDF.at(i)*aux << " ";
				//this->U[m.GetNameOfFiles().at(k)].push_back(this->IDF[m.Get_Words().at(i)] * aux);
				//this->U[nameFile].push_back(this->IDF[m.Get_Words().at(i)] * aux);
				//k++;
			}
			k++;
		}

		/*while (!freq.eof())
		{
			freq >> word;
			if (word.compare("BILL") != 0)
			{
				aux = stoi(word, nullptr, 10);

				//this->U.second.at(j).push_back(this->IDF[m.Get_Words().at(i)] * aux);
				this->U[m.GetNameOfFiles().at(j)].push_back(this->IDF[m.Get_Words().at(i)] * aux);
				i++;
			}
			else
			{
				j++;
				i = 0;
			}
		}*/
	}
	else
	{
		cout << "Erro!" << endl;
	}

	freq.close();
	//U.close();
}

vector<string> Index::split(const string &s)
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
