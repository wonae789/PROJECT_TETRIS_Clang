#include<Windows.h>
#include"KeyCurControl.h"
#include"blockStageControl.h"

#define START_CURPOS_X (10 *2)
#define START_CURPOS_Y (0)
#define SYS_DELAY 100

int main(void)
{
	// 커서 깜밖이 제거
	RemoveCursor();

	// 새 블록 등장 위치 설정
	InitNewBlockPos(START_CURPOS_X, START_CURPOS_Y);

	//블록 선택
	ChooseBlock();

	//블록 내리는 작업
	while (1)
	{
		// 블록 이동
		BlockDown();

		BlockRight();

		BlockLeft();

		// 잠깐 화면 멈춤 (100)
		Sleep(SYS_DELAY);

		//int i, j;
		//for (int i=0; i < 50000; i++)
		//	for (int j=0; j < 10000; j++)
		//		;


	}

	return 0;
}