//
// Created by Yuyang Huang on 10/6/21.
//

/*
 * 309. Best Time to Buy and Sell Stock with Cooldown
 * Medium, but is hard indeed
 *
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * Find the maximum profit you can achieve. You may complete as many transactions as you like
 * (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
 *
 * After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
 * Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 *
 * Example 1:
 * Input: prices = [1,2,3,0,2]
 * Output: 3
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 *
 * Example 2:
 * Input: prices = [1]
 * Output: 0
 *
 * Constraints:
 * 1 <= prices.length <= 5000
 * 0 <= prices[i] <= 1000
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * use state machine
	 * reset -> reset, reset-> held
	 * held -> held, held -> sold
	 * sold -> reset
	 */
	int maxProfit(vector<int> &prices) {
		if (prices.size() <= 1) return 0;
		vector<int> reset(prices.size(), 0);
		vector<int> held(prices.size(), 0);
		vector<int> sold(prices.size(), 0);
		
		held[0] = -prices[0];
		reset[0] = 0;
		sold[0] = INT_MIN;
		
		for (int i = 1; i < prices.size(); i++) {
			reset[i] = max(reset[i - 1], sold[i - 1]);
			held[i] = max(held[i - 1], reset[i - 1] - prices[i]);
			sold[i] = held[i - 1] + prices[i];
		}
		return max(reset[prices.size() - 1], sold[prices.size() - 1]);
	}
};

int main() {
	Solution solution;
	vector<int> prices;
	prices = {1, 2, 3, 0, 2};
	PrintSingleResult(solution.maxProfit(prices));
	prices = {0, 1};
	PrintSingleResult(solution.maxProfit(prices));
}