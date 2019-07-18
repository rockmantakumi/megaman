#pragma once
#pragma once

#include "stdafx.h"
#include <curses.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>

#define TATE 300
#define YOKO 1000
#define TATECELL 152
#define YOKOCELL 438

extern int tatewaku;
extern int yokowaku;
extern int submenuflag, menuflag, vert, hori;
extern int stageflag;
extern int startflag;
extern int clearflag[9];
extern int weapon[9];
extern int num, rnd;
extern int counter;

void start(int select);
void init();
void drawmenu();
void drawstart();
void drawbase();
void drawstage(int stagenumber);
void draw_clear();
int drawsubmenu();
void filewrite();