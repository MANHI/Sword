#include<iostream>
#include<string>
#include<vector>

using namespace std;

void Reverse(char *start, char *end)
{
	if (start == NULL || end == NULL)
		return;

	while (start < end)		//利用交换来反转
	{
		char tmp;
		tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

void ReverseWordOrder(char *str)
{
	if (str == NULL)
		return;
	int len = 0;
	char *start = str, *end = str;
	while (*end != '\0')
		end++;			
	end--;			//The end points to the string

	Reverse(start, end);

	printf_s("%s\n", str);

	start = end = str;

	while (*start != '\0')
	{
		if (*start == ' ')
		{
			start++;
			end++;
		}
		else if (*end == ' ' || *end == '\0')
		{
			Reverse(start, --end);  //结尾字符不能翻转，必须减1到最后一个字符
			start = ++end;  
		}
		else
		{
			end++;
		}
	}
	printf_s("%s\n", str);
}

int main(void)
{
	char str[] = "i am a student.";
	ReverseWordOrder(str);
	return 0;
}