#include<conio.h>
#include<Windows.h>
#include"point.h"

// �Լ� : void RemoveCursor(void)
// ��� : ����ǥ�� ����
// ��ȯ : void

void RemoveCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo); // �ܼ� ������ ���ִ±��
}

// �Լ� : point GetCurrentCursorPos(void)
// ��� : Ŀ�� ��ġ ���� ���� ����ü ������ ��ȯ
// ��ȯ : point

point GetCurrentCursorPos(void)
{
	point curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;// �ܼ� ���â�� ������ ��� ���� ����ü. �����Ǵ°�.

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint.x = curInfo.dwCursorPosition.X;
	curPoint.y = curInfo.dwCursorPosition.Y;

	return curPoint;
}

// �Լ� : void SetCurrentCursorPos(int x, int y)
// ��� : Ŀ�� ��ġ�� ����
// ��ȯ : void

void SetCurrentCursorPos(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}