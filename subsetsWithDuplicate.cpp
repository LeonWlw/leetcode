//迭代法求res，每一次在上次的基础上加入新元素
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
	vector<vector<int> > res(1, vector<int>());
	if (nums.emtpy()) {
	    res.push_back(nums);
	    return res;
	}
	sort(nums.begin(), nums.end());
	int idx = 0;
	for (int i = 0; i < nums.size(); ++i) {
	    int start = (i != 0 && nums[i] == nums[i - 1]) ? idx : 0;//若两次nums[]相同，下标更新为上次加进来的子集
	    int end = res.size();
	    for (int j = 0; j < end; ++j) {
		vector<int> tmp(res[j]);
		tmp.push_back(nums[i]);
		res.push_back(tmp);
	    }
	    idx = end;
	}
	return res;
    }
};
