#define _CRT_SECURE_NO_WARNINGS 1
# include "game.h"


//menu()函数用以打印扫雷游戏的菜单
void menu(){
	printf("**********************\n");
	printf("*****扫雷小游戏*******\n");
	printf("******1 .play ********\n");
	printf("******0 .exit ********\n");
	printf("**********************\n");
	
}

//game()函数：扫雷游戏的实现过程
void game(){

	//存放布置好的雷
	char mine[ROWS][COLS] = {0};		 // '0'	 
	//存放排查出来的雷的信息	
	char show[ROWS][COLS] = {0};		   // '*'
	//初始化棋盘
	InitBoard(mine,ROWS,COLS,'0');		//初始化布置雷的棋盘
	InitBoard(show,ROWS,COLS, '*');		//初始化排查后雷的信息的棋盘
	 
	//DisplayBoard()函数：显示棋盘
	DisplayBoard(show,ROW,COL);
	//布置好的雷的信息不应该轻易打印
	//DisplayBoard(mine ,ROW,COL);
	//1.布置雷
	SetMine(mine,ROW,COL);
	DisplayBoard(mine,ROW,COL);
	//2.扫雷
	FindMine(mine,show,ROW,COL);
}
int main(){
	int input = 0;
	//srand()函数用于设置随机数的生成起点的(一般取时间戳(时间戳由time()函数返回)作为起点)
	//time_t类型：即整型
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请输入你的选择：");
		scanf("%d",&input);
		switch (input){
		case 1:
			//扫雷游戏
			game();
			break;
		case 0:
			printf("退出游戏!\n");
			break;
		default:
			printf("选择错误，请重新输入你的选择。\n");
			break;
		}

	} while (input);
	return 0;
}