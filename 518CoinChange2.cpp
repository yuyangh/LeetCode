//
// Created by Yuyang Huang on 6/7/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 *
 * https://leetcode.com/problems/coin-change-2/description/
 *
 * algorithms
 * Medium (44.67%)
 * Likes:    1686
 * Dislikes: 58
 * Total Accepted:    106.3K
 * Total Submissions: 218.6K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * You are given coins of different denominations and a total amount of money.
 * Write a function to compute the number of combinations that make up that
 * amount. You may assume that you have infinite number of each kind of
 * coin.
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: amount = 5, coins = [1, 2, 5]
 * Output: 4
 * Explanation: there are four ways to make up the amount:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 *
 *
 * Example 2:
 *
 *
 * Input: amount = 3, coins = [2]
 * Output: 0
 * Explanation: the amount of 3 cannot be made up just with coins of 2.
 *
 *
 * Example 3:
 *
 *
 * Input: amount = 10, coins = [10]
 * Output: 1
 *
 *
 *
 *
 * Note:
 *
 * You can assume that
 *
 *
 * 0 <= amount <= 5000
 * 1 <= coin <= 5000
 * the number of coins is less than 500
 * the answer is guaranteed to fit into signed 32-bit integer
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(mn)
 * dp is converted from recursion, because recursion starts from beginning to recurse back
 * so iteration starts from beginning
 */
class Solution {
public:
	int change(int amount, vector<int> &coins) {
		// int result = 0;
		vector<int> accumulation(amount + 1);
		accumulation[0] = 1;
		for (int coin: coins) {
			for (int value = coin; value <= amount; value++) {
				accumulation[value] += accumulation[value - coin];
			}
		}
		// helper(result, amount, coins, 0);
		return accumulation[amount];
	}

private:
	/*
	 * recursion
	 */
	void helper(int &result, int remain, vector<int> &coins, int coinIndex) {
		// base case
		if (remain < 0) {
			return;
		}
		if (remain == 0) {
			result++;
			return;
		}
		
		// iterate each coin
		for (int i = coinIndex; i < coins.size(); ++i) {
			helper(result, remain - coins[i], coins, i);
		}
	}
};
// @lc code=end

int main() {
	Solution solution;
	int amount;
	vector<int> coins;
	
	amount = 5;
	coins = {1, 2, 5};
	PrintSingleResult(solution.change(amount, coins));
	
	Complete();
}
