#include<stdio.h>
#include<windows.h>

void ShowBlock(char blockInfo[][4]);
void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos(void);

char blockModel[][4][4] =
{

	{
		{0,0,0,0},
		{1,0,0,0},
		{1,1,1,0},
		{0,0,0,0},
	},

	{
		{0,1,0,0},
		{0,1,0,0},
		{1,1,0,0},
		{0,0,0,0},
	},

	{
		{0,0,0,0},
		{1,1,1,0},
		{0,0,1,0},
		{0,0,0,0},
	},

	{
		{0,0,0,0},
		{1,1,0,0},
		{1,0,0,0},
		{1,0,0,0},
	},
};

int main(void)
{

	GetCurrentCursorPos(0, 0);
	ShowBlock(blockModel[0]);

	GetCurrentCursorPos(0, 8);
	ShowBlock(blockModel[1]);

	GetCurrentCursorPos(12, 0);
	ShowBlock(blockModel[2]);

	GetCurrentCursorPos(12, 8);
	ShowBlock(blockModel[3]);
	getchar();


	return 0;
}

void ShowBlock(char blockInfo[][4])
{
	int y, x;
	COORD curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);
			if (blockInfo[y][x] == 1)
				printf("бс");
		}
	}
	SetCurrentCursorPos(curPos.X, curPos.Y);
}

void SetCurrentCursorPos(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}