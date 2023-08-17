#include<stdio.h>
#include"game.h"
void menu()
{
	printf("**************************\n");
	printf("******   1.play  *********\n");
	printf("******   0.exit  *********\n");
	printf("**************************\n");
}

void game()
{
	//雷的存储
	//1.布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };//11*11
	//2.排查的出雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	/*DispalyBoard(mine, ROW, COL);*/
	DispalyBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	//扫雷
	FindMine(mine,show,ROW,COL);
}	
void test()
{
	int input=0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择！\n");
			break;
		}

	} while (input);

}
int main()
{
	test();
	return 0;
}