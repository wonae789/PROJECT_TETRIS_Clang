/*
	Name : KeyCurControl.c	ver 1.0
	content : Ŀ��, Ű���� ��Ʈ�� �Լ��� ����
	Implementation : JJH

	Last modified 2019/07/02
*/

#include<conio.h>
#include<Windows.h>
#include"point.h"

/*
	�Լ� : void RemoveCursor(void)
	��� : ���� �Ÿ��� Ŀ���� ����
	��ȯ : void
*/

void RemoveCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

/*
	�Լ� : point GetCurrentCursorPos(void)
	��� : ���� Ŀ�� ��ġ ������ ���� ����ü ���� ��ȯ
	��ȯ : point
*/

point GetCurrentCursorPos(void)
{
	point curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);// ���� �ܼ�â�� ��ġ ��ǥ�� ������ش�.
	curPoint.x = curInfo.dwCursorPosition.X;
	curPoint.y = curInfo.dwCursorPosition.Y;

	return curPoint;
}


/*
	�Լ� : void SetCurrentCursorPos(int x, int y)
	��� : Ŀ�� ��ġ�� ����
	��ȯ : void
*/

void SetCurrentCursorPos(int x, int y) // ��ǥ�� �Է¹޾Ƽ� Ŀ���� ��ġ�� �̵���Ŵ.
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


/* end of file */