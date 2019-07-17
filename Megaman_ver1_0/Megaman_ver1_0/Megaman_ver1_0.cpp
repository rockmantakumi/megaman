// Fin_kadai_mega.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "curses.h"
#include "draw_enemy.h"
#include "draw_mega.h"
#include "enemy_action.h"
#include "Mega_action.h"
#include "Stage.h"
#include <Windows.h>
#include <random>


void show_status(int stageNum);	//ステータス見せる
bool Enemy_deth();		//敵の死亡判定
bool Megaman_deth();	//メガマンの死亡フラグ

int main()
{

	//ここからCursesの初期設定---------------------------------------------------------------------------
	init();

	if (initscr() == NULL) {
		return 1;
	}

	noecho();
	cbreak;
	start_color();
	init_pair(0, COLOR_BLACK, COLOR_BLACK); //黒で塗りつぶし
	init_pair(1, COLOR_BLUE, COLOR_BLUE);	//青で塗りつぶし
	init_pair(2, COLOR_YELLOW, COLOR_YELLOW);	//黄で塗りつぶし
	init_pair(3, COLOR_RED, COLOR_RED);		//赤で塗りつぶし
	init_pair(4, COLOR_WHITE, COLOR_WHITE);	//白で塗りつぶし
	init_pair(5, COLOR_GREEN, COLOR_GREEN);	//緑で塗りつぶし
	init_pair(6, COLOR_WHITE, COLOR_BLACK);	//黒の背景に白
	init_pair(7, COLOR_CYAN, COLOR_CYAN);	//水色で塗りつぶし
	init_pair(8, COLOR_BLACK, COLOR_BLACK); //黒で塗りつぶし
	init_pair(9, COLOR_BLACK, COLOR_BLACK || A_REVERSE || A_BOLD);	//黒の塗りつぶしやけどグレーっぽい

	keypad(stdscr, TRUE);
	erase();

	//Cursesの初期設定終了-------------------------------------------------------------------------------

	int startup = 0;
	int select = 0;
	//矢印
	int arrow[5][100] = {
		{ 1,0,0 },
		{ 1,1,0 },
		{ 1,1,1 },
		{ 1,1,0 },
		{ 1,0,0 },
	};

	int load[5][33] = {
		{ 1,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,1,0,0,0,1,0,1,1,1 },
		{ 1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,1,0,1,1,0,1,0,0 },
		{ 1,0,0,0,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1 },
		{ 1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0 },
		{ 1,1,1,0,0,1,0,0,1,0,1,0,1,1,0,0,0,1,0,0,1,0,1,0,1,0,0,0,1,0,1,1,1 }
	};

	int newgame[5][32] = {
		{ 1,0,0,1,0,1,1,1,0,1,0,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,0,1,0,1,1,1 },
		{ 1,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,1,0,1,1,0,1,0,0 },
		{ 1,0,1,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1 },
		{ 1,0,0,1,0,1,0,0,0,1,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0 },
		{ 1,0,0,1,0,1,1,1,0,1,0,0,0,1,0,0,1,0,0,1,0,1,0,1,0,0,0,1,0,1,1,1 }
	};

	//初期化
	attrset(COLOR_PAIR(4));

	while (startup == 0) {
		erase();
		//LOADGAMEとNEWGAMEの描画
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 33; j++) {
				if (load[i][j] == 1) {
					mvaddstr(i + TATECELL / 2 - 15, j + YOKOCELL / 2 - 15, " ");
				}
			}
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 32; j++) {
				if (newgame[i][j] == 1) {
					mvaddstr(i + TATECELL / 2 + 15, j + YOKOCELL / 2 - 15, " ");
				}
			}
		}
		//矢印の描画
		if (select == 0) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 3; j++) {
					if (arrow[i][j] == 1) {
						mvaddstr(i + TATECELL / 2 - 15, j + YOKOCELL / 2 - 20, " ");
					}
				}
			}
		}
		else if (select == 1) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 3; j++) {
					if (arrow[i][j] == 1) {
						mvaddstr(i + TATECELL / 2 + 15, j + YOKOCELL / 2 - 20, " ");
					}
				}
			}
		}
		refresh();
		if (GetAsyncKeyState(VK_UP)) {
			if (select == 1) {
				select--;
			}
			Sleep(200);
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			if (select == 0) {
				select++;
			}
			Sleep(200);
		}
		if (GetAsyncKeyState(VK_RETURN)) {
			startup = 1;
			Sleep(200);
		}
	}

	start(select);

	while (true) {
		// 画面をクリア
		erase();

		//ステージ選択開始----------------
		while (menuflag == 0) {
			erase();
			drawmenu();
			refresh();

			set_Enemy_status(stageflag);
			set_Megaman_status();

			set_Enemy_place();
			set_Megaman_place();
		}
		//ステージ選択終了----------------

		//スタート画面描画
		drawstart();

		//バトル開始--------------------------------------------
		
		while (menuflag == 1) {
			erase();

			drawbase();
			drawstage(stageflag);	//ステージ描画

			//メガマンが必殺技中でないなら敵は行動
			if (Megaman.specialFlag == 0) {
				Enemy_action();
			}

			//敵が必殺技中でないならメガマンは行動
			if (Current.specialFlag == 0) {
				mega_move();
			}

			//敵が必殺技中なら敵の描画はやめる（必殺技用関数で描画）
			if (Current.specialFlag == 0) {
				draw_enemy(stageflag);
			}

			draw_megaman(Megaman);

			show_status(stageflag);	//それぞれのHPを画面左上に描画

			refresh();

			//敵の死亡判定
			if (Enemy_deth() == true) {

				drop_weapon();	//武器落とす

				draw_clear();	//クリア画面表示
				clearflag[stageflag] = 1;
				refresh();
				menuflag = 0;
				break;
			}

			//メガマンの死亡判定
			if (Megaman_deth() == true) {
				refresh();
				menuflag = 0;
				break;
			}
			
			//キーのEを押すとサブメニューが表示され、メガマンの武器を変更できる
			if (GetAsyncKeyState(0x45)) {
				submenuflag = 1;
				Megaman.colorCondition = drawsubmenu();
			}
			refresh();
		}

		//バトル終了--------------------------------------------

		refresh();

	}
	endwin();

	return 0;
}


//敵のHPを表示
void show_status(int stageNum) {
	//ロックマンの体力描画
	attrset(COLOR_PAIR(5) | A_REVERSE | A_BOLD);
	for (int i = 0; i < Megaman.HP; i++) {
		for (int j = 0; j < 8; j++) {
			mvaddstr(40 - (i + 5), j + 20, " ");
		}
	}
	attrset(COLOR_PAIR(0) | A_REVERSE | A_BOLD);
	for (int i = 0; i < Megaman.HP; i++) {
		for (int j = 2; j < 6; j++) {
			mvaddstr(40 - (i + 5), j + 20, " ");
		}
	}
	for (int i = 35; i < 43; i++) {
		for (int j = -1; j < 9; j++) {
			mvaddstr(i, j + 20, " ");
		}
	}
	for (int j = 0; j < 8; j++) {
		mvaddstr(43, j + 20, " ");
	}
	for (int j = 2; j < 7; j++) {
		mvaddstr(44, j + 20, " ");
	}
	attrset(COLOR_PAIR(1));
	for (int i = -1; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			mvaddstr(i + 40, j + 22, " ");
		}
	}
	attrset(COLOR_PAIR(4));
	mvaddstr(40, 24, " ");
	mvaddstr(40, 25, " ");
	attrset(COLOR_PAIR(7));
	for (int i = 38; i < 42; i++) {
		for (int j = 0; j < 2; j++) {
			mvaddstr(i + 1, (j * 5) + 21, " ");
		}
	}
	for (int i = 21; i < 25; i++) {
		for (int j = 0; j < 2; j++) {
			mvaddstr((j * 5) + 38, i + 1, " ");
		}
	}
	attrset(COLOR_PAIR(0));
	for (int i = 0; i < Megaman.HP; i += 2) {
		for (int j = 0; j < 8; j++) {
			mvaddstr(40 - (i + 5), j + 20, " ");
		}
	}
	//敵の体力描画
	attrset(COLOR_PAIR(3) | A_REVERSE | A_BOLD);
	for (int y = 0; y < Current.HP; y++) {
		for (int x = 0; x < 8; x++) {
			mvaddstr(40 - (y + 5), x + 50, " ");
		}
	}
	attrset(COLOR_PAIR(0) | A_REVERSE | A_BOLD);
	for (int y = 0; y < Current.HP; y++) {
		for (int x = 2; x < 6; x++) {
			mvaddstr(40 - (y + 5), x + 50, " ");
		}
	}
	for (int i = 35; i < 43; i++) {
		for (int j = -1; j < 9; j++) {
			mvaddstr(i, j + 50, " ");
		}
	}
	for (int j = 0; j < 8; j++) {
		mvaddstr(43, j + 50, " ");
	}
	for (int j = 2; j < 7; j++) {
		mvaddstr(44, j + 50, " ");
	}
	attrset(COLOR_PAIR(3));
	for (int i = -1; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			mvaddstr(i + 40, j + 52, " ");
		}
	}
	attrset(COLOR_PAIR(4));
	mvaddstr(40, 54, " ");
	mvaddstr(40, 55, " ");
	attrset(COLOR_PAIR(2));
	for (int i = 38; i < 42; i++) {
		for (int j = 0; j < 2; j++) {
			mvaddstr(i + 1, (j * 5) + 51, " ");
		}
	}
	for (int i = 51; i < 55; i++) {
		for (int j = 0; j < 2; j++) {
			mvaddstr((j * 5) + 38, i + 1, " ");
		}
	}
	attrset(COLOR_PAIR(0));
	for (int y = 0; y < Current.HP; y += 2) {
		for (int x = 0; x < 8; x++) {
			mvaddstr(40 - (y + 5), x + 50, " ");
		}
	}
	//敵とロックマンの体力枠描画
	attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
	for (int i = 0; i < 32; i++) {
		mvaddstr(i + 5, 19, " ");
		mvaddstr(i + 5, 28, " ");
		mvaddstr(i + 5, 49, " ");
		mvaddstr(i + 5, 58, " ");
	}
	for (int i = 0; i < 8; i++) {
		mvaddstr(36, i + 20, " ");
		mvaddstr(5, i + 20, " ");
		mvaddstr(36, i + 50, " ");
		mvaddstr(5, i + 50, " ");
	}
}

//敵の死亡判定用関数
bool Enemy_deth() {
	if (Current.HP <= 0) {
		return true;
	}
	else {
		return false;
	}
}

//メガマンの死亡判定用関数
bool Megaman_deth() {
	if (Megaman.HP <= 0) {
		return true;
	}
	else {
		return false;
	}
}

