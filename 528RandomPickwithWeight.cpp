//
// Created by Yuyang Huang on 6/5/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 *
 * https://leetcode.com/problems/random-pick-with-weight/description/
 *
 * algorithms
 * Medium (43.17%)
 * Likes:    661
 * Dislikes: 1838
 * Total Accepted:    84K
 * Total Submissions: 192.6K
 * Testcase Example:  '["Solution", "pickIndex"]\n[[[1]], []]'
 *
 * Given an array w of positive integers, where w[i] describes the weight of
 * index i, write a function pickIndex which randomly picks an index in
 * proportion to its weight.
 *
 * Note:
 *
 *
 * 1 <= w.length <= 10000
 * 1 <= w[i] <= 10^5
 * pickIndex will be called at most 10000 times.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * ["Solution","pickIndex"]
 * [[[1]],[]]
 * Output: [null,0]
 *
 *
 *
 * Example 2:
 *
 *
 * Input:
 * ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
 * [[[1,3]],[],[],[],[],[]]
 * Output: [null,0,1,1,1,0]
 *
 *
 * Explanation of Input Syntax:
 *
 * The input is two lists: the subroutines called and their arguments.
 * Solution's constructor has one argument, the array w. pickIndex has no
 * arguments. Arguments are always wrapped with a list, even if there aren't
 * any.
 *
 */

// @lc code=start

/*
 * Time complexity: O(log n) for pickIndex
 * use prefix sum and binary search
 */
class Solution {
public:
	Solution(vector<int> &w) : prefixSum(w.size()) {
		for (int i = 0; i < w.size(); ++i) {
			sum += w[i];
			prefixSum[i] = sum;
		}
	}
	
	int pickIndex() {
		int num = rand() % sum + 1;
		return binarySearch(num);
	}

private:
	vector<int> prefixSum;
	int sum = 0;
	
	/**
	 * return elements on the right if not find
	 * @param target
	 * @return index in the prefix sum
	 */
	int binarySearch(int target) {
		int left = 0, right = prefixSum.size();
		while (left < right) {
			int middle = (left + right) / 2;
			if (prefixSum[middle] == target) {
				return middle;
			} else if (prefixSum[middle] < target) {
				left = middle + 1;
			} else {
				right = middle;
			}
		}
		return right;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

int main() {
	vector<int> weight;
	
	PrintSingleResult("test1");
	weight = {1};
	Solution solution1(weight);
	PrintSingleResult(solution1.pickIndex());
	PrintSingleResult(solution1.pickIndex());
	
	PrintSingleResult("test2");
	weight = {1, 3};
	Solution solution2(weight);
	PrintSingleResult(solution2.pickIndex());
	PrintSingleResult(solution2.pickIndex());
	PrintSingleResult(solution2.pickIndex());
	PrintSingleResult(solution2.pickIndex());
	
	Complete();
}