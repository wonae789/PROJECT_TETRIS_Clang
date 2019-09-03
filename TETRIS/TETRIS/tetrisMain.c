#include<Windows.h>
#include<conio.h>
#include"KeyCurControl.h"
#include"blockStageControl.h"

#define START_CURPOS_X (10 *2)
#define START_CURPOS_Y (0)




int main(void)
{
	//게임 속도 설정
	InitKeyDelayRate(10);
	// 커서 깜밖이 제거
	RemoveCursor();

	// 새 블록 등장 위치 설정
	InitNewBlockPos(START_CURPOS_X, START_CURPOS_Y);

	//블록 선택
	ChooseBlock();

	while (1)
	{
		// 블록을 한칸씩 아래 이동
		//BlockDown();

		// 키 입력에 따라 블럭 이동
		ProcessKeyInput();

	}







	return 0;
}