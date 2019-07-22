//***
// win_main.cpp
//***
#include "myLib.h"
#include "game.h"
#include "global.h"

//---
// ローカル変数
//---
CGame* g_pMain = NULL;
const BOOL WINDOW_SCREEN = true;

//---
// ローカル関数
//---
void win_main_init();
void win_main_loop();
void win_main_dest();

//--
// ウィンドゥ画面のメイン
//---
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	win_main_init();

	while (ProcessMessage() == 0){
		win_main_loop();
#if defined(_DEBUG) | defined(DEBUG)
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;
		if (end == TRUE)break;
#endif
	}
	win_main_dest();
}

//---
// メイン初期化処理
//---
void win_main_init()
{
	// DirectX関係
	if (WINDOW_SCREEN)
	{
		SetGraphMode(1920, 1080, 32);
		//実際のサイズ(1600,1000)
		SetMainWindowText(_T("テストプログラム"));
	}
	if (DxLib_Init() == -1) //ライブラリの初期化処理
		return;

	// GAME関係
	g_pMain = new CGame();
	g_pMain->Init();
}

//---
// メインループ処理
//---
void win_main_loop(){
	//メイン処理
	g_pMain->Update();
	g_pMain->Draw();
	ScreenFlip();
}

//---
// メイン終了処理
//---
void win_main_dest()
{
	g_pMain->Dest();
	delete g_pMain;
	g_pMain = NULL;
}