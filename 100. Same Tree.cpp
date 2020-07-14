#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 *
 * https://leetcode.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (50.08%)
 * Likes:    1201
 * Dislikes: 39
 * Total Accepted:    392.5K
 * Total Submissions: 780.5K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * Given two binary trees, write a function to check if they are the same or
 * not.
 *
 * Two binary trees are considered the same if they are structurally identical
 * and the nodes have the same value.
 *
 * Example 1:
 * Input:     1         1
 * ⁠         / \       / \
 * ⁠        2   3     2   3
 *
 * ⁠       [1,2,3],   [1,2,3]
 *
 * Output: true
 *
 *
 * Example 2:
 * Input:     1         1
 * ⁠         /           \
 * ⁠        2             2
 *
 * ⁠       [1,2],     [1,null,2]
 *
 * Output: false
 *
 *
 * Example 3:
 * Input:     1         1
 * ⁠         / \       / \
 * ⁠        2   1     1   2
 *
 * ⁠       [1,2,1],   [1,1,2]
 *
 * Output: false
 *
 * test cases:
 * [1,2,3]
 * [1,2,3]
 * [1,2,3]
 * [1,2,null,3]
 * [null]
 * []
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
	/*
	 * Time complexity: O(n)
	 */
	bool isSameTree(TreeNode *p, TreeNode *q) {
		// check one nullptr case
		if ((p != nullptr && q == nullptr) ||
		    (p == nullptr && q != nullptr)) {
			return false;
		}
		
		// check value and subtree
		if (p != nullptr && q != nullptr) {
			if (p->val != q->val) {
				return false;
			}
			bool left = isSameTree(p->left, q->left);
			if (!left) {
				return false;
			}
			bool right = isSameTree(p->right, q->right);
			if (!right) {
				return false;
			}
		}
		return true;
	}
};

