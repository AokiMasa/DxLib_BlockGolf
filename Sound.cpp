#include"GV.h"

char file_name[256];

/***********************************************************************
関数のプロトタイプ宣言(関数の宣言のみ。関数の定義は後述。)
loadFiles[0] : SE01.mp3	//タイトル画面BGM
loadFiles[1] : SE02.mp3	//ボールを発射したとき
loadFiles[2] : SE03.mp3	//ボールが物に当たったとき
loadFiles[3] : SE04.mp3	//ステージクリア時のBGM
loadFiles[4] : SE05.mp3	//セレクトボタンをクリック
loadFiles[5] : SE06.mp3	//戻るボタンを押したとき
loadFiles[6] : SE07.mp3	//ゲームオーバー時のBGM
loadFiles[7] : SE08.mp3	//ゲームプレイ中BGM
int i : サウンド番号
int playtype : 再生方法・1ノーマル再生・2バックグラウンド再生・3ループ再生
************************************************************************/
void play_sound(int, int);

void play_sound(int i,int playtype) {
	PlaySoundMem(loadFiles[i+5], playtype);
}
