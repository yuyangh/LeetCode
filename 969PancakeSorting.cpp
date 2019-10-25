//
// Created by Yuyang Huang on 10/25/19.
//
/*
 * @lc app=leetcode id=969 lang=cpp
 *
 * [969] Pancake Sorting
 *
 * https://leetcode.com/problems/pancake-sorting/description/
 *
 * algorithms
 * Medium (62.40%)
 * Likes:    208
 * Dislikes: 252
 * Total Accepted:    16.3K
 * Total Submissions: 26K
 * Testcase Example:  '[3,2,4,1]'
 *
 * Given an array A, we can perform a pancake flip: We choose some positive
 * integer k <= A.length, then reverse the order of the first k elements of A.
 * We want to perform zero or more pancake flips (doing them one after another
 * in succession) to sort the array A.
 *
 * Return the k-values corresponding to a sequence of pancake flips that sort
 * A.  Any valid answer that sorts the array within 10 * A.length flips will be
 * judged as correct.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [3,2,4,1]
 * Output: [4,2,4,3]
 * Explanation:
 * We perform 4 pancake flips, with k values 4, 2, 4, and 3.
 * Starting state: A = [3, 2, 4, 1]
 * After 1st flip (k=4): A = [1, 4, 2, 3]
 * After 2nd flip (k=2): A = [4, 1, 2, 3]
 * After 3rd flip (k=4): A = [3, 2, 1, 4]
 * After 4th flip (k=3): A = [1, 2, 3, 4], which is sorted.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [1,2,3]
 * Output: []
 * Explanation: The input is already sorted, so there is no need to flip
 * anything.
 * Note that other answers, such as [3, 3], would also be accepted.
 *
 * Note:
 *
 *
 * 1 <= A.length <= 100
 * A[i] is a permutation of [1, 2, ..., A.length]
 *
 *
 */

// @lc code=start
#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * time complexity: O(n*n)
	 */
	vector<int> pancakeSort(vector<int> &A) {
		vector<int> result;
		int nextLargestNum, pos;
		for (nextLargestNum = A.size(); nextLargestNum > 0; nextLargestNum--) {
			for (pos = 0; A[pos] != nextLargestNum; pos++) {}
			
			// the place of this number is correct, we do not need to do anything
			if(pos==nextLargestNum-1){
				continue;
			}
			
			// swap the nextLargestNum to the front
			reverse(A.begin(), A.begin() + pos + 1);
			// record down the place of flip
			result.emplace_back(pos + 1);
			// swap the nextLargestNum to its proper place
			reverse(A.begin(), A.begin() + nextLargestNum);
			result.emplace_back(nextLargestNum);
		}
		return result;
	}
};
// @lc code=end

int main() {
	vector<int> arr = {1, 4, 2, 3};
	Solution solution;
	auto result = solution.pancakeSort(arr);
	PrintVector(result);
}


