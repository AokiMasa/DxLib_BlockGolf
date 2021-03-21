#include "GV.h"

int blockHandle;		//画像

/*
int block_map[MAX_BLOCK_Y][MAX_BLOCK_X] = {
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
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
};


int block_map[MAX_BLOCK_Y][MAX_BLOCK_X] = 
{
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,1,0,1,0,1,0,1,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,0,1,0,1,0,1,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,1,0,1,0,1,0,1,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,0,1,0,1,0,1,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,1,0,1,0,1,0,1,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,0,1,0,1,0,1,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
};
*/

//初期化+生成
void init_blocks() {
	
	//ブロックのフラグを全部Falseにしてからブロックを生成
	int a = 0;
	for (int i = 0; i < MAX_BLOCK_Y; i++) {
		for (int j = 0; j < MAX_BLOCK_X; j++) {
			blocks[a].flg = false;
			//printfDx("a:%d\n", a);
			a++;
		}
	}
	

	blockHandle = LoadGraph("./src/Block.jpg");

	int x, y;
	GetGraphSize(blockHandle, &x, &y);
	//printfDx("Block_X:%d Block_Y:%d\n", x,y);
	create_blocks();
	
	/*
	//ブロックのマップデータが1の場所だけTrueにする
	int i, j;
	int count = 0;
	for (i = 0; i < MAX_BLOCK_Y; i++) {
		for (j = 0; j < MAX_BLOCK_X; j++) {
			if (block_map[i][j] != 0) {
				blocks[count].x = BLOCK_WIDTH * (float)j;
				blocks[count].y = BLOCK_HEIGHT * (float)i;
				blocks[count].flg = true;
				blocks[count].hp = 9;//ここはブロックのHP用のHPデータを使う・もしくはランダムでHPを割り当てる
			}
			count++;
		}
	}
	*/
}

//ブロックの当たり判定
void collision_block() {
	for (int i = 0; i < MAX_BLOCKS; i++) {
		for (int j = 0; j < MAX_BALLS; j++) {
			if (blocks[i].flg && balls[j].bFlg) {
				//上面の当たり判定
				if (balls[j].x > blocks[i].x && balls[j].x < blocks[i].x + BLOCK_WIDTH &&
					balls[j].y > blocks[i].y - (BALL_SIZE / 4) && balls[j].y < blocks[i].y + COLLISION_OFFSET) {
					balls[j].y = blocks[i].y - (BALL_SIZE / 2);
					balls[j].spd_y *= -1;
					balls[j].hp -= 1;
					blocks[i].hp -= 1;

					//エフェクト関係
					effect[j].onActive = true;
					effect[j].x = balls[j].x;
					effect[j].y = balls[j].y;
				}
				//下面の当たり判定
				if (balls[j].x > blocks[i].x && balls[j].x < blocks[i].x + BLOCK_WIDTH &&
					balls[j].y < blocks[i].y + (BLOCK_HEIGHT + (BALL_SIZE / 2)) && balls[j].y > blocks[i].y + BLOCK_HEIGHT - COLLISION_OFFSET) {
					balls[j].y = blocks[i].y + (BLOCK_HEIGHT + (BALL_SIZE / 2));
					balls[j].spd_y *= -1;
					balls[j].hp -= 1;
					blocks[i].hp -= 1;

					//エフェクト関係
					effect[j].onActive = true;
					effect[j].x = balls[j].x;
					effect[j].y = balls[j].y;
				}
				//左面の当たり判定
				if (balls[j].y > blocks[i].y && balls[j].y < blocks[i].y + BLOCK_HEIGHT &&
					balls[j].x > blocks[i].x - (BALL_SIZE / 4) && balls[j].x < blocks[i].x + COLLISION_OFFSET) {
					balls[j].x = blocks[i].x - (BALL_SIZE / 2);
					balls[j].spd_x *= -1;
					balls[j].hp -= 1;
					blocks[i].hp -= 1;

					//エフェクト関係
					effect[j].onActive = true;
					effect[j].x = balls[j].x;
					effect[j].y = balls[j].y;
				}
				//右面の当たり判定
				if (balls[j].y > blocks[i].y && balls[j].y < blocks[i].y + BLOCK_HEIGHT &&
					balls[j].x < blocks[i].x + (BLOCK_WIDTH + (BALL_SIZE / 2)) && balls[j].x > blocks[i].x + BLOCK_WIDTH - COLLISION_OFFSET) {
					balls[j].x = blocks[i].x + (BLOCK_WIDTH + (BALL_SIZE / 2));
					balls[j].spd_x *= -1;
					balls[j].hp -= 1;
					blocks[i].hp -= 1;

					//エフェクト関係
					effect[j].onActive = true;
					effect[j].x = balls[j].x;
					effect[j].y = balls[j].y;
				}
			}
		}
		if (blocks[i].hp < 0)blocks[i].flg = false;
	}
}

//画像の描画
void draw_block() {

	for (int i = 0; i < MAX_BLOCKS; i++) {

		/*DrawBox(blocks[0].x,
				blocks[0].y,
				blocks[0].x + BLOCK_WIDTH,
				blocks[0].y + BLOCK_HEIGHT,
				GetColor(100, 200, 100), true);
		*/
		
		if (blocks[i].flg) {
			//画像の描画
			DrawGraph((int)blocks[i].x, (int)blocks[i].y, blockHandle, true);

			/*デバッグ用の表示*/
			//各Blockの位置座標
			DrawFormatString((int)blocks[i].x + (BLOCK_WIDTH / 4), (int)blocks[i].y + (BLOCK_HEIGHT / 8), GetColor(255, 0, 0), "X:%d\nY:%d\nHP:%d\nFLG:%d", (int)blocks[i].x, (int)blocks[i].y, blocks[i].hp, blocks[i].flg);
		}
	}
}
