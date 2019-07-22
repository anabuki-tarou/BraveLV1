//---
//item.h
//---
#ifndef __ITEMCONTROL_H__
#define __ITEMCONTROL_H__


#include "map.h"
#include <list>
#include "CharaData.h"


const int ITEM_COUNT = 4;

using namespace std;

class CItemData : public CTempData{
public:
	int m_image;
	int miniimage;
	CItemData(){ m_image = 0; }
	~CItemData(){}
};


class CItemControl {
private:
	int img[ITEM_COUNT];
	int mimg[ITEM_COUNT];
	int window;
	int winmo;
	list<CItemData> itemList;
public:
	CItemControl(){ itemList.clear(); }
	~CItemControl(){}
	void loadFiles();
	void init(CVector2D pos, int itemCode);
	void draw();
	int chkItem(CVector2D pos);
	void setItem(CVector2D pos);
	void makeItem(CMapControl* ptr);
};

#endif __ITEMCONTROL_H__