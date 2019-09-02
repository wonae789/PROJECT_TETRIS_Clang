#include <stdio.h>
#include <Windows.h>

int main(void)
{
	COORD pos1 = { 0,2 }; //옮길 위치에 대한 구조체 변수 생성
	COORD pos2 = { 6,6 };
	COORD pos3 = { 15,4 };

	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);// 현재 콘솔창의 핸들을 얻어서 

	SetConsoleCursorPosition(hConsoleOut, pos1);// 위치를 반영시킴
	printf("첫 번재 인사 : 안녕하세요");
	getchar();

	SetConsoleCursorPosition(hConsoleOut, pos2);
	printf("두 번재 인사 : 안녕하세요");
	getchar();

	SetConsoleCursorPosition(hConsoleOut, pos3);
	printf("세 번재 인사 : 안녕하세요");
	getchar();

	return 0;
}