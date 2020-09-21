#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"		  

//Init Board()函数：初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set){
	int i = 0;
	int j = 0;
	for (i = 0; i < rows;i++){
		for (int j = 0; j < cols; j++){
			board[i][j] = set;
		}
	}
}

//DisplayBoard()函数：将11 * 11的棋盘显示为9 * 9的棋盘打印出来
void  DisplayBoard(char board[ROWS][COLS], int row, int col){
	int i = 0;
	int j = 0;
	printf("--------------------------\n");
	//列号的打印
	for (i = 0; i <= col; i++){
		printf("%d",i);
	}
	printf("\n");
	for (i = 1; i <= row; i++){
		//每一行前面的行号
		printf("%d",i);
		for (j = 1; j <= col; j++){
			printf("%c",board[i][j]);
		}
		printf("\n");
	}
	printf("---------------------------\n");

}

// SetMine()函数：布置雷
void SetMine(char mine[ROWS][COLS], int row, int col){
	//1.随机找坐标布置雷
	//布置多少个雷-10个
	int count = EASY_COUNT;
	while (count){
	//布置成功一个雷count--;
		//1.生成随机坐标
		//rand()函数使用之前必须调用srand()函数
		int x = rand() % row + 1;//生成1-9的随机数
		int y = rand() % col + 1;
		// 2.布置
		if (mine[x][y] == '0'){
			mine[x][y] = '1';
			count--;
		}
	}
}


//GetMineCount()函数:使用此坐标周围的字符'1'- '0' = 1即求得个数
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
	//FindMine()函数：扫雷
	void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col){
		int x = 0;
		int y = 0;
		int win = 0;

		while(win < ROW * COL - EASY_COUNT){
		//while (1){
			printf("请输入要排查的坐标：");
			scanf("%d%d", &x, &y);
			if (x >= 1 && x <= row && y >= 1 && y <= col){
				//判断(x,y)坐标处是否是雷
				if (mine[x][y] == '1'){
					printf("很遗憾，此处是雷！\n");
					DisplayBoard(mine, row, col);
					break;
				}
				else{
					//如果(x,y)坐标处不是雷	 ，就统计此坐标周围有几个雷
					int count = GetMineCount(mine, x, y);
					//将从mine中统计的雷的个数使用count + '0'写入show中显示
					show[x][y] = count + '0';
					DisplayBoard(show, ROW, COL);

				}
			}
			else{
				printf("坐标不合法，请重新输入！");
			}
		}
		if (win == ROW * COL - EASY_COUNT){
			printf("恭喜，排雷成功！");
			DisplayBoard(mine,row,col);
		}

	}




