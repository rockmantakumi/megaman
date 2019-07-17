#pragma once

#include "stdafx.h"
#include <curses.h>

#define CHARBUFF 124

void water(int wx, int wy);
void reverse_water(int wx, int wy);

//elect‚Ì•`‰æ—p
void elect(int ex, int ey);
void reverse_elect(int ex, int ey);
void elect_jamp(int ex, int ey);
void reverse_elect_jamp(int ex, int ey);
void elect_move(int ex, int ey);
void reverse_elect_move(int ex, int ey);
void elect_atkmove(int ex, int ey);
void reverse_elect_atkmove(int ex, int ey);
void elect_atk1(int ex, int ey);
void reverse_elect_atk1(int ex, int ey);
void elect_atk2(int ex, int ey);
void elect_spmove1(int ex, int ey);
void elect_spmove2(int ex, int ey);
void elect_sp(int ex, int ey);

void E_weapon(int Ex, int Ey, int color_num);

//heat‚Ì•`‰æ—p
void heat_half(int hx, int hy);
void heat_atkmove_half(int hx, int hy);
void heat(int hx, int hy);
void reverse_heat(int hx, int hy);
void heat_atkmove(int hx, int hy);
void reverse_heat_atkmove(int hx, int hy);
void heat_atk2(int hx, int hy);
void heat_atk1(int hx, int hy);
void reverse_heat_atk1(int hx, int hy);


//hub_hound‚Ì•`‰æ—p
void hub_hound(int hbx, int hby);
void reverse_hub_hound(int hbx, int hby);
void hub_hound_move(int hbx, int hby);
void reverse_hub_hound_move(int hbx, int hby);
void hub_hound_atk1(int hbx, int hby);
void reverse_hub_hound_atk1(int hbx, int hby);
void hub_hound_sp(int hbx, int hby);

//ice_demon‚Ì•`‰æ—p
void ice_demon(int ix, int iy);
void reverse_ice_demon(int ix, int iy);
void ice_demon_move(int ix, int iy);
void reverse_ice_demon_move(int ix, int iy);
void ice_demon_atkmove(int ix, int iy);
void reverse_ice_demon_atkmove(int ix, int iy);
void ice_demon_atk2(int ix, int iy);
void reverse_ice_demon_atk2(int ix, int iy);

