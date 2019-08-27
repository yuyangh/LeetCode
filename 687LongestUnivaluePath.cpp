#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Easy (34.07%)
 * Likes:    1028
 * Dislikes: 258
 * Total Accepted:    62.9K
 * Total Submissions: 184.3K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given a binary tree, find the length of the longest path where each node in
 * the path has the same value. This path may or may not pass through the
 * root.
 *
 * The length of path between two nodes is represented by the number of edges
 * between them.
 *
 * Example 1:
 * Input:
 *
 *
 * ⁠             5
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         1   1   5
 *
 *
 * Output: 2
 *
 * Example 2:
 * Input:
 *
 *
 * ⁠             1
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         4   4   5
 *
 *
 * Output: 2
 * Note: The given binary tree has not more than 10000 nodes. The height of the
 * tree is not more than 1000.
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
	int longestUnivaluePath(TreeNode *root) {
		recursion(root);
		return maxLength;
	}

private:
	int maxLength = 0;
	
	int recursion(TreeNode *node) {
		if (node == nullptr) {
			return 0;
		}
		
		int total_length = 0;
		int left_length = 0;
		int right_length = 0;
		
		if (node->left != nullptr) {
			if (node->val == node->left->val) {
				left_length += recursion(node->left) + 1;
			} else {
				recursion(node->left);
			}
		}
		if (node->right != nullptr) {
			if (node->val == node->right->val) {
				right_length += recursion(node->right) + 1;
			} else {
				recursion(node->right);
			}
		}
		
		// calculate node connect two sides
		total_length = left_length + right_length;
		if (total_length > maxLength) {
			maxLength = total_length;
		}
		
		// choose 1 path to connect to the parent node
		return max(left_length, right_length);
	}
};


void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

TreeNode *stringToTreeNode(string input) {
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	if (!input.size()) {
		return nullptr;
	}
	
	string item;
	stringstream ss;
	ss.str(input);
	
	getline(ss, item, ',');
	TreeNode *root = new TreeNode(stoi(item));
	queue<TreeNode *> nodeQueue;
	nodeQueue.push(root);
	
	while (true) {
		TreeNode *node = nodeQueue.front();
		nodeQueue.pop();
		
		if (!getline(ss, item, ',')) {
			break;
		}
		
		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int leftNumber = stoi(item);
			node->left = new TreeNode(leftNumber);
			nodeQueue.push(node->left);
		}
		
		if (!getline(ss, item, ',')) {
			break;
		}
		
		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int rightNumber = stoi(item);
			node->right = new TreeNode(rightNumber);
			nodeQueue.push(node->right);
		}
	}
	return root;
}

int main() {
	string line;
	while (getline(cin, line)) {
		TreeNode *root = stringToTreeNode(line);
		
		int ret = Solution().longestUnivaluePath(root);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}

