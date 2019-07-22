//---
// Player.cpp
//---
#include "Player.h"
#include "global.h"


void CPlayerControl::loadFiles(){
	LoadDivGraph("media\\img\\chara.png",12,3,4,PLAYER_CHIPSIZE,PLAYER_CHIPSIZE,gh);
	mini = LoadGraph("media\\img\\smp1_chara012.png");
}


void CPlayerControl::init(CVector2D pos){
	this->m_Player.pos = pos;
	m_Player.life = 3;
	m_Player.amode = A_NORMAL;
	m_Player.moverate = 7;
	dir = 5;
	timer = 0;
	if (m_Player.pos.getX() > 9){
		scx = m_Player.pos.getX() - 8;
		if (scx > 10)
			scx = 10;
	}
	if (m_Player.pos.getY() > 5){
		scy = m_Player.pos.getY() - 4;
		if (scy > 19)
			scy = 19;
	}
	clear = FALSE;
}


void CPlayerControl::makePlayer(CMapControl* ptr){
	CVector2D pos = ptr->searchMap(MPITEM_HEROPOS);
	init(pos);
}


CVector2D CPlayerControl::getPos()const{
	return m_Player.getPos();
}

void CPlayerControl::item(CItemControl *ptr){
	CVector2D pos = m_Player.getPos();
	if ((ptr->chkItem(pos)) == MPITEM_TREASURE1){
		ptr->setItem(pos);
		tre[0] = 1;
	}
	if ((ptr->chkItem(pos)) == MPITEM_TREASURE2){
		ptr->setItem(pos);
		tre[1] = 1;
	}
}

void CPlayerControl::move(CMapControl* ptr){
	m_Player.movecounter++;
	m_Player.movecounter %= m_Player.moverate;
	lasttime = GetNowCount() & INT_MAX;
	if (timer == 0)
		timer = lasttime;
	//自キャラ移動
	if (m_Player.movecounter == 0){
		struct minimap miniMap;
		//ミニマップ情報をマップに問い合わせ
		miniMap = ptr->getMiniMap2(m_Player.getPos());
		int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		//ダミー
		if (IsAKeyTrigger(key) == TRUE){
			if (ptr->getDeposit(m_Player.getPos()) == TRUE){
				printfDx("いえーーーーーーーーーーーーーーーーーーーーーーい");
				for (int i = 0; i < 9; i++){
					if (tre[i] == 1)
						tre[i] = 2;
				}
				time = lasttime;
			}
			printfDx("%d\n", key);
		}
		if (IsBKeyTrigger(key) == TRUE){
			if (time + 500 > lasttime){
				printfDx("%d\n", key);
				printfDx("Foooooooooooooooooooooooooooooo!!!!!");
			}
		}
		if (IsCKeyTrigger(key) == TRUE){
			printfDx("%d\n", key);
		}
		//現在の中央を(1,1)として、加算値を算出
		int hx = 1, hy = 1;
		if (key & ck[0]){
			printfDx("%d\n", key);
			hy -= 1; dir = 2; res = 0;
		}
		else if (key & ck[1]){
			printfDx("%d\n", key);
			hy += 1; dir = 5; res = 3;
		}
		else if (key & ck[2]){
			printfDx("%d\n", key);
			hx -= 1; dir = 8; res = 6;
		}
		else if (key & ck[3]){
			printfDx("%d\n", key);
			hx += 1; dir = 11; res = 9;
		}
		else{
			res = dir;
		}
		if (res == 0 && timer + 300 < lasttime){
			res = 1;
			timer = lasttime;
		}
		if (res == 3 && timer + 300 < lasttime){
			res = 4;
			timer = lasttime;
		}
		if (res == 6 && timer + 300 < lasttime){
			res = 7;
			timer = lasttime;
		}
		if (res == 9 && timer + 300 < lasttime){
			res = 10;
			timer = lasttime;
		}
		if (miniMap.m[hy][hx] == 1){

			m_Player.pos = m_Player.pos + CVector2D((hx - 1), (hy - 1));
			if (m_Player.pos.getX() > 9){
				if (hx == 2){
					if (scx < 10)
						scx++;
				}
			}
			if (m_Player.pos.getX() < 19){
				if (hx == 0){
					if (scx > 0)
						scx--;
				}
			}
			if (m_Player.pos.getY() > 5){
				if (hy == 2){
					if (scy < 19)
						scy++;
				}
			}
			if (m_Player.pos.getY() < 24){
				if (hy == 0){
					if (scy > 0)
						scy--;
				}
			}
		}
		
	}
	//クリア判定
	if (m_Player.pos.getX() == 28 && m_Player.pos.getY() == 29)
		clear = TRUE;
	
}


void CPlayerControl::draw(){
	DrawGraph(m_Player.pos.getX() * PLAYER_CHIPSIZE-scx*PLAYER_CHIPSIZE, m_Player.pos.getY() * PLAYER_CHIPSIZE - scy*PLAYER_CHIPSIZE, gh[res], true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawGraph(m_Player.pos.getX() * PLAYER_MINI_CHIPSIZE, m_Player.pos.getY() * PLAYER_MINI_CHIPSIZE, mini, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

/*void CPlayerControl::setKey(BOOL key){
	this->m_Player.key = key;
}

BOOL CPlayerControl::getKey()const{
	return m_Player.key;
}*/
