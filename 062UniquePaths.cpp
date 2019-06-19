#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (47.74%)
 * Likes:    1604
 * Dislikes: 111
 * Total Accepted:    294.9K
 * Total Submissions: 616.4K
 * Testcase Example:  '3\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * How many possible unique paths are there?
 *
 *
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 *
 * Example 1:
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 *
 *
 * Example 2:
 * Input: m = 7, n = 3
 * Output: 28
 */
class Solution {
public:
	vector<vector<int>> path;
	int uniquePaths(int m, int n) {
		if(m==0||n==0){
			return 0;
		}
		
		path.reserve(n);
		for(int row=0;row<n;row++){
			path.emplace_back(m,0);
		}
		
		// dynamic programming
		path[0][0]=1;
		for(int col=1;col<m;col++){
			path[0][col]=1;
		}
		for(int row=1;row<n;row++){
			path[row][0]=1;
		}
		for(int row=1;row<n;row++){
			for(int col=1;col<m;col++){
				path[row][col]=path[row-1][col]+path[row][col-1];
			}
		}
		return path[n-1][m-1];
	}
};


int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int m = stringToInteger(line);
		getline(cin, line);
		int n = stringToInteger(line);
		
		int ret = Solution().uniquePaths(m, n);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}