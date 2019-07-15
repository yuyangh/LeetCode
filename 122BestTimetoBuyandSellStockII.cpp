#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 *
 * algorithms
 * Easy (52.04%)
 * Likes:    1104
 * Dislikes: 1334
 * Total Accepted:    343K
 * Total Submissions: 654.5K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (i.e., buy one and sell one share of the stock
 * multiple times).
 *
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 *
 * Example 1:
 *
 *
 * Input: [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit
 * = 5-1 = 4.
 * Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 =
 * 3.
 *
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
 *
 *
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *
 */
class Solution {
public:
	// based on reference, it is a monotone increase
	int maxProfit(vector<int> &prices) {
		int ret = 0;
		for (size_t i = 1; i < prices.size(); ++i){
			// either sell or purchase
			ret += max(prices[i] - prices[i - 1], 0);
		}
		return ret;
	}
	
	// compare with the min_price and do the update,
	// same runtime, but a little bit complex
	int maxProfitOrginal(vector<int> &prices) {
		int total_profit = 0;
		int max_profit = 0;
		int min_price = INT_MAX;
		
		for (int price : prices) {
			// update min_price and update profit
			if (price < min_price) {
				total_profit += max_profit;
				max_profit = 0;
				min_price = price;
			} else {
				int profit = price - min_price;
				// based on profit to decide to keep or sell
				if (profit > max_profit) {
					max_profit = profit;
				} else {
					total_profit += max_profit;
					max_profit = 0;
					min_price = price;
				}
			}
		}
		total_profit += max_profit;
		return total_profit;
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
