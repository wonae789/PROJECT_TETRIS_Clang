#include<conio.h>
#include<Windows.h>
#include"point.h"
#include"blockStageControl.h"

#define KEY_SENSITIVE 100
#define SYS_DELAY 20

#define LEFT 75
#define UP 72
#define RIGHT 77
#define DOWN 80

static int keyDelayRate; // 값 클수록 속도가 증가


// 함수 : void RemoveCursor(void)
// 기능 : 깜빡표시 제거
// 반환 : void

void RemoveCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo); // 콘솔 깜박이 없애는기능
}

// 함수 : point GetCurrentCursorPos(void)
// 기능 : 커서 위치 정보 담은 구조체 변수를 반환
// 반환 : point

point GetCurrentCursorPos(void)
{
	point curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;// 콘솔 출력창의 정보를 담기 위한 구조체. 제공되는것.

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint.x = curInfo.dwCursorPosition.X;
	curPoint.y = curInfo.dwCursorPosition.Y;

	return curPoint;
}

// 함수 : void SetCurrentCursorPos(int x, int y)
// 기능 : 커서 위치를 설정
// 반환 : void

void SetCurrentCursorPos(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 함수 : void ProcessKeyInput(void)
// 기능 : 키 입력 블록 이동
// 반환 : void


void ProcessKeyInput(void)
{
	int i;
	int key;

	for (i = 0; i < KEY_SENSITIVE; i++)
	{
		if (_kbhit() != 0) // _kbhit 키가 입력이 되있는지 안되었는지 확인하는 함수
			               // _kbhit는 입력되면 true를 반환함

		{
			key = _getch();// _getch 는 conio.h에 선언됨, Enter 키 입력을 요구하지 않음.
			               // 입력받기 전까지 STOP 상태가 된다.
			               //        echo 하지도 않아서 입력내용이 화면에 보여주지 않음.
			               // 키 입력하면 그 키의 아스키코드값을 반환함.
			// 블록 이동
			switch (key) // 오른쪽 - 77, 왼쪽 - 75 , 아래 - 80
			{
			case RIGHT:
				BlockRight();
				break;
			case LEFT:
				BlockLeft();
				break;
			case UP:
				BlockRotate();
				break;
			case DOWN:
				BlockDown();
				break;

			}
		}

		if (i % keyDelayRate == 0) // 나머지 연산. keyDelayRate 5면, 키입력검사 5회당 1번씩 실행됨.
			Sleep(SYS_DELAY); // Sleep 함수는 Windows.h 헤더에 정의됨.
	}
}

void InitKeyDelayRate(int rate)
{
	if (rate < 1)
		return;
	keyDelayRate = rate;
}