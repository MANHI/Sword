#include<iostream>
#include<vector>

using namespace std;

void DivideOddAndEven(vector<int> &nums)
{
	int l = 0;
	int r = nums.size() - 1;
	while (l <= r)
	{
		if (nums[l] % 2 == 0 && nums[r] % 2 != 0)
		{
			int temp = nums[l];
			nums[l] = nums[r];
			nums[r] = temp;
		}
		if (nums[l] % 2 != 0)
			l++;
		if (nums[r] % 2 == 0)
			r--;
	}
}

int main(void)
{
	vector<int> nums = { 2, 1, 3, 4, 5, 8, 7 };
	DivideOddAndEven(nums);
	for (auto c : nums)
		cout << c << " ";
	cout << endl;
	return 0;
}