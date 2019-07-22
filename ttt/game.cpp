//---
// game.cpp
//---
#include "stdio.h"
#include "screen.h"
#include "gametitle_screen.h"
#include "game_screen.h"
#include "gameover_screen.h"
#include "gameclear_screen.h"
#include "gameload_screen.h"
#include "gameoption_screen.h"
#include "game.h"

CGame::CGame(){ }
CGame::~CGame(){ }

void CGame::Init()
{
	m_now_screen = TITLE_SCREEN;
	m_pScreen = NULL;
}

void CGame::Update()
{
	if (m_pScreen == NULL){
		switch (m_now_screen){
		case TITLE_SCREEN:
			m_pScreen = new CTitleScreen();
			break;
		case GAME_SCREEN:
			m_pScreen = new CGameScreen();
			break;
		case GAMECLEAR_SCREEN:
			m_pScreen = new CGameClearScreen();
			break;
		case GAMEOVER_SCREEN:
			m_pScreen = new CGameOverScreen();
			break;
		case GAMELOAD_SCREEN:
			m_pScreen = new CGameLoadScreen();
			break;
		case GAMEOPTION_SCREEN:
			m_pScreen = new CGameOptionScreen();
			break;
		default:
			assert(false);
		}
		ScreenFlip();
		m_pScreen->Load();
		m_pScreen->Init();
	}
	else{
		m_pScreen->Update();

		if (m_now_screen != m_pScreen->GetNextScreen()){
			m_now_screen = m_pScreen->GetNextScreen();
			m_pScreen->Dest();
			delete m_pScreen;
			m_pScreen = NULL;
		}
	}
}

void CGame::Draw()
{
	if (m_pScreen){
		m_pScreen->Draw();
	}
}
void CGame::Dest()
{
	if (m_pScreen){
		delete m_pScreen;
		m_pScreen = NULL;
	}
}
