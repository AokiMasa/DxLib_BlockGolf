#include"GV.h"
//�u���b�N�摜�ǂݍ���
void load_BlockImg() {
	loadFiles[0] = LoadGraph("./src/Block2.png");
}
//�{�[���摜�ǂݍ���
void load_BallImg() {
	loadFiles[1] = LoadGraph("./src/Ball3.png");
}
//�u���b�N�z�[���摜�ǂݍ���
void load_BHImg() {
	loadFiles[2] = LoadGraph("./src/BlackHole3.png");
}
//�\�����摜�ǂݍ���
void load_SLImg() {
	loadFiles[3] = LoadGraph("./src/Ball.png");
	loadFiles[4] = LoadGraph("./src/Player1.png");
}
//�e�����ǂݍ���
void load_Sound() {
	char file_name[256];
	for (int i = 0; i < 8; i++) {
		sprintf_s(file_name, sizeof(file_name), "./sound/SE0%d.mp3", i + 1);
		loadFiles[i + 5] = LoadSoundMem(file_name);
	}
}

