//
// Created by Yuyang Huang on 8/26/21.
//

/*
 * 199. Binary Tree Right Side View
 * Medium
 *
 * Given the root of a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 *
 * Example 1:
 * Input: root = [1,2,3,null,5,null,4]
 * Output: [1,3,4]
 *
 * Example 2:
 * Input: root = [1,null,3]
 * Output: [1,3]
 *
 * Example 3:
 * Input: root = []
 * Output: []
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 */

#include "LeetCodeLib.h"

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
	 * recursively discovering right nodes first
	 */
	vector<int> rightSideView(TreeNode *root) {
		vector<int> values;
		helper(root, 0, values);
		return values;
	}
	
	void helper(TreeNode *node, int level, vector<int> &values) {
		if (node == nullptr) {
			return;
		}
		if (values.size() == level) {
			values.push_back(node->val);
		}
		helper(node->right, level + 1, values);
		helper(node->left, level + 1, values);
		
	}
};