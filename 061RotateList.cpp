#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (27.21%)
 * Likes:    631
 * Dislikes: 823
 * Total Accepted:    198.2K
 * Total Submissions: 723.7K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, rotate the list to the right by k places, where k is
 * non-negative.
 *
 * Example 1:
 *
 *
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 * Explanation:
 * rotate 1 steps to the right: 5->1->2->3->4->NULL
 * rotate 2 steps to the right: 4->5->1->2->3->NULL
 *
 *
 * Example 2:
 *
 *
 * Input: 0->1->2->NULL, k = 4
 * Output: 2->0->1->NULL
 * Explanation:
 * rotate 1 steps to the right: 2->0->1->NULL
 * rotate 2 steps to the right: 1->2->0->NULL
 * rotate 3 steps to the right: 0->1->2->NULL
 * rotate 4 steps to the right: 2->0->1->NULL
 *
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
	ListNode *rotateRight(ListNode *head, int k) {
		if (head == nullptr || k == 0) {
			return head;
		}
		new_head_ = head;
		target_ = k;
		
		// get the size of the list
		int list_size;
		size_ = 0;
		recursion(head);
		list_size = size_;
		
		
		if (list_size == k) {
			return pivot_;
		}
		// get the target
		if (list_size < k) {
			size_ = 0;
			target_ = k % list_size;
			if (target_ == 0) {
				return head;
			}
			recursion(head);
		}
		
		// modify the list
		new_head_ = pivot_;
		tail_->next = head;
		prev_->next = nullptr;
		
		return new_head_;
	}

private:
	int size_ = 0;
	int target_ = 0;
	ListNode *pivot_ = nullptr;
	ListNode *prev_ = nullptr;
	ListNode *tail_ = nullptr;
	ListNode *new_head_;
	
	// get the size, pivot, and node before pivot
	void recursion(ListNode *node) {
		if (node != nullptr) {
			recursion(node->next);
			if (node->next == nullptr) {
				tail_ = node;
			}
			++size_;
			if (size_ == target_) {
				pivot_ = node;
			}
			if (size_ == target_ + 1) {
				prev_ = node;
			}
			return;
		}
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

int stringToInteger(string input) {
	return stoi(input);
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
		getline(cin, line);
		int k = stringToInteger(line);
		
		ListNode *ret = Solution().rotateRight(head, k);
		
		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}