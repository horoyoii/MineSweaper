#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
	// 2차원배열
	// int형 변수 4개짜리 1차원 배열이 2차원 배열의 요소가 된다.
	int num[3][4] = { {1,2,3,4}, {5,6,7,8},{9,10,11,12} };
	printf("%d\n", num[2][2]);
	printf("%p\n", num);
	printf("%p\n", &num[0][0]); // 부분배열의 첨자 
	printf("%p\n", num[0]); // 부분배열 
	printf("%p\n", num[1]);

	char animal[5][10] = { "abce", "dog", "rion" };
	printf("%c\n", animal[0][2]);

	char* arry[5] = { "dog", "ass", "yourr" };
	printf("%s\n", arry[2]);
	// 문자열 상수는 포인터이다. 

	//char animal[5][10] = { "dog","elephant", "horse", "tiger", "lion" }; 
	// 2차원 문자배열에 초기화하는 것은 모든 문자열이 배열에 복사되는 것
	//char* animal[5] = { "dog","elephant", "horse", "tiger", "lion" };
	// 포인터배열에 초기화되는 것은 포인터만 초기화되는 것

	char ch[30][30][3];
	*(ch[0][0]) = "s";
	ch[0][0][0] = 'c';
	ch[0][0][1] = 's';
	printf("%c", *(ch[0][0]));

	char* ch1[3][3] = { "□", };
	ch1[0][0] = "□";
	printf("%s\n", ch1[0][1]);
	puts("");


	// memset(arr, 0, sizeof(arr));//arr의 메모리를 0으로 설정

	char* ch1[20][20];

	memset(ch1, "aa", sizeof(ch1));


}