//---
// main.h
//---
#ifndef __MAIN_H__
#define __MAIN_H__

//�w�b�_�[�t�@�C��
#include <stdio.h>
#include "DxLib.h"

//�v���g�^�C�v
class CGame;

//���C���N���X
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