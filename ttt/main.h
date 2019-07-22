//---
// main.h
//---
#ifndef __MAIN_H__
#define __MAIN_H__

//ヘッダーファイル
#include <stdio.h>
#include "DxLib.h"

//プロトタイプ
class CGame;

//メインクラス
class CMain
{
public:
	CMain();
	~CMain();
	void Init();
	void Dest();
	void Update();
	void Draw();
private:
	CGame* m_pGame;
};

#endif __MAIN_H__