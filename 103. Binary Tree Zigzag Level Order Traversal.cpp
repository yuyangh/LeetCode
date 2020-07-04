#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (41.87%)
 * Likes:    980
 * Dislikes: 60
 * Total Accepted:    225.1K
 * Total Submissions: 535.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
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
	 * use reverse method to get the result
	 */
	vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> result;
		traverse(result, root, 0);
		
		// reverse even levels
		for (int level = 1; level < result.size(); level += 2) {
			reverse(result[level].begin(), result[level].end());
		}
		return result;
	}
	
	/*
	 * use reverse
	 */
	void traverse(vector<vector<int>> &result, TreeNode *node, int level) {
		if (node == nullptr) {
			return;
		}
		if (level >= result.size()) {
			result.emplace_back(vector<int>(1, node->val));
		} else {
			result[level].emplace_back(node->val);
		}
		traverse(result, node->left, level + 1);
		traverse(result, node->right, level + 1);
	}
	
	/*
	 * only result will be reverted for odd even line
	 * discover order does not change
	 */
	vector<vector<int> > zigzagLevelOrderBFS(TreeNode *root) {
		if (root == nullptr) {
			return {};
		}
		
		queue<TreeNode *> nodeQueue;
		
		// initial node
		vector<vector<int>> result;
		nodeQueue.emplace(root);
		
		int height = 0;
		while (!nodeQueue.empty()) {
			// number of elements to search for this level
			size_t size = nodeQueue.size();
			vector<int> row(size, 0);
			
			for (size_t i = 0; i < size; ++i) {
				TreeNode *node = nodeQueue.front();
				nodeQueue.pop();
				if (node != nullptr) {
					if (node->left != nullptr) {
						nodeQueue.emplace(node->left);
					}
					if (node->right != nullptr) {
						nodeQueue.emplace(node->right);
					}
					size_t index;
					
					// decide to put in from left to right or reverse
					if (height % 2 == 0) {
						index = i;
					} else {
						index = size - 1 - i;
					}
					row[index] = node->val;
				}
			}
			result.emplace_back(row);
			height++;
		}
		return result;
	}
};

