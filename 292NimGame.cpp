#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=292 lang=cpp
 *
 * [292] Nim Game
 *
 * https://leetcode.com/problems/nim-game/description/
 *
 * algorithms
 * Easy (55.72%)
 * Likes:    386
 * Dislikes: 1178
 * Total Accepted:    187.4K
 * Total Submissions: 336.3K
 * Testcase Example:  '4'
 *
 * You are playing the following Nim Game with your friend: There is a heap of
 * stones on the table, each time one of you take turns to remove 1 to 3
 * stones. The one who removes the last stone will be the winner. You will take
 * the first turn to remove the stones.
 *
 * Both of you are very clever and have optimal strategies for the game. Write
 * a function to determine whether you can win the game given the number of
 * stones in the heap.
 *
 * Example:
 * Input: 4
 * Output: false
 * Explanation: If there are 4 stones in the heap, then you will never win the
 * game;
 * No matter 1, 2, or 3 stones you remove, the last stone will always
 * be
 * removed by your friend.
 */
class Solution {
public:
	bool canWinNim(int n) {
		/*
		 * because one cannot take more than 3,
		 * so n%4!=0 ensure one is the last
		 */
		return n % 4 != 0;
	}
};


int stringToInteger(string input) {
	return stoi(input);
}

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
		int n = stringToInteger(line);
		
		bool ret = Solution().canWinNim(n);
		
		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}

