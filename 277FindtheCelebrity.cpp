//
// Created by Yuyang Huang on 10/28/19.
//

/*
 * Suppose you are at a party with n people (labeled from 0 to n - 1) and among them,
 * there may exist one celebrity.
 * The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.
 * Now you want to find out who the celebrity is or verify that there is not one.
 * The only thing you are allowed to do is to ask questions like:
 * "Hi, A. Do you know B?" to get information of whether A knows B.
 * You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).
 * You are given a helper function bool knows(a, b) which tells you whether A knows B.
 * Implement a function int findCelebrity(n). There will be exactly one celebrity if he/she is in the party.
 * Return the celebrity's label if there is a celebrity in the party.
 * If there is no celebrity, return -1.
 */

/*
 * Input: graph = [
 * [1,1,0],
 * [0,1,0],
 * [1,1,1]
 * ]
 * Output: 1
 * Explanation: There are three persons labeled with 0, 1 and 2. graph[i][j] = 1 means
 * person i knows person j, otherwise graph[i][j] = 0 means person i does not know person j.
 * The celebrity is the person labeled as 1 because both 0 and 2 know him but 1 does not know anybody.
 */

#include "LeetCodeLib.h"

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
	/*
	 * time complexity: O(n)
	 * if a knows b, a is not celebrity, else b is not celebrity
	 */
	int findCelebrity(int n) {
		if (n == 1) {
			return 1;
		}
		
		// save the celebrity
		list<int> celebrities;
		for (int i = 0; i < n; ++i) {
			celebrities.emplace_back(i);
		}
		
		list<int>::iterator curr;
		while (celebrities.size() > 1) {
			curr = celebrities.begin();
			auto next = curr++;
			if (knows(*curr, *(next))) {
				celebrities.erase(curr);
			} else {
				celebrities.erase(next);
			}
		}
		
		// check celebrity knows no one,
		// every one knows celebrity
		curr = celebrities.begin();
		for (int i = 0; i < n; ++i) {
			if (i != *curr && knows(*curr, i)) {
				return -1;
			}
			if (!knows(i, *curr)) {
				return -1;
			}
		}
		return *curr;
	}
};