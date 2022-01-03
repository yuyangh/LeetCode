//
// Created by Yuyang Huang on 1/3/22.
//

/*
 * 241. Different Ways to Add Parentheses
 * Medium
 *
 * Given a string expression of numbers and operators,
 * return all possible results from computing all the different possible ways to group numbers and operators.
 * You may return the answer in any order.
 *
 * Example 1:
 * Input: expression = "2-1-1"
 * Output: [0,2]
 * Explanation:
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 *
 * Example 2:
 * Input: expression = "2*3-4*5"
 * Output: [-34,-14,-10,-10,10]
 * Explanation:
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 *
 * Constraints:
 * 1 <= expression.length <= 20
 * expression consists of digits and the operator '+', '-', and '*'.
 * All the integer values in the input expression are in the range [0, 99].
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Dynamic programming
	 * memorize computation result
	 */
	vector<int> diffWaysToCompute(string expression) {
		unordered_map<string, vector<int>> strNums;
		return helper(expression,strNums);
	}

private:
	vector<int> helper(string str,unordered_map<string, vector<int>>& strNums){
		vector<int> result;
		for (int i = 0; i < str.size(); i++) {
			char cur = str[i];
			// divide the string into left and right, then combine
			if (cur == '+' || cur == '-' || cur == '*') {
				auto leftStr=str.substr(0, i);
				auto rightStr=str.substr(i + 1);
				
				vector<int> left,right;
				if(strNums.find(leftStr)==strNums.end()){
					left=helper(leftStr,strNums);
				}else{
					left=strNums[leftStr];
				}
				if(strNums.find(rightStr)==strNums.end()){
					right=helper(rightStr,strNums);
				}else{
					right=strNums[rightStr];
				}
				
				for (auto l: left) {
					for (int r: right) {
						if (cur == '+') {
							result.push_back(l + r);
						}
						if (cur == '-') {
							result.push_back(l - r);
						}
						if (cur == '*') {
							result.push_back(l * r);
						}
					}
				}
			}
		}
		// if the string cannot be divided, then it must be numbers
		if (result.empty()) {
			result.push_back(stoi(str));
		}
		return result;
	}
	
	vector<int> helper(string str) {
		vector<int> result;
		for (int i = 0; i < str.size(); i++) {
			char cur = str[i];
			// divide the string into left and right, then combine
			if (cur == '+' || cur == '-' || cur == '*') {
				auto left = helper(str.substr(0, i));
				auto right = helper(str.substr(i + 1));
				for (auto l: left) {
					for (int r: right) {
						if (cur == '+') {
							result.push_back(l + r);
						}
						if (cur == '-') {
							result.push_back(l - r);
						}
						if (cur == '*') {
							result.push_back(l * r);
						}
					}
				}
			}
		}
		// if the string cannot be divided, then it must be numbers
		if (result.empty()) {
			result.push_back(stoi(str));
		}
		return result;
	}
};

int main() {
	Solution solution;
	PrintVector(solution.diffWaysToCompute("2-1-1"));
	PrintVector(solution.diffWaysToCompute("2*3-4*5"));
}