#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (47.34%)
 * Likes:    2794
 * Dislikes: 132
 * Total Accepted:    531.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[7,1,5,3,6,4]'
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
 *
 *
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Not 7-1 = 6, as selling price needs to be larger than buying price.
 *
 *
 * Example 2:
 *
 *
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *
 *
 */
class Solution {
public:
	// O(n) runtime, O(1) space
	int maxProfit(vector<int> &prices) {
		int max_profit = 0;
		int min_price = INT_MAX;
		for (int price : prices) {
			// compare the price and profit
			if (price < min_price) {
				min_price = price;
			} else {
				int profit = price - min_price;
				if (profit > max_profit) {
					max_profit = profit;
				}
			}
		}
		return max_profit;
	}
	
	// O(n) runtime, O(n) space
	int maxProfitSlow(vector<int> &prices) {
		if (prices.empty()) {
			return 0;
		}
		
		vector<int> min_price(prices.size(), prices[0]);
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] < min_price[i - 1]) {
				min_price[i] = prices[i];
			} else {
				min_price[i] = min_price[i - 1];
			}
		}
		
		vector<int> max_price(prices.size(), prices.back());
		for (int i = static_cast<int>(prices.size()) - 2; i >= 0; --i) {
			if (prices[i] > max_price[i + 1]) {
				max_price[i] = prices[i];
			} else {
				max_price[i] = max_price[i + 1];
			}
		}
		
		int max_profit = 0;
		for (int i = 0; i < prices.size(); ++i) {
			int profit = max_price[i] - min_price[i];
			if (profit > max_profit) {
				max_profit = profit;
			}
		}
		return max_profit;
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