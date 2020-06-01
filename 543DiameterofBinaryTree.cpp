//
// Created by Yuyang Huang on 5/31/20.
//

#include "LeetCodeLib.h"


/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (47.63%)
 * Likes:    2803
 * Dislikes: 180
 * Total Accepted:    316.7K
 * Total Submissions: 659.2K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 *
 * Given a binary tree, you need to compute the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through the
 * root.
 *
 *
 *
 * Example:
 * Given a binary tree
 *
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \
 * ⁠     4   5
 *
 *
 *
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 *
 *
 * Note:
 * The length of path between two nodes is represented by the number of edges
 * between them.
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
 * Time Complexity: O(n)
 * DFS
 */
class Solution {
public:
	int diameterOfBinaryTree(TreeNode *root) {
		helper(root);
		return maxHeight;
	}

private:
	int helper(TreeNode *node) {
		if (node == nullptr) {
			return 0;
		}
		int leftHeight = helper(node->left);
		int rightHeight = helper(node->right);
		maxHeight = max(leftHeight + rightHeight, maxHeight);
		return 1 + max(leftHeight, rightHeight);
	}
	
	int maxHeight = 0;
};
// @lc code=end

