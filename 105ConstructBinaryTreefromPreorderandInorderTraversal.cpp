#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (41.30%)
 * Likes:    1760
 * Dislikes: 50
 * Total Accepted:    229.1K
 * Total Submissions: 552K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 *
 * Return the following binary tree:
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if (preorder.empty()) {
			return nullptr;
		}
		// record the value index mapping for in order traversal
		for (int i = 0; i < inorder.size(); ++i) {
			valueIndexMap.emplace(inorder[i], i);
		}
		TreeNode *root;
		int index = 0;
		root = build(preorder, 0, preorder.size() - 1, inorder, index);
		return root;
	}
	
	/*
	 * The basic idea is here:
	 * Say we have 2 arrays, PRE and IN.
	 * Preorder traversing implies that PRE[0] is the root node.
	 * Then we can find this PRE[0] in IN, say it's IN[5].
	 * Now we know that IN[5] is root, so we know that IN[0] - IN[4] is on the left side,
	 * IN[6] to the end is on the right side.
	 * Recursively doing this on subarrays, we can build a tree out of it :)
	 */
	TreeNode *build(vector<int> &preorder, int start, int end, vector<int> &inorder, int &index) {
		if (index >= preorder.size()) {
			return nullptr;
		}
		
		// the node we use must in the range
		int value = preorder[index];
		int position = valueIndexMap[value];
		if (position < start || position > end) {
			return nullptr;
		}
		
		// at the leaf
		auto *node = new TreeNode(value);
		++index;
		if (start == end) {
			return node;
		}
		
		// build left and right
		TreeNode *left = build(preorder, start, position - 1, inorder, index);
		TreeNode *right = build(preorder, position + 1, end, inorder, index);
		node->left = left;
		node->right = right;
		return node;
	}

private:
	unordered_map<int, int> valueIndexMap;
};

int main() {
	vector<int> preorder = {2, 1, 3};
	vector<int> inorder = {1, 2, 3};
	
	preorder = {6, 5, 2, 1, 3, 4, 7};
	inorder = {1, 2, 3, 4, 5, 6, 7};
	
	// preorder = {5, 3, 2, 1, 4, 8, 7, 9};
	// inorder = {1, 2, 3, 4, 5, 7, 8, 9};
	
	// preorder = {3, 9, 20, 15, 7};
	// inorder = {9, 3, 15, 20, 7};
	
	// preorder = {1, 2};
	// inorder = {2, 1};
	
	Solution solution;
	auto tree = solution.buildTree(preorder, inorder);
	vector<int> result;
	PreOrderRecursiveTraversal(tree, result);
	for (const auto &item : result) {
		cout << item << " ";
	}
	cout << endl;
}

