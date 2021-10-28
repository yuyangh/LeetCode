//
// Created by Yuyang Huang on 11/4/21.
//

/*
 * 404. Sum of Left Leaves
Easy

Given the root of a binary tree, return the sum of all left leaves.



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
Example 2:

Input: root = [1]
Output: 0


Constraints:

The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000
 */


#include "LeetCodeLib.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	int sumOfLeftLeaves(TreeNode *root) {
		return helper(root, false);
	}

private:
	int helper(TreeNode *node, bool isLeft) {
		if (node == nullptr) {
			return 0;
		}
		int addedVal = 0;
		// only add value for leaves
		if (node->left == nullptr &&
		    node->right == nullptr &&
		    isLeft) {
			addedVal = node->val;
		}
		int left = helper(node->left, true);
		int right = helper(node->right, false);
		return left + right + addedVal;
	}
};