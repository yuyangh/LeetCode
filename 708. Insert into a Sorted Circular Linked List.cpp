//
// Created by Yuyang Huang on 8/25/21.
//

/*
 * 708. Insert into a Sorted Circular Linked List
 * Medium
 *
 * Given a Circular Linked List node, which is sorted in ascending order,
 * write a function to insert a value insertVal into the list such that it remains a sorted circular list.
 * The given node can be a reference to any single node in the list
 * and may not necessarily be the smallest value in the circular list.
 *
 * If there are multiple suitable places for insertion, you may choose any place to insert the new value.
 * After the insertion, the circular list should remain sorted.
 *
 * If the list is empty (i.e., the given node is null),
 * you should create a new single circular list and return the reference to that single node.
 * Otherwise, you should return the originally given node.
 *
 * Example 1:
 * Input: head = [3,4,1], insertVal = 2
 * Output: [3,4,1,2]
 * Explanation: In the figure above, there is a sorted circular list of three elements.
 * You are given a reference to the node with value 3, and we need to insert 2 into the list.
 * The new node should be inserted between node 1 and node 3. After the insertion, the list should look like this,
 * and we should still return node 3.
 *
 * Example 2:
 * Input: head = [], insertVal = 1
 * Output: [1]
 * Explanation: The list is empty (given head is null).
 * We create a new single circular list and return the reference to that single node.
 *
 * Example 3:
 * Input: head = [1], insertVal = 0
 * Output: [1,0]
 *
 * Constraints:
 * 0 <= Number of Nodes <= 5 * 104
 * -106 <= Node.val, insertVal <= 106
 */

#include "LeetCodeLib.h"

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
	/*
	 * Time complexity: O(n)
	 */
	Node *insert(Node *head, int insertVal) {
		if (head == nullptr) {
			Node *node = new Node(insertVal);
			node->next = node;
			return node;
		}
		
		Node *curr = head, *next = head->next;
		bool insert = false;
		Node *node = new Node(insertVal);
		do {
			// insert when:
			// 1. curr <= insertVal <= next
			// 2. insertVal > max (insert at the tail)
			// 3. insertVal < min (insert at the tail)
			if (curr->val <= insertVal && insertVal <= next->val) { insert = true; }
			if (curr->val <= insertVal && insertVal > next->val && curr->val > next->val) { insert = true; }
			if (curr->val >= insertVal && insertVal < next->val && next->val < curr->val) { insert = true; }
			
			if (insert) {
				curr->next = node;
				node->next = next;
				break;
			}
			curr = next;
			next = next->next;
			
			if (curr == head) { break; }
		} while (true);
		
		// The only reason why `value` was not inserted is that
		// all values in the list are the same and are not equal to `value`.
		// So, we could insert `value` anywhere.
		if (!insert) {
			curr->next = node;
			node->next = next;
		}
		
		return head;
	}
};
