//
// Created by Yuyang Huang on 9/13/21.
//

/*
 * 1041. Robot Bounded In Circle
 * Medium
 *
 * On an infinite plane, a robot initially stands at (0, 0) and faces north.
 * The robot can receive one of three instructions:
 * "G": go straight 1 unit;
 * "L": turn 90 degrees to the left;
 * "R": turn 90 degrees to the right.
 * The robot performs the instructions given in order, and repeats them forever.
 *
 * Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.
 * Example 1:
 * Input: instructions = "GGLLGG"
 * Output: true
 * Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
 * When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.
 *
 * Example 2:
 * Input: instructions = "GG"
 * Output: false
 * Explanation: The robot moves north indefinitely.
 *
 * Example 3:
 * Input: instructions = "GL"
 * Output: true
 * Explanation: The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
 *
 * Constraints:
 * 1 <= instructions.length <= 100
 * instructions[i] is 'G', 'L' or, 'R'.
 */

#include "LeetCodeLib.h

class Solution {
public:
	/*
	 * Time complexity: O(n)
	 *
	 * First, if the robot returns to the initial point after one cycle, that's the limit cycle trajectory.
	 * Second, if the robot doesn't face north at the end of the first cycle, that's the limit cycle trajectory.
	 * Once again, that's the consequence of the plane symmetry for the repeated cycles
	 */
	bool isRobotBounded(string instructions) {
		// initial direction is facing north, same as moves[0]
		int direction = 0;
		int x = 0, y = 0;
		vector<vector<int>> moves = {{0,  1},
		                             {1,  0},
		                             {0,  -1},
		                             {-1, 0}};
		for (char c: instructions) {
			if (c == 'G') {
				x += moves[direction][0];
				y += moves[direction][1];
			}
			if (c == 'R') {
				direction = (direction + 1 + moves.size()) % moves.size();
			}
			if (c == 'L') {
				direction = (direction - 1 + moves.size()) % moves.size();
			}
		}
		
		// return to origin
		if (x == 0 && y == 0) {
			return true;
		}
		
		// after 1 pass still facing north cannot go back to origin again
		if (direction == 0) {
			return false;
		}
		
		// any other direction, with 4 pass, will go back to original place
		return true;
	}
};