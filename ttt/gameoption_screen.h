//---
// gameoption_screen.h
//---
#ifndef __GAMEOPTION_SCREEN_H__
#define __GAMEOPTION_SCREEN_H__

//ヘッダーファイル
#include "myLib.h"
#include "screen.h"


//ゲームクリアスクリーンクラス
class CGameOptionScreen : public CScreen
{
private:
	SCREEN m_state;
	int    m_largefont;
	int    m_optionImage;
	int p;
	int pc;
	int st;
	BOOL con;
	int cc;
	int p1, p2, p3, p4;
public:
	CGameOptionScreen();
	virtual~CGameOptionScreen();
	SCREEN GetNextScreen();
	void Load();
	void Init();
	void Update();
	void Draw();
	void Dest();
};

#endif __GAMEOPTION_SCREEN_H__