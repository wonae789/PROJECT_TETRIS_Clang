#include<stdio.h>
#include<windows.h>

void ShowBlock(char blockInfo[][4]);
void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos(void);
void RemoveCursor(void);

char blockModel[][4][4] =
{

	{
		{0,0,0,0},	// 0
		{1,0,0,0},
		{1,1,1,0},
		{0,0,0,0}
	},

	{
		{0,1,0,0},	// 1
		{0,1,0,0},
		{1,1,0,0},
		{0,0,0,0}
	},

	{
		{0,0,0,0},	// 2
		{1,1,1,0},
		{0,0,1,0},
		{0,0,0,0}
	},

	{
		{0,0,0,0},	// 3
		{1,1,0,0},
		{1,0,0,0},
		{1,0,0,0}
	},

	{
		{0,0,0,0},	// 4
		{0,0,1,0},
		{1,1,1,0},
		{0,0,0,0}
	},

	{
		{0,0,0,0},	// 5
		{0,1,1,0},
		{0,0,1,0},
		{0,0,1,0}
	},

	{
		{0,0,0,0},	// 6
		{0,1,1,1},
		{0,1,0,0},
		{0,0,0,0}
	},

	{
		{0,1,0,0},	// 7
		{0,1,0,0},
		{0,1,1,0},
		{0,0,0,0}
	},

	{
		{0,0,0,0},	// 8
		{0,1,0,0},
		{1,1,1,0},
		{0,0,0,0}
	},

	{
		{0,0,0,0},	// 9
		{0,1,0,0},
		{1,1,0,0},
		{0,1,0,0}
	},

	{
		{0,0,0,0},	// 10
		{0,0,0,0},
		{1,1,1,0},
		{0,1,0,0}
	},

	{
		{0,0,0,0},	// 11
		{0,1,0,0},
		{0,1,1,0},
		{0,1,0,0}
	},

	{
		{0,1,0,0},	// 12
		{0,1,0,0},
		{0,1,0,0},
		{0,1,0,0}
	},

	{
		{0,0,0,0},	// 13
		{0,0,0,0},
		{1,1,1,1},
		{0,0,0,0}
	},

	{
		{0,1,0,0},	// 14
		{0,1,0,0},
		{0,1,0,0},
		{0,1,0,0}
	},

	{
		{0,0,0,0},	// 15
		{0,0,0,0},
		{1,1,1,1},
		{0,0,0,0}
	},

	{
		{0,0,0,0},	// 16
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}
	},

	{
		{0,0,0,0},	// 17
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}
	},

	{
		{0,0,0,0},	// 18
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}
	},

	{
		{0,0,0,0},	// 19
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}
	},

	{
		{0,0,0,0},	// 20
		{0,1,1,0},
		{1,1,0,0},
		{0,0,0,0}
	},

	{
		{1,0,0,0},	// 21
		{1,1,0,0},
		{0,1,0,0},
		{0,0,0,0}
	},

	{
		{0,0,0,0},	// 22
		{0,1,1,0},
		{1,1,0,0},
		{0,0,0,0}
	},

	{
		{1,0,0,0},	// 23
		{1,1,0,0},
		{0,1,0,0},
		{0,0,0,0}
	},

	{
		{0,0,0,0},	// 24
		{1,1,0,0},
		{0,1,1,0},
		{0,0,0,0}
	},

	{
		{0,1,0,0},	// 25
		{1,1,0,0},
		{1,0,0,0},
		{0,0,0,0}
	},

	{
		{0,0,0,0},	// 26
		{1,1,0,0},
		{0,1,1,0},
		{0,0,0,0}
	},

	{
		{0,1,0,0},	// 27
		{1,1,0,0},
		{1,0,0,0},
		{0,0,0,0}
	},

};

int main(void)
{
	RemoveCursor();



	SetCurrentCursorPos(0, 0); // 콘솔 커서 위치 를 변경하는 기능의 함수. MS에서 정한것. x갑이 증가하면 오른쪽, y값이 증가하면 아래쪽으로 이동
	
	for (int i = 0; i < 28; i++)
	{
	SetCurrentCursorPos(0, i);
	ShowBlock(blockModel[0]);
	Sleep(1000);
	system("cls");
	
	}

	
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
				printf("■");
		}
	}
	SetCurrentCursorPos(curPos.X, curPos.Y);
}

void SetCurrentCursorPos(int x, int y) // 좌표를 입력받아서 커서의 위치를 이동시킴.
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

COORD GetCurrentCursorPos(void) // 현재 커서의 위치정보를 반환한다.
{
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);// 콘재 콘솔창의 위치 좌표를 출력해준다.
	curPoint.X = curInfo.dwCursorPosition.X;
	curPoint.Y = curInfo.dwCursorPosition.Y;

	return curPoint;
}

void RemoveCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}