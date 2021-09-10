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

class Point {
public:
	int x;
	int y;
	int jump = 0;
	int estJump = 0;
	
	explicit Point(int x, int y) : x(x), y(y) {}
	
	explicit Point(int x, int y, int jump, int estJump) : x(x), y(y), jump(jump), estJump(estJump) {}
};

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
		
		
		auto pointComp = [](Point &lhs, Point &rhs) {
			if (lhs.jump + lhs.estJump == rhs.jump + rhs.estJump) {
				return lhs.jump > rhs.jump;
			} else {
				return lhs.jump + lhs.estJump > rhs.jump + rhs.estJump;
			}
		};
		
		priority_queue<Point, vector<Point>, decltype(pointComp)> pq(pointComp);
		Point origin(0, 0, 0, estimatedJump(0, 0, x, y));
		pq.emplace(origin);
		
		while (true) {
			auto point = pq.top();
			pq.pop();
			
			int xPos, yPos, jump;
			xPos = point.x;
			yPos = point.y;
			jump = point.jump;
			if (xPos == x && yPos == y) {
				return jump;
			}
			
			// visit each move
			for (auto &move: moves) {
				int newX = xPos + move[0], newY = yPos + move[1];
				
				// some point need to go through negative boarder to visit
				if (explored.count(JoinPoint(newX, newY)) > 0) {
					continue;
				}
				
				pq.emplace(Point(newX, newY, jump + 1, estimatedJump(newX, newY, x, y)));
				explored.emplace(JoinPoint(newX, newY));
			}
		}
		return -1;
	}

private:
	long long JoinPoint(long long x, long long y) {
		return (x * 1000) + y;
	}
	
	int estimatedJump(int x, int y, int targetX, int targetY) {
		int xDist = abs(targetX - x), yDist = abs(targetY - y);
		if (xDist < 4 && yDist < 4) {
			return jumps[xDist][yDist];
		}
		return max(0, min(min(xDist / 2, yDist),
		                  min(xDist, yDist / 2)));
	}
	
	vector<vector<int>> jumps = {{3, 2, 3, 2},
	                             {2, 1, 4, 3},
	                             {3, 2, 1, 2},
	                             {0, 3, 2, 3},};
};

int main() {
	Solution solution;
	PrintSingleResult(solution.minKnightMoves(2, 1));
	PrintSingleResult(solution.minKnightMoves(5, 5));
	PrintSingleResult(solution.minKnightMoves(130, -86));
	PrintSingleResult(solution.minKnightMoves(2, 112));
	PrintSingleResult(solution.minKnightMoves(0, -300));
	PrintSingleResult(solution.minKnightMoves(114, -179));
}