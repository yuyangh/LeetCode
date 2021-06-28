//
// Created by Yuyang Huang on 6/27/21.
//

/*
 * 684. Redundant Connection
 * Medium
 *
 * In this problem, a tree is an undirected graph that is connected and has no cycles.
 * You are given a graph that started as a tree with n nodes labeled from 1 to n,
 * with one additional edge added. The added edge has two different vertices chosen from 1 to n,
 * and was not an edge that already existed.
 *
 * The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that
 * there is an edge between nodes ai and bi in the graph.
 *
 * Return an edge that can be removed so that the resulting graph is a tree of n nodes.
 * If there are multiple answers, return the answer that occurs last in the input.
 *
 * Example 1:
 * Input: edges = [[1,2],[1,3],[2,3]]
 * Output: [2,3]
 *
 * Example 2:
 * Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
 * Output: [1,4]
 *
 * Constraints:
 * n == edges.length
 * 3 <= n <= 1000
 * edges[i].length == 2
 * 1 <= ai < bi <= edges.length
 * ai != bi
 * There are no repeated edges.
 * The given graph is connected.
 */

#include "LeetCodeLib.h"

class UnionFind {
public:
	void unionSons(int a, int b) {
		if (findParent(a) == findParent(b)) {
			return;
		} else {
			parent[findParent(a)] = findParent(b);
		}
	}
	
	int findParent(int son) {
		if (parent.find(son) == parent.end()) {
			parent[son] = son;
			return son;
		}
		if (parent[son] == son) {
			return son;
		}
		
		parent[son] = findParent(parent[son]);
		return parent[son];
	}

private:
	unordered_map<int, int> parent;
};

/*
 * use Union find to check cycle
 */
class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>> &edges) {
		UnionFind unionFind;
		for (const auto &edge : edges) {
			int start = edge[0], end = edge[1];
			if (unionFind.findParent(start) == unionFind.findParent(end)) {
				return edge;
			} else {
				unionFind.unionSons(start, end);
			}
		}
		return edges.back();
	}
};

int main() {
	Solution solution;
	
	vector<vector<int>> edges;
	edges = {{1, 2},
	         {1, 3},
	         {2, 3}};
	PrintVector(solution.findRedundantConnection(edges));
	
	edges = {{1, 2},
	         {2, 3},
	         {3, 4},
	         {1, 4},
	         {1, 5}};
	PrintVector(solution.findRedundantConnection(edges));
	
	Complete();
	
	
}