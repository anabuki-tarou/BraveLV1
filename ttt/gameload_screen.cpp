//---
// gameload_screen.cpp
//---

//�w�b�_�[�t�@�C��
#include "gameload_screen.h"

//�R���X�g���N�^
CGameLoadScreen::CGameLoadScreen()
{
	m_state = GAMELOAD_SCREEN;
}

//�f�X�g���N�^
CGameLoadScreen::~CGameLoadScreen(){ }

void CGameLoadScreen::Dest(){ }

//���[�h
void CGameLoadScreen::Load(){
	m_largefont = CreateFontToHandle("���C���I", 90, -1, DX_FONTTYPE_ANTIALIASING);
}

//������
void CGameLoadScreen::Init() {
	m_lasttime = GetNowCount() & INT_MAX;
}

//���s����
void CGameLoadScreen::Update()
{
	if (((GetNowCount() & INT_MAX) - m_lasttime) > GAMELOAD_TIME) m_state = GAME_SCREEN;
#if defined(_DEBUG) | defined(DEBUG)
#endif
}

//�`��
void CGameLoadScreen::Draw()
{
	ClearDrawScreen();
	DrawBox(0, 0, 800, 600, GetColor(255, 255, 255), true);
	DrawStringToHandle(100, 200, "���[�h��", GetColor(80, 128, 255), m_largefont);
#if defined(_DEBUG) | defined(DEBUG)
#endif
}

//���̃X�e�[�W��
SCREEN CGameLoadScreen::GetNextScreen()
{
	return (m_state);
}
