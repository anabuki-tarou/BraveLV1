//---
// myLib.cpp
//---
#include "myLib.h"
#include "global.h"

CVector2D& CVector2D::operator+=(const CVector2D& ope){
	pos_x += ope.pos_x;
	pos_y += ope.pos_y;
	return *this;
}

CVector2D& CVector2D::operator-=(const CVector2D& ope){
	pos_x -= ope.pos_x;
	pos_y -= ope.pos_y;
	return *this;
}

CVector2D& CVector2D::operator=(const CVector2D& ope){
	pos_x = ope.pos_x;
	pos_y = ope.pos_y;
	return *this;
}

CVector2D& CVector2D::operator+(const CVector2D& ope){
	pos_x += ope.pos_x;
	pos_y += ope.pos_y;
	return *this;
}

BOOL CVector2D::operator==(const CVector2D& ope){
	if ((pos_x == ope.pos_x) && (pos_y == ope.pos_y))
		return true;
	else
		return false;
}

BOOL IsAKeyTrigger(int key){
	static int g_akey_prev;
	if (key & ck[4]){
		if (g_akey_prev == false){
			g_akey_prev = true;
			return true;
		}
	}
	else{
		g_akey_prev = false;
	}
	return false;
}

BOOL IsBKeyTrigger(int key){
	static int g_bkey_prev;
	if (key & ck[5]){
		if (g_bkey_prev == false){
			g_bkey_prev = true;
			return true;
		}
	}
	else{
		g_bkey_prev = false;
	}
	return false;
}

BOOL IsCKeyTrigger(int key){
	static int g_ckey_prev;
	if (key & ck[6]){
		if (g_ckey_prev == false){
			g_ckey_prev = true;
			return true;
		}
	}
	else{
		g_ckey_prev = false;
	}
	return false;
}

BOOL IsUPKeyTrigger(int key){
	static int g_upkey_prev;
	if (key & ck[0]){
		if (g_upkey_prev == false){
			g_upkey_prev = true;
			return true;
		}
	}
	else{
		g_upkey_prev = false;
	}
	return false;
}

BOOL IsDOWNKeyTrigger(int key){
	static int g_downkey_prev;
	if (key & ck[1]){
		if (g_downkey_prev == false){
			g_downkey_prev = true;
			return true;
		}
	}
	else{
		g_downkey_prev = false;
	}
	return false;
}