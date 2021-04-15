#include"GV.h"

int effectImage[8];
int effectImage2[18];
int effect_orders[15] = { 0,1,2,3,4,5,6,7,6,5,4,3,2,1,0 };					//エフェクトの描画の順番
int effect_orders2[18] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };	//エフェクトの描画の順番
int effect_numOrder = sizeof(effect_orders) / sizeof(effect_orders[0]);		//配列の要素数の計算
int effect_numOrder2 = sizeof(effect_orders2) / sizeof(effect_orders2[0]);	//配列の要素数の計算

int effect_speed = 1;				//エフェクト再生スピード
int effect_wait = effect_speed;		//待ち時間

//各エフェクト画像読み込み
void load_Effect() {
	LoadDivGraph("./src/effect4.png", 8, 4, 2, 32, 32, effectImage);		//画像を分割して読み込む
	LoadDivGraph("./src/effect5.png", 18, 5, 4, 64, 64, effectImage2);		//画像を分割して読み込む
}
//初期化
void init_effect() {
<<<<<<< HEAD
	LoadDivGraph("./src/effect4.png", 8, 4, 2, 32, 32, effectImage);		//画像を分割して読み込む
	LoadDivGraph("./src/effect5.png", 18, 5, 4, 64, 64, effectImage2);		//画像を分割して読み込む
	for (int i = 0; i < MAX_BALLS; i++) {
		effect[i].cnt = 0;
		effect[i].onActive = false;
	}
	for (int i = 0; i < AFTIMAGENUM; i++) {
=======
	for (int i = 0; i < AFTIMAGENUM1; i++) {
		effect[i].cnt = 0;
		effect[i].onActive = false;
	}
	for (int i = 0; i < AFTIMAGENUM2; i++) {
>>>>>>> Aoki
		m_effect[i].cnt = 0;
		m_effect[i].onActive = false;
	}
}

<<<<<<< HEAD
//描画
void draw_effect() {
	int m_Xpos, m_Ypos;		//マウス座標
=======
void draw_m_effect() {
	int m = GetMouseInput();	//マウスの入力状態
	int m_Xpos, m_Ypos;			//マウス座標
>>>>>>> Aoki

	GetMousePoint(&m_Xpos, &m_Ypos);		//マウス座標の取得

	//m_effectのonActiveがfalseな場所を探してマウス座標をｘｙ座標に入れる。代入したらbreakでfor文から抜ける
<<<<<<< HEAD
	for (int i = 0; i < AFTIMAGENUM; i++) {
		if (!m_effect[i].onActive && bCnt%2==0) {
=======
	for (int i = 0; i < AFTIMAGENUM2; i++) {
		if (m_effect[i].onActive == false && bCnt % 2 == 0) {
>>>>>>> Aoki
			m_effect[i].x = m_Xpos;
			m_effect[i].y = m_Ypos;
			m_effect[i].onActive = true;
			break;
		}
	}

	//m_effectの描画処理
<<<<<<< HEAD
	for (int i = 0; i < AFTIMAGENUM; i++) {

		if (!m_effect[i].onActive)continue;

		m_effect[i].cnt++;

		if (m_effect[i].cnt >= effect_numOrder2) {
			m_effect[i].cnt = 0;
			m_effect[i].onActive = false;
			continue;
		}
		int effect_type = effect_orders2[m_effect[i].cnt];

		if (m_Xpos >= 0 && m_Xpos <= FIELD_WIDTH && m_Ypos >= 0 && m_Ypos <= FIELD_HEIGHT - 16) {
			DrawRotaGraph(m_effect[i].x, m_effect[i].y, 1.0, 0.0, effectImage2[effect_type], true);
		}
	}

	//effectの描画処理
	for (int i = 0; i < MAX_BALLS; i++) {

		if (!effect[i].onActive)continue;
=======
	for (int i = 0; i < AFTIMAGENUM2; i++) {
>>>>>>> Aoki

		if (!m_effect[i].onActive)continue;

		m_effect[i].cnt++;

		/*
		if (--effect_wait <= 0) {
			m_effect[i].cnt++;
			effect_wait = effect_speed;
		}
		*/

<<<<<<< HEAD

		switch (balls[i].knd)
		{
		case 1: {
=======
		if (m_effect[i].cnt >= effect_numOrder2) {
			m_effect[i].cnt = 0;
			m_effect[i].onActive = false;
			continue;
		}
		int effect_type = effect_orders2[m_effect[i].cnt];
>>>>>>> Aoki

		if (m_Xpos >= 0 && m_Xpos <= FIELD_WIDTH && m_Ypos >= 0 && m_Ypos <= FIELD_HEIGHT - BALL_SHOT_POS_OFFSET) {
			if (m & MOUSE_INPUT_LEFT) {
				DrawRotaGraph(m_effect[i].x, m_effect[i].y, 1.0, 0.0, effectImage2[effect_type], true);
			}
		}
<<<<<<< HEAD
		case 3: {
			if (effect[i].cnt >= effect_numOrder2) {
				effect[i].cnt = 0;
				effect[i].onActive = false;
				continue;
			}
			int effect_type = effect_orders2[effect[i].cnt];
			//if (balls[i].bFlg && balls[i].knd == 3)DrawRotaGraph(effect[i].x, effect[i].y, 1.0, 0.0, effectImage2[effect_type], true);
			break;
=======
	}
}

void draw_effectBG() {
	//effectの描画処理
	for (int i = 0; i < AFTIMAGENUM1; i++) {

		if (effect[i].onActive == false)continue;

		//effect[i].cnt++;

		if (--effect_wait <= 0) {
			effect[i].cnt++;
			effect_wait = effect_speed;
>>>>>>> Aoki
		}

		if (effect[i].cnt >= effect_numOrder2) {
			effect[i].cnt = 0;
			effect[i].onActive = false;
			continue;
		}
		int effect_type = effect_orders2[effect[i].cnt];
		DrawRotaGraph(effect[i].x, effect[i].y, 1.0, 0.0, effectImage2[effect_type], true);
	}
}

//描画
void draw_effect() {
	//effectの描画処理
	for (int i = 0; i < AFTIMAGENUM1; i++) {

		if (effect[i].onActive == false)continue;

		//effect[i].cnt++;

		if (--effect_wait <= 0) {
			effect[i].cnt++;
			effect_wait = effect_speed;
		}

		if (effect[i].cnt >= effect_numOrder) {
			effect[i].cnt = 0;
			effect[i].onActive = false;
			continue;
		}
		int effect_type = effect_orders[effect[i].cnt];
		DrawRotaGraph(effect[i].x, effect[i].y, 1.0, 0.0, effectImage[effect_type], true);
	}
}
