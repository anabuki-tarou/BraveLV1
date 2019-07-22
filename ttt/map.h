//---
// map.h
//---
#ifndef __MAP_H__
#define __MAP_H__

#include "DxLib.h"
#include "myLib.h"
#include "CharaData.h"
#include <list>

using namespace std;
const int MAP_CHIPSIZE = 96;
const int MAP_MINI_CHIPSIZE = 16;
const int MAP_WIDTH = 30;
const int MAP_HEIGHT = 30;
const int BUFSIZE = 256;
const int MINI_MAP_WIDTH = 3;
const int MINI_MAP_HEIGHT = 3;
const int MAP_COUNT = 3;

enum MapItem{
	MPITEM_NO, MPITEM_ROCK, MPITEM_HMONSTER, MPITEM_VMONSTER, MPITEM_DRAGON, MPITEM_FIRE, MPITEM_HEROPOS = 7, MPITEM_KEY, MPITEM_GOAL,MPITEM_TREASURE1,MPITEM_TREASURE2,MPITEM_DEPOSIT
};

struct minimap{
	char m[MINI_MAP_HEIGHT][MINI_MAP_WIDTH];
};

class CMapControl{
private:
	int mapdata[MAP_HEIGHT][MAP_WIDTH];
	int mapitem[MAP_COUNT];
	int mmapitem[MAP_COUNT];
public:
	CMapControl(){}
	~CMapControl(){}
	void loadMap(int stage);
	BOOL loadItem();
	list<CTempData> searchEnemy();
	CVector2D searchMap(MapItem mi);
	void drawMap();
	int getMiniMap(CVector2D pos)const;
	minimap getMiniMap2(CVector2D pos)const;
	BOOL getDeposit(CVector2D pos);
	list<CTempData> searchItem();
};

#endif __MAP_H__