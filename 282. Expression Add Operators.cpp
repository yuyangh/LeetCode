//
// Created by Yuyang Huang on 9/6/21.
//

/*
 * 282. Expression Add Operators
 * Hard
 *
 * Given a string num that contains only digits and an integer target,
 * return all possibilities to add the binary operators '+', '-', or '*'
 * between the digits of num so that the resultant expression evaluates to the target value.
 *
 * Example 1:
 * Input: num = "123", target = 6
 * Output: ["1*2*3","1+2+3"]
 *
 * Example 2:
 * Input: num = "232", target = 8
 * Output: ["2*3+2","2+3*2"]
 *
 * Example 3:
 * Input: num = "105", target = 5
 * Output: ["1*0+5","10-5"]
 *
 * Example 4:
 * Input: num = "00", target = 0
 * Output: ["0*0","0+0","0-0"]
 *
 * Example 5:
 * Input: num = "3456237490", target = 9191
 * Output: []
 *
 * Constraints:
 * 1 <= num.length <= 10
 * num consists of only digits.
 * -231 <= target <= 231 - 1
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(4^n)
	 * for each digit, there are 4 operations: No operation, +, -, *
	 * because * has different operational precedence, think about using a stack
	 * current solution TLE on leetcode
	 */
	vector<string> addOperators(string num, int target) {
		vector<string> result;
		vector<string> calculation;
		
		helper(num, target, calculation, 0, result);
		return result;
	}

private:
	void helper(string &num, int target, vector<string>& calculation, int index, vector<string> &result) {
		if (index == num.size()) {
			string calString;
			for(auto& str:calculation){
				calString+=str;
			}
			
			int value = calculate(calString);
			if (value == target) {
				result.push_back(calString);
			}
			return;
		}
		for (int len = 1; len + index <= num.size(); len++) {
			if (len > 1 && num[index] == '0') {
				continue;
			}
			string numStr = num.substr(index, len);
			if (calculation.empty()) {
				calculation.push_back(numStr);
				helper(num, target, calculation, index + len, result);
				calculation.pop_back();
			} else {
				calculation.emplace_back("+");
				calculation.push_back(numStr);
				helper(num, target, calculation, index + len, result);
				calculation.pop_back();
				calculation.pop_back();
				
				calculation.emplace_back("-");
				calculation.push_back(numStr);
				helper(num, target, calculation, index + len, result);
				calculation.pop_back();
				calculation.pop_back();
				
				calculation.emplace_back("*");
				calculation.push_back(numStr);
				helper(num, target, calculation , index + len, result);
				calculation.pop_back();
				calculation.pop_back();
				
			}
		}
	}
	
	int calculate(string& s) {
		stack<long long> numbers;
		string currNum;
		char oper = '+';
		for (int i = 0; i < s.size(); i++) {
			if (isdigit(s[i])) {
				currNum += s[i];
			}
			
			// process each number when meet a operator
			if ((!isdigit(s[i]) && !iswspace(s[i]))
			    || i == s.size() - 1) {
				long long num = stoll(currNum);
				if (oper == '+') { numbers.push(num); }
				if (oper == '-') { numbers.push(-num); }
				if (oper == '*') {
					long long prevNum = numbers.top();
					numbers.top() = prevNum * num;
				}
				if (oper == '/') {
					long long prevNum = numbers.top();
					numbers.top() = (prevNum / num);
				}
				
				oper = s[i];
				currNum = "";
			}
		}
		
		long long result = 0;
		while (!numbers.empty()) {
			result += numbers.top();
			numbers.pop();
		}
		return result;
	}
};

int main() {
	Solution solution;
	string num;
	int target;
	
	num = "123", target = 6;
	PrintVector(solution.addOperators(num, target));
	
	num = "232", target = 8;
	PrintVector(solution.addOperators(num, target));
	
	num = "105", target = 5;
	PrintVector(solution.addOperators(num, target));
	
	num = "00", target = 0;
	PrintVector(solution.addOperators(num, target));
	
	num = "3456237490", target = 9191;
	PrintVector(solution.addOperators(num, target));
}