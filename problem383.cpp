#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class solution
{
public:
	void adaptor()
	{
		string ransomNote = "bg";
		string magazine = "bgfaseasdfasdasdfasdff";
		cout << canConstruct(ransomNote, magazine) << endl;
	}
private:
	bool canConstruct(string ransomNote, string magazine) {
		vector<int> prime = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
		unsigned long long productm = 1;
		unsigned long long productr = 1;

		for (int i = 0; i<magazine.length(); i++)
		{
			productm *= prime[magazine[i] - 97];
		}

		for (int i = 0; i<ransomNote.length(); i++)
		{
			if (productm % prime[ransomNote[i] - 97] == 0)
				productm /= prime[ransomNote[i] - 97];
			else
				return false;
		}

		return true;

	}
};