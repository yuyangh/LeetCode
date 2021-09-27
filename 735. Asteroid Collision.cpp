//
// Created by Yuyang Huang on 9/28/21.
//

/*
 * 735. Asteroid Collision
Medium

2502

194

Add to List

Share
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.



Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
Example 4:

Input: asteroids = [-2,-1,1,2]
Output: [-2,-1,1,2]
Explanation: The -2 and -1 are moving left, while the 1 and 2 are moving right. Asteroids moving the same direction never meet, so no asteroids will meet each other.


Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(n)
	 */
	vector<int> asteroidCollision(vector<int> &asteroids) {
		vector<int> stones;
		vector<int> result;
		for (int stone: asteroids) {
			if (stone > 0) {
				stones.push_back(stone);
			} else {
				// stone moving left
				// no impeding stones
				if (stones.empty()) {
					result.push_back(stone);
					continue;
				}
				
				while (!stones.empty()) {
					// exact collision
					if (stones.back() == -stone) {
						stone = 0;
						stones.pop_back();
						break;
					}
					if (stones.back() < -stone) {
						stones.pop_back();
					} else {
						stone = 0;
						break;
					}
				}
				if (stone != 0) {
					result.push_back(stone);
				}
			}
		}
		for (auto &stone: stones) {
			result.push_back(stone);
		}
		return result;
	}
};

int main() {
	Solution solution;
	vector<int> stones;
	stones = {5, 10, -5};
	PrintVector(solution.asteroidCollision(stones));
	stones = {8, -8};
	PrintVector(solution.asteroidCollision(stones));
	stones = {10, 2, -5};
	PrintVector(solution.asteroidCollision(stones));
	stones = {-2, -1, 1, 2};
	PrintVector(solution.asteroidCollision(stones));
}
