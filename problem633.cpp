#include <iostream>
#include <algorithm>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		judgeSquareSum(234);
	}
private:
	bool judgeSquareSum(int c) {
		int lo = ceil(sqrt(c));
		for (int i = 0; i<lo/2; i++)
		{
			int sum = c + 2 * i*(lo - i);
			double a = floor(sqrt(c + 2 * i*(lo - i)));
			double t = sqrt(c + 2 * i*(lo - i));
			if (floor(sqrt(c + 2 * i*(lo - i))) == sqrt(c + 2 * i*(lo - i)))
				return true;
		}
		return false;
	}
};