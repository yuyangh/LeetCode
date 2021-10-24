//
// Created by Yuyang Huang on 10/24/21.
//

/*
 * 797. All Paths From Source to Target
 * Medium
 * Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1,
 * find all possible paths from node 0 to node n - 1 and return them in any order.
 * The graph is given as follows: graph[i] is a list of all nodes you can visit from node i
 * (i.e., there is a directed edge from node i to node graph[i][j]).
 *
 * Example 1:
 * Input: graph = [[1,2],[3],[3],[]]
 * Output: [[0,1,3],[0,2,3]]
 * Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
 *
 * Example 2:
 * Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
 * Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 *
 * Example 3:
 * Input: graph = [[1],[]]
 * Output: [[0,1]]
 *
 * Example 4:

Input: graph = [[1,2,3],[2],[3],[]]
Output: [[0,1,2,3],[0,2,3],[0,3]]
Example 5:

Input: graph = [[1,3],[2],[3],[]]
Output: [[0,1,2,3],[0,3]]


Constraints:

n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n
graph[i][j] != i (i.e., there will be no self-loops).
All the elements of graph[i] are unique.
The input graph is guaranteed to be a DAG.
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * DFS all path
	 */
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		if(graph.empty()){
			return {};
		}
	    vector<vector<int>> ans;
	    vector<int> path;
		helper(graph,ans,path,0);
		return ans;
    }

private:
	void helper(vector<vector<int>>& graph, vector<vector<int>> &ans,vector<int>& path,int node){
		int target=graph.size()-1;
		if(target==node){
			path.emplace_back(node);
			ans.emplace_back(path);
			path.pop_back();
			return;
		}
		
		path.emplace_back(node);
		vector<int> nextNodes=graph[node];
		for(auto nextNode:nextNodes){
			helper(graph,ans,path,nextNode);
		}
		path.pop_back();
	}
};