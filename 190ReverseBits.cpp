#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 *
 * https://leetcode.com/problems/reverse-bits/description/
 *
 * algorithms
 * Easy (31.96%)
 * Likes:    588
 * Dislikes: 196
 * Total Accepted:    189K
 * Total Submissions: 590.4K
 * Testcase Example:  '00000010100101000001111010011100'
 *
 * Reverse bits of a given 32 bits unsigned integer.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: 00000010100101000001111010011100
 * Output: 00111001011110000010100101000000
 * Explanation: The input binary string 00000010100101000001111010011100
 * represents the unsigned integer 43261596, so return 964176192 which its
 * binary representation is 00111001011110000010100101000000.
 *
 *
 * Example 2:
 *
 *
 * Input: 11111111111111111111111111111101
 * Output: 10111111111111111111111111111111
 * Explanation: The input binary string 11111111111111111111111111111101
 * represents the unsigned integer 4294967293, so return 3221225471 which its
 * binary representation is 10101111110010110010011101101001.
 *
 *
 *
 * Note:
 *
 *
 * Note that in some languages such as Java, there is no unsigned integer type.
 * In this case, both input and output will be given as signed integer type and
 * should not affect your implementation, as the internal binary representation
 * of the integer is the same whether it is signed or unsigned.
 * In Java, the compiler represents the signed integers using 2's complement
 * notation. Therefore, in Example 2 above the input represents the signed
 * integer -3 and the output represents the signed integer -1073741825.
 *
 *
 *
 *
 * Follow up:
 *
 * If this function is called many times, how would you optimize it?
 *
 */
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		/*
		 * for 8 bit binary number abcdefgh, the process is as follow:
		 * abcdefgh -> efghabcd -> ghefcdab -> hgfedcba
		 */
		n = (n >> 16) | (n << 16);
		n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
		n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
		n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
		n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
		return n;
	}
	
	uint32_t reverseBitsBasic(uint32_t n) {
		uint32_t result = 0;
		for (int i = 0; i < 32; ++i) {
			// shift each digit and plus digit
			result = (result << 1) + (n >> i & (1));
		}
		return result;
	}
};

int main() {
	uint32_t input = 0b101;
	Solution solution;
	auto result = solution.reverseBits(input);
	PrintSingleResult(result);
	return 0;
}

