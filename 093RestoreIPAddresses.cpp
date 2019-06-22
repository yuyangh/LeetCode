#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (31.57%)
 * Likes:    679
 * Dislikes: 277
 * Total Accepted:    142K
 * Total Submissions: 448.4K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 *
 * Example:
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 */
class Solution {
public:
	vector<vector<string>> combination;
	
	vector<string> restoreIpAddresses(string s) {
		vector<string> buffer;
		ip(buffer, s, 0, 4);
		vector<string> ans;
		// concat 4 parts into 1 string
		for (auto &item:combination) {
			for (int i = 1; i < item.size(); i++) {
				item[0] += '.' + item[i];
			}
			ans.emplace_back(item[0]);
		}
		return ans;
	}
	
	void ip(vector<string> &buffer, string &s, int start, int remain) {
		// base
		if (remain == 0) {
			if (start == s.size()) {
				combination.emplace_back(buffer);
			}
			return;
		}
		
		for (int len = 1; len <= 3; len++) {
			if (start + len > s.size()) {
				return;
			}
			// deal with leading 0 situation
			string temp = s.substr(start, len);
			if (temp[0] == '0' && temp.size() != 1) {
				continue;
			}
			
			// check number range
			int num = stoi(temp);
			if (num < 256) {
				buffer.emplace_back(temp);
			} else {
				continue;
			}
			// backtracking
			ip(buffer, s, start + len, remain - 1);
			buffer.pop_back();
		}
	}
};

int main(){
	string input="25525511135";
	Solution solution;
	cout<<"input is:\t"<<input<<endl;
	cout<<"combination is:"<<endl;
	for (const auto &item : solution.restoreIpAddresses(input)) {
		cout<<item<<endl;
	}
	return 0;
}

