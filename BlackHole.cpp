#include "GV.h"

int bhHandle;	//�摜
int inCnt;		//�{�[�����u���b�N�z�[���ɓ�������
double p;


//BlackHole�̏�����
void init_bh() {
	p = 0;
	bhHandle = LoadGraph("./src/BlackHole3.png");
	bh.x = FIELD_WIDTH / 2;
	bh.y = 64;
	bh.r = 32;	
}

void move_bh() {
	inCnt = 1;		//�{�[�����u���b�N�z�[���ɓ�������

	for (int i = 0; i < MAX_BALLS; i++) {
		//�u���b�N�z�[���̒��S�ɏ��X�ɋ߂Â�
		if (balls[i].knd == 2) {
			balls[i].x += (bh.x - balls[i].x) * 0.04f;
			balls[i].y += (bh.y - balls[i].y) * 0.04f;
		}
		//�u���b�N�z�[���ƃ{�[���̒��S�_������0.25�������ƃu���b�N�z�[���̒��S�_�Ɉړ�(float�^�̓_�Ɠ_�̓����蔻��Ȃ̂Ō덷�����l��)
		if ((fabsf((bh.x - balls[i].x)) < 0.25f && fabsf((bh.y - balls[i].y)) < 0.25f) && balls[i].knd == 2) {
			balls[i].x = bh.x;
			balls[i].y = bh.y;
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
			balls[i].bFlg) {
			balls[i].knd = 2;
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
	p+=0.01;
	if (p > 2 * M_PI)p = 0;
	DrawRotaGraph((int)bh.x, (int)bh.y, 1.0,p, bhHandle, true);
	//DrawCircle((int)bh.x, (int)bh.y, (int)bh.r, GetColor(0, 255, 0), true);
	DrawFormatString(FIELD_WIDTH - 110, FIELD_HEIGHT - 140, GetColor(255, 255, 255), "BH:%.1f\nBH:%.1f", bh.x, bh.y);
}
