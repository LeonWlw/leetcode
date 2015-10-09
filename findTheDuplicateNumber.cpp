#include <iostream>
#include <vector>
//寻找一个大小n+1，从1到n的数组中，唯一重复出现的那个数。空间复杂度O(1)，时间复杂度小于O(n*n)。
//此数组，位置i应该存放i+1，若有重复，则必有多个数争抢同一位置
using namespace std;

int findDuplicate(vector<int>& nums) {
    if (nums.empty())
	return 0;

    for (int i = 0; i < nums.size(); ++i) {
	while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])  //将数组调整顺序
	    swap(nums[nums[i] - 1], nums[i]);
	if (nums[i] != i + 1)
	    return nums[i];
}

int main()
{
    vector<int> nums;
    int tmp, ans;
    char ch;

    cout << "Please input the array(from 1 to n, size n+1, contains at less one duplicate number):" << endl;
    while (cin >> tmp) {
	nums.push_back(tmp);
	if ((ch = cin.get()) == '\n')
	    break;
    }
    ans = findDuplicate(nums);
    cout << "The duplicate number is " << ans << endl;

    return 0;
}
