//
// Created by Yuyang Huang on 5/30/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (40.45%)
 * Likes:    1081
 * Dislikes: 18
 * Total Accepted:    93.5K
 * Total Submissions: 230.8K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an integer matrix, find the length of the longest increasing path.
 *
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 *
 * Example 1:
 *
 *
 * Input: nums =
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 *
 *
 * Example 2:
 *
 *
 * Input: nums =
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(V+E)=O(mn)
 * use topological sort
 */
class Solution {
public:
	int longestIncreasingPath(vector<vector<int>> &matrix) {
		if(matrix.empty()){
			return 0;
		}
		
		// from -> to, values are spots larger than self
		vector<vector<int>> adjList(matrix.size() * matrix[0].size());
		vector<int> prerequisites(matrix.size() * matrix[0].size(), 0);
		// number of steps to the spot
		vector<int> spotNumStep(matrix.size() * matrix[0].size(), 1);
		addSurroundingPrerequisite(matrix, adjList, prerequisites);
		
		queue<int> bag;
		for (int spotIndex = 0; spotIndex < prerequisites.size(); ++spotIndex) {
			if (prerequisites[spotIndex] == 0) {
				bag.emplace(spotIndex);
			}
		}
		
		// topological sort
		while (!bag.empty()) {
			int fromIndex = bag.front();
			bag.pop();
			for (const auto &toIndex : adjList[fromIndex]) {
				spotNumStep[toIndex] = max(spotNumStep[fromIndex] + 1, spotNumStep[toIndex]);
				prerequisites[toIndex]--;
				if (prerequisites[toIndex] == 0) {
					bag.emplace(toIndex);
				}
			}
		}
		
		return *std::max_element(spotNumStep.begin(), spotNumStep.end());
	}

private:
	void addSurroundingPrerequisite(vector<vector<int>> &matrix,
	                                vector<vector<int>> &adjList, vector<int> &prerequisites) {
		for (int row = 0; row < matrix.size(); ++row) {
			for (int col = 0; col < matrix[0].size(); ++col) {
				int value = matrix[row][col];
				int from = getSpotIndex(matrix, row, col);
				int to;
				// up
				if (row - 1 >= 0 && value < matrix[row - 1][col]) {
					to = getSpotIndex(matrix, row - 1, col);
					adjList[from].emplace_back(to);
					prerequisites[to]++;
				}
				// left
				if (col - 1 >= 0 && value < matrix[row][col - 1]) {
					to = getSpotIndex(matrix, row, col - 1);
					adjList[from].emplace_back(to);
					prerequisites[to]++;
				}
				// right
				if (col + 1 < matrix[0].size() && value < matrix[row][col + 1]) {
					to = getSpotIndex(matrix, row, col + 1);
					adjList[from].emplace_back(to);
					prerequisites[to]++;
				}
				// down
				if (row + 1 < matrix.size() && value < matrix[row + 1][col]) {
					to = getSpotIndex(matrix, row + 1, col);
					adjList[from].emplace_back(to);
					prerequisites[to]++;
				}
			}
		}
	}
	
	int getSpotIndex(vector<vector<int>> &matrix, int row, int col) {
		return row * matrix[0].size() + col;
	}
};
// @lc code=end

int main() {
	Solution solution;
	vector<vector<int>> nums = {
			{9, 9, 4},
			{6, 6, 8},
			{2, 1, 1}
	};
	assert(solution.longestIncreasingPath(nums) == 4);
	
	nums = {
			{3, 4, 5},
			{3, 2, 6},
			{2, 2, 1}
	};
	assert(solution.longestIncreasingPath(nums) == 4);
	
	nums={{0},{1},{5},{5}};
	PrintSingleResult(solution.longestIncreasingPath(nums));
	Complete();
}