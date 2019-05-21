#include "LeetCodeLib.h"

class MyStack {
public:
	/** Initialize your data structure here. */
	queue<int> a, b;
	
	MyStack() {
	
	}
	
	/** Push element x onto stack. */
	void push(int x) {
		a.push(x);
	}
	
	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		getLastElement();
		int result = a.front();
		a.pop();
		putElementsBack();
		return result;
	}
	
	/** Get the top element. */
	int top() {
		getLastElement();
		int result = a.front();
		b.push(result);
		a.pop();
		putElementsBack();
		return result;
	}
	
	/** Returns whether the stack is empty. */
	bool empty() {
		return a.empty() && b.empty();
	}
	
	void getLastElement() {
		while (a.size() > 1) {
			b.push(a.front());
			a.pop();
		}
	}
	
	void putElementsBack() {
		while (!b.empty()) {
			a.push(b.front());
			b.pop();
		}
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */