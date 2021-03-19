#define GLOBAL_INSTANCE
#include "GV.h"

int ProcessLoop() {
	if (ProcessMessage() != 0)return -1;//�v���Z�X�������G���[�Ȃ�-1��Ԃ�
	if (ClearDrawScreen() != 0)return -1;//��ʃN���A�������G���[�Ȃ�-1��Ԃ�
	return 0;
}

class Fps {
	int mStartTime;         //����J�n����
	int mCount;             //�J�E���^
	float mFps;             //fps
	static const int N = 60;//���ς����T���v����
	static const int FPS = 144;	//�ݒ肵��FPS

public:
	Fps() {
		mStartTime = 0;
		mCount = 0;
		mFps = 0;
	}

	bool Update() {
		if (mCount == 0) { //1�t���[���ڂȂ玞�����L��
			mStartTime = GetNowCount();
		}
		if (mCount == N) { //60�t���[���ڂȂ畽�ς��v�Z����
			int t = GetNowCount();
			mFps = 1000.f / ((t - mStartTime) / (float)N);
			mCount = 0;
			mStartTime = t;
		}
		mCount++;
		return true;
	}

	//�����������ɏ���
	void Draw() {
		switch (Game)
		{
		case 0:			//������

			init_balls();
			init_bh();
			init_blocks();		
			init_sl();
			bCnt = 0;
			slCnt = 0;

			Game = 1;
			break;
		case 1:			//�^�C�g��

			//�����ꂽ��ړ�(�o������)
			Game = 2;
			break;
		case 2:			//�Q�[���X�^�[�g

			//BlackHole.cpp
			move_bh();
			collision_bh();
			draw_bh();

			//Ball.cpp
			shot_balls();
			move_balls();
			collision_ball();
			draw_ball();

			//Block.cpp
			collision_block();
			draw_block();
			
			bCnt++;

		break;

		case 3:			//�\�����p�̃e�X�g

			//ShotLine.cpp
			move_sl();
			draw_sl();

			slCnt++;
			//slCnt = (slCnt + 1) % SHOTLINE_OFFSET;
		break;

		case 4:			//�N���A�A���U���g���
			Game = 0;
			break;

		case 5:			//�Q�[���I�[�o�[���
			Game = 0;
			break;
		default:
			break;
		}

		/*�f�o�b�O�p�̕\��*/
		DrawFormatString(FIELD_WIDTH - 110, FIELD_HEIGHT - 160, GetColor(255, 255, 255), "STAGE:%d", Stage_Num + 1);
		DrawFormatString(FIELD_WIDTH - 110, FIELD_HEIGHT - 20, GetColor(255, 255, 255), "%.1f", mFps);
	}

	void Wait() {
		int tookTime = GetNowCount() - mStartTime;	//������������
		int waitTime = mCount * 1000 / FPS - tookTime;	//�҂ׂ�����
		if (waitTime > 0) {
			Sleep(waitTime);	//�ҋ@
		}
	}
};

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	
	// �E�C���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);
	// �E�C���h�E�̃T�C�Y���蓮�ł͂ł����A���E�C���h�E�̃T�C�Y�ɍ��킹�Ċg������Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, true);
	// ��ʃT�C�Y�͍ő�� 960x704 �ɂ��Ă���
	SetGraphMode(FIELD_WIDTH, FIELD_HEIGHT, 32);
	// �`�悷�镶����̃T�C�Y��ݒ�
	SetFontSize(12);
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;//�������Ɨ���ʉ�

	Fps fps;

	Stage_Num = 0;

	while (ProcessLoop() == 0) {	//���C�����[�v

		fps.Update();	//�X�V
		fps.Draw();		//�`��
		ScreenFlip();	//����ʔ��f
		fps.Wait();		//�ҋ@
	}

	// �S�O���t�B�b�N��������
	InitGraph();

	// �c�w���C�u�����g�p�̏I������
	DxLib_End();					

	return 0;						// �\�t�g�̏I�� 
}
