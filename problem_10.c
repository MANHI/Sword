#include <iostream>

using namespace std;
int Count(int n)
{
	int flag = 1;
	int count = 0;
	while(n)
	{
		++count;
		n = (n-1) & n;
	}
	return count;
}

int main(void)
{
	int n;
	cin >> n;
	cout << Count(n)<<endl;
	return 0;
}