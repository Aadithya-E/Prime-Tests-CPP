#define INT int

#include<iostream>
#include<vector>
#include<math.h>
#include<thread>

using namespace std;

vector<bool> result[8];
INT lim;
INT max;

void check1()
{
	INT i;
	INT j;
	INT counter = 0;
	for (i = 2; i < lim; i++)
	{
		if (result[1][i - 1])
		{
			continue;
		}
		if(!(counter == 0))
		{ 
			continue;
		}
		for (j = 0; j < max - 1; j++)
		{
			if ((j + 1) % i == 0 && (j + 1) != i)
			{
				result[1][j] = true;
			}
		}
	}
}

int main()
{
	cin >> max;

	vector<bool> lbool(max - 1);

	INT i = (INT)0;
	INT j;

	lim = sqrt(max);

	for (i = 0; i < 8; i++)
	{
		for (j = 0; result[i].size() < (max-1); j++)
		{
			result[i].push_back(false);
		}
	}
	
	for (i = 2; i < lim; i++)
	{
		if (lbool[i - 1])
		{
			continue;
		}
		for (j = 0; j < max - 1; j++)
		{
			if ((j + 1) % i == 0 && (j + 1) != i)
			{
				lbool[j] = true;
			}
		}
	}

	i = max - 1;
	for (i = max - 2; i >= 0; i--)
	{
		if (!(lbool[i]))
		{
			cout << i + 1 << endl;
		}
	}

	return 0;
}