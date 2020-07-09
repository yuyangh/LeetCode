//
// Created by Yuyang Huang on 7/9/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
 *
 * https://leetcode.com/problems/maximum-width-of-binary-tree/description/
 *
 * algorithms
 * Medium (39.50%)
 * Likes:    1409
 * Dislikes: 281
 * Total Accepted:    73.8K
 * Total Submissions: 181.9K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * Given a binary tree, write a function to get the maximum width of the given
 * tree. The width of a tree is the maximum width among all levels. The binary
 * tree has the same structure as a full binary tree, but some nodes are null.
 *
 * The width of one level is defined as the length between the end-nodes (the
 * leftmost and right most non-null nodes in the level, where the null nodes
 * between the end-nodes are also counted into the length calculation.
 *
 * Example 1:
 *
 *
 * Input:
 *
 * ⁠          1
 * ⁠        /   \
 * ⁠       3     2
 * ⁠      / \     \
 * ⁠     5   3     9
 *
 * Output: 4
 * Explanation: The maximum width existing in the third level with the length 4
 * (5,3,null,9).
 *
 *
 * Example 2:
 *
 *
 * Input:
 *
 * ⁠         1
 * ⁠        /
 * ⁠       3
 * ⁠      / \
 * ⁠     5   3
 *
 * Output: 2
 * Explanation: The maximum width existing in the third level with the length 2
 * (5,3).
 *
 *
 * Example 3:
 *
 *
 * Input:
 *
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      /
 * ⁠     5
 *
 * Output: 2
 * Explanation: The maximum width existing in the second level with the length
 * 2 (3,2).
 *
 *
 * Example 4:
 *
 *
 * Input:
 *
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      /     \
 * ⁠     5       9
 * ⁠    /         \
 * ⁠   6           7
 * Output: 8
 * Explanation:The maximum width existing in the fourth level with the length 8
 * (6,null,null,null,null,null,null,7).
 *
 *
 *
 *
 * Note: Answer will in the range of 32-bit signed integer.
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
class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * DFS
	 */
	int widthOfBinaryTree(TreeNode *root) {
		if (root == nullptr) { return 0; }
		
		vector<pair<long long, long long>> widths;
		helper(root, 0, 0, widths);
		
		long long maxWidth = 1;
		for (const auto &width : widths) {
			maxWidth = max(maxWidth, width.second - width.first + 1);
		}
		
		return maxWidth;
	}
	
	void helper(TreeNode *node, int height, long long step, vector<pair<long long, long long>> &widths) {
		if (node == nullptr) {
			return;
		}
		
		// record a new layer
		if (height >= widths.size()) {
			widths.emplace_back(INT_MAX, INT_MIN);
		}
		
		widths[height].first = min(step, widths[height].first);
		widths[height].second = max(step, widths[height].second);
		
		helper(node->left, height + 1, step * 2, widths);
		// if left side does not exist, then right side does not need to explore
		if (widths[height].first != INT_MAX) {
			helper(node->right, height + 1, step * 2 + 1, widths);
		}
	}
};
// @lc code=end

