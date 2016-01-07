/*************************************************************************
	> File Name: repeatedDnaSequences.cpp
	> Author: weiliuwei
	> Mail: weiliuwei2013@sina.com 
	> Created Time: Thu 07 Jan 2016 04:33:32 PM CST
 ************************************************************************/
//DNA序列有ACGT四个字母组成，根据其ASCII发现，由后3位可标示s[i] & 7取出字母序列
//unordered_map为无序hash，标记有无，初始全为0，即全部存在，每读取一个序列，其在map中val为1，当发现再次发现val为1时，说明出现第二次，取到目前为止的10个字符
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> res;
		if (s == "")
			return res;

		unordered_map<int, int> map;
		for (size_t t = 0, i = 0; i < s.size(); ++i) {
			if (map[t = t << 3 & 0x3FFFFFFF | s[i] & 7]++ == 1)
				res.push_back(s.substr(i - 9, 10));
		}
		return res;
	}
};
