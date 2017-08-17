#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> res = getRow(3);
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i] << "\t";
		}
		cout << endl;
	}
private:
	vector<int> getRow(int rowIndex) {
		vector<int> res = {1};
		vector<int> temp;
		if (rowIndex == 0)
			return res;

		for (int i = 0; i < rowIndex; i++)
		{
			temp = res;
			res = {};
			res.push_back(1);
			for (int j = 1; j <= i; j++)
			{ 
				res.push_back(temp[j - 1] + temp[j]);
			}
			res.push_back(1);
		}
		return res;
	}
};