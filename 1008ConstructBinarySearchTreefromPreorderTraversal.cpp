//
// Created by Yuyang Huang on 5/24/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
 *
 * algorithms
 * Medium (73.89%)
 * Likes:    1061
 * Dislikes: 35
 * Total Accepted:    107.9K
 * Total Submissions: 139K
 * Testcase Example:  '[8,5,1,7,10,12]'
 *
 * Return the root node of a binary search tree that matches the given preorder
 * traversal.
 *
 * (Recall that a binary search tree is a binary tree where for every node, any
 * descendant of node.left has a value < node.val, and any descendant of
 * node.right has a value > node.val.  Also recall that a preorder traversal
 * displays the value of the node first, then traverses node.left, then
 * traverses node.right.)
 *
 * It's guaranteed that for the given test cases there is always possible to
 * find a binary search tree with the given requirements.
 *
 * Example 1:
 *
 *
 * Input: [8,5,1,7,10,12]
 * Output: [8,5,10,1,7,null,12]
 *
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= preorder.length <= 100
 * 1 <= preorder[i] <= 10^8
 * The values of preorder are distinct.
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
 * time complexity: O(n)
 */
class Solution {
public:
	TreeNode *bstFromPreorder(vector<int> &preorder) {
		if (preorder.empty()) {
			return nullptr;
		}
		int index = 0;
		// return helper_recur(preorder, index, INT_MIN, INT_MAX);
		return helper_iter(preorder);
	}
	
	TreeNode *helper_iter(vector<int> &preorder) {
		stack<TreeNode *> nodes;
		TreeNode *root = new TreeNode(preorder[0]);
		// dummy node to enable stack non-empty
		nodes.push(new TreeNode(INT_MAX));
		nodes.push(root);
		
		for (int i = 1; i < preorder.size(); ++i) {
			TreeNode *node = new TreeNode(preorder[i]);
			if (preorder[i] < nodes.top()->val) {
				nodes.top()->left = node;
			} else {
				TreeNode *parent;
				// pop the stack to stop at the parent
				while (nodes.top()->val < node->val) {
					parent = nodes.top();
					nodes.pop();
				}
				parent->right = node;
			}
			nodes.push(node);
		}
		return root;
	}
	
	/**
	 * recursively construct new node that satisfy the subtree
	 * @param preorder the preorder array
	 * @param index index in the preorder array
	 * @param low lower bound of the value for the subtree
	 * @param high upper bound of the value for the subtree
	 * @return node of the tree
	 */
	TreeNode *helper_recur(vector<int> &preorder, int &index, int low, int high) {
		if (index >= preorder.size() || preorder[index] < low || preorder[index] > high) {
			return nullptr;
		}
		TreeNode *node = new TreeNode(preorder[index]);
		++index;
		node->left = helper_recur(preorder, index, low, node->val);
		node->right = helper_recur(preorder, index, node->val, high);
		return node;
	}
};
// @lc code=end

int main() {
	vector<int> preorder = {8, 5, 1, 7, 10, 12};
	Solution solution;
	auto result = solution.bstFromPreorder(preorder);
	PrintTree(result);
	Complete();
}
