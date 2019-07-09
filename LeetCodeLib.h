#ifndef LEETCODE_LEETCODELIB_H
#define LEETCODE_LEETCODELIB_H

#include <assert.h>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <numeric>

#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <fstream>

using namespace std;
ifstream INPUT_FILE("../temp.txt");

class Node {
public:
	int val = -1;
	Node *left = nullptr;
	Node *right = nullptr;
	Node *next = nullptr;
	
	Node() : val(-1), right(nullptr), left(nullptr), next(nullptr) {}
	
	explicit Node(int val) : val(val), right(nullptr), left(nullptr), next(nullptr) {}
	
	Node(int _val, Node *_left, Node *_right, Node *_next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
	
	static void levelOrder(vector<vector<int>> &result, Node *root) {
		levelOrder(result, root, 0);
	}

private:
	static void levelOrder(vector<vector<int>> &result, Node *node, int level) {
		if (node == nullptr) {
			return;
		}
		// add the vector for that level
		if (level >= result.size()) {
			result.emplace_back(vector<int>());
		}
		result[level].emplace_back(node->val);
		// add for the next level
		levelOrder(result, node->left, level + 1);
		levelOrder(result, node->right, level + 1);
	}
};

struct ListNode {
	int val;
	ListNode *next;
	
	ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
	int val = -1;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;
	
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
	static void levelOrder(vector<vector<int>> &result, TreeNode *root) {
		levelOrder(result, root, 0);
	}

private:
	static void levelOrder(vector<vector<int>> &result, TreeNode *node, int level) {
		if (node == nullptr) {
			return;
		}
		// add the vector for that level
		if (level >= result.size()) {
			result.emplace_back(vector<int>());
		}
		result[level].emplace_back(node->val);
		// add for the next level
		levelOrder(result, node->left, level + 1);
		levelOrder(result, node->right, level + 1);
	}
	
};

static void PreOrderRecursiveTraversal(TreeNode *node, vector<int> &result) {
	if (node == nullptr) {
		return;
	}
	result.emplace_back(node->val);
	PreOrderRecursiveTraversal(node->left, result);
	PreOrderRecursiveTraversal(node->right, result);
}


template<class T>
static void PrintSingleResult(T result) {
	cout << "Result:\t" << result << endl;
}

template<class T>
static void PrintVector(vector<T> &arr) {
	for (const auto &item : arr) {
		cout << item << " ";
	}
	cout << endl;
}

template<class T>
static void PrintVectorVector(vector<vector<T>> &arr) {
	for (const auto &row : arr) {
		for (const auto &item : row) {
			cout << item << " ";
		}
		cout << endl;
	}
}

#endif //LEETCODE_LEETCODELIB_H
