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
	//����Ȃ��A������Ώ��ŁA�ϋv�l�����A�s��
};


class CCharaData{
public:
	CVector2D pos; //�ʒu���
	int image; //�摜�C���[�W
	int miniimage;//�~�j�C���[�W
	int life; //���C�t
	ATARIMODE amode; //�����蔻�葮��
	int movecounter; //�ړ��J�E���g
public:
	CCharaData(){}
	~CCharaData(){}
	CCharaData(CVector2D po, int img, int li, ATARIMODE amod, int mco): pos(po), image(img), life(li), amode(amod), movecounter(mco){}


	void setPos(const CVector2D &pos){ //���ݒn�ݒ�
		this->pos = pos;
	}
	CVector2D getPos(void)const{ //���ݒn�擾
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