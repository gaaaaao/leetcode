#include <iostream>

using namespace std;

class Powxn
{
public:
	void adaptor();
private:
	double myPow(double x, int n);
	double iterp(double x, int n);
};

inline void Powxn::adaptor()
{
	cout << myPow(3, -3) << endl;;

}

inline double Powxn::myPow(double x, int n)
{
	if (n >= 0)
		return iterp(x, n);
	else
		return 1/iterp(x, -n);
}

inline double Powxn::iterp(double x, int n)
{
	if (n == 0)
		return 1;
	if (n % 2 == 0)
	{
		double t = iterp(x, n / 2);
		return t*t;
	}
	if (n % 2 == 1)
	{
		double t = iterp(x, n / 2);
		return t*t*x;
	}
}
