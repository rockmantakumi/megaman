
#include "stdafx.h"
#include "Stage.h"
#include "draw_enemy.h"
#include "draw_mega.h"
#include "Mega_action.h"

#define BUFFSIZE 255

char name[BUFFSIZE];				//file��
char currentDirectory[BUFFSIZE];	//���݂̃f�B���N�g��
char directory[BUFFSIZE];			//�����̖��O���܂߂��f�B���N�g��
int tatewaku = 40;					//���j���[��ʂ̘g�̏c��
int yokowaku = 90;					//���j���[��ʂ̘g�̉���
int submenuflag = 0;				//�퓬���̃T�u���j���[�p�t���O
int menuflag = 0;					//���C�����j���[�p�t���O
int vert = YOKOCELL / 2 - yokowaku / 2;	//x���W�ێ��p�ϐ�
int hori = TATECELL / 2 - tatewaku / 2; //y���W�ێ��p�ϐ�
int stageflag = 5;					//�I������Ă���X�e�[�W
int startflag = 0;					//�N������̉�ʕ\���p�t���O
int clearflag[9] = { 0,0,0,0,0,0,0,0,0 };	//�N���A����Ă���X�e�[�W�̃t���O
int weapon[9] = { 100,100,100,100,100,100,100,100,100 };	//���ꕐ��̃G�l���M�[
int num = 0, rnd = 0;				//�J�E���g�p�ėp�ϐ�
int counter = 0;					//
int counter2 = 0;					//


									//���݂̃f�B���N�g���Ƃ��Ă���
void getCurrentDirectory(char* currentDirectory) {
	GetCurrentDirectory(BUFFSIZE, currentDirectory);
}

//ini�t�@�C���Ăяo��
void fileread() {

	strcpy_s(directory, currentDirectory);
	strcat_s(directory, "\\data.ini");
	GetPrivateProfileString("data", "key", "baka", name, BUFFSIZE, directory);
}

//��ʃT�C�Y�╶���T�C�Y�̐ݒ�
void init() {
	//---------------------------------�`��ݒ蕔��--------------------------------
	//�����T�C�Y�ύX
	const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX info = { sizeof info };
	info.dwFontSize.X = 3;
	info.dwFontSize.Y = 6;
	SetCurrentConsoleFontEx(hConsole, 0, &info);

	//�E�B���h�E�T�C�Y�ύX
	BOOL bRtn;
	HANDLE hWrite;
	SMALL_RECT rctWindowRect = { 0,0,YOKO,TATE };
	COORD dwCoord = { YOKO,TATE };
	hWrite = GetStdHandle(STD_OUTPUT_HANDLE);
	bRtn = SetConsoleScreenBufferSize(hWrite, dwCoord);
	bRtn = SetConsoleWindowInfo(hWrite, TRUE, &rctWindowRect);

	//---------------------------------�`��ݒ�I��--------------------------------
}

//�N������̉�ʂ�LOAD GAME���I�����ꂽ��t�@�C���ǂݍ��݂����ăZ�[�u�f�[�^����
void start(int select) {
	if (select == 0) {
		//�f�B���N�g������
		getCurrentDirectory(currentDirectory);
		//�t�@�C���ǂݍ���
		fileread();
		FILE* fp;
		errno_t error;
		//�f�B���N�g�����킹��
		char directory[BUFFSIZE];
		char str[BUFFSIZE];
		strcpy_s(directory, currentDirectory);
		strcat_s(directory, "\\");
		strcat_s(directory, name);
		//�����ŃI�[�v��
		error = fopen_s(&fp, directory, "r");
		if (error != 0) {
			fprintf_s(stderr, "%s", directory);
		}
		else {

			int i = 0;
			int flag = 0;
			while (fgets(str, BUFFSIZE, fp) != NULL) {
				int j = 0;
				char* p1, *p2; // char�^�|�C���^���[�N
							   //== �ϊ����̕����� ==
				char delim[] = ",";//�f���~�^�i�����n����j�����ł̓J���}
				char* ctx;
				//== �ϊ������i�X�y�[�X��؂�ŕ�������������̐��l�ϊ��j==
				p1 = strtok_s(str, delim, &ctx); // 1�ڂ̕���������擾

				while (p1 != NULL) {
					clearflag[i] = atoi(p1);
					p1 = strtok_s(NULL, delim, &ctx);
					i++;
				}
			}
			fclose(fp);
		}
	}
}

//���C�����j���[�̕`��
void drawmenu() {
	int coming[5][24] = {
		{ 0,1,0,0,0,1,0,0,1,0,0,0,1,0,1,0,1,0,0,1,0,0,1,1 },
		{ 1,0,1,0,1,0,1,0,1,1,0,1,1,0,1,0,1,1,0,1,0,1,0,0 },
		{ 1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,1,1 },
		{ 1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,1,0,1,0,1 },
		{ 0,1,0,0,0,1,0,0,1,0,0,0,1,0,1,0,1,0,0,1,0,0,1,0 }
	};
	int soon[5][16] = {
		{ 0,1,1,0,0,1,0,0,0,1,0,0,1,0,0,1 },
		{ 1,0,0,0,1,0,1,0,1,0,1,0,1,1,0,1 },
		{ 0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,1 },
		{ 0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1 },
		{ 1,1,0,0,0,1,0,0,0,1,0,0,1,0,0,1 }
	};
	int saved[5][19] = {
		{ 0,1,1,0,0,1,0,0,1,0,1,0,1,1,1,0,1,1,0 },
		{ 1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1 },
		{ 0,1,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1 },
		{ 0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1 },
		{ 1,1,0,0,1,0,1,0,0,1,0,0,1,1,1,0,1,1,0 }
	};
	//���g���`��
	int num1 = (YOKOCELL / 2) - (2 * yokowaku);
	int num2 = (TATECELL / 2) - (tatewaku * 3 / 4 + tatewaku);
	for (int m = 0; m < 3; m++) {
		num1 = (YOKOCELL / 2) - (2 * yokowaku);
		for (int n = 0; n < 3; n++) {
			attrset(COLOR_PAIR(1));
			for (int i = num2; i <= num2 + tatewaku + 2; i++) {
				mvaddstr(i, num1, " ");
				mvaddstr(i, num1 + 2, " ");
				mvaddstr(i, num1 + yokowaku, " ");
				mvaddstr(i, num1 + yokowaku + 2, " ");
			}

			for (int i = num1; i <= num1 + yokowaku + 2; i++) {
				mvaddstr(num2 + 2, i, " ");
				mvaddstr(num2, i, " ");
				mvaddstr(num2 + tatewaku + 2, i, " ");
				mvaddstr(num2 + tatewaku, i, " ");
			}
			num1 += yokowaku / 2 + yokowaku;
		}
		num2 += 10 + tatewaku;
	}
	//�g���`�悵�ė]�v�ȂƂ��������Ă���
	num2 = (TATECELL / 2) - (tatewaku * 3 / 4 + tatewaku);
	for (int m = 0; m < 3; m++) {
		num1 = (YOKOCELL / 2) - (2 * yokowaku);
		for (int n = 0; n < 3; n++) {
			attrset(COLOR_PAIR(0));
			for (int i = num2 + 1; i <= num2 + tatewaku + 1; i++) {
				mvaddstr(i, num1 + 1, " ");
				mvaddstr(i, num1 + yokowaku + 1, " ");
			}
			for (int i = num1 + 1; i <= num1 + yokowaku + 1; i++) {
				mvaddstr(num2 + 1, i, " ");
				mvaddstr(num2 + 1 + tatewaku, i, " ");
			}
			num1 += yokowaku / 2 + yokowaku;
		}
		num2 += 10 + tatewaku;
	}
	//�L�[����󂯕t���ăX�e�[�W�I��
	if (GetAsyncKeyState(VK_UP)) {
		if (hori >= (TATECELL / 2) - tatewaku) {
			hori -= (10 + tatewaku);
			stageflag -= 3;
		}
		Sleep(200);
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		if (hori <= (TATECELL / 2)) {
			hori += (10 + tatewaku);
			stageflag += 3;
		}
		Sleep(200);
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		if (vert >= YOKOCELL / 2 - yokowaku) {
			vert -= (yokowaku / 2 + yokowaku);
			stageflag -= 1;
		}
		Sleep(200);
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		if (vert <= YOKOCELL / 2) {
			vert += (yokowaku / 2 + yokowaku);
			stageflag += 1;
		}
		Sleep(200);
	}
	//�G���^�[�L�[�őI��
	if (clearflag[stageflag] == 0) {
		if (stageflag == 1 || stageflag == 2 || stageflag == 3 || stageflag == 6) {
			if (GetAsyncKeyState(VK_RETURN)) {
				menuflag = -1;
			}
		}
	}
	//���j���[�ł̃��K�}���̕`��
	if (stageflag == 5) {
		if (counter < 2000) {
			megaman(YOKOCELL / 2 - 8, TATECELL / 2 + 15, 0);
		}
		else if (counter < 4000) {
			mega_move(YOKOCELL / 2 - 8, TATECELL / 2 + 15, 0);
		}
		else {
			counter = 0;
		}
		counter++;
	}
	else if (stageflag == 1 || stageflag == 4 || stageflag == 7) {
		reverse_megaman(YOKOCELL / 2 - 8, TATECELL / 2 + 15, 0);
	}
	else if (stageflag == 3 || stageflag == 6 || stageflag == 9) {
		megaman(YOKOCELL / 2 - 8, TATECELL / 2 + 15, 0);
	}
	else {
		megaman(YOKOCELL / 2 - 8, TATECELL / 2 + 15, 0);
	}
	//���j���[�œG�̕`��
	//elect�̕`��
	if (clearflag[1] == 0) {
		if (stageflag == 1) {
			if (counter < 2000) {
				elect(YOKOCELL / 2 - (2 * yokowaku) + yokowaku / 2 - 10, TATECELL / 2 - (tatewaku * 3 / 4 + 5));
			}
			else if (counter < 4000) {
				elect_spmove1(YOKOCELL / 2 - (2 * yokowaku) + yokowaku / 2 - 10, TATECELL / 2 - (tatewaku * 3 / 4 + 5));
			}
			else {
				counter = 0;
			}
			counter++;
		}
		else {
			elect(YOKOCELL / 2 - (2 * yokowaku) + yokowaku / 2 - 10, TATECELL / 2 - (tatewaku * 3 / 4 + 5));
		}
	}


	//heat�̕`��
	if (clearflag[2] == 0) {
		if (stageflag == 2) {
			if (counter < 2000) {
				heat_half(YOKOCELL / 2 - (yokowaku / 2) + 43, TATECELL / 2 - (tatewaku / 2) - tatewaku / 2 + 20);
			}
			else if (counter < 4000) {
				heat_atkmove_half(YOKOCELL / 2 - (yokowaku / 2) + 30, TATECELL / 2 - (tatewaku / 2) - tatewaku / 2 + 20);
			}
			else {
				counter = 0;
			}
			counter++;
		}
		else {
			heat_half(YOKOCELL / 2 - (yokowaku / 2) + 43, TATECELL / 2 - (tatewaku / 2) - tatewaku / 2 + 20);
		}
	}
	//heat�̕`��
	if (clearflag[3] == 0) {
		if (stageflag == 3) {
			if (counter < 2000) {
				hub_hound(YOKOCELL / 2 + yokowaku + (yokowaku / 2) - 16, TATECELL / 2 - (tatewaku / 2) - tatewaku / 2 + 3);
			}
			else if (counter < 4000) {
				hub_hound_atk1(YOKOCELL / 2 + yokowaku + (yokowaku / 2) - 21, TATECELL / 2 - (tatewaku / 2) - tatewaku / 2 + 3);
			}
			else {
				counter = 0;
			}
			counter++;
		}
		else {
			hub_hound(YOKOCELL / 2 + yokowaku + (yokowaku / 2) - 16, TATECELL / 2 - (tatewaku / 2) - tatewaku / 2 + 3);
		}
	}
	/*
	//splash�̕`��
	if (clearflag[4] == 0) {
	if (stageflag == 4) {
	if (counter < 2000) {
	water(YOKOCELL / 2 - (2 * yokowaku)+yokowaku / 2 - 10, TATECELL / 2 + tatewaku / 2 - 5);
	}
	else if (counter < 4000) {
	//water_atkmove(YOKOCELL / 2 - (2 * yokowaku)+yokowaku / 2 - 10, TATECELL / 2 + tatewaku / 2 - 5);
	}
	else {
	counter = 0;
	}
	counter++;
	}
	else {
	water(YOKOCELL / 2 - (2 * yokowaku)+yokowaku / 2 - 10, TATECELL / 2 + tatewaku / 2 - 5);
	}
	}
	*/
	//icedemon�̕`��
	if (clearflag[6] == 0) {
		if (stageflag == 6) {
			if (counter < 2000) {
				ice_demon(YOKOCELL / 2 + (yokowaku)+yokowaku / 2 - 10, TATECELL / 2 + tatewaku / 2 - 5);
			}
			else if (counter < 4000) {
				ice_demon_atkmove(YOKOCELL / 2 + (yokowaku)+yokowaku / 2 - 10, TATECELL / 2 + tatewaku / 2 - 5);
			}
			else {
				counter = 0;
			}
			counter++;
		}
		else {
			ice_demon(YOKOCELL / 2 + (yokowaku)+yokowaku / 2 - 10, TATECELL / 2 + tatewaku / 2 - 5);
		}
	}
	//--------------------------------------Coming soon--------------------------------------
	attrset(COLOR_PAIR(4));
	for (int i = YOKOCELL / 2 - (yokowaku * 2) + 10; i < YOKOCELL / 2 - (yokowaku)-10; i++) {
		for (int j = (TATECELL / 2) - 17; j < (TATECELL / 2) + 9 - 17; j += 8) {
			mvaddstr(j + 14, i + 1, " ");
		}
	}
	/*
	for (int i = YOKOCELL / 2 + yokowaku + 10; i < YOKOCELL / 2 + yokowaku + yokowaku - 10; i++) {
	for (int j = (TATECELL / 2) - 17; j < (TATECELL / 2) + 9 - 17; j += 8) {
	mvaddstr(j + 14, i + 1, " ");
	}
	}
	*/
	for (int i = YOKOCELL / 2 - (yokowaku * 2) + 10; i < YOKOCELL / 2 - (yokowaku)-10; i++) {
		for (int j = (TATECELL / 2) + tatewaku - 7; j < (TATECELL / 2) + tatewaku - 7 + 9; j += 8) {
			mvaddstr(j + 14, i + 1, " ");
		}
	}
	for (int i = YOKOCELL / 2 + 10 - yokowaku / 2; i < YOKOCELL / 2 + (yokowaku / 2) - 10; i++) {
		for (int j = (TATECELL / 2) + tatewaku - 7; j < (TATECELL / 2) + tatewaku - 7 + 9; j += 8) {
			mvaddstr(j + 14, i + 1, " ");
		}
	}
	for (int i = YOKOCELL / 2 + yokowaku + 10; i < YOKOCELL / 2 + yokowaku + yokowaku - 10; i++) {
		for (int j = (TATECELL / 2) + tatewaku - 7; j < (TATECELL / 2) + tatewaku - 7 + 9; j += 8) {
			mvaddstr(j + 14, i + 1, " ");
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 24; j++) {
			if (coming[i][j] == 1) {
				mvaddstr((TATECELL / 2) + i - 1, YOKOCELL / 2 - (yokowaku * 2) + 18 + j, " ");
			}

		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 16; j++) {
			if (soon[i][j] == 1) {
				mvaddstr((TATECELL / 2) + i - 1, YOKOCELL / 2 - (yokowaku * 2) + 55 + j, " ");

			}
		}
	}
	/*
	for (int i = 0; i < 5; i++) {
	for (int j = 0; j < 24; j++) {
	if (coming[i][j] == 1) {
	mvaddstr((TATECELL / 2) + i - 1, YOKOCELL / 2 + yokowaku + 18 + j, " ");
	}

	}
	}
	for (int i = 0; i < 5; i++) {
	for (int j = 0; j < 16; j++) {
	if (soon[i][j] == 1) {
	mvaddstr((TATECELL / 2) + i - 1, YOKOCELL / 2 + yokowaku + 55 + j, " ");

	}
	}
	}
	*/
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 24; j++) {
			if (coming[i][j] == 1) {
				mvaddstr((TATECELL / 2) + tatewaku + 9 + i, YOKOCELL / 2 - (yokowaku * 2) + 18 + j, " ");
			}

		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 16; j++) {
			if (soon[i][j] == 1) {
				mvaddstr((TATECELL / 2) + tatewaku + 9 + i, YOKOCELL / 2 - (yokowaku * 2) + 55 + j, " ");

			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 24; j++) {
			if (coming[i][j] == 1) {
				mvaddstr((TATECELL / 2) + tatewaku + 9 + i, YOKOCELL / 2 + 18 - yokowaku / 2 + j, " ");
			}

		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 16; j++) {
			if (soon[i][j] == 1) {
				mvaddstr((TATECELL / 2) + tatewaku + 9 + i, YOKOCELL / 2 + 55 - yokowaku / 2 + j, " ");

			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 24; j++) {
			if (coming[i][j] == 1) {
				mvaddstr((TATECELL / 2) + tatewaku + 9 + i, YOKOCELL / 2 + yokowaku + 18 + j, " ");
			}

		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 16; j++) {
			if (soon[i][j] == 1) {
				mvaddstr((TATECELL / 2) + tatewaku + 9 + i, YOKOCELL / 2 + yokowaku + 55 + j, " ");

			}
		}
	}
	//--------------------------------------Coming soon--------------------------------------

	attrset(COLOR_PAIR(4));
	//���ݑI�����Ă�g���`��
	if (counter2 < 200) {
		attrset(COLOR_PAIR(4));
	}
	else if (counter2 < 400) {
		attrset(COLOR_PAIR(0));
	}
	else {
		counter2 = 0;
	}
	counter2++;
	//����
	for (int i = vert + 1; i < vert + yokowaku + 2; i++) {
		mvaddstr(hori + 1, i, " ");
		mvaddstr(hori + tatewaku + 1, i, " ");
	}
	//�c��
	for (int i = hori + 1; i < hori + tatewaku + 1; i++) {
		mvaddstr(i, vert + 1, " ");
		mvaddstr(i, vert + yokowaku + 1, " ");
	}

	//S�����ꂽ��Z�[�u�f�[�^��csv�ɏ����o����
	if (GetAsyncKeyState(0x53)) {
		filewrite();
		//���b�N�}���f���Ă�Ƃ����^�����ɂ���
		attrset(COLOR_PAIR(0));
		for (int i = 0; i <= tatewaku; i++) {
			for (int j = 0; j <= yokowaku; j++) {
				mvaddstr(TATECELL / 2 + i - tatewaku / 2 + 1, YOKOCELL / 2 + j - yokowaku / 2 + 1, " ");
			}
		}
		//SAVED��\��
		attrset(COLOR_PAIR(4));
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 19; j++) {
				if (saved[i][j] == 1) {
					mvaddstr(TATECELL / 2 + i, YOKOCELL / 2 + j - 8, " ");
				}
			}
		}
		refresh();
		Sleep(1000);
	}
}

//�X�e�[�W�I�����Ďn�܂�Ƃ���̕`��
void drawstart() {
	int start[5][18] = {
		{ 0,1,1,0,1,1,1,0,1,0,0,1,1,0,0,1,1,1 },
		{ 1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0 },
		{ 0,1,0,0,0,1,0,1,1,1,0,1,1,0,0,0,1,0 },
		{ 0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0 },
		{ 1,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0 }
	};
	int stage[5][18] = {
		{ 0,1,1,0,1,1,1,0,1,0,0,0,1,1,0,1,1,1 },
		{ 1,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,0 },
		{ 0,1,0,0,0,1,0,1,1,1,0,1,1,1,0,1,1,1 },
		{ 0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0 },
		{ 1,1,0,0,0,1,0,1,0,1,0,0,1,0,0,1,1,1 }
	};
	int arrow[5][3] = {
		{ 1,0,0 },
		{ 1,1,0 },
		{ 1,1,1 },
		{ 1,1,0 },
		{ 1,0,0 },
	};

	int name_stage[9][5][34] = {
		{},
		{//stageflag = 1
			{ 1,1,1,0,1,0,0,0,1,1,1,0,0,1,0,0,1,1,1,0,1,1,0,0,0,1,0 },
			{ 1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,1,0,1 },
			{ 1,1,1,0,1,0,0,0,1,1,1,0,1,0,0,0,0,1,0,0,1,1,0,0,1,0,1 },
			{ 1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,1,0,1 },
			{ 1,1,1,0,1,1,1,0,1,1,1,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0 }
		},
		{//stageflag = 2
			{ 1,0,1,0,1,1,1,0,0,1,0,0,1,1,1 },
			{ 1,0,1,0,1,0,0,0,1,0,1,0,0,1,0 },
			{ 1,1,1,0,1,1,1,0,1,1,1,0,0,1,0 },
			{ 1,0,1,0,1,0,0,0,1,0,1,0,0,1,0 },
			{ 1,0,1,0,1,1,1,0,1,0,1,0,0,1,0 }
		},
		{//stageflag = 3},
			{ 1,0,1,0,1,0,1,0,1,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,1,0,0,1,0,1,1,0 },
			{ 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1 },
			{ 1,1,1,0,1,0,1,0,1,1,0,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1 },
			{ 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1 },
			{ 1,0,1,0,0,1,0,0,1,1,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,1,1,0 }
		},
		{//stageflag = 4
			{ 0,1,1,0,1,1,0,0,1,0,0,0,0,1,0,0,0,1,1,0,1,0,1 },
			{ 1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1 },
			{ 0,1,0,0,1,1,0,0,1,0,0,0,1,1,1,0,0,1,0,0,1,1,1 },
			{ 0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1 },
			{ 1,1,0,0,1,0,0,0,1,1,1,0,1,0,1,0,1,1,0,0,1,0,1 }
		},
		{//stageflag = 5

		},
		{//stageflag = 6
			{ 1,1,1,0,0,1,0,0,1,1,1,0,1,1,0,0,1,1,1,0,1,0,0,0,1,0,0,1,0,0,1,0,0,1},
			{ 0,1,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,1,0,1,1,0,1,0,1,0,1,1,0,1},
			{ 0,1,0,0,1,0,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1},
			{ 0,1,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,0,1},
			{ 1,1,1,0,0,1,0,0,1,1,1,0,1,1,0,0,1,1,1,0,1,0,0,0,1,0,0,1,0,0,1,0,0,1}
		}
	};


	erase();
	//���b�N�}���~��Ă���
	attrset(COLOR_PAIR(7));
	for (int k = 0; k < TATECELL / 2 + 10; k += 5) {
		erase();
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 8; j++) {
				mvaddstr(j + k, YOKOCELL / 2 - 1 + i, " ");
			}
		}
		refresh();
		Sleep(10);
	}
	//���b�N�}�������Ă��Ă�������ĂȂ�
	for (int j = 0; j < 10; j++) {
		erase();
		for (int i = 0; i < 35; i++) {
			mvaddstr(TATECELL / 2 + 10, i + YOKOCELL / 2 - 15, " ");
		}
		for (int i = 0; i < 25; i++) {
			mvaddstr(TATECELL / 2 + 9, i + YOKOCELL / 2 - 10, " ");
			mvaddstr(TATECELL / 2 + 11, i + YOKOCELL / 2 - 10, " ");
			mvaddstr(TATECELL / 2 + 12, i + YOKOCELL / 2 - 10, " ");
		}
		refresh();
		Sleep(10);
	}
	//���b�N�}�����Ɉړ�
	for (int i = 0; i < 60; i++) {
		erase();
		megaman(YOKOCELL / 2 - 10 - i, TATECELL / 2 + 15, 0);
		refresh();
		if (i == 0) {
			Sleep(500);
		}
	}
	//�����L�тĂ���
	attrset(COLOR_PAIR(4));
	for (int i = 0; i < YOKOCELL; i++) {
		mvaddstr(TATECELL / 2 - 30, i, " ");
		mvaddstr(TATECELL / 2 + 35, YOKOCELL - i, " ");
		if (i % 40 == 0) {
			refresh();
			Sleep(1);
		}
	}
	//stage�ԍ���start�`��
	for (int i = 0; i < sizeof name_stage / sizeof name_stage[stageflag]; i++) {
		for (int j = sizeof name_stage[stageflag] / sizeof name_stage[stageflag][i] - 1; j >= 0; j--) {
			for (int k = sizeof name_stage[stageflag][i] / sizeof name_stage[stageflag][i][j] - 1; k >= 0; k--) {
				if (name_stage[stageflag][j][k] == 1) {
					mvaddstr((TATECELL / 2 + j - 10), (YOKOCELL / 2 - sizeof name_stage[stageflag][i] / sizeof name_stage[stageflag][i][j] + k - 2), " ");
				}
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 18; j++) {
			if (start[i][j] == 1) {
				mvaddstr(TATECELL / 2 + i, YOKOCELL / 2 + j - 15, " ");
			}
			if (stage[i][j] == 1) {
				mvaddstr(TATECELL / 2 + i - 10, YOKOCELL / 2 + j, " ");
			}
		}
	}
	refresh();

	counter = 0;
	//���̐ݒ�
	int star[50][3], star2[50][3], star3[50][3];
	for (int i = 0; i < 50; i++) {
		star[i][0] = rand() % TATECELL / 2 - 30;
		star[i][1] = rand() % YOKOCELL;
		star[i][2] = rand() % 2;
		star2[i][0] = rand() % TATECELL / 2 - 30;
		star2[i][1] = rand() % YOKOCELL;
		star2[i][2] = rand() % 2;
		star3[i][0] = rand() % TATECELL / 2 - 30;
		star3[i][1] = rand() % YOKOCELL;
		star3[i][2] = rand() % 2;
		if (star[i][2] == 0) {
			star[i][0] = TATECELL - rand() % (TATECELL - (TATECELL / 2 + 35));
		}
		if (star2[i][2] == 0) {
			star2[i][0] = TATECELL - rand() % (TATECELL - (TATECELL / 2 + 35));
		}
		if (star2[i][2] == 0) {
			star2[i][0] = TATECELL - rand() % (TATECELL - (TATECELL / 2 + 35));
		}
	}
	while (true) {
		//���̕`��

		if (counter < 10) {
			attrset(COLOR_PAIR(4));
		}
		else if (counter < 20) {
			attrset(COLOR_PAIR(0));
		}
		else {
			counter = 0;
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 3; j++) {
				if (arrow[i][j] == 1) {
					mvaddstr(TATECELL / 2 + i, YOKOCELL / 2 + j - 21, " ");
				}
			}
		}
		counter++;
		refresh();
		//������
		attrset(COLOR_PAIR(4));

		for (int i = 0; i < 50; i++) {
			mvaddstr(star[i][0], star[i][1], " ");
			mvaddstr(star[i][0], star[i][1] + 1, " ");
			mvaddstr(star2[i][0], star2[i][1] + 2, " ");
			mvaddstr(star3[i][0], star3[i][1] + 3, " ");
		}

		refresh();
		attrset(COLOR_PAIR(0));
		for (int i = 0; i < 50; i++) {
			mvaddstr(star[i][0], star[i][1], " ");

			mvaddstr(star2[i][0], star2[i][1], " ");
			mvaddstr(star3[i][0], star3[i][1], " ");
			if (star[i][1] > YOKOCELL) {
				star[i][1] = 0;
			}
			else {
				star[i][1]++;
			}
			if (star2[i][1] > YOKOCELL) {
				star2[i][1] = 0;
			}
			else {
				star2[i][1] += 2;
			}
			if (star3[i][1] > YOKOCELL) {
				star3[i][1] = 0;
			}
			else {
				star3[i][1] += 3;
			}
		}
		refresh();
		if (GetAsyncKeyState(VK_RETURN)) {
			erase();
			//���b�N�}�����U���|�[�Y�Ƃ�
			mega_buster(YOKOCELL / 2 - 10 - 59, TATECELL / 2 + 15, 0);
			refresh();
			Sleep(500);
			erase();
			attrset(COLOR_PAIR(7));
			//���b�N�}����������ĂȂ�
			for (int j = 0; j < 10; j++) {
				erase();
				for (int i = 0; i < 35; i++) {
					mvaddstr(TATECELL / 2 + 10, i + YOKOCELL / 2 - 73, " ");
				}
				for (int i = 0; i < 25; i++) {
					mvaddstr(TATECELL / 2 + 9, i + YOKOCELL / 2 - 68, " ");
					mvaddstr(TATECELL / 2 + 11, i + YOKOCELL / 2 - 68, " ");
					mvaddstr(TATECELL / 2 + 12, i + YOKOCELL / 2 - 68, " ");
				}
				refresh();
				Sleep(10);
			}
			//���b�N�}���㏸
			for (int k = TATECELL / 2 + 10; k >= 0; k -= 5) {
				erase();
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 8; j++) {
						mvaddstr(j + k, YOKOCELL / 2 - 59 + i, " ");
					}
				}
				refresh();
				Sleep(10);
			}
			menuflag = 1;
			break;
		}
	}
}

void drawbase() {
	//�X�e�[�W�̃x�[�X�ƂȂ�ǂ⏰�̕`��
	attrset(COLOR_PAIR(4));
	//�ǂ̕\��
	for (int i = 0; i < TATECELL; i++) {
		mvaddstr(i, 2, " ");
		mvaddstr(i, YOKOCELL, " ");
	}
	//���ƓV��̕\��
	for (int i = 2; i <= YOKOCELL; i++) {
		mvaddstr(0, i, " ");
		mvaddstr(TATECELL, i, " ");
	}
}

void drawstage(int stagenumber) {
	/*
	attrset(COLOR_PAIR(4));
	switch (stagenumber)
	{
	case 1:
	//�X�e�[�W1�̑���
	for (int i = 50; i < 150; i++) {
	mvaddstr(TATECELL - 50, i, " ");
	mvaddstr(TATECELL - 50, i + YOKOCELL - 200, " ");
	mvaddstr(TATECELL - 100, i + YOKOCELL / 2 - 100, " ");
	}
	break;
	case 2:
	//�X�e�[�W2�̑���
	for (int i = 2; i < 102; i++) {
	mvaddstr(TATECELL - 50, i, " ");
	mvaddstr(TATECELL - 50, i + YOKOCELL - 102, " ");
	}
	break;
	case 3:
	//�X�e�[�W3�̑���
	if (num == 0) {
	attrset(COLOR_PAIR(3));
	num++;
	}
	else if (num == 1) {
	attrset(COLOR_PAIR(4));
	num = 0;
	}
	for (int i = YOKOCELL / 2 - yokowaku; i < YOKOCELL / 2 + yokowaku; i++) {
	mvaddstr(TATECELL, i, " ");
	}
	break;
	case 4:
	//�X�e�[�W4�̑���
	attrset(COLOR_PAIR(1));
	for (int i = 1; i < TATECELL; i++) {
	for (int j = 3; j < YOKOCELL; j++) {
	mvaddstr(i, j, " ");
	}
	}
	break;
	case 5:
	//�X�e�[�W5�̑���

	break;
	case 6:
	//�X�e�[�W6�̑���
	num++;
	if (num == 10000) {
	num = 0;
	rnd = rand() % 2;
	}
	if (rnd == 0) {
	for (int i = 2; i < 102; i++) {
	mvaddstr(TATECELL - 50, i, " ");
	mvaddstr(TATECELL - 50, i + YOKOCELL - 102, " ");
	}
	}
	else if (rnd == 1) {
	for (int i = YOKOCELL / 2 - yokowaku; i < YOKOCELL / 2 + yokowaku; i++) {
	mvaddstr(TATECELL - 50, i, " ");
	}
	}
	break;
	case 7:
	//�X�e�[�W7�̑���
	for (int i = 2; i < 70; i++) {
	attrset(COLOR_PAIR(3));
	mvaddstr(TATECELL, i, " ");
	mvaddstr(TATECELL, i + YOKOCELL - 70, " ");
	}
	break;
	case 8:
	//�X�e�[�W8�̑���
	for (int i = YOKOCELL / 2 - yokowaku * 2; i < YOKOCELL / 2 + yokowaku * 2; i++) {
	mvaddstr(TATECELL - 50, i, " ");
	mvaddstr(TATECELL - 100, i, " ");
	}
	break;
	case 9:
	//�X�e�[�W9�̑���
	mvaddstr(35, 55, " ");
	mvaddstr(20, 160, " ");
	mvaddstr(10, 80, " ");
	mvaddstr(30, 110, " ");
	mvaddstr(36, 140, " ");
	mvaddstr(26, 20, " ");
	break;
	default:
	break;
	}
	*/
}

void draw_clear() {

	int clear[5][20] = {
		{ 0,0,1,0,0,1,0,0,0,1,1,1,0,0,1,0,0,1,1,0 },
		{ 0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1 },
		{ 0,1,0,0,0,1,0,0,0,1,1,1,0,1,1,1,0,1,1,0 },
		{ 0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1 },
		{ 0,0,1,0,0,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1 }
	};
	int new_weapon[5][41] = {
		{ 1,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,0,0,1,0,0,1,1,0,0,0,1,0,0,1,0,0,1 },
		{ 1,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1 },
		{ 1,0,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,0,0,1,0,1,0,1,0,1,1 },
		{ 1,0,0,1,0,1,0,0,0,1,1,0,1,1,0,1,1,0,1,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,1 },
		{ 1,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,0,1,0,1,0,1,0,0,0,0,1,0,0,1,0,0,1 }
	};
	attrset(COLOR_PAIR(7));
	for (int k = 0; k < TATECELL / 2 + 10; k += 5) {
		erase();
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 8; j++) {
				mvaddstr(j + k, YOKOCELL / 2 - 59 + i, " ");
			}
		}
		refresh();
		Sleep(10);
	}
	//���b�N�}����������ĂȂ�
	for (int j = 0; j < 10; j++) {
		erase();
		for (int i = 0; i < 35; i++) {
			mvaddstr(TATECELL / 2 + 10, i + YOKOCELL / 2 - 73, " ");
		}
		for (int i = 0; i < 25; i++) {
			mvaddstr(TATECELL / 2 + 9, i + YOKOCELL / 2 - 68, " ");
			mvaddstr(TATECELL / 2 + 11, i + YOKOCELL / 2 - 68, " ");
			mvaddstr(TATECELL / 2 + 12, i + YOKOCELL / 2 - 68, " ");
		}
		refresh();
		Sleep(10);
	}
	//���b�N�}��
	erase();
	megaman(YOKOCELL / 2 - 69, TATECELL / 2 + 15, Megaman.colorCondition);
	refresh();
	//CLEAR�̕`��
	attrset(COLOR_PAIR(4));
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 5; j++) {
			if (clear[j][i] == 1) {
				mvaddstr(TATECELL / 2 + j, YOKOCELL / 2 + i - 15, " ");
			}
		}
		if (i % 4 == 0) {
			refresh();
			Sleep(200);
		}
	}
	counter = 0;
	int counter2 = 0;
	while (true) {
		if (counter < 2000) {
			megaman(YOKOCELL / 2 - 69, TATECELL / 2 + 15, Megaman.colorCondition);
		}
		else if (counter < 4000) {
			megaman(YOKOCELL / 2 - 69, TATECELL / 2 + 15, stageflag);
		}
		else {
			counter = 0;
			counter2++;
		}
		refresh();
		counter++;
		if (counter2 == 6) {
			break;
		}
	}
	//�����L�тĂ���
	for (int i = 0; i < YOKOCELL; i++) {
		mvaddstr(TATECELL / 2 - 30, i, " ");
		mvaddstr(TATECELL / 2 + 35, YOKOCELL - i, " ");
		if (i % 40 == 0) {
			refresh();
			Sleep(1);
		}
	}
	//���̐ݒ�
	int star[50][3], star2[50][3], star3[50][3];
	for (int i = 0; i < 50; i++) {
		star[i][0] = rand() % TATECELL / 2 - 30;
		star[i][1] = rand() % YOKOCELL;
		star[i][2] = rand() % 2;
		star2[i][0] = rand() % TATECELL / 2 - 30;
		star2[i][1] = rand() % YOKOCELL;
		star2[i][2] = rand() % 2;
		star3[i][0] = rand() % TATECELL / 2 - 30;
		star3[i][1] = rand() % YOKOCELL;
		star3[i][2] = rand() % 2;
		if (star[i][2] == 0) {
			star[i][0] = TATECELL - rand() % (TATECELL - (TATECELL / 2 + 35));
		}
		if (star2[i][2] == 0) {
			star2[i][0] = TATECELL - rand() % (TATECELL - (TATECELL / 2 + 35));
		}
		if (star2[i][2] == 0) {
			star2[i][0] = TATECELL - rand() % (TATECELL - (TATECELL / 2 + 35));
		}
	}
	counter = 0;
	//������
	while (true) {
		attrset(COLOR_PAIR(4));
		for (int m = 0; m < 2000; m++) {
			for (int i = 0; i < 50; i++) {
				mvaddstr(star[i][0], star[i][1], " ");
				mvaddstr(star[i][0], star[i][1] + 1, " ");
				mvaddstr(star2[i][0], star2[i][1]+2, " ");
				mvaddstr(star3[i][0], star3[i][1]+3, " ");
			}
		}
		refresh();
		attrset(COLOR_PAIR(0));
		for (int i = 0; i < 50; i++) {
			mvaddstr(star[i][0], star[i][1], " ");
			mvaddstr(star[i][0], star[i][1] + 1, " ");
			mvaddstr(star2[i][0], star2[i][1], " ");
			mvaddstr(star3[i][0], star3[i][1], " ");
			if (star[i][1] > YOKOCELL) {
				star[i][1] = 0;
			}
			else {
				star[i][1]++;
			}
			if (star2[i][1] > YOKOCELL) {
				star2[i][1] = 0;
			}
			else {
				star2[i][1] += 2;
			}
			if (star3[i][1] > YOKOCELL) {
				star3[i][1] = 0;
			}
			else {
				star3[i][1] += 3;
			}
		}
		refresh();
		if (counter < 10) {
			attrset(COLOR_PAIR(4));
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 41; j++) {
					if (new_weapon[i][j] == 1) {
						mvaddstr(TATECELL / 2 + i - 8, YOKOCELL / 2 + j - 25, " ");
					}
				}
			}
		}
		else if (counter < 20) {
			attrset(COLOR_PAIR(0));
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 41; j++) {
					if (new_weapon[i][j] == 1) {
						mvaddstr(TATECELL / 2 + i - 8, YOKOCELL / 2 + j - 25, " ");
					}
				}
			}
		}
		else {
			counter = 0;
		}
		counter++;
		if (GetAsyncKeyState(VK_RETURN)) {
			erase();
			attrset(COLOR_PAIR(7));
			//���b�N�}����������ĂȂ�
			for (int j = 0; j < 10; j++) {
				erase();
				for (int i = 0; i < 35; i++) {
					mvaddstr(TATECELL / 2 + 10, i + YOKOCELL / 2 - 73, " ");
				}
				for (int i = 0; i < 25; i++) {
					mvaddstr(TATECELL / 2 + 9, i + YOKOCELL / 2 - 68, " ");
					mvaddstr(TATECELL / 2 + 11, i + YOKOCELL / 2 - 68, " ");
					mvaddstr(TATECELL / 2 + 12, i + YOKOCELL / 2 - 68, " ");
				}
				refresh();
				Sleep(10);
			}
			//���b�N�}���㏸
			for (int k = TATECELL / 2 + 5; k >= 0; k -= 5) {
				erase();
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 8; j++) {
						mvaddstr(j + k, YOKOCELL / 2 - 59 + i, " ");
					}
				}
				refresh();
				Sleep(10);
			}
			break;
		}
	}
}

int drawsubmenu() {
	//EXIT
	char exit[5][100] = {
		{ '1','1','1','0','1','0','1','0','1','0','1','1','1' },
		{ '1','0','0','0','1','0','1','0','1','0','0','1','0' },
		{ '1','1','1','0','0','1','0','0','1','0','0','1','0' },
		{ '1','0','0','0','1','0','1','0','1','0','0','1','0' },
		{ '1','1','1','0','1','0','1','0','1','0','0','1','0' },
	};  	//EXIT
			//���
	char arrow[5][100] = {
		{ '1','0','0' },
		{ '1','1','0' },
		{ '1','1','1' },
		{ '1','1','0' },
		{ '1','0','0' },
	};
	//E
	char weapon0[5][3] = {
		{ '1','1','1' },
		{ '1','0','0' },
		{ '1','1','1' },
		{ '1','0','0' },
		{ '1','1','1' },
	};
	//H
	char weapon1[5][3] = {
		{ '1','0','1' },
		{ '1','0','1' },
		{ '1','1','1' },
		{ '1','0','1' },
		{ '1','0','1' },
	};
	//B
	char weapon2[5][3] = {
		{ '1','1','0' },
		{ '1','0','1' },
		{ '1','1','0' },
		{ '1','0','1' },
		{ '1','1','0' },
	};
	//S
	char weapon3[5][3] = {
		{ '0','1','1' },
		{ '1','0','1' },
		{ '1','1','0' },
		{ '0','0','1' },
		{ '1','1','0' },
	};
	//F
	char weapon4[5][3] = {
		{ '1','1','1' },
		{ '1','0','0' },
		{ '1','1','0' },
		{ '1','0','0' },
		{ '1','0','0' },
	};
	//H
	char weapon5[5][3] = {
		{ '1','0','1' },
		{ '1','0','1' },
		{ '1','1','1' },
		{ '1','0','1' },
		{ '1','0','1' },
	};
	//L
	char weapon6[5][3] = {
		{ '1','0','0' },
		{ '1','0','0' },
		{ '1','0','0' },
		{ '1','0','0' },
		{ '1','1','1' },
	};
	//I
	char weapon7[5][3] = {
		{ '1','1','1' },
		{ '0','1','0' },
		{ '0','1','0' },
		{ '0','1','0' },
		{ '1','1','1' },
	};

	int arrowpos = 0;
	while (submenuflag == 1) {
		//erase();
		attrset(COLOR_PAIR(4));
		//�T�u���j���[�̕\��
		//�g��
		for (int i = YOKOCELL / 2 - yokowaku * 2; i <= YOKOCELL / 2 + yokowaku; i++) {
			mvaddstr(5, i, " ");
			mvaddstr(TATECELL - 5, i, " ");
		}
		for (int i = 5; i <= TATECELL - 5; i++) {
			mvaddstr(i, YOKOCELL / 2 - yokowaku * 2, " ");
			mvaddstr(i, YOKOCELL / 2 + yokowaku, " ");
		}
		//���g
		//�^�����ɓh��Ԃ�
		attrset(COLOR_PAIR(8));
		for (int i = YOKOCELL / 2 - yokowaku * 2 + 1; i < YOKOCELL / 2 + yokowaku; i++) {
			for (int j = 6; j < TATECELL - 5; j++) {
				mvaddstr(j, i, " ");
			}
		}
		attrset(COLOR_PAIR(4));

		//����\��
		if (clearflag[1] == 1) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 3; j++) {
					if (weapon0[i][j] == '1') {
						mvaddstr(i - 8 * 14 + TATECELL - 20, j + YOKOCELL / 2 - yokowaku * 2 + 30, " ");
					}
				}
			}

			for (int i = 0; i < weapon[0]; i++) {
				for (int j = 0; j < 3; j++) {
					mvaddstr(j - 8 * 14 + TATECELL - 19, i + YOKOCELL / 2 - yokowaku * 2 + 20 + 20, " ");
				}
			}
		}
		if (clearflag[2] == 1) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 3; j++) {
					if (weapon1[i][j] == '1') {
						mvaddstr(i - 7 * 14 + TATECELL - 20, j + YOKOCELL / 2 - yokowaku * 2 + 30, " ");
					}
				}
			}

			for (int i = 0; i < weapon[1]; i++) {
				for (int j = 0; j < 3; j++) {
					mvaddstr(j - 7 * 14 + TATECELL - 19, i + YOKOCELL / 2 - yokowaku * 2 + 20 + 20, " ");
				}
			}
		}
		if (clearflag[3] == 1) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 3; j++) {
					if (weapon2[i][j] == '1') {
						mvaddstr(i - 6 * 14 + TATECELL - 20, j + YOKOCELL / 2 - yokowaku * 2 + 30, " ");
					}
				}
			}
			for (int i = 0; i < weapon[2]; i++) {
				for (int j = 0; j < 3; j++) {
					mvaddstr(j - 6 * 14 + TATECELL - 19, i + YOKOCELL / 2 - yokowaku * 2 + 20 + 20, " ");
				}
			}
		}
		if (clearflag[4] == 1) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 3; j++) {
					if (weapon3[i][j] == '1') {
						mvaddstr(i - 5 * 14 + TATECELL - 20, j + YOKOCELL / 2 - yokowaku * 2 + 30, " ");
					}
				}
			}
			for (int i = 0; i < weapon[3]; i++) {
				for (int j = 0; j < 3; j++) {
					mvaddstr(j - 5 * 14 + TATECELL - 19, i + YOKOCELL / 2 - yokowaku * 2 + 20 + 20, " ");
				}
			}
		}
		if (clearflag[5] == 1) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 3; j++) {
					if (weapon4[i][j] == '1') {
						mvaddstr(i - 4 * 14 + TATECELL - 20, j + YOKOCELL / 2 - yokowaku * 2 + 30, " ");
					}
				}
			}
			for (int i = 0; i < weapon[4]; i++) {
				for (int j = 0; j < 3; j++) {
					mvaddstr(j - 4 * 14 + TATECELL - 19, i + YOKOCELL / 2 - yokowaku * 2 + 20 + 20, " ");
				}
			}
		}
		if (clearflag[6] == 1) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 3; j++) {
					if (weapon5[i][j] == '1') {
						mvaddstr(i - 3 * 14 + TATECELL - 20, j + YOKOCELL / 2 - yokowaku * 2 + 30, " ");
					}
				}
			}
			for (int i = 0; i < weapon[5]; i++) {
				for (int j = 0; j < 3; j++) {
					mvaddstr(j - 3 * 14 + TATECELL - 19, i + YOKOCELL / 2 - yokowaku * 2 + 20 + 20, " ");
				}
			}
		}
		if (clearflag[7] == 1) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 3; j++) {
					if (weapon6[i][j] == '1') {
						mvaddstr(i - 2 * 14 + TATECELL - 20, j + YOKOCELL / 2 - yokowaku * 2 + 30, " ");
					}
				}
			}
			for (int i = 0; i < weapon[6]; i++) {
				for (int j = 0; j < 3; j++) {
					mvaddstr(j - 2 * 14 + TATECELL - 19, i + YOKOCELL / 2 - yokowaku * 2 + 20 + 20, " ");
				}
			}
		}
		if (clearflag[8] == 1) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 3; j++) {
					if (weapon7[i][j] == '1') {
						mvaddstr(i - 1 * 14 + TATECELL - 20, j + YOKOCELL / 2 - yokowaku * 2 + 30, " ");
					}
				}
			}
			for (int i = 0; i < weapon[7]; i++) {
				for (int j = 0; j < 3; j++) {
					mvaddstr(j - 1 * 14 + TATECELL - 19, i + YOKOCELL / 2 - yokowaku * 2 + 20 + 20, " ");
				}
			}
		}


		//EXIT�`��
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 13; j++) {
				if (exit[i][j] == '1') {
					mvaddstr(i + TATECELL - 20, j + YOKOCELL / 2 - yokowaku * 2 + 30, " ");
				}
			}
		}
		//���`��
		if (GetAsyncKeyState(VK_UP)) {
			if (arrowpos < 8) {
				arrowpos++;
			}
			Sleep(200);
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			if (arrowpos > 0) {
				arrowpos--;
			}
			Sleep(200);
		}
		if (arrowpos == 0) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 3; j++) {
					if (arrow[i][j] == '1') {
						mvaddstr(i + TATECELL - 20, j + YOKOCELL / 2 - yokowaku * 2 + 20, " ");
					}
				}
			}
		}
		else {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 3; j++) {
					if (arrow[i][j] == '1') {
						mvaddstr(i - arrowpos * 14 + TATECELL - 20, j + YOKOCELL / 2 - yokowaku * 2 + 20, " ");
					}
				}
			}
		}
		refresh();
		if (GetAsyncKeyState(VK_RETURN)) {
			if (arrowpos == 0) {
				submenuflag = 0;
				Sleep(200);
				return 0;
			}
			if (clearflag[9 - arrowpos] == 1) {
				submenuflag = 0;
				Sleep(200);
				return 9 - arrowpos;
			}
		}
	}
}
void filewrite() {
	FILE* fp;
	errno_t error;
	char buffer[BUFFSIZE];
	error = fopen_s(&fp, "data.csv", "w");
	if (error != 0) {
		fprintf_s(stderr, "failed to open");
	}
	else {
		for (int i = 0; i < 9; i++) {
			fprintf(fp, "%d,", clearflag[i]);
		}
		fclose(fp);
	}
}