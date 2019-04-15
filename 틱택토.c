#include <stdio.h>
#include <stdlib.h>

void main(void) {
	printf("Let's play TIC TAC TO!!!!!!!\n"); //오프닝
	printf("VS Player Mode : 1\n");
	printf("VS Computer Mode : 2\n");
	printf("Select Game Mode >>>");
	char gamemode = getchar(); // 게임 모드 입력
	printf("\n\n"); 

	//말판 초기화 시작
	int x, y;	
	char BLANK = ' ';	
	char board[3][3];
	for (x = 0; x < 3; x++) {
		for (y = 0; y < 3; y++) {
			board[x][y] = BLANK;
		}
	}
	//말판 초기화 끝

	int turnNumber = 0; //턴 변수
	
	while (1) {

		//게임판 그리기 시작
		system("cls");
		int a;
		printf("x|y[0]|[1]|[2]\n");
		for (a = 0; a < 3; a++) {
			printf("   ---|---|---\n");	//위쪽틀
			printf("[%d] %c | %c | %c \n", a, board[a][0], board[a][1], board[a][2]); //표식이있는곳
		}
		printf("   ---|---|---\n"); //아랫쪽틀
		//게임판 그리기 끝

		//승자 유무 확인 시작
		int ix, iy;//반복문에 쓰일 변수
		char winner = 'A';	//winner : 승자의 표시 저장 (O, X)
		//가로줄
		for (ix = 0; ix < 3; ix++) {	//2차원 배열 x좌표가 점점 증가함(가로줄 확인)
			if (board[ix][0] == board[ix][1] && board[ix][2] == board[ix][1]) {
				winner = board[ix][0];
			}
		}
		//세로줄
		for (iy = 0; iy < 3; iy++) { //y좌표가 증가하는 반복문 (세로줄 확인)
			if (board[0][iy] == board[1][iy] && board[2][iy] == board[1][iy]) {
				winner = board[0][iy];
			}
		}
		//대각선
		if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
			winner = board[1][1];
		}
		if (winner == 'O' || winner == 'X') {	//승자가 있을때 출력 처리
			if (gamemode == '1') {
				if (winner == 'O') {	// O는 선공 플레이어
					printf("Player1 Win!!!!!!!!\n");
				}
				else {
					printf("Player2 Win.\n");
				}
			}
			else {
				if (winner == 'O') {
					printf("Player1 Win!!!!!!!!\n");
				}
				else {
					printf("Computer Win.\n");
				}
			}
			break;
		}
		if (turnNumber > 8) {	// 9턴 이후부터는 무승부
			printf("****DRAW****\n");
			break;
		}
		//승자 유무 확인 끝
		

		//턴 시작
		if (gamemode == '1') {	// Vs 사람 일때
			if (turnNumber % 2 == 0) {	// 짝수,홀수로 턴 플레이어(O, X) 구분
				while (1) {	//좌표가 제대로 입력되지않으면 계속 반복
					printf("Turn %d\n", turnNumber);
					printf("Player 1's turn (x y) :");	
					scanf_s("%d %d", &x, &y);
					if (board[x][y] != BLANK) {		//이미 표시된 곳을 지정할경우 오류
						printf("Wrong Position!!\n");
					}
					else {
						break; //제대로 좌표를 지정했을때 반복문을 빠져나옴
					}
				}
				board[x][y] = 'O';	// 말판에 저장
			}
			else {
				while (1) {
					printf("Turn %d\n", turnNumber);
					printf("Player 2's turn (x y) :");
					scanf_s("%d %d", &x, &y);
					if (board[x][y] != BLANK) {	
						printf("Wrong Position!!\n");
					}
					else {
						break;
					}
				}
				board[x][y] = 'X';
			}
		}
		else if (gamemode == '2') {	// Vs 컴퓨터 일때
			if (turnNumber % 2 == 0) {
				while (1) {
					printf("Turn %d\n", turnNumber);
					printf("Player's turn (x y) :");
					scanf_s("%d %d", &x, &y);
					if (board[x][y] != BLANK) {
						printf("Wrong Position!!\n");
					}
					else {
						break;
					}
				}
				board[x][y] = 'O';
			}
			else {
				//컴퓨터는 턴 종료가 너무 빨라서 턴 안내가 필요없음
				
				do {	// 컴퓨터는 계속 똑같은 곳에 둘 수 도 있음
					x = rand() % 4;
					y = rand() % 4;
				} while (board[x][y] != BLANK);
				board[x][y] = 'X';
			}
		}
		turnNumber++; //종료와 동시에 1턴증가
		//턴 종료
	}
}
