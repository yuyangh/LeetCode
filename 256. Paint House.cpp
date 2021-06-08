//
// Created by Yuyang Huang on 6/7/21.
//

/*
 * 256. Paint House
 * Medium
 *
 * There is a row of n houses, where each house can be painted
 * one of three colors: red, blue, or green.
 * The cost of painting each house with a certain color is different.
 * You have to paint all the houses such that no two adjacent houses
 * have the same color.
 *
 * The cost of painting each house with a certain color is represented
 * by an n x 3 cost matrix costs.
 *
 * For example, costs[0][0] is the cost of painting house 0 with the color red;
 * costs[1][2] is the cost of painting house 1 with color green, and so on...
 *
 * Return the minimum cost to paint all houses.
 *
 * Example 1:
 * Input: costs = [[17,2,17],[16,16,5],[14,3,19]]
 * Output: 10
 * Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
 * Minimum cost: 2 + 5 + 3 = 10.
 *
 * Example 2:
 * Input: costs = [[7,6,2]]
 * Output: 2
 *
 * Constraints:
 * costs.length == n
 * costs[i].length == 3
 * 1 <= n <= 100
 * 1 <= costs[i][j] <= 20
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(n), time complexity: O(n)
	 * use dynamic programming to memorize previous total cost
	 * can do space optimization to save more space
	 */
	int minCost(vector<vector<int>> &costs) {
		if (costs.empty()) {
			return 0;
		}
		vector<vector<int>> totalCosts(costs);
		for (int row = 1; row < totalCosts.size(); row++) {
			for (int color = 0; color < 3; color++) {
				switch (color) {
					case 0: {
						totalCosts[row][color] += min(totalCosts[row - 1][color + 1],
						                              totalCosts[row - 1][color + 2]);
						break;
					};
					case 1: {
						totalCosts[row][color] += min(totalCosts[row - 1][color - 1],
						                              totalCosts[row - 1][color + 1]);
						break;
					};
					case 2: {
						totalCosts[row][color] += min(totalCosts[row - 1][color - 2],
						                              totalCosts[row - 1][color - 1]);
						break;
					};
					default: {
						cerr << "Warning: out of range" << endl;
					}
				}
			}
		}
		return *min_element(totalCosts.back().begin(), totalCosts.back().end());
	}
};

int main() {
	Solution solution;
	vector<vector<int>> costs = {{17, 2,  17},
	                             {16, 16, 5},
	                             {14, 3,  19}};
	PrintSingleResult(solution.minCost(costs));
	
	Complete();
}