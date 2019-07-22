//---
// gameclear_screen.cpp
//---

//ヘッダーファイル
#include "gameclear_screen.h"
#include "global.h"

//コンストラクタ
CGameClearScreen::CGameClearScreen()
{
	m_state = GAMECLEAR_SCREEN;
}

//デストラクタ
CGameClearScreen::~CGameClearScreen(){ }

void CGameClearScreen::Dest(){ }

//ロード
void CGameClearScreen::Load(){
	m_largefont = CreateFontToHandle("メイリオ", 90, -1, DX_FONTTYPE_ANTIALIASING);
	LoadDivGraph("media\\img\\item.png", 4, 4, 1, 96, 96, img);
}

//初期化
void CGameClearScreen::Init() {
	m_lasttime = GetNowCount() & INT_MAX;
}

//実行処理
void CGameClearScreen::Update()
{
	if (((GetNowCount() & INT_MAX) - m_lasttime) > GAMECLEAR_TIME) m_state = TITLE_SCREEN;
#if defined(_DEBUG) | defined(DEBUG)
#endif
}

//描画
void CGameClearScreen::Draw()
{
	ClearDrawScreen();
	DrawBox(0, 0, 800, 600, GetColor(255, 255, 255), true);
	DrawStringToHandle(100, 200, "ゲームクリア", GetColor(80, 128, 255), m_largefont);
	for (int i = 0; i < 9; i++){
		if (tre[i] == 2)
		DrawGraph(100 * i, 500, img[i + 2],TRUE);
	}
#if defined(_DEBUG) | defined(DEBUG)
#endif
}

//次のステージへ
SCREEN CGameClearScreen::GetNextScreen()
{
	return (m_state);
}
