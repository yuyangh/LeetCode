#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (39.45%)
 * Likes:    878
 * Dislikes: 19
 * Total Accepted:    156.6K
 * Total Submissions: 394.9K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 *
 * Return the following binary tree:
 *
 *
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
	unordered_map<int, int> valueIndexMap;
	
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if (inorder.empty()) {
			return nullptr;
		}
		reverse(inorder.begin(), inorder.end()); // become inorder from right to left
		reverse(postorder.begin(), postorder.end()); // become preorder from right to left
		
		for (int i = 0; i < postorder.size(); i++) {
			valueIndexMap.emplace(inorder[i], i);
		}
		
		TreeNode *root;
		int index = 0;
		root = build(inorder, 0, inorder.size(), postorder, index);
		return root;
	}
	
	TreeNode *build(vector<int> &inorder, int start, int end, vector<int> &preorder, int &index) {
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
		TreeNode *node = new TreeNode(value);
		++index;
		if (start == end) {
			return node;
		}
		
		// build right and left
		TreeNode *right = build(inorder, start, position - 1, preorder, index);
		node->right = right;
		TreeNode *left = build(inorder, position + 1, end, preorder, index);
		node->left = left;
		return node;
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

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

string treeNodeToString(TreeNode *root) {
	if (root == nullptr) {
		return "[]";
	}
	
	string output = "";
	queue<TreeNode *> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode *node = q.front();
		q.pop();
		
		if (node == nullptr) {
			output += "null, ";
			continue;
		}
		
		output += to_string(node->val) + ", ";
		q.push(node->left);
		q.push(node->right);
	}
	return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> inorder = stringToIntegerVector(line);
		getline(cin, line);
		vector<int> postorder = stringToIntegerVector(line);
		
		TreeNode *ret = Solution().buildTree(inorder, postorder);
		
		string out = treeNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}