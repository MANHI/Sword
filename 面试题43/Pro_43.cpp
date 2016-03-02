#include"Pro_43.h"

using namespace std;

#define Max_number 6

/*求n个骰子点数和出现的概率*/
void Probability(const int num, vector<int>& res)
{
	for (int i = 1; i <= Max_number; i++)
		Probability(num, num, i, res);
}

void Probability(int original, int current,int sum,vector<int>& res)
{
	if (current == 1)
	{
		res[sum - original]++;
	}
	else
	{
		for (int i = 1; i <= Max_number; i++)
			Probability(original, current - 1, sum + i, res);
	}
}

int main(void)
{
	int num,i;
	cin >> num;
	vector<int> res;
	for (i = 0; i < Max_number*num + 1 - num; i++)
		res.push_back(0);
	Probability(num, res);
	for (i = 0; i < Max_number*num + 1 - num; i++)
	{
		cout << "value:  " << i + num << "  probability is : " << (int)res[i] / pow(Max_number, num) << endl;
	}
	return 0;

}