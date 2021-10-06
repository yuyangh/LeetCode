//
// Created by Yuyang Huang on 10/6/21.
//

/*
 * 188. Best Time to Buy and Sell Stock IV
 * Hard
 *
 * You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
 * Find the maximum profit you can achieve. You may complete at most k transactions.
 * Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 *
 * Example 1:
 * Input: k = 2, prices = [2,4,1]
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
 *
 * Example 2:
 * Input: k = 2, prices = [3,2,6,5,0,3]
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
 * Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 *
 * Constraints:
 * 0 <= k <= 100
 * 0 <= prices.length <= 1000
 * 0 <= prices[i] <= 1000
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(kn)
	 * dp[i, j] represents the max profit up until prices[j] using at most i transactions.
	 * dp[i, j] = max(dp[i, j-1], prices[j] - prices[jj] + dp[i-1, jj]) { jj in range of [0, j-1] }
	 *          = max(dp[i, j-1], prices[j] + max(dp[i-1, jj] - prices[jj]))
	 * dp[0, j] = 0; 0 transactions makes 0 profit
	 * dp[i, 0] = 0; if there is only one price data point you can't make any transaction.
	 * */
	int maxProfit(int k, vector<int> &prices) {
		int n = prices.size();
		if (n <= 1) {
			return 0;
		}
		
		//if k >= n/2, then you can make maximum number of transactions.
		if (k >= n / 2) {
			int maxPro = 0;
			for (int i = 1; i < n; i++) {
				if (prices[i] > prices[i - 1])
					maxPro += prices[i] - prices[i - 1];
			}
			return maxPro;
		}
		
		vector<vector<int>> dp(k + 1, vector<int>(n));
		for (int transaction = 1; transaction <= k; transaction++) {
			// local max is the memorization for:
			// max(prices[j] - prices[i] + dp[i-1][j-1]), for i=[0..j] (The best buying day from i-1 transactions).
			int localMax = dp[transaction - 1][0] - prices[0];
			for (int day = 1; day < n; day++) {
				// max (best so far, transact on day j)
				dp[transaction][day] = max(dp[transaction][day - 1], prices[day] + localMax);
				localMax = max(localMax, dp[transaction - 1][day] - prices[day]);
			}
		}
		return dp[k][n - 1];
	}
};

int main() {
	Solution solution;
	int k;
	vector<int> prices;
	k = 2, prices = {2, 4, 1};
	PrintSingleResult(solution.maxProfit(k, prices));
	
	k = 2, prices = {3, 2, 6, 5, 0, 3};
	PrintSingleResult(solution.maxProfit(k, prices));
	
	
}