#include <iostream>
#include <algorithm>

using namespace std;

class Rectangle_Area
{
public:
	void adapter();
private:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H);
};

inline void Rectangle_Area::adapter()
{
	cout << computeArea(1, 2, 3, 4, 5, 6, 7, 8) << endl;
}

inline int Rectangle_Area::computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	int area = (C - A)*(D - B) + (G - E)*(H - F);
	if (G<A || H<B || E>C || F>D)
		return area;
	return area - (min(C, G) - max(A, E))*(min(D, H) - max(B, F));
}
