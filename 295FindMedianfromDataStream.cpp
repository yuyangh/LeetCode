#include <stdlib.h>
#include "LeetCodeLib.h"

class MedianFinder {
public:
	/** initialize your data structure here. */
	// important!!! less<> is put large at the top
	priority_queue<int, vector<int>, less<int>> small;
	priority_queue<int, vector<int>, greater<int>> large;
	double median = 0;
	
	MedianFinder() {
	
	}
	
	void addNum(int num) {
		if (large.empty() && small.empty()) {
			median = num;
			small.push(num);
			return;
		}
		
		
		if (num < small.top()) {
			small.push(num);
		} else {
			large.push(num);
		}
		
		if (small.size() == large.size()) {
			median = ((double) small.top() + (double) large.top()) / 2.0;
		} else {
			if (abs(((long) small.size() - (long) large.size())) > 1) {
				if (small.size() > large.size()) {
					large.push(small.top());
					small.pop();
				} else {
					small.push(large.top());
					large.pop();
				}
				median = ((double) small.top() + (double) large.top()) / 2.0;
			} else {
				if (small.size() > large.size()) {
					median = small.top();
				} else {
					median = large.top();
				}
			}
		}
		
	}
	
	double findMedian() {
		return median;
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
	MedianFinder mf;
	mf.addNum(1);
	mf.addNum(2);
	cout << mf.findMedian() << endl;
	mf.addNum(3);
	cout << mf.findMedian() << endl;
}