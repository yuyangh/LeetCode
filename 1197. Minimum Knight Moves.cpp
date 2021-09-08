//
// Created by Yuyang Huang on 9/8/21.
//

/*
 * 1197. Minimum Knight Moves
 * Medium
 *
 * In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].
 * A knight has 8 possible moves it can make, as illustrated below.
 * Each move is two squares in a cardinal direction, then one square in an orthogonal direction.
 * Return the minimum number of steps needed to move the knight to the square [x, y].
 * It is guaranteed the answer exists.
 *
 * Example 1:
 * Input: x = 2, y = 1
 * Output: 1
 * Explanation: [0, 0] → [2, 1]
 *
 * Example 2:
 * Input: x = 5, y = 5
 * Output: 4
 * Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
 *
 * Constraints:
 * -300 <= x, y <= 300
 * 0 <= |x| + |y| <= 300
 */
#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(?)
	 * BFS to find the target
	 * Because the move is symmetric, we use set and compression to memorize explored points
	 */
	int minKnightMoves(int x, int y) {
		unordered_set<long long> explored;
		vector<vector<int>> moves = {{2,  1},
		                             {1,  2},
		                             {2,  -1},
		                             {1,  -2},
		                             {-2, 1},
		                             {-1, 2},
		                             {-2, -1},
		                             {-1, -2}};
		
		queue<pair<pair<int, int>, int>> pointDistQueue;
		pointDistQueue.emplace(make_pair(make_pair(0, 0), 0));
		
		while (true) {
			auto point = pointDistQueue.front();
			pointDistQueue.pop();
			
			int xPos, yPos, dist;
			xPos = point.first.first;
			yPos = point.first.second;
			dist = point.second;
			if (xPos == abs(x) && yPos == abs(y)) {
				return dist;
			}
			
			// visit each move
			for (auto &move: moves) {
				int newX = xPos + move[0], newY = yPos + move[1];
				
				// some point need to go through negative boarder to visit
				if (explored.count(JoinPoint(newX, newY)) > 0
				    || newX < -1 || newY < -1) {
					continue;
				}
				
				pointDistQueue.emplace(make_pair(make_pair(newX, newY), dist + 1));
				explored.emplace(JoinPoint(newX, newY));
			}
		}
		return -1;
	}

private:
	long long JoinPoint(long long x, long long y) {
		return (x * 1000) + y;
	}
};

int main() {
	Solution solution;
	PrintSingleResult(solution.minKnightMoves(2, 1));
	PrintSingleResult(solution.minKnightMoves(5, 5));
	PrintSingleResult(solution.minKnightMoves(2, 112));
	PrintSingleResult(solution.minKnightMoves(0, -300));
}