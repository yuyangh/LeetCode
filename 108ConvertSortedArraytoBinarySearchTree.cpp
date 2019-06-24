#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (50.92%)
 * Likes:    1178
 * Dislikes: 122
 * Total Accepted:    269K
 * Total Submissions: 525.8K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 *
 * Example:
 * Given the sorted array: [-10,-3,0,5,9],
 *
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 *
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
	TreeNode *sortedArrayToBST(vector<int> &nums) {
		if (nums.empty()) {
			return nullptr;
		}
		TreeNode *root;
		root = construct(nums, 0, nums.size() - 1);
		return root;
	}
	
	TreeNode *construct(vector<int> &nums, int start, int end) {
		// base case
		if (start > end) {
			return nullptr;
		}
		// process with self
		int mid = (start + end) / 2;
		TreeNode *node = new TreeNode(nums[mid]);
		
		// process with left and right
		TreeNode *left = construct(nums, start, mid - 1);
		node->left = left;
		TreeNode *right = construct(nums, mid + 1, end);
		node->right = right;
		return node;
	}
};

int main() {
	vector<int> arr = {1, 2, 3, 4, 5};
	
	arr = {-10, -3, 0, 5, 9};
	
	Solution solution;
	auto tree = solution.sortedArrayToBST(arr);
	vector<int> result;
	PreOrderRecursiveTraversal(tree, result);
	PrintVector(result);
	return 0;
}

