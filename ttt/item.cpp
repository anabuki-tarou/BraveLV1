//---
//item.cpp
//---
#include "item.h"
#include "global.h"

void CItemControl::loadFiles(){
	LoadDivGraph("media\\img\\item.png", ITEM_COUNT, 4, 1, IMG_CHIPSIZE, IMG_CHIPSIZE, img);
	LoadDivGraph("media\\img\\miniitem.png", ITEM_COUNT, 4, 1, IMG_MINI_CHIPSIZE, IMG_MINI_CHIPSIZE, mimg);
	window = LoadGraph("media\\img\\talkwindow.png");
	winmo = LoadGraph("media\\img\\window.png");
}

void CItemControl::init(CVector2D pos, int itemCode){
	CItemData item;
	item.pos = pos;
	item.m_image = img[itemCode - MPITEM_KEY];
	item.miniimage = mimg[itemCode - MPITEM_KEY];
	item.obj = itemCode;
	itemList.push_back(item);
}

void CItemControl::makeItem(CMapControl* ptr){
	list<CTempData> obj = (*ptr).searchItem();
	for (auto it = obj.begin(); it != obj.end(); it++){
		switch ((*it).obj){
		case MPITEM_KEY:
		case MPITEM_GOAL:
		case MPITEM_TREASURE1:
		case MPITEM_TREASURE2:
			init((*it).pos, (*it).obj);
		}
	}
}

void CItemControl::draw(){
	for (auto it = itemList.begin(); it != itemList.end(); it++){
		DrawGraph(((*it).pos.getX() - scx)*IMG_CHIPSIZE , ((*it).pos.getY()-scy)*IMG_CHIPSIZE,(*it).m_image, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA,200);
		DrawGraph(((*it).pos.getX())*IMG_MINI_CHIPSIZE, ((*it).pos.getY())*IMG_MINI_CHIPSIZE, (*it).miniimage, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	DrawGraph(1100, 0, window, TRUE);
	DrawRectGraph(1120, 20, 117, 129, 316, 52, winmo, TRUE, FALSE);
	for (int i = 0; i < 9; i++){
		if (tre[i] == 1)
			DrawGraph(100 * i + 1120, 100, img[i + 2], TRUE);
	}
}


int CItemControl::chkItem(CVector2D pos){
	for (auto it = itemList.begin(); it != itemList.end(); it++){
		if ((*it).pos == pos) return (*it).obj;//ƒAƒCƒeƒ€–¼‚ð•Ô‹p
	}
	return 0; //Žb’è‚Å0=‚È‚µ
}

void CItemControl::setItem(CVector2D pos){
	for (auto it = itemList.begin(); it != itemList.end(); it++){
		if ((*it).pos == pos) (*it).pos = CVector2D(-100, -100);//”Þ•û‚Ö
	}
}