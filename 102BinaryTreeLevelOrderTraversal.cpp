#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (48.64%)
 * Likes:    1501
 * Dislikes: 40
 * Total Accepted:    383.9K
 * Total Submissions: 788.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 *
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * return its level order traversal as:
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
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
	vector<vector<int>> result;
	
	vector<vector<int>> levelOrder(TreeNode *root) {
		levelOrder(root, 0);
		return result;
	}
	
	void levelOrder(TreeNode *node, int level) {
		if (node == nullptr) {
			return;
		}
		// add the vector for that level
		if (level >= result.size()) {
			result.emplace_back(vector<int>());
		}
		result[level].emplace_back(node->val);
		// add for the next level
		levelOrder(node->left, level + 1);
		levelOrder(node->right, level + 1);
	}
};

