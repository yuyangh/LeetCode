#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 *
 * https://leetcode.com/problems/dungeon-game/description/
 *
 * algorithms
 * Hard (27.06%)
 * Likes:    677
 * Dislikes: 16
 * Total Accepted:    66.1K
 * Total Submissions: 243.7K
 * Testcase Example:  '[[-2,-3,3],[-5,-10,1],[10,30,-5]]'
 *
 * The demons had captured the princess (P) and imprisoned her in the
 * bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid
 * out in a 2D grid. Our valiant knight (K) was initially positioned in the
 * top-left room and must fight his way through the dungeon to rescue the
 * princess.
 *
 * The knight has an initial health point represented by a positive integer. If
 * at any point his health point drops to 0 or below, he dies immediately.
 *
 * Some of the rooms are guarded by demons, so the knight loses health
 * (negative integers) upon entering these rooms; other rooms are either empty
 * (0's) or contain magic orbs that increase the knight's health (positive
 * integers).
 *
 * In order to reach the princess as quickly as possible, the knight decides to
 * move only rightward or downward in each step.
 *
 * Write a function to determine the knight's minimum initial health so that he
 * is able to rescue the princess.
 *
 * For example, given the dungeon below, the initial health of the knight must
 * be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN ->
 * DOWN.
 *
 * -2 (K)
 * -3
 * 3
 *
 * -5
 * -10
 * 1
 *
 * 10
 * 30
 * -5 (P)
 *
 * Note:
 * The knight's health has no upper bound.
 * Any room can contain threats or power-ups, even the first room the knight
 * enters and the bottom-right room where the princess is imprisoned.
 */
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>> &dungeon) {
		if (dungeon.empty()) {
			return 0;
		}
		const int WIDTH = dungeon[0].size(), HEIGHT = dungeon.size();
		vector<vector<int>> hp(dungeon.size(), vector<int>(dungeon[0].size(), 0));
		
		hp[HEIGHT - 1][WIDTH - 1] = max(1 - dungeon[HEIGHT - 1][WIDTH - 1], 1);
		// initialize bottom row
		for (int col = WIDTH - 2; col >= 0; col--) {
			hp[HEIGHT - 1][col] = max(hp[HEIGHT - 1][col + 1] - dungeon[HEIGHT - 1][col], 1);
		}
		// initialize rightest column
		for (int row = HEIGHT - 2; row >= 0; row--) {
			hp[row][WIDTH - 1] = max(hp[row + 1][WIDTH - 1] - dungeon[row][WIDTH - 1], 1);
		}
		
		// calculate the center
		for (int row = HEIGHT - 2; row >= 0; row--) {
			for (int col = WIDTH - 2; col >= 0; col--) {
				int minPrevHPNeed = min(hp[row + 1][col], hp[row][col + 1]);
				hp[row][col] = max(minPrevHPNeed - dungeon[row][col], 1);
			}
		}
		return hp[0][0];
		
	}
};

