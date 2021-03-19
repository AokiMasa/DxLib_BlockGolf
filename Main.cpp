#define GLOBAL_INSTANCE
#include "GV.h"

int ProcessLoop() {
	if (ProcessMessage() != 0)return -1;//プロセス処理がエラーなら-1を返す
	if (ClearDrawScreen() != 0)return -1;//画面クリア処理がエラーなら-1を返す
	return 0;
}

class Fps {
	int mStartTime;         //測定開始時刻
	int mCount;             //カウンタ
	float mFps;             //fps
	static const int N = 60;//平均を取るサンプル数
	static const int FPS = 144;	//設定したFPS

public:
	Fps() {
		mStartTime = 0;
		mCount = 0;
		mFps = 0;
	}

	bool Update() {
		if (mCount == 0) { //1フレーム目なら時刻を記憶
			mStartTime = GetNowCount();
		}
		if (mCount == N) { //60フレーム目なら平均を計算する
			int t = GetNowCount();
			mFps = 1000.f / ((t - mStartTime) / (float)N);
			mCount = 0;
			mStartTime = t;
		}
		mCount++;
		return true;
	}

	//処理をここに書く
	void Draw() {
		switch (Game)
		{
		case 0:			//初期化

			init_balls();
			init_bh();
			init_blocks();		
			init_sl();
			bCnt = 0;
			slCnt = 0;

			Game = 1;
			break;
		case 1:			//タイトル

			//押されたら移動(出来たら)
			Game = 2;
			break;
		case 2:			//ゲームスタート

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

		case 3:			//予測線用のテスト

			//ShotLine.cpp
			move_sl();
			draw_sl();

			slCnt++;
			//slCnt = (slCnt + 1) % SHOTLINE_OFFSET;
		break;

		case 4:			//クリア、リザルト画面
			Game = 0;
			break;

		case 5:			//ゲームオーバー画面
			Game = 0;
			break;
		default:
			break;
		}

		/*デバッグ用の表示*/
		DrawFormatString(FIELD_WIDTH - 110, FIELD_HEIGHT - 160, GetColor(255, 255, 255), "STAGE:%d", Stage_Num + 1);
		DrawFormatString(FIELD_WIDTH - 110, FIELD_HEIGHT - 20, GetColor(255, 255, 255), "%.1f", mFps);
	}

	void Wait() {
		int tookTime = GetNowCount() - mStartTime;	//かかった時間
		int waitTime = mCount * 1000 / FPS - tookTime;	//待つべき時間
		if (waitTime > 0) {
			Sleep(waitTime);	//待機
		}
	}
};

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	
	// ウインドウモードで起動
	ChangeWindowMode(TRUE);
	// ウインドウのサイズを手動ではできず、且つウインドウのサイズに合わせて拡大もしないようにする
	SetWindowSizeChangeEnableFlag(FALSE, true);
	// 画面サイズは最大の 960x704 にしておく
	SetGraphMode(FIELD_WIDTH, FIELD_HEIGHT, 32);
	// 描画する文字列のサイズを設定
	SetFontSize(12);
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;//初期化と裏画面化

	Fps fps;

	Stage_Num = 0;

	while (ProcessLoop() == 0) {	//メインループ

		fps.Update();	//更新
		fps.Draw();		//描画
		ScreenFlip();	//裏画面反映
		fps.Wait();		//待機
	}

	// 全グラフィックを初期化
	InitGraph();

	// ＤＸライブラリ使用の終了処理
	DxLib_End();					

	return 0;						// ソフトの終了 
}
