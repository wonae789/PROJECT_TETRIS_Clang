/*
	Name : KeyCurControl.c	ver 1.0
	content : 커서, 키보드 컨트롤 함수들 정의
	Implementation : JJH

	Last modified 2019/07/02
*/

#include<conio.h>
#include<Windows.h>
#include"point.h"

/*
	함수 : void RemoveCursor(void)
	기능 : 깜빡 거리는 커서의 제거
	반환 : void
*/

void RemoveCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

/*
	함수 : point GetCurrentCursorPos(void)
	기능 : 현재 커서 위치 정보를 담은 구조체 변수 반환
	반환 : point
*/

point GetCurrentCursorPos(void)
{
	point curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);// 콘재 콘솔창의 위치 좌표를 출력해준다.
	curPoint.x = curInfo.dwCursorPosition.X;
	curPoint.y = curInfo.dwCursorPosition.Y;

	return curPoint;
}


/*
	함수 : void SetCurrentCursorPos(int x, int y)
	기능 : 커서 위치를 설정
	반환 : void
*/

void SetCurrentCursorPos(int x, int y) // 좌표를 입력받아서 커서의 위치를 이동시킴.
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


/* end of file */