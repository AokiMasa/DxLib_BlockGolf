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
#define FIELD_WIDTH 480			//��ʂ̕�
#define FIELD_HEIGHT 867		//��ʂ̍���

/*�u���b�N�֌W*/
#define MAX_BLOCKS 390			//�u���b�N�̍��v��

#define BLOCK_WIDTH 32			//�u���b�N�̕�
#define BLOCK_HEIGHT 32			//�u���b�N�̍���

#define MAX_BLOCK_X 15			//x�����̍ő�u���b�N��
#define MAX_BLOCK_Y 26			//y�����̍ő�u���b�N��

/*�{�[���֌W*/
#define MAX_BALLS 30			//�{�[���̍��v��

#define BALL_SPEED 5			//�{�[���̃X�s�[�h
#define BALL_SIZE 19			//�{�[���̑傫��
#define BALL_SHOT_OFFSET 10		//�{�[���̔��ˊԊu

#define BALL_SHOT_POS_OFFSET 19 //�{�[���̔��ˍ��W�̒���

/*�\�����֌W*/
#define MAX_SHOTLINE_POINT 20	//�\�����̓_�̐�
#define SHOTLINE_OFFSET 32		//�\�����̓_��\������Ԋu

/*�X�e�[�W�֌W*/
#define MAX_STAGE 5             //�X�e�[�W����

/*�G�t�F�N�g�֌W*/
<<<<<<< HEAD
#define AFTIMAGENUM	30			// �c���f�[�^�̐�
=======
#define AFTIMAGENUM1 90			//effect�c���f�[�^�̐�
#define AFTIMAGENUM2 30			//m_effect�c���f�[�^�̐�
>>>>>>> Aoki
