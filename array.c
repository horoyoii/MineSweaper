#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
	// 2�����迭
	// int�� ���� 4��¥�� 1���� �迭�� 2���� �迭�� ��Ұ� �ȴ�.
	int num[3][4] = { {1,2,3,4}, {5,6,7,8},{9,10,11,12} };
	printf("%d\n", num[2][2]);
	printf("%p\n", num);
	printf("%p\n", &num[0][0]); // �κй迭�� ÷�� 
	printf("%p\n", num[0]); // �κй迭 
	printf("%p\n", num[1]);

	char animal[5][10] = { "abce", "dog", "rion" };
	printf("%c\n", animal[0][2]);

	char* arry[5] = { "dog", "ass", "yourr" };
	printf("%s\n", arry[2]);
	// ���ڿ� ����� �������̴�. 

	//char animal[5][10] = { "dog","elephant", "horse", "tiger", "lion" }; 
	// 2���� ���ڹ迭�� �ʱ�ȭ�ϴ� ���� ��� ���ڿ��� �迭�� ����Ǵ� ��
	//char* animal[5] = { "dog","elephant", "horse", "tiger", "lion" };
	// �����͹迭�� �ʱ�ȭ�Ǵ� ���� �����͸� �ʱ�ȭ�Ǵ� ��

	char ch[30][30][3];
	*(ch[0][0]) = "s";
	ch[0][0][0] = 'c';
	ch[0][0][1] = 's';
	printf("%c", *(ch[0][0]));

	char* ch1[3][3] = { "��", };
	ch1[0][0] = "��";
	printf("%s\n", ch1[0][1]);
	puts("");


	// memset(arr, 0, sizeof(arr));//arr�� �޸𸮸� 0���� ����

	char* ch1[20][20];

	memset(ch1, "aa", sizeof(ch1));


}