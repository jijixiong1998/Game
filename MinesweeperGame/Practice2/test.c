#define _CRT_SECURE_NO_WARNINGS 1
# include "game.h"


//menu()�������Դ�ӡɨ����Ϸ�Ĳ˵�
void menu(){
	printf("**********************\n");
	printf("*****ɨ��С��Ϸ*******\n");
	printf("******1 .play ********\n");
	printf("******0 .exit ********\n");
	printf("**********************\n");
	
}

//game()������ɨ����Ϸ��ʵ�ֹ���
void game(){

	//��Ų��úõ���
	char mine[ROWS][COLS] = {0};		 // '0'	 
	//����Ų�������׵���Ϣ	
	char show[ROWS][COLS] = {0};		   // '*'
	//��ʼ������
	InitBoard(mine,ROWS,COLS,'0');		//��ʼ�������׵�����
	InitBoard(show,ROWS,COLS, '*');		//��ʼ���Ų���׵���Ϣ������
	 
	//DisplayBoard()��������ʾ����
	DisplayBoard(show,ROW,COL);
	//���úõ��׵���Ϣ��Ӧ�����״�ӡ
	//DisplayBoard(mine ,ROW,COL);
	//1.������
	SetMine(mine,ROW,COL);
	DisplayBoard(mine,ROW,COL);
	//2.ɨ��
	FindMine(mine,show,ROW,COL);
}
int main(){
	int input = 0;
	//srand()���������������������������(һ��ȡʱ���(ʱ�����time()��������)��Ϊ���)
	//time_t���ͣ�������
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("���������ѡ��");
		scanf("%d",&input);
		switch (input){
		case 1:
			//ɨ����Ϸ
			game();
			break;
		case 0:
			printf("�˳���Ϸ!\n");
			break;
		default:
			printf("ѡ������������������ѡ��\n");
			break;
		}

	} while (input);
	return 0;
}