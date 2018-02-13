#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
// 지뢰찾기 20x20
// x축 1~20 
// y축 1~20

//========================================
// 입력받은 x, y 좌표에 대한 구조체
//========================================
typedef struct {
	int x;
	int y;
}Point;

void setup(char** (*ptr)[20]);
void ShowBoard(char** (*ptr)[20]); // "openboard"의 자료형(인자의 자료형)이 char** / 뒤의 (*ptr)[20] 는 2차원배열을 나타냄
void setup1(int* (*ptr)[20]); // int형을 의 주소값을 
void ShowBoard1(int* (*ptr)[20]);
void Choice(char** (*ptMboard)[20], int* (*ptJboard)[20]);
void Check(Point);
void CheckIfmine(Point*, int*);
void CheckIfwin(int*);
void flag(Point*);

//========================================
// 지뢰찾기 판
// 1. board : 지뢰가 배치된 보드
// 2. openBoard : 사용자에게 출력될 보드
// 3. 입력된 x,y좌표를 board판에서 비교하여 openBoard에 결과를 넘겨주어 출력한다.
//========================================
int board[20][20] = { 0, };
char* openBoard[20][20] = { NULL, };





int main(void) {
	printf("지뢰찾기\n");
	
	//========================================
	// 초기설정
	//========================================
	setup(openBoard); // char* 자료형을 담고 있는 변수의 주소값을 보낸다. 매개변수는 char**형 (*ptr)[20]
	setup1(board); // 지뢰가 배치된 보드

	ShowBoard(openBoard); 
	//ShowBoard1(board);



	//========================================
	// 지뢰찾기 이벤트 루프 시작
	//========================================
	Point pos = { 0,0 };
	int fail = 1;
	while (fail) {
		int choice;
		printf("좌표 입력 : (x, y)\n");
		scanf("%d", &pos.x);
		scanf("%d", &pos.y);
		puts("1.확인 2.깃발세우기");
		scanf("%d", &choice);
		// 좌표 확인
		if (choice == 1) {
			Check(pos);  // 
			ShowBoard(openBoard);

			// 패배 조건식
			// 선택된 좌표의 값이 1일 경우(지뢰인 경우) 패배 -> 종료
			CheckIfmine(&pos, &fail); // 지뢰인지 확인 후 이벤트 종료하는 함수

			// 승리 조건식
			// openBoard판에 남이있는 "■"의 갯수가 board판의 1의 갯수(지뢰의 갯수)와 동일해지면 승리 -> 종료
			CheckIfwin(&fail);
		}

		// 좌표 깃발세우기
		else if(choice == 2) {
			flag(&pos);
			ShowBoard(openBoard);
		}
		else {
			printf("1과 2 중 하나를 입력해주세요.\n");
		}
	}
	




	
	
	

	return 0;
}

//=============================================
// 보여질 화면 초기세팅
//=============================================
// 1. 0행 마지막행 0열 마지막열은 x, y좌표로 출력
// 2. 나머지 칸은 ■ 로 출력
//=============================================
void setup(char** (*ptr)[20]) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (i == 0 || i == 19) {
				char* ch1 = malloc(sizeof(char) * 4);
				sprintf(ch1, "%d", j);
				ptr[i][j] = ch1;
			}
			else if (j == 0 || j == 19) {
				char* ch1 = malloc(sizeof(char) * 4);
				sprintf(ch1, "%d", i);
				ptr[i][j] = ch1;
			}
			else {
				ptr[i][j] = "■";
			}
		
		}
	}
}
//=============================================
// 현재 상황 출력되는 보드판
//=============================================

void ShowBoard(char** (*ptr)[20]) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			printf("%2s ", ptr[i][j]);
		}
		puts(" ");
	}
}




//=============================================
// 지뢰가 배치될 보드 설정(숨은 보드)
//=============================================
// 1. 3으로 나뉘어 나머지가 0이면 지뢰 나머지이면 지뢰아님
// 2. 2는 테두리를 의미
// 3. 1이면 지뢰.
// 4. 0이면 지뢰아님.
//=============================================
void setup1(int* (*ptr)[20]) {
	srand(time(NULL));
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (i == 0 || i == 19) {
				ptr[i][j] = 2;
			}
			else if (j == 0 || j ==19) {
				ptr[i][j] = 2;
			}
			else {
				if (rand() % 7 == 0) { // 난이도 조절 가능
					ptr[i][j] = 1;
				}
				else {
					ptr[i][j] = 0;
				}
			}
		}
	}
}
//=============================================
// 지뢰현황 출력되는 보드판
//=============================================
void ShowBoard1(int* (*ptr)[20]) {
	puts(" ");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			printf("%2d ", ptr[i][j]);
		}
		puts(" ");
	}

}

void Choice(char** (*ptMboard)[20], int* (*ptJboard)[20]) {

}


//========================================
// 입력받은 x,y좌표에 해당하는 값을 보드판에서 확인한다.
//========================================
// 1. 그 값이 1이면 지뢰 -> 0을 반환하여 게임종료
// 2. 그 값이 0이면 지뢰x ->
//========================================

void Check(Point ptr) {
	int x = ptr.x;
	int y = ptr.y;
	int t = board[x][y];
	if (strcmp(openBoard[x][y], "■")) {
		return;
	}

	if (t == 1) {
		openBoard[x][y] = "★";
		return;
	}
	else if (t == 0) {

		int sum = 0;
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if (board[x + i][y + j] == 1) {
					sum += 1;
				}


			}
		}


		if (sum != 0) {
			char* ch1 = (char*)malloc(sizeof(char) * 5);
			sprintf(ch1, "%d", sum);
			openBoard[x][y] = ch1;
			return;
		}
		else {
			char* ch1 = (char*)malloc(sizeof(char) * 5);
			ch1 = "□";
			openBoard[x][y] = ch1;
			//Check(&pos) 형으로 main에서 넘김받았다.
			Point pos1 = { 0, 0 };
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					pos1.x = x + i;
					pos1.y = y + j;
					Check(pos1);
				}

			}
		}
	}
	else {
		int n = 0;
	}

}

//========================================
// 패배 조건식
//========================================

void CheckIfmine(Point* ptr, int* ptrr) {
	if (board[ptr->x][ptr->y] == 1) {
		*ptrr = 0;
		puts("지뢰입니다. GameOver\n");
	} 
}



//========================================
// 승리 조건식
//========================================
void CheckIfwin(int* ptr) {
	int sum = 0;
	int sum1 = 0;
	for (int i = 1; i < 19; i++) {
		for (int j = 1; j < 19; j++) {
			if (board[i][j] == 1) {
				sum++;
			}
		}
	}

	for (int i = 1; i < 19; i++) {
		for (int j = 1; j < 19; j++) {
			if (!strcmp(openBoard[i][j], "▷")) {
				sum1++;
			}
		}
	}
	if (sum == sum1) {
		*ptr = 0;
		puts("\n====!!승리!!====\n");
	}
}

void flag(Point* pt) {
	openBoard[pt->x][pt->y] = "▷";
}