#include "LeetCodeLib.h"

class Solution {

public:
	// iterative approach
	int calculate(string s) {
		int result = 0;
		int sign = 1;
		stack<int> st;
		for (int i = 0; i < s.size(); i++) {
			// get the number from string
			if (s[i] >= '0') {
				int num = 0;
				while (i < s.size() && s[i] >= '0') {
					num *= 10;
					num += int(s[i]) - '0';
					i++;
				}
				i--;
				result += num * sign;
			} else if (s[i] == '+') {
				sign = 1;
			} else if (s[i] == '-') {
				sign = -1;
			} else if (s[i] == '(') {
				st.push(result);
				st.push(sign);
				result = 0;
				sign = 1;
			} else if (s[i] == ')') {
				sign = st.top();
				st.pop();
				result *= sign;
				result += st.top();
				st.pop();
			}
		}
		return result;
	}
	
	// prev own approach
	
	// #define LEFT_PARA_VALUE -999999 /* -999999 represents '('*/
	// stack<int> reverse, order;
	// int calculate(string s) {
	// 	int result = 0;
	//
	// 	for (int i = 0; i < s.size(); ++i) {
	// 		if (s[i] == ' ') {
	// 			continue;
	// 		}
	// 		if(s[i]=='('){
	// 			reverse.push(LEFT_PARA_VALUE);
	// 			continue;
	// 		}
	// 		if (s[i] == ')') {
	// 			while (reverse.top() != LEFT_PARA_VALUE/*represents '('*/) {
	// 				order.push(reverse.top());
	// 				reverse.pop();
	// 			}
	// 			reverse.pop();// get rid of "("
	// 			result = calculatePara();
	// 			reverse.push(result);
	// 		} else {
	// 			// check each input is a num or not
	// 			if (isdigit(s[i])) {
	// 				string numString = s.substr(i, 20);
	// 				int num = stoi(numString);
	// 				reverse.push(num);
	// 				i += to_string(num).size() - 1;
	// 			} else {
	// 				reverse.push((s[i]));
	// 			}
	// 		}
	// 	}
	//
	// 	// handle all nums in ()
	// 	if (reverse.empty()) {
	// 		return result;
	// 	} else {
	// 		while (!reverse.empty()) {
	// 			order.push(reverse.top());
	// 			reverse.pop();
	// 		}
	// 		return calculatePara();
	// 	}
	// }
	//
	// int calculatePara() {
	// 	if(order.empty()){
	// 		cout<<"Problem in order stack"<<endl;
	// 		return 0;
	// 	}
	// 	int result = (order.top()), right;
	// 	int op;
	// 	order.pop();
	// 	// do operations on each num
	// 	while (!order.empty()) {
	// 		op = order.top();
	// 		order.pop();
	// 		right = order.top();
	// 		order.pop();
	// 		if (op == '+') {
	// 			result = result + right;
	// 		} else {
	// 			result = result - right;
	// 		}
	// 	}
	// 	return result;
	// }
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
		string s = stringToString(line);
		
		int ret = Solution().calculate(s);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}

/*
 * testcase
 * "1 + 1"=2
 * "(1+(4+5+2)-3)+(6+8)"=23
 * */