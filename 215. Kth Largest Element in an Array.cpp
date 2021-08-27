#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * 215. Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * Example 1:
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 *
 * Example 2:
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 *
 * Note:
 * You may assume k is always valid, 1 â‰¤ k â‰¤ array's length.
 *
 */

class Solution {
public:
	/*
	 * partition algo is O(n)
	 * maintaining a pq with size K is O(nlogk)
	 * pq is O(nlogn)
	*/
	int findKthLargest_nthElement(vector<int>& nums, int k) {
		nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
		return nums[k - 1];
	}
	
	int findKthLargest_partialSort(vector<int>& nums, int k) {
		partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
		return nums[k - 1];
	}
	
	int findKthLargest(vector<int> &nums, int k) {
		// less is smaller put at the front
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < nums.size(); i++) {
			pq.push(nums[i]);
			if (pq.size() > k) {
				pq.pop();
			}
		}
		return pq.top();
	}
};