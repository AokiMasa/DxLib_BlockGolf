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
#define FIELD_WIDTH 480			//画面の幅
#define FIELD_HEIGHT 867		//画面の高さ

/*ブロック関係*/
#define MAX_BLOCKS 390			//ブロックの合計数

#define BLOCK_WIDTH 32			//ブロックの幅
#define BLOCK_HEIGHT 32			//ブロックの高さ

#define MAX_BLOCK_X 15			//x方向の最大ブロック数
#define MAX_BLOCK_Y 26			//y方向の最大ブロック数

/*ボール関係*/
#define MAX_BALLS 30			//ボールの合計数

#define BALL_SPEED 5			//ボールのスピード
#define BALL_SIZE 19			//ボールの大きさ
#define BALL_SHOT_OFFSET 10		//ボールの発射間隔

#define BALL_SHOT_POS_OFFSET 19 //ボールの発射座標の調整

/*予測線関係*/
#define MAX_SHOTLINE_POINT 20	//予測線の点の数
#define SHOTLINE_OFFSET 32		//予測線の点を表示する間隔

/*ステージ関係*/
#define MAX_STAGE 5             //ステージ総数

/*エフェクト関係*/
<<<<<<< HEAD
#define AFTIMAGENUM	30			// 残像データの数
=======
#define AFTIMAGENUM1 90			//effect残像データの数
#define AFTIMAGENUM2 30			//m_effect残像データの数
>>>>>>> Aoki
