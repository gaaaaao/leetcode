#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<string> list1 = { "ubbg","KFC" };
		vector<string> list2 = { "KFC" };
		vector<string> res = findRestaurant(list1, list2);
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i] << "\t";
		}
		cout << endl;
	}
private:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {

		map<string, int> hash1;
		map<string, int> hash2;
		vector<string> res;
		int sumindex = 10000;
		for (int i = 0; i<list1.size(); i++)
		{
			hash1[list1[i]] = i;
		}
		for (int i = 0; i<list2.size(); i++)
		{
			hash2[list2[i]] = i;
		}
		for (int i = 0; i<list1.size(); i++)
		{
			if (hash2.find(list1[i]) != hash2.end())
			{
				if (hash1[list1[i]] + hash2[list1[i]] <= sumindex)
				{
					res.push_back(list1[i]);
					sumindex = hash1[list1[i]] + hash2[list1[i]];
				}
			}
		}
		return res;
	}
};