#include "GV.h"

int bhHandle;	//画像
int inCnt;		//ボールがブラックホールに入った数
double p;


//BlackHoleの初期化
void init_bh() {
	p = 0;
	bhHandle = LoadGraph("./src/BlackHole3.png");
	bh.x = FIELD_WIDTH / 2;
	bh.y = 64;
	bh.r = 32;	
}

void move_bh() {
	inCnt = 1;		//ボールがブラックホールに入った数

	for (int i = 0; i < MAX_BALLS; i++) {
		//ブラックホールの中心に徐々に近づく
		if (balls[i].knd == 2) {
			balls[i].x += (bh.x - balls[i].x) * 0.04f;
			balls[i].y += (bh.y - balls[i].y) * 0.04f;
		}
		//ブラックホールとボールの中心点が距離0.25未満だとブラックホールの中心点に移動(float型の点と点の当たり判定なので誤差分を考慮)
		if ((fabsf((bh.x - balls[i].x)) < 0.25f && fabsf((bh.y - balls[i].y)) < 0.25f) && balls[i].knd == 2) {
			balls[i].x = bh.x;
			balls[i].y = bh.y;
			balls[i].knd = 3;
		}
		else if (balls[i].knd == 3) {
			balls[i].num = inCnt;
			inCnt++;

			//ボールがMAX_BALLS分入ったらGameを切り替える
			if (balls[i].num == MAX_BALLS) {
				//ステージを次のマップデータにする
				Stage_Num += 1;
				if (Stage_Num > MAX_STAGE - 1) Stage_Num = 0;
				Game = 4;
			}
		}
	}
}

//BlackHoleの当たり判定
void collision_bh() {
	for (int i = 0; i < MAX_BALLS; i++) {
		if (((
			(bh.x - balls[i].x) * (bh.x - balls[i].x) +
			(bh.y - balls[i].y) * (bh.y - balls[i].y) <= (bh.r + balls[i].r) * (bh.r + balls[i].r)) &&
			(
			(bh.x - balls[i].x) * (bh.x - balls[i].x) +
			(bh.y - balls[i].y) * (bh.y - balls[i].y) >= ((bh.r / 2) + balls[i].r) * ((bh.r / 2) + balls[i].r))) &&
			balls[i].bFlg) {
			balls[i].knd = 2;
		}

		/*
		if ((bh.x - balls[i].x) * (bh.x - balls[i].x) + (bh.y - balls[i].y) * (bh.y - balls[i].y) >= ((bh.r / 2) + balls[i].r) * ((bh.r / 2) + balls[i].r)) {
			printfDx("OUT\n");
		}else printfDx("IN\n");
		*/

		//点と円の当たり判定↓
		//if ((balls[i].x - bh.x) * (balls[i].x - bh.x) + (balls[i].y - bh.y) * (balls[i].y - bh.y) <= balls[i].r * balls[i].r) 
		//printfDx("I:%d//num:%d//knd:%d\n", i, balls[i].num, balls[i].knd);
	}
	//printfDx("inCnt:%d\n", inCnt);
}

//BlackHoleの描画
void draw_bh() {
	p+=0.01;
	if (p > 2 * M_PI)p = 0;
	DrawRotaGraph((int)bh.x, (int)bh.y, 1.0,p, bhHandle, true);
	//DrawCircle((int)bh.x, (int)bh.y, (int)bh.r, GetColor(0, 255, 0), true);
	DrawFormatString(FIELD_WIDTH - 110, FIELD_HEIGHT - 140, GetColor(255, 255, 255), "BH:%.1f\nBH:%.1f", bh.x, bh.y);
}
