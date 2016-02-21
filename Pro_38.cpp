#include<iostream>
#include<vector>

using namespace std;

class CountTimes{
public:
	int CountNumTimes(const vector<int> num, int target);
	int FindFirstNum(const vector<int> num, int target,int left, int right);
	int FindLastNum(const vector<int> num, int target,int left, int right);
};

int CountTimes::CountNumTimes(const vector<int> num,int target)
{
	if (num.size() == 0)
		return 0;
	int l = FindLastNum(num, target, 0, num.size()-1);
	int f = FindFirstNum(num, target, 0, num.size()-1);
	if (f > -1 && l > -1)
		return l - f + 1;
}

int CountTimes::FindFirstNum(const vector<int> num,int target,int left,int right)
{
	if (num.size() == 0)
		return 0;
	while (left <= right)
	{
		int mid = (right + left) / 2;
		int n = num[mid];
		if (target == n)
		{
			if (mid > 1 && num[mid - 1] != target || mid == 0)  //注意边界条件
				return mid;
			else
				right = mid - 1;
		}
		else if (target < n )
			right = mid - 1;
		else if (target > n)
			left = mid + 1;
	}
	return -1;
}

int CountTimes::FindLastNum(const vector<int> num, int target, int left, int right)
{
	if (num.size() == 0)
		return 0;
	while (left <= right)
	{
		int mid = (right + left) / 2;
		int n = num[mid];
		if (target == n)
		{
			if (mid < right && num[mid + 1] != target || mid == right)		//注意边界条件
				return mid;
			else 
				left = mid + 1;
		}
		else if (target < n)
			right = mid - 1;
		else if (target > n)
			left = mid + 1;
	}
	return -1;

}

int main(void)
{
	vector<int> num = { 1, 2, 3, 3, 3, 3, 3,3,3, 5,5, 7, 8 };
	CountTimes c;
	cout << c.CountNumTimes(num, 5) << endl;
}