#include <stdio.h>
#include <Windows.h>

int main(void)
{
	CONSOLE_SCREEN_BUFFER_INFO curInfo;// �ܼ� ���â�� ������ ��� ���� ����ü. �����Ǵ°�.

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	printf("[%d, %d] \n", curInfo.dwCursorPosition.X, curInfo.dwCursorPosition.Y); // ���� �ܼ�â�� ��ġ ��ǥ�� ������ش�.
	puts("First Hello world");

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	printf("[%d, %d] \n", curInfo.dwCursorPosition.X, curInfo.dwCursorPosition.Y);
	puts("Second Hello world");

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	printf("[%d, %d] \n", curInfo.dwCursorPosition.X, curInfo.dwCursorPosition.Y);
	

	return 0;
}