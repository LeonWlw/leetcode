#include <iostream>
#include <vector>
#include <algorithm>
//根据一个不重复数组，输出其子集序列，子集数组升序排列
//动态变化tmp数组，加入res结果二维数组中
using namespace std;

vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> > res(1, vector<int>());
    if (nums.empty()) {
		res.push_back(nums);
		return res;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
		int reSize = res.size();
		for (int j = 0; j < reSize; ++j) {
			vector<int> tmp(res[j]);
			tmp.push_back(nums[i]);
		res.push_back(tmp);
		}
    }

    return res;
}

int main()
{
    vector<int> nums;
    vector<vector<int> > res;
    int tmp;
    char ch;

    cout << "Please iuput the array(distinct):";
    while (cin >> tmp) {
		nums.push_back(tmp);
		if ((ch = cin.get()) == '\n')
			break;
    }
    res = subsets(nums);
    for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << " ";
    cout << endl;
    for (int i = 0; i < res.size(); ++i)
		for (int j = 0; j < res[0].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
    cout << endl;

    return 0;
}
