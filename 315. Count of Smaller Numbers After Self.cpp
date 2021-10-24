
#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (38.08%)
 * Likes:    1102
 * Dislikes: 49
 * Total Accepted:    76.2K
 * Total Submissions: 199.9K
 * Testcase Example:  '[5,2,6,1]'
 *
 * You are given an integer array nums and you have to return a new counts
 * array. The counts array has the property where counts[i] is the number of
 * smaller elements to the right of nums[i].
 *
 * Example:
 *
 *
 * Input: [5,2,6,1]
 * Output: [2,1,1,0]
 * Explanation:
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 *
 */

class BinaryIndexTree {
public:
	BinaryIndexTree(int size) {
		// it can contain numbers from 0 to size
		binaryIndexTree.resize(size + 1);
	}
	
	void update(int i, int val) {
		int delta = val - sumRange(i, i);
		for (i++; i < binaryIndexTree.size(); i += lowbit(i)) {
			binaryIndexTree[i] += delta;
		}
	}
	
	int sumRange(int start, int end) {
		return sum(end) - sum(start - 1);
	}

private:
	vector<int> binaryIndexTree;
	
	int lowbit(int num) {
		return num & (-num);
	}
	
	int sum(int num) {
		int result = 0;
		for (num++; num != 0; num -= lowbit(num)) {
			result += binaryIndexTree[num];
		}
		return result;
	}
};

/*
 * Time complexity: O(nlogn)
 * 1st idea: during merge, counted inverted item
 * Ref solution
 * use merge sort to get inverse numbers, which calculates the relative difference in location
 *
 * 2nd idea:
 * use segment tree or binary index tree to accumulate the count of items on the right
 * then do a range sum to get number of items on the right smaller than self
 */
class Solution {
public:
	vector<int> countSmaller(vector<int> &nums) {
		vector<int> smallerCount(nums.size());
		
		// number to its index
		vector<int> numIndex(nums.size());
		iota(numIndex.begin(), numIndex.end(), 0);
		
		mergeSort(nums, numIndex, 0, nums.size(), smallerCount);
		return smallerCount;
	}
	
	/*
	 * Use binary index tree
	 */
	vector<int> countSmaller2(vector<int> &nums) {
		int offset = 10000;
		vector<int> smallerCount(nums.size());
		
		BinaryIndexTree binaryIndexTree(25000);
		for (int i = nums.size() - 1; i >= 0; --i) {
			// count items smaller than self
			smallerCount[i] = binaryIndexTree.sumRange(0, -1+nums[i] + offset);
			// update the count
			binaryIndexTree.update(nums[i] + offset,
			                       1 + binaryIndexTree.sumRange(nums[i] + offset, nums[i] + offset));
		}
		
		
		return smallerCount;
	}
	
	/*
	 * segment tree implementation
	 */
	vector<int> countSmaller3(vector<int>& nums) {
		int offset = 1e4;        // offset negative to non-negative
		int size = 2 * 1e4 + 1;  // total possible values in nums
		vector<int> tree(size * 2);
		vector<int> result;
		
		for (int i = nums.size() - 1; i >= 0; i--) {
			int smaller_count = query(0, nums[i] + offset, tree, size);
			result.push_back(smaller_count);
			update(nums[i] + offset, 1, tree, size);
		}
		reverse(result.begin(), result.end());
		return result;
	}
	
	// implement segment tree
	void update(int index, int value, vector<int>& tree, int size) {
		// shift the index to the leaf
		index += size;
		
		// update from leaf to root
		tree[index] += value;
		while (index > 1) {
			index /= 2;
			tree[index] = tree[index * 2] + tree[index * 2 + 1];
		}
	}
	
	int query(int left, int right, vector<int>& tree, int size) {
		// return sum of [left, right)
		int result = 0;
		left += size;  // shift the index to the leaf
		right += size;
		while (left < right) {
			// if left is a right node
			// bring the value and move to parent's right node
			if (left % 2 == 1) {
				result += tree[left];
				left++;
			}
			// else directly move to parent
			left /= 2;
			// if right is a right node
			// bring the value of the left node and move to parent
			if (right % 2 == 1) {
				right--;
				result += tree[right];
			}
			// else directly move to parent
			right /= 2;
		}
		return result;
	}

private:
	void mergeSort(vector<int> &nums, vector<int> &numIndex, int begin, int end, vector<int> &smallerCount) {
		int length = end - begin;
		if (length > 1) {
			int mid = (begin + end) / 2;
			mergeSort(nums, numIndex, begin, mid, smallerCount);
			mergeSort(nums, numIndex, mid, end, smallerCount);
			
			vector<int> buffer;
			buffer.reserve(length);
			
			int leftIdx = begin, rightIdx = mid, semiArrCount = 0;
			while (leftIdx < mid || rightIdx < end) {
				if ((rightIdx == end) ||
				    (leftIdx < mid && nums[numIndex[leftIdx]] <= nums[numIndex[rightIdx]])) {
					buffer.push_back(numIndex[leftIdx]);
					// plus the relative count for the other array
					// the relative position difference is calculated with recursion
					smallerCount[numIndex[leftIdx]] += semiArrCount;
					leftIdx++;
					
				} else {
					buffer.push_back(numIndex[rightIdx]);
					rightIdx++;
					semiArrCount++;
					
				}
			}
			
			// write new Index to the old place
			move(buffer.begin(), buffer.end(), numIndex.begin() + begin);
		}
	}
};


int main() {
	Solution solution;
	vector<int> nums = {5, 2, 6, 1};
	
	PrintVector(solution.countSmaller(nums));
	
	
	PrintVector(solution.countSmaller2(nums));
	
	nums = {-1,-1};
	PrintVector(solution.countSmaller2(nums));
	
	Complete();
}
