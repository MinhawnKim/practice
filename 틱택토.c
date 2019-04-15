#include <stdio.h>
#include <stdlib.h>

void main(void) {
	printf("Let's play TIC TAC TO!!!!!!!\n"); //������
	printf("VS Player Mode : 1\n");
	printf("VS Computer Mode : 2\n");
	printf("Select Game Mode >>>");
	char gamemode = getchar(); // ���� ��� �Է�
	printf("\n\n"); 

	//���� �ʱ�ȭ ����
	int x, y;	
	char BLANK = ' ';	
	char board[3][3];
	for (x = 0; x < 3; x++) {
		for (y = 0; y < 3; y++) {
			board[x][y] = BLANK;
		}
	}
	//���� �ʱ�ȭ ��

	int turnNumber = 0; //�� ����
	
	while (1) {

		//������ �׸��� ����
		system("cls");
		int a;
		printf("x|y[0]|[1]|[2]\n");
		for (a = 0; a < 3; a++) {
			printf("   ---|---|---\n");	//����Ʋ
			printf("[%d] %c | %c | %c \n", a, board[a][0], board[a][1], board[a][2]); //ǥ�����ִ°�
		}
		printf("   ---|---|---\n"); //�Ʒ���Ʋ
		//������ �׸��� ��

		//���� ���� Ȯ�� ����
		int ix, iy;//�ݺ����� ���� ����
		char winner = 'A';	//winner : ������ ǥ�� ���� (O, X)
		//������
		for (ix = 0; ix < 3; ix++) {	//2���� �迭 x��ǥ�� ���� ������(������ Ȯ��)
			if (board[ix][0] == board[ix][1] && board[ix][2] == board[ix][1]) {
				winner = board[ix][0];
			}
		}
		//������
		for (iy = 0; iy < 3; iy++) { //y��ǥ�� �����ϴ� �ݺ��� (������ Ȯ��)
			if (board[0][iy] == board[1][iy] && board[2][iy] == board[1][iy]) {
				winner = board[0][iy];
			}
		}
		//�밢��
		if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
			winner = board[1][1];
		}
		if (winner == 'O' || winner == 'X') {	//���ڰ� ������ ��� ó��
			if (gamemode == '1') {
				if (winner == 'O') {	// O�� ���� �÷��̾�
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
		if (turnNumber > 8) {	// 9�� ���ĺ��ʹ� ���º�
			printf("****DRAW****\n");
			break;
		}
		//���� ���� Ȯ�� ��
		

		//�� ����
		if (gamemode == '1') {	// Vs ��� �϶�
			if (turnNumber % 2 == 0) {	// ¦��,Ȧ���� �� �÷��̾�(O, X) ����
				while (1) {	//��ǥ�� ����� �Էµ��������� ��� �ݺ�
					printf("Turn %d\n", turnNumber);
					printf("Player 1's turn (x y) :");	
					scanf_s("%d %d", &x, &y);
					if (board[x][y] != BLANK) {		//�̹� ǥ�õ� ���� �����Ұ�� ����
						printf("Wrong Position!!\n");
					}
					else {
						break; //����� ��ǥ�� ���������� �ݺ����� ��������
					}
				}
				board[x][y] = 'O';	// ���ǿ� ����
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
		else if (gamemode == '2') {	// Vs ��ǻ�� �϶�
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
				//��ǻ�ʹ� �� ���ᰡ �ʹ� ���� �� �ȳ��� �ʿ����
				
				do {	// ��ǻ�ʹ� ��� �Ȱ��� ���� �� �� �� ����
					x = rand() % 4;
					y = rand() % 4;
				} while (board[x][y] != BLANK);
				board[x][y] = 'X';
			}
		}
		turnNumber++; //����� ���ÿ� 1������
		//�� ����
	}
}
