#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (44.13%)
 * Likes:    2181
 * Dislikes: 80
 * Total Accepted:    406.1K
 * Total Submissions: 918.7K
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 * Note: Given n will be a positive integer.
 *
 * Example 1:
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 *
 *
 * Example 2:
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 */
class Solution {
public:
	int climbStairs(int n) {
		vector<int> count;
		count.reserve(n);
		count.emplace_back(0);
		count.emplace_back(1);
		count.emplace_back(2);
		// every step is the sum of previous two steps
		for (int i = 3; i <= n; i++) {
			count.emplace_back(count[i - 1] + count[i - 2]);
		}
		return count[n];
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int n = stringToInteger(line);
		
		int ret = Solution().climbStairs(n);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}
