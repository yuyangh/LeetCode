#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (33.13%)
 * Likes:    848
 * Dislikes: 73
 * Total Accepted:    185.2K
 * Total Submissions: 557.5K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 *
 * Example 1:
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 *
 *
 * Example 2:
 * Input: 1->1->1->2->3
 * Output: 2->3
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == nullptr) {
			return head;
		}
		// number of nodes need to be deleted
		int del = 0;
		ListNode *newHead = head, *node = head, *nextNode, *prev = nullptr;
		while (node != nullptr) {
			nextNode = node->next;
			// check duplicate
			if (nextNode != nullptr) {
				if (node->val == nextNode->val) {
					del = 2;
				}
			}
			if (del) {
				--del;
				// deal with head
				if (newHead == node) {
					newHead = nextNode;
				} else {
					// update the linked list
					prev->next = nextNode;
				}
				delete node;
			} else {
				// update prev only when the node is not going to be deleted
				prev = node;
			}
			node = nextNode;
		}
		return newHead;
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

string listNodeToString(ListNode *node) {
	if (node == nullptr) {
		return "[]";
	}
	
	string result;
	while (node) {
		result += to_string(node->val) + ", ";
		node = node->next;
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		ListNode *head = stringToListNode(line);
		
		ListNode *ret = Solution().deleteDuplicates(head);
		
		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}

