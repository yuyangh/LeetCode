//
// Created by Yuyang Huang on 6/1/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 *
 * https://leetcode.com/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (60.14%)
 * Likes:    3098
 * Dislikes: 48
 * Total Accepted:    487.1K
 * Total Submissions: 764.8K
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * Invert a binary tree.
 *
 * Example:
 *
 * Input:
 *
 *
 * ⁠    4
 * ⁠  /   \
 * ⁠ 2     7
 * ⁠/ \   / \
 * 1   3 6   9
 *
 * Output:
 *
 *
 * ⁠    4
 * ⁠  /   \
 * ⁠ 7     2
 * ⁠/ \   / \
 * 9   6 3   1
 *
 * Trivia:
 * This problem was inspired by this original tweet by Max Howell:
 *
 * Google: 90% of our engineers use the software you wrote (Homebrew), but you
 * can’t invert a binary tree on a whiteboard so f*** off.
 *
 */

// @lc code=start
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
 
/*
 * Time complexity: O(n)
 * recursion
 */
class Solution {
public:
	TreeNode *invertTree(TreeNode *root) {
		return helper(root);
	}

private:
	TreeNode *helper(TreeNode *node) {
		if (node == nullptr) {
			return nullptr;
		}
		auto temp = node->left;
		node->left = node->right;
		node->right = temp;
		helper(node->left);
		helper(node->right);
		return node;
	}
};
// @lc code=end

