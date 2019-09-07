#include<Windows.h>
#include<conio.h>
#include"common.h"
#include"KeyCurControl.h"
#include"blockStageControl.h"

#define START_CURPOS_X (5 *2)
#define START_CURPOS_Y (0)


int main(void)
{
	//게임 속도 설정
	InitKeyDelayRate(2);

	// 커서 깜밖이 제거
	RemoveCursor();

	//게임 보드 그리기
	DrawGameBoard();


	while (1)
	{
		// 새 블록 등장 위치 설정
		InitNewBlockPos(START_CURPOS_X, START_CURPOS_Y);

		//블록 선택
		ChooseBlock();

		//게임 종료 확인
		if (IsGameOver())
			break;

		while (1)
		{

			if(BlockDown()==0)
			{
				AddCurrentBlockInfoToBoard();
				break;
			}
			// 키 입력에 따라 블럭 이동
			ProcessKeyInput();
		}
	}

	SetCurrentCursorPos(10, 10);
	puts("게임 종료 ");

	return 0;
}