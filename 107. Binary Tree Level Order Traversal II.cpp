#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (46.92%)
 * Likes:    756
 * Dislikes: 144
 * Total Accepted:    234.6K
 * Total Submissions: 495.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * return its bottom-up level order traversal as:
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
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
	 * first traverse top to bottom, then reverse
	 */
	vector<vector<int>> levelOrderBottom(TreeNode *root) {
		vector<vector<int>> result;
		traverse(result, root, 0);
		// reverse operation is O(logn) because the height of the tree is log(n)
		reverse(result.begin(), result.end());
		return result;
	}

private:
	void traverse(vector<vector<int>> &result, TreeNode *node, int level) {
		// base case
		if (node == nullptr) {
			return;
		}
		
		// add another level
		if (level >= result.size()) {
			result.emplace_back();
		}
		result[level].emplace_back(node->val);
		
		traverse(result, node->left, level + 1);
		traverse(result, node->right, level + 1);
	}
};

int main() {
	vector<TreeNode *> nodes;
	int num = 10;
	nodes.reserve(num);
	for (int i = 0; i < num; ++i) {
		nodes.push_back(new TreeNode(i+1));
	}
	
	nodes[0]->left = nodes[1];
	nodes[0]->right = nodes[2];
	nodes[2]->right = nodes[3];
	PrintTree(nodes[0]);
	
	Solution solution;
	auto result = solution.levelOrderBottom(nodes[0]);
	PrintVectorVector(result);
	return 0;
}

