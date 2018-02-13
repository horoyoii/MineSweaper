#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int num1 = 63421;
	long num2 = 92357234;
	char s[25];

	sprintf(s, "%d", num1);

	char* str[3][3] = { NULL, };

	

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			char s1[5];
			sprintf(s1, "%d", i*j);
			str[i][j] = s1;
			printf("%s", str[i][j]);
		}
		puts(" ");
	}

	return 0;
}