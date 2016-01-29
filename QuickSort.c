#include<iostream>
#include<vector>
using namespace std;

int MergeSort(vector<int> &num,int low, int high)
{
	int start = low;
	int end = high;
	int c = num[end];  //基准数
	int tmp = 0;
	int index = start - 1;
	for (int i = start; i < end; i++)
	{
		if (num[i] <= c)
		{
			index++;
			if (index != start - 1)   //important
			{
				tmp = num[index];
				num[index] = num[i];
				num[i] = tmp;
			}
		}
	}
	tmp = num[index+1];
	num[index+1] = num[end];
	num[end] = tmp;
	return index + 1;
}

void QuickSort(vector<int> &num, int low, int high)
{
	int partion;
	int start = low;
	int end = high;
	partion = MergeSort(num,start, end);
	if (partion > start)
		QuickSort(num, start, partion - 1);
	if (partion < end)
		QuickSort(num,partion + 1, end);
}

int main(void)
{
	vector<int> num = { 11, 3, 2, 5, 6, 4, 6, 9 };
	int len = num.size();
	QuickSort(num,0, len - 1);
	for (auto &a : num)
		cout << a << " ";
	cout << endl;
}