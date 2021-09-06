//
// Created by Yuyang Huang on 9/6/21.
//

/*
 * 791. Custom Sort String
 * Medium
 * You are given two strings order and s.
 * All the words of order are unique and were sorted in some custom order previously.
 * Permute the characters of s so that they match the order that order was sorted.
 * More specifically, if a character x occurs before a character y in order,
 * then x should occur before y in the permuted string.
 *
 * Return any permutation of s that satisfies this property.
 *
 * Example 1:
 * Input: order = "cba", s = "abcd"
 * Output: "cbad"
 * Explanation:
 * "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".
 * Since "d" does not appear in order, it can be at any position in the returned string.
 * "dcba", "cdba", "cbda" are also valid outputs.
 *
 * Example 2:
 * Input: order = "cbafg", s = "abcd"
 * Output: "cbad"
 *
 * Constraints:
 * 1 <= order.length <= 26
 * 1 <= s.length <= 200
 * order and s consist of lowercase English letters.
 * All the characters of order are unique.
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(nlogn)
	 * Better approach: bucket sort with counting
	 */
	string customSortString(string order, string s) {
		vector<int> dic(26,100);
		for(int i=0;i<order.size();i++){
			char letter=order[i];
			dic[letter-'a']=i;
		}
		
		sort(s.begin(),s.end(),[&dic](char lhs, char rhs){
			return dic[lhs-'a']<dic[rhs-'a'];
		});
		return s;
	}
};