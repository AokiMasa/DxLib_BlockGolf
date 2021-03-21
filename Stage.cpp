#include "GV.h"

int block_map0[MAX_BLOCK_Y][MAX_BLOCK_X] =
{
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,0,1,1,0,0,0,1,1,0,1},
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,0,1,1,1,0,1,1,1,0,1},
	{1,1,1,1,1,0,1,1,1,1,1},
};

int block_map1[MAX_BLOCK_Y][MAX_BLOCK_X] =
{
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,0,1,1,0,0,0,1,1,0,1},
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,0,1,1,1,0,1,1,1,0,1},
	{1,1,1,1,1,0,1,1,1,1,1},
};

int block_map2[MAX_BLOCK_Y][MAX_BLOCK_X] =
{
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,0,1,1,0,0,0,1,1,0,1},
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,0,1,1,1,0,1,1,1,0,1},
	{1,1,1,1,1,0,1,1,1,1,1},
};

int block_map3[MAX_BLOCK_Y][MAX_BLOCK_X] =
{
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,0,1,1,0,0,0,1,1,0,1},
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,0,1,1,1,0,1,1,1,0,1},
	{1,1,1,1,1,0,1,1,1,1,1},
};

int block_map4[MAX_BLOCK_Y][MAX_BLOCK_X] =
{
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,0,1,1,0,0,0,1,1,0,1},
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,1,1,1,1,0,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,0,1,1,1,0,1,1,1,0,1},
	{1,1,1,1,1,0,1,1,1,1,1},
};
int block_map5[MAX_BLOCK_Y][MAX_BLOCK_X] =
{
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{1,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
};

void create_blocks() {
	switch(Stage_Num)
	{
	case 0: {
		//ブロックのマップデータが1の場所だけTrueにする
		int count = 0;
		for (int i = 0; i < MAX_BLOCK_X; i++) {
			for (int j = 0; j < MAX_BLOCK_Y; j++) {
				if (block_map0[j][i] != 0) {
					blocks[count].x = BLOCK_WIDTH * i;
					blocks[count].y = BLOCK_HEIGHT * j;
					blocks[count].flg = true;
					blocks[count].hp = 1;//ここはブロックのHP用のHPデータを使う・もしくはランダムでHPを割り当てる
				}
				count++;
			}
		}
		break;
	}
	case 1: {
		//ブロックのマップデータが1の場所だけTrueにする
		int count = 0;
		for (int i = 0; i < MAX_BLOCK_X; i++) {
			for (int j = 0; j < MAX_BLOCK_Y; j++) {
				if (block_map1[j][i] != 0) {
					blocks[count].x = BLOCK_WIDTH * i;
					blocks[count].y = BLOCK_HEIGHT * j;
					blocks[count].flg = true;
					blocks[count].hp = 1;//ここはブロックのHP用のHPデータを使う・もしくはランダムでHPを割り当てる
				}
				count++;
			}
		}
		break;
	}
	case 2: {
		//ブロックのマップデータが1の場所だけTrueにする
		int count = 0;
		for (int i = 0; i < MAX_BLOCK_X; i++) {
			for (int j = 0; j < MAX_BLOCK_Y; j++) {
				if (block_map2[j][i] != 0) {
					blocks[count].x = BLOCK_WIDTH * i;
					blocks[count].y = BLOCK_HEIGHT * j;
					blocks[count].flg = true;
					blocks[count].hp = 1;//ここはブロックのHP用のHPデータを使う・もしくはランダムでHPを割り当てる
				}
				count++;
			}
		}
		break;
	}
	case 3: {
		//ブロックのマップデータが1の場所だけTrueにする
		int count = 0;
		for (int i = 0; i < MAX_BLOCK_X; i++) {
			for (int j = 0; j < MAX_BLOCK_Y; j++) {
				if (block_map3[j][i] != 0) {
					blocks[count].x = BLOCK_WIDTH * i;
					blocks[count].y = BLOCK_HEIGHT * j;
					blocks[count].flg = true;
					blocks[count].hp = 1;//ここはブロックのHP用のHPデータを使う・もしくはランダムでHPを割り当てる
				}
				count++;
			}
		}
		break;
	}
	case 4: {
		//ブロックのマップデータが1の場所だけTrueにする
		int count = 0;
		for (int i = 0; i < MAX_BLOCK_X; i++) {
			for (int j = 0; j < MAX_BLOCK_Y; j++) {
				if (block_map4[j][i] != 0) {
					blocks[count].x = BLOCK_WIDTH * i;
					blocks[count].y = BLOCK_HEIGHT * j;
					blocks[count].flg = true;
					blocks[count].hp = 1;//ここはブロックのHP用のHPデータを使う・もしくはランダムでHPを割り当てる
				}
				count++;
			}
		}
		break;
	}
	case 5: {
		//ブロックのマップデータが1の場所だけTrueにする
		int count = 0;
		for (int i = 0; i < MAX_BLOCK_X; i++) {
			for (int j = 0; j < MAX_BLOCK_Y; j++) {
				if (block_map5[j][i] != 0) {
					blocks[count].x = BLOCK_WIDTH * i;
					blocks[count].y = BLOCK_HEIGHT * j;
					blocks[count].flg = true;
					blocks[count].hp = 1;//ここはブロックのHP用のHPデータを使う・もしくはランダムでHPを割り当てる
				}
				count++;
			}
		}
		break;
	}
	default:
		Game = 0;
		Stage_Num = 0;
		break;
	}
}

