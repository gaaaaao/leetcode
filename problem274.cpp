#include <iostream>
#include <map>
#include <vector>
using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> citations = { 4,4,0,0 };
		hIndex(citations);
	}
private:
	int hIndex(vector<int>& citations) 
	{
		map<int, int> hash;
		for (int i = 0; i<citations.size(); i++)
		{
			hash[citations[i]]++;
		}
		int cit = 0;
		for (int ind = hash.rbegin()->first; ind >= 0; ind--)
		{
			cit += hash[ind];
			if (cit >= ind)
				return cit;

		}
		return cit;
	}
};