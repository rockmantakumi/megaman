#pragma once
#pragma once

#include "stdafx.h"
#include <curses.h>

#define CHARBUFF 124

//���K�}���̕`��p�֐�
void megaman(int mx, int my, int Condition);//���K�}���̒ʏ펞�̊G
void reverse_megaman(int mx, int my, int Condition);	//���K�}���̒ʏ펞�i���]�j
void mega_move(int mx, int my, int Condition);//���K�}���̑����Ă�����
void reverse_mega_move(int mx, int my, int Condition);//���K�}���̑����Ă����ԁi���]�j
void mega_jamp(int mx, int my, int Condition);//���K�}���̃W�����v��
void reverse_mega_jamp(int mx, int my, int Condition);//���K�}���̃W�����v���i���]�j
void mega_buster(int mx, int my, int Condition);//���K�}���̍U����
void reverse_mega_buster(int mx, int my, int Condition);//���K�}���̍U�����i���]�j
void exemark(int mx, int my);//�G�O�[�}�[�N�̕`��
void draw_suraimega(int rx, int ry, int Condition);//���K�}���̃X���C�f�B���O
void draw_revslidmega(int rx, int ry, int Condition);//���K�}���̃X���C�f�B���O�i���]�j

void slid_megaman();//�X���C�f�C���O�̈ړ����\�b�h
void megaman_attack();//���K�}���̍U���̃��\�b�h
void attack(int x, int y, int Condition);//���K�}���̍U���̋ʂ̕`��
