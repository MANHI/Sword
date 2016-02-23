#include<iostream>
#include<string>
#include<vector>

using namespace std;

void Reverse(char *start, char *end)
{
	if (start == NULL || end == NULL)
		return;

	while (start < end)		//���ý�������ת
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
			Reverse(start, --end);  //��β�ַ����ܷ�ת�������1�����һ���ַ�
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