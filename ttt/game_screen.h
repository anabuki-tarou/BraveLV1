//---
// game_screen.h
//---
#ifndef __GAME_SCREEN_H__
#define __GAME_SCREEN_H__

//ヘッダーファイル
#include "myLib.h"
#include "screen.h"
#include "map.h"
#include "CharaData.h"
#include "player.h"
#include "Enemy.h"
#include "item.h"
#include "global.h"


//ゲームスクリーンクラス
class CGameScreen : public CScreen
{
private:
	int m_bgm;
	SCREEN m_state;
	CMapControl m_Map;
	CPlayerControl m_PlayerCtl;
	CEnemyControl m_EnemyCtl;
	CItemControl m_ItemCtl;
public:
	CGameScreen();
	virtual~CGameScreen();
	SCREEN GetNextScreen();
	void Load();
	void Init();
	void Update();
	void Draw();
	void Dest();
};

#endif __GAME_SCREEN_H__