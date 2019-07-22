//---
//EnemyMover.cpp
//---
#include "Enemy.h"


//横移動だけを行うmover
void HoriMover::mover(CEnemyData *cd, int miniMap){
	int tempX = cd->getDir();
	//ミニマップ情報復元
	int mpdata = (miniMap >> (4 + tempX)) & 1;
	if (mpdata == 1){
		cd->setPos(cd->getPos() + CVector2D(tempX, 0));
	}
	else{
		cd->setDir(-tempX);
	}
}


//縦移動だけを行うmover
void VertMover::mover(CEnemyData *cd, int miniMap){
	int tempY = cd->getDir();
	//ミニマップ情報復元
	int mpdata = (miniMap >> (4 + tempY * 3)) & 1;
	if (mpdata == 1){
		cd->setPos(cd->getPos() + CVector2D(0, tempY));
	}
	else{
		cd->setDir(-tempY);
	}
}


//炎用のmover
void StayMover::mover(CEnemyData *cd, int miniMap){
	int tempX = cd->getDir();
	//ミニマップ情報復元
	int mpdata = (miniMap >> (4 + tempX)) & 1;
	if (mpdata == 1){
		cd->setPos(cd->getPos() + CVector2D(tempX, 0));
	}
	else{
		cd->setPos(cd->getPos() + CVector2D(0, -100));
		cd->setDir(STOP);
	}
}
