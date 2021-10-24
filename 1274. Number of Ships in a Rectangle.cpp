//
// Created by Yuyang Huang on 10/24/21.
//

/*
 * 1274. Number of Ships in a Rectangle
 * Hard
 *
 * (This problem is an interactive problem.)
 * Each ship is located at an integer point on the sea represented by a cartesian plane,
 * and each integer point may contain at most 1 ship.
 * You have a function Sea.hasShips(topRight, bottomLeft) which takes two points as arguments
 * and returns true If there is at least one ship in the rectangle represented by the two points,
 * including on the boundary.
 *
 * Given two points: the top right and bottom left corners of a rectangle,
 * return the number of ships present in that rectangle.
 * It is guaranteed that there are at most 10 ships in that rectangle.
 * Submissions making more than 400 calls to hasShips will be judged Wrong Answer.
 * Also, any solutions that attempt to circumvent the judge will result in disqualification.
 *
 * Example :
 * Input:
 * ships = [[1,1],[2,2],[3,3],[5,5]], topRight = [4,4], bottomLeft = [0,0]
 * Output: 3
 * Explanation: From [0,0] to [4,4] we can count 3 ships within the range.
 *
 * Example 2:
 * Input: ans = [[1,1],[2,2],[3,3]], topRight = [1000,1000], bottomLeft = [0,0]
 * Output: 3
 *
 * Constraints:
 * On the input ships is only given to initialize the map internally.
 * You must solve this problem "blindfolded". In other words, you must find the answer using the given hasShips API,
 * without knowing the ships position.
 * 0 <= bottomLeft[0] <= topRight[0] <= 1000
 * 0 <= bottomLeft[1] <= topRight[1] <= 1000
 * topRight != bottomLeft
 */

/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

#include "LeetCodeLib.h"

class Sea {
public:
	bool hasShips(vector<int> topRight, vector<int> bottomLeft);
};

class Solution {
public:
	/*
	 * Time complexity: Time complexity: O(n) where n is total number of points inside the rectangle
	 * T(n) = 4xT(n/4) + O(1) apply master theorem: n^(log(4)4) = n is O(O(1)). So T(n) = O(n)
	 * divide the current rectangle into 4 pieces in the middle.
	 */
	int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
		// beyond bounds
		if (bottomLeft[0] > topRight[0] || bottomLeft[1] > topRight[1]) {
			return 0;
		}
		// this area has no ships
		if (!sea.hasShips(topRight, bottomLeft)) {
			return 0;
		}
		
		// the area is a single point
		if (topRight == bottomLeft) {
			return 1;
		}
		int midRow = (topRight[0] + bottomLeft[0]) / 2, midCol = (topRight[1] + bottomLeft[1]) / 2;
		int bottomLeftRow = bottomLeft[0], bottomLeftCol = bottomLeft[1], topRightRow = topRight[0], topRightCol = topRight[1];
		// divide into quarters and solve
		return countShips(sea, {midRow, midCol}, bottomLeft) +
		       countShips(sea, {topRightRow, midCol}, {midRow + 1, bottomLeftCol}) +
		       countShips(sea, topRight, {midRow + 1, midCol + 1}) +
		       countShips(sea, {midRow, topRightCol}, {bottomLeftRow, midCol + 1});
	}
};

int main() {
	vector<int> a(1, 1), b = {1};
	PrintSingleResult(a == b);
}