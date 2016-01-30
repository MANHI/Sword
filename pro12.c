#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*打印从1到最大的n位数，用字符串模拟加法解决*/
bool AddNum(vector<char> &res)
{
	int i, j, bit = 0;
	int flag = 0;
	int nsum = 0;
	bool isOverflow = true;
	for (i = res.size() - 1; i >= 0; i--) //从最低位开始
	{
		nsum = res[i] - '0' + flag;
		if (i == res.size() - 1)  //最低位的话加1
			nsum++;
		if (nsum >= 10)
		{
			if (i == 0)
				isOverflow = false;
			else
			{
				res[i] = nsum - 10 + '0';
				flag = 1;  //进位
			}
		}
		else  //无进位，最低位加1，打印出
		{
			res[i] = '0' + nsum;
			break;
		}
	}
	return isOverflow;
}

void PrintNum(const vector<char> res)
{
	string str;
	int flag = 0; 
	for (int i = 0; i < res.size(); i++)
	{
		if (res[i] == '0' && flag == 0)
			continue;
		else
		{
			str += res[i];
			flag = 1;
		}
	}
	cout << str << " ";
}

int main(void)
{
	int n;
	cin >> n;
	vector<char> res(n,'0');
	while (AddNum(res))
	{
		PrintNum(res);
	}
	return 0;
}