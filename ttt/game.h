//---
// game.h
//---
#ifndef __GAME_H__
#define __GAME_H__

//ヘッダーファイル
#include "myLib.h"

//プロトタイプ
enum SCREEN;
class CScreen;

//ゲームクラス
class CGame
{
private:
	CScreen* m_pScreen; //現在のスクリーンクラスへのポインタ
	SCREEN   m_now_screen; //画面情報
public:
	CGame();
	~CGame();
	void Init();
	void Update();
	void Draw();
	void Dest();
};

#endif __GAME_H__