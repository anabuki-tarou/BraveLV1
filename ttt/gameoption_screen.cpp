//---
// gameoption_screen.cpp
//---

//ヘッダーファイル
#include "gameoption_screen.h"
#include "global.h"

//コンストラクタ
CGameOptionScreen::CGameOptionScreen()
{
	m_state = GAMEOPTION_SCREEN;
}

//デストラクタ
CGameOptionScreen::~CGameOptionScreen(){ }

void CGameOptionScreen::Dest(){ }

//ロード
void CGameOptionScreen::Load(){
	m_optionImage = LoadGraph("media\\img\\title.png");
	m_largefont = CreateFontToHandle("メイリオ", 90, -1, DX_FONTTYPE_ANTIALIASING);
}

//初期化
void CGameOptionScreen::Init() {
	p = 0;
	pc = 405;
	if (dif == 0){
		st = 390;
	}
	else if (dif == 1){
		st = 470;
	}
	else{
		st = 550;
	}
	con = FALSE;
	cc = 0;
}

//実行処理
void CGameOptionScreen::Update()
{
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (con == FALSE){
		if (IsBKeyTrigger(key) == TRUE) m_state = TITLE_SCREEN;
		if (IsAKeyTrigger(key) == TRUE){
			switch (p){
			case 0:
				dif = 0;//簡単
				st = pc - 15;
				break;
			case 1:
				dif = 1;//普通
				st = pc - 15;
				break;
			case 2:
				dif = 2;//難しい
				st = pc - 15;
				break;
			case 3:
				con = TRUE;
				for (int i = 0; i < 7; i++){
					printfDx("%d", ck[i]);
					ck[i] = 0;
				}
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
	}
	else{
		
		if (cc < 7){
			WaitKey();
			key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
			ck[cc] = key;
			cc++;
		}
		else{
			cc = 0;
			con = FALSE;
			for (int i = 0; i < 7; i++){
				printfDx("%d", ck[i]);
			}
		}
	}
	if (p == 3){
		pc=710;
	}
	else{
		pc = 405 + p * 80;
	}
#if defined(_DEBUG) | defined(DEBUG)
#endif
}

//描画
void CGameOptionScreen::Draw()
{
	ClearDrawScreen();
	if (con == TRUE)
		SetDrawBright(100, 100, 100);
	else
		SetDrawBright(255, 255, 255);
	DrawBox(0, 0, 1920, 1080, GetColor(255, 255, 255), true);
	DrawRectGraph(750, 300, 527, 84, 349, 310, m_optionImage,TRUE,FALSE);
	DrawRectGraph(700, 700, 554, 465, 422, 62, m_optionImage, TRUE, FALSE);
	DrawRectGraph(650, pc, 27, 309, 31, 39, m_optionImage, TRUE, FALSE);
	DrawRectGraph(1100, st, 77, 288, 61, 56, m_optionImage, TRUE, FALSE);
	if (con == TRUE){
		SetDrawBright(255, 255, 255);
		DrawRectGraph(500, 400, 36, 589, 938, 53, m_optionImage, TRUE, FALSE);
		switch (cc){
		case 0:
			p1 = 38; p2 = 651; p3 = 87; p4 = 696;
			break;
		case 1:
			p1 = 136; p2 = 655; p3 = 185; p4 = 699;
			break;
		case 2:
			p1 = 333; p2 = 650; p3 = 381; p4 = 698;
			break;
		case 3:
			p1 = 233; p2 = 650; p3 = 283; p4 = 698;
			break;
		case 4:
			p1 = 427; p2 = 656; p3 = 461; p4 = 695;
			break;
		case 5:
			p1 = 484; p2 = 657; p3 = 514; p4 = 696;
			break;
		case 6:
			p1 = 534; p2 = 656; p3 = 566; p4 = 696;
		}
		DrawRectGraph(500, 600, p1, p2, p3-p1, p4-p2, m_optionImage, TRUE, FALSE);
	}
#if defined(_DEBUG) | defined(DEBUG)
#endif
}

//次のステージへ
SCREEN CGameOptionScreen::GetNextScreen()
{
	return (m_state);
}
