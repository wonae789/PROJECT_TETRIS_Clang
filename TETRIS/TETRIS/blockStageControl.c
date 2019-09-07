#include<time.h>
#include"common.h"
#include"blockInfo.h"
#include"KeyCurControl.h"
//#include"point.h"


#define GBOARD_WIDTH 10 // 가로 경계선
#define GBOARD_HEIGHT 20 // 세로 경계선

#define GBOARD_ORIGIN_X 4
#define GBOARD_ORIGIN_Y 2

static int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2] = { 0, };

static int currentBlockModel;
static int curPosX, curPosY; //20 , 0 처음 블록 나타낼 위치
static int rotateSte;  // static은 초기호 안하면 0

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
	return currentBlockModel + rotateSte; // rotateSte 블록 회전
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


// 함수 : int DetectCollision(int posX, int posY, char blockModel[][4])
// 설명 : 충돌방지
// 반환 : int

int DetectCollision(int posX, int posY, char blockModel[][4]) // pox poy 둘다 콘솔좌표, blockModel은 블럭정보
{
	int x, y;

	int arrx = (posX - GBOARD_ORIGIN_X) / 2; // posX와 posY 는 cur , 블록 시작위치
	int arry =posY - GBOARD_ORIGIN_Y;

	for (x = 0; x < 4; x++)
	{
		for (y = 0; y < 4; y++)
		{
			if (blockModel[y][x] == 1 && gameBoardInfo[arry + y][arrx + x] == 1) // 핵심. 콘솔정보를 배열정보와 맞춰서 변환하여 서로 1을 확인한다.
				return 0;
		}
	}
	return 1;
}


// 함수 : int BlockDown(void)
// 설명 : 블록을 한칸씩 내린다
// 반환 : int , 성공 1, 실패 0 반환

int BlockDown(void)
{
	if (!DetectCollision(curPosX, curPosY + 1, blockModel[GetCurrentBlockIdx()]))
		return 0;

	DeleteBlock(blockModel[GetCurrentBlockIdx()]); // 그려진 블록을 지우고
	curPosY += 1; // Y축 값을 1 올리고

	SetCurrentCursorPos(curPosX, curPosY); // y축 1증가(↓).된 위치로 커서를 옮긴다(반영함) 
	ShowBlock(blockModel[GetCurrentBlockIdx()]); // 옮겨진 위치에서 다시 그림을 그린다.

	return 1;
}

// 함수 : void BlockRight(void)
// 설명 : 블록을 한칸 오른쪽으로
// 반환 : void

void BlockRight(void)
{
	if (!DetectCollision(curPosX + 2, curPosY, blockModel[GetCurrentBlockIdx()]))
		return; // 충돌 여부 확인

	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosX += 2;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}


// 함수 : void BlockLeft(void)
// 설명 : 블록을 한칸 왼쪽으로
// 반환 : void

void BlockLeft(void)
{

	if (!DetectCollision(curPosX - 2, curPosY, blockModel[GetCurrentBlockIdx()]))
		return; // 충돌 여부 확인

	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosX -= 2;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}

// 함수 : void BlockRotate(void)
// 설명 : 블록 회전
// 반환 : void

void BlockRotate(void)
{

	int nextRotSte;
	int beforeRotSte = rotateSte;

	DeleteBlock(blockModel[GetCurrentBlockIdx()]);

	nextRotSte = rotateSte + 1; // static 전역변수 rotateSte 
	nextRotSte %= 4;// static 전역변수 rotateSte 는 1~4를 반복한다.
	rotateSte = nextRotSte;

	if (!DetectCollision(curPosX, curPosY, blockModel[GetCurrentBlockIdx()]))
	{
		rotateSte = beforeRotSte; // 충돌났을경우 rotateSte값은 이전상태로 돌려 변경하지 못하게함 
		return; // 충돌 여부 확인
	}

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]); //  반영된 rotateSte를 showblock 보여줌
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


// 함수 : void DrawGameBoard(void)
// 설명 : 게임 맵
// 반환 : void

void DrawGameBoard(void)
{
	int x, y;

	//시각적인 부분 
	for (y = 0; y <= GBOARD_HEIGHT; y++)
	{
		SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y+y); // 해당 위치로 커서 이동

		if (y == GBOARD_HEIGHT)  // for 구문에 <= 연산자를 쓴 이유
			printf("┗");
		else
			printf("┃");
	}

	for (y = 0; y <= GBOARD_HEIGHT; y++)
	{
		SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH + 1) * 2, GBOARD_ORIGIN_Y + y);

		if (y == GBOARD_HEIGHT)
			printf("┛");
		else
			printf("┃");
	}

	for (x = 1; x < GBOARD_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(GBOARD_ORIGIN_X + x * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
		printf("━");
	}

	SetCurrentCursorPos(0, 0);

	//데이터 처리
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

// 함수 : void AddCurrentBlockInfoToBoard(void)
// 설명 : 현재 블록 정보를 맵에다가 추가(쌓기)
// 반환 : void

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

// 함수 : int IsGameOver(void)
// 설명 : 종료 확인 함수
// 반환 : 종료시 1 반환

int IsGameOver(void)
{

	if (!DetectCollision(curPosX, curPosY, blockModel[GetCurrentBlockIdx()]))
		return 1;
	else
		return 0;



}