//
// Created by Yuyang Huang on 10/3/19.
//



/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 *
 * https://leetcode.com/problems/top-k-frequent-words/description/
 *
 * algorithms
 * Medium (46.99%)
 * Likes:    940
 * Dislikes: 92
 * Total Accepted:    86.5K
 * Total Submissions: 183.2K
 * Testcase Example:  '["i", "love", "leetcode", "i", "love", "coding"]\n2'
 *
 * Given a non-empty list of words, return the k most frequent elements.
 * Your answer should be sorted by frequency from highest to lowest. If two
 * words have the same frequency, then the word with the lower alphabetical
 * order comes first.
 *
 * Example 1:
 *
 * Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 * Output: ["i", "love"]
 * Explanation: "i" and "love" are the two most frequent words.
 * ⁠   Note that "i" comes before "love" due to a lower alphabetical order.
 *
 *
 *
 * Example 2:
 *
 * Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is",
 * "is"], k = 4
 * Output: ["the", "is", "sunny", "day"]
 * Explanation: "the", "is", "sunny" and "day" are the four most frequent
 * words,
 * ⁠   with the number of occurrence being 4, 3, 2 and 1 respectively.
 *
 *
 *
 * Note:
 *
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Input words contain only lowercase letters.
 *
 *
 *
 * Follow up:
 *
 * Try to solve it in O(n log k) time and O(n) extra space.
 *
 *
 */

#include "LeetCodeLib.h"

// @lc code=start
class Solution {
public:
	/*
	 * time: O(nlogk), space:O(k)
	 */
	vector<string> topKFrequent(vector<string>& words, int k) {
		// store the existence number of each word
		unordered_map<string,int> countWordsMap;
		for (const auto &word : words) {
			auto it=countWordsMap.find(word);
			if(it==countWordsMap.end()){
				countWordsMap.emplace(word,1);
			}else{
				it->second+=1;
			}
		}
		
		// put smaller items at the top of pq
		auto comp=[](pair<string,int> &lhs,pair<string,int>& rhs){
			if(lhs.second>rhs.second){
				return true;
			}else{
				if(lhs.second==rhs.second){
					if(lhs.first.compare(rhs.first)<0){
						return true;
					}
				}
				return false;
			}
		};
		
		// use a pq to store top k elements
		priority_queue<pair<string,int>,vector<pair<string,int>>, decltype(comp)> pq(comp);
		for (const auto &item : countWordsMap) {
			pq.push(item);
			if(pq.size()>k){
				pq.pop();
			}
		}
		
		vector<string> result;
		result.reserve(k);
		
		while(!pq.empty()&&result.size()<k){
			result.emplace_back(pq.top().first);
			pq.pop();
		}
		
		// now, small items are at the front, need to reverse
		reverse(result.begin(),result.end());
		
		return result;
	}
};
// @lc code=end


