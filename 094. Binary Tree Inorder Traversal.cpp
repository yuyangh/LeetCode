#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (56.81%)
 * Likes:    1658
 * Dislikes: 72
 * Total Accepted:    472.8K
 * Total Submissions: 829.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example:
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * Output: [1,3,2]
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		inOrderIterative(result, root);
		// inOrderRecursive(root);
		return result;
	}
	
	void inOrderIterative(vector<int> &result, TreeNode *node) {
		stack<TreeNode *> nodeStack;
		TreeNode *curr = node;
		while (curr != nullptr || !nodeStack.empty()) {
			// go to the left side
			while (curr != nullptr) {
				nodeStack.push(curr);
				curr = curr->left;
			}
			curr = nodeStack.top();
			// record node's value
			nodeStack.pop();
			result.emplace_back(curr->val);
			
			// work on to the curr's right side,
			// avoid search on left side again
			curr = curr->right;
		}
	}
	
	void inOrderRecursive(vector<int> &result, TreeNode *node) {
		if (node == nullptr) {
			return;
		}
		inOrderRecursive(result, node->left);
		result.emplace_back(node->val);
		inOrderRecursive(result, node->right);
	}
};
