#include <iostream>
#include <string>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		cout << convertToBase7(100) << endl;
	}
public:
	string convertToBase7(int num) {
		string res = "";
		int remainder = 0;
		while (num != 0)
		{
			remainder = num % 7;
			res += remainder + 48;
			num /= 7;
		}
		res.insert()
		return res;
	}
};