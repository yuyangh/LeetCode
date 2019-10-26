#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (39.35%)
 * Likes:    2209
 * Dislikes: 242
 * Total Accepted:    363.6K
 * Total Submissions: 924.1K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 *
 *
 *
 *
 * Example:
 *
 *
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 *
 *
 *
 *
 */

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end


class MinStack {
public:
	vector<int> nums;
	// keep min nums
	vector<int> minNums;
	
	/** initialize your data structure here. */
	MinStack() {
	
	}
	
	void push(int x) {
		if (minNums.empty()) {
			minNums.emplace_back(x);
		} else {
			// record down nums <= current minimum
			if (minNums.back() >= x) {
				minNums.emplace_back(x);
			}
		}
		nums.emplace_back(x);
	}
	
	void pop() {
		int num = nums.back();
		nums.pop_back();
		// if the num is the current minimum, pop the minNums
		if (num == minNums.back()) {
			nums.pop_back();
		}
	}
	
	int top() {
		return nums.back();
	}
	
	int getMin() {
		return minNums.back();
	}
};

class MinStackRef {
public:
	int minVal;
	vector<int> nums;
	
	/** initialize your data structure here. */
	MinStackRef() {
		minVal = INT_MAX;
	}
	
	void push(int x) {
		// <= sign helps to handle two identical number case
		if (x <= minVal) {
			// saves a copy of 2nd smallest value
			nums.push_back(minVal);
			minVal = x;
		}
		nums.push_back(x);
	}
	
	void pop() {
		int num = nums.back();
		nums.pop_back();
		if (num == minVal) {
			// get the 2nd smallest value
			minVal = nums.back();
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