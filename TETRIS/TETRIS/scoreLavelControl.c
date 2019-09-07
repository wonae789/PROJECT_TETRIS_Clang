#include "common.h"
#include "KeyCurControl.h"

#define LEVEL_DIFF 2 // ������ ���� �ӵ�
#define LEVEL_UP_SCORE_DIFF 20 // ���� �����ϴ� ����


static int curGameLevel = 1;
static int curGameScore = 0;

// �Լ� : void ShowCurrentScoreAndLevel(void)
// ���� : ������ ���� ���
// ��ȯ : void

void ShowCurrentScoreAndLevel(void)
{
	SetCurrentCursorPos(30, 4);
	printf("���� ���� : %d", curGameLevel);


	SetCurrentCursorPos(30, 8);
	printf("���� ���� : %d", curGameScore);
}


// �Լ� : void GameLevelUp(void)
// ���� : ���� ���� ���
// ��ȯ : void


void GameLevelUp(void)
{
	curGameLevel++;
	KeyDelaySpeedCtl(LEVEL_DIFF);
}

// �Լ� : void AddGameScore(int score)
// ���� : ���� ���� ���� �߰�
// ��ȯ : void

void AddGameScore(int score)
{
	if (score < 1)
		return;
	curGameScore += score;

	// ���� ����� ������
	if (curGameScore >= curGameLevel * LEVEL_UP_SCORE_DIFF) // ����*20���� ũ�� ������
		GameLevelUp();

}