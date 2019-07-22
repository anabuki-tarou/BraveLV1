//---
//main.cpp
//---

#include "main.h"
#include "game.h"


CMain::CMain()
{
	m_pGame = new CGame;
}

CMain::~CMain()
{
	delete m_pGame;
	m_pGame = 0;
}

void CMain::Init()
{
	m_pGame->Init();
}

void CMain::Dest()
{
	m_pGame->Dest();
}

void CMain::Update()
{
	//�C���v�b�g

	m_pGame->Update();
}

void CMain::Draw()
{
	m_pGame->Draw();
}