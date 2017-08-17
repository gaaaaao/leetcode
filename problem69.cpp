#include <iostream>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		cout << mySqrt(4) << endl;
	}
private:
	int mySqrt(int x) {
		return binarysearch(x, 0, x / 2 + 1, (x / 2 + 1) / 2);
	}
	
	int binarysearch(int x, int start, int end, int n)
	{
		if ((long long)n*n > x)
			return binarysearch(x, start, n, (n + start) / 2);
		else if ((long long)n * n < x)
			return binarysearch(x, n, end, (end + n) / 2);
		else
			return n;
	}
};