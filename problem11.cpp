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
        int water=0;
        int i=0,j=height.size()-1;
        
        while(i<j){
            water=max(water,min(height[i],height[j])*(j-i));
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        
        return water;
}
