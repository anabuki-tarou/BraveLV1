//---
// game_screen.cpp
//---


//�w�b�_�[�t�@�C��
#include "game_screen.h"


int g_stage = 1;

//�R���X�g���N�^
CGameScreen::CGameScreen()
{
	m_state = GAME_SCREEN;
}

//�f�X�g���N�^
CGameScreen::~CGameScreen(){ }

void CGameScreen::Dest(){
	StopSoundMem(m_bgm);
}

//���[�h
void CGameScreen::Load(){
	m_Map.loadMap(g_stage);
	m_Map.loadItem();
	m_PlayerCtl.loadFiles();
	m_EnemyCtl.loadFiles();
	m_ItemCtl.loadFiles();
	m_bgm = LoadSoundMem("media\\mp3\\music01.mp3");
}

//������
void CGameScreen::Init() {
	m_PlayerCtl.makePlayer(&m_Map);
	m_EnemyCtl.makeEnemy(&m_Map);
	m_ItemCtl.makeItem(&m_Map);
	PlaySoundMem(m_bgm, DX_PLAYTYPE_LOOP);
}

//�X�V����
void CGameScreen::Update()
{
#if defined(_DEBUG) | defined(DEBUG)
#endif
	m_PlayerCtl.move(&m_Map);
	m_EnemyCtl.move(&m_Map);

	//�A�C�e������
	m_PlayerCtl.item(&m_ItemCtl);

	//�X�e�[�W�ړ�����
	CVector2D pos = m_PlayerCtl.getPos();
	if (m_ItemCtl.chkItem(pos) == MPITEM_GOAL){
		g_stage++;
		m_state = GAMELOAD_SCREEN;
		if (g_stage == 1)
		jud = 3;
	}
	if (m_ItemCtl.chkItem(pos) == MPITEM_KEY){
		g_stage--;
		m_state = GAMELOAD_SCREEN;
		if (g_stage == 1)
		jud = 2;
	}

	//�Q�[���N���A����
	if (clear == TRUE)
		m_state = GAMECLEAR_SCREEN;

	//�Q�[���I�[�o�[����
	if (over == TRUE){
		m_state = GAMEOVER_SCREEN;
	}
}

//�`�揈��
void CGameScreen::Draw()
{
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();
	m_Map.drawMap();
	m_PlayerCtl.draw();
	m_EnemyCtl.draw();
	m_ItemCtl.draw();

#if defined(_DEBUG) | defined(DEBUG)
	DrawString(10, 100, "GAME Screen Hit E key to GAMEOVER F key to GAMECLEAR", GetColor(255, 255, 255));
#endif
}

//���̃X�e�[�W��
SCREEN CGameScreen::GetNextScreen()
{
	return (m_state);
}
