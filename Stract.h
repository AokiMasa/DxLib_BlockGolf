#pragma once
//Ballに関する構造体
typedef struct {
	int cnt, knd;//カウンタ、種類
	bool flag;//フラグ
	int x, y, r, angle, spd_x, spd_y;//座標、半径、角度、スピードx&y
}ball_t;

//Blockに関する構造体
typedef struct {
	int cnt, knd;//カウンタ、種類
	int x, y;//座標
}block_t;

