#include "GV.h"
int Score = 0;
//初期化
void init_score() {
	Score = 0;
	DrawFormatString(FIELD_WIDTH - 110, FIELD_HEIGHT - 180, GetColor(0, 0, 255), "SCORE:%d", Score);
}

void draw_score() {
	DrawFormatString(FIELD_WIDTH - 110, FIELD_HEIGHT - 180, GetColor(0, 0, 255), "SCORE:%d", Score);
}


//Score加算処理
void Add_Point() {
	//入ったボールのHPの倍の数値をスコアに加算
	Score += balls[0].hp * 2;
}