#pragma once
#pragma once

//#include "stdafx.h"
#include "curses.h"
#include <Windows.h>
#include <random>

#define CHARBUFF 124

//敵の構造体
struct Enemy {
	char name[CHARBUFF];	//名前
	int HP;	//体力
	int ATK;	//攻撃力
	int speed;	//移動速度
	int jampFlag;	//ジャンプのフラグ
	int moveFlag;	//移動のフラグ
	int attackFlag;	//攻撃のフラグ
	int reverse;	//反転フラグ
	int specialFlag;	//必殺技フラグ
	int specialLimit;	//必殺技使用可能回数
	int attackLimit;	//攻撃回数用フラグ
	int height;	//敵の高さ
	int width;	//敵の幅
};

//各キャラの構造体
extern Enemy Elect;		//stage1
extern Enemy Heat;		//stage2
extern Enemy Hub_hound;	//stage3
extern Enemy Ice_demon;	//stage6

extern Enemy Current;	//現在のキャラの構造体名


void set_Enemy_place();	//敵の初期位置設定
void set_Enemy_status(int stageNum);	//ステータス設定
void draw_enemy(int stageNum);	//ステージごとの敵を描画

								//敵の行動関数
int DistanceEtoR();	//メガマンとの距離測る
void Enemy_action();	//敵の行動選択
void Enemy_moveR();	//右に移動
void Enemy_moveL();	//左に移動
void Enemy_jamp();	//ジャンプ
void Enemy_attack();	//攻撃を選択
void Enemy_atk1();	//攻撃１
void Enemy_atk2();	//攻撃２
void Enemy_DB();	//必殺技


void drop_weapon();	//敵が倒されると武器をドロップする
bool attack_hit(int WxR, int WxL);	//あたり判定
void hit_limit(int WxR, int WxL, int chara_select);	//あたり限界
void Enemy_efect();	//敵の登場エフェクト


extern int Ex, Ey;	//敵の描画座標
extern int Wx, Wy;	//敵の技座標
extern int SPx, SPy;	//敵の必殺技座標

extern int attackNum;	//敵の攻撃制限用カウンタ

extern int hit_count;	//攻撃判定制限用カウンタ


