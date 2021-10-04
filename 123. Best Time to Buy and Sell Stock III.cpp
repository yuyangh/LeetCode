#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * 123. Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard 
 * 
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 *
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 *
 * Example 1:
 *
 *
 * Input: [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit
 * = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 =
 * 3.
 *
 * Example 2:
 *
 *
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are
 * engaging multiple transactions at the same time. You must sell before buying
 * again.
 *
 *
 * Example 3:
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *
 */
class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * 最多两次买卖
	 * 解法是一次买卖的followup，将输入一分为二，left and right. 左右两边分别找最大值。
	 */
	int maxProfit(vector<int> &prices) {
		if (prices.empty()) {
			return 0;
		}
		
		int n = prices.size();
		vector<int> maxLeftProfit(n);
		vector<int> maxRightProfit(n);
		
		int minPrice = prices[0];
		for (int i = 1; i < n; i++) {
			maxLeftProfit[i] = max(maxLeftProfit[i - 1], prices[i] - minPrice);
			minPrice = min(minPrice, prices[i]);
		}
		
		int maxPrice = prices[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			maxRightProfit[i] = max(maxRightProfit[i + 1], maxPrice - prices[i]);
			maxPrice = max(maxPrice, prices[i]);
		}
		
		int maxProfit = 0;
		for (int i = 0; i < n; i++) {
			maxProfit = max(maxProfit, maxLeftProfit[i] + maxRightProfit[i]);
		}
		return maxProfit;
	}
};


void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> prices = stringToIntegerVector(line);
		
		int ret = Solution().maxProfit(prices);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}