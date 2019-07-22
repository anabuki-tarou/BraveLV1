//---
// gameover_screen.cpp
//---

//�w�b�_�[�t�@�C��
#include "gameover_screen.h"

//�R���X�g���N�^
CGameOverScreen::CGameOverScreen()
{
	m_state = GAMEOVER_SCREEN;
}

//�f�X�g���N�^
CGameOverScreen::~CGameOverScreen(){ }

void CGameOverScreen::Dest(){
	StopSoundMem(m_GoverSound);
}

//���[�h
void CGameOverScreen::Load(){
	m_largefont = CreateFontToHandle("���C���I", 90, -1, DX_FONTTYPE_ANTIALIASING);
	m_GoverSound = LoadSoundMem("media\\mp3\\fall05.mp3");
}

//������
void CGameOverScreen::Init(){
	m_lasttime = GetNowCount() & INT_MAX;
	PlaySoundMem(m_GoverSound, DX_PLAYTYPE_BACK);
}

//���s����
void CGameOverScreen::Update()
{
	if (((GetNowCount() & INT_MAX) - m_lasttime) > GAMEOVER_TIME) m_state = TITLE_SCREEN;
#if defined(_DEBUG) | defined(DEBUG)
#endif
}

//�`��
void CGameOverScreen::Draw()
{
	ClearDrawScreen();
	DrawStringToHandle(100, 200, "�Q�[���I�[�o�[", GetColor(255, 0, 0), m_largefont);
#if defined(_DEBUG) | defined(DEBUG)
#endif
}

//���̃X�e�[�W��
SCREEN CGameOverScreen::GetNextScreen()
{
	return (m_state);
}
