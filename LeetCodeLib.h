

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

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;
	
	Node() {}
	
	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

struct ListNode {
	int val;
	ListNode *next;
	
	ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
static void PrintVector(vector<T>& arr) {
	for (const auto &item : arr) {
		cout << item << " ";
	}
	cout << endl;
}

template<class T>
static void PrintVectorVector(vector<vector<T>>& arr) {
	for (const auto &row : arr) {
		for (const auto &item : row) {
			cout << item << " ";
		}
		cout << endl;
	}
}

#endif //LEETCODE_LEETCODELIB_H
