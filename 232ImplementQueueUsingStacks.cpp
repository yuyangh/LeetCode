#include "LeetCodeLib.h"

class MyQueue {
public:
	/** Initialize your data structure here. */
	stack<int> reverse, order;
	
	MyQueue() {
	
	}
	
	/** Push element x to the back of queue. */
	void push(int x) {
		restoreReverseElements();
		reverse.push(x);
	}
	
	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int result = peek();
		order.pop();
		return result;
	}
	
	/** Get the front element. */
	int peek() {
		restoreReverseElements();
		while (!reverse.empty()) {
			order.push(reverse.top());
			reverse.pop();
		}
		int result = order.top();
		return result;
	}
	
	/** Returns whether the queue is empty. */
	bool empty() {
		return reverse.empty() && order.empty();
	}
	
	void restoreReverseElements() {
		while (!order.empty()) {
			reverse.push(order.top());
			order.pop();
		}
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */