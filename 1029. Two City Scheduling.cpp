//
// Created by Yuyang Huang on 6/3/20.
//

#include "LeetCodeLib.h"

/*
 * 1029. Two City Scheduling
 *
 * https://leetcode.com/problems/two-city-scheduling/description/
 *
 * algorithms
 * Easy
 *
 * There are 2N people a company is planning to interview. The cost of flying
 * the i-th person to city A is costs[i][0], and the cost of flying the i-th
 * person to city B is costs[i][1].
 *
 * Return the minimum cost to fly every person to a city such that exactly N
 * people arrive in each city.
 *
 * Example 1:
 * Input: [[10,20],[30,200],[400,50],[30,20]]
 * Output: 110
 * Explanation:
 * The first person goes to city A for a cost of 10.
 * The second person goes to city A for a cost of 30.
 * The third person goes to city B for a cost of 50.
 * The fourth person goes to city B for a cost of 20.
 *
 * The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people
 * interviewing in each city.
 *
 *
 * Note:
 * 1 <= costs.length <= 100
 * It is guaranteed that costs.length is even.
 * 1 <= costs[i][0], costs[i][1] <= 1000
 */

// @lc code=start


class Solution {
public:
	/*
	 * Time complexity: O(nlogn)
	 * greedy approach, sort by the gain of company ascending order
	 * choose the lowest cost one until fill up n cities each
	 */
	int twoCitySchedCost(vector<vector<int>> &costs) {
		// Sort by a gain (positive or neg) which company has by sending a person to city A and not to city B
		sort(costs.begin(), costs.end(), [](vector<int> &lhs, vector<int> &rhs) {
			return lhs[0] - lhs[1] < rhs[0] - rhs[1];
		});
		int sum = 0;
		int limit = costs.size() / 2, cityANum = 0, cityBNum = 0;
		
		// To optimize the company expenses,
		// send the first n persons to the city A
		// and the others to the city B
		for (int i = 0; i < limit; ++i) {
			sum += costs[i][0] + costs[i + limit][1];
		}
		return sum;
	}
};
// @lc code=end

int main() {
	Solution solution;
	vector<vector<int>> costs;
	costs = {{10,  20},
	         {30,  200},
	         {400, 50},
	         {30,  20}};
	PrintSingleResult(solution.twoCitySchedCost(costs));
	assert(solution.twoCitySchedCost(costs) == 110);
	
	costs = {{259, 770},
	         {448, 54},
	         {926, 667},
	         {184, 139},
	         {840, 118},
	         {577, 469}};
	assert(solution.twoCitySchedCost(costs) == 1859);
	Complete();
}
