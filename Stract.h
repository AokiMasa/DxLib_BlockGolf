#pragma once
//Ballに関する構造体
typedef struct {
	int   knd;		//種類 1 : 通常処理 ・ 2 : ブラックホール内処理		
	bool  flag;		//フラグ
	float x,		//Ball_X_座標
		  y,		//Ball_Y_座標
		  r,		//Ball_半径
		  angle,	//Ball_角度
		  spd_x,	//スピードx
		  spd_y;	//スピードy
}Ball_t;

//Blockに関する構造体
typedef struct {
	int   knd;		//種類
	bool  flg;		//フラグ	
	float x,		//Block_X座標
		  y;		//Block_Y座標
}Block_t;

//BlackHoleに関する構造体
typedef struct {
	float x,        //BH_X_中心座標
		  y,        //BH_Y_中心座標
		  r;        //BH_半径
}BH_t;
