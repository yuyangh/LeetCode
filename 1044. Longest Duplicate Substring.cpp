//
// Created by Yuyang Huang on 6/19/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=1044 lang=cpp
 *
 * [1044] Longest Duplicate Substring
 *
 * https://leetcode.com/problems/longest-duplicate-substring/description/
 *
 * algorithms
 * Hard (23.67%)
 * Likes:    413
 * Dislikes: 177
 * Total Accepted:    18.2K
 * Total Submissions: 61.5K
 * Testcase Example:  '"banana"'
 *
 * Given a string S, consider all duplicated substrings: (contiguous)
 * substrings of S that occur 2 or more times.  (The occurrences may overlap.)
 *
 * Return any duplicated substring that has the longest possible length.  (If S
 * does not have a duplicated substring, the answer is "".)
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "banana"
 * Output: "ana"
 *
 *
 * Example 2:
 *
 *
 * Input: "abcd"
 * Output: ""
 *
 *
 *
 *
 * Note:
 *
 *
 * 2 <= S.length <= 10^5
 * S consists of lowercase English letters.
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(nlogn)
 * use binary search + rolling hash
 * rolling hash can hash in O(1)
 */
class Solution {
public:
	string longestDupSubstring(string S) {
		int low = 0, high = S.size(), mid;
		string duplicateStr, result;
		while (low < high) {
			mid = (low + high) / 2;
			duplicateStr = findDuplicate(S, mid);
			if (!duplicateStr.empty()) {
				result = duplicateStr;
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		return result;
	}

private:
	const unsigned int base = 26;
	
	string findDuplicate(string &s, int length) {
		unordered_set<unsigned long long> seenHashedSet;
		
		unsigned long long hashValue = 0, modulus = ULONG_LONG_MAX>>5;
		
		// calculate the hash value for the first string, a* 26^(length-1) + b*26^(length-2) + ...
		for (int idx = 0; idx < length; ++idx) {
			hashValue = (hashValue * base + (s[idx] - 'a')) % modulus;
		}
		seenHashedSet.emplace(hashValue);
		
		// calculate the leading term
		unsigned long long leadingTerm = 1;
		for (int i = 1; i <= length; ++i) {
			leadingTerm = (leadingTerm * base) % modulus;
		}
		
		// do rolling hash
		for (int i = 1; i + length <= s.size(); ++i) {
			// remove previous leading term and add the new one
			hashValue = (hashValue * base - (s[i - 1] - 'a') * leadingTerm % modulus + modulus) % modulus;
			hashValue = (hashValue + s[i + length - 1] - 'a') % modulus;
			
			if (seenHashedSet.count(hashValue) == 0) {
				seenHashedSet.emplace(hashValue);
			} else {
				return s.substr(i, length);
			}
		}
		return "";
	}
};
// @lc code=end

int main() {
	Solution solution;
	PrintSingleResult(solution.longestDupSubstring("banana"));
	PrintSingleResult(solution.longestDupSubstring("aabaaaab"));
	
	Complete();
}