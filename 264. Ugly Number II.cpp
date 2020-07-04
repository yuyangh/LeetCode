//
// Created by Yuyang Huang on 7/4/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (37.80%)
 * Likes:    1777
 * Dislikes: 113
 * Total Accepted:    162.4K
 * Total Submissions: 395.4K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5.Â 
 *
 * Example:
 *
 *
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 *
 * Note: Â 
 *
 *
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 *
 */

// @lc code=start


class Ugly {
public:
	/*
	 * Time complexity: O(n)
	 * set counters for each factor,
	 * and increase the counter for generating the minimum one
	 */
	Ugly() {
		size_t size = 1690;
		uglyNumbers.reserve(size);
		uglyNumbers.emplace_back(1);
		
		int idx2 = 0, idx3 = 0, idx5 = 0;
		for (int i = 1; i < size; ++i) {
			int factor2 = uglyNumbers[idx2] * 2;
			int factor3 = uglyNumbers[idx3] * 3;
			int factor5 = uglyNumbers[idx5] * 5;
			int minUgly = min({factor2, factor3, factor5});
			uglyNumbers.emplace_back(minUgly);
			
			if (factor2 == minUgly) { idx2++; }
			if (factor3 == minUgly) { idx3++; }
			if (factor5 == minUgly) { idx5++; }
		}
	}
	
	int nthUglyNumber(int n) {
		return uglyNumbers[n - 1];
	}

private:
	vector<int> uglyNumbers;
};

static Ugly ugly;

class Solution {
public:
	int nthUglyNumber(int n) {
		return ugly.nthUglyNumber(n);
	}
};
// @lc code=end

int main() {
	Solution solution;
	PrintSingleResult(solution.nthUglyNumber(10));
	
	Complete();
}
