#include<iostream>
#include<vector>
using namespace std;

void PrintSequence(int small, int big);

void FindContinuousSeuence(int sum)
{
	int small = 1;
	int big = 2;
	int end = (sum + 1) / 2;
	int cur = big + small;
	while (small < end)
	{
		if (cur < sum)
		{
			big++;
			cur += big;
		}
		else if (cur > sum)
		{的
			cur -= small;
			small++;
		}
		else
		{
			PrintSequence(small, big);
			cur -= small;
			small++;
		}
	}
}

void PrintSequence(int small, int big)
{
	cout << small << "-" << big << endl;
}

int main(void)
{
	int sum;
	cin >> sum;
	FindContinuousSeuence(sum);
	return 0;
}