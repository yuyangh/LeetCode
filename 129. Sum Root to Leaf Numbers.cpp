#include "LeetCodeLib.h"
/*
 * 129. Sum Root to Leaf Numbers
 *
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 *
 * algorithms
 * Medium
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path
 * could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the number
 * 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 * Input: [1,2,3]
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * Output: 25
 * Explanation:
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Therefore, sum = 12 + 13 = 25.
 *
 * Example 2:
 * Input: [4,9,0,5,1]
 * ⁠   4
 * ⁠  / \
 * ⁠ 9   0
 * / \
 * 5   1
 * Output: 1026
 * Explanation:
 * The root-to-leaf path 4->9->5 represents the number 495.
 * The root-to-leaf path 4->9->1 represents the number 491.
 * The root-to-leaf path 4->0 represents the number 40.
 * Therefore, sum = 495 + 491 + 40 = 1026.
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
	int sumNumbers(TreeNode *root) {
		int sum = 0;
		helper(root, sum, 0);
		return sum;
	}

private:
	/*
	 * go from top to bottom,
	 * add value at leaf node
	 */
	void helper(TreeNode *node, int &sum, int curr) {
		if (node == nullptr) {
			return;
		}
		int currVal = curr * 10 + node->val;
		if (node->left == nullptr && node->right == nullptr) {
			sum += currVal;
			return;
		}
		helper(node->left, sum, currVal);
		helper(node->right, sum, currVal);
	}
};