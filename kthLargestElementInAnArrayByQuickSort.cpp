//快排思想，最优O(n)
//随机取key，将数组分为小于key和不小于key的两部分，看小于部分的个数与k的大小关系，确定第k大数在哪部分，继续快排，直到取到
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
	int low = 0;
	int high = nums.size() - 1;
	while (low < high) {
	    int left = low;
	    int right = high;
	    int key = nums[left];
	    while (left < right) {
		while (left < right && nums[right] < key)
		    --right;
		nums[left] = nums[right];
		while (left < right && nums[left] >= key)
		    ++left;
		nums[right] = nums[left];
	    }
	    nums[left] = key;
	    if (left == k - 1)
		return nums[k - 1];
	    else if (left > k - 1)
		high = left - 1;
	    else
		low = left + 1;
	}
	return nums[k - 1];
};
