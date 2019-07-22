//---
// Enemy.cpp
//---
#include "Enemy.h"
#include "global.h"

HoriMover hmover;
VertMover vmover;
StayMover smover;


void CEnemyControl::loadFiles(){
	LoadDivGraph("media\\img\\enemy.png", IMAGE_COUNT, 4, 1, IMG_CHIPSIZE, IMG_CHIPSIZE, img);
	LoadDivGraph("media\\img\\minienemy.png", IMAGE_COUNT, 4, 1, IMG_MINI_CHIPSIZE, IMG_MINI_CHIPSIZE, mimg);
	fireSound = LoadSoundMem("media\\mp3\\tm2_slash000.mp3");//‰Š‚Ì”­ŽË‰¹
}


void CEnemyControl::init(CVector2D pos, int EnemyCode){
	CEnemyData Enemy;
	Enemy.pos = pos;
	Enemy.life = 0;
	assert(0 <= (EnemyCode - MPITEM_HMONSTER) && (EnemyCode - MPITEM_HMONSTER) < IMAGE_COUNT);
	Enemy.image = img[EnemyCode - MPITEM_HMONSTER];
	Enemy.miniimage = mimg[EnemyCode - MPITEM_HMONSTER];
	switch (EnemyCode){
	case MPITEM_HMONSTER:
		Enemy.BMover = &hmover;
		break;
	case MPITEM_VMONSTER:
		Enemy.BMover = &vmover;
		break;
	case MPITEM_DRAGON:
		break;
	case MPITEM_FIRE:
		Enemy.BMover = &smover;
		break;
	default:
		assert(false);
	}
	Enemy.amode = (ATARIMODE)3;
	Enemy.movecounter = 0;
	Enemy.moverate = 7;
	Enemy.direction = LEFT;
	Enemylist.push_back(Enemy);
}


void CEnemyControl::move(CMapControl *ptr){
	for (auto it = Enemylist.begin(); it != Enemylist.end(); it++){
		(*it).movecounter++;
		(*it).movecounter %= (*it).moverate;
			//“GƒLƒƒƒ‰ˆÚ“®;
		if ((*it).movecounter == 0){
			int miniMap = (*ptr).getMiniMap((*it).getPos());
			(*it).mover(miniMap);
		}
		//ˆÚ“®’âŽ~’†‚Ì“G‚Å‚ ‚ê‚ÎA1/3*60‚ÌŠm—§‚Å•œŠˆ
		if (GetRand(3 * FPS) == 1 && (*it).getDir() == STOP){
			for (auto it3 = it; it3 != Enemylist.end(); it3++){
				if ((*it3).image == img[ENM_IMG_DRAGON]){
					(*it).setDir(LEFT);
					(*it).setPos((*it3).getPos() + CVector2D(-1, 0));
					PlaySoundMem(fireSound, DX_PLAYTYPE_BACK);
					break;
				}
			}
		}
	}
}
void CEnemyControl::draw(){
	for (auto it = Enemylist.begin(); it != Enemylist.end(); it++){
		DrawGraph(((*it).getPos().getX()-scx)*IMG_CHIPSIZE, ((*it).getPos().getY()-scy)*IMG_CHIPSIZE,
			(*it).image, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
		DrawGraph(((*it).getPos().getX())*IMG_MINI_CHIPSIZE, ((*it).getPos().getY())*IMG_MINI_CHIPSIZE,
			(*it).miniimage, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
}

BOOL CEnemyControl::chkEnemy(CVector2D pos){
	for (auto it = Enemylist.begin(); it != Enemylist.end(); it++){
		if ((*it).pos == pos) return true; //true=“G‚ ‚è
	}
	return false; //false=“G‚È‚µ
}


void CEnemyControl::makeEnemy(CMapControl* ptr){
	Enemylist.clear();
	list<CTempData> chara;
	chara = (*ptr).searchEnemy();
	for (auto it = chara.begin(); it != chara.end(); it++){
		switch ((*it).obj){
		case MPITEM_FIRE:
		case MPITEM_HMONSTER:
		case MPITEM_VMONSTER:
		case MPITEM_DRAGON:
			init((*it).pos, (*it).obj);
			break;
		case MPITEM_HEROPOS:
		case MPITEM_KEY:
		case MPITEM_GOAL:
			break;
		default:
			assert(false);
		}
	}
}
