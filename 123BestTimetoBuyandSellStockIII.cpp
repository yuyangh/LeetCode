#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (33.77%)
 * Likes:    1181
 * Dislikes: 56
 * Total Accepted:    155.9K
 * Total Submissions: 456.7K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 *
 * Note: You may not engage in multiple transactions at the same time (i.e.,
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
 *
 *
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *
 */
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int total_profit = 0;
		int max_profit = 0;
		int min_price = INT_MAX;
		vector<int> profits;
		profits.reserve(prices.size());
		
		for (int price : prices) {
			// update min_price and update profit
			if (price < min_price) {
				profits.emplace_back(max_profit);
				max_profit = 0;
				min_price = price;
			} else {
				int profit = price - min_price;
				// based on profit to decide to keep or sell
				if (profit > max_profit) {
					max_profit = profit;
				} else {
					profits.emplace_back(max_profit);
					max_profit = 0;
					min_price = price;
				}
			}
		}
		profits.emplace_back(max_profit);
		
		int largest=0,larger=0;
		for (const auto &profit : profits) {
			if(profit>=largest){
				larger=largest;
				largest=profit;
			}else{
				if(profit>larger){
					larger=profit;
				}
			}
		}
		return larger+largest;
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