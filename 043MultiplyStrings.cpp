#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (30.78%)
 * Likes:    1012
 * Dislikes: 467
 * Total Accepted:    204.8K
 * Total Submissions: 664.2K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 *
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 *
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 *
 *
 * Note:
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 */
class Solution {
public:
	string multiply(string num1, string num2) {
		// allocate the size
		string sum(num1.size() + num2.size(), '0');
		
		// do the multiplication from the end
		for (int i = num1.size() - 1; i >= 0; --i) {
			int carry = 0;
			for (int j = num2.size() - 1; j >= 0; --j) {
				int tmp = (sum[i + j + 1] - '0') +
				          (num1[i] - '0') * (num2[j] - '0') + carry;
				sum[i + j + 1] = tmp % 10 + '0';
				carry = tmp / 10;
			}
			
			// write leading carry after a loop
			sum[i] += carry;
		}
		
		// trim any leading zeros
		size_t startpos = sum.find_first_not_of("0");
		if (string::npos != startpos) {
			return sum.substr(startpos);
		}
		
		// return 0 if we computed nothing but zeros
		return "0";
	}
	
	/*
	 * reverse the string and
	 * do multiplication for entire num1 with each digit of num2
	 * it is slow because
	 * the reverse operation and add string operation takes time
	 */
	string multiplySlow(string num1, string num2) {
		// check 0 case
		if (num1.empty() || num2.empty()) {
			return "0";
		}
		if (checkZero(num1) || checkZero(num2)) {
			return "0";
		}
		
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		
		string ans = "";
		// go through each digit in num1
		for (int i = 0; i < num1.size(); i++) {
			string multiplication;
			int carry = 0;
			// add zeros
			for (int zeros = 0; zeros < i; zeros++) {
				multiplication += '0';
			}
			// do multiplication for each digit
			for (char num2digit : num2) {
				
				int digit1 = getDigit(num1[i]);
				int digit2 = getDigit(num2digit);
				int num = digit1 * digit2 + carry;
				int digit = (num) % 10;
				carry = (num) / 10;
				stringAppendNum(multiplication, digit);
			}
			if (carry) {
				stringAppendNum(multiplication, carry);
			}
			// add multiplication result to ans
			addString(ans, multiplication);
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
	
	inline int getDigit(char ch) {
		return ch - '0';
	}
	
	inline void stringAppendNum(string &lhs, int digit) {
		lhs += ('0' + digit);
	}
	
	inline bool checkZero(string &str) {
		for (char ch : str) {
			if (ch != '0') {
				return false;
			}
		}
		return true;
	}
	
	inline void addString(string &lhs, const string &rhs) {
		int carry = 0;
		int length = max(lhs.size(), rhs.size());
		int left, right, sum, digit;
		for (int i = 0; i < length; i++) {
			if (i >= lhs.size()) {
				left = 0;
			} else {
				left = getDigit(lhs[i]);
			}
			if (i >= rhs.size()) {
				right = 0;
			} else {
				right = getDigit(rhs[i]);
			}
			
			sum = left + right + carry;
			digit = sum % 10;
			carry = sum / 10;
			if (i >= lhs.size()) {
				lhs += '0' + digit;
			} else {
				lhs[i] = '0' + digit;
			}
		}
		if (carry) {
			lhs += '0' + carry;
		}
	}
};


string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
				case '\"':
					result.push_back('\"');
					break;
				case '/' :
					result.push_back('/');
					break;
				case '\\':
					result.push_back('\\');
					break;
				case 'b' :
					result.push_back('\b');
					break;
				case 'f' :
					result.push_back('\f');
					break;
				case 'r' :
					result.push_back('\r');
					break;
				case 'n' :
					result.push_back('\n');
					break;
				case 't' :
					result.push_back('\t');
					break;
				default:
					break;
			}
			i++;
		} else {
			result.push_back(currentChar);
		}
	}
	return result;
}

int main() {
	string line;
	while (getline(cin, line)) {
		string num1 = stringToString(line);
		getline(cin, line);
		string num2 = stringToString(line);
		
		string ret = Solution().multiply(num1, num2);
		
		string out = (ret);
		cout << out << endl;
	}
	return 0;
}