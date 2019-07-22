//---
// gameclear_screen.h
//---
#ifndef __GAMECLEAR_SCREEN_H__
#define __GAMECLEAR_SCREEN_H__

//�w�b�_�[�t�@�C��
#include "myLib.h"
#include "screen.h"

const int GAMECLEAR_TIME = (3 * 1000);  //3*1000ms

//�Q�[���N���A�X�N���[���N���X
class CGameClearScreen : public CScreen
{
private:
	SCREEN m_state;
	int    m_largefont;
	int    m_lasttime;
	int	   img[4];
public:
	CGameClearScreen();
	virtual~CGameClearScreen();
	SCREEN GetNextScreen();
	void Load();
	void Init();
	void Update();
	void Draw();
	void Dest();
};

#endif __GAMECLEAR_SCREEN_H__