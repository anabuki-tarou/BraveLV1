//---
// gameover_screen.cpp
//---

//ヘッダーファイル
#include "gameover_screen.h"

//コンストラクタ
CGameOverScreen::CGameOverScreen()
{
	m_state = GAMEOVER_SCREEN;
}

//デストラクタ
CGameOverScreen::~CGameOverScreen(){ }

void CGameOverScreen::Dest(){
	StopSoundMem(m_GoverSound);
}

//ロード
void CGameOverScreen::Load(){
	m_largefont = CreateFontToHandle("メイリオ", 90, -1, DX_FONTTYPE_ANTIALIASING);
	m_GoverSound = LoadSoundMem("media\\mp3\\fall05.mp3");
}

//初期化
void CGameOverScreen::Init(){
	m_lasttime = GetNowCount() & INT_MAX;
	PlaySoundMem(m_GoverSound, DX_PLAYTYPE_BACK);
}

//実行処理
void CGameOverScreen::Update()
{
	if (((GetNowCount() & INT_MAX) - m_lasttime) > GAMEOVER_TIME) m_state = TITLE_SCREEN;
#if defined(_DEBUG) | defined(DEBUG)
#endif
}

//描画
void CGameOverScreen::Draw()
{
	ClearDrawScreen();
	DrawStringToHandle(100, 200, "ゲームオーバー", GetColor(255, 0, 0), m_largefont);
#if defined(_DEBUG) | defined(DEBUG)
#endif
}

//次のステージへ
SCREEN CGameOverScreen::GetNextScreen()
{
	return (m_state);
}
