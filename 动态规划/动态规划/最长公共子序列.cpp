#include<iostream>
#include<string>
using namespace std;

void LCSlength(int m, int n, char* x, char* y, int** c, char** b)
{
	for (int i = 1; i <= m; i++)
		c[i][0] = 0;
	for (int i = 1; i <= n; i++)
		c[0][i] = 0;

	int i, j;
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
		{
			if (x[i] == y[j])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 's';
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 'i';
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 'j';
			}

		}
}


void LCS(int i, int j, char* x, char** b)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 's')
	{
		LCS(i - 1, j - 1, x, b);
		cout << x[i];
	}
	else if (b[i][j] == 'i')
		LCS(i - 1, j, x, b);
	else
		LCS(i, j - 1, x, b);
}

/*
int main()
{
	const int r =8;
	char y[7] = {'0' ,'B','D','C','A','B','A' };
	char x[8] = { '0','A','B','C','B','D','A','B' };
	int** p = new int*[r];
	char** s = new char*[r];
	for (int i = 0; i < r; i++)
		p[i] = new int[r];
	for (int i = 0; i < r; i++)
		s[i] = new char[r];
	LCSlength(6, 7, x, y, p, s);
	LCS(6, 7, x, s);
	return 0;
}
*/
