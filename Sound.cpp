#include"GV.h"

char file_name[256];

/***********************************************************************
�֐��̃v���g�^�C�v�錾(�֐��̐錾�̂݁B�֐��̒�`�͌�q�B)
loadFiles[0] : SE01.mp3	//�^�C�g�����BGM
loadFiles[1] : SE02.mp3	//�{�[���𔭎˂����Ƃ�
loadFiles[2] : SE03.mp3	//�{�[�������ɓ��������Ƃ�
loadFiles[3] : SE04.mp3	//�X�e�[�W�N���A����BGM
loadFiles[4] : SE05.mp3	//�Z���N�g�{�^�����N���b�N
loadFiles[5] : SE06.mp3	//�߂�{�^�����������Ƃ�
loadFiles[6] : SE07.mp3	//�Q�[���I�[�o�[����BGM
loadFiles[7] : SE08.mp3	//�Q�[���v���C��BGM
int i : �T�E���h�ԍ�
int playtype : �Đ����@�E1�m�[�}���Đ��E2�o�b�N�O���E���h�Đ��E3���[�v�Đ�
************************************************************************/
void play_sound(int, int);

void play_sound(int i,int playtype) {
	PlaySoundMem(loadFiles[i+5], playtype);
}
