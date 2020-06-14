//
// Created by Yuyang Huang on 6/13/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (43.24%)
 * Likes:    2850
 * Dislikes: 138
 * Total Accepted:    313.4K
 * Total Submissions: 671.5K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 *
 * Example: 
 *
 *
 * You may serialize the following tree:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 *
 * as "[1,2,3,null,null,4,5]"
 *
 *
 * Clarification: The above format is the same as how LeetCode serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 *
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
 *
 */

// @lc code=start

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
	/*
	 * Encodes a tree to a single string.
	 * using in order traversal
	 */
	string serialize(TreeNode *root) {
		if (root == nullptr) {
			return "null,";
		}
		string curr = to_string(root->val);
		string left = serialize(root->left);
		string right = serialize(root->right);
		return curr + ',' + left + right;
	}
	
	// Decodes your encoded data to tree.
	TreeNode *deserialize(string data) {
		vector<string> nodeStrings = split(data);
		vector<TreeNode *> nodes;
		nodes.reserve(nodeStrings.size());
		
		for (const auto &nodeString : nodeStrings) {
			if (nodeString.empty()) {
				continue;
			}
			if (nodeString == "null") {
				nodes.emplace_back(nullptr);
			} else {
				int val = stoi(nodeString);
				auto node = new TreeNode(val);
				nodes.emplace_back(node);
			}
		}
		int idx = 0;
		
		return helper(idx, nodes);
	}

private:
	TreeNode *helper(int &idx, vector<TreeNode *> &nodes) {
		if (idx >= nodes.size()) {
			return nullptr;
		}
		
		auto root = nodes[idx];
		++idx;
		if (root == nullptr) {
			return root;
		}
		auto left = helper(idx, nodes);
		auto right = helper(idx, nodes);
		root->left = left;
		root->right = right;
		return root;
		
	}
	
	vector<string> split(string &data, string delim = ",") {
		size_t start = 0, delimPos = data.find_first_of(delim, start);
		vector<string> result;
		while (delimPos != string::npos) {
			result.emplace_back(data.substr(start, delimPos - start));
			start = delimPos + 1;
			delimPos = data.find_first_of(delim, start);
		}
		
		// add the last one
		result.emplace_back(data.substr(start));
		return result;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

int main() {
	Codec codec;
	auto root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	
	PrintTree(root);
	string serialized = codec.serialize(root);
	PrintSingleResult(serialized);
	PrintTree(codec.deserialize(serialized));
	
	Complete();
}
