#include "stdafx.h"
#include "enemy_action.h"
#include "draw_enemy.h"
#include "draw_mega.h"
#include "Mega_action.h"
#include "Stage.h"


int Ex = 0, Ey = 0;	//�G�̊e���W
int Wx = 0, Wy = 0;	//�G�̋Z�̍��W
int SPx = 10, SPy = 0;	//�G�̕K�E�Z���W

int attackNum = 0;	//�U���񐔗p�J�E���^
int jampX[2];	//�W�����v����Ƃ��̓G�ƃ��K�}���̂����W�ۑ��p

int hit_count = 0;	//�����蔻��̐����p�J�E���^

Enemy Elect;	//stage1
Enemy Heat;		//stage2
Enemy Hub_hound;//stage3
Enemy Ice_demon;//stage6
Enemy Current;	//���݂̃L�����̍\���̖�


//�G�̏����ʒu�ݒ�
void set_Enemy_place() {
	Ex = 400, Ey = TATECELL;
}


//�G�̃X�e�[�^�X��ݒ�
void set_Enemy_status(int stageNum) {

	Ex = 400, Ey = TATECELL;	//�G�̊e���W

	if (stageNum == 1) {
		sprintf_s(Elect.name, "%s", "Elect");
		Elect.HP = 30;
		Elect.ATK = 2;
		Elect.speed = 2;
		Elect.height = 23;
		Elect.width = 24;
		Current = Elect;
	}
	else if (stageNum == 2) {
		sprintf_s(Heat.name, "%s", "Heat");
		Heat.HP = 30;
		Heat.ATK = 3;
		Heat.speed = 1;
		Heat.height = 46;
		Heat.width = 27;
		Current = Heat;
	}
	else if (stageNum == 3) {
		sprintf_s(Hub_hound.name, "%s", "Hub_hound");
		Hub_hound.HP = 30;
		Hub_hound.ATK = 2;
		Hub_hound.speed = 3;
		Hub_hound.height = 23;
		Hub_hound.width = 29;
		Current = Hub_hound;
	}
	else if (stageNum == 6) {
		sprintf_s(Ice_demon.name, "%s", "Ice_demon");
		Ice_demon.HP = 30;
		Ice_demon.ATK = 2;
		Ice_demon.speed = 3;
		Ice_demon.height = 32;
		Ice_demon.width = 26;
		Current = Ice_demon;
	}

	Current.reverse = 0;	//���]�p�t���O
	Current.jampFlag = 0;	//�W�����v�p�t���O
	Current.moveFlag = 0;	//�ړ��p�t���O
	Current.attackFlag = 0;	//�U���p�t���O
	Current.specialFlag = 0;	//�K�E�Z�p�t���O
	Current.specialLimit = 1;	//�K�E�Z�g�p�����p�t���O
	Current.attackLimit = 3;	//�U���񐔐����p�t���O
	attackNum = 0;	//�U���񐔗p�J�E���^
}

//enemy�̕`��ireverse:�i�s�����̔��� jamp:�W�����v�̔��� move:�ړ��̔��� atk:�U���̔���)
//reserve��0�Ȃ�G���������A1�Ȃ�E����
//jampFlag��1�Ȃ�W�����v
//moveFlag��1�Ȃ�ړ�(stageNum == 6�@�̂Ƃ��̂�1�ȏ�ňړ�)
//attackFlag��1�ȏ�Ȃ�U��
//�G�̕`��
void draw_enemy(int stageNum) {

	if (stageNum == 1) {

		if (Current.reverse == 0) {
			if (Current.jampFlag == 1) {
				elect_jamp(Ex, Ey);
			}
			else if (Current.moveFlag == 1) {
				elect_move(Ex, Ey);
			}
			else if (Current.attackFlag >= 1) {
				elect_atkmove(Ex, Ey);
			}
			else {
				elect(Ex, Ey);
			}
		}
		else if (Current.reverse == 1) {
			if (Current.jampFlag == 1) {
				reverse_elect_jamp(Ex, Ey);
			}
			else if (Current.moveFlag == 1) {
				reverse_elect_move(Ex, Ey);
			}
			else if (Current.attackFlag >= 1) {
				reverse_elect_atkmove(Ex, Ey);
			}
			else {
				reverse_elect(Ex, Ey);
			}
		}
	}
	else if (stageNum == 2) {

		if (Current.reverse == 0) {
			if (Current.jampFlag == 1) {
				heat(Ex, Ey);
			}
			else if (Current.moveFlag == 1) {
				heat(Ex, Ey);
			}
			else if (Current.attackFlag >= 1) {
				heat_atkmove(Ex, Ey);
			}
			else {
				heat(Ex, Ey);
			}
		}
		else if (Current.reverse == 1) {
			if (Current.jampFlag == 1) {
				reverse_heat(Ex, Ey);
			}
			else if (Current.moveFlag == 1) {
				reverse_heat(Ex, Ey);
			}
			else if (Current.attackFlag >= 1) {
				reverse_heat_atkmove(Ex, Ey);
			}
			else {
				reverse_heat(Ex, Ey);
			}
		}
	}
	else if (stageNum == 3) {

		if (Current.reverse == 0) {
			if (Current.jampFlag == 1) {
				hub_hound(Ex, Ey);
			}
			else if (Current.moveFlag == 1) {
				hub_hound_move(Ex, Ey);
			}
			else if (Current.attackFlag >= 1) {
				//hub_hound(Ex, Ey);
			}
			else {
				hub_hound(Ex, Ey);
			}
		}
		else if (Current.reverse == 1) {
			if (Current.jampFlag == 1) {
				reverse_hub_hound(Ex, Ey);
			}
			else if (Current.moveFlag == 1) {
				reverse_hub_hound_move(Ex, Ey);
			}
			else if (Current.attackFlag >= 1) {
				//reverse_hub_hound(Ex, Ey);
			}
			else {
				reverse_hub_hound(Ex, Ey);
			}
		}
	}
	else if (stageNum == 6) {
		if (Current.reverse == 0) {
			if (Current.jampFlag == 1) {
				ice_demon_move(Ex, Ey);
			}
			else if (Current.moveFlag >= 1) {
				ice_demon_move(Ex, Ey);
			}
			else if (Current.attackFlag >= 1) {
				ice_demon_atkmove(Ex, Ey);
			}
			else {
				ice_demon(Ex, Ey);
			}
		}
		else if (Current.reverse == 1) {
			if (Current.jampFlag == 1) {
				reverse_ice_demon_move(Ex, Ey);
			}
			else if (Current.moveFlag >= 1) {
				reverse_ice_demon_move(Ex, Ey);
			}
			else if (Current.attackFlag >= 1) {
				reverse_ice_demon_atkmove(Ex, Ey);
			}
			else {
				reverse_ice_demon(Ex, Ey);
			}
		}
	}

}


//��������G�̍s��-------------------------------------------------------------------------------------

//�G�ƃ��K�}���̋����𑪂�
int DistanceEtoR() {
	int Distance = Ex - Rx;
	return Distance;
}

//�G�̍s����I��----------------------------------------------------------------------------------------
void Enemy_action() {
	int Distance = 0;
	Distance = DistanceEtoR();

	//�s�����łȂ��Ȃ�A�����ɂ���ĕ����𔻒f
	if (Distance > 0 && (Current.jampFlag == 0 && Current.moveFlag == 0 && Current.attackFlag == 0)) {
		Current.reverse = 0;
	}
	else if (Distance < 0 && (Current.jampFlag == 0 && Current.moveFlag == 0 && Current.attackFlag == 0)) {
		Current.reverse = 1;
	}

	//�V�����s������
	if (Current.specialLimit > 0 && (Current.specialFlag > 0 || Current.HP <= 5 && Current.jampFlag == 0)) {

		Enemy_DB();

	}
	else {
		//�U������@new
		if (Current.attackLimit == 0 && Current.jampFlag == 0 && Current.moveFlag == 0) {
			Wx = Ex, Wy = Ey;	//�Z��\��������ŏ��̍��W��G�̍��W�ɂ���
			if (Distance > 120) {
				Current.attackFlag = 1;
			}
			else {
				Current.attackFlag = 2;
			}
			Current.attackLimit = 1;
		}
		//�W�����v����ƈړ����� new
		else if ((Distance > 250 || Distance < -250) && Current.attackFlag == 0 && Current.jampFlag == 0 && Current.moveFlag == 0) {
			Current.jampFlag = 1;
			jampX[0] = Ex, jampX[1] = Rx;	//�W�����v���̓G�ƃ��K�}����x���W�ۑ�(jampX[0]:�G jampX[1]:���K�}��)
			Current.attackLimit = 0;
		}
		else if ((Distance > 180 || Distance < -180) && Current.attackFlag == 0 && Current.jampFlag == 0 && Current.moveFlag == 0) {
			Current.moveFlag = 1;
			Current.attackLimit = 0;
		}
		else if (Current.attackFlag == 0 && Current.jampFlag == 0 && Current.moveFlag == 0) {
			Current.attackFlag = 1;
			Current.attackLimit = 1;
		}


		if (Current.jampFlag == 1) {
			Enemy_jamp();
		}
		else if (Current.moveFlag >= 1) {
			if (Current.reverse == 0) {
				Enemy_moveL();
			}
			else {
				Enemy_moveR();
			}
		}
		else if (Current.attackFlag > 0) {
			Enemy_attack();
		}
	}

}
//�G�̍s���I���I��----------------------------------------------------------------------------------------------------------------------------


//�G�̈ړ��p�֐�------------------------------------------------------------------------------

//�G���E�ɓ�����
void Enemy_moveR() {

	//�X�e�[�W�U�łȂ��Ƃ�
	if (stageflag != 6) {

		//�G�̃X�s�[�h�Ԃ񂾂����W�ړ�
		Ex += Current.speed;

		//������120�ȓ��Ȃ�I��
		if (DistanceEtoR() > -120) {
			Current.moveFlag = 0;
		}

		//�E�[�ɗ����炻���ňړ��I��
		if (Ex > YOKOCELL) {
			Ex = YOKOCELL - Current.width;
			Current.moveFlag = 0;
		}
	}
	//�X�e�[�W��6�̂Ƃ�
	else if (stageflag == 6) {

		//Current.moveFlag��500�����Ȃ炻�̏�őҋ@
		if (Current.moveFlag < 500) {
			Ex = Ex;
		}
		//Current.moveFlag�����l���ɂȂ�ƓG�̂������΂ɏu�Ԉړ�
		else if (Current.moveFlag >= 500 && Current.moveFlag <= 550) {

			if (Rx >= YOKOCELL - Megaman.width * 2 - 30) {
				Ex = Rx - Megaman.width * 2 - 30;
			}
			else {
				Ex = Rx + Megaman.width + 30;
				Current.reverse = 0;
			}
			Current.moveFlag = 550;
		}

		Current.moveFlag++;

		//�G�̈ړ����͏������x���x���Ȃ邽�߁AmoveFlag�̃J�E���g�𑁂߂�
		if (Current.moveFlag > 0 || Current.jampFlag > 0) {
			if (Current.moveFlag > 495 && Current.moveFlag < 500) {
				Current.moveFlag = 500;
			}
			else {
				Current.moveFlag += 5;
			}
		}

		//moveFlag��2000�𒴂���ƈړ��I��
		if (Current.moveFlag > 2000) {
			Current.moveFlag = 0;
			Current.attackLimit = 0;
		}
	}
}

//�G�����ɓ�����(���e�͉E�ւ̈ړ��Ɠ����Ȃ̂Ő����͊���)
void Enemy_moveL() {
	if (stageflag != 6) {
		Ex -= Current.speed;

		if (DistanceEtoR() < 120) {
			Current.moveFlag = 0;
		}

		if (Ex < WidthL) {
			Ex = WidthL;
			Current.moveFlag = 0;
		}
	}
	else if (stageflag == 6) {

		if (Current.moveFlag < 500) {

			Ex = Ex;
		}
		else if (Current.moveFlag >= 500 && Current.moveFlag <= 550) {

			if (Rx <= 3 + Megaman.width * 2 + 30) {
				Ex = Rx + Megaman.width * 2 + 30;

			}
			else {
				Ex = Rx - Megaman.width - 30;
				Current.reverse = 1;
			}
			Current.moveFlag = 550;
		}

		if (Current.moveFlag > 0 || Current.jampFlag > 0) {
			if (Current.moveFlag > 495 && Current.moveFlag < 500) {
				Current.moveFlag = 500;
			}
			else {
				Current.moveFlag += 5;
			}
		}

		Current.moveFlag++;

		if (Current.moveFlag > 2000) {
			Current.moveFlag = 0;
			Current.attackLimit = 0;
		}

	}

}

//�G�̈ړ��p�֐��I��-------------------------------------------------------------------------

//�G�̃W�����v�p�֐�-------------------------------------------------------------------------
//�G���W�����v������(1�Ȃ獶�����ɁA2�Ȃ�E������)
void Enemy_jamp() {

	if (stageflag != 6) {
		if (Current.reverse == 0) {

			//�W�����v���̓G��x���W���A�W�����v�J�n���̓G�ƃ��K�}���̋����̒��_�ɂȂ�܂ŏ㏸
			//���_�ɂ��ǂ���Ɖ��~
			if (Ex > (jampX[1] + (jampX[0] - jampX[1]) / 2)) {
				Ey -= 1;
			}
			else {
				Ey += 1;
			}

			//�W�����v���ɐi�s�����ɂ��i��
			Ex -= 3;
		}
		else if (Current.reverse == 1) {
			if (Ex < (jampX[0] + (jampX[1] - jampX[0]) / 2)) {
				Ey -= 1;
			}
			else {
				Ey += 1;
			}
			Ex += 3;
		}

		//�W�����v�̍��������y���W��30�Ƃ���
		if (Ey < 30) {
			Ey = 30;
		}

		//���݂̓G�̈ʒu�����ɓ��B����΃W�����v�I��
		if (Ey == TATECELL) {
			Current.jampFlag = 0;
		}

		//���݂̈ʒu����ʂ̒[�Ȃ狭���I�ɏI��
		if (Ex < 3) {
			Ey = TATECELL;
			Ex = WidthL;
			Current.jampFlag = 0;
		}
		else if (Ex > YOKOCELL) {
			Ey = TATECELL;
			Ex = YOKOCELL - Current.width;
			Current.jampFlag = 0;
		}
	}
	//�X�e�[�W6�̓G�̓W�����v�����ɏu�Ԉړ�����
	else if (stageflag == 6) {
		Current.jampFlag = 0;
		Current.moveFlag = 1;
		if (Current.reverse == 0) {
			Enemy_moveL();
		}
		else {
			Enemy_moveR();
		}
	}

}
//�G�̃W�����v�p�֐��I��----------------------------------------------------------------------


//�G�̍U���p�֐�------------------------------------------------------------------------------

//�G�̍U����I��
void Enemy_attack() {
	if (Current.attackFlag == 1) {
		Enemy_atk1();
	}
	else if (Current.attackFlag == 2) {
		Enemy_atk2();
	}
}

//�U���P
void Enemy_atk1() {

	//stage1�܂���2�G�̍U��
	if (stageflag == 1 || stageflag == 2) {

		//�Z�̐i�s�́A��x��x���W��5�i��
		if (Current.reverse == 0) {

			//���ꂼ��̓G�̋Z��\��
			if (stageflag == 1) {
				elect_atk1(Wx, Wy);
			}
			else if (stageflag == 2) {
				heat_atk1(Wx, Wy);
			}

			//�������x���������߁A���W�ړ���x��
			if (attackNum % 10 == 0) {
				Wx -= 1;

				//���K�}���̈ړ����̓��U�̑��x���グ��
				if (Megaman.moveFlag >= 1) {
					Wx -= 5;
				}
			}


		}
		else if (Current.reverse == 1) {

			if (stageflag == 1) {
				reverse_elect_atk1(Wx, Wy);
			}
			else if (stageflag == 2) {
				reverse_heat_atk1(Wx, Wy);
			}

			if (attackNum % 10 == 0) {
				Wx += 1;

				//���K�}���̈ړ����̓��U�̑��x���グ��
				if (Megaman.moveFlag >= 1) {
					Wx += 5;
				}
			}

		}

		attackNum++;

		//�U�������K�}���ɓ����邩�A�[�܂ōs���ΏI���
		if (attack_hit(Wx, Wx) == true) {
			Wx = Ex;
		}
		else if (Wx < 3 || Wx > YOKOCELL - 24) {
			Wx = Ex;
		}

		//�U��1�͘A����2��s��
		if (attackNum / 1000 == 2) {
			Current.attackFlag = 0;
			attackNum = 0;
		}
	}
	//stage3�̓G�̍U���p
	else if (stageflag == 3) {

		//�G��������
		if (Current.reverse == 0) {

			//�U���P��`��
			hub_hound_atk1(Ex, Ey);

			//�U���̈ړ����x��3
			Ex -= 3;

			//���K�}���̈ړ����̓��U�̑��x���グ��
			if (Megaman.jampFlag >= 1 || Megaman.moveFlag >= 1) {
				Ex -= 3;
			}

			//�����蔻��
			Wx = Ex, Wy = Ey - 12;
			hit_limit(Wx + 48, Wx, 0);

		}
		//�G���E����
		else if (Current.reverse == 1) {

			//�U���P��`��
			reverse_hub_hound_atk1(Ex, Ey);

			//�U���̈ړ����x��3
			Ex += 3;

			//���K�}���̈ړ����̓��U�̑��x���グ��
			if (Megaman.jampFlag >= 1 || Megaman.moveFlag >= 1) {
				Ex += 3;
			}

			//�����蔻��
			Wx = Ex, Wy = Ey - 12;
			hit_limit(Wx + 48, Wx, 0);

		}

		//���[�܂��͉E�[�܂œ��B����ƁA�U���񐔂��P�J�E���g���ēG�̌����𔽓]
		if (Ex < 3) {
			Ex = 3;
			attackNum++;
			Current.reverse = 1;
		}
		else if (Ex > YOKOCELL - 48) {
			Ex = Ex - Current.width;
			attackNum++;
			Current.reverse = 0;
		}

		//�U��1�͘A����2��s��
		if (attackNum == 2) {
			Current.attackFlag = 0;
			attackNum = 0;
		}
	}
	//�X�e�[�W6�͍U���P�Ȃ��̂ňړ�������
	else if (stageflag == 6) {
		Current.attackFlag = 0;
		Current.moveFlag = 1;
	}

}

//�U���Q
void Enemy_atk2() {

	//stage1�܂���2�G�̍U��
	if (stageflag == 1 || stageflag == 2) {

		//�G��������
		if (Current.reverse == 0) {

			//800�Ŋ���؂�鎞�ɍU���i�������x�Ƃ̒����j�i�U���͈�x�ł����W50���ړ��j
			if (attackNum % 800 == 0) {
				Wx = Wx -= 50;
			}

			//�G���Ƃ̍U����\��
			if (stageflag == 1) {
				elect_atk2(Wx, Wy);
			}
			else if (stageflag == 2) {
				heat_atk2(Wx, Wy);
			}

		}
		//�G���E����
		else if (Current.reverse == 1) {

			//800�Ŋ���؂�鎞�ɍU���i�������x�Ƃ̒����j�i�U���͈�x�ł����W50���ړ��j
			if (attackNum % 800 == 0) {
				Wx = Wx += 50;
			}

			//�G���Ƃ̍U����\��
			if (stageflag == 1) {
				elect_atk2(Wx, Wy);
			}
			else if (stageflag == 2) {
				heat_atk2(Wx, Wy);
			}
		}

		//�G�̍s�����͏������x���Ȃ�̂�attackNum�̒ǉ��ʂ𑝂₷
		if (Megaman.jampFlag >= 1 || Megaman.moveFlag >= 1) {
			attackNum += 50;
		}

		//�U�����[�܂ōs���ΏI���
		if (Wx < 3) {
			Wx = Ex;
		}
		else if (Wx > YOKOCELL - 30) {
			Wx = Ex + Current.width;
		}

		//�����蔻��͋Z���\�����ꂽ�Ƃ��̂�
		if (attackNum % 800 == 0) {
			if (Current.reverse == 0) {
				hit_limit(Wx + 24, Wx, 0);
			}
			else if (Current.reverse == 1) {
				hit_limit(Wx - 24, Wx, 0);
			}

		}

		attackNum++;

		//�U��2�͘A����3��s��
		if (attackNum / 800 == 3) {
			Current.attackFlag = 0;
			attackNum = 0;
		}
	}
	//stage3�͍U���Q�Ȃ�
	else if (stageflag == 3) {
		Current.attackFlag = 0;
	}
	//stage6�̓G�̍U��
	else if (stageflag == 6) {

		//�G��������
		if (Current.reverse == 0) {

			//attackNum��1000�����̎��Z��\���i��莞�ԕ\�������邽�߁j
			if (attackNum < 1000) {

				//�G�̏ꏊ�ɂ���ċZ�̏ꏊ�ύX�i�Z����ʊO�ɍs���Ȃ��悤�ɂ���j�i44�͋Z�̕��j
				if (Rx > Current.width + 50) {
					ice_demon_atk2(Wx - 44 - 30, Wy);

					//�`�悳��ăJ�E���g��500�܂œ����蔻�肠��
					if (attackNum > 500) {
						hit_limit(Wx - 30, Wx - 44 - 30, 0);
					}

				}
				else {
					ice_demon_atk2(Rx, Wy);

					//�`�悳��ăJ�E���g��500�܂œ����蔻�肠��
					if (attackNum > 500) {
						hit_limit(Rx + 44, Rx, 0);
					}

				}

			}
		}
		//�G���E����
		else if (Current.reverse == 1) {

			if (attackNum < 1000) {

				//�G�̏ꏊ�ɂ���ċZ�̏ꏊ�ύX�i�Z����ʊO�ɍs���Ȃ��悤�ɂ���j�i44�͋Z�̕��j
				if (Rx < YOKOCELL - 44) {
					reverse_ice_demon_atk2(Wx + Current.width + 30, Wy);

					if (attackNum > 500) {
						hit_limit(Wx + Current.width + 30 + 44, Wx + Current.width + 30, 0);
					}

				}
				else {
					reverse_ice_demon_atk2(YOKOCELL - 40, Wy);

					if (attackNum > 500) {
						hit_limit(Rx + Megaman.width, YOKOCELL - 40, 0);
					}

				}

			}
		}

		attackNum++;

		//attackNum��1000�𒴂���ƍU���I�����Ĉړ�
		if (attackNum > 1000) {
			Current.attackFlag = 0;
			attackNum = 0;
			Current.moveFlag = 1;
			Current.attackLimit = 0;
		}
	}

}

//�G�̍U���p�֐��I��--------------------------------------------------------------------------


//�K�E�Z--------------------------------------------------------------------------------------

void Enemy_DB() {
	int cnt = 0;

	//���K�}���̍s�����~
	Megaman.attackFlag = 0;
	Megaman.jampFlag = 0;
	Megaman.moveFlag = 0;

	//�X�e�[�W�P�@elect�̕K�E�Z
	if (stageflag == 1) {
		Ex = YOKOCELL - Current.width - 10;
		Rx = 50, Ry = TATECELL;

		if (Current.specialFlag < 20) {
			elect_jamp(Ex, Ey);
			Ey -= 2;
			Current.specialFlag++;
			napms(80);
		}
		else if (Current.specialFlag >= 20 && Current.specialFlag < 40) {
			elect_spmove1(Ex, Ey);
			Current.specialFlag++;
			napms(80);
		}
		else if (Current.specialFlag >= 40 && Current.specialFlag < 60) {
			elect_spmove2(Ex, Ey);
			Current.specialFlag++;
			napms(80);
		}
		//�ł����������Ƃ�
		else if (Current.specialFlag >= 60 && SPy < 200) {
			elect_spmove2(Ex, Ey);
			while (cnt <= SPy) {
				if (cnt % 3 == 0) {
					SPx = 10;
				}
				else if (cnt % 3 == 1) {
					SPx = 11;
				}
				else {
					SPx = 12;
				}

				elect_sp(SPx, cnt);
				cnt++;
			}
			SPy++;
		}
		else {
			Megaman.HP -= Current.ATK * 5;
			SPx = 10, SPy = 0;
			Current.specialFlag = 0;
			Current.specialLimit = 0;
			set_Enemy_place();		//�G�̏ꏊ�����Ƃ̈ʒu��
			set_Megaman_place();	//���K�}���̏ꏊ�����Ƃ̈ʒu��
		}
	}
	//�X�e�[�W�Q�@heat�̕K�E�Z�i�������j
	else if (stageflag == 2) {
		Current.specialFlag = 0;
		Current.specialLimit = 0;
	}
	//�X�e�[�W�R�@hub_hound�̕K�E�Z
	else if (stageflag == 3) {

		if (Current.specialFlag == 0) {
			Rx = 100, Ry = TATECELL;
			Ex = 300, Ey = TATECELL;
		}
		else if (Current.specialFlag == 40) {
			Ex = 20, Ey = Current.height;
		}
		else if (Current.specialFlag == 60) {
			Ex = 180, Ey = Current.height;
		}
		else if (Current.specialFlag == 80) {
			Ex = 100, Ey = Current.height;
		}

		if (Current.specialFlag < 20) {
			megaman(Rx, Ry, Megaman.colorCondition);
			Ry -= 3;
			Current.specialFlag++;
			napms(40);
		}
		else if (Current.specialFlag >= 20 && Current.specialFlag < 40) {
			Ey = Ry;
			hub_hound_atk1(Ex, Ey);
			Ex -= 15;
			Current.specialFlag++;
			napms(40);
		}
		else if (Current.specialFlag >= 40 && Current.specialFlag < 60) {
			hub_hound_atk1(Ex, Ey);
			Ex += 8;
			Ey += 6;
			Current.specialFlag++;
			napms(40);
		}
		else if (Current.specialFlag >= 60 && Current.specialFlag < 80) {
			hub_hound_atk1(Ex, Ey);
			Ex -= 8;
			Ey += 6;
			Current.specialFlag++;
			napms(40);
		}
		else if (Current.specialFlag >= 80 && Current.specialFlag < 100) {
			hub_hound_sp(Ex, Ey);
			megaman(Rx, Ry, Megaman.colorCondition);
			if (Ey >= Ry) {
				Ry += 6;
			}
			Ey += 6;
			Current.specialFlag++;
			napms(40);
		}
		else {
			Megaman.HP -= Current.ATK * 5;
			SPx = 10, SPy = 0;
			Current.specialFlag = 0;
			Current.specialLimit = 0;
			set_Enemy_place();		//�G�̏ꏊ�����Ƃ̈ʒu��
			set_Megaman_place();	//���K�}���̏ꏊ�����Ƃ̈ʒu��
		}
	}
	//�X�e�[�W�U�@ice_demon�̕K�E�Z�i�������j
	else if (stageflag == 6) {
		Current.specialFlag = 0;
		Current.specialLimit = 0;
	}

}

//�K�E�Z�I��----------------------------------------------------------------------------------

//�����蔻��p�֐�----------------------------------------------------------------------------

//�G�̍U���̓����蔻��
bool attack_hit(int WxR, int WxL) {

	//�Z�̂����W�̉E�[�ƍ��[�����K�}���̈ʒu�ɂ��Ԃ��true��HP��G�̍U�������炷
	if (Current.reverse == 0) {
		if (((WxL <= Rx + Megaman.width && WxL >= Rx) || (WxR <= Rx + Megaman.width && WxR >= Rx)) && (Wy >= Ry - Megaman.height && Wy <= Ry)) {

			Megaman.HP -= Current.ATK;

			return true;
		}
		else {
			return false;
		}
	}
	else if (Current.reverse == 1) {
		if (((WxL <= Rx + Megaman.width && WxL >= Rx) || (WxR <= Rx + Megaman.width && WxR >= Rx)) && (Wy >= Ry - Megaman.height && Wy <= Ry)) {

			Megaman.HP -= Current.ATK;

			return true;
		}
		else {
			return false;
		}
	}
}

//�����蔻��p�֐��I��-------------------------------------------------------------------------

//����h���b�v�p�֐�---------------------------------------------------------------------------

//���헎�Ƃ����
void drop_weapon() {

	int dx = YOKOCELL / 2, dy = 50;
	int cnt = 0;

	//�ォ�痎�Ƃ�
	while (dy < TATECELL) {
		erase();
		E_weapon(dx, dy, 1);
		dy += 2;
		megaman(Rx, Ry, Megaman.colorCondition);
		refresh();
		napms(20);
	}

	//���K�}��������Ƃ�܂Ń��[�v
	while (1) {
		erase();

		if (cnt % 1000 <= 500) {
			E_weapon(dx, dy, 1);
		}
		else if (cnt % 1000 > 500) {
			E_weapon(dx, dy, 2);
		}
		mega_move();
		draw_megaman(Megaman);

		if (Megaman.jampFlag > 0 || Megaman.moveFlag > 0) {
			cnt += 50;
		}

		refresh();
		cnt++;

		if ((Rx + Megaman.width >= dx && Rx <= dx + 13) && (Ry <= dy && Ry > dy - 13)) {
			break;
		}
	}
}

//����h���b�v�p�֐��I��-----------------------------------------------------------------------

//�����蔻��𐧌�����֐�-------------------------------------------------------------------

void hit_limit(int WxR, int WxL, int chara_select) {

	//chara_select = 0�@�Ȃ�G�̓����蔻��A�����łȂ��Ȃ烁�K�}���̔���
	if (chara_select == 0 && hit_count == 0) {
		if (attack_hit(WxR, WxL) == true) {
			hit_count++;
		}
	}
	else if(chara_select == 1 && hit_count == 0){
		if (mega_attack_hit() == true) {
			hit_count++;
		}
	}
	
	//��x�����蔻�肳���ƃJ�E���g
	if (hit_count > 0) {
		hit_count++;
	}

	//�G�ƃ��K�}���̂��ꂼ��ň��ʃJ�E���g�����ƃJ�E���g��0��
	if (hit_count > 100 && chara_select == 0) {
		hit_count = 0;
	}
	else if (hit_count > 15000 && chara_select == 1) {
		hit_count = 0;
	}

	//���K�}�����s��������J�E���g��0��
	if (Megaman.jampFlag > 0 && chara_select == 1) {
		hit_count = 0;
	}

}

//�����蔻��𐧌�����p�֐��I��----------------------------------------------------------------
