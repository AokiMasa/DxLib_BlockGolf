#include "GV.h"
#include "Function.h"

int ballHandle;			//画像
int m_Xpos, m_Ypos;		//マウス座標
double angle = -1.57;	//初期弧度
int deg;				//角度

//初期化
void init_balls() {
	int x, y;
	ballHandle = LoadGraph("./src/Ball.png");
	GetGraphSize(ballHandle, &x, &y);
	//printfDx("Ball_X:%d Ball_Y:%d\n", x, y);

	for (int i = 0; i < MAX_BALLS; i++) { 
		balls[i].x	   = FIELD_WIDTH / 2;
		balls[i].y	   = FIELD_HEIGHT - 16;
		balls[i].spd_x = BALL_SPEED;
		balls[i].spd_y = BALL_SPEED;
		balls[i].r     = BALL_SIZE / 2;
		balls[i].num   = 0;
		balls[i].hp    = 9;
		balls[i].angle = (float)angle;
		balls[i].tmp   = 0;
		balls[i].deg   = 0;
		balls[i].flag  = false;
		balls[i].bFlg  = true;
		balls[i].knd   = 1;
	}
}

//ボールの発射間隔
void shot_balls() {

	GetMousePoint(&m_Xpos, &m_Ypos);				 //マウス座標の取得	
	
	if (m_Xpos >= 0 && m_Xpos <= FIELD_WIDTH && m_Ypos >= 0 && m_Ypos <= FIELD_HEIGHT - 16) {
		angle = angle2(m_Xpos, m_Ypos);				 //ラジアン値
		deg = (int)-((float)angle * (180 / M_PI));	 //度数	
	}

	for (int i = 0; i < MAX_BALLS; i++) {
		//ショットフラグが有効かつ、BALL_SHOT_OFFSETループに一回発射
		if (!balls[i].flag && bCnt%BALL_SHOT_OFFSET == 0) {
			balls[i].x     = FIELD_WIDTH / 2;
			balls[i].y     = FIELD_HEIGHT - 16;
			balls[i].angle = (float)angle;
			balls[i].flag  = true;
			break;
		}
	}
	//printfDx("bCnt:%d\n", bCnt);
}

//ボールの移動
void move_balls() {
	for (int i = 0; i < MAX_BALLS; i++) {
		//このif文のflagを消すとバグが起きたので消さないで
		if (balls[i].knd == 1 && balls[i].flag) {
			balls[i].x += (float)cos(balls[i].angle) * balls[i].spd_x;
			balls[i].y += (float)sin(balls[i].angle) * balls[i].spd_y;
		}
		if (balls[i].hp < 0)balls[i].bFlg = false;
	}
}

//画面外にBallが出ないようにする処理
void collision_ball() {
	for (int i = 0; i < MAX_BALLS;i++) {
		if (balls[i].x >= FIELD_WIDTH - (BALL_SIZE / 2)) {
			balls[i].x = FIELD_WIDTH - (BALL_SIZE / 2);
			balls[i].spd_x *= -1;
			balls[i].hp -= 1;

			//エフェクト関係
			effect[i].onActive = true;
			effect[i].x = balls[i].x;
			effect[i].y = balls[i].y;
		}
		if (balls[i].x <= 0 + (BALL_SIZE / 2)) {
			balls[i].x = 0 + (BALL_SIZE / 2);
			balls[i].spd_x *= -1;
			balls[i].hp -= 1;

			//エフェクト関係
			effect[i].onActive = true;
			effect[i].x = balls[i].x;
			effect[i].y = balls[i].y;
		}
		if (balls[i].y <= 0 + (BALL_SIZE / 2)) {
			balls[i].y = 0 + (BALL_SIZE / 2);
			balls[i].spd_y *= -1;
			balls[i].hp -= 1;

			//エフェクト関係
			effect[i].onActive = true;
			effect[i].x = balls[i].x;
			effect[i].y = balls[i].y;
		}
		if (balls[i].y >= FIELD_HEIGHT - (BALL_SIZE / 2)) {
			balls[i].y = FIELD_HEIGHT - (BALL_SIZE / 2);
			balls[i].spd_y *= -1; 
			balls[i].hp -= 1;

			//エフェクト関係
			effect[i].onActive = true;
			effect[i].x = balls[i].x;
			effect[i].y = balls[i].y;
		}
	}
}

//画像の描画
void draw_ball() {
	//ショットスタート座標を見てわかるようにした
	DrawCircle(FIELD_WIDTH / 2, FIELD_HEIGHT - 16, 10, GetColor(0, 255, 100), true);

	for (int i = 0; i < MAX_BALLS; i++) {
		if (balls[i].bFlg && balls[i].knd != 3)DrawRotaGraph((int)balls[i].x, (int)balls[i].y, 1.0, 0.0, ballHandle, true);//DrawGraph((int)balls[i].x, (int)balls[i].y, ballHandle, true);

		/*デバッグ用の表示*/
		//各ボールの座標とHPの表示
		if (balls[i].knd == 1)DrawFormatString((int)balls[i].x + 8, (int)balls[i].y - 18, GetColor(255, 255, 255), "X:%.1f\nY:%.1f\nHP:%d", balls[i].x, balls[i].y,balls[i].hp);
		//マウス座標の表示
		DrawFormatString(FIELD_WIDTH - 110, FIELD_HEIGHT - 100, GetColor(255, 255, 255), "MX:%d\nMY:%d", m_Xpos,m_Ypos);
		//ショットのラジアン値
		DrawFormatString(FIELD_WIDTH - 110, FIELD_HEIGHT - 60, GetColor(255, 255, 255), "ANGLE:%.2lf", angle);
		//角度
		DrawFormatString(FIELD_WIDTH - 110, FIELD_HEIGHT - 40, GetColor(255, 255, 255), "DEG:%d", deg);			
	}
}