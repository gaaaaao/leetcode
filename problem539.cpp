#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<string> timePoints = { 
			"12:12","12:13" };
		cout << findMinDifference(timePoints) << endl;
	}
private:
	int findMinDifference(vector<string>& timePoints) {
		int len = timePoints.size();
		vector<vector<int>> times(len, vector<int>(2, 0));
		for (int i = 0; i<len; i++)
		{
			times[i][0] = stoi(timePoints[i].substr(0, 2));
			times[i][1] = stoi(timePoints[i].substr(3, 2));
		}
		sort(times.begin(), times.end(), cmp);
		int hour = 24;
		int min = 60;
		for (int i = 0; i<len; i++)
		{
			int j = ((i - 1) % len + len) % len;
			int temph = times[i][0] - times[j][0];
			temph = (temph % 24 + 24) % 24;
			int tempm = times[i][1] - times[j][1];
			if (tempm < 0)
			{
				temph = ((temph-1)%24+24)%24;
				tempm = (tempm % 60 + 60) % 60;
			}
			if (temph < hour)
			{
				hour = temph;
				min = tempm;
			}
			else if (temph == hour && tempm < min)
				min = tempm;
		}
		return hour * 60 + min;
	}
	static bool cmp(vector<int>& a, vector<int>& b)
	{
		if (a[0] < b[0])
			return true;
		else if (a[0] == b[0])
			if (a[1] < b[1])
				return true;
		return false;
	}
};
