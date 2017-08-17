#include <iostream>
#include <math.h>
using namespace std;

class Number_Complement
{
public:
	void adaptor();
private:
	int findComplement(int num);
};

void Number_Complement::adaptor()
{
}

int Number_Complement::findComplement(int num)
{
	if (num == 0)
		return 1;
	int sum = 0;
	int t = 0;
	int count = 0;
	while (num != 1 && num != -1)
	{
		t = !(num % 2);
		num >>= 1;
		sum += t * pow(2, count);
		count++;
	}

	return sum;
}
