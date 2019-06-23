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
 *
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
 *
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
	vector<vector<int>> result;
	
	vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
		traverse(root, 0);
		for (int level = 1; level < result.size(); level += 2) {
			reverse(result[level].begin(), result[level].end());
		}
		return result;
	}
	
	// use queue to store one level nodes
	// use queue size [queue.size() - 1 - i]
	// to store nodes' values in reverse order if needed
	vector<vector<int> > zigzagLevelOrderRef(TreeNode *root) {
		if (root == NULL) {
			return vector<vector<int> >();
		}
		vector<vector<int> > result;
		
		queue<TreeNode *> nodesQueue;
		nodesQueue.push(root);
		bool leftToRight = true;
		
		while (!nodesQueue.empty()) {
			int size = nodesQueue.size();
			// allocate the size of the row
			vector<int> row(size);
			for (int i = 0; i < size; i++) {
				TreeNode *node = nodesQueue.front();
				nodesQueue.pop();
				
				// find position to fill node's value
				int index = (leftToRight) ? i : (size - 1 - i);
				
				row[index] = node->val;
				if (node->left) {
					nodesQueue.push(node->left);
				}
				if (node->right) {
					nodesQueue.push(node->right);
				}
			}
			// after this level
			leftToRight = !leftToRight;
			result.push_back(row);
		}
		return result;
	}
	
	// use reverse
	void traverse(TreeNode *node, int level) {
		if (node == nullptr) {
			return;
		}
		if (level >= result.size()) {
			result.emplace_back(vector<int>(1, node->val));
		} else {
			result[level].emplace_back(node->val);
		}
		traverse(node->left, level + 1);
		traverse(node->right, level + 1);
	}
};

