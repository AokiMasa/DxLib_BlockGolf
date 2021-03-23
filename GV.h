#pragma once
/*�����͕K�p*/
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

GLOBAL int  Game;			//�Q�[���J�ڔԍ�
GLOBAL int Stage_Num;		//�X�e�[�W�ԍ�

/*BLOCK�̍\���̃f�[�^*/
GLOBAL Block_t blocks[MAX_BLOCKS];

/*�eBlock�̏�����+����*/
GLOBAL void init_blocks();
/*�eBlock�̓����蔻��*/
GLOBAL void collision_block();
/*�eBlock�̕`��*/
GLOBAL void draw_block();


/*BALL�̍\���̃f�[�^*/
GLOBAL Ball_t balls[MAX_BALLS];

/*���ˊԊu�𐔂���J�E���^*/
GLOBAL int bCnt;
/*�eBall�̏�����*/
GLOBAL void init_balls();
/*�eBall�̓����蔻��*/
GLOBAL void collision_ball();
/*�eBall�̕`��*/
GLOBAL void draw_ball();
/*�eBall�̓���*/
GLOBAL void move_balls();	
/*Ball�����Ԋu�Ō���*/
GLOBAL void shot_balls();


/*BLACKHOLE�̍\���̃f�[�^*/
GLOBAL BH_t bh;

/*BlackHole�̏�����*/
GLOBAL void init_bh();
/*BlackHole�̓����蔻��*/
GLOBAL void collision_bh();
/*BlackHole�̓���*/
GLOBAL void move_bh();
/*BlackHole�̕`��*/
GLOBAL void draw_bh();


/*SHOTLINE�̍\���̃f�[�^*/
GLOBAL ShotLine_t sl[MAX_SHOTLINE_POINT];

/*SHOTLINE�̓_��\������Ԋu*/
GLOBAL int slCnt;
/*ShotLine�̏�����*/
GLOBAL void init_sl();
/*ShotLine�̓���*/
GLOBAL void move_sl();
/*ShotLine�̕`��*/
GLOBAL void draw_sl();


/*Stage*/

/*�u���b�N�̔z�u*/
GLOBAL void create_blocks();