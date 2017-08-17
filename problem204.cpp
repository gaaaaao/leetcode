#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		cout << countPrimes(1500000) << endl;
		cout << countPrimes(16) << endl;
	}
private:
	int countPrimes(int n) {
		/*int res = 0;
		for (int i = 2; i<n; i++)
		{
			int root = sqrt(i);
			for (int j = 2; j <= root; j++)
			{
				if (i%j == 0)
					goto label;
			}
			res++;
		label:
			continue;
		}
		return res;*/
		int *table = new int[n];
		int root = sqrt(n);
		int res = 0;
		int i, j;
		for (int i = 2; i < n; i++)
		{
			if (i % 2 == 0)
				table[i] = 1;
			else
				table[i] = 0;
		}
		for (i = 3; i <= root; i++)
		{
			if (table[i])
				continue;
			res++;
			for (j = 2; i * j < n; j++)
			{
				table[i*j] = 1;
			}
		}
		for (i; i < n; i++)
		{
			if (table[i] == 0)
				res++;
		}
		delete[] table;
		return res;
		//bool *Del = new bool[n]; // 标记是否被划去
		//Del[2] = false;

		//for (int i = 3; i<n; ++i)
		//	if (i % 2 == 0)
		//		Del[i] = true;  // 2的倍数全部划去
		//	else
		//		Del[i] = false;

		//for (int i = 3; i<n; i += 2)
		//	if (!Del[i])  // 之后第一个未被划去
		//	{
		//		if (i*i>n)  break;
		//		for (int j = 2; i*j<n; ++j)
		//			Del[i*j] = true;
		//	}

		//int count = 0;
		//for (int i = 2; i<n; ++i)
		//	if (!Del[i])
		//		++count;

		//delete[] Del;
		//return count;
	}
};