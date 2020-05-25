//
// Created by Yuyang Huang on 5/25/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 *
 * https://leetcode.com/problems/uncrossed-lines/description/
 *
 * algorithms
 * Medium (52.62%)
 * Likes:    671
 * Dislikes: 13
 * Total Accepted:    31.7K
 * Total Submissions: 57K
 * Testcase Example:  '[1,4,2]\n[1,2,4]'
 *
 * We write the integers of A and BÂ (in the order they are given) on two
 * separate horizontal lines.
 *
 * Now, we may draw connecting lines: a straight line connecting two numbers
 * A[i] and B[j]Â such that:
 *
 *
 * A[i] == B[j];
 * The line we draw does not intersect any other connecting (non-horizontal)
 * line.
 *
 *
 * Note that a connecting lines cannot intersect even at the endpoints:Â each
 * number can only belong to one connecting line.
 *
 * Return the maximum number of connecting lines we can draw in this way.
 *
 * Example 1:
 * Input: A = [1,4,2], B = [1,2,4]
 * Output: 2
 * Explanation: We can draw 2 uncrossed lines as in the diagram.
 * We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4
 * will intersect the line from A[2]=2 to B[1]=2.
 *
 * Example 2:
 * Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
 * Output: 3
 *
 * Example 3:
 * Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
 * Output: 2
 *
 * Note:
 * 1 <= A.length <= 500
 * 1 <= B.length <= 500
 * 1 <= A[i], B[i] <= 2000
 *
 *
 */

// @lc code=start
class Solution {
public:
	/*
	 * time complexity: O(mn)
	 * space complexity: O(n)
	 * because each row only relies on previous row,
	 * so we can use two rows with mod operation to do memorization
	 *      A: a1 a2 a3
	 * odd
	 * even
	 * row corresponds to B%2,
	 * col corresponds to A
	 */
	int maxUncrossedLines(vector<int> &A, vector<int> &B) {
		vector<vector<unsigned int>> dp(2, vector<unsigned int>(A.size() + 1, 0));
		int row;
		for (row = 1; row < 1 + B.size(); ++row) {
			for (int col = 1; col < 1 + A.size(); ++col) {
				if (A[col - 1] == B[(row - 1)]) {
					dp[row % 2][col] = max({
							                       dp[(row - 1) % 2][col - 1] + 1,
							                       dp[(row - 1) % 2][col],
							                       dp[(row) % 2][col - 1]});
				} else {
					dp[row % 2][col] = max(dp[(row - 1) % 2][col], dp[row % 2][col - 1]);
				}
			}
		}
		return dp[(row - 1) % 2].back();
	}
	
	/*
	 * time complexity: O(mn)
	 * space complexity: O(mn)
	 *   A: a1 a2 a3
	 * B:
	 * b1
	 * b2
	 * row corresponds to B,
	 * col corresponds to A
	 */
	int maxUncrossedLines_original(vector<int> &A, vector<int> &B) {
		vector<vector<unsigned int>> dp(B.size() + 1, vector<unsigned int>(A.size() + 1, 0));
		for (int row = 1; row < dp.size(); ++row) {
			for (int col = 1; col < dp[0].size(); ++col) {
				if (A[col - 1] == B[row - 1]) {
					dp[row][col] = max({1 + dp[row - 1][col - 1], dp[row - 1][col], dp[row][col - 1]});
				} else {
					dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]);
				}
			}
		}
		return dp.back().back();
	}
};
// @lc code=end

int main() {
	Solution solution;
	vector<int> A = {1, 4, 2}, B = {1, 2, 4};
	assert(solution.maxUncrossedLines(A, B) == 2);
	A = {2, 5, 1, 2, 5}, B = {10, 5, 2, 1, 5, 2};
	assert(solution.maxUncrossedLines(A, B) == 3);
	A = {1, 3, 7, 1, 7, 5}, B = {1, 9, 2, 5, 1};
	assert(solution.maxUncrossedLines(A, B) == 2);
	Complete();
}



