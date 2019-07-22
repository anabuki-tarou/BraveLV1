//---
// gameload_screen.h
//---
#ifndef __GAMELOAD_SCREEN_H__
#define __GAMELOAD_SCREEN_H__

//�w�b�_�[�t�@�C��
#include "myLib.h"
#include "screen.h"

const int GAMELOAD_TIME = (2 * 1000);  //2*1000ms

//�Q�[���N���A�X�N���[���N���X
class CGameLoadScreen : public CScreen
{
private:
	SCREEN m_state;
	int    m_largefont;
	int    m_lasttime;
public:
	CGameLoadScreen();
	virtual~CGameLoadScreen();
	SCREEN GetNextScreen();
	void Load();
	void Init();
	void Update();
	void Draw();
	void Dest();
};

#endif __GAMELOAD_SCREEN_H__