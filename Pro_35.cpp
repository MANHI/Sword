#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
	unordered_map<char,int> map;  //哈希表
	char *str = "abaccdeff";
	if (str == NULL)
		return -1;
	for (char *index = str; *index != '\0'; index++)
		map[*index]++;
	for (char *index = str; *index != '\0'; index++)
	{
		if (map[*index] == 1)
		{
			cout << *index << endl;
			break;
		}
	}
	return 0;
}