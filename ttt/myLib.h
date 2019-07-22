//---
// mylib.h
//---
#ifndef __MYLIB_H__
#define __MYLIB_H__

//ヘッダーファイル
#include "DxLib.h"
#include "assert.h"
//#include "memory.h"

//プリプロセッサ
//#define STRUCT_ZERO_CLEAR(X) memset( &X, 0, sizeof( X ) )
#define FPS                   (60)
#define FRAMETIME             (0.016666f)     // =(1.0f/FPS)
#define DEG2RAD               (0.0174528f)    // =(2.0f*3.1415f/360.0f)
#define ARRAY_SIZE(a)         (sizeof(a)/sizeof(a[0]))

//キートリガー処理
BOOL IsAKeyTrigger(int key);
BOOL IsBKeyTrigger(int key);
BOOL IsCKeyTrigger(int key);
BOOL IsUPKeyTrigger(int key);
BOOL IsDOWNKeyTrigger(int key);

class CVector2D{
private:
	int pos_x;
	int pos_y;
public:
	int getX(void)const{ return pos_x; }
	int getY(void)const{ return pos_y; }
	void setX(int x){ pos_x = x; }
	void setY(int y){ pos_y = y; }
	CVector2D() :pos_x(0), pos_y(0){};
	CVector2D(int x, int y) : pos_x(x), pos_y(y){};
	CVector2D& operator +=(const CVector2D& ope);
	CVector2D& operator -=(const CVector2D& ope);
	CVector2D& operator =(const CVector2D& ope);
	CVector2D& operator +(const CVector2D& ope);
	BOOL operator==(const CVector2D& ope);
};
#endif __MYLIB_H__