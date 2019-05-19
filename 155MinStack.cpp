#include "LeetCodeLib.h"
class MinStack {
public:
	int minVal;
	vector<int> nums;
	
	/** initialize your data structure here. */
	MinStack() {
		minVal=INT_MAX;
	}
	
	void push(int x) {
		// <= sign helps to handle two identical number case
		if(x<=minVal){
			// saves a copy of 2nd smallest value
			nums.push_back(minVal);
			minVal=x;
		}
		nums.push_back(x);
	}
	
	void pop() {
		int num=nums.back();
		nums.pop_back();
		if(num==minVal){
			// get the 2nd smallest value
			minVal=nums.back();
			nums.pop_back();
		}
	}
	
	int top() {
		return nums.back();
	}
	
	int getMin() {
		return minVal;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */