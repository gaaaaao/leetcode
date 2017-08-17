#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> temp;
		vector<pair<int, int>> prerequisites;
		prerequisites.push_back(make_pair(1, 0));
		findOrder(2, prerequisites);
	}
private:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<bool>> map(numCourses, vector<bool>(numCourses, false));
		vector<int> courses(numCourses, 0);
		vector<int> res;
		iota(courses.begin(), courses.end(), 0);
		for (int i = 0; i<prerequisites.size(); i++)
		{
			int x = prerequisites[i].first;
			int y = prerequisites[i].second;
			map[x][y] = true;
		}
		while (!courses.empty())
		{
			vector<int> temp;
			for (int i = 0; i<courses.size(); i++)
			{
				int f = 0;
				for (int j = 0; j<numCourses; j++)
					f += map[courses[i]][j];
				if (f == 0)
					temp.push_back(courses[i]);
			}
			if (temp.empty())
				return vector<int>();
			for (int i = 0; i<temp.size(); i++)
			{
				res.push_back(temp[i]);
				for (int j = 0; i<numCourses; j++)
				{
					map[j][temp[i]] = false;
				}
			}
		}
		return res;
	}

};