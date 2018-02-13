#define _CRT_SECURE_NO_WARNINGS
#define _CPP_OVERLOAD_SECURE_FUNC_SPLITPATH
#include<stdlib.h>
#include<stdio.h>
int main(void) {

	char*** arr = (char***)malloc(sizeof(char**) * 20);
	for (int i = 0; i < 20; i++) {
		arr[i] = (char**)malloc(sizeof(char*) * 20);
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (i == 0) {
				char* ch1 = malloc(sizeof(char)*4);
				sprintf(ch1, "%d", j);
				arr[i][j] = ch1;
			}
			else if (i == 19) {
				char* ch1 = malloc(sizeof(char) * 4);
				sprintf(ch1, "%d", j);
				arr[i][j] = ch1;
			}
			else if (j == 19||j==0) {
				char* ch1 = malloc(sizeof(char) * 4);
				sprintf(ch1, "%d", i);
				arr[i][j] = ch1;
			}
			else {
				arr[i][j] = "бс";
			}

		}
	}
	

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			printf("%2s ", arr[i][j]);

		}
		puts(" ");
	}


	char str[20][5] = { NULL, };
	for (int i = 0; i < 20; i++) {
		sprintf(str[i], "%d ", i);
	}
	
	printf("%s\n", str[2]);
	



	return 0;
}

