//
// Created by Yuyang Huang on 9/28/21.
//

/*
 * 1525. Number of Good Ways to Split a String
 * Medium
 *
 * You are given a string s, a split is called good if you can split s into 2 non-empty strings p and q
 * where its concatenation is equal to s and the number of distinct letters in p and q are the same.
 * Return the number of good splits you can make in s.
 *
 * Example 1:
 * Input: s = "aacaba"
 * Output: 2
 * Explanation: There are 5 ways to split "aacaba" and 2 of them are good.
 * ("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.
 * ("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.
 * ("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good split).
 * ("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good split).
 * ("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.
 *
 * Example 2:
 * Input: s = "abcd"
 * Output: 1
 * Explanation: Split the string as follows ("ab", "cd").
 *
 * Example 3:
 * Input: s = "aaaaa"
 * Output: 4
 * Explanation: All possible splits are good.
 *
 * Example 4:
 * Input: s = "acbadbaada"
 * Output: 2
 *
 * Constraints:
 * s contains only lowercase English letters.
 * 1 <= s.length <= 10^5
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(n)
	 */
	int numSplits(string s) {
		unordered_map<char, int> leftCharCountMap;
		unordered_map<char, int> rightCharCountMap;
		for (char c: s) {
			rightCharCountMap[c]++;
		}
		
		int result = 0;
		for (size_t i = 0; i < s.size(); i++) {
			char c = s[i];
			leftCharCountMap[c]++;
			rightCharCountMap[c]--;
			
			if (rightCharCountMap[c] == 0) {
				rightCharCountMap.erase(c);
			}
			if (leftCharCountMap.size() == rightCharCountMap.size()) {
				result += 1;
			}
		}
		return result;
	}
};

int main(){
	Solution solution;
	PrintSingleResult(solution.numSplits("aacaba"));
	PrintSingleResult(solution.numSplits("abcd"));
	PrintSingleResult(solution.numSplits("aaaaa"));
	PrintSingleResult(solution.numSplits("acbadbaada"));
}