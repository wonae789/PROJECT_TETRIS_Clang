#include<Windows.h>
#include<conio.h>
#include"KeyCurControl.h"
#include"blockStageControl.h"

#define START_CURPOS_X (10 *2)
#define START_CURPOS_Y (0)




int main(void)
{
	//���� �ӵ� ����
	InitKeyDelayRate(10);
	// Ŀ�� ������ ����
	RemoveCursor();

	// �� ��� ���� ��ġ ����
	InitNewBlockPos(START_CURPOS_X, START_CURPOS_Y);

	//��� ����
	ChooseBlock();

	while (1)
	{
		// ����� ��ĭ�� �Ʒ� �̵�
		//BlockDown();

		// Ű �Է¿� ���� �� �̵�
		ProcessKeyInput();

	}







	return 0;
}