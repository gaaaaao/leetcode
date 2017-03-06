#include <iostream>
#include <string>
using namespace std;

class License_Key_Formatting
{
public:
	void adaptor();
private:
	string licenseKeyFormatting(string S, int K);
};

inline void License_Key_Formatting::adaptor()
{
	string S = "2-4A0r7-4k";
	int k = 3;
	string s = licenseKeyFormatting(S, k);
	cout << s << endl;
}

inline string License_Key_Formatting::licenseKeyFormatting(string S, int K)
{
	S += "&";
	int count = 0;
	int i = 0;
	while(S[i] != '&')
	{

		if (S[i] > 96 && S[i] < 123)
			S[i] -= 32;

		if (S[i] == 45)
		{
			S.erase(i, 1);
			i--;
		}
		i++;
	}
	S.erase(S.length() - 1, 1);
	i = S.length()-1;
	if (K > i)
		return S;
	while(i > 0)
	{
		if (count == K - 1)
		{
			S.insert(i, "-");
			count = 0;
		}
		else
			count++;
		
		i--;
	}
	return S;
}
