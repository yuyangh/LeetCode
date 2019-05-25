#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */
class Solution {
public:
	string removeKdigits(string num, int k) {
		if (k >= num.size()) {
			return "0";
		}
		for (int i = 0; i < num.size() - 1; i++) {
			if (k == 0) {
				break;
			}
			if (num[i] > num[i + 1]) {
				num[i] = '#';
				i--;
				k--;
			}
		}
		
		while (k > 0) {
			num.pop_back();
			k--;
		}
		
		num.erase(remove(num.begin(), num.end(), '#'), num.end());
		
		int zeroCount = 0;
		for (int i = 0; i < num.size() - 1; ++i) {
			if (num[i] != '0') {
				break;
			} else {
				zeroCount++;
			}
		}
		num.erase(0, zeroCount);
		return num;
	}
	
	// works, but take too much memory
	// string removeKdigits(string num, int k) {
	// 	string buffer=num;
	// 	int minNum=INT_MAX;
	//
	// 	for(int i=0;i<k;i++){
	// 		vector<string> reducedNums(buffer.size(),buffer);
	// 		for (int j = 0; j < reducedNums.size(); ++j) {
	// 			reducedNums[j].erase(j,1);
	// 			if(reducedNums[j].empty()){
	// 				return "0";
	// 			}
	// 		}
	// 		buffer=*min_element(reducedNums.begin(),reducedNums.end());
	// 	}
	// 	// get rid of leading zero
	// 	for (int i = 0; i < buffer.size()-1; ++i) {
	// 		if(buffer[i]=='0'){
	// 			buffer.erase(i,1);
	// 			i--;
	// 		}else{
	// 			break;
	// 		}
	// 	}
	//
	// 	return buffer;
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