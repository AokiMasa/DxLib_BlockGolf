#include "GV.h"
#include "Function.h"

int slHandle;		//�摜
int slpHandle;      //�摜
double aa = -1.57;  //�����ʓx

//������
void init_sl() {
	slHandle = LoadGraph("./src/Ball.png");
	slpHandle = LoadGraph("./src/Player1.png");

	for (int i = 0; i < MAX_SHOTLINE_POINT; i++) {
		sl[i].x = FIELD_WIDTH / 2;
		sl[i].y = FIELD_HEIGHT - 16;
	}
}

//ShotLine�̓���
void move_sl() {
	int m_Xpos, m_Ypos;
	
	GetMousePoint(&m_Xpos, &m_Ypos);

	if (m_Xpos >= 0 && m_Xpos <= FIELD_WIDTH && m_Ypos >= 0 && m_Ypos <= FIELD_HEIGHT - 16) {
		aa = angle2(m_Xpos, m_Ypos);
	}

	//slCnt����������0�ɖ߂�
	//if (slCnt > SHOTLINE_OFFSET)slCnt = 0;
	//printfDx("slCnt:%d\n", slCnt);
	//printfDx("cnt:%d\n", slCnt);

	for (int i = 0; i < MAX_SHOTLINE_POINT; i++) {	
		//sl[i].x = (FIELD_WIDTH / 2) - SHOTLINE_OFFSET * i;
		//sl[i].y = (FIELD_HEIGHT - 8) - SHOTLINE_OFFSET * i;

		//�X�^�[�g���W����}�E�X��X���W�̊p�x�Ɍ�������i��SHOTLINE_OFFSET�̕���slCnt���ړ�����             
		sl[i].x = (FIELD_WIDTH / 2) + (float)cos(aa) * ((i * SHOTLINE_OFFSET) + slCnt % SHOTLINE_OFFSET);
		//�X�^�[�g���W����}�E�X��Y���W�̊p�x�Ɍ�������i��SHOTLINE_OFFSET�̕���slCnt���ړ����� 
		sl[i].y = (FIELD_HEIGHT - 16) + (float)sin(aa) * ((i * SHOTLINE_OFFSET) + slCnt % SHOTLINE_OFFSET);

		//�E�I�[�o�[�̏ꍇ
		if (sl[i].x >= FIELD_WIDTH - (BALL_SIZE / 2)) {
			sl[i].x += fabsf(sl[i].x - (FIELD_WIDTH -(BALL_SIZE /2))) * -2;
		}
		//���ɃI�[�o�[�̏ꍇ
		else if (sl[i].x <= 0 + (BALL_SIZE / 2)) {
			sl[i].x += fabsf(sl[i].x - (0 + (BALL_SIZE / 2))) * 2;
		}
	}
}

//ShotLine�̕`��
void draw_sl() {
	for (int i = 0; i < MAX_SHOTLINE_POINT; i++) {
		DrawRotaGraph((int)sl[i].x, (int)sl[i].y, 1.0, 0.0, slHandle, true);
		//DrawFormatString((int)sl[i].x + 8, (int)sl[i].y - 8, GetColor(255, 255, 255), "I:%d",i);
		//DrawFormatString((int)sl[i].x + 8, (int)sl[i].y + 8, GetColor(255, 255, 255), "X:%.1f\nY:%.1f", sl[i].x, sl[i].y);
	}	

	//DrawCircle(FIELD_WIDTH / 2, FIELD_HEIGHT - 16, 10, GetColor(0, 255, 100), true);
	//DrawRotaGraph(FIELD_WIDTH / 2, FIELD_HEIGHT - 16, 1.0, 0.0, slHandle, true);
	DrawRotaGraph((FIELD_WIDTH / 2), (FIELD_HEIGHT - 16), 1.0, aa + M_PI / 2, slpHandle, true);
}
