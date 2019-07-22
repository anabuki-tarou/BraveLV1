//---
// gametitle_screen.cpp
//---

//�w�b�_�[�t�@�C��
#include "gametitle_screen.h"
#include "global.h"

//�R���X�g���N�^
CTitleScreen::CTitleScreen()
{
	m_state = TITLE_SCREEN;
}

//�f�X�g���N�^
CTitleScreen::~CTitleScreen(){ }

void CTitleScreen::Dest(){ }

//���[�h
void CTitleScreen::Load(){
	m_titleImage = LoadGraph("media\\img\\title.png");
	m_middlefont = CreateFontToHandle("���C���I", 42, -1, DX_FONTTYPE_ANTIALIASING);
}

//������
void CTitleScreen::Init(){
	jud = 0;
	for (int i = 0; i < 9; i++){
		tre[i] = 0;
	}
	p = 0;
	pc = 610;
}

//���s����
void CTitleScreen::Update()
{
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (IsAKeyTrigger(key) == TRUE){
		switch (p){
		case 0:
			m_state = GAME_SCREEN;
			break;
		case 1:
			break;
		case 2:
			m_state = GAMEOPTION_SCREEN;
			break;
		case 3:
			end = TRUE;
			break;
		}
	}
	if (IsUPKeyTrigger(key) == TRUE){
		if (p > 0)
			p--;
	}
	if (IsDOWNKeyTrigger(key) == TRUE){
		if (p < 3)
			p++;
	}
	pc = 610+p*65;
}

//�`��
void CTitleScreen::Draw()
{
	ClearDrawScreen();
	DrawBox(0, 0, 1920, 1080, GetColor(255, 255, 255), true);
	DrawRectGraph(750, 600, 29, 30, 400, 252, m_titleImage, TRUE, FALSE);
	DrawRectGraph(700, pc, 27, 309, 31, 39, m_titleImage, TRUE, FALSE);
	DrawRectGraph(780, 200, 99, 359,366, 96, m_titleImage, TRUE, FALSE);
#if defined(_DEBUG) | defined(DEBUG)
#endif
}
//���̃X�e�[�W��
SCREEN CTitleScreen::GetNextScreen()
{
	return (m_state);
}