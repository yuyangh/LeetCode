//
// Created by Yuyang Huang on 7/11/20.
//

#include "LeetCodeLib.h"

/*
 * Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
 * The successor of a node p is the node with the smallest key greater than p.val.
 *
 * Example 1:
 * Input: root = [2,1,3], p = 1
 * Output: 2
 * Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.
 *
 * Input: root = [5,3,6,2,4,null,null,1], p = 6
 * Output: null
 * Explanation: There is no in-order successor of the current node, so the answer is null.
 *
 * Note:
 * If the given node has no in-order successor in the tree, return null.
 * It's guaranteed that the values of the tree are unique.
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
	 * Time complexity: O(h)
	 * iterative based on value property of bst
	 */
	TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
		TreeNode *cur = root;
		TreeNode *candidate = nullptr;
		
		// If we reach null, our search is over, just return the candidate.
		while (cur != nullptr) {
			// If current node's value is less than or equal to p's value,
			// the answer must be in the right subtree.
			if (cur->val <= p->val) {
				cur = cur->right;
			} else {
				// If current node's value is greater than p's value, current node is a candidate.
				// Go to its left subtree to see if we can find a smaller one.
				candidate = cur;
				cur = cur->left;
			}
		}
		
		return candidate;
		// return helper(root, nullptr, p);
	}

private:
	/*
	 * Recursive
	 */
	TreeNode *helper(TreeNode *node, TreeNode *parent, TreeNode *target) {
		if (node == nullptr) {
			return nullptr;
		}
		
		if (target->val == node->val) {
			if (node->right != nullptr) {
				auto nextNode = node->right;
				while (nextNode->left != nullptr) {
					nextNode = nextNode->left;
				}
				return nextNode;
			} else {
				return parent;
			}
		} else if (target->val < node->val) {
			return helper(node->left, node, target);
		} else {
			return helper(node->right, parent, target);
		}
	}
};