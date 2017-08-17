#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		manyfishes();
	}
private:
	void manyfishes()
	{
		int min = 0;
		int max = 0;
		cin >> min >> max;
		int totalfishes = max - min + 1;
		int fishnum = 0;
		cin >> fishnum;
		vector<bool> pendingfishes(totalfishes);
		iota(pendingfishes.begin(), pendingfishes.end(), min);
		int curfish = 0;
		for (int i = 0; i<fishnum; i++)
		{
			cin >> curfish;
			int biggerfishmin = min / curfish;
			int biggerfishmax = max / curfish;
			for (int i = biggerfishmin; i <= biggerfishmax; i++)
			{
				if (i < 2)
					continue;
				if (i > 10)
					break;
				pendingfishes[curfish*i - min] = false;
			}
			biggerfishmin = curfish / max;
			biggerfishmax = curfish / min;
			for (int i = biggerfishmin;i <= biggerfishmax; i++)
			{
				if (i < 2)
					continue;
				if (i > 10)
					break;
				if(curfish%i == 0)
					pendingfishes[curfish / i - min] = false;
			}
		}
		int res = 0;
		for (auto i : pendingfishes)
		{
			if (i)
				res++;
		}
		cout << res << endl;

	}
};