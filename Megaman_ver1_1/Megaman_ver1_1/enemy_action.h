#pragma once
#pragma once

//#include "stdafx.h"
#include "curses.h"
#include <Windows.h>
#include <random>

#define CHARBUFF 124

//�G�̍\����
struct Enemy {
	char name[CHARBUFF];	//���O
	int HP;	//�̗�
	int ATK;	//�U����
	int speed;	//�ړ����x
	int jampFlag;	//�W�����v�̃t���O
	int moveFlag;	//�ړ��̃t���O
	int attackFlag;	//�U���̃t���O
	int reverse;	//���]�t���O
	int specialFlag;	//�K�E�Z�t���O
	int specialLimit;	//�K�E�Z�g�p�\��
	int attackLimit;	//�U���񐔗p�t���O
	int height;	//�G�̍���
	int width;	//�G�̕�
};

//�e�L�����̍\����
extern Enemy Elect;		//stage1
extern Enemy Heat;		//stage2
extern Enemy Hub_hound;	//stage3
extern Enemy Ice_demon;	//stage6

extern Enemy Current;	//���݂̃L�����̍\���̖�


void set_Enemy_place();	//�G�̏����ʒu�ݒ�
void set_Enemy_status(int stageNum);	//�X�e�[�^�X�ݒ�
void draw_enemy(int stageNum);	//�X�e�[�W���Ƃ̓G��`��

								//�G�̍s���֐�
int DistanceEtoR();	//���K�}���Ƃ̋�������
void Enemy_action();	//�G�̍s���I��
void Enemy_moveR();	//�E�Ɉړ�
void Enemy_moveL();	//���Ɉړ�
void Enemy_jamp();	//�W�����v
void Enemy_attack();	//�U����I��
void Enemy_atk1();	//�U���P
void Enemy_atk2();	//�U���Q
void Enemy_DB();	//�K�E�Z


void drop_weapon();	//�G���|�����ƕ�����h���b�v����
bool attack_hit(int WxR, int WxL);	//�����蔻��
void hit_limit(int WxR, int WxL, int chara_select);	//��������E
void Enemy_efect();	//�G�̓o��G�t�F�N�g


extern int Ex, Ey;	//�G�̕`����W
extern int Wx, Wy;	//�G�̋Z���W
extern int SPx, SPy;	//�G�̕K�E�Z���W

extern int attackNum;	//�G�̍U�������p�J�E���^

extern int hit_count;	//�U�����萧���p�J�E���^


