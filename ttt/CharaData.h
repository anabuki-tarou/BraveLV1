//---
// CharaData.h
//---
#ifndef __CHARADATA_H__
#define __CHARADATA_H__


#include"myLib.h"


const int IMG_CHIPSIZE = 96;
const int IMG_MINI_CHIPSIZE = 16;
const int MOVERATE = 7;


enum ATARIMODE{
	A_GHOST, A_NORMAL, A_HARD, A_MORTAL
	//判定なし、当たれば消滅、耐久値を持つ、不死
};


class CCharaData{
public:
	CVector2D pos; //位置情報
	int image; //画像イメージ
	int miniimage;//ミニイメージ
	int life; //ライフ
	ATARIMODE amode; //当たり判定属性
	int movecounter; //移動カウント
public:
	CCharaData(){}
	~CCharaData(){}
	CCharaData(CVector2D po, int img, int li, ATARIMODE amod, int mco): pos(po), image(img), life(li), amode(amod), movecounter(mco){}


	void setPos(const CVector2D &pos){ //現在地設定
		this->pos = pos;
	}
	CVector2D getPos(void)const{ //現在地取得
		return pos;
	}
};


class CTempData{
public:
	CVector2D pos;
	int obj;
	CTempData(){}
	~CTempData(){}
};

#endif __ CHARADATA_H__