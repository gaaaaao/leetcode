#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;
class Perfect_Rectangle
{
public:
	void adaptor();
private:
	bool isRectangleCover(vector<vector<int> >& rectangles);
};

inline void Perfect_Rectangle::adaptor()
{
	const int row = 4;
	const int col = 4;
	int rectangles[row][col] = { {0, 0, 1, 1},{0, 0, 2, 1},{1, 0, 2, 1 }, { 0, 2, 2, 3 } };
	vector<vector<int>> rec;
	
	for (int i = 0; i < row; i++)
	{
		vector<int> temp(rectangles[i], rectangles[i] + col);
		rec.push_back(temp);
	}
	cout << isRectangleCover(rec) << endl;
}

inline bool Perfect_Rectangle::isRectangleCover(vector<vector<int>>& rectangles)
{
	unordered_set<string> st;
	int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN, area = 0;
	for (auto rect : rectangles) {
		min_x = min(min_x, rect[0]);
		min_y = min(min_y, rect[1]);
		max_x = max(max_x, rect[2]);
		max_y = max(max_y, rect[3]);
		area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
		string s1 = to_string(rect[0]) + "_" + to_string(rect[1]); // bottom-left
		string s2 = to_string(rect[0]) + "_" + to_string(rect[3]); // top-left
		string s3 = to_string(rect[2]) + "_" + to_string(rect[3]); // top-right
		string s4 = to_string(rect[2]) + "_" + to_string(rect[1]); // bottom-right
		if (st.count(s1)) st.erase(s1);
		else st.insert(s1);
		if (st.count(s2)) st.erase(s2);
		else st.insert(s2);
		if (st.count(s3)) st.erase(s3);
		else st.insert(s3);
		if (st.count(s4)) st.erase(s4);
		else st.insert(s4);
	}
	string t1 = to_string(min_x) + "_" + to_string(min_y);
	string t2 = to_string(min_x) + "_" + to_string(max_y);
	string t3 = to_string(max_x) + "_" + to_string(max_y);
	string t4 = to_string(max_x) + "_" + to_string(min_y);
	if (!st.count(t1) || !st.count(t2) || !st.count(t3) || !st.count(t4) || st.size() != 4) return false;
	return area == (max_x - min_x) * (max_y - min_y);
}
