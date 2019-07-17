#include "stdafx.h"
#include "enemy_action.h"
#include "draw_enemy.h"
#include "draw_mega.h"
#include "Mega_action.h"
#include "Stage.h"


int Ex = 0, Ey = 0;	//敵の各座標
int Wx = 0, Wy = 0;	//敵の技の座標
int SPx = 10, SPy = 0;	//敵の必殺技座標

int attackNum = 0;	//攻撃回数用カウンタ
int jampX[2];	//ジャンプするときの敵とメガマンのｘ座標保存用

int hit_count = 0;	//当たり判定の制限用カウンタ

Enemy Elect;	//stage1
Enemy Heat;		//stage2
Enemy Hub_hound;//stage3
Enemy Ice_demon;//stage6
Enemy Current;	//現在のキャラの構造体名


//敵の初期位置設定
void set_Enemy_place() {
	Ex = 400, Ey = TATECELL;
}


//敵のステータスを設定
void set_Enemy_status(int stageNum) {

	Ex = 400, Ey = TATECELL;	//敵の各座標

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

	Current.reverse = 0;	//反転用フラグ
	Current.jampFlag = 0;	//ジャンプ用フラグ
	Current.moveFlag = 0;	//移動用フラグ
	Current.attackFlag = 0;	//攻撃用フラグ
	Current.specialFlag = 0;	//必殺技用フラグ
	Current.specialLimit = 1;	//必殺技使用制限用フラグ
	Current.attackLimit = 3;	//攻撃回数制限用フラグ
	attackNum = 0;	//攻撃回数用カウンタ
}

//enemyの描画（reverse:進行方向の判定 jamp:ジャンプの判定 move:移動の判定 atk:攻撃の判定)
//reserveは0なら敵が左向き、1なら右向き
//jampFlagは1ならジャンプ
//moveFlagは1なら移動(stageNum == 6　のときのみ1以上で移動)
//attackFlagは1以上なら攻撃
//敵の描画
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


//ここから敵の行動-------------------------------------------------------------------------------------

//敵とメガマンの距離を測る
int DistanceEtoR() {
	int Distance = Ex - Rx;
	return Distance;
}

//敵の行動を選択----------------------------------------------------------------------------------------
void Enemy_action() {
	int Distance = 0;
	Distance = DistanceEtoR();

	//行動中でないなら、距離によって方向を判断
	if (Distance > 0 && (Current.jampFlag == 0 && Current.moveFlag == 0 && Current.attackFlag == 0)) {
		Current.reverse = 0;
	}
	else if (Distance < 0 && (Current.jampFlag == 0 && Current.moveFlag == 0 && Current.attackFlag == 0)) {
		Current.reverse = 1;
	}

	//新しい行動判定
	if (Current.specialLimit > 0 && (Current.specialFlag > 0 || Current.HP <= 5 && Current.jampFlag == 0)) {

		Enemy_DB();

	}
	else {
		//攻撃判定　new
		if (Current.attackLimit == 0 && Current.jampFlag == 0 && Current.moveFlag == 0) {
			Wx = Ex, Wy = Ey;	//技を表示させる最初の座標を敵の座標にする
			if (Distance > 120) {
				Current.attackFlag = 1;
			}
			else {
				Current.attackFlag = 2;
			}
			Current.attackLimit = 1;
		}
		//ジャンプ判定と移動判定 new
		else if ((Distance > 250 || Distance < -250) && Current.attackFlag == 0 && Current.jampFlag == 0 && Current.moveFlag == 0) {
			Current.jampFlag = 1;
			jampX[0] = Ex, jampX[1] = Rx;	//ジャンプ時の敵とメガマンのx座標保存(jampX[0]:敵 jampX[1]:メガマン)
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
//敵の行動選択終了----------------------------------------------------------------------------------------------------------------------------


//敵の移動用関数------------------------------------------------------------------------------

//敵を右に動かす
void Enemy_moveR() {

	//ステージ６でないとき
	if (stageflag != 6) {

		//敵のスピードぶんだけ座標移動
		Ex += Current.speed;

		//距離が120以内なら終了
		if (DistanceEtoR() > -120) {
			Current.moveFlag = 0;
		}

		//右端に来たらそこで移動終了
		if (Ex > YOKOCELL) {
			Ex = YOKOCELL - Current.width;
			Current.moveFlag = 0;
		}
	}
	//ステージが6のとき
	else if (stageflag == 6) {

		//Current.moveFlagが500未満ならその場で待機
		if (Current.moveFlag < 500) {
			Ex = Ex;
		}
		//Current.moveFlagが一定値内になると敵のすぐそばに瞬間移動
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

		//敵の移動中は処理速度が遅くなるため、moveFlagのカウントを早める
		if (Current.moveFlag > 0 || Current.jampFlag > 0) {
			if (Current.moveFlag > 495 && Current.moveFlag < 500) {
				Current.moveFlag = 500;
			}
			else {
				Current.moveFlag += 5;
			}
		}

		//moveFlagが2000を超えると移動終了
		if (Current.moveFlag > 2000) {
			Current.moveFlag = 0;
			Current.attackLimit = 0;
		}
	}
}

//敵を左に動かす(内容は右への移動と同じなので説明は割愛)
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

//敵の移動用関数終了-------------------------------------------------------------------------

//敵のジャンプ用関数-------------------------------------------------------------------------
//敵をジャンプさせる(1なら左向きに、2なら右向きに)
void Enemy_jamp() {

	if (stageflag != 6) {
		if (Current.reverse == 0) {

			//ジャンプ中の敵のx座標が、ジャンプ開始時の敵とメガマンの距離の中点になるまで上昇
			//中点にたどりつくと下降
			if (Ex > (jampX[1] + (jampX[0] - jampX[1]) / 2)) {
				Ey -= 1;
			}
			else {
				Ey += 1;
			}

			//ジャンプ中に進行方向にも進む
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

		//ジャンプの高さ上限のy座標を30とする
		if (Ey < 30) {
			Ey = 30;
		}

		//現在の敵の位置が下に到達すればジャンプ終了
		if (Ey == TATECELL) {
			Current.jampFlag = 0;
		}

		//現在の位置が画面の端なら強制的に終了
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
	//ステージ6の敵はジャンプせずに瞬間移動する
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
//敵のジャンプ用関数終了----------------------------------------------------------------------


//敵の攻撃用関数------------------------------------------------------------------------------

//敵の攻撃を選択
void Enemy_attack() {
	if (Current.attackFlag == 1) {
		Enemy_atk1();
	}
	else if (Current.attackFlag == 2) {
		Enemy_atk2();
	}
}

//攻撃１
void Enemy_atk1() {

	//stage1または2敵の攻撃
	if (stageflag == 1 || stageflag == 2) {

		//技の進行は、一度でx座標を5進む
		if (Current.reverse == 0) {

			//それぞれの敵の技を表示
			if (stageflag == 1) {
				elect_atk1(Wx, Wy);
			}
			else if (stageflag == 2) {
				heat_atk1(Wx, Wy);
			}

			//処理速度が速いため、座標移動を遅延
			if (attackNum % 10 == 0) {
				Wx -= 1;

				//メガマンの移動中はワザの速度を上げる
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

				//メガマンの移動中はワザの速度を上げる
				if (Megaman.moveFlag >= 1) {
					Wx += 5;
				}
			}

		}

		attackNum++;

		//攻撃がメガマンに当たるか、端まで行けば終わり
		if (attack_hit(Wx, Wx) == true) {
			Wx = Ex;
		}
		else if (Wx < 3 || Wx > YOKOCELL - 24) {
			Wx = Ex;
		}

		//攻撃1は連続で2回行う
		if (attackNum / 1000 == 2) {
			Current.attackFlag = 0;
			attackNum = 0;
		}
	}
	//stage3の敵の攻撃用
	else if (stageflag == 3) {

		//敵が左向き
		if (Current.reverse == 0) {

			//攻撃１を描画
			hub_hound_atk1(Ex, Ey);

			//攻撃の移動速度は3
			Ex -= 3;

			//メガマンの移動中はワザの速度を上げる
			if (Megaman.jampFlag >= 1 || Megaman.moveFlag >= 1) {
				Ex -= 3;
			}

			//当たり判定
			Wx = Ex, Wy = Ey - 12;
			hit_limit(Wx + 48, Wx, 0);

		}
		//敵が右向き
		else if (Current.reverse == 1) {

			//攻撃１を描画
			reverse_hub_hound_atk1(Ex, Ey);

			//攻撃の移動速度は3
			Ex += 3;

			//メガマンの移動中はワザの速度を上げる
			if (Megaman.jampFlag >= 1 || Megaman.moveFlag >= 1) {
				Ex += 3;
			}

			//当たり判定
			Wx = Ex, Wy = Ey - 12;
			hit_limit(Wx + 48, Wx, 0);

		}

		//左端または右端まで到達すると、攻撃回数を１カウントして敵の向きを反転
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

		//攻撃1は連続で2回行う
		if (attackNum == 2) {
			Current.attackFlag = 0;
			attackNum = 0;
		}
	}
	//ステージ6は攻撃１ないので移動させる
	else if (stageflag == 6) {
		Current.attackFlag = 0;
		Current.moveFlag = 1;
	}

}

//攻撃２
void Enemy_atk2() {

	//stage1または2敵の攻撃
	if (stageflag == 1 || stageflag == 2) {

		//敵が左向き
		if (Current.reverse == 0) {

			//800で割り切れる時に攻撃（処理速度との調整）（攻撃は一度でｘ座標50ずつ移動）
			if (attackNum % 800 == 0) {
				Wx = Wx -= 50;
			}

			//敵ごとの攻撃を表示
			if (stageflag == 1) {
				elect_atk2(Wx, Wy);
			}
			else if (stageflag == 2) {
				heat_atk2(Wx, Wy);
			}

		}
		//敵が右向き
		else if (Current.reverse == 1) {

			//800で割り切れる時に攻撃（処理速度との調整）（攻撃は一度でｘ座標50ずつ移動）
			if (attackNum % 800 == 0) {
				Wx = Wx += 50;
			}

			//敵ごとの攻撃を表示
			if (stageflag == 1) {
				elect_atk2(Wx, Wy);
			}
			else if (stageflag == 2) {
				heat_atk2(Wx, Wy);
			}
		}

		//敵の行動中は処理が遅くなるのでattackNumの追加量を増やす
		if (Megaman.jampFlag >= 1 || Megaman.moveFlag >= 1) {
			attackNum += 50;
		}

		//攻撃が端まで行けば終わり
		if (Wx < 3) {
			Wx = Ex;
		}
		else if (Wx > YOKOCELL - 30) {
			Wx = Ex + Current.width;
		}

		//当たり判定は技が表示されたときのみ
		if (attackNum % 800 == 0) {
			if (Current.reverse == 0) {
				hit_limit(Wx + 24, Wx, 0);
			}
			else if (Current.reverse == 1) {
				hit_limit(Wx - 24, Wx, 0);
			}

		}

		attackNum++;

		//攻撃2は連続で3回行う
		if (attackNum / 800 == 3) {
			Current.attackFlag = 0;
			attackNum = 0;
		}
	}
	//stage3は攻撃２なし
	else if (stageflag == 3) {
		Current.attackFlag = 0;
	}
	//stage6の敵の攻撃
	else if (stageflag == 6) {

		//敵が左向き
		if (Current.reverse == 0) {

			//attackNumが1000未満の時技を表示（一定時間表示させるため）
			if (attackNum < 1000) {

				//敵の場所によって技の場所変更（技が画面外に行かないようにする）（44は技の幅）
				if (Rx > Current.width + 50) {
					ice_demon_atk2(Wx - 44 - 30, Wy);

					//描画されてカウントが500まで当たり判定あり
					if (attackNum > 500) {
						hit_limit(Wx - 30, Wx - 44 - 30, 0);
					}

				}
				else {
					ice_demon_atk2(Rx, Wy);

					//描画されてカウントが500まで当たり判定あり
					if (attackNum > 500) {
						hit_limit(Rx + 44, Rx, 0);
					}

				}

			}
		}
		//敵が右向き
		else if (Current.reverse == 1) {

			if (attackNum < 1000) {

				//敵の場所によって技の場所変更（技が画面外に行かないようにする）（44は技の幅）
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

		//attackNumが1000を超えると攻撃終了して移動
		if (attackNum > 1000) {
			Current.attackFlag = 0;
			attackNum = 0;
			Current.moveFlag = 1;
			Current.attackLimit = 0;
		}
	}

}

//敵の攻撃用関数終了--------------------------------------------------------------------------


//必殺技--------------------------------------------------------------------------------------

void Enemy_DB() {
	int cnt = 0;

	//メガマンの行動を停止
	Megaman.attackFlag = 0;
	Megaman.jampFlag = 0;
	Megaman.moveFlag = 0;

	//ステージ１　electの必殺技
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
		//でっかい雷落とす
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
			set_Enemy_place();		//敵の場所をもとの位置に
			set_Megaman_place();	//メガマンの場所をもとの位置に
		}
	}
	//ステージ２　heatの必殺技（未実装）
	else if (stageflag == 2) {
		Current.specialFlag = 0;
		Current.specialLimit = 0;
	}
	//ステージ３　hub_houndの必殺技
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
			set_Enemy_place();		//敵の場所をもとの位置に
			set_Megaman_place();	//メガマンの場所をもとの位置に
		}
	}
	//ステージ６　ice_demonの必殺技（未実装）
	else if (stageflag == 6) {
		Current.specialFlag = 0;
		Current.specialLimit = 0;
	}

}

//必殺技終了----------------------------------------------------------------------------------

//当たり判定用関数----------------------------------------------------------------------------

//敵の攻撃の当たり判定
bool attack_hit(int WxR, int WxL) {

	//技のｘ座標の右端と左端がメガマンの位置にかぶるとtrueでHPを敵の攻撃分減らす
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

//当たり判定用関数終了-------------------------------------------------------------------------

//武器ドロップ用関数---------------------------------------------------------------------------

//武器落とすやつ
void drop_weapon() {

	int dx = YOKOCELL / 2, dy = 50;
	int cnt = 0;

	//上から落とす
	while (dy < TATECELL) {
		erase();
		E_weapon(dx, dy, 1);
		dy += 2;
		megaman(Rx, Ry, Megaman.colorCondition);
		refresh();
		napms(20);
	}

	//メガマンが武器とるまでループ
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

//武器ドロップ用関数終了-----------------------------------------------------------------------

//当たり判定を制限する関数-------------------------------------------------------------------

void hit_limit(int WxR, int WxL, int chara_select) {

	//chara_select = 0　なら敵の当たり判定、そうでないならメガマンの判定
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
	
	//一度当たり判定されるとカウント
	if (hit_count > 0) {
		hit_count++;
	}

	//敵とメガマンのそれぞれで一定量カウントされるとカウントを0に
	if (hit_count > 100 && chara_select == 0) {
		hit_count = 0;
	}
	else if (hit_count > 15000 && chara_select == 1) {
		hit_count = 0;
	}

	//メガマンが行動したらカウントを0に
	if (Megaman.jampFlag > 0 && chara_select == 1) {
		hit_count = 0;
	}

}

//当たり判定を制限する用関数終了----------------------------------------------------------------
