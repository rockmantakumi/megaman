#include "stdafx.h"
#include "mega_action.h"
#include "draw_mega.h"
#include "Enemy_action.h"
#include "Stage.h"

int Rx = 0, Ry = 0;
int Bx = 0, By = 0;
int Ry_temp = 0;//�W�����v�p���W
int Ry_prev = 0;//�W�����v�p���W
int megaattackNum = 0;//�U���񐔗p

Mega Megaman;

void set_Megaman_place() {
	Rx = 10, Ry = TATECELL;	//test
	Bx = Rx + 25; By = Ry - 14;
}

void set_Megaman_status() {
	//���K�}���̍\���̏�����
	Megaman.HP = 30;
	Megaman.ATK = 1;
	Megaman.attackFlag = 0;
	Megaman.jampFlag = 0;
	Megaman.moveFlag = 0;
	Megaman.reverse = 0;
	Megaman.specialFlag = 0;
	Megaman.width = 21;
	Megaman.height = 24;
	Megaman.colorCondition = 0;

	Rx = 10, Ry = TATECELL;	//���K�}���̍ŏ��̈ʒu
	Bx = Rx + 25; By = Ry - 14;//���K�}���̃o�X�^�[�ŏ��̈ʒu
}

// ���K�}���̍U���̕`��
void draw_megaman(Mega Current) {
	if (Megaman.reverse == 0) {//������
		if (Megaman.jampFlag == 1) {//�W�����v�\
			if (Megaman.attackFlag == 1) {
				mega_jamp(Rx, Ry, Megaman.colorCondition);
				megaman_attack();
				Ry_temp = Ry;
				if (Ry > TATECELL - 60) {//�����͒n�ʂ���U�O�܂�
					Ry += (Ry - Ry_prev) + 1;
				}
				else if (Ry <= TATECELL - 60) {
					Ry = TATECELL - 59;
				}
				Ry_prev = Ry_temp;
				if (Ry >= TATECELL) {
					Megaman.jampFlag = 0;
					Ry_prev = 0;
					Ry_temp = 0;
					Ry = TATECELL;
				}
			}
			else {
				mega_jamp(Rx, Ry, Megaman.colorCondition);

				Ry_temp = Ry;
				if (Ry > TATECELL - 60) {//�����͒n�ʂ���U�O�܂�
					Ry += (Ry - Ry_prev) + 1;
				}
				else if (Ry <= TATECELL - 60) {
					Ry = TATECELL - 59;
				}
				Ry_prev = Ry_temp;
				if (Ry >= TATECELL) {
					Megaman.jampFlag = 0;
					Ry_prev = 0;
					Ry_temp = 0;
					Ry = TATECELL;
					Megaman.attackFlag = 0;
				}
			}

		}

		else if (Megaman.moveFlag == 1) {
			if (Megaman.attackFlag == 1) {
				mega_move(Rx, Ry, Megaman.colorCondition);
				megaman_attack();

			}
			else {
				mega_move(Rx, Ry, Megaman.colorCondition);
			}
		}
		else if (Megaman.attackFlag == 1) {
			megaman_attack();
			mega_buster(Rx, Ry, Megaman.colorCondition);//���b�N�}���̂����̊G
		}
		else if (Megaman.slidFlag == 1) {
			slid_megaman();
			draw_suraimega(Rx, Ry, Megaman.colorCondition);
		}
		else if (Megaman.attackFlag == 1 && Megaman.moveFlag == 1) {
			mega_move(Rx, Ry, Megaman.colorCondition);
			megaman_attack();
			mega_buster(Rx, Ry, Megaman.colorCondition);
		}
		else {
			megaman(Rx, Ry, Megaman.colorCondition);
		}
	}
	else if (Megaman.reverse == 1) {//�E����
		if (Megaman.jampFlag == 1) {//�W�����v�\
			if (Megaman.attackFlag == 1) {
				reverse_mega_jamp(Rx, Ry, Megaman.colorCondition);
				megaman_attack();
				Ry_temp = Ry;
				if (Ry > TATECELL - 60) {
					Ry += (Ry - Ry_prev) + 1;
				}
				else if (Ry <= TATECELL - 60) {
					Ry = TATECELL - 59;
				}
				Ry_prev = Ry_temp;
				if (Ry >= TATECELL) {
					Megaman.jampFlag = 0;
					Ry_prev = 0;
					Ry_temp = 0;
					Ry = TATECELL;
				}
			}
			else {
				reverse_mega_jamp(Rx, Ry, Megaman.colorCondition);

				Ry_temp = Ry;
				if (Ry > TATECELL - 60) {
					Ry += (Ry - Ry_prev) + 1;
				}
				else if (Ry <= TATECELL - 60) {
					Ry = TATECELL - 59;
				}
				Ry_prev = Ry_temp;
				if (Ry >= TATECELL) {
					Megaman.jampFlag = 0;
					Ry_prev = 0;
					Ry_temp = 0;
					Ry = TATECELL;
				}
			}
		}
		else if (Megaman.moveFlag == 2) {
			reverse_mega_move(Rx, Ry, Megaman.colorCondition);
		}
		else if (Megaman.attackFlag == 1) {
			megaman_attack();

			reverse_mega_buster(Rx, Ry, Megaman.colorCondition);
		}
		else if (Megaman.slidFlag == 1) {
			slid_megaman();
			draw_revslidmega(Rx, Ry, Megaman.colorCondition);

		}
		else {
			reverse_megaman(Rx, Ry, Megaman.colorCondition);
		}
	}
	
	if (Megaman.jampFlag > 0) {
		hit_count = 0;
	}
}


//���K�}���̈ړ� test
void mega_move() {

	if (GetAsyncKeyState(VK_RIGHT)) {//�L�[�E�������ꂽ
		if (GetAsyncKeyState(VK_UP)) {
			Megaman.jampFlag = 1;
			Ry_prev = Ry;
			Ry = Ry - 2;
		}
		Megaman.reverse = 0;
		Megaman.moveFlag = 1;
		Megaman.attackFlag = 0;
		Rx += 2;
		Bx = Rx + 25;
	}
	else if (GetAsyncKeyState(VK_LEFT)) {//�L�[���������ꂽ
		if (GetAsyncKeyState(VK_UP)) {
			Megaman.jampFlag = 1;
			Ry_prev = Ry;
			Ry = Ry - 2;
		}
		Megaman.reverse = 1;
		Megaman.moveFlag = 2;
		Megaman.attackFlag = 0;
		Rx -= 2;
		Bx = Rx;
	}
	else if (GetAsyncKeyState(VK_UP)) {//�L�[�オ�����ꂽ
		Megaman.jampFlag = 1;
		Ry_prev = Ry;
		Ry = Ry - 2;
		Megaman.attackFlag = 0;
	}
	else if (GetAsyncKeyState('B')) {//�L�[B�������ꂽ
		Megaman.attackFlag = 1;
		if (GetAsyncKeyState(VK_UP)) {//�L�[�オ�����ꂽ
			Megaman.jampFlag = 1;
			Ry_prev = Ry;
			Ry = Ry - 2;
		}
	}
	else if (GetAsyncKeyState(VK_DOWN)) {//�L�[���������ꂽ
		Megaman.slidFlag = 1;
		Megaman.attackFlag = 0;
		if (Megaman.reverse == 0) {
			Bx = Rx + 25;
		}
		else {
			Bx = Rx;
		}

	}
	else {
		Megaman.moveFlag = 0;
	}

	//�Ƃ肠������5�`450�܂�
	if (Rx <= WidthL) {
		Rx = WidthL;
	}
	if (Rx >= WidthR - 24) {
		Rx = WidthR - 24;
	}
}
void megaman_Buster1() {//�U�����\�b�h
	if (Megaman.reverse == 0) {//�E����
		attack(Bx, By, Megaman.colorCondition);//�U���̋ʂ̕`��
		Bx += 1;

		if (Current.moveFlag > 0 || Current.jampFlag > 0 || (stageflag == 3 && Current.attackFlag > 0)) {
			Bx += 1;
		}

	}
	else if (Megaman.reverse == 1) {//������
		attack(Bx, By, Megaman.colorCondition);
		Bx -= 1;

		if (Current.moveFlag > 0 || Current.jampFlag > 0 || (stageflag == 3 && Current.attackFlag > 0)) {
			Bx -= 1;
		}
	}
	if (Bx < WidthL || Bx > WidthR - 24) {//�ǂ܂œ��������狅�͏�����
		Bx = Rx;
		megaattackNum++;
	}
	else if (Bx > WidthR - 24) {
		Bx = Rx + 25;
		megaattackNum++;
	}

	hit_limit(0, 0, 1);

	/*if (mega_attack_hit() == true) {//�G�ɂ�����������
		Current.HP -= Megaman.ATK;

		
		if (Megaman.reverse == 0) {//��������
			Bx = Rx + 25;
			megaattackNum++;
		}
		else if (Megaman.reverse == 1) {//�E������
			Bx = Rx;
			megaattackNum++;
		}

	}*/

	//�U��1�͘A����1��s��
	if (megaattackNum == 1) {
		Megaman.attackFlag = 0;
		megaattackNum = 0;
	}
}

void megaman_attack() {//�U������
	if (Megaman.attackFlag == 1) {
		megaman_Buster1();
	}
	else if (Megaman.attackFlag == 2) {
		//megaman_hissatu();
	}
}
void slid_megaman() {//�X���C�f�B���O�ł̈ړ�

	if (Megaman.reverse == 0) {//��������
		Rx += 2;
		Bx += 2;
		Megaman.slidFlag = 0;

	}
	else if (Megaman.reverse == 1) {//�E������
		Rx -= 2;
		Bx -= 2;
		Megaman.slidFlag = 0;
	}
}

bool mega_attack_hit() {
	if (Megaman.reverse == 0) {
		if (Bx >= Ex && Bx < Ex + Current.width && By >= Ey - Current.height && By <= Ey) {
			Current.HP -= Megaman.ATK;
			Bx = Rx + 25;
			megaattackNum++;
			return true;
		}
		else {
			return false;
		}
	}
	else if (Megaman.reverse == 1) {

		if (Bx >= Ex && Bx < Ex + Current.width && By >= Ey - Current.height && By <= Ey) {
			Current.HP -= Megaman.ATK;
			Bx = Rx;
			megaattackNum++;
			return true;
		}
		else {
			return false;
		}
	}
}