#include<iostream>
#include<vector>
using namespace std;

bool IsBit1(int num, int index)
{
	num = num >> index;
	return (num & 1);
}

int FindFirst1(int num)
{
	int result, flag = 1;
	int bitnum = 0;
	while (flag <= num)
	{
		if (num & flag)
			break;
		flag = flag << 1;
		bitnum++;
	}
	return bitnum;
}

vector<int> FindOnceNum(const vector<int> num)
{
	vector<int> array1, array2,result;
	int res1 = 0, res2 = 0;
	int index;
	if (num.size() < 1)
		return result;
	int n = num[0];
	for (int i = 1; i < num.size(); i++)
		n ^= num[i];
	index = FindFirst1(n);
	for (int j = 0; j < num.size(); j++)
	{
		if (IsBit1(num[j], index))
			res1 ^= num[j];
		else
			res2 ^= num[j];
	}
	result.push_back(res1);
	result.push_back(res2);
	return result;
}

int main(void)
{
	vector<int> num = { 1, 2, 3, 1, 2, 4, 4, 5, 5 ,6};
	vector<int> res;
	res = FindOnceNum(num);
	cout << res[0] << endl;
	cout << res[1] << endl;
	return 0;
}