#include "LeetCodeLib.h"

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
	ListNode *partition(ListNode *head, int x) {
		ListNode *smallHead = nullptr, *smallTail = nullptr,
				*largeHead = nullptr, *largeTail = nullptr,
				*ptr = head;
		
		if (ptr == nullptr) {
			return ptr;
		}
		while (ptr != nullptr) {
			if (ptr->val < x) {
				if (smallHead == nullptr) {
					smallHead = ptr;
					smallTail = ptr;
				} else {
					smallTail->next = ptr;
					smallTail = ptr;
				}
			} else {
				if (largeHead == nullptr) {
					largeHead = ptr;
					largeTail = ptr;
				} else {
					largeTail->next = ptr;
					largeTail = ptr;
				}
			}
			ptr = ptr->next;
		}
		
		if (smallHead == nullptr) {
			return largeHead;
		} else {
			smallTail->next = largeHead;
			// handle the end of the list!
			if (largeTail != nullptr) {
				largeTail->next = nullptr;
			}
			return smallHead;
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
		int x = stringToInteger(line);
		
		ListNode *ret = Solution().partition(head, x);
		
		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}