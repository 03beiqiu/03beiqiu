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
	//�׵Ĵ洢
	//1.���úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };//11*11
	//2.�Ų�ĳ��׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	/*DispalyBoard(mine, ROW, COL);*/
	DispalyBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	//ɨ��
	FindMine(mine,show,ROW,COL);
}	
void test()
{
	int input=0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}

	} while (input);

}
int main()
{
	test();
	return 0;
}