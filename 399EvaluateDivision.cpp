//
// Created by Yuyang Huang on 5/31/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (49.09%)
 * Likes:    2076
 * Dislikes: 159
 * Total Accepted:    121.6K
 * Total Submissions: 239.8K
 * Testcase Example:  '[["a","b"],["b","c"]]\n[2.0,3.0]\n' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * Equations are given in the format A / B = k, where A and B are variables
 * represented as strings, and k is a real number (floating point number).
 * Given some queries, return the answers. If the answer does not exist, return
 * -1.0.
 *
 * Example:
 * Given  a / b = 2.0, b / c = 3.0.
 * queries are:  a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
 * return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 *
 * The input is:  vector<pair<string, string>> equations, vector<double>&
 * values, vector<pair<string, string>> queries , where equations.size() ==
 * values.size(), and the values are positive. This represents the equations.
 * Return  vector<double>.
 *
 * According to the example above:
 *
 *
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]
 * ].
 *
 *
 *
 * The input is always valid. You may assume that evaluating the queries will
 * result in no division by zero and there is no contradiction.
 *
 */

// @lc code=start

/*
 * Time complexity: O(n), deem UnionFind as constant
 */
class Solution {
public:
	vector<double> calcEquation(vector<vector<string>> &equations,
	                            vector<double> &values, vector<vector<string>> &queries) {
		unordered_map<string, UnionFindNode *> nodes;
		vector<double> result;
		for (int i = 0; i < equations.size(); ++i) {
			auto s1 = equations[i][0], s2 = equations[i][1];
			int node1Exist = nodes.count(s1), node2Exist = nodes.count(s2);
			if (node1Exist == 0 && node2Exist == 0) {
				nodes[s1] = new UnionFindNode(values[i]);
				nodes[s2] = new UnionFindNode(1.0);
				nodes[s1]->parent = nodes[s2];
			} else if (node1Exist == 0) {
				nodes[s1] = new UnionFindNode(nodes[s2]->value * values[i]);
				nodes[s1]->parent = nodes[s2];
			} else if (node2Exist == 0) {
				nodes[s2] = new UnionFindNode(nodes[s1]->value / values[i]);
				nodes[s2]->parent = nodes[s1];
			} else {
				nodes[s1]->Union(nodes[s2], values[i], nodes);
			}
		}
		
		for (const auto &query : queries) {
			// first check node existence
			if (nodes.count(query[0]) == 0 || nodes.count(query[1]) == 0
			    || nodes[query[0]]->findParent() != nodes[query[1]]->findParent()) {
				result.emplace_back(-1);
			} else {
				result.emplace_back(nodes[query[0]]->value / nodes[query[1]]->value);
			}
		}
		return result;
	}

private:
	struct UnionFindNode {
		double value;
		UnionFindNode *parent;
		
		explicit UnionFindNode(double val) : value(val), parent(this) {};
		
		explicit UnionFindNode() : value(1.0), parent(this) {};
		
		void Union(UnionFindNode *node, double num, unordered_map<string, UnionFindNode *> &nodes) {
			UnionFindNode *selfParent = this->findParent();
			auto nodeParent = node->findParent();
			// keep associated nodes with same value
			double ratio = node->value * num / this->value;
			for (auto &item : nodes) {
				if (item.second->findParent() == selfParent) {
					item.second->value *= ratio;
				}
			}
			selfParent->parent = nodeParent;
		}
		
		UnionFindNode *findParent() {
			if (this->parent == this) {
				return this;
			}
			this->parent = this->parent->findParent();
			return this->parent;
		}
	};
};
// @lc code=end

int main() {
	vector<vector<string>> equations = {{"a", "b"},
	                                    {"b", "c"}};
	vector<double> values = {2.0, 3.0};
	vector<vector<string>> queries = {{"a", "c"},
	                                  {"b", "a"},
	                                  {"a", "e"},
	                                  {"a", "a"},
	                                  {"x", "x"}};
	Solution solution;
	auto result = solution.calcEquation(equations, values, queries);
	PrintVector(result);
}