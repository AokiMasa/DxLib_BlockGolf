#include"GV.h"
int effectImage[8];
int effect_orders[15] = { 0,1,2,3,4,5,6,7,6,5,4,3,2,1,0 };		//エフェクトの描画の順番
int effect_numOrder = sizeof(effect_orders) / sizeof(effect_orders[0]);		//配列の要素数の計算

int effect_speed = 2;				//エフェクト再生スピード
int effect_wait = effect_speed;		//待ち時間

//初期化
void init_effect() {
	LoadDivGraph("./src/effect4.png", 8, 4, 2, 32, 32, effectImage);
	for (int i = 0; i < MAX_BALLS; i++) {
		effect[i].cnt = 0;
		effect[i].onActive = false;
	}
}

//描画
void draw_effect() {
	for (int i = 0; i < MAX_BALLS; i++) {
		if (!effect[i].onActive)continue;

		if (--effect_wait < 0) {
			effect[i].cnt++;
			effect_wait = effect_speed;
		}

		if (effect[i].cnt >= effect_numOrder) {
			effect[i].cnt = 0;
			effect[i].onActive = false;
			continue;
		}
		int effect_type = effect_orders[effect[i].cnt];
		//printfDx("etypr%d\n",effect_type);
		if(balls[i].bFlg)DrawRotaGraph(effect[i].x, effect[i].y, 1.0, 0.0, effectImage[effect_type], true);
	}
}