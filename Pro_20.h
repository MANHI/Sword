#include<iostream>
#include<vector>
using namespace std;

void PrintClockNums(const vector<vector<int>> nums, int row, int col, int start);

void PrintClock(const vector<vector<int>> nums,int row,int col)
{
	int start = 0;
	if (row <= 0 || col <= 0)
		return;
	while (row > start * 2 && col > start * 2)
	{
		PrintClockNums(nums, row, col, start);
		start++;
	}
}

void PrintClockNums(const vector<vector<int>> nums, int row, int col, int start)
{
	int i, j;
	int endX = col - 1 - start;
	int endY = row - 1 - start;
	for (i = start; i <= endX; i++)  //从左向右打印一行
		cout << nums[start][i] << " ";

	if (endY > start)  //从上向下打印一列
	{
		for (i = start+1; i <= endY; i++)
			cout << nums[i][endX] << " ";
	}

	if (endX > start && endY > start) //从右向左打印一行
	{
		for (i = endX - 1; i >= start; i--)
			cout << nums[endY][i] << " ";
	}

	if (endX > start && endY - 1 > start)
	{
		for (i = endY - 1; i > start; i--)
			cout << nums[i][start] << " ";
	}
}

int main(void)
{
	vector<vector<int>> nums = { { 1, 2, 3, 4 }, 
								 { 5, 6, 7, 8 }, 
								 {9, 10, 11, 12},
								 { 13, 14, 15, 16 }
								};
	PrintClock(nums, nums.size(), nums[0].size());
	return 0;
}