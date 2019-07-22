//---
// gameload_screen.cpp
//---

//ヘッダーファイル
#include "gameload_screen.h"

//コンストラクタ
CGameLoadScreen::CGameLoadScreen()
{
	m_state = GAMELOAD_SCREEN;
}

//デストラクタ
CGameLoadScreen::~CGameLoadScreen(){ }

void CGameLoadScreen::Dest(){ }

//ロード
void CGameLoadScreen::Load(){
	m_largefont = CreateFontToHandle("メイリオ", 90, -1, DX_FONTTYPE_ANTIALIASING);
}

//初期化
void CGameLoadScreen::Init() {
	m_lasttime = GetNowCount() & INT_MAX;
}

//実行処理
void CGameLoadScreen::Update()
{
	if (((GetNowCount() & INT_MAX) - m_lasttime) > GAMELOAD_TIME) m_state = GAME_SCREEN;
#if defined(_DEBUG) | defined(DEBUG)
#endif
}

//描画
void CGameLoadScreen::Draw()
{
	ClearDrawScreen();
	DrawBox(0, 0, 800, 600, GetColor(255, 255, 255), true);
	DrawStringToHandle(100, 200, "ロード中", GetColor(80, 128, 255), m_largefont);
#if defined(_DEBUG) | defined(DEBUG)
#endif
}

//次のステージへ
SCREEN CGameLoadScreen::GetNextScreen()
{
	return (m_state);
}
