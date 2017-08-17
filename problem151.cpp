#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Reverse_Words_in_a_String
{
public:
	void adaptor()
	{
		string s = "                    b             a ";
		reverseWords(s);
		cout << s << endl;
	}
private:
	void reverseWords(string &s)
	{
		s += "\0";
		string ss = "";
		vector<string> words;
		int len = s.length();
		for (int i = 0; i<len;)
		{
			if (s[i] != ' ')
			{
				string temp = "";
				while (s[i] != '\0' & s[i] != ' ')
				{
					temp += s[i];
					i++;
				}
				ss = temp + ss;
				if (s[i] != '\0')
					ss = ' ' + ss;
			}
			else
				i++;
		}
		//s = "";
		//for (vector<string>::reverse_iterator iter = words.rbegin(); iter != words.rend(); iter++)
		//{
		//	s += *iter;
		//	if ((iter + 1) != words.rend())
		//		s += ' ';
		//}
		s = ss;
	}
};