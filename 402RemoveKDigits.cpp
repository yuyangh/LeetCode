#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 *
 * "1234567890"
 * 9
 */
class Solution {
public:
	/*
	 * use stack to reach the feature of the problem,
	 * which is removing prev digit larger than self
	 */
	string removeKdigits(string num, int k) {
		// remove all digits
		if (k >= num.size()) {
			return "0";
		}
		
		string result;
		stack<char> num_stack;
		int pop_need = k;
		
		// remove prev digit if prev > curr
		for (char digit : num) {
			while (!num_stack.empty() && num_stack.top() > digit && pop_need > 0) {
				num_stack.pop();
				--pop_need;
			}
			num_stack.push(digit);
		}
		
		// pop the ending numbers
		while (pop_need > 0) {
			num_stack.pop();
			pop_need--;
		}
		
		// put stack into string
		while (!num_stack.empty()) {
			result += num_stack.top();
			num_stack.pop();
		}
		
		for (int i = static_cast<int>(result.size()) - 1; i > 0; --i) {
			if (result[i] != '0') {
				break;
			} else {
				result.pop_back();
			}
		}
		
		// result string is in reverse order
		reverse(result.begin(), result.end());
		return result;
	}
	
	// do string manipulation
	string removeKdigitsString(string num, int k) {
		// remove all digits
		if (k >= num.size()) {
			return "0";
		}
		
		while (k > 0) {
			int i = 0;
			// remove prev digit if prev > curr
			while (i + 1 < num.size() && num[i] <= num[i + 1]) { i++; }
			num.erase(i, 1);
			k--;
		}
		// trim leading zeros
		int s = 0;
		while (s < (int) num.size() - 1 && num[s] == '0') { s++; }
		num.erase(0, s);
		
		return num == "" ? "0" : num;
	}
	
	// works, but take too much memory
	string removeKdigitsSlow(string num, int k) {
		string buffer = num;
		int minNum = INT_MAX;
		
		for (int i = 0; i < k; i++) {
			vector<string> reducedNums(buffer.size(), buffer);
			for (int j = 0; j < reducedNums.size(); ++j) {
				reducedNums[j].erase(j, 1);
				if (reducedNums[j].empty()) {
					return "0";
				}
			}
			buffer = *min_element(reducedNums.begin(), reducedNums.end());
		}
		// get rid of leading zero
		for (int i = 0; i < buffer.size() - 1; ++i) {
			if (buffer[i] == '0') {
				buffer.erase(i, 1);
				i--;
			} else {
				break;
			}
		}
		
		return buffer;
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

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		string num = stringToString(line);
		getline(cin, line);
		int k = stringToInteger(line);
		
		string ret = Solution().removeKdigits(num, k);
		
		string out = (ret);
		cout << out << endl;
	}
	return 0;
}