//---
// screen.h
//---
#ifndef __SCREEN_H__
#define __SCREEN_H__

//ゲームスクリーンの種類
enum SCREEN {
	TITLE_SCREEN,
	GAME_SCREEN,
	GAMECLEAR_SCREEN,
	GAMEOVER_SCREEN,
	GAMELOAD_SCREEN,
	GAMEOPTION_SCREEN
};

class CScreen
{
public:
	virtual SCREEN GetNextScreen() = 0; //次のスクリーンを示す
	virtual void Load(){}
	virtual void Init(){}
	virtual void Update(){}
	virtual void Draw(){}
	virtual void Dest(){}
};

#endif __SCREEN_H__