
//stage3�̓G�̕`��pcpp

#include "stdafx.h"
#include "draw_enemy.h"

//hub_hound�̕`��p
int draw_hub_hound[23][29] =
{
	{ 0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0 },
	{ 0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0 },
	{ 0,0,1,1,1,1,0,5,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0 },
	{ 0,0,0,0,1,0,1,0,5,1,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
	{ 0,0,1,0,0,0,1,0,1,9,9,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 0,0,0,0,1,1,1,0,0,0,0,9,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,7,1 },
	{ 0,0,0,1,5,5,1,1,1,1,1,0,9,9,9,0,0,0,0,0,0,0,0,9,9,0,1,1,7 },
	{ 1,1,1,1,5,1,1,1,7,1,1,0,9,9,4,9,0,0,0,0,0,9,9,4,9,9,1,7,7 },
	{ 1,1,1,1,1,1,1,1,1,7,7,7,0,9,4,4,9,9,9,9,9,4,4,4,9,9,1,1,7 },
	{ 0,0,0,0,0,1,1,1,1,1,1,7,0,9,2,2,2,2,2,2,2,2,2,4,9,9,1,7,0 },
	{ 0,0,3,0,1,1,1,7,1,1,1,0,9,4,2,0,0,0,2,0,0,0,2,4,9,9,1,7,0 },
	{ 0,0,0,1,1,0,0,0,1,7,7,0,9,4,2,0,0,0,2,0,0,0,2,9,9,9,7,7,0 },
	{ 0,0,1,1,0,0,0,0,0,0,0,9,9,4,4,2,0,2,4,2,0,2,9,9,0,9,9,0,0 },
	{ 0,0,0,0,0,0,0,0,9,9,9,9,9,9,9,4,2,4,4,4,2,9,0,0,7,0,9,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,9,9,4,4,9,9,0,1,1,7,0,9,0,0 },
	{ 0,0,0,0,0,0,0,0,0,1,0,1,1,7,0,0,0,9,9,0,1,0,1,1,1,7,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,1,0,1,7,0,0,0,0,0,0,1,0,1,1,7,1,7,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,1,1,7,0,0,0,0,0,0,1,7,0,1,1,7,1,7,0 },
	{ 0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,1,7,0,0,0,1,1,7,0 },
	{ 0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,1,0 },
	{ 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0 }
};

//hub_hound�̈ړ����̕`��p
int draw_hub_hound_move[23][30] =
{
	{ 0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0 },
	{ 0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0 },
	{ 0,0,1,1,1,1,0,5,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0 },
	{ 0,0,0,0,1,0,1,0,5,1,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
	{ 0,0,1,0,0,0,1,0,1,9,9,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0 },
	{ 0,0,0,0,1,1,1,0,0,0,0,9,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,7,1,0 },
	{ 0,0,0,1,5,5,1,1,1,1,1,0,9,9,9,0,0,0,0,0,0,0,0,9,9,0,1,1,7,0 },
	{ 1,1,1,1,5,1,1,1,7,1,1,0,9,9,4,9,0,0,0,0,0,9,9,4,9,9,1,7,7,0 },
	{ 1,1,1,1,1,1,1,1,1,7,7,7,0,9,4,4,9,9,9,9,9,4,4,4,9,9,1,1,7,0 },
	{ 0,0,0,0,0,1,1,1,1,1,1,7,0,9,2,2,2,2,2,2,2,2,2,4,9,9,1,7,0,0 },
	{ 0,0,3,0,1,1,1,7,1,1,1,0,9,4,2,0,0,0,2,0,0,0,2,4,9,9,1,7,0,0 },
	{ 0,0,0,1,1,0,0,0,1,7,7,0,9,4,2,0,0,0,2,0,0,0,2,9,9,9,7,7,0,0 },
	{ 0,0,1,1,0,0,0,0,0,0,0,9,9,4,4,2,0,2,4,2,0,2,9,9,0,9,9,0,0,0 },
	{ 0,0,0,0,0,0,0,0,9,9,9,9,9,9,9,4,2,4,4,4,2,9,0,0,7,0,9,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,9,9,4,4,9,9,0,1,1,7,0,9,0,0,0 },
	{ 0,0,0,0,1,1,1,1,1,0,0,1,1,1,0,0,0,9,9,0,1,0,1,1,1,7,0,0,0,0 },
	{ 0,1,0,0,0,0,0,1,0,1,1,7,1,7,0,0,0,0,0,0,1,0,1,1,7,1,7,0,0,0 },
	{ 1,0,1,1,1,1,1,0,7,1,7,7,7,7,0,0,0,0,0,0,0,1,0,1,1,7,1,7,0,0 },
	{ 1,0,1,0,0,0,1,7,1,7,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,7,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,7,0,0,7,1,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1 },
};

//hub_hound�̍U�����̕`��p
int draw_hub_hound_atk1[25][48] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,8,8,0,0,0,0,7,8,8,8,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,8,4,8,0,7,1,7,8,4,4,8,0,0,1,8,8,4,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,7,0,0,0,0,8,4,4,1,7,1,8,8,4,8,8,7,7,1,8,4,4,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,8,8,7,1,0,7,7,8,4,8,7,1,7,1,8,4,4,8,1,1,7,7,8,4,8,8,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,8,8,4,8,1,7,7,8,4,4,8,7,1,1,1,8,4,4,8,1,1,7,1,8,4,8,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,8,4,4,8,7,7,7,8,4,4,8,7,1,1,1,8,4,8,8,1,1,1,1,8,4,8,1,1,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,7,8,4,4,8,7,1,1,8,4,4,8,1,1,1,1,8,4,8,1,1,1,1,1,8,4,8,7,1,1,8,8,8,0,0,0,0,8,8,8,0,0,0,0,0,0,0 },
	{ 7,7,8,4,4,8,7,1,1,8,4,4,8,1,1,1,1,8,4,8,1,1,1,1,7,8,4,8,7,1,7,8,4,8,1,0,0,8,8,4,8,0,0,0,0,0,0,0 },
	{ 1,1,8,8,4,8,7,1,1,8,4,4,8,1,1,1,1,8,4,8,1,7,7,1,7,8,4,8,7,1,7,8,4,8,7,1,1,8,4,4,8,1,7,1,0,0,0,0 },
	{ 1,1,1,8,4,8,7,1,1,8,8,4,8,1,1,1,1,8,4,8,8,7,7,1,7,8,4,8,7,1,7,8,4,8,7,7,1,8,8,4,8,1,7,1,7,1,1,1 },
	{ 1,1,1,8,4,8,8,1,1,7,8,4,8,1,1,1,1,8,4,4,8,7,7,1,7,8,4,8,8,1,7,8,4,8,7,7,1,7,8,4,8,1,1,1,7,7,1,1 },
	{ 1,1,1,8,8,4,8,1,1,7,8,4,8,8,1,1,1,8,4,4,8,7,7,1,7,8,4,4,8,1,7,8,4,4,8,1,1,7,8,4,8,8,7,7,1,0,0,0 },
	{ 1,1,1,1,8,4,8,8,1,7,8,8,4,8,1,1,1,8,8,4,8,7,7,1,7,8,4,4,8,1,7,8,8,4,8,1,1,7,8,4,4,8,0,0,0,0,0,0 },
	{ 1,1,1,7,8,4,4,8,1,7,1,8,4,8,8,1,1,7,8,4,8,8,7,1,7,8,4,4,8,1,7,1,8,4,8,1,1,7,7,8,8,8,0,0,0,0,0,0 },
	{ 1,1,1,7,8,4,4,8,7,1,1,8,4,4,8,1,1,7,8,4,4,8,7,1,7,8,4,4,8,1,7,1,8,8,4,8,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,1,1,7,8,8,4,8,8,1,1,8,8,4,8,8,1,7,8,8,4,4,8,1,7,8,8,4,8,1,7,1,0,0,8,8,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,1,1,7,7,8,4,4,8,1,1,1,8,4,4,8,1,7,1,8,4,4,8,1,7,1,8,4,8,1,7,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,7,7,8,8,4,8,1,1,7,8,8,4,8,4,4,4,8,8,4,8,1,1,1,8,4,8,1,7,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,0,1,8,4,8,8,1,7,7,8,4,8,8,1,1,7,8,4,8,1,1,0,8,8,4,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,8,4,4,8,7,7,7,8,4,4,8,1,1,7,8,8,4,8,8,0,0,8,4,4,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,8,8,8,8,7,7,7,1,8,4,4,8,1,7,7,8,4,8,0,0,0,1,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,1,0,7,7,7,1,8,8,8,7,7,7,7,8,8,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,7,7,1,0,0,0,0,0,7,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
};

//hub_hound�̕`��
void hub_hound(int hbx, int hby) {
	for (int y = 22; y >= 0; y--) {
		for (int x = 0; x < 29; x++) {
			if (draw_hub_hound[y][x] != 0) {
				if (draw_hub_hound[y][x] == 8) {
					attrset(COLOR_PAIR(draw_hub_hound[y][x]));
				}
				else {
					attrset(COLOR_PAIR(draw_hub_hound[y][x]) | A_REVERSE | A_BOLD);
				}
				mvaddstr(hby - (22 - y), hbx + x, " ");
			}
		}
	}
}

void reverse_hub_hound(int hbx, int hby) {
	for (int y = 22; y >= 0; y--) {
		for (int x = 28; x >= 0; x--) {
			if (draw_hub_hound[y][x] != 0) {
				if (draw_hub_hound[y][x] == 8) {
					attrset(COLOR_PAIR(draw_hub_hound[y][x]));
				}
				else {
					attrset(COLOR_PAIR(draw_hub_hound[y][x]) | A_REVERSE | A_BOLD);
				}
				mvaddstr(hby - (22 - y), hbx + (28 - x), " ");
			}
		}
	}
}

//hub_hound�̈ړ����̕`��
void hub_hound_move(int hbx, int hby) {
	for (int y = 22; y >= 0; y--) {
		for (int x = 0; x < 30; x++) {
			if (draw_hub_hound_move[y][x] != 0) {
				if (draw_hub_hound_move[y][x] == 8) {
					attrset(COLOR_PAIR(draw_hub_hound_move[y][x]));
				}
				else {
					attrset(COLOR_PAIR(draw_hub_hound_move[y][x]) | A_REVERSE | A_BOLD);
				}
				mvaddstr(hby - (22 - y), hbx + x, " ");
			}
		}
	}
}

void reverse_hub_hound_move(int hbx, int hby) {
	for (int y = 22; y >= 0; y--) {
		for (int x = 29; x >= 0; x--) {
			if (draw_hub_hound_move[y][x] != 0) {
				if (draw_hub_hound_move[y][x] == 8) {
					attrset(COLOR_PAIR(draw_hub_hound_move[y][x]));
				}
				else {
					attrset(COLOR_PAIR(draw_hub_hound_move[y][x]) | A_REVERSE | A_BOLD);
				}
				mvaddstr(hby - (22 - y), hbx + (29 - x), " ");
			}
		}
	}
}

//hub_hound�̍U���̕`��p
void hub_hound_atk1(int hbx, int hby) {
	for (int y = 24; y >= 0; y--) {
		for (int x = 0; x < 48; x++) {
			if (draw_hub_hound_atk1[y][x] != 0) {
				if (draw_hub_hound_atk1[y][x] == 8) {
					attrset(COLOR_PAIR(draw_hub_hound_atk1[y][x]));
				}
				else {
					attrset(COLOR_PAIR(draw_hub_hound_atk1[y][x]) | A_REVERSE | A_BOLD);
				}
				mvaddstr(hby - (24 - y), hbx + x, " ");
			}
		}
	}
}

void reverse_hub_hound_atk1(int hbx, int hby) {
	for (int y = 24; y >= 0; y--) {
		for (int x = 47; x >= 0; x--) {
			if (draw_hub_hound_atk1[y][x] != 0) {
				if (draw_hub_hound_atk1[y][x] == 8) {
					attrset(COLOR_PAIR(draw_hub_hound_atk1[y][x]));
				}
				else {
					attrset(COLOR_PAIR(draw_hub_hound_atk1[y][x]) | A_REVERSE | A_BOLD);
				}
				mvaddstr(hby - (24 - y), hbx + (47 - x), " ");
			}
		}
	}
}

//hub_hound�̕K�E�Z�̕`��
void hub_hound_sp(int hbx, int hby) {
	for (int x = 0; x < 48; x++) {
		for (int y = 24; y >= 0; y--) {
			if (draw_hub_hound_atk1[y][x] != 0) {
				if (draw_hub_hound_atk1[y][x] == 8) {
					attrset(COLOR_PAIR(draw_hub_hound_atk1[y][x]));
				}
				else {
					attrset(COLOR_PAIR(draw_hub_hound_atk1[y][x]) | A_REVERSE | A_BOLD);
				}
				mvaddstr(hby - x, hbx + y, " ");
			}
		}
	}
}