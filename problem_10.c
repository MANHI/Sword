#include <iostream>
/*把一个整数减去1之后再和原来的整数做位与运算，得到的结果相当于是把整数最右边的1换成0*/
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
