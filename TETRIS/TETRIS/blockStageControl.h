#ifndef __BLOCK_STAGE_H_
#define __BLOCK_STAGE_H_

void InitDownSpeed(int speed);

void InitNewBlockPos(int x, int y);
void ChooseBlock(void);
int GetCurrentBlockIdx(void);
void ShowBlock(char blockInfo[][4]);
void DeleteBlock(char blockInfo[][4]);
int BlockDown(void);
void BlockLeft(void);
void BlockRight(void);
void BlockRotate(void);
void SolidCurrentBlock(void);



void AddCurrentBlockInfoToBoard(void);
void DrawGameBoard(void);
int IsGameOver(void);



#endif