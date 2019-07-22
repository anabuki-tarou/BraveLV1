//---
// Player.h
//---
#ifndef __PLAYERCONTROL_H__
#define __PLAYERCONTROL_H__


#include "CharaData.h"
#include "map.h"
#include "item.h"
const int PLAYER_CHIPSIZE = 96;
const int PLAYER_MINI_CHIPSIZE = 16;

class CPlayerData : public CCharaData{
public:
	int moverate;
	CPlayerData(){}
	~CPlayerData(){}
};


class CPlayerControl {
private:
	CPlayerData m_Player;
public:
	CPlayerControl(){}
	~CPlayerControl(){}
	CVector2D getPos()const;
	void loadFiles();
	void init(CVector2D pos);
	void draw();
	void setKey(BOOL key);
	BOOL getKey()const;
	void move(CMapControl *ptr);
	void item(CItemControl *ptr);
	void makePlayer(CMapControl *ptr);
	int gh[12];
	int mini;
	int res;
	int dir;
	int lasttime;
	int timer;
	int time;
};


#endif __PLAYERCONTROL_H__