
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
class Solution {
protected:
	void merge_countSmaller(vector<int>& indices, int first, int last,
	                        vector<int>& results, vector<int>& nums) {
		int count = last - first;
		if (count > 1) {
			int step = count / 2;
			int mid = first + step;
			merge_countSmaller(indices, first, mid, results, nums);
			merge_countSmaller(indices, mid, last, results, nums);
			vector<int> tmp;
			tmp.reserve(count);
			int idx1 = first;
			int idx2 = mid;
			int semicount = 0;
			while ((idx1 < mid) || (idx2 < last)) {
				if ((idx2 == last) || ((idx1 < mid) &&
				                       (nums[indices[idx1]] <= nums[indices[idx2]]))) {
					tmp.push_back(indices[idx1]);
					results[indices[idx1]] += semicount;
					++idx1;
				} else {
					tmp.push_back(indices[idx2]);
					++semicount;
					++idx2;
				}
			}
			move(tmp.begin(), tmp.end(), indices.begin()+first);
		}
	}
public:
	vector<int> countSmaller(vector<int>& nums) {
		int n = nums.size();
		vector<int> results(n, 0);
		vector<int> indices(n, 0);
		iota(indices.begin(), indices.end(), 0);
		merge_countSmaller(indices, 0, n, results, nums);
		return results;
	}
};

