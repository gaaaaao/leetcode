#include <iostream>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		reverseBits(32768);
	}
private:
	uint32_t reverseBits(uint32_t n) {
		for (int i = 0; i<16; i++)
		{
			int r = (n >> i) % 2;
			int l = (n >> (31 - i)) % 2;
			if (l == r)
				continue;
			else if (l == 1)
			{
				n -= 1 << (31 - i);
				n += 1 << i;
			}
			else if (r == 1)
			{
				n += 1 << (31 - i);
				n -= 1 << i;
			}
		}
		return n;
	}
};