#pragma once
/*ここは必用*/
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "Define.h"
#include "Stract.h"
#include "stdio.h"

#ifdef GLOBAL_INSTANCE
#define GLOBAL
#else
#define GLOBAL extern 

#endif

GLOBAL int  Game;			//ゲーム遷移番号
GLOBAL int Stage_Num;		//ステージ番号

/*BLOCKの構造体データ*/
GLOBAL Block_t blocks[MAX_BLOCKS];

/*各Blockの初期化+生成*/
GLOBAL void init_blocks();
/*各Blockの当たり判定*/
GLOBAL void collision_block();
/*各Blockの描画*/
GLOBAL void draw_block();


/*BALLの構造体データ*/
GLOBAL Ball_t balls[MAX_BALLS];

/*発射間隔を数えるカウンタ*/
GLOBAL int bCnt;
/*各Ballの初期化*/
GLOBAL void init_balls();
/*各Ballの当たり判定*/
GLOBAL void collision_ball();
/*各Ballの描画*/
GLOBAL void draw_ball();
/*各Ballの動き*/
GLOBAL void move_balls();	
/*Ballを一定間隔で撃つ*/
GLOBAL void shot_balls();


/*BLACKHOLEの構造体データ*/
GLOBAL BH_t bh;

/*BlackHoleの初期化*/
GLOBAL void init_bh();
/*BlackHoleの当たり判定*/
GLOBAL void collision_bh();
/*BlackHoleの動き*/
GLOBAL void move_bh();
/*BlackHoleの描画*/
GLOBAL void draw_bh();


/*SHOTLINEの構造体データ*/
GLOBAL ShotLine_t sl[MAX_SHOTLINE_POINT];

/*SHOTLINEの点を表示する間隔*/
GLOBAL int slCnt;
/*ShotLineの初期化*/
GLOBAL void init_sl();
/*ShotLineの動き*/
GLOBAL void move_sl();
/*ShotLineの描画*/
GLOBAL void draw_sl();


/*Stage*/

/*ブロックの配置*/
GLOBAL void create_blocks();