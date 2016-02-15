#include <iostream>
using namespace std;

int FindGreateSumOfSubarray(int pdate[], int nLength)
{
	if (nLength <= 0)
		return 0;
	int nCursum = 0;
	int nGreatestSum = -1;
	for (int i = 0; i < nLength; i++)
	{
		if (nCursum <= 0)
			nCursum = pdate[i];
		else
			nCursum += pdate[i];
		if (nCursum > nGreatestSum)
			nGreatestSum = nCursum;
	}
	return nGreatestSum;
}

int main(void)
{
	int pdate[9] = { -3, 2, 2, 10, -8, -7, 2, -5 };
	int result;
	result = FindGreateSumOfSubarray(pdate, 8);
	cout << result << endl;
	return 0;
}