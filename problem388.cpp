#include <iostream>

using namespace std;

class Longest_Absolute_File_Path
{
public:
	void adaptor();
private:
	int lengthLongestPath(string input);
};

void Longest_Absolute_File_Path::adaptor()
{
}

int Longest_Absolute_File_Path::lengthLongestPath(string input)
{
	int max = 0;
	int len = input.length();
	for (int i = 0; i < len; i++)
	{
		if (input[i] == '\\')
		{
			//if(input)
		}
	}
	return 0;
}
