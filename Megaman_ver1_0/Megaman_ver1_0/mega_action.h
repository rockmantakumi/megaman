#pragma once

#include "stdafx.h"
#include "curses.h"
#include <Windows.h>
#include <random>

#define CHARBUFF 124

//画面の限界
#define WidthL	10
#define WidthR	430
#define Height	400

struct Mega {
	char name[CHARBUFF];	//名前
	int HP;	//体力
	int ATK;	//攻撃力
	int jampFlag;	//ジャンプのフラグ
	int moveFlag;	//移動のフラグ
	int attackFlag;	//攻撃のフラグ
	int reverse;	//反転フラグ
	int specialFlag;	//必殺技フラグ
	int height;	//メガマンの高さ
	int width;	//メガマンの幅
	int slidFlag;	//スライディング用フラグ
	int colorCondition;	//色用
};

extern Mega Megaman;

void draw_megaman(Mega Current);	//mega描画 test
void mega_move();	//test

void set_Megaman_place();	//メガマンの初期位置
void set_Megaman_status();	//メガマンのステータス設定
bool mega_attack_hit();


extern int Rx, Ry;	//テスト用メガマン座標
extern int Bx, By;//テスト用メガマン座標
extern int megaattackNum;//メガマンの攻撃上限