
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

/*
 * Time complexity: O(nlogn)
 * Ref solution
 * use merge sort to get inverse numbers, which calculates the relative difference in location
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
	
	Complete();
}
