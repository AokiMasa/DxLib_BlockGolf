#include "GV.h"

int bhHandle;			//画像
int inCnt;				//ボールがブラックホールに入った数
double p;				//ブラックホールの回転の速さ
double rad[MAX_BALLS];	//ブラックホールと当たった時の各ボールのラジアン値
double r[MAX_BALLS];	//半径

//BlackHoleの初期化
void init_bh() {
	p = 0;
	bhHandle = LoadGraph("./src/BlackHole3.png");
	bh.x = FIELD_WIDTH / 2;
	bh.y = 64;
	bh.r = 32;	
	for (int i = 0; i < MAX_BALLS; i++) {
		r[i]   = 32;
		rad[i] = 0;
	}
}

void move_bh() {
	inCnt = 1;		//ボールがブラックホールに入った数

	for (int i = 0; i < MAX_BALLS; i++) {
		//ブラックホールの中心に徐々に近づく
		if (balls[i].knd == 2) {

			//各ボールの角度を1°づつ増やす
			balls[i].deg += 3;
			//一周したらその角度で止める
			if (balls[i].deg >= 360 + balls[i].tmp)360 + balls[i].tmp;
			//角度をラジアン値に戻す
			rad[i] = balls[i].deg * M_PI / 180;

			//半径を32から-0.175づつ減らしていく
			r[i]  -= 0.175;
			//半径が-の値にならないように0未満になったら半径を0にする
			if (r[i] < 0)r[i] = 0;

			//各ボールが円を描き(徐々に小さく)ながら移動してブラックホールの中心に向かう
			balls[i].x = bh.x + r[i] * cos(rad[i]);
			balls[i].y = bh.y + r[i] * sin(rad[i]);

			//ブラックホールに当たった場所から直線で向かう(徐々にゆっくりになりながら進む)
			//balls[i].x += (bh.x - balls[i].x) * 0.04f;
			//balls[i].y += (bh.y - balls[i].y) * 0.04f;
			
			//printfDx("r[%d]:%lf\nrad[%d]:%lf\n", i,r[i],i,rad[i]);
		}
		//ブラックホールとボールの中心点が距離0.25未満だとブラックホールの中心点に移動(float型の点と点の当たり判定なので誤差分を考慮)
		if ((fabsf((bh.x - balls[i].x)) < 0.25f && fabsf((bh.y - balls[i].y)) < 0.25) && balls[i].knd == 2) {
			balls[i].x   = bh.x;
			balls[i].y   = bh.y;

			//エフェクト関係
			effect[i].onActive = true;
			effect[i].x = balls[i].x;
			effect[i].y = balls[i].y;

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
			(balls[i].bFlg && balls[i].knd==1)) {
			balls[i].knd = 2;

			balls[i].deg = atan2(balls[i].y - bh.y, balls[i].x - bh.x) * 180 / M_PI;
			balls[i].deg +=(balls[i].deg < 0) * 360;

			balls[i].tmp = balls[i].deg;
			//printfDx("I:%d\ndeg:%lf\nrad:%lf\n", i,balls[i].tmp,rad);
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
	//画像の回転(ラジアン値)
	p += 0.025;
	if (p > 2 * M_PI)p = 0;
	DrawRotaGraph((int)bh.x, (int)bh.y, 1.0,p, bhHandle, true);
	//DrawCircle((int)bh.x, (int)bh.y, (int)bh.r, GetColor(0, 255, 0), true);

	/*デバッグ用の表示*/
	//ブラックホールの中心座標の表示
	DrawFormatString(FIELD_WIDTH - 110, FIELD_HEIGHT - 140, GetColor(255, 255, 255), "BH:%.1f\nBH:%.1f", bh.x, bh.y);
	//各ボールのブラックホールと当たった時の角度、ラジアン値の表示
	//for (int i = 0; i < MAX_BALLS; i++)DrawFormatString(FIELD_WIDTH - 110, i * 50, GetColor(255, 255, 255), "r[%d]:%lf\nrad[%d]:%lf\ntmp[%d]:%lf\n", i, r[i], i, rad[i],i,balls[i].tmp);

}
