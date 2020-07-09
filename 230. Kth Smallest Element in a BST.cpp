//
// Created by Yuyang Huang on 5/20/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (53.99%)
 * Likes:    2275
 * Dislikes: 57
 * Total Accepted:    367.6K
 * Total Submissions: 626.6K
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * Given a binary search tree, write a function kthSmallest to find the kth
 * smallest element in it.
 *
 *
 * Example 1:
 * Input: root = [3,1,4,null,2], k = 1
 * ⁠  3
 * ⁠ / \
 * ⁠1   4
 * ⁠ \
 * 2
 * Output: 1
 *
 * Example 2:
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * ⁠      5
 * ⁠     / \
 * ⁠    3   6
 * ⁠   / \
 * ⁠  2   4
 * ⁠ /
 * ⁠1
 * Output: 3
 *
 *
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to
 * find the kth smallest frequently? How would you optimize the kthSmallest
 * routine?
 *
 *
 * Constraints:
 * The number of elements of the BST is between 1 to 10^4.
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
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
class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * iteratively go through the tree to count nodes
	 */
	int kthSmallest(TreeNode *root, int k) {
		if (root == nullptr) {
			return 0;
		}
		stack<TreeNode *> nodes;
		nodes.emplace(root);
		int count = 0;
		while (!nodes.empty()) {
			// go to the left
			while (nodes.top()->left != nullptr) {
				nodes.emplace(nodes.top()->left);
			}
			
			// pop until there is right
			while (nodes.top()->right == nullptr) {
				auto node = nodes.top();
				nodes.pop();
				count++;
				if (count == k) {
					return node->val;
				}
			}
			// go to the right
			if (nodes.top()->right != nullptr) {
				auto node = nodes.top();
				nodes.pop();
				count++;
				if (count == k) {
					return node->val;
				}
				nodes.emplace(node->right);
			}
		}
		return count;
	}
};
// @lc code=end
