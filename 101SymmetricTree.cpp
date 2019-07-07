#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (43.53%)
 * Likes:    2343
 * Dislikes: 48
 * Total Accepted:    419.8K
 * Total Submissions: 959.7K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 *
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 *
 *
 *
 *
 * But the following [1,2,2,null,3,null,3] is not:
 *
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 *
 *
 *
 *
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
	// recursion without memorizing
	bool isSymmetric(TreeNode *root) {
		if (root== nullptr) {
			return true;
		}
		// recursively comparing two pointers
		return helper(root->left, root->right);
	}
	
	// use two vectors to memorize the traverse, previous written
	bool isSymmetricMemorize(TreeNode *root) {
		if (root == nullptr) {
			return true;
		}
		checkLeftSymmetric(root->left);
		checkRightSymmetric(root->right);
		
		if (left_nodes_.size() != right_nodes_.size()) {
			return false;
		}
		
		// check whether left contents same as right contents
		for (int i = 0; i < left_nodes_.size(); ++i) {
			// left node is not nullptr
			if (left_nodes_[i] != nullptr) {
				if (right_nodes_[i] != nullptr) {
					if (left_nodes_[i]->val != right_nodes_[i]->val) {
						return false;
					}
				} else {
					return false;
				}
			} else {
				if (right_nodes_[i] != nullptr) {
					return false;
				}
			}
		}
		return true;
	}
	
private:
	vector<TreeNode *> left_nodes_;
	vector<TreeNode *> right_nodes_;
	
	bool helper(TreeNode *p, TreeNode *q) {
		if (!p && !q) {
			return true;
		} else {
			// single nullptr
			if (!p || !q) {
				return false;
			}
		}
		
		if (p->val != q->val) {
			return false;
		}
		
		return helper(p->left, q->right) &&
		       helper(p->right, q->left);
	}
	
	void checkLeftSymmetric(TreeNode *node) {
		left_nodes_.emplace_back(node);
		if (node != nullptr) {
			checkLeftSymmetric(node->left);
			checkLeftSymmetric(node->right);
		}
	}
	
	void checkRightSymmetric(TreeNode *node) {
		right_nodes_.emplace_back(node);
		if (node != nullptr) {
			checkRightSymmetric(node->right);
			checkRightSymmetric(node->left);
		}
	}
};

