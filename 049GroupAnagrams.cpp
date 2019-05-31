#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (46.62%)
 * Likes:    1627
 * Dislikes: 108
 * Total Accepted:    336.9K
 * Total Submissions: 720.4K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 *
 * Example:
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 *
 * Note:
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 */
class Solution {
public:
	// use count of char in each word as the key
	// use hashtable to group words
	vector<vector<string>> groupAnagrams(vector<string> &strs) {
		if (strs.empty()) {
			return vector<vector<string>>();
		}
		
		// produce the initialKey for the map
		string initialKey;
		for (size_t i = 0; i < 26; i++) {
			// initialize the count for each char as 0
			initialKey += '0';
		}
		
		// key: count of each char, value: vector of words
		unordered_map<string, vector<string>> result;
		for (auto &str : strs) {
			string key(initialKey);
			for (char ch : str) {
				// modify count of char in key
				key[ch - 'a']++;
			}
			auto find = result.find(key);
			if (find == result.end()) {
				result.emplace(key, vector<string>(1, str));
			} else {
				find->second.emplace_back(str);
			}
		}
		
		vector<vector<string>> groups;
		groups.reserve(result.size());
		for (auto &it : result) {
			groups.emplace_back(it.second);
		}
		return groups;
	}
};

