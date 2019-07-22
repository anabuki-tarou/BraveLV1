//---
// gameclear_screen.cpp
//---

//�w�b�_�[�t�@�C��
#include "gameclear_screen.h"
#include "global.h"

//�R���X�g���N�^
CGameClearScreen::CGameClearScreen()
{
	m_state = GAMECLEAR_SCREEN;
}

//�f�X�g���N�^
CGameClearScreen::~CGameClearScreen(){ }

void CGameClearScreen::Dest(){ }

//���[�h
void CGameClearScreen::Load(){
	m_largefont = CreateFontToHandle("���C���I", 90, -1, DX_FONTTYPE_ANTIALIASING);
	LoadDivGraph("media\\img\\item.png", 4, 4, 1, 96, 96, img);
}

//������
void CGameClearScreen::Init() {
	m_lasttime = GetNowCount() & INT_MAX;
}

//���s����
void CGameClearScreen::Update()
{
	if (((GetNowCount() & INT_MAX) - m_lasttime) > GAMECLEAR_TIME) m_state = TITLE_SCREEN;
#if defined(_DEBUG) | defined(DEBUG)
#endif
}

//�`��
void CGameClearScreen::Draw()
{
	ClearDrawScreen();
	DrawBox(0, 0, 800, 600, GetColor(255, 255, 255), true);
	DrawStringToHandle(100, 200, "�Q�[���N���A", GetColor(80, 128, 255), m_largefont);
	for (int i = 0; i < 9; i++){
		if (tre[i] == 2)
		DrawGraph(100 * i, 500, img[i + 2],TRUE);
	}
#if defined(_DEBUG) | defined(DEBUG)
#endif
}

//���̃X�e�[�W��
SCREEN CGameClearScreen::GetNextScreen()
{
	return (m_state);
}
