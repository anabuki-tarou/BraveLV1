//---
// Enemy.h
//---
#ifndef __ENEMYCONTRPL_H__
#define __ENEMYCONTROL_H__

#include "CharaData.h"
#include <list>
#include "map.h"


const int IMAGE_COUNT = 4;


enum Dir{LEFT=-1,STOP=0,RIGHT=1};
enum EnemyType{ENM_IMG_ZAKO1,ENM_IMG_ZAKO2,ENM_IMG_DRAGON,ENM_IMG_FIRE};
using namespace std;


class CEnemyData;
class BaseMover{
public:
	virtual void mover(CEnemyData *cd, int miniMap){};
};


class CEnemyData : public CCharaData{
public:
	int direction; //移動方向
	int moverate;
	BaseMover *BMover;
	void mover(int miniMap){
		if (BMover != NULL)		BMover->mover(this, miniMap);
	}
	void setDir(int dir){
		direction = dir;
	}
	int getDir()const{
		return direction;
	}
	void setPos(CVector2D pos){
		//if (pos.getX()<0 || pos.getX()>MAP_WIDTH || pos.getY() < 0 || pos.getY() > MAP_HEIGHT)return;
		this->pos = pos;
	}


	CEnemyData(){ BMover = 0; }
	~CEnemyData(){}
};

class CEnemyControl{
private:
	int fireSound;
	int img[IMAGE_COUNT];
	int mimg[IMAGE_COUNT];
	list<CEnemyData> Enemylist;
public:
	CEnemyControl(){ Enemylist.clear(); }
	~CEnemyControl(){}
	void loadFiles();
	void init(CVector2D pos, int EnemyCode);
	void draw();
	BOOL chkEnemy(CVector2D pos);
	void move(CMapControl* ptr);
	void makeEnemy(CMapControl* ptr);
};


//横移動だけを行うmover
class HoriMover : public BaseMover{
public:
	void mover(CEnemyData *cd, int miniMap);
};


//縦移動だけを行うmover
class VertMover : public BaseMover{
public:
	void mover(CEnemyData *cd, int miniMap);
};

//炎用のmover
class StayMover : public BaseMover{
public:
	void mover(CEnemyData *cd, int miniMap);
};


#endif __ENEMYCONTROL_H__