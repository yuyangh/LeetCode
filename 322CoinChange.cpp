#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (30.31%)
 * Likes:    1747
 * Dislikes: 76
 * Total Accepted:    197.3K
 * Total Submissions: 648.1K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 *
 * Example 1:
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 *
 * Example 2:
 * Input: coins = [2], amount = 3
 * Output: -1
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 *
 */
class Solution {
public:
	int coinChange(vector<int> &coins, int amount) {
		if (coins.empty()) {
			return -1;
		}
		
		// check from target to zero
		vector<int> data(amount + 1, INT_MAX / 2);
		data[amount] = 0;
		for (int i = amount; i >= 0; i--) {
			for (int coin:coins) {
				if (i - coin < 0) {
					continue;
				}
				data[i - coin] = min(data[i] + 1, data[i - coin]);
			}
		}
		if (data[0] == INT_MAX / 2) {
			return -1;
		} else {
			return data[0];
		}
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

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> coins = stringToIntegerVector(line);
		getline(cin, line);
		int amount = stringToInteger(line);
		
		int ret = Solution().coinChange(coins, amount);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}