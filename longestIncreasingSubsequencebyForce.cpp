//O(n*n)
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1)
			return nums.size();

		vector<int> dp;
		dp.resize(nums.size());
		dp[0] = 1;
		int max = 1;
		for (int i = 1; i < nums.size(); ++i) {
			dp[i] = 1;
			for (int j = 0; j < i; ++j) {
				if (nums[i] > nums[j])
					dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
			}
		max = max > dp[i] ? max : dp[i];
		}
		return max;
	}
};
