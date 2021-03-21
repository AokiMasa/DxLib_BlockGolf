#include "GV.h"
#include "Function.h"

int ballHandle;			//�摜
int m_Xpos, m_Ypos;		//�}�E�X���W
double angle = -1.57;	//�����ʓx
int deg;				//�p�x

//������
void init_balls() {
	int x, y;
	ballHandle = LoadGraph("./src/Ball.png");
	GetGraphSize(ballHandle, &x, &y);
	//printfDx("Ball_X:%d Ball_Y:%d\n", x, y);

	for (int i = 0; i < MAX_BALLS; i++) { 
		balls[i].x	   = FIELD_WIDTH / 2;
		balls[i].y	   = FIELD_HEIGHT - 16;
		balls[i].spd_x = BALL_SPEED;
		balls[i].spd_y = BALL_SPEED;
		balls[i].r     = BALL_SIZE / 2;
		balls[i].num   = 0;
		balls[i].hp    = 9;
		balls[i].angle = (float)angle;
		balls[i].tmp   = 0;
		balls[i].deg   = 0;
		balls[i].flag  = false;
		balls[i].bFlg  = true;
		balls[i].knd   = 1;
	}
}

//�{�[���̔��ˊԊu
void shot_balls() {

	GetMousePoint(&m_Xpos, &m_Ypos);				 //�}�E�X���W�̎擾	
	
	if (m_Xpos >= 0 && m_Xpos <= FIELD_WIDTH && m_Ypos >= 0 && m_Ypos <= FIELD_HEIGHT - 16) {
		angle = angle2(m_Xpos, m_Ypos);				 //���W�A���l
		deg = (int)-((float)angle * (180 / M_PI));	 //�x��	
	}

	for (int i = 0; i < MAX_BALLS; i++) {
		//�V���b�g�t���O���L�����ABALL_SHOT_OFFSET���[�v�Ɉ�񔭎�
		if (!balls[i].flag && bCnt%BALL_SHOT_OFFSET == 0) {
			balls[i].x     = FIELD_WIDTH / 2;
			balls[i].y     = FIELD_HEIGHT - 16;
			balls[i].angle = (float)angle;
			balls[i].flag  = true;
			break;
		}
	}
	//printfDx("bCnt:%d\n", bCnt);
}

//�{�[���̈ړ�
void move_balls() {
	for (int i = 0; i < MAX_BALLS; i++) {
		//����if����flag�������ƃo�O���N�����̂ŏ����Ȃ���
		if (balls[i].knd == 1 && balls[i].flag) {
			balls[i].x += (float)cos(balls[i].angle) * balls[i].spd_x;
			balls[i].y += (float)sin(balls[i].angle) * balls[i].spd_y;
		}
		if (balls[i].hp < 0)balls[i].bFlg = false;
	}
}

//��ʊO��Ball���o�Ȃ��悤�ɂ��鏈��
void collision_ball() {
	for (int i = 0; i < MAX_BALLS;i++) {
		if (balls[i].x >= FIELD_WIDTH - (BALL_SIZE / 2)) {
			balls[i].x = FIELD_WIDTH - (BALL_SIZE / 2);
			balls[i].spd_x *= -1;
			balls[i].hp -= 1;

			//�G�t�F�N�g�֌W
			effect[i].onActive = true;
			effect[i].x = balls[i].x;
			effect[i].y = balls[i].y;
		}
		if (balls[i].x <= 0 + (BALL_SIZE / 2)) {
			balls[i].x = 0 + (BALL_SIZE / 2);
			balls[i].spd_x *= -1;
			balls[i].hp -= 1;

			//�G�t�F�N�g�֌W
			effect[i].onActive = true;
			effect[i].x = balls[i].x;
			effect[i].y = balls[i].y;
		}
		if (balls[i].y <= 0 + (BALL_SIZE / 2)) {
			balls[i].y = 0 + (BALL_SIZE / 2);
			balls[i].spd_y *= -1;
			balls[i].hp -= 1;

			//�G�t�F�N�g�֌W
			effect[i].onActive = true;
			effect[i].x = balls[i].x;
			effect[i].y = balls[i].y;
		}
		if (balls[i].y >= FIELD_HEIGHT - (BALL_SIZE / 2)) {
			balls[i].y = FIELD_HEIGHT - (BALL_SIZE / 2);
			balls[i].spd_y *= -1; 
			balls[i].hp -= 1;

			//�G�t�F�N�g�֌W
			effect[i].onActive = true;
			effect[i].x = balls[i].x;
			effect[i].y = balls[i].y;
		}
	}
}

//�摜�̕`��
void draw_ball() {
	//�V���b�g�X�^�[�g���W�����Ă킩��悤�ɂ���
	DrawCircle(FIELD_WIDTH / 2, FIELD_HEIGHT - 16, 10, GetColor(0, 255, 100), true);

	for (int i = 0; i < MAX_BALLS; i++) {
		if (balls[i].bFlg && balls[i].knd != 3)DrawRotaGraph((int)balls[i].x, (int)balls[i].y, 1.0, 0.0, ballHandle, true);//DrawGraph((int)balls[i].x, (int)balls[i].y, ballHandle, true);

		/*�f�o�b�O�p�̕\��*/
		//�e�{�[���̍��W��HP�̕\��
		if (balls[i].knd == 1)DrawFormatString((int)balls[i].x + 8, (int)balls[i].y - 18, GetColor(255, 255, 255), "X:%.1f\nY:%.1f\nHP:%d", balls[i].x, balls[i].y,balls[i].hp);
		//�}�E�X���W�̕\��
		DrawFormatString(FIELD_WIDTH - 110, FIELD_HEIGHT - 100, GetColor(255, 255, 255), "MX:%d\nMY:%d", m_Xpos,m_Ypos);
		//�V���b�g�̃��W�A���l
		DrawFormatString(FIELD_WIDTH - 110, FIELD_HEIGHT - 60, GetColor(255, 255, 255), "ANGLE:%.2lf", angle);
		//�p�x
		DrawFormatString(FIELD_WIDTH - 110, FIELD_HEIGHT - 40, GetColor(255, 255, 255), "DEG:%d", deg);			
	}
}