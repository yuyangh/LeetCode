//
// Created by Yuyang Huang on 6/28/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 *
 * https://leetcode.com/problems/reconstruct-itinerary/description/
 *
 * algorithms
 * Medium (33.03%)
 * Testcase Example:  '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * Given a list of airline tickets represented by pairs of departure and
 * arrival airports [from, to], reconstruct the itinerary in order. All of the
 * tickets belong to a man who departs from JFK. Thus, the itinerary must begin
 * with JFK.
 *
 * Note:
 * If there are multiple valid itineraries, you should return the itinerary
 * that has the smallest lexical order when read as a single string. For
 * example, the itinerary ["JFK", "LGA"] has a smaller lexical order than
 * ["JFK", "LGB"].
 * All airports are represented by three capital letters (IATA code).
 * You may assume all tickets form at least one valid itinerary.
 * One must use all the tickets once and only once.
 *
 *
 * Example 1:
 * Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 * Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
 *
 *
 * Example 2:
 * Input:
 * [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
 * Explanation: Another possible reconstruction is
 * ["JFK","SFO","ATL","JFK","ATL","SFO"].
 * But it is larger in lexical order.
 */

// @lc code=start
/*
 * Explanation:
 * First keep going forward until you get stuck. That's a good main path already.
 * Remaining tickets form cycles which are found on the way back and get merged into that main path.
 * By writing down the path backwards when retreating from recursion,
 * merging the cycles into the main path is easy - the end part of the path has already been written,
 * the start part of the path hasn't been written yet,
 * so just write down the cycle now and then keep backwards-writing the path.
 * link: https://leetcode.com/problems/reconstruct-itinerary/discuss/78768/Short-Ruby-Python-Java-C%2B%2B
 */
class Solution {
public:
	/*
	 * Eulerian path algorithm
	 * Time complexity: ( E log E)
	 */
	vector<string> findItinerary(vector<vector<string>> &tickets) {
		unordered_map<string, multiset<string>> flightMap;
		vector<string> routes;
		
		for (const auto &ticket : tickets) {
			flightMap[ticket[0]].emplace(ticket[1]);
		}
		string depart = "JFK";
		visit(flightMap, routes, depart);
		
		reverse(routes.begin(), routes.end());
		return routes;
	}

private:
	void visit(unordered_map<string, multiset<string>> &flightMap, vector<string> &routes, string &airport) {
		while (!flightMap[airport].empty()) {
			string nextAirport = *flightMap[airport].begin();
			flightMap[airport].erase(flightMap[airport].begin());
			visit(flightMap, routes, nextAirport);
		}
		routes.emplace_back(airport);
	}
};
// @lc code=end

int main() {
	Solution solution;
	vector<vector<string>> tickets;
	
	tickets = {{"MUC", "LHR"},
	           {"JFK", "MUC"},
	           {"SFO", "SJC"},
	           {"LHR", "SFO"}};
	PrintVector(solution.findItinerary(tickets));
	
	tickets = {{"JFK", "SFO"},
	           {"JFK", "ATL"},
	           {"SFO", "ATL"},
	           {"ATL", "JFK"},
	           {"ATL", "SFO"}};
	PrintVector(solution.findItinerary(tickets));
	
	Complete();
}