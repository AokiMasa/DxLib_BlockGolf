#pragma once
#include "GV.h"

#ifdef GLOBAL_INSTANCE
#define GLOBAL
#else
#define GLOBAL extern 

#endif

/*当たり判定関係*/
#define COLLISION_OFFSET 3		//当たり判定の許容範囲（ピクセル）

/*画面関係*/
#define FIELD_WIDTH 704			//画面の幅
#define FIELD_HEIGHT 960		//画面の高さ

/*ブロック関係*/
#define MAX_BLOCKS 165			//ブロックの合計数

#define BLOCK_WIDTH 64			//ブロックの幅
#define BLOCK_HEIGHT 64			//ブロックの高さ

#define MAX_BLOCK_X 11			//x方向の最大ブロック数
#define MAX_BLOCK_Y 15			//y方向の最大ブロック数

/*ボール関係*/
#define MAX_BALLS 10			//ボールの合計数

#define BALL_SPEED 2			//ボールのスピード
#define BALL_SIZE 16			//ボールの大きさ
#define BALL_SHOT_OFFSET 30		//ボールの発射間隔

/*予測線関係*/
#define MAX_SHOTLINE_POINT 40	//予測線の点の数
#define SHOTLINE_OFFSET 32		//予測線の点を表示する間隔

/*ステージ関係*/
#define MAX_STAGE 5             //ステージ総数