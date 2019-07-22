//***
// win_main.cpp
//***
#include "myLib.h"
#include "game.h"
#include "global.h"

//---
// ���[�J���ϐ�
//---
CGame* g_pMain = NULL;
const BOOL WINDOW_SCREEN = true;

//---
// ���[�J���֐�
//---
void win_main_init();
void win_main_loop();
void win_main_dest();

//--
// �E�B���h�D��ʂ̃��C��
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
// ���C������������
//---
void win_main_init()
{
	// DirectX�֌W
	if (WINDOW_SCREEN)
	{
		SetGraphMode(1920, 1080, 32);
		//���ۂ̃T�C�Y(1600,1000)
		SetMainWindowText(_T("�e�X�g�v���O����"));
	}
	if (DxLib_Init() == -1) //���C�u�����̏���������
		return;

	// GAME�֌W
	g_pMain = new CGame();
	g_pMain->Init();
}

//---
// ���C�����[�v����
//---
void win_main_loop(){
	//���C������
	g_pMain->Update();
	g_pMain->Draw();
	ScreenFlip();
}

//---
// ���C���I������
//---
void win_main_dest()
{
	g_pMain->Dest();
	delete g_pMain;
	g_pMain = NULL;
}