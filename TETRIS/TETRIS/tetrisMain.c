#include<Windows.h>
#include<conio.h>
#include"common.h"
#include"KeyCurControl.h"
#include"blockStageControl.h"

#define START_CURPOS_X (5 *2)
#define START_CURPOS_Y (0)


int main(void)
{
	//���� �ӵ� ����
	InitKeyDelayRate(2);

	// Ŀ�� ������ ����
	RemoveCursor();

	//���� ���� �׸���
	DrawGameBoard();


	while (1)
	{
		// �� ��� ���� ��ġ ����
		InitNewBlockPos(START_CURPOS_X, START_CURPOS_Y);

		//��� ����
		ChooseBlock();

		//���� ���� Ȯ��
		if (IsGameOver())
			break;

		while (1)
		{

			if(BlockDown()==0)
			{
				AddCurrentBlockInfoToBoard();
				break;
			}
			// Ű �Է¿� ���� �� �̵�
			ProcessKeyInput();
		}
	}

	SetCurrentCursorPos(10, 10);
	puts("���� ���� ");

	return 0;
}