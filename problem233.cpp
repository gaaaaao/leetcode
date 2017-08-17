#include <iostream>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		countDigitOne(234);
	}
private:
	int countDigitOne(int n) {
		int digits = 0;
		int p = n;
		while (p)
		{
			digits++;
			p /= 10;
		}
		int res = 0;
		//int k = num(n, digits);
		while (n)
		{
			int firdig = n / pow(10, digits - 1);
			if (firdig == 1)
			{
				if (n - pow(10, digits - 1) == 0)
					res += (digits - 1)*pow(10, digits - 2);
				else
					res += n - (pow(10, digits - 1)) + 1;

			}
			else
			{
				res += pow(10, digits - 1);
				res += firdig*(digits-1)*pow(10, digits - 2);
			}
			n -= firdig*pow(10, digits - 1);
			digits--;
		}
		//return num(n,digits);
		return res;
	}
	//int num(int n,int digits)
	//{
	//	if (digits == 0)
	//		return 0;
	//	int res = 0;
	//	int firdig = n / pow(10, digits - 1);
	//	if (digits > 1 && n - firdig*pow(10, digits - 1) == 0 && firdig == 1)
	//		return num(n - 1, digits - 1) + 1;
	//	else if (digits > 1 && n - firdig*pow(10, digits - 1) == 0)
	//		return num(n - 1, digits) + 1;
	//	if (firdig == 1)
	//	{
	//		res += n - (pow(10, digits - 1)) + 1;
	//	}
	//	else
	//	{
	//		res += pow(10, digits - 1);
	//		res += (firdig-1)*(digits - 1)*pow(10, digits - 2);
	//	}
	//	n -= firdig*pow(10, digits - 1);
	//	digits--;
	//	return res+2*num(n,digits);
	//}

};