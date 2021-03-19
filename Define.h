#pragma once
#include "GV.h"

#ifdef GLOBAL_INSTANCE
#define GLOBAL
#else
#define GLOBAL extern 

#endif

/*�����蔻��֌W*/
#define COLLISION_OFFSET 3		//�����蔻��̋��e�͈́i�s�N�Z���j

/*��ʊ֌W*/
#define FIELD_WIDTH 704			//��ʂ̕�
#define FIELD_HEIGHT 960		//��ʂ̍���

/*�u���b�N�֌W*/
#define MAX_BLOCKS 165			//�u���b�N�̍��v��

#define BLOCK_WIDTH 64			//�u���b�N�̕�
#define BLOCK_HEIGHT 64			//�u���b�N�̍���

#define MAX_BLOCK_X 11			//x�����̍ő�u���b�N��
#define MAX_BLOCK_Y 15			//y�����̍ő�u���b�N��

/*�{�[���֌W*/
#define MAX_BALLS 10			//�{�[���̍��v��

#define BALL_SPEED 2			//�{�[���̃X�s�[�h
#define BALL_SIZE 16			//�{�[���̑傫��
#define BALL_SHOT_OFFSET 30		//�{�[���̔��ˊԊu

/*�\�����֌W*/
#define MAX_SHOTLINE_POINT 40	//�\�����̓_�̐�
#define SHOTLINE_OFFSET 32		//�\�����̓_��\������Ԋu

/*�X�e�[�W�֌W*/
#define MAX_STAGE 5             //�X�e�[�W����