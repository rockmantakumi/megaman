#pragma once
#pragma once

#include "stdafx.h"
#include "curses.h"
#include <Windows.h>
#include <random>

#define CHARBUFF 124

//��ʂ̌��E

#define Height	400

struct Mega {
	char name[CHARBUFF];	//���O
	int HP;	//�̗�
	int ATK;	//�U����
	int jampFlag;	//�W�����v�̃t���O
	int moveFlag;	//�ړ��̃t���O
	int attackFlag;	//�U���̃t���O
	int reverse;	//���]�t���O
	int specialFlag;	//�K�E�Z�t���O
	int height;	//���K�}���̍���
	int width;	//���K�}���̕�
	int slidFlag;	//�X���C�f�B���O�p�t���O
	int colorCondition;	//�F�p
};

extern Mega Megaman;

void draw_megaman(Mega Current);	//���K�}���`�� 
void mega_move();	//���K�}���̍s��

void set_Megaman_place();	//���K�}���̏����ʒu
void set_Megaman_status();	//���K�}���̃X�e�[�^�X�ݒ�
bool mega_attack_hit();//�����蔻��


extern int Rx, Ry;	//�e�X�g�p���K�}�����W
extern int Bx, By;//�e�X�g�p���K�}�����W
extern int megaattackNum;//���K�}���̍U�����