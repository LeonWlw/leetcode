#include <iostream>
#include <vector>
#include <unordered_map>
//寻找无序数组中最长连续序列的长度，要求O(n)。
//优先考虑hash_map，每个数的上下寻找，已找过的在之后可以忽略
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if (nums.empty())
	return 0;
    int cur = 0;
    int max = 0;
    unordered_map<int, bool> used;
    for (int i = 0; i < nums.size(); ++i)
	used[nums[i]] = false;
    for (int i = 0; i < nums.size(); ++i) {
	if (used[nums[i]])
	    continue;
	else {
	    used[nums[i]] = true;
	    cur = 1;
	    for (int j = nums[i] + 1; used.find(j) != used.end(); ++j) {
		cur++;
		used[j] = true;
	    }
	    for (int j = nums[i] - 1; used.find(j) != used.end(); --j) {
		cur++;
		used[j] = true;
	    }
	    if (cur > max)
		max = cur;
	}
    }
    return max;
}

int main()
{
    vector<int> nums;
    int tmp, res;
    char ch;

    cout << "Please input the array:";
    while (cin >> tmp) {
	nums.push_back(tmp);
	if ((ch = cin.get()) == '\n')
	    break;
    }
    res = longestConsecutive(nums);
    cout << "The longest consecutive sequence in the array is: " << res << endl;
    
    return 0;
}
