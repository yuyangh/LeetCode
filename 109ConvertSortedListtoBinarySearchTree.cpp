#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (40.96%)
 * Likes:    1036
 * Dislikes: 68
 * Total Accepted:    179.3K
 * Total Submissions: 435.5K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 *
 * Example:
 * Given the sorted linked list: [-10,-3,0,5,9],
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
	TreeNode *sortedListToBST(ListNode *head) {
		int size = 0;
		ListNode *temp = head;
		// get the size of the list
		while (temp != nullptr) {
			temp = temp->next;
			++size;
		}
		TreeNode *root;
		root = build(head, 0, size);
		return root;
	}

private:
	// O(n) time complexity
	TreeNode *build(ListNode *&node, int start, int end) {
		if (start > end) {
			return nullptr;
		}
		if (start == end) {
			if (node == nullptr) {
				return nullptr;
			}
			TreeNode *treeNode = new TreeNode(node->val);
			node = node->next;
			return treeNode;
		}
		
		int mid = (start + end) / 2;
		
		// build the left subtree
		auto left = build(node, start, mid - 1);
		
		// build the node self
		TreeNode *treeNode = new TreeNode(node->val);
		treeNode->left = left;
		
		// build from the next
		node = node->next;
		
		// build the right subtree
		auto right = build(node, mid + 1, end);
		treeNode->right = right;
		
		return treeNode;
	}
	
	// O(nlogn) time complexity
	// fast and slow pointer approach
	TreeNode *sortedListToBST(ListNode *head, ListNode *tail) {
		if (head == tail) {
			return nullptr;
		}
		if (head->next == tail) {
			TreeNode *root = new TreeNode(head->val);
			return root;
		}
		ListNode *mid = head, *temp = head;
		
		// find the middle element
		while (temp != tail && temp->next != tail) {
			mid = mid->next;
			temp = temp->next->next;
		}
		TreeNode *root = new TreeNode(mid->val);
		
		// build left and right subtree
		root->left = sortedListToBST(head, mid);
		root->right = sortedListToBST(mid->next, tail);
		return root;
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

ListNode *stringToListNode(string input) {
	// Generate list from the input
	vector<int> list = stringToIntegerVector(input);
	
	// Now convert that list into linked list
	ListNode *dummyRoot = new ListNode(0);
	ListNode *ptr = dummyRoot;
	for (int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
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
		ListNode *head = stringToListNode(line);
		
		TreeNode *ret = Solution().sortedListToBST(head);
		
		string out = treeNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}