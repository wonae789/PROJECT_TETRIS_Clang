#include "common.h"
#include "KeyCurControl.h"

#define LEVEL_DIFF 2 // 레벨별 증가 속도
#define LEVEL_UP_SCORE_DIFF 20 // 제발 증가하는 단위


static int curGameLevel = 1;
static int curGameScore = 0;

// 함수 : void ShowCurrentScoreAndLevel(void)
// 설명 : 점수와 레벨 출력
// 반환 : void

void ShowCurrentScoreAndLevel(void)
{
	SetCurrentCursorPos(30, 4);
	printf("현재 레벨 : %d", curGameLevel);


	SetCurrentCursorPos(30, 8);
	printf("현재 점수 : %d", curGameScore);
}


// 함수 : void GameLevelUp(void)
// 설명 : 게임 레벨 향상
// 반환 : void


void GameLevelUp(void)
{
	curGameLevel++;
	KeyDelaySpeedCtl(LEVEL_DIFF);
}

// 함수 : void AddGameScore(int score)
// 설명 : 게임 게임 점수 추가
// 반환 : void

void AddGameScore(int score)
{
	if (score < 1)
		return;
	curGameScore += score;

	// 레벨 상승후 레벨업
	if (curGameScore >= curGameLevel * LEVEL_UP_SCORE_DIFF) // 레벨*20보다 크면 레벨업
		GameLevelUp();

}