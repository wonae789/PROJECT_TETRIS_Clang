#include<time.h>
#include"common.h"
//#include"point.h"
#include"blockInfo.h"
#include"KeyCurControl.h"

static int currentBlockModel;
static int curPosX, curPosY;

// 함수 : void InitNewBlockPos(int x, int y)
// 설명 : 블록의 첫 위치 선정
// 반환 : void

void InitNewBlockPos(int x, int y)
{
	if (x < 0 || y < 0)
		return;

	curPosX = x;
	curPosY = y;

	SetCurrentCursorPos(x, y);
}

// 함수 : void ChooseBlock(void)
// 설명 : 출력할 블록을 무작위 선택
// 반환 : void

void ChooseBlock(void)
{
	srand((unsigned int)time(NULL));
	currentBlockModel = (rand() % NUM_OF_BLOCK_MODEL) * 4;
}

// 함수 : int GetCurrentBlockIdx(void)
// 설명 : 현재 출력할 블록 index 정보를 반환
// 반환 : int

int GetCurrentBlockIdx(void)
{
	return currentBlockModel;
}

// 함수 : void ShowBlock(char blockInfo[][4])
// 설명 : 전달된 인자를 받아서 블록을 출력
// 반환 : void

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
				printf("■"); // 특수문자 ■ 는 공백 2칸 차지함
		}
	}
	SetCurrentCursorPos(curPos.x, curPos.y);
}

// 함수 : void DeleteBlock(char blockInfo[][4])
// 설명 : 전달된 인자를 받아서 블록을 삭제
// 반환 : void

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
				printf("  "); // 특수문자 ■ 는 공백 2칸 차지함
		}
	}
	SetCurrentCursorPos(curPos.x, curPos.y);
}

// 함수 : void BlockDown(void)
// 설명 : 블록을 한칸씩 내린다
// 반환 : void

void BlockDown(void)
{
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosY += 1;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}


// 함수 : void BlockRight(void)
// 설명 : 블록을 한칸 오른쪽으로
// 반환 : void

void BlockRight(void)
{
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosX += 1;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}


// 함수 : void BlockLeft(void)
// 설명 : 블록을 한칸 왼쪽으로
// 반환 : void

void BlockLeft(void)
{
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosX -= 1;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}

