#pragma once
#pragma once

#include "stdafx.h"
#include <curses.h>

#define CHARBUFF 124

//メガマンの描画用関数
void megaman(int mx, int my, int Condition);//メガマンの通常時の絵
void reverse_megaman(int mx, int my, int Condition);	//メガマンの通常時（反転）
void mega_move(int mx, int my, int Condition);//メガマンの走っている状態
void reverse_mega_move(int mx, int my, int Condition);//メガマンの走っている状態（反転）
void mega_jamp(int mx, int my, int Condition);//メガマンのジャンプ時
void reverse_mega_jamp(int mx, int my, int Condition);//メガマンのジャンプ時（反転）
void mega_buster(int mx, int my, int Condition);//メガマンの攻撃時
void reverse_mega_buster(int mx, int my, int Condition);//メガマンの攻撃時（反転）
void exemark(int mx, int my);//エグゼマークの描画
void draw_suraimega(int rx, int ry, int Condition);//メガマンのスライディング
void draw_revslidmega(int rx, int ry, int Condition);//メガマンのスライディング（反転）

void slid_megaman();//スライデイングの移動メソッド
void megaman_attack();//メガマンの攻撃のメソッド
void attack(int x, int y, int Condition);//メガマンの攻撃の玉の描画
