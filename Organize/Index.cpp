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
	int *DF, i = 0;
	int freq;
	string word;

	DF = (int*)malloc(tamanho * sizeof(int));

	for (int i = 0; i < tamanho; i++)
	{
		DF[i] = 0;
	}

	if (arq.is_open())
	{
		while (!arq.eof())
		{
			arq >> freq;
			if (freq != 0)
			{
				if (freq != '\n')
				{
					DF[i] += 1;
					i++;
				}
				else
				{
					i = 0;
				}
			}
		}
	}
	else
	{
		cout << "Erro ao abrir o arquivo !" << endl;
	}

	if (d.is_open())
	{
		for (int i = 0; i < tamanho; i++)
		{
			d << DF[i] << " ";
		}
	}
	else
	{
		cout << "Bugo!" << endl;
	}

	arq.close();
	d.close();
}