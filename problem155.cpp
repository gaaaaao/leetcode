#include <iostream>
#include <vector>

using namespace std;

class MinStack
{
public:
	vector<int> min;
	vector<int> stack;
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		stack.push_back(x);
		if (min.empty())
			min.push_back(x);
		else
		{
			if (x < min.back())
				min.push_back(x);
			else
				min.push_back(min.back());
		}
	}

	void pop() {
		stack.pop_back();
		min.pop_back();
	}

	int top() {
		return stack.back();
	}

	int getMin() {
		return min.back();
	}
};