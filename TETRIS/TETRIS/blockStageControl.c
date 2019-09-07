#include<time.h>
#include"common.h"
#include"blockInfo.h"
#include"KeyCurControl.h"
//#include"point.h"


#define GBOARD_WIDTH 10 // ���� ��輱
#define GBOARD_HEIGHT 20 // ���� ��輱

#define GBOARD_ORIGIN_X 4
#define GBOARD_ORIGIN_Y 2

static int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2] = { 0, };

static int currentBlockModel;
static int curPosX, curPosY; //20 , 0 ó�� ��� ��Ÿ�� ��ġ
static int rotateSte;  // static�� �ʱ�ȣ ���ϸ� 0

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
	return currentBlockModel + rotateSte; // rotateSte ��� ȸ��
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


// �Լ� : int DetectCollision(int posX, int posY, char blockModel[][4])
// ���� : �浹����
// ��ȯ : int

int DetectCollision(int posX, int posY, char blockModel[][4]) // pox poy �Ѵ� �ܼ���ǥ, blockModel�� ������
{
	int x, y;

	int arrx = (posX - GBOARD_ORIGIN_X) / 2; // posX�� posY �� cur , ��� ������ġ
	int arry =posY - GBOARD_ORIGIN_Y;

	for (x = 0; x < 4; x++)
	{
		for (y = 0; y < 4; y++)
		{
			if (blockModel[y][x] == 1 && gameBoardInfo[arry + y][arrx + x] == 1) // �ٽ�. �ܼ������� �迭������ ���缭 ��ȯ�Ͽ� ���� 1�� Ȯ���Ѵ�.
				return 0;
		}
	}
	return 1;
}


// �Լ� : int BlockDown(void)
// ���� : ����� ��ĭ�� ������
// ��ȯ : int , ���� 1, ���� 0 ��ȯ

int BlockDown(void)
{
	if (!DetectCollision(curPosX, curPosY + 1, blockModel[GetCurrentBlockIdx()]))
		return 0;

	DeleteBlock(blockModel[GetCurrentBlockIdx()]); // �׷��� ����� �����
	curPosY += 1; // Y�� ���� 1 �ø���

	SetCurrentCursorPos(curPosX, curPosY); // y�� 1����(��).�� ��ġ�� Ŀ���� �ű��(�ݿ���) 
	ShowBlock(blockModel[GetCurrentBlockIdx()]); // �Ű��� ��ġ���� �ٽ� �׸��� �׸���.

	return 1;
}

// �Լ� : void BlockRight(void)
// ���� : ����� ��ĭ ����������
// ��ȯ : void

void BlockRight(void)
{
	if (!DetectCollision(curPosX + 2, curPosY, blockModel[GetCurrentBlockIdx()]))
		return; // �浹 ���� Ȯ��

	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosX += 2;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}


// �Լ� : void BlockLeft(void)
// ���� : ����� ��ĭ ��������
// ��ȯ : void

void BlockLeft(void)
{

	if (!DetectCollision(curPosX - 2, curPosY, blockModel[GetCurrentBlockIdx()]))
		return; // �浹 ���� Ȯ��

	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosX -= 2;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}

// �Լ� : void BlockRotate(void)
// ���� : ��� ȸ��
// ��ȯ : void

void BlockRotate(void)
{

	int nextRotSte;
	int beforeRotSte = rotateSte;

	DeleteBlock(blockModel[GetCurrentBlockIdx()]);

	nextRotSte = rotateSte + 1; // static �������� rotateSte 
	nextRotSte %= 4;// static �������� rotateSte �� 1~4�� �ݺ��Ѵ�.
	rotateSte = nextRotSte;

	if (!DetectCollision(curPosX, curPosY, blockModel[GetCurrentBlockIdx()]))
	{
		rotateSte = beforeRotSte; // �浹������� rotateSte���� �������·� ���� �������� ���ϰ��� 
		return; // �浹 ���� Ȯ��
	}

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]); //  �ݿ��� rotateSte�� showblock ������
}






//void GBOARD_MAP(void)
//{
//	int i, j;
//	for (i = 0; i < GBOARD_HEIGHT; i++)
//	{
//		for (j = 0; j < GBOARD_WIDTH; j++)
//		{
//			if (i == GBOARD_HEIGHT + 1 || j == 0 || j == GBOARD_WIDTH + 1)
//				gameBoardInfo[i][j] = 1;
//			else
//				gameBoardInfo[i][j] = 0;
//		}
//	}
//}


// �Լ� : void DrawGameBoard(void)
// ���� : ���� ��
// ��ȯ : void

void DrawGameBoard(void)
{
	int x, y;

	//�ð����� �κ� 
	for (y = 0; y <= GBOARD_HEIGHT; y++)
	{
		SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y+y); // �ش� ��ġ�� Ŀ�� �̵�

		if (y == GBOARD_HEIGHT)  // for ������ <= �����ڸ� �� ����
			printf("��");
		else
			printf("��");
	}

	for (y = 0; y <= GBOARD_HEIGHT; y++)
	{
		SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH + 1) * 2, GBOARD_ORIGIN_Y + y);

		if (y == GBOARD_HEIGHT)
			printf("��");
		else
			printf("��");
	}

	for (x = 1; x < GBOARD_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(GBOARD_ORIGIN_X + x * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
		printf("��");
	}

	SetCurrentCursorPos(0, 0);

	//������ ó��
	for (y = 0; y < GBOARD_HEIGHT; y++)
	{
		gameBoardInfo[y][0] = 1;
		gameBoardInfo[y][GBOARD_WIDTH+1] = 1;
	}

	for (x = 0; x < GBOARD_WIDTH + 2; x++)
	{
		gameBoardInfo[GBOARD_HEIGHT][x] = 1;
	}


}

// �Լ� : void AddCurrentBlockInfoToBoard(void)
// ���� : ���� ��� ������ �ʿ��ٰ� �߰�(�ױ�)
// ��ȯ : void

void AddCurrentBlockInfoToBoard(void)
{
	int x, y;

	int arrCurX;
	int arrCurY;

	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{

			arrCurX = (curPosX - GBOARD_ORIGIN_X) / 2;
			arrCurY = curPosY - GBOARD_ORIGIN_Y;

			if (blockModel[GetCurrentBlockIdx()][y][x] == 1)
				gameBoardInfo[arrCurY + y][arrCurX + x] = 1;
		}
	}
}

// �Լ� : int IsGameOver(void)
// ���� : ���� Ȯ�� �Լ�
// ��ȯ : ����� 1 ��ȯ

int IsGameOver(void)
{

	if (!DetectCollision(curPosX, curPosY, blockModel[GetCurrentBlockIdx()]))
		return 1;
	else
		return 0;



}