#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> digits = { 9,9 };
		plusOne(digits);
		for (vector<int>::iterator iter = digits.begin(); iter != digits.end(); iter++)
		{
			cout << *iter << "\t";
		}
		cout << endl;
	}
private:
	vector<int> plusOne(vector<int> &digits)
	{
		int len = digits.size();
		vector<int>::reverse_iterator riter;
		for (riter = digits.rbegin(); riter != digits.rend(); riter++)
		{
			if (*riter < 9)
			{
				*riter += 1;
				return digits;
			}
			else
				*riter = 0;
		}
		digits.insert(digits.begin(), 1);
		return digits;
	}
};