/*
给定一个字符串，找出不含有重复字符的最长子串的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 无重复字符的最长子串是 "abc"，其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 无重复字符的最长子串是 "b"，其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 无重复字符的最长子串是 "wke"，其长度为 3。
     请注意，答案必须是一个子串，"pwke" 是一个子序列 而不是子串。
*/

// 滑动窗口思路解决问题
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int max_size = 0;
		int index[128] = { 0 };
		for (int i = 0, j = 0; j < s.length(); ++j)
		{
			if (index[(int)s[j]] > i) i = index[(int)s[j]];
			if (j - i + 1 > max_size) max_size = j - i + 1;
			index[(int)s[j]] = j + 1;
		}
		return max_size;
	}
};