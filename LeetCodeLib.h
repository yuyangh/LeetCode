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
#include <iomanip>

using namespace std;
ifstream INPUT_FILE("../temp.txt");

static string GenerateSpaces(int n) {
	string spaces;
	for (int i = 0; i < n; ++i) {
		spaces += ' ';
	}
	return spaces;
}

/*
 * calculate the maximum height of the tree
 */
template <class T>
static int TreeHeight(T *node);

/*
 * print the tree out nicely,
 * the gap between %d is space_width spaces, default value is 2
 *       %d
 *   %d      %d
 * %d  %d  %d  %d
 */
template <class T>
static void PrintTree(T *root, int space_width=2);


class Node {
public:
	int val = -1;
	Node *left = nullptr;
	Node *right = nullptr;
	Node *next = nullptr;
	
	Node() : val(-1), right(nullptr), left(nullptr), next(nullptr) {}
	
	explicit Node(int val) : val(val), right(nullptr), left(nullptr), next(nullptr) {}
	
	Node(int _val, Node *_left, Node *_right, Node *_next) :
			val(_val), left(_left), right(_right), next(_next) {}
			
private:
	
};

struct ListNode {
	int val;
	ListNode *next;
	
	explicit ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
	int val = -1;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;
	
	explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
private:
	
};

template<class T>
static void PreOrderRecursiveTraversal(T *node, vector<int> &result) {
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

/*
 * calculate the maximum height of the tree
 */
template <class T>
static int TreeHeight(T *node) {
	if (node == nullptr) {
		return 0;
	}
	int left = TreeHeight(node->left);
	int right = TreeHeight(node->right);
	return max(left, right) + 1;
}

/*
 * print the tree out nicely
 *       %d
 *   %d      %d
 * %d  %d  %d  %d
 */
template <class T>
static void PrintTree(T *root, int space_width) {
	queue<T *> current_level;
	queue<T *> next_level;
	
	current_level.push(root);
	int level = 0;
	int height = TreeHeight(root);
	string spaces = GenerateSpaces(space_width);
	
	while (!current_level.empty()) {
		++level;
		
		// print out the left spaces
		int left_spaces = static_cast<int>(pow(2, height - level)) - 1;
		for (int left_space = 0; left_space < left_spaces; ++left_space) {
			cout << spaces;
		}
		
		// print out values and middle spaces
		while (!current_level.empty() && level <= height) {
			auto node = current_level.front();
			current_level.pop();
			
			// print out values, nullptr also needs spaces
			if (node != nullptr) {
				cout << setw(space_width) << setfill('0') << node->val;
				next_level.push(node->left);
				next_level.push(node->right);
			} else {
				cout << spaces;
				next_level.push(nullptr);
				next_level.push(nullptr);
			}
			flush(cout);
			
			// print out middle spaces
			int middle_spaces = 2 * left_spaces + 1;
			for (int middle_space = 0; middle_space < middle_spaces; ++middle_space) {
				cout << spaces;
			}
		}
		swap(current_level, next_level);
		cout << endl;
		if (level > height) {
			break;
		}
	}
}

#endif //LEETCODE_LEETCODELIB_H
