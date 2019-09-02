#include <stdio.h>
#include <Windows.h>

int main(void)
{
	CONSOLE_SCREEN_BUFFER_INFO curInfo;// 콘솔 출력창의 정보를 담기 위한 구조체. 제공되는것.

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	printf("[%d, %d] \n", curInfo.dwCursorPosition.X, curInfo.dwCursorPosition.Y); // 콘재 콘솔창의 위치 좌표를 출력해준다.
	puts("First Hello world");

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	printf("[%d, %d] \n", curInfo.dwCursorPosition.X, curInfo.dwCursorPosition.Y);
	puts("Second Hello world");

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	printf("[%d, %d] \n", curInfo.dwCursorPosition.X, curInfo.dwCursorPosition.Y);
	

	return 0;
}