//
// Created by Yuyang Huang on 8/22/21.
//

/*
 * 227. Basic Calculator II
 * Medium
 *
 * Given a string s which represents an expression, evaluate this expression and return its value.
 * The integer division should truncate toward zero.
 * You may assume that the given expression is always valid.
 * All intermediate results will be in the range of [-231, 231 - 1].
 *
 * Note: You are not allowed to use any built-in function
 * which evaluates strings as mathematical expressions, such as eval().
 *
 * Example 1:
 * Input: s = "3+2*2"
 * Output: 7
 *
 * Example 2:
 * Input: s = " 3/2 "
 * Output: 1
 *
 * Example 3:
 * Input: s = " 3+5 / 2 "
 * Output: 5
 *
 * Constraints:
 * 1 <= s.length <= 3 * 105
 * s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
 * s represents a valid expression.
 * All the integers in the expression are non-negative integers in the range [0, 231 - 1].
 * The answer is guaranteed to fit in a 32-bit integer.
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time Complexity: O(n)
	 * use a stack to keep intermediate result
	 * process each number when meet a operator
	 */
	int calculate(string s) {
		stack<int> numbers;
		string currNum;
		char oper = '+';
		for (int i = 0; i < s.size(); i++) {
			if (isdigit(s[i])) {
				currNum += s[i];
			}
			
			// process each number when meet a operator
			if ((!isdigit(s[i]) && !iswspace(s[i]))
			    || i == s.size() - 1) {
				int num = stoi(currNum);
				if (oper == '+') { numbers.push(num); }
				if (oper == '-') { numbers.push(-1 * num); }
				if (oper == '*') {
					int prevNum = numbers.top();
					numbers.pop();
					numbers.push(prevNum * num);
				}
				if (oper == '/') {
					int prevNum = numbers.top();
					numbers.pop();
					numbers.push(prevNum / num);
				}
				
				oper = s[i];
				currNum = "";
			}
			
		}
		int result = 0;
		while (!numbers.empty()) {
			result += numbers.top();
			numbers.pop();
		}
		return result;
	}
};

int main() {
	Solution solution;
	string s = "3+2*2";
	PrintSingleResult(solution.calculate(s));
	
	s = " 3/2 ";
	PrintSingleResult(solution.calculate(s));
	
	s = " 3+5 / 2 ";
	PrintSingleResult(solution.calculate(s));
	s = " 3-7/1 ";
	PrintSingleResult(solution.calculate(s));
	s = " 3+7/1*2 ";
	PrintSingleResult(solution.calculate(s));
	
}