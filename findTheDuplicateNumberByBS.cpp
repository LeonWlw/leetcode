//二分法查找该重复数，若小于mid的个数大于mid的位置，重复数在前半部，反之在后半部
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
	if (nums.empty())
	    return 0;

	int low = 0;
	int high = nums.size() - 1;
	int mid = 0;
	while (low < high) {
	    mid = low + (high - low) / 2;
	    int cnt = count(nums, mid);
	    if (cnt > mid)
		high = mid;
	    else
		low = mid + 1;
	}
	return low;
    }
    int count(vector<int> nums, int mid) {
	int cnt = 0;
	for (int i= 0; i < nums.szie(); ++i)
	    if (nums[i] <= mid)
		cnt++;
	return cnt;
    }
}
