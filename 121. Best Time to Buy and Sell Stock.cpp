#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * 121. Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 *
 * If you were only permitted to complete at most one transaction (i.e., buy
 * one and sell one share of the stock), design an algorithm to find the
 * maximum profit.
 *
 * Note that you cannot sell a stock before you buy one.
 *
 * Example 1:
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Not 7-1 = 6, as selling price needs to be larger than buying price.
 *
 *
 * Example 2:
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 */


class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * Space complexity: O(1)
	 * memorize both min_price and max_profit
	 * 解法就是贪心的思想，就是寻找价格差最大的两天之间的收益。
	 */
	int maxProfit(vector<int> &prices) {
		if (prices.empty()) {
			return 0;
		}
		int maxProfit = 0;
		int minPrice = prices.front();
		for (int price: prices) {
			maxProfit = max(maxProfit, price - minPrice);
			minPrice = min(minPrice, price);
		}
		
		return maxProfit;
	}
}