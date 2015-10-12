//数组n个数，有2^n种组合
//每种组合，通过和1与加入组，加过后右移指针，扫描整个直到最后
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
	vector<vector<int> res;
	if (nums.empty()) {
	    res.push_back(nums);
	    return res;
	}
	int max = 1 << nums.size();
	for (int i = 0; i < max; ++i) {
	    vector<int> tmp;
	    int idx = 0;
	    int j = 0;
	    while (j) {
		if (j & 1)
		    tmp.push_back(nums[idx]);
		idx++;
		j >>= 1;
	    }
	    res.push_back(tmp);
	}
    }
};
