#include<Windows.h>
#include"KeyCurControl.h"
#include"blockStageControl.h"

#define START_CURPOS_X (5 *2)
#define START_CURPOS_Y (0)
#define SYS_DELAY 100

int main(void)
{
	// Ŀ�� ������ ����
	RemoveCursor();

	// �� ��� ���� ��ġ ����
	InitNewBlockPos(START_CURPOS_X, START_CURPOS_Y);

	//��� ����
	ChooseBlock();

	//��� ������ �۾�
	while (1)
	{
		// ��� ��ĭ �Ʒ��� �̵�
		BlockDown();

		// ��� ȭ�� ���� (100)
		Sleep(SYS_DELAY);

		//int i, j;
		//for (int i=0; i < 50000; i++)
		//	for (int j=0; j < 10000; j++)
		//		;


	}

	return 0;
}