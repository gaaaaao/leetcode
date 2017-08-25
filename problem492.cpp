#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		constructRectangle(45);
	}
	vector<int> constructRectangle(int area) {
		vector<int> res;
		int sqr = sqrt(area);
		for (int i = sqr; i>0; i--)
		{
			if (area % i == 0)
			{
				res.push_back(area / i);
				res.push_back(i);
				return res;
			}
		}
	}
};