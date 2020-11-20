//
// Created by Yuyang Huang on 11/20/20.
//

#include "LeetCodeLib.h"

/*
 * 1423. Maximum Points You Can Obtain from Cards
 * Medium
 *
 * There are several cards arranged in a row,
 * and each card has an associated number of points.
 * The points are given in the integer array cardPoints.
 * In one step, you can take one card from the beginning or from the end of the row.
 * You have to take exactly k cards.
 * Your score is the sum of the points of the cards you have taken.
 * Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
 *
 * Example 1:
 * Input: cardPoints = [1,2,3,4,5,6,1], k = 3
 * Output: 12
 * Explanation: After the first step, your score will always be 1.
 * However, choosing the rightmost card first will maximize your total score.
 * The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
 *
 * Example 2:
 * Input: cardPoints = [2,2,2], k = 2
 * Output: 4
 * Explanation: Regardless of which two cards you take, your score will always be 4.
 *
 * Example 3:
 * Input: cardPoints = [9,7,7,9,7,7,9], k = 7
 * Output: 55
 * Explanation: You have to take all the cards. Your score is the sum of points of all cards.
 *
 * Example 4:
 * Input: cardPoints = [1,1000,1], k = 1
 * Output: 1
 * Explanation: You cannot take the card in the middle. Your best score is 1.
 *
 * Example 5:
 * Input: cardPoints = [1,79,80,1,1,1,200,1], k = 3
 * Output: 202
 *
 * Constraints:
 * 1 <= cardPoints.length <= 10^5
 * 1 <= cardPoints[i] <= 10^4
 * 1 <= k <= cardPoints.length
 */

class Solution {
public:
	/*
	 * Time complexity: O(n)
	 */
	int maxScore(vector<int> &cardPoints, int k) {
		if (k == 0) { return 0; }
		if (k == cardPoints.size()) { return accumulate(cardPoints.begin(), cardPoints.end(), 0); }
		
		int leftSum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0), rightSum = 0;
		int rightIdx;
		int maxSum = leftSum;
		for (rightIdx = 0; rightIdx < k; rightIdx++) {
			leftSum -= cardPoints[k - 1 - rightIdx];
			rightSum += cardPoints[cardPoints.size() - 1 - rightIdx];
			maxSum = max(maxSum, leftSum + rightSum);
		}
		return maxSum;
	}
};

int main() {
	Solution solution;
	vector<int> arr;
	arr = {1, 2, 3, 4, 5, 6, 1};
	PrintSingleResult(solution.maxScore(arr, 3) == 12);
	arr = {2, 2, 2};
	PrintSingleResult(solution.maxScore(arr, 2) == 4);
	arr = {9, 7, 7, 9, 7, 7, 9};
	PrintSingleResult(solution.maxScore(arr, 7) == 55);
	arr = {1, 1000, 1};
	PrintSingleResult(solution.maxScore(arr, 1) == 1);
	arr = {1, 79, 80, 1, 1, 1, 200, 1};
	PrintSingleResult(solution.maxScore(arr, 3) == 202);
}