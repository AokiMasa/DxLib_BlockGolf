#include "GV.h"
//#include "Ball.cpp"


int Score = 0;
//������
void init_score(){
	Score = 0;
	DrawFormatString(FIELD_WIDTH - 150, FIELD_HEIGHT - 240, GetColor(255, 255, 255), "SCORE:%d", Score);
}

void draw_score() {
	DrawFormatString(FIELD_WIDTH - 150, FIELD_HEIGHT - 240, GetColor(255, 255, 255), "SCORE:%d", Score);
}


//Score���Z����
void Add_Point() {
	//�������{�[����HP�̔{�̐��l���X�R�A�ɉ��Z
	Score += balls[0].hp * 2;
}