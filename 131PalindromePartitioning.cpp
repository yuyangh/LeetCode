#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (41.03%)
 * Likes:    913
 * Dislikes: 38
 * Total Accepted:    165.8K
 * Total Submissions: 403.3K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * Example:
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 */
class Solution {
public:
	vector<vector<string>> result;
	vector<string> stringLiterals;
	vector<vector<string>> partition(string s) {
		stringLiterals.reserve(s.size());
		for( int i=0;i<s.size();i++){
			stringLiterals.emplace_back(s.substr(i,1));
		}
		result.emplace_back(stringLiterals);
		merge();
		return result;
	}
	
	void merge(){
		string buffer;
		for(int i=0;i<result.size();i++){
			for(int pos=1;pos<result[i].size();pos++){
				buffer=result[i][pos-1]+result[i][pos];
				if(isPalindrome(buffer)){
					result.emplace_back(result[i]);
					result.back()[pos]=buffer;
					result.back().erase(result.back().begin()+pos-1);
				}
				if(pos+1<result[i].size()){
					buffer+=result[i][pos+1];
					if(isPalindrome(buffer)){
						result.emplace_back(result[i]);
						result.back()[pos]=buffer;
						result.back().erase(result.back().begin()+pos+1);
						result.back().erase(result.back().begin()+pos-1);
					}
					
				}
			}
		}
	}
	
	bool isPalindrome(int start,int end, string& s){
		while(start<=end){
			if(s[start]!=s[end]){
				return false;
			}
			start++;
			end--;
		}
		return true;
	}
	
	bool isPalindrome(string& s){
		int start=0,end=s.size()-1;
		while(start<=end){
			if(s[start]!=s[end]){
				return false;
			}
			start++;
			end--;
		}
		return true;
	}
	
	
	
	bool partition(int pos,string& s){
		if(pos==s.size()){
			result.emplace_back(vector<string>());
			return true;
		}
		bool palindrome=false;
		for(int i=pos;i<s.size();i++){
			if(isPalindrome(pos,i,s)){
				if(partition(i+1,s)){
					result.back().emplace_back(s.substr(pos,i));
					palindrome=true;
				}
			}
		}
		return palindrome;
	}
};

int main(){
	Solution solution;
	string str="aaba";
	auto result=solution.partition(str);
	for (const auto &item : result) {
		for (const auto &string : item) {
			cout<<string<<" ";
		}
		cout<<endl;
	}
}