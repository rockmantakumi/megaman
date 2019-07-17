// Fin_kadai_mega.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
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


void show_status(int stageNum);	//�X�e�[�^�X������
bool Enemy_deth();		//�G�̎��S����
bool Megaman_deth();	//���K�}���̎��S�t���O

int main()
{

	//��������Curses�̏����ݒ�---------------------------------------------------------------------------
	init();

	if (initscr() == NULL) {
		return 1;
	}

	noecho();
	cbreak;
	start_color();
	init_pair(0, COLOR_BLACK, COLOR_BLACK); //���œh��Ԃ�
	init_pair(1, COLOR_BLUE, COLOR_BLUE);	//�œh��Ԃ�
	init_pair(2, COLOR_YELLOW, COLOR_YELLOW);	//���œh��Ԃ�
	init_pair(3, COLOR_RED, COLOR_RED);		//�Ԃœh��Ԃ�
	init_pair(4, COLOR_WHITE, COLOR_WHITE);	//���œh��Ԃ�
	init_pair(5, COLOR_GREEN, COLOR_GREEN);	//�΂œh��Ԃ�
	init_pair(6, COLOR_WHITE, COLOR_BLACK);	//���̔w�i�ɔ�
	init_pair(7, COLOR_CYAN, COLOR_CYAN);	//���F�œh��Ԃ�
	init_pair(8, COLOR_BLACK, COLOR_BLACK); //���œh��Ԃ�
	init_pair(9, COLOR_BLACK, COLOR_BLACK || A_REVERSE || A_BOLD);	//���̓h��Ԃ��₯�ǃO���[���ۂ�

	keypad(stdscr, TRUE);
	erase();

	//Curses�̏����ݒ�I��-------------------------------------------------------------------------------

	int startup = 0;
	int select = 0;
	//���
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

	//������
	attrset(COLOR_PAIR(4));

	while (startup == 0) {
		erase();
		//LOADGAME��NEWGAME�̕`��
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
		//���̕`��
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
		// ��ʂ��N���A
		erase();

		//�X�e�[�W�I���J�n----------------
		while (menuflag == 0) {
			erase();
			drawmenu();
			refresh();

			set_Enemy_status(stageflag);
			set_Megaman_status();

			set_Enemy_place();
			set_Megaman_place();
		}
		//�X�e�[�W�I���I��----------------

		//�X�^�[�g��ʕ`��
		drawstart();

		//�o�g���J�n--------------------------------------------
		
		while (menuflag == 1) {
			erase();

			drawbase();
			drawstage(stageflag);	//�X�e�[�W�`��

			//���K�}�����K�E�Z���łȂ��Ȃ�G�͍s��
			if (Megaman.specialFlag == 0) {
				Enemy_action();
			}

			//�G���K�E�Z���łȂ��Ȃ烁�K�}���͍s��
			if (Current.specialFlag == 0) {
				mega_move();
			}

			//�G���K�E�Z���Ȃ�G�̕`��͂�߂�i�K�E�Z�p�֐��ŕ`��j
			if (Current.specialFlag == 0) {
				draw_enemy(stageflag);
			}

			draw_megaman(Megaman);

			show_status(stageflag);	//���ꂼ���HP����ʍ���ɕ`��

			refresh();

			//�G�̎��S����
			if (Enemy_deth() == true) {

				drop_weapon();	//���헎�Ƃ�

				draw_clear();	//�N���A��ʕ\��
				clearflag[stageflag] = 1;
				refresh();
				menuflag = 0;
				break;
			}

			//���K�}���̎��S����
			if (Megaman_deth() == true) {
				refresh();
				menuflag = 0;
				break;
			}
			
			//�L�[��E�������ƃT�u���j���[���\������A���K�}���̕����ύX�ł���
			if (GetAsyncKeyState(0x45)) {
				submenuflag = 1;
				Megaman.colorCondition = drawsubmenu();
			}
			refresh();
		}

		//�o�g���I��--------------------------------------------

		refresh();

	}
	endwin();

	return 0;
}


//�G��HP��\��
void show_status(int stageNum) {
	//���b�N�}���̗͕̑`��
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
	//�G�̗͕̑`��
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
	//�G�ƃ��b�N�}���̗̑͘g�`��
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

//�G�̎��S����p�֐�
bool Enemy_deth() {
	if (Current.HP <= 0) {
		return true;
	}
	else {
		return false;
	}
}

//���K�}���̎��S����p�֐�
bool Megaman_deth() {
	if (Megaman.HP <= 0) {
		return true;
	}
	else {
		return false;
	}
}

