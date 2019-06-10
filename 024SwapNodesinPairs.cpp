#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (44.59%)
 * Likes:    1149
 * Dislikes: 102
 * Total Accepted:    318.7K
 * Total Submissions: 710.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 * Example:
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
	ListNode *swapPairs(ListNode *head) {
		if (head == nullptr) {
			return nullptr;
		}
		ListNode *curr = head, *nextNode, *nextCurr, *prev = nullptr;
		
		// go two pointers
		while (curr != nullptr) {
			nextNode = curr->next;
			if (nextNode != nullptr) {
				nextCurr = nextNode->next;
				// check header
				if (prev != nullptr) {
					prev->next = nextNode;
				} else {
					head = nextNode;
				}
				nextNode->next = curr;
				curr->next = nextCurr;
				prev = curr;
				curr = nextCurr;
			} else {
				return head;
			}
		}
		return head;
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