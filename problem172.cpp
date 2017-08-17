#include <iostream>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		int n = 1808548329;
		cout << trailingZeroes(n) << endl;
	}
private:
	int trailingZeroes(int n) {
		long long index = 5;
		long count = 0;
		long x = n;
		while (index <= x)
		{
			count += x / index;
			index *= 5;
			
		}
		return int(count);
	}
};