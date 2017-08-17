#include <iostream>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		isHappy(7);
	}
private:
	bool isHappy(int n) {
		if (n == 0)
			return false;
		int temp = 0;
		int x = 0;
		while (n != 1)
		{
			x = floor(log10(n));
			if (x != 0 && (n % (int)pow(10.0, x) == 0) && n / (int)pow(10.0, x) == 1) return true;
			else if (x != 0 && (n % (int)pow(10, x) == 0) && n / (int)pow(10, x) != 1) return false;
			else
			{
				while (n != 0)
				{
					temp += (n % 10)*(n % 10);
					n /= 10;
				}
				n = temp;
				temp = 0;
			}
		}

	}
};