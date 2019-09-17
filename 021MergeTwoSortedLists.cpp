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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode dummy(INT_MIN);
		ListNode *tail = &dummy;
		
		// check either list reach the end
		while (l1 && l2) {
			if (l1->val < l2->val) {
				tail->next = l1;
				l1 = l1->next;
			} else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}
		
		// connect non-empty list at the tail
		tail->next = l1 ? l1 : l2;
		return dummy.next;
	}
	
	// code written initially
	ListNode *mergeTwoListsInitial(ListNode *l1, ListNode *l2) {
		ListNode *head = nullptr, *tail = head;
		ListNode *l1ptr = l1, *l2ptr = l2;
		if (l1 != nullptr && l2 == nullptr) {
			return l1;
		}
		if (l1 == nullptr && l2 != nullptr) {
			return l2;
		}
		if (l1 == nullptr && l2 == nullptr) {
			return nullptr;
		}
		
		// two pointers go through the list
		while (l1ptr != nullptr || l2ptr != nullptr) {
			if (l1ptr != nullptr && l2ptr == nullptr) {
				tail->next = l1ptr;
				break;
			}
			if (l1ptr == nullptr && l2ptr != nullptr) {
				tail->next = l2ptr;
				break;
			}
			if (l1ptr->val < l2ptr->val) {
				// handle head and tail situations differently
				if (!head) {
					head = l1ptr;
					tail = head;
				} else {
					tail->next = l1ptr;
					tail = l1ptr;
				}
				l1ptr = l1ptr->next;
				
			} else {
				if (!head) {
					head = l2ptr;
					tail = head;
				} else {
					tail->next = l2ptr;
					tail = l2ptr;
					
				}
				l2ptr = l2ptr->next;
				
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

int main() {
	string line;
	while (getline(cin, line)) {
		ListNode *l1 = stringToListNode(line);
		getline(cin, line);
		ListNode *l2 = stringToListNode(line);
		
		ListNode *ret = Solution().mergeTwoLists(l1, l2);
		
		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}