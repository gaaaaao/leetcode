#include <iostream>
#include <vector>

using namespace std;

class Container_With_Most_Water
{
public:
	void adaptor();
private:
	int maxArea(vector<int>& height);
};

inline void Container_With_Most_Water::adaptor()
{
	vector<int> height;
	height.push_back(1);
	height.push_back(1);

	cout << maxArea(height) << endl;
}

inline int Container_With_Most_Water::maxArea(vector<int>& height)
{
	int left = 0;
	int right = height.size() - 1;
	int maxArea = 0;

	while (left < right)
	{
		if (height[left] >= height[right])
		{
			if (maxArea < height[right]*(right - left))
				maxArea = height[right]*(right - left);
			right--;
		}
		else if (height[left] < height[right])
		{
			if (maxArea < height[left] * (right - left))
				maxArea = height[left] * (right - left);
			left++;
		}
	}
	return maxArea;
}
