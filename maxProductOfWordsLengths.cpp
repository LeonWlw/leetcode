/*************************************************************************
	> File Name: maxProductOfWordsLengths.cpp
	> Author: weiliuwei
	> Mail: weiliuwei2013@sina.com 
	> Created Time: Mon 04 Jan 2016 05:11:17 PM CST
 ************************************************************************/
//求字符串数组(均小写)中，互不相同的俩字符串最大的长度乘积
//用二进制数来表示每个字符串具有的字符
#include<iostream>
#include<cstddef>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int maxProduct(vector<string>& words) {
	vector<int> mask(words.size());
	int res = 0;
	int len = 0;
	for (size_t i = 0; i < words.size(); ++i) {
		for (char c : words[i])
			mask[i] |= 1 << (c - 'a');
		for (size_t j = 0; j < i; ++j) {
			if (!(mask[i] & mask[j]))
				len = words[i].size() * words[j].size();
				if (res < len)
					res = len;
		}
	}
	return res;
}

int main()
{
	vector<string> words;
	string tmp;
	char c;
	int res;

	cout << "Please input the string:";
	while ( cin >> tmp) {
		words.push_back(tmp);
		if ((c = cin.get()) == '\n')
			break;
	}
	res = maxProduct(words);
	cout << "The result is " << res << endl;

	return 0;
}
