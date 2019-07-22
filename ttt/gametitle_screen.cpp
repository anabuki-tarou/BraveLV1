//---
// gametitle_screen.cpp
//---

//ヘッダーファイル
#include "gametitle_screen.h"
#include "global.h"

//コンストラクタ
CTitleScreen::CTitleScreen()
{
	m_state = TITLE_SCREEN;
}

//デストラクタ
CTitleScreen::~CTitleScreen(){ }

void CTitleScreen::Dest(){ }

//ロード
void CTitleScreen::Load(){
	m_titleImage = LoadGraph("media\\img\\title.png");
	m_middlefont = CreateFontToHandle("メイリオ", 42, -1, DX_FONTTYPE_ANTIALIASING);
}

//初期化
void CTitleScreen::Init(){
	jud = 0;
	for (int i = 0; i < 9; i++){
		tre[i] = 0;
	}
	p = 0;
	pc = 610;
}

//実行処理
void CTitleScreen::Update()
{
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (IsAKeyTrigger(key) == TRUE){
		switch (p){
		case 0:
			m_state = GAME_SCREEN;
			break;
		case 1:
			break;
		case 2:
			m_state = GAMEOPTION_SCREEN;
			break;
		case 3:
			end = TRUE;
			break;
		}
	}
	if (IsUPKeyTrigger(key) == TRUE){
		if (p > 0)
			p--;
	}
	if (IsDOWNKeyTrigger(key) == TRUE){
		if (p < 3)
			p++;
	}
	pc = 610+p*65;
}

//描画
void CTitleScreen::Draw()
{
	ClearDrawScreen();
	DrawBox(0, 0, 1920, 1080, GetColor(255, 255, 255), true);
	DrawRectGraph(750, 600, 29, 30, 400, 252, m_titleImage, TRUE, FALSE);
	DrawRectGraph(700, pc, 27, 309, 31, 39, m_titleImage, TRUE, FALSE);
	DrawRectGraph(780, 200, 99, 359,366, 96, m_titleImage, TRUE, FALSE);
#if defined(_DEBUG) | defined(DEBUG)
#endif
}
//次のステージへ
SCREEN CTitleScreen::GetNextScreen()
{
	return (m_state);
}