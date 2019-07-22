//---
// map.cpp
//---

#include "map.h"
#include "global.h"

void CMapControl::loadMap(int stage){
	char buf[BUFSIZE];
	sprintf_s(buf, sizeof(buf), "media\\txt\\stage%d.txt", stage);
	int fh = FileRead_open(buf);
	for (int y = 0; y < MAP_HEIGHT; y++){
		FileRead_gets(buf, sizeof(buf), fh);
		for (int x = 0; x < MAP_WIDTH; x++){
			mapdata[y][x] = (int)(buf[x] - '0');
		}
	}
	FileRead_close(fh);
}


BOOL CMapControl::loadItem(){
	LoadDivGraph("media\\img\\map.png", MAP_COUNT, 3, 1, MAP_CHIPSIZE, MAP_CHIPSIZE, mapitem);
	LoadDivGraph("media\\img\\minimap.png", MAP_COUNT, 3, 1, MAP_MINI_CHIPSIZE, MAP_MINI_CHIPSIZE, mmapitem);
	return true;
}

void CMapControl::drawMap(){
	for (int y = 0; y < MAP_HEIGHT; y++){
		for (int x = 0; x < MAP_WIDTH; x++){
			DrawGraph((x-scx)*MAP_CHIPSIZE, (y-scy)*MAP_CHIPSIZE, mapitem[MPITEM_NO], false);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
			DrawGraph((x)*MAP_MINI_CHIPSIZE, (y)*MAP_MINI_CHIPSIZE, mmapitem[MPITEM_NO], false);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			int c = mapdata[y][x];
			if (c == MPITEM_ROCK){
				DrawGraph((x-scx)*MAP_CHIPSIZE, (y-scy)*MAP_CHIPSIZE, mapitem[MPITEM_ROCK], true);
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
				DrawGraph((x)*MAP_MINI_CHIPSIZE, (y)*MAP_MINI_CHIPSIZE, mmapitem[MPITEM_ROCK], true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
			if (c == MPITEM_DEPOSIT){
				DrawGraph((x - scx)*MAP_CHIPSIZE, (y - scy)*MAP_CHIPSIZE, mapitem[2], true);
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
				DrawGraph((x)*MAP_MINI_CHIPSIZE, (y)*MAP_MINI_CHIPSIZE, mmapitem[2], true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
		}
	}
}

//マップから全部の敵を探し出す
list<CTempData> CMapControl::searchEnemy(){
	CTempData data;
	list<CTempData> obj;
	obj.clear();
	for (int y = 0; y < MAP_HEIGHT; y++){
		for (int x = 0; x < MAP_WIDTH; x++){
			int c = mapdata[y][x];
			switch (c){
			case MPITEM_DRAGON:
				for (int i = -3; i < 0; i++){  //3slot for FireData
					data.pos = CVector2D(x + i, y);
					data.obj = MPITEM_FIRE;
					obj.push_back(data);
				}
			case MPITEM_HEROPOS:
			case MPITEM_HMONSTER:
			case MPITEM_VMONSTER:
				data.pos = CVector2D(x, y);
				data.obj = c;
				obj.push_back(data);
				mapdata[y][x] = MPITEM_NO;
				break;
			}
		}
	}
	return obj;
}

//マップから特定の物を探す(最初に発見したもののみ)
CVector2D CMapControl::searchMap(MapItem mi){
	if (jud == 0){
		jud = 1;
		return CVector2D(28, 28);
	}
	else if(jud == 1){
		for (int y = 0; y < MAP_HEIGHT; y++){
			for (int x = 0; x < MAP_WIDTH; x++){
				int c = mapdata[y][x];
				if (c == mi){
					mapdata[y][x] = MPITEM_NO;
					return CVector2D(x, y);
				}
			}
		}
	}
	else if (jud == 2){
		jud = 1;
		return CVector2D(28, 3);

	}
	else if (jud == 3){
		jud = 1;
		return CVector2D(7, 4);
	}
	assert(false);
	return CVector2D(-100, -100);
}
//ミニマップ作成
int CMapControl::getMiniMap(CVector2D pos)const{
	int miniMap = 0;
	int yMin = pos.getY() - 1;
	int xMin = pos.getX() - 1;
	for (int y = 0; y < MINI_MAP_HEIGHT; y++){
		for (int x = 0; x < MINI_MAP_WIDTH; x++){
			if (mapdata[yMin + y][xMin + x] == MPITEM_NO) miniMap |= 1 << (MINI_MAP_HEIGHT * y + x);
		}
	}
	return miniMap;
}

//ミニマップ作成2
minimap CMapControl::getMiniMap2(CVector2D pos)const{
	struct minimap mpdata;
	int yMin = pos.getY() - 1;
	int xMin = pos.getX() - 1;
	for (int y = 0; y < MINI_MAP_HEIGHT; y++){
		for (int x = 0; x < MINI_MAP_WIDTH; x++){
			if (mapdata[yMin + y][xMin + x] == MPITEM_NO) mpdata.m[y][x] = 1; else mpdata.m[y][x] = 0;
		}
	}
	return mpdata; 
}

BOOL CMapControl::getDeposit(CVector2D pos){
	if (mapdata[pos.getY()+1][27] == MPITEM_DEPOSIT)
		return TRUE;
	else
		return FALSE;
}

//マップから全アイテムを探し出す
list<CTempData> CMapControl::searchItem(){
	CTempData data;
	list<CTempData> obj;
	obj.clear();
	for (int y = 0; y < MAP_HEIGHT; y++){
		for (int x = 3; x < MAP_WIDTH; x++){
			int c = mapdata[y][x];
			switch (c){
			case MPITEM_GOAL:
			case MPITEM_KEY:
			case MPITEM_TREASURE1:
			case MPITEM_TREASURE2:
				data.pos = CVector2D(x, y);
				data.obj = c;
				obj.push_back(data);
				mapdata[y][x] = MPITEM_NO;
				break;
			}
		}
	}
	return obj;
}