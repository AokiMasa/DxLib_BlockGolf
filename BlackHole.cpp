#include "GV.h"

int bhHandle;			//�摜
int inCnt;				//�{�[�����u���b�N�z�[���ɓ�������
double p;				//�u���b�N�z�[���̉�]�̑���
double rad[MAX_BALLS];	//�u���b�N�z�[���Ɠ����������̊e�{�[���̃��W�A���l
double r[MAX_BALLS];	//���a

//BlackHole�̏�����
void init_bh() {
	p = 0;
	bhHandle = LoadGraph("./src/BlackHole3.png");
	bh.x = FIELD_WIDTH / 2;
	bh.y = 64;
	bh.r = 32;	
	for (int i = 0; i < MAX_BALLS; i++) {
		r[i]   = 32;
		rad[i] = 0;
	}
}

void move_bh() {
	inCnt = 1;		//�{�[�����u���b�N�z�[���ɓ�������

	for (int i = 0; i < MAX_BALLS; i++) {
		//�u���b�N�z�[���̒��S�ɏ��X�ɋ߂Â�
		if (balls[i].knd == 2) {

			//�e�{�[���̊p�x��1���Â��₷
			balls[i].deg += 3;
			//��������炻�̊p�x�Ŏ~�߂�
			if (balls[i].deg >= 360 + balls[i].tmp)360 + balls[i].tmp;
			//�p�x�����W�A���l�ɖ߂�
			rad[i] = balls[i].deg * M_PI / 180;

			//���a��32����-0.175�Â��炵�Ă���
			r[i]  -= 0.175;
			//���a��-�̒l�ɂȂ�Ȃ��悤��0�����ɂȂ����甼�a��0�ɂ���
			if (r[i] < 0)r[i] = 0;

			//�e�{�[�����~��`��(���X�ɏ�����)�Ȃ���ړ����ău���b�N�z�[���̒��S�Ɍ�����
			balls[i].x = bh.x + r[i] * cos(rad[i]);
			balls[i].y = bh.y + r[i] * sin(rad[i]);

			//�u���b�N�z�[���ɓ��������ꏊ���璼���Ō�����(���X�ɂ������ɂȂ�Ȃ���i��)
			//balls[i].x += (bh.x - balls[i].x) * 0.04f;
			//balls[i].y += (bh.y - balls[i].y) * 0.04f;
			
			//printfDx("r[%d]:%lf\nrad[%d]:%lf\n", i,r[i],i,rad[i]);
		}
		//�u���b�N�z�[���ƃ{�[���̒��S�_������0.25�������ƃu���b�N�z�[���̒��S�_�Ɉړ�(float�^�̓_�Ɠ_�̓����蔻��Ȃ̂Ō덷�����l��)
		if ((fabsf((bh.x - balls[i].x)) < 0.25f && fabsf((bh.y - balls[i].y)) < 0.25) && balls[i].knd == 2) {
			balls[i].x   = bh.x;
			balls[i].y   = bh.y;

			//�G�t�F�N�g�֌W
			effect[i].onActive = true;
			effect[i].x = balls[i].x;
			effect[i].y = balls[i].y;

			balls[i].knd = 3;
		}
		else if (balls[i].knd == 3) {
			balls[i].num = inCnt;
			inCnt++;

			//�{�[����MAX_BALLS����������Game��؂�ւ���
			if (balls[i].num == MAX_BALLS) {
				//�X�e�[�W�����̃}�b�v�f�[�^�ɂ���
				Stage_Num += 1;
				if (Stage_Num > MAX_STAGE - 1) Stage_Num = 0;
				Game = 4;
			}
		}
	}
}

//BlackHole�̓����蔻��
void collision_bh() {
	for (int i = 0; i < MAX_BALLS; i++) {
		if (((
			(bh.x - balls[i].x) * (bh.x - balls[i].x) +
			(bh.y - balls[i].y) * (bh.y - balls[i].y) <= (bh.r + balls[i].r) * (bh.r + balls[i].r)) &&
			(
			(bh.x - balls[i].x) * (bh.x - balls[i].x) +
			(bh.y - balls[i].y) * (bh.y - balls[i].y) >= ((bh.r / 2) + balls[i].r) * ((bh.r / 2) + balls[i].r))) &&
			(balls[i].bFlg && balls[i].knd==1)) {
			balls[i].knd = 2;

			balls[i].deg = atan2(balls[i].y - bh.y, balls[i].x - bh.x) * 180 / M_PI;
			balls[i].deg +=(balls[i].deg < 0) * 360;

			balls[i].tmp = balls[i].deg;
			//printfDx("I:%d\ndeg:%lf\nrad:%lf\n", i,balls[i].tmp,rad);
		}

		/*
		if ((bh.x - balls[i].x) * (bh.x - balls[i].x) + (bh.y - balls[i].y) * (bh.y - balls[i].y) >= ((bh.r / 2) + balls[i].r) * ((bh.r / 2) + balls[i].r)) {
			printfDx("OUT\n");
		}else printfDx("IN\n");
		*/

		//�_�Ɖ~�̓����蔻�聫
		//if ((balls[i].x - bh.x) * (balls[i].x - bh.x) + (balls[i].y - bh.y) * (balls[i].y - bh.y) <= balls[i].r * balls[i].r) 
		//printfDx("I:%d//num:%d//knd:%d\n", i, balls[i].num, balls[i].knd);
	}
	//printfDx("inCnt:%d\n", inCnt);
}

//BlackHole�̕`��
void draw_bh() {
	//�摜�̉�](���W�A���l)
	p += 0.025;
	if (p > 2 * M_PI)p = 0;
	DrawRotaGraph((int)bh.x, (int)bh.y, 1.0,p, bhHandle, true);
	//DrawCircle((int)bh.x, (int)bh.y, (int)bh.r, GetColor(0, 255, 0), true);

	/*�f�o�b�O�p�̕\��*/
	//�u���b�N�z�[���̒��S���W�̕\��
	DrawFormatString(FIELD_WIDTH - 110, FIELD_HEIGHT - 140, GetColor(255, 255, 255), "BH:%.1f\nBH:%.1f", bh.x, bh.y);
	//�e�{�[���̃u���b�N�z�[���Ɠ����������̊p�x�A���W�A���l�̕\��
	//for (int i = 0; i < MAX_BALLS; i++)DrawFormatString(FIELD_WIDTH - 110, i * 50, GetColor(255, 255, 255), "r[%d]:%lf\nrad[%d]:%lf\ntmp[%d]:%lf\n", i, r[i], i, rad[i],i,balls[i].tmp);

}
