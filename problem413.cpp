#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> a = { 1,1,1,2,5,7,8,11 };
		numberOfArithmeticSlices(a);
	}
private:
	int numberOfArithmeticSlices(vector<int>& A) {
		int l = 2;
		vector<int> con;
		for (int i = 2; i<A.size(); i++)
		{
			if (A[i] + A[i - 2] == 2 * A[i - 1])
			{
				l++;
			}
			else
			{
				if (l >= 3)
				{
					con.push_back(l);
				}
				l = 2;
			}
		}
		if (l >= 3)
			con.push_back(l);
		int sum = 0;
		for (int i = 0; i<con.size(); i++)
		{
			sum += (con[i] - 1)*(con[i] - 2) / 2;
		}
		return sum;
	}
};