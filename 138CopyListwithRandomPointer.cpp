//
// Created by Yuyang Huang on 10/23/19.
//

// #include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (29.69%)
 * Likes:    2016
 * Dislikes: 508
 * Total Accepted:    294.6K
 * Total Submissions: 990.3K
 * Testcase Example:  '{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}'
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 *
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input:
 *
 * {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
 *
 * Explanation:
 * Node 1's value is 1, both of its next and random pointer points to Node 2.
 * Node 2's value is 2, its next pointer points to null and its random pointer
 * points to itself.
 *
 *
 *
 *
 * Note:
 *
 *
 * You must return the copy of the given head as a reference to the cloned
 * list.
 *
 *
 */

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
#include <list>
#include <unordered_set>
#include <fstream>
#include <iomanip>

using namespace std;

// @lc code=start
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if(head==nullptr){
			return head;
		}
		Node* node=head;
		
		// for each node in the list, copy the node and append to the current one without random pointer
		while(node!= nullptr){
			Node* copy=new Node(node->val,node->next, nullptr);
			node->next=copy;
			node=copy->next;
		}
		
		// copy the random pointer
		node=head;
		while(node!= nullptr){
			// because node's random is default to nullptr,
			// so only need to change for not nullptr case
			if(node->random!= nullptr){
				node->next->random=node->random->next;
			}
			
			// go to next original list's node
			node=node->next->next;
		}
		
		// create a dummy node that linked to new list
		Node* dummy=new Node(-1, nullptr, nullptr);
		Node* lastNode=dummy;
		
		node=head;
		while(node!= nullptr){
			// un-weave the list
			lastNode->next=node->next;
			node->next=node->next->next;
			
			// go to next orginal list's node and new list's node
			node=node->next;
			lastNode=lastNode->next;
		}
		return dummy->next;
	}
};
// @lc code=end

int main(){
	Node* a=new Node();
	Node* b=new Node();
	
	a->val=1;
	b->val=2;
	
	a->next=b;
	b->next= nullptr;
	
	a->random=b;
	b->random=b;
	
	Solution solution;
	auto result=solution.copyRandomList(a);
	cout<<result->val<<endl;
	
	return 0;
}



