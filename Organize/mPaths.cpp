#include "mPaths.h"

mPaths::mPaths()
{
}

mPaths::~mPaths()
{
}

int mPaths::countPath(wchar_t *wC)
{
	int count = 0;
	wchar_t *file = wC;
	WIN32_FIND_DATA ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE;

	hFind = FindFirstFile(file, &ffd);

	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			count++;
		} while (FindNextFile(hFind, &ffd) == TRUE);
		FindClose(hFind);
	}
	else
	{
		cout << "Failed to find path" << endl;
	}

	return count;
}
