#include <iostream>
#include <vector>
#include <algorithm>
//O(NlogN),binary_search
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if (nums.size() == 0 || nums.size() == 1)
        return nums.size();

	vector<int> min;
	for (int num : nums) {
		auto it = lower_bound(min.begin(), min.end(), num);
		if (it != min.end())
			*it = num;
		else
			min.push_back(num);
	}
	return min.size();
}

int main()
{
	vector<int> nums;
	int tmp, len;
	char ch;

	cout << "Please input the array: ";
	while (cin >> tmp) {
		nums.push_back(tmp);
		if ((ch = cin.get()) == '\n')
			break;
	}
	len = lengthOfLIS(nums);
    cout << "The longest increasing subsequence's length is " << len << endl;

    return 0;
}
