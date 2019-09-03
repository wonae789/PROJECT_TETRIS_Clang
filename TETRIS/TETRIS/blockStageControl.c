#include<time.h>
#include"common.h"
//#include"point.h"
#include"blockInfo.h"
#include"KeyCurControl.h"

static int currentBlockModel;
static int curPosX, curPosY;

// �Լ� : void InitNewBlockPos(int x, int y)
// ���� : ����� ù ��ġ ����
// ��ȯ : void

void InitNewBlockPos(int x, int y)
{
	if (x < 0 || y < 0)
		return;

	curPosX = x;
	curPosY = y;

	SetCurrentCursorPos(x, y);
}

// �Լ� : void ChooseBlock(void)
// ���� : ����� ����� ������ ����
// ��ȯ : void

void ChooseBlock(void)
{
	srand((unsigned int)time(NULL));
	currentBlockModel = (rand() % NUM_OF_BLOCK_MODEL) * 4;
}

// �Լ� : int GetCurrentBlockIdx(void)
// ���� : ���� ����� ��� index ������ ��ȯ
// ��ȯ : int

int GetCurrentBlockIdx(void)
{
	return currentBlockModel;
}

// �Լ� : void ShowBlock(char blockInfo[][4])
// ���� : ���޵� ���ڸ� �޾Ƽ� ����� ���
// ��ȯ : void

void ShowBlock(char blockInfo[][4])
{
	int y, x;
	point curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			SetCurrentCursorPos((curPos.x + x * 2), curPos.y + y);
			if (blockInfo[y][x] == 1)
				printf("��"); // Ư������ �� �� ���� 2ĭ ������
		}
	}
	SetCurrentCursorPos(curPos.x, curPos.y);
}

// �Լ� : void DeleteBlock(char blockInfo[][4])
// ���� : ���޵� ���ڸ� �޾Ƽ� ����� ����
// ��ȯ : void

void DeleteBlock(char blockInfo[][4])
{
	int y, x;
	point curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			SetCurrentCursorPos((curPos.x + x * 2), curPos.y + y);
			if (blockInfo[y][x] == 1)
				printf("  "); // Ư������ �� �� ���� 2ĭ ������
		}
	}
	SetCurrentCursorPos(curPos.x, curPos.y);
}

// �Լ� : void BlockDown(void)
// ���� : ����� ��ĭ�� ������
// ��ȯ : void

void BlockDown(void)
{
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosY += 1;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}


// �Լ� : void BlockRight(void)
// ���� : ����� ��ĭ ����������
// ��ȯ : void

void BlockRight(void)
{
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosX += 1;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}


// �Լ� : void BlockLeft(void)
// ���� : ����� ��ĭ ��������
// ��ȯ : void

void BlockLeft(void)
{
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosX -= 1;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}

