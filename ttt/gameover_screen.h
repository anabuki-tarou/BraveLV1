//---
// gameover_screen.h
//---
#ifndef __GAMEOVER_SCREEN_H__
#define __GAMEOVER_SCREEN_H__

//ヘッダーファイル
#include "myLib.h"
#include "screen.h"

const int GAMEOVER_TIME = (5 * 1000);   //5*1000ms
//ゲームオーバースクリーンクラス
class CGameOverScreen : public CScreen
{
private:
	int m_GoverSound;
	SCREEN m_state;
	int    m_largefont;
	int    m_lasttime;
public:
	CGameOverScreen();
	virtual~CGameOverScreen();
	SCREEN GetNextScreen();
	void Load();
	void Init();
	void Update();
	void Draw();
	void Dest();
};

#endif __GAMEOVER_SCREEN_H__