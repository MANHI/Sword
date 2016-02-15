#include<iostream>
using namespace std;

void Pre(char *pstr);
void Premutation(char *pstr, char *pbegin);

void Pre(char *pstr)
{
	if (pstr == NULL)
		return;
	Premutation(pstr, pstr);
}

void Premutation(char *pstr, char *pbegin)
{
	if (*pbegin == '\0')
		printf_s("%s ", pstr);
	else
	{
		for (char *pch = pbegin; *pch != '\0'; ++pch)
		{
			char temp = *pch;
			*pch = *pbegin;
			*pbegin = temp;
			Premutation(pstr, pbegin + 1);

			temp = *pch;
			*pch = *pbegin;
			*pbegin = temp;
		}
	}
}

int main(void)
{
	char s[5] = { 'a', 'b', 'c'};
	Pre(s);
	return 0;
}