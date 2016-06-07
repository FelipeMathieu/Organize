#include "Index.h"

int Index::Get_qtdeArq()
{
	return this->qtdeArq;
}

void Index::geraDF(int tamanho)
{
	this->wordSize = tamanho;
	ifstream arq("Freq_Palavras.txt");
	ofstream d("DF.txt");
	int i = 0;
	vector<int> DF(this->wordSize);
	int freq = 0;
	string word;

	for (int j = 0; j < this->wordSize; j++)
	{
		DF.at(j) = 0;
	}

	if (arq.is_open())
	{
		while (!arq.eof())
		{
			arq >> word;
			if (word.compare("BILL") != 0)
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
			}
		}
	}
	else
	{
		cout << "Erro ao abrir o arquivo !" << endl;
	}

	if (d.is_open())
	{
		for (int j = 0; j < this->wordSize; j++)
		{
			d << DF.at(j) << " ";
		}
	}
	else
	{
		cout << "Bugo!" << endl;
	}

	arq.close();
	d.close();

	geraIDF(DF);
}

void Index::geraIDF(vector<int> df)
{
	ofstream idf("IDF.txt");
	int j = 0;
	double aux = 0.0;

	this->IDF = vector<double>(this->wordSize);

	for (int i = 0; i < this->wordSize; i++)
	{
		aux = log2 (((double)this->qtdeArq)/((double)df.at(i)));
		this->IDF.at(i) = aux;
		aux = 0.0;
	}

	if (idf.is_open())
	{
		for (int i = 0; i < this->IDF.size(); i++)
		{
			idf << this->IDF.at(i) << " ";
		}
	}
	else
	{
		cout << "Erro ao salvar IDF." << endl;
	}

	idf.close();

	geraU();
}

void Index::geraU()
{
	ifstream freq("Freq_Palavras.txt");
	ofstream U("TF_IDF.txt");
	string word;
	int i = 0, aux = 0, j = 1, j1 = 0;

	if (freq.is_open() && U.is_open())
	{
		while (!freq.eof())
		{
			freq >> word;
			if (word.compare("BILL") != 0)
			{
				if (j1 != j)
				{
					U << "DOC" << j1 + 1 << " ---> ";
					j1++;
				}

				aux = stoi(word, nullptr, 10);

				U << this->IDF.at(i)*aux << " ";
				i++;
	
			}
			else
			{
				U << endl;
				i = 0;
				j++;
			}
		}
	}
	else
	{
		cout << "Erro!" << endl;
	}
}