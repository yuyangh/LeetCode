//
// Created by Yuyang Huang on 6/2/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 *
 * https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
 *
 * algorithms
 * Medium (54.77%)
 * Likes:    894
 * Dislikes: 323
 * Total Accepted:    47.9K
 * Total Submissions: 86.7K
 * Testcase Example:  '[[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]'
 *
 * On a 2D plane, we place stones at some integer coordinate points.Â  Each
 * coordinate point may have at most one stone.
 *
 * Now, a move consists of removing a stoneÂ that shares a column or row with
 * another stone on the grid.
 *
 * What is the largest possible number of moves we can make?
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
 * Output: 5
 *
 *
 *
 * Example 2:
 *
 *
 * Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
 * Output: 3
 *
 *
 *
 * Example 3:
 *
 *
 * Input: stones = [[0,0]]
 * Output: 0
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= stones.length <= 1000
 * 0 <= stones[i][j] < 10000
 *
 *
 *
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(n)
 */
class Solution {
public:
	int removeStones(vector<vector<int>> &stones) {
		// store stone position
		vector<vector<int>> colStonesRow(10010);
		vector<vector<int>> rowStonesCol(10010);
		
		// union stones together
		for (const auto &stone : stones) {
			int row = stone[0], col = stone[1];
			int stoneHashedPos = hashStonePos(row, col);
			parent[stoneHashedPos] = stoneHashedPos;
			
			colStonesRow[col].emplace_back(row);
			if (colStonesRow[col].size() > 1) {
				unionStone(hashStonePos(colStonesRow[col][colStonesRow[col].size() - 2], col),
				           stoneHashedPos);
			}
			
			rowStonesCol[row].emplace_back(col);
			if (rowStonesCol[row].size() > 1) {
				unionStone(hashStonePos(row, rowStonesCol[row][rowStonesCol[row].size() - 2]),
				           stoneHashedPos);
			}
		}
		
		int islands = 0;
		for (const auto &item : parent) {
			if (item.first == item.second) {
				islands++;
			}
		}
		
		return stones.size() - islands;
	}

private:
	unordered_map<int, int> parent;
	
	void unionStone(int hashStonePos1, int hashStonePos2) {
		if (findParent(hashStonePos1) == findParent(hashStonePos2)) {
			return;
		} else {
			parent[findParent(hashStonePos1)] = findParent(hashStonePos2);
		}
	}
	
	int findParent(int son) {
		if (parent[son] == son) {
			return son;
		}
		parent[son] = findParent(parent[son]);
		return parent[son];
	}
	
	int hashStonePos(int row, int col) {
		return row * 10000 + col;
	}
};
// @lc code=end

int main() {
	vector<vector<int>> stones;
	Solution solution;
	stones = {{0, 0},
	          {0, 1},
	          {1, 0},
	          {1, 2},
	          {2, 1},
	          {2, 2}};
	PrintSingleResult(solution.removeStones(stones));
	
	Solution solution1;
	stones = {{0, 0},
	          {0, 2},
	          {1, 1},
	          {2, 0},
	          {2, 2}};
	PrintSingleResult(solution1.removeStones(stones));
	
	Solution solution2;
	stones = {{0, 0}};
	PrintSingleResult(solution2.removeStones(stones));
	Complete();
	
}