//
// Created by Yuyang Huang on 6/18/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 *
 * https://leetcode.com/problems/h-index-ii/description/
 *
 * algorithms
 * Medium (35.84%)
 * Likes:    370
 * Dislikes: 589
 * Total Accepted:    111.1K
 * Total Submissions: 310.5K
 * Testcase Example:  '[0,1,3,5,6]'
 *
 * Given an array of citations sorted in ascending order (each citation is a
 * non-negative integer) of a researcher, write a function to compute the
 * researcher's h-index.
 *
 * According to the definition of h-index on Wikipedia: "A scientist has index
 * h if h of his/her N papers have at least h citations each, and the other N −
 * h papers have no more than h citations each."
 *
 * Example:
 *
 *
 * Input: citations = [0,1,3,5,6]
 * Output: 3
 * Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each
 * of them had
 * ⁠            received 0, 1, 3, 5, 6 citations respectively.
 * Since the researcher has 3 papers with at least 3 citations each and the
 * remaining
 * two with no more than 3 citations each, her h-index is 3.
 *
 * Note:
 *
 * If there are several possible values for h, the maximum one is taken as the
 * h-index.
 *
 * Follow up:
 *
 *
 * This is a follow up problem to H-Index, where citations is now guaranteed to
 * be sorted in ascending order.
 * Could you solve it in logarithmic time complexity?
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(logn)
 * the question asks: find a index so that there are arr[index] items start from the index
 */
class Solution {
public:
	int hIndex(vector<int> &citations) {
		int pivot, left = 0, right = citations.size() - 1;
		while (left <= right) {
			pivot = left + (right - left) / 2;
			if (citations[pivot] == citations.size() - pivot) {
				return citations.size() - pivot;
			} else if (citations[pivot] < citations.size() - pivot) {
				left = pivot + 1;
			} else {
				right = pivot - 1;
			}
		}
		return citations.size() - left;
	}
};
// @lc code=end

