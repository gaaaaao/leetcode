#include <iostream>

using namespace std;

class Unique_Binary_Search_Trees
{
public:
	void adaptor();
private:
	int numTrees(int n);
};

inline  void Unique_Binary_Search_Trees::adaptor()
{
	cout << numTrees(19) << endl;
}

inline int Unique_Binary_Search_Trees::numTrees(int n)
{
	unsigned long long nsig = 1;
	unsigned long long n2sig = 1;
	for (int i = 1; i < n; i++)
	{
		nsig *= i;
		n2sig *= n + i + 1;
	}
	nsig *= n;
	return (int)(n2sig/nsig);
}
