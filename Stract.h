#pragma once
//Ball�Ɋւ���\����
typedef struct {
	int   knd;		//��� 1 : �ʏ폈�� �E 2 : �u���b�N�z�[��������		
	bool  flag;		//�t���O
	float x,		//Ball_X_���W
		  y,		//Ball_Y_���W
		  r,		//Ball_���a
		  angle,	//Ball_�p�x
		  spd_x,	//�X�s�[�hx
		  spd_y;	//�X�s�[�hy
}Ball_t;

//Block�Ɋւ���\����
typedef struct {
	int   knd;		//���
	bool  flg;		//�t���O	
	float x,		//Block_X���W
		  y;		//Block_Y���W
}Block_t;

//BlackHole�Ɋւ���\����
typedef struct {
	float x,        //BH_X_���S���W
		  y,        //BH_Y_���S���W
		  r;        //BH_���a
}BH_t;
