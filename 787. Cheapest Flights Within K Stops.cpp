//
// Created by Yuyang Huang on 6/14/20.
//

# include "LeetCodeLib.h"

/*
 * 787. Cheapest Flights Within K Stops
 *
 * https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
 *
 * algorithms
 * Medium 
 *
 * There are n cities connected by m flights. Each flight starts from city u
 * and arrives at v with a price w.
 *
 * Now given all the cities and flights, together with starting city src and
 * the destination dst, your task is to find the cheapest price from src to dst
 * with up to k stops. If there is no such route, output -1.
 *
 *
 * Example 1:
 * Input:
 * n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
 * src = 0, dst = 2, k = 1
 * Output: 200
 * Explanation:
 * The graph looks like this:
 *
 *
 * The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as
 * marked red in the picture.
 *
 *
 * Example 2:
 * Input:
 * n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
 * src = 0, dst = 2, k = 0
 * Output: 500
 * Explanation:
 * The graph looks like this:
 *
 *
 * The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as
 * marked blue in the picture.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes n will be in range [1, 100], with nodes labeled from 0
 * to n - 1.
 * The size of flights will be in range [0, n * (n - 1) / 2].
 * The format of each flight will be (src, dst, price).
 * The price of each flight will be in the range [1, 10000].
 * k is in the range of [0, n - 1].
 * There will not be any duplicated flights or self cycles.
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(nlogn)
 * dijkskra algorithm with modification,
 * add discovered node to pq as well
 */
class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
		// adj list for {destination, cost}
		vector<vector<vector<int>>> adjList(n);
		
		// pq for {cityIndex, cost, stops}
		auto comp = [](vector<int> &lhs, vector<int> &rhs) {
			return lhs[1] > rhs[1];
		};
		priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
		
		for (const auto &flight: flights) {
			adjList[flight[0]].emplace_back(vector<int>({flight[1], flight[2]}));
		}
		
		pq.push({src, 0, 0});
		while (!pq.empty()) {
			auto city = pq.top();
			pq.pop();
			
			// abandon city that exceeds stops limit
			if (city[2] > K + 1) {
				continue;
			}
			
			// reach destination
			if (city[0] == dst) {
				return city[1];
			}
			
			// add nearby cities to pq
			auto nearbyCities = adjList[city[0]];
			for (const auto &nearbyCity: nearbyCities) {
				pq.emplace(vector<int>({nearbyCity[0],
				                        nearbyCity[1] + city[1],
				                        city[2] + 1}));
			}
		}
		return -1;
	}
};
// @lc code=end

int main() {
	Solution solution;
	int n = 3, src = 0, dst = 2, k = 1;
	vector<vector<int>> edges = {{0, 1, 100},
	                             {1, 2, 100},
	                             {0, 2, 500}};
	
	PrintSingleResult(solution.findCheapestPrice(n, edges, src, dst, k));
	
	PrintSingleResult(solution.findCheapestPrice(n, edges, src, dst, 0));
	
	
	Complete();
	
	
}