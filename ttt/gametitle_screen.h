//---
// gametitle_screen.h
//---
#ifndef __TITLE_SCREEN_H__
#define __TITLE_SCREEN_H__

//�w�b�_�[�t�@�C��
#include "myLib.h"
#include "screen.h"

//�^�C�g���X�N���[���N���X
class CTitleScreen : public CScreen
{
private:
	SCREEN m_state;
	int    m_titleImage;
	int    m_middlefont;
	int    p;
	int    pc;
public:
	CTitleScreen();
	virtual ~CTitleScreen();
	SCREEN GetNextScreen();
	void Load();
	void Init();
	void Update();
	void Draw();
	void Dest();
};

#endif __TITLE_SCREEN_H__