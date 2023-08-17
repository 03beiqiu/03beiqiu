#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0;i <= rows;i++)
	{
		for (j = 0;j <= cols;j++)
		{
			board[i][j] = set;
		}
	}
}

void DispalyBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列号
	for (i = 0;i <= row;i++)
	{
		printf("%d ", i);

	}
	printf("\n");
	for (i = 1;i <= row;i++)
	{
		printf("%d ", i);
		for (j = 1;j <= col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{ 
			board[x][y] = '1';
		    count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	return mine[x - 1][y - 1] +
		   mine[x - 1][y] +
	   	   mine[x - 1][y + 1] +
		   mine[x][y - 1] +
		   mine[x][y + 1] +
		   mine[x + 1][y - 1] +
		   mine[x + 1][y] +
		   mine[x + 1][y + 1] - 8 * '0';

}
void Expand(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
	if (get_mine_count(mine, x, y) == 0)
	{
		show[x][y] = '0';
		int i = 0;
		int j = 0;
		for (i = x - 1;i <= x + 1;i++)
		{
			for (j = y - 1;j <= y + 1;j++)
			{
				if (show[i][j] == '*' && i > 0 && i <= row && j > 0 && j <= col)
				{
					Expand(mine, show, row, col, i, j);
				}
			}
		}
	}
	else
	{
		show[x][y] = get_mine_count(mine, x, y) + '0';
	}
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win=0;
	//9*9-10=71
	while (1)
	{
		printf("请输入排查的坐标:>");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//坐标合法
			if (mine[x][y] == '1')
			{
				printf("很遗憾，被炸了\n");
				DispalyBoard(mine, row, col);
				break;
			}
			else//不是雷
				//计算几个雷
			{
				Expand(mine, show, row, col, x, y);
				/*int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';*/
			    //清空
			   /* get_mine_null(mine, x, y);
			    show[x][y] = count + '0';*/
				
				DispalyBoard(show, row, col);
				win++;
			}
		}
		else
			printf("输入坐标非法，请重新输入！\n");
	}
	if(win == row * col - EASY_COUNT)
	{
		printf("恭喜你，过关了！\n");
		DispalyBoard(mine, row, col);
	}
}