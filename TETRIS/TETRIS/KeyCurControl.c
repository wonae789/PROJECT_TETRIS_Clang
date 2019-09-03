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

static int keyDelayRate; // �� Ŭ���� �ӵ��� ����


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
// ��� : Ŀ�� ��ġ ���� ���� ����ü ������ ��ȯ(���� ��ġ�� Ŀ�������� �������)
// ��ȯ : point

point GetCurrentCursorPos(void)
{
	point curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;// �ܼ� ���â�� ������ ��� ���� ����ü. �����Ǵ°�.

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo); // ���� Ŀ���� ��ġ�� curinfo�� ����ȴ�.
	curPoint.x = curInfo.dwCursorPosition.X;
	curPoint.y = curInfo.dwCursorPosition.Y;

	return curPoint;
}

// �Լ� : void SetCurrentCursorPos(int x, int y)
// ��� : Ŀ�� ��ġ�� ����
// ��ȯ : void

void SetCurrentCursorPos(int x, int y)
{
	COORD pos = { x,y }; // Windows.h �� ������ �Լ�, ��ǥ 2�� ����.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // pos ��ġ�� Ŀ���� �̵�
	//SetConsoleCursorPosition - ��ɷ���Ʈâ�� ���ִ� Ŀ���� ��ġ �̵� �Լ�
	//GetStdHandle(STD_OUTPUT_HANDLE) - ȭ�鿡 ��� ���������Ʈ(�ܼ�â)�� �����ϱ����� ���� ��ȯ��.
	//GetStdHandle - Ű�� �޶�¶�
	//STD_OUTPUT_HANDLE - �ڵ鰪

}

// �Լ� : void ProcessKeyInput(void)
// ��� : Ű �Է� ��� �̵�
// ��ȯ : void


void ProcessKeyInput(void)
{
	int i;
	int key;

	for (i = 0; i < KEY_SENSITIVE; i++)
	{
		if (_kbhit() != 0) // _kbhit Ű�� �Է��� ���ִ��� �ȵǾ����� Ȯ���ϴ� �Լ�
			               // _kbhit�� �ԷµǸ� true�� ��ȯ��

		{
			key = _getch();// _getch �� conio.h�� �����, Enter Ű �Է��� �䱸���� ����.
			               // �Է¹ޱ� ������ STOP ���°� �ȴ�.
			               //        echo ������ �ʾƼ� �Է³����� ȭ�鿡 �������� ����.
			               // Ű �Է��ϸ� �� Ű�� �ƽ�Ű�ڵ尪�� ��ȯ��.
			// ��� �̵�
			switch (key) // ������ - 77, ���� - 75 , �Ʒ� - 80
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

		if (i % keyDelayRate == 0) // ������ ����. keyDelayRate 5��, Ű�Է°˻� 5ȸ�� 1���� �����.
			Sleep(SYS_DELAY); // Sleep �Լ��� Windows.h ����� ���ǵ�.
	}
}

void InitKeyDelayRate(int rate)
{
	if (rate < 1)
		return;
	keyDelayRate = rate;
}