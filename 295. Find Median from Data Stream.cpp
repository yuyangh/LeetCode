/*
 * 295. Find Median from Data Stream
 * Hard
 *
 * The median is the middle value in an ordered integer list.
 * If the size of the list is even, there is no middle value
 * and the median is the mean of the two middle values.
 *
 * For example, for arr = [2,3,4], the median is 3.
 * For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
 *
 * Implement the MedianFinder class:
 * MedianFinder() initializes the MedianFinder object.
 * void addNum(int num) adds the integer num from the data stream to the data structure.
 * double findMedian() returns the median of all elements so far.
 * Answers within 10-5 of the actual answer will be accepted.
 *
 * Example 1:
 * Input
 * ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 * [[], [1], [2], [], [3], []]
 *
 * Output
 * [null, null, null, 1.5, null, 2.0]
 *
 * Explanation
 * MedianFinder medianFinder = new MedianFinder();
 * medianFinder.addNum(1);    // arr = [1]
 * medianFinder.addNum(2);    // arr = [1, 2]
 * medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
 * medianFinder.addNum(3);    // arr[1, 2, 3]
 * medianFinder.findMedian(); // return 2.0
 *
 * Constraints:
 * -105 <= num <= 105
 * There will be at least one element in the data structure before calling findMedian.
 * At most 5 * 104 calls will be made to addNum and findMedian.
 *
 * Follow up:
 * If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
 * If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
 */
#include "LeetCodeLib.h"

class MedianFinder {
public:
	/** initialize your binaryIndexTree structure here. */
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