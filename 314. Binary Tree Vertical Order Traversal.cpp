//
// Created by Yuyang Huang on 8/26/21.
//

/*
 * 314. Binary Tree Vertical Order Traversal
 * Medium
 *
 * Given the root of a binary tree, return the vertical order traversal of its nodes' values. 
 * (i.e., from top to bottom, column by column).
 * If two nodes are in the same row and column, the order should be from left to right.
 * 
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[9],[3,15],[20],[7]]
 * 
 * Example 2:
 * Input: root = [3,9,8,4,0,1,7]
 * Output: [[4],[9],[3,0,1],[8],[7]]
 * 
 * Example 3:
 * Input: root = [3,9,8,4,0,1,7,null,null,null,2,5]
 * Output: [[4],[9,5],[3,0,1],[8,2],[7]]
 *
 * Example 4:
 * Input: root = []
 * Output: []
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 */

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
#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * use BFS to ensure top nodes are recorded first
	 */
	vector <vector<int>> verticalOrder(TreeNode *root) {
		
		unordered_map<int, vector<int>> indexNodes;
		helper(root, indexNodes);
		
		vector <vector<int>> result;
		// get the range of index
		int minIdx = INT_MAX;
		for (auto &item:indexNodes) {
			minIdx = min(minIdx, item.first);
		}
		int maxIdx = INT_MIN;
		for (auto &item:indexNodes) {
			maxIdx = max(maxIdx, item.first);
		}
		
		for (int i = minIdx; i <= maxIdx; i++) {
			result.emplace_back(indexNodes[i]);
		}
		return result;
	}
	
	void helper(TreeNode *node, unordered_map<int, vector<int>> &indexNodes) {
		if (node == nullptr) { return; }
		
		queue <pair<TreeNode *, int>> nodeOrderQueue;
		nodeOrderQueue.push(make_pair(node, 0));
		
		while (!nodeOrderQueue.empty()) {
			auto curr = nodeOrderQueue.front();
			nodeOrderQueue.pop();
			if (curr.first != nullptr) {
				indexNodes[curr.second].push_back(curr.first->val);
				nodeOrderQueue.push(make_pair(curr.first->left, curr.second - 1));
				nodeOrderQueue.push(make_pair(curr.first->right, curr.second + 1));
			}
		}
	}
};