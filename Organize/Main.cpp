#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

void main(void)
{
	ifstream fin;
	string a, b;
	int count = 0;
	clock_t k = NULL, m = NULL, result = NULL;
	float r;

	cout << "Insira a palavra a ser pesquisada: ";
	cin >> a;

	fin.open("palavras.txt");

	k = clock();
	while (!fin.eof())
	{
		fin >> b;
		if (a == b)
		{
			count += 1;
		}
	}
	m = clock();

	result = m - k;
	r = ((float)result) / CLOCKS_PER_SEC;

	cout << "A palavra '" << a << "' aparece " << count << " vezes no arquivo." << endl;
	cout << "Tempo de execucao: " << r << endl;
	fin.close();
}