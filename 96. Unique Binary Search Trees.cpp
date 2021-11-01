#include "LeetCodeLib.h"

/*
 * 96. Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ...n?
 *
 * Example:
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 *
 *   1         3     3      2      1
 *    \       /     /      / \      \
 *     3     2     1      1   3      2
 *    /     /       \                 \
 *   2     1         2                 3
 */

/*
 * Time complexity: O(n*n)
 * space complexity: O(n)
 * dynamic programming
 */
class Solution {
public:
	int numTrees(int n) {
		vector<int> numForms(n + 2);
		
		// base case
		numForms[0] = 1;
		numForms[1] = 1;
		
		// each subtree can reuse previous calculation
		for (int i = 2; i <= n; ++i) {
			int form = 0;
			for (int left = 0; left < i; ++left) {
				form += numForms[left] * numForms[i - left - 1];
			}
			numForms[i] = form;
		}
		return numForms[n];
	}
	
	int numTreesMath(int n) {
		long C = 1;
		for (int i = 0; i < n; ++i) {
			C = C * 2 * (2 * i + 1) / (i + 2);
		}
		return (int) C;
	}
};


int main() {
	Solution solution;
	assert(solution.numTrees(3) == 5);
	assert(solution.numTrees(0) == 1);
	
	Complete();
}

