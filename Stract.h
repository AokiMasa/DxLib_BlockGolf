#pragma once
//Ball�Ɋւ���\����
typedef struct {
	int   knd;		//��� 1 : �ʏ폈�� �@2 : �u���b�N�z�[��������	�@3 : �u���b�N�z�[�����̒��S�̏���
	int   num;      //�u���b�N�z�[���ɓ��������Ԃ��L�^����
	int   hp;       //�{�[���̗̑�
	bool  flag;		//Shot�t���O(�G��Ȃ�)
	bool  bFlg;     //�����T�EF���ĕ\���ⓖ���蔻����Ƃ�
	float x;		//Ball_X���W
	float y;		//Ball_Y���W
	float r;		//Ball_���a
	float angle;	//Ball_�p�x
	float spd_x;	//Ball_�ړ��X�s�[�hX
	float spd_y;	//Ball_�ړ��X�s�[�hY
	double tmp, deg;//�u���b�N�z�[���Ɠ����������̊e�{�[���̊p�x
}Ball_t;

//Block�Ɋւ���\����
typedef struct {
	int   knd;		//���
	int   hp;       //�u���b�N�̗̑�
	bool  flg;		//�t���O	
	float x;		//Block_X���W
	float y;		//Block_Y���W
}Block_t;

//BlackHole�Ɋւ���\����
typedef struct {
	float x;        //BH_X���S���W
	float y;        //BH_Y���S���W
	float r;        //BH_���a
}BH_t;

//�\�����Ɋւ���\����
typedef struct {
	float x;		//�e�\�����̋ʂ�X���W
	float y;		//�e�\�����̋ʂ�Y���W
}ShotLine_t;

//�G�t�F�N�g
typedef struct {
	float x;		//Effect_X���W
	float y;		//Effect_X���W
	int cnt;		//�J�E���^
	bool onActive;	//�\���t���O
}Effect_t;