//
// Created by Yuyang Huang on 6/3/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=951 lang=cpp
 *
 * [951] Flip Equivalent Binary Trees
 *
 * https://leetcode.com/problems/flip-equivalent-binary-trees/description/
 *
 * algorithms
 * Medium (65.06%)
 * Likes:    568
 * Dislikes: 23
 * Total Accepted:    44.3K
 * Total Submissions: 67.6K
 * Testcase Example:  '[1,2,3,4,5,6,null,null,null,7,8]\n[1,3,2,null,6,4,5,null,null,null,null,8,7]'
 *
 * For a binary tree T, we can define a flip operation as follows: choose any
 * node, and swap the left and right child subtrees.
 *
 * A binary tree X is flip equivalent to a binary tree Y if and only if we can
 * make X equal to Y after some number of flip operations.
 *
 * Write a function that determines whether two binary trees are flip
 * equivalent.  The trees are given by root nodes root1 and root2.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 =
 * [1,3,2,null,6,4,5,null,null,null,null,8,7]
 * Output: true
 * Explanation: We flipped at nodes with values 1, 3, and 5.
 *
 *
 *
 *
 *
 * Note:
 *
 *
 * Each tree will have at most 100 nodes.
 * Each value in each tree will be a unique integer in the range [0, 99].
 *
 *
 *
 *
 *
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
	bool flipEquiv(TreeNode *root1, TreeNode *root2) {
		return helper(root1, root2);
	}

private:
	bool helper(TreeNode *node1, TreeNode *node2) {
		if (node1 == nullptr && node2 == nullptr) {
			return true;
		}
		if ((node1 == nullptr && node2 != nullptr) ||
		    (node1 != nullptr && node2 == nullptr)) {
			return false;
		}
		if (node1->val != node2->val) {
			return false;
		}
		
		// check flopped or not
		bool unflip = helper(node1->left, node2->left) && helper(node1->right, node2->right);
		bool flip = helper(node1->left, node2->right) && helper(node1->right, node2->left);
		return unflip || flip;
	}
};
// @lc code=end

