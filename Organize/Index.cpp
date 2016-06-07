#include "Index.h"

int Index::Get_qtdeArq()
{
	return this->qtdeArq;
}

void Index::geraDF(int tamanho)
{
	ifstream arq("Freq_Palavras.txt");
	ofstream d("DF.txt");
	vector<string> p;
	int i = 0;
	vector<int> DF(tamanho);
	int freq = 0;
	string word;

	for (int j = 0; j < tamanho; j++)
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
					//i++;
					freq = 0;
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
		for (int j = 0; j < tamanho; j++)
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
}