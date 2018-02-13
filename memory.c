# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>



char* ReadUserName() {
	char* name = (char*)malloc(sizeof(char) * 20);
	gets(name);
	return name;
}


int main(void) {
	char* name1;
	char* name2;
	name1 = ReadUserName();
	printf("name1 : %s\n", name1);
	name2 = ReadUserName();
	printf("name2 : %s\n", name2);

	printf("name1 : %s\n", name1);
	printf("name2 : %s\n", name2);


	free(name1);
	free(name2);
	return 0;
}
