#pragma once
//Ballに関する構造体
typedef struct {
	int   knd;		//種類 1 : 通常処理 　2 : ブラックホール内処理	　3 : ブラックホール内の中心の処理
	int   num;      //ブラックホールに入った順番を記録する
	int   hp;       //ボールの体力
	bool  flag;		//Shotフラグ(触らない)
	bool  bFlg;     //これをT・Fして表示や当たり判定をとる
	float x;		//Ball_X座標
	float y;		//Ball_Y座標
	float r;		//Ball_半径
	float angle;	//Ball_角度
	float spd_x;	//Ball_移動スピードX
	float spd_y;	//Ball_移動スピードY
	double tmp, deg;//ブラックホールと当たった時の各ボールの角度
}Ball_t;

//Blockに関する構造体
typedef struct {
	int   knd;		//種類
	int   hp;       //ブロックの体力
	bool  flg;		//フラグ	
	float x;		//Block_X座標
	float y;		//Block_Y座標
}Block_t;

//BlackHoleに関する構造体
typedef struct {
	float x;        //BH_X中心座標
	float y;        //BH_Y中心座標
	float r;        //BH_半径
}BH_t;

//予測線に関する構造体
typedef struct {
	float x;		//各予測線の玉のX座標
	float y;		//各予測線の玉のY座標
}ShotLine_t;

//エフェクト
typedef struct {
	float x;		//Effect_X座標
	float y;		//Effect_X座標
	int cnt;		//カウンタ
	bool onActive;	//表示フラグ
}Effect_t;