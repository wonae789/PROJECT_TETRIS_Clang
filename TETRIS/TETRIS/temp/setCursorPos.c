#include <stdio.h>
#include <Windows.h>

int main(void)
{
	COORD pos1 = { 0,2 }; //�ű� ��ġ�� ���� ����ü ���� ����
	COORD pos2 = { 6,6 };
	COORD pos3 = { 15,4 };

	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);// ���� �ܼ�â�� �ڵ��� �� 

	SetConsoleCursorPosition(hConsoleOut, pos1);// ��ġ�� �ݿ���Ŵ
	printf("ù ���� �λ� : �ȳ��ϼ���");
	getchar();

	SetConsoleCursorPosition(hConsoleOut, pos2);
	printf("�� ���� �λ� : �ȳ��ϼ���");
	getchar();

	SetConsoleCursorPosition(hConsoleOut, pos3);
	printf("�� ���� �λ� : �ȳ��ϼ���");
	getchar();

	return 0;
}