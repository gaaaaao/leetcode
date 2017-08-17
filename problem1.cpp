#include <iostream>
#include <vector>

class solution
{
public:
    void adaptor()
    {
    
    }
private:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> temp;
        for(int i = 0;i<nums.size();i++)
        {
            temp.push_back(make_pair(nums[i],i));
        }
        sort(temp.begin(), temp.end(),cmp);
        int i = 0;
        int j = temp.size()-1;
        while(i < j)
        {
            if(temp[i].first + temp[j].first > target)
                j--;
            else if(temp[i].first + temp[j].first < target)
                i++;
            else
            {
                vector<int> res;
                res.push_back(temp[i].second);
                res.push_back(temp[j].second);
                return res;
            }
        }

    }
    static bool cmp(pair<int, int> & a, pair<int, int> & b)
    {
        return a.first < b.first;
    }
}
