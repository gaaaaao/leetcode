#include <iostream>
#include <vector>

using namespace std;

class Palindrome_Number {
public:
	void adaptor();
private:
	bool isPalindrome(int x);
};

inline void Palindrome_Number::adaptor()
{
	int i = 0;
	cin >> i;
	while (i != -1)
	{
		cout << isPalindrome(i) << endl;
		cin >> i;
	}
}

inline bool Palindrome_Number::isPalindrome(int x)
{
	if (x < 0)
		return false;
	int num = x;
	vector<char> digit;
	int i = -1;
	int left = 0;
	int right = 0;
	
	digit.push_back('#');
	while (num != 0)
	{
		i = num % 10;
		num = num / 10;
		digit.push_back(i);
		digit.push_back('#');
	}

	right = digit.size() - 1;

	while (right != left)
	{
		if (digit[left] == digit[right])
		{
			left++;
			right--;
			continue;
		}
		return false;
	}
	return true;
}
