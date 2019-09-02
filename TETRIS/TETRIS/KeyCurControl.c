#include<conio.h>
#include<Windows.h>
#include"point.h"

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