#include <iostream>

using namespace std;

class Hamming_Distance
{
public:
	void adaptor();
private:
	int hammingDistance(int x, int y);
};

inline void Hamming_Distance::adaptor()
{
	cout << hammingDistance(2147483649,0) << endl;
}

inline int Hamming_Distance::hammingDistance(int x, int y)
{
	int count = 0;
	while(!(x == 0 && y == 0))
	{
		if ((x % 2) != (y % 2))
		{
			count++;
		}
		x >>= 1;
		y >>= 1;
	}
	return count;
}
