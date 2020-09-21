#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"		  

//Init Board()��������ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set){
	int i = 0;
	int j = 0;
	for (i = 0; i < rows;i++){
		for (int j = 0; j < cols; j++){
			board[i][j] = set;
		}
	}
}

//DisplayBoard()��������11 * 11��������ʾΪ9 * 9�����̴�ӡ����
void  DisplayBoard(char board[ROWS][COLS], int row, int col){
	int i = 0;
	int j = 0;
	printf("--------------------------\n");
	//�кŵĴ�ӡ
	for (i = 0; i <= col; i++){
		printf("%d",i);
	}
	printf("\n");
	for (i = 1; i <= row; i++){
		//ÿһ��ǰ����к�
		printf("%d",i);
		for (j = 1; j <= col; j++){
			printf("%c",board[i][j]);
		}
		printf("\n");
	}
	printf("---------------------------\n");

}

// SetMine()������������
void SetMine(char mine[ROWS][COLS], int row, int col){
	//1.��������겼����
	//���ö��ٸ���-10��
	int count = EASY_COUNT;
	while (count){
	//���óɹ�һ����count--;
		//1.�����������
		//rand()����ʹ��֮ǰ�������srand()����
		int x = rand() % row + 1;//����1-9�������
		int y = rand() % col + 1;
		// 2.����
		if (mine[x][y] == '0'){
			mine[x][y] = '1';
			count--;
		}
	}
}


//GetMineCount()����:ʹ�ô�������Χ���ַ�'1'- '0' = 1����ø���
int GetMineCount(char mine[ROWS][COLS], int x, int y){
	return  mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y + 1] +
		mine[x + 1][y] +
		mine[x - 1][y + 1] - 8 * '0';
}
	//FindMine()������ɨ��
	void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col){
		int x = 0;
		int y = 0;
		int win = 0;

		while(win < ROW * COL - EASY_COUNT){
		//while (1){
			printf("������Ҫ�Ų�����꣺");
			scanf("%d%d", &x, &y);
			if (x >= 1 && x <= row && y >= 1 && y <= col){
				//�ж�(x,y)���괦�Ƿ�����
				if (mine[x][y] == '1'){
					printf("���ź����˴����ף�\n");
					DisplayBoard(mine, row, col);
					break;
				}
				else{
					//���(x,y)���괦������	 ����ͳ�ƴ�������Χ�м�����
					int count = GetMineCount(mine, x, y);
					//����mine��ͳ�Ƶ��׵ĸ���ʹ��count + '0'д��show����ʾ
					show[x][y] = count + '0';
					DisplayBoard(show, ROW, COL);

				}
			}
			else{
				printf("���겻�Ϸ������������룡");
			}
		}
		if (win == ROW * COL - EASY_COUNT){
			printf("��ϲ�����׳ɹ���");
			DisplayBoard(mine,row,col);
		}

	}




