//
// Created by Yuyang Huang on 9/13/21.
//

/*
 * 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 * Medium
 *
 * You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:
 * horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
 * verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
 *
 * Return the maximum area of a piece of cake after you cut at each horizontal
 * and vertical position provided in the arrays horizontalCuts and verticalCuts.
 * Since the answer can be a large number, return this modulo 109 + 7.
 *
 * Example 1:
 * Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
 * Output: 4
 * Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts.
 * After you cut the cake, the green piece of cake has the maximum area.
 *
 * Example 2:
 * Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
 * Output: 6
 * Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts.
 * After you cut the cake, the green and yellow pieces of cake have the maximum area.
 *
 * Example 3:
 * Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
 * Output: 9
 *
 * Constraints:
 * 2 <= h, w <= 109
 * 1 <= horizontalCuts.length <= min(h - 1, 105)
 * 1 <= verticalCuts.length <= min(w - 1, 105)
 * 1 <= horizontalCuts[i] < h
 * 1 <= verticalCuts[i] < w
 * All the elements in horizontalCuts are distinct.
 * All the elements in verticalCuts are distinct.
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(mlogm nlogn)
	 * because each vertical cut and horizontal cut is independent
	 * find the largest vertical cut, then for horizontal
	 */
	int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts) {
		int modulo = 1E9 + 7;
		
		// base case
		horizontalCuts.emplace_back(0);
		horizontalCuts.emplace_back(h);
		verticalCuts.emplace_back(0);
		verticalCuts.emplace_back(w);
		
		sort(horizontalCuts.begin(), horizontalCuts.end());
		sort(verticalCuts.begin(), verticalCuts.end());
		
		int maxHorizontalGap = 0, maxVerticalGap = 0;
		for (int i = 1; i < horizontalCuts.size(); i++) {
			maxHorizontalGap = max(maxHorizontalGap, horizontalCuts[i] - horizontalCuts[i - 1]);
		}
		for (int i = 1; i < verticalCuts.size(); i++) {
			maxVerticalGap = max(maxVerticalGap, verticalCuts[i] - verticalCuts[i - 1]);
		}
		
		unsigned long long result = (static_cast<unsigned long long>(maxHorizontalGap % modulo) *
		                             static_cast<unsigned long long>(maxVerticalGap % modulo)) % modulo;
		return result;
	}
};

int main() {
	Solution solution;
	int h, w;
	vector<int> horizontalCuts;
	vector<int> verticalCuts;
	h = 1000000000, w = 1000000000;
	horizontalCuts = {2};
	verticalCuts = {2};
	PrintSingleResult(solution.maxArea(h, w, horizontalCuts, verticalCuts));
}