/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define NULL nullptr

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode *front=head,*prev=head,*curr=head,*temp=head,*start,*end;
		
		// go to the pos that need reverse
		for(int i=0;i<m-1;i++){
			front=curr;
			curr=curr->next;
		}
		end=curr;
		
		// do the reverse
		// curr goes to the one after the start of the reverse
		// prev is at the start of the reverse
		for(int i=0;i<n-m+1;i++){
			temp=curr->next;
			curr->next=prev;
			prev=curr;
			curr=temp;
		}
		
		// re-link together
		if(m==1){
			head=prev;
		}else{
			front->next=prev;
		}
		
		end->next=curr;
		
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
		int m = stringToInteger(line);
		getline(cin, line);
		int n = stringToInteger(line);
		
		ListNode *ret = Solution().reverseBetween(head, m, n);
		
		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}