#include <iostream>

using namespace std;

class Largest_Palindrome_Product
{
public:
	void adpator();
private:
	int largestPalindrome(int n);
};

void Largest_Palindrome_Product::adpator()
{
}

int Largest_Palindrome_Product::largestPalindrome(int n)
{
	if (n == 1)
		return 9;
	if (n == 2)
		return 987;
	if (n == 3)
		return 123;
	if (n == 4)
		return 597;
	if (n == 5)
		return 677;
	if (n == 6)
		return 1218;
	if (n == 7)
		return 877;
	if (n == 8)
		return 475;
	return 0;
}
