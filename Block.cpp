#include "GV.h"

int blockHandle;		//�摜

/*
int block_map[MAX_BLOCK_Y][MAX_BLOCK_X] = {
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
};


int block_map[MAX_BLOCK_Y][MAX_BLOCK_X] = 
{
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,1,0,1,0,1,0,1,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,0,1,0,1,0,1,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,1,0,1,0,1,0,1,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,0,1,0,1,0,1,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,1,0,1,0,1,0,1,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,0,1,0,1,0,1,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0},
};
*/

//������+����
void init_blocks() {
	
	//�u���b�N�̃t���O��S��False�ɂ��Ă���u���b�N�𐶐�
	int a = 0;
	for (int i = 0; i < MAX_BLOCK_Y; i++) {
		for (int j = 0; j < MAX_BLOCK_X; j++) {
			blocks[a].flg = false;
			//printfDx("a:%d\n", a);
			a++;
		}
	}
	

	blockHandle = LoadGraph("./src/Block.jpg");

	int x, y;
	GetGraphSize(blockHandle, &x, &y);
	//printfDx("Block_X:%d Block_Y:%d\n", x,y);
	create_blocks();
	
	/*
	//�u���b�N�̃}�b�v�f�[�^��1�̏ꏊ����True�ɂ���
	int i, j;
	int count = 0;
	for (i = 0; i < MAX_BLOCK_Y; i++) {
		for (j = 0; j < MAX_BLOCK_X; j++) {
			if (block_map[i][j] != 0) {
				blocks[count].x = BLOCK_WIDTH * (float)j;
				blocks[count].y = BLOCK_HEIGHT * (float)i;
				blocks[count].flg = true;
				blocks[count].hp = 9;//�����̓u���b�N��HP�p��HP�f�[�^���g���E�������̓����_����HP�����蓖�Ă�
			}
			count++;
		}
	}
	*/
}

//�u���b�N�̓����蔻��
void collision_block() {
	for (int i = 0; i < MAX_BLOCKS; i++) {
		for (int j = 0; j < MAX_BALLS; j++) {
			if (blocks[i].flg && balls[j].bFlg) {
				//��ʂ̓����蔻��
				if (balls[j].x > blocks[i].x && balls[j].x < blocks[i].x + BLOCK_WIDTH &&
					balls[j].y > blocks[i].y - (BALL_SIZE / 4) && balls[j].y < blocks[i].y + COLLISION_OFFSET) {
					balls[j].y = blocks[i].y - (BALL_SIZE / 2);
					balls[j].spd_y *= -1;
					balls[j].hp -= 1;
					blocks[i].hp -= 1;

					//�G�t�F�N�g�֌W
					effect[j].onActive = true;
					effect[j].x = balls[j].x;
					effect[j].y = balls[j].y;
				}
				//���ʂ̓����蔻��
				if (balls[j].x > blocks[i].x && balls[j].x < blocks[i].x + BLOCK_WIDTH &&
					balls[j].y < blocks[i].y + (BLOCK_HEIGHT + (BALL_SIZE / 2)) && balls[j].y > blocks[i].y + BLOCK_HEIGHT - COLLISION_OFFSET) {
					balls[j].y = blocks[i].y + (BLOCK_HEIGHT + (BALL_SIZE / 2));
					balls[j].spd_y *= -1;
					balls[j].hp -= 1;
					blocks[i].hp -= 1;

					//�G�t�F�N�g�֌W
					effect[j].onActive = true;
					effect[j].x = balls[j].x;
					effect[j].y = balls[j].y;
				}
				//���ʂ̓����蔻��
				if (balls[j].y > blocks[i].y && balls[j].y < blocks[i].y + BLOCK_HEIGHT &&
					balls[j].x > blocks[i].x - (BALL_SIZE / 4) && balls[j].x < blocks[i].x + COLLISION_OFFSET) {
					balls[j].x = blocks[i].x - (BALL_SIZE / 2);
					balls[j].spd_x *= -1;
					balls[j].hp -= 1;
					blocks[i].hp -= 1;

					//�G�t�F�N�g�֌W
					effect[j].onActive = true;
					effect[j].x = balls[j].x;
					effect[j].y = balls[j].y;
				}
				//�E�ʂ̓����蔻��
				if (balls[j].y > blocks[i].y && balls[j].y < blocks[i].y + BLOCK_HEIGHT &&
					balls[j].x < blocks[i].x + (BLOCK_WIDTH + (BALL_SIZE / 2)) && balls[j].x > blocks[i].x + BLOCK_WIDTH - COLLISION_OFFSET) {
					balls[j].x = blocks[i].x + (BLOCK_WIDTH + (BALL_SIZE / 2));
					balls[j].spd_x *= -1;
					balls[j].hp -= 1;
					blocks[i].hp -= 1;

					//�G�t�F�N�g�֌W
					effect[j].onActive = true;
					effect[j].x = balls[j].x;
					effect[j].y = balls[j].y;
				}
			}
		}
		if (blocks[i].hp < 0)blocks[i].flg = false;
	}
}

//�摜�̕`��
void draw_block() {

	for (int i = 0; i < MAX_BLOCKS; i++) {

		/*DrawBox(blocks[0].x,
				blocks[0].y,
				blocks[0].x + BLOCK_WIDTH,
				blocks[0].y + BLOCK_HEIGHT,
				GetColor(100, 200, 100), true);
		*/
		
		if (blocks[i].flg) {
			//�摜�̕`��
			DrawGraph((int)blocks[i].x, (int)blocks[i].y, blockHandle, true);

			/*�f�o�b�O�p�̕\��*/
			//�eBlock�̈ʒu���W
			DrawFormatString((int)blocks[i].x + (BLOCK_WIDTH / 4), (int)blocks[i].y + (BLOCK_HEIGHT / 8), GetColor(255, 0, 0), "X:%d\nY:%d\nHP:%d\nFLG:%d", (int)blocks[i].x, (int)blocks[i].y, blocks[i].hp, blocks[i].flg);
		}
	}
}
