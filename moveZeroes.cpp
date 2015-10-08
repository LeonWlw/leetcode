#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    if (nums.size() == 0)
	return;
    int start = 0, count = 0;
    for (int i = 0; i < nums.size(); ++i) {
	if (nums[i] != 0)
	    nums[start++] = nums[i];
	else
	    count++;
    }
    for (int i = nums.size() - count; i < nums.size(); ++i)
	nums[i] = 0;
}

int main()
{
    vector<int> nums;
    int tmp;
    char c;
    cout << "Please input the array:";
    while (cin >> tmp) {
	nums.push_back(tmp);
	if ((c = cin.get()) == '\n')
	    break;
    }
    for (int i = 0; i < nums.size(); ++i)
	cout << nums[i] << " ";
    cout << endl;
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); ++i)
	cout << nums[i] << " ";
    cout << endl;

    return 0;
}
