//---
//EnemyMover.cpp
//---
#include "Enemy.h"


//���ړ��������s��mover
void HoriMover::mover(CEnemyData *cd, int miniMap){
	int tempX = cd->getDir();
	//�~�j�}�b�v��񕜌�
	int mpdata = (miniMap >> (4 + tempX)) & 1;
	if (mpdata == 1){
		cd->setPos(cd->getPos() + CVector2D(tempX, 0));
	}
	else{
		cd->setDir(-tempX);
	}
}


//�c�ړ��������s��mover
void VertMover::mover(CEnemyData *cd, int miniMap){
	int tempY = cd->getDir();
	//�~�j�}�b�v��񕜌�
	int mpdata = (miniMap >> (4 + tempY * 3)) & 1;
	if (mpdata == 1){
		cd->setPos(cd->getPos() + CVector2D(0, tempY));
	}
	else{
		cd->setDir(-tempY);
	}
}


//���p��mover
void StayMover::mover(CEnemyData *cd, int miniMap){
	int tempX = cd->getDir();
	//�~�j�}�b�v��񕜌�
	int mpdata = (miniMap >> (4 + tempX)) & 1;
	if (mpdata == 1){
		cd->setPos(cd->getPos() + CVector2D(tempX, 0));
	}
	else{
		cd->setPos(cd->getPos() + CVector2D(0, -100));
		cd->setDir(STOP);
	}
}
