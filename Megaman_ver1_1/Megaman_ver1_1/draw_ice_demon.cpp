
//stage6�̓G�̕`��pcpp

#include "stdafx.h"
#include "draw_enemy.h"

//ice_demon�̕`��p
int draw_ice_demon[32][25] = { { 0,0,0,0,0,0,0,0,0,0,0,8,8,0,0,0,8,8,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,8,2,8,0,0,8,2,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,8,2,8,0,0,8,2,8,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,8,2,8,0,0,8,2,8,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,8,2,2,8,0,8,2,2,8,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,2,2,2,8,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,8,1,1,2,2,2,2,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,8,1,1,1,1,2,2,8,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,8,1,1,3,1,1,1,8,8,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,8,1,3,1,1,7,8,1,1,8,8,0,0,0,0,0 },
{ 0,0,8,0,0,0,8,0,0,8,1,1,7,7,7,8,1,1,1,1,8,0,0,0,0 },
{ 0,8,2,8,0,8,2,8,0,0,8,7,7,7,8,8,1,1,1,1,8,0,0,0,0 },
{ 8,2,8,0,8,2,8,0,8,0,0,8,7,8,8,1,1,1,1,1,1,8,0,0,0 },
{ 0,8,2,8,8,2,8,8,2,8,0,0,8,0,8,1,1,1,1,1,1,8,0,0,0 },
{ 0,0,8,2,8,1,1,8,8,8,0,0,0,0,8,1,1,1,1,1,1,1,8,0,0 },
{ 0,0,0,8,8,8,1,1,1,8,0,0,0,8,8,1,1,1,1,1,1,1,8,0,0 },
{ 0,0,0,0,0,0,8,8,7,8,0,0,8,7,8,1,1,1,1,1,1,1,8,0,0 },
{ 0,0,0,0,0,0,0,8,7,7,8,8,7,7,8,1,1,1,1,1,1,1,1,8,0 },
{ 0,0,0,0,0,0,0,0,8,7,7,7,7,8,1,1,1,1,1,1,1,1,1,8,0 },
{ 0,0,0,0,0,0,0,0,0,8,8,8,8,8,1,1,1,1,1,1,1,1,1,8,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,8,8,1,1,1,1,1,1,1,1,1,8,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,8,8,1,1,1,1,1,1,1,1,1,1,8,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,1,1,1,1,1,8 },
{ 0,0,0,0,0,0,0,0,0,8,8,1,1,1,1,1,1,1,1,1,1,1,1,1,8 },
{ 0,0,0,0,0,0,0,8,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8 },
{ 0,0,0,0,0,0,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8 },
{ 0,0,0,0,0,0,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8 },
{ 0,0,0,0,0,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8 },
{ 0,0,0,0,0,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8 },
{ 0,0,0,0,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8 },
{ 0,0,0,0,8,1,1,1,1,1,1,1,1,1,8,8,8,8,8,8,8,8,8,8,0 },
{ 0,0,0,0,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0 } };

//ice_demon�̈ړ��p�̕`��p
int draw_ice_demon_move[32][25] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,8,8,0,0,0,8,8,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,8,7,8,0,0,8,7,8,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,8,7,8,0,0,8,7,8,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,8,7,8,0,0,8,7,8,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,8,7,7,8,0,8,7,7,8,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,7,7,7,8,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,8,7,7,7,7,7,7,8,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,8,7,7,7,7,7,7,8,8,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,8,7,7,3,7,7,7,8,8,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,8,7,3,7,7,7,8,7,7,8,8,0,0,0,0,0 },
	{ 0,0,8,0,0,0,8,0,0,8,7,7,7,7,7,8,7,7,7,7,8,0,0,0,0 },
	{ 0,8,7,8,0,8,7,8,0,0,8,7,7,7,8,8,7,7,7,7,8,0,0,0,0 },
	{ 8,7,8,0,8,7,8,0,8,0,0,8,7,8,8,7,7,7,7,7,7,8,0,0,0 },
	{ 0,8,7,8,8,7,8,8,7,8,0,0,8,0,8,7,7,7,7,7,4,8,0,0,0 },
	{ 0,0,8,7,8,7,7,8,8,8,0,0,0,0,8,7,7,7,7,4,7,4,8,0,0 },
	{ 0,0,0,8,8,8,7,7,7,8,0,0,0,8,8,7,7,7,7,7,4,4,8,0,0 },
	{ 0,0,0,0,0,0,8,8,7,8,0,0,8,7,8,7,7,7,7,4,7,4,8,0,0 },
	{ 0,0,0,0,0,0,0,8,7,7,8,8,7,7,8,7,7,7,7,7,4,7,4,8,0 },
	{ 0,0,0,0,0,0,0,0,8,7,7,7,7,8,7,7,7,7,7,4,7,4,4,8,0 },
	{ 0,0,0,0,0,0,0,0,0,8,8,8,8,8,7,7,7,7,7,7,4,7,4,8,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,8,8,7,7,7,7,7,4,7,4,4,8,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,8,8,1,7,7,7,7,7,7,4,7,4,8,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,8,1,1,7,7,7,7,7,4,7,4,7,4,8 },
	{ 0,0,0,0,0,0,0,0,0,8,8,1,7,1,7,7,7,7,7,7,4,7,7,4,8 },
	{ 0,0,0,0,0,0,0,8,8,1,1,7,1,7,7,7,7,7,7,4,7,4,4,4,8 },
	{ 0,0,0,0,0,0,8,1,1,7,7,1,7,7,7,7,7,7,4,7,4,7,4,4,8 },
	{ 0,0,0,0,0,0,8,1,1,1,1,7,1,7,7,7,7,7,7,4,7,4,4,4,8 },
	{ 0,0,0,0,0,8,1,1,7,1,7,1,7,7,7,7,7,7,4,7,4,7,4,4,8 },
	{ 0,0,0,0,0,8,1,7,1,7,1,7,7,7,7,7,7,4,7,4,7,4,4,4,8 },
	{ 0,0,0,0,8,1,1,1,7,1,1,7,7,7,7,7,4,7,4,4,4,4,4,4,8 },
	{ 0,0,0,0,8,1,1,1,1,1,7,1,7,7,8,8,8,8,8,8,8,8,8,8,0 },
	{ 0,0,0,0,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0 } };

//ice_demon�̍U�����̕`��p
int draw_ice_demon_atkmove[32][31] = { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,1,1,1,1,1,8,8,8,8,0,0,0,0,0,0 },
{ 0,0,8,8,0,0,0,8,8,0,0,8,8,8,1,1,1,1,1,1,1,1,1,1,8,8,8,0,0,0,0 },
{ 0,0,8,2,8,0,0,8,2,8,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,8,0,0,0 },
{ 0,0,0,8,2,8,0,0,8,2,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,8,0 },
{ 0,0,0,8,2,8,0,0,8,2,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,8 },
{ 0,0,8,2,2,8,0,8,2,2,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8 },
{ 0,0,8,8,8,8,8,2,2,2,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8 },
{ 0,0,8,1,1,2,2,2,2,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8 },
{ 0,8,1,1,1,1,2,2,8,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8 },
{ 8,1,1,3,1,1,1,8,8,1,1,1,1,8,8,8,8,8,8,8,8,1,1,1,1,1,1,1,1,1,8 },
{ 8,1,3,1,1,7,7,8,1,8,8,8,8,1,1,1,1,1,1,8,0,8,8,1,1,1,1,1,1,1,8 },
{ 8,1,1,8,8,7,7,8,8,8,1,1,8,8,1,1,1,1,1,8,8,0,0,8,8,1,1,1,1,1,8 },
{ 8,8,8,0,0,8,7,8,7,7,7,7,1,1,8,8,7,1,1,1,8,8,0,0,8,8,1,1,1,1,8 },
{ 0,0,0,0,0,8,7,8,8,7,7,7,7,7,1,8,8,8,7,1,1,1,8,0,0,8,1,1,1,1,8 },
{ 0,0,0,0,8,7,8,0,0,8,8,8,8,8,7,7,1,8,8,7,1,1,8,8,0,8,8,1,1,1,8 },
{ 0,0,0,0,0,8,0,0,0,0,0,0,0,8,8,8,7,1,1,8,7,1,1,8,0,0,8,1,1,1,8 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1,8,7,7,1,8,7,1,8,0,0,0,8,1,1,8 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,8,1,1,7,8,7,7,1,8,1,1,8,0,0,8,1,1,8 },
{ 0,0,0,0,0,0,0,0,0,0,0,8,8,1,1,7,7,7,8,8,7,8,7,1,8,8,0,0,8,1,8 },
{ 0,0,0,0,0,0,0,0,0,0,8,8,1,1,7,7,7,7,7,8,1,1,8,8,2,8,0,0,8,1,8 },
{ 0,0,0,0,0,0,0,0,0,8,8,1,1,7,7,7,7,8,8,8,1,1,1,8,2,8,0,0,8,8,8 },
{ 0,0,0,0,0,0,0,0,0,8,1,1,7,7,7,7,8,0,8,1,1,1,8,2,8,2,8,0,8,8,0 },
{ 0,0,0,0,0,0,0,0,0,8,1,7,7,7,8,8,8,8,2,8,1,8,8,8,2,2,8,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,8,1,7,7,8,8,0,0,0,8,2,8,8,7,8,2,8,8,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,8,1,1,8,8,8,0,0,0,0,8,8,0,8,8,8,7,1,8,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,8,8,8,7,8,0,0,0,0,0,0,0,0,8,7,7,1,8,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0,8,7,8,0,0,0,0,0,0,0,0,0,8,8,8,8,8,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,8,8,8,7,8,0,0,0,0,0,0,0,0,0,0,0,8,7,8,0,0 },
{ 0,0,0,0,0,0,0,0,0,8,8,8,7,7,8,0,0,0,0,0,0,0,0,0,8,8,8,7,8,0,0 },
{ 0,0,0,0,0,0,0,0,0,8,2,2,2,8,8,0,0,0,0,0,0,0,0,0,8,2,2,7,8,0,0 },
{ 0,0,0,0,0,0,0,0,0,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,0,0 } };

//ice_demon�̍U���Q�̕`��p
int draw_ice_demon_atk2[36][44] = { { 0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,8,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,8,1,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,8,1,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,8,1,1,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,8,1,1,7,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,1,1,7,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,8,1,1,7,7,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,8,1,1,7,7,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,8,1,1,7,7,7,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,8,1,1,7,7,7,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,8,1,1,7,7,7,7,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,8,1,1,7,7,7,7,4,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,8,0,0,0,0,0,0,0,0,8,1,1,1,7,7,7,7,4,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 8,7,8,0,0,0,0,0,0,0,0,8,1,1,7,7,7,7,4,4,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 8,7,7,8,0,0,0,0,0,0,0,8,1,1,1,7,7,7,7,4,4,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,8,7,7,8,0,0,0,0,0,0,0,8,1,1,7,7,7,7,7,4,4,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,8,1,7,7,8,0,0,0,0,0,0,8,1,1,1,7,7,7,7,4,4,4,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,8,1,7,7,7,8,0,0,0,0,0,0,8,1,1,1,7,7,7,7,4,4,4,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,8,1,7,7,7,8,0,0,0,0,0,8,1,1,1,7,7,7,7,4,4,4,4,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,8,1,7,7,7,7,8,0,0,0,0,0,8,1,1,1,7,7,7,7,4,4,4,4,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,8,1,7,7,7,7,7,8,0,0,0,0,8,1,1,1,1,7,7,7,7,4,4,4,4,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,8,1,7,7,7,7,7,8,0,0,0,0,8,1,1,1,1,1,7,7,7,4,4,4,4,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,8,1,7,7,7,7,7,4,8,0,0,0,8,1,1,1,1,7,7,7,7,7,4,4,4,4,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,8,1,1,7,7,7,7,7,4,8,0,0,0,8,1,1,1,1,1,7,7,7,4,4,4,4,4,8,0,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,8,1,1,7,7,7,7,7,4,4,8,0,0,8,1,1,1,1,7,1,7,7,4,4,4,4,4,4,8,0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,8,1,1,1,7,7,7,4,4,4,8,0,0,8,1,1,1,1,1,7,7,7,4,4,4,4,4,4,8,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,8,1,1,1,1,7,7,7,4,4,4,8,0,8,1,1,1,1,7,1,7,7,7,4,4,4,4,4,4,8,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,8,1,1,1,7,1,7,7,4,7,4,4,8,0,8,1,1,1,1,7,1,7,7,7,4,4,4,4,4,4,8,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,8,1,1,1,1,7,1,7,7,4,7,4,4,8,8,1,1,1,1,1,1,1,7,4,7,4,7,4,4,4,4,8,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,8,1,1,7,1,7,7,7,7,4,7,4,4,4,8,1,1,1,1,1,7,1,7,4,7,4,7,4,4,4,4,8,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,8,1,1,1,7,1,7,7,4,7,4,7,4,4,8,1,1,1,1,7,1,7,1,7,4,7,4,7,4,4,4,4,8,0,0,0,0,0,0 },
{ 0,0,0,0,0,8,1,1,1,1,7,1,7,7,4,7,4,7,4,4,8,1,1,1,1,1,1,7,1,7,4,7,4,7,4,7,4,4,8,0,0,0,0,0 },
{ 0,0,0,0,0,8,1,1,1,7,1,7,1,7,7,4,7,4,7,4,8,1,1,1,1,7,7,1,1,7,7,4,7,4,7,4,7,4,7,8,0,0,0,0 },
{ 0,0,0,0,0,0,8,1,1,1,7,1,7,1,4,7,4,7,4,7,4,8,1,1,1,1,1,7,1,1,4,7,4,7,4,7,4,7,4,7,8,0,0,0 },
{ 0,0,0,0,0,0,8,1,1,1,1,7,1,7,1,4,7,4,7,4,7,8,8,1,1,1,1,1,1,7,1,7,7,7,7,7,7,7,7,7,7,8,0,0 } };



//ice_demon�̕`��
void ice_demon(int ix, int iy) {
	for (int y = 31; y >= 0; y--) {
		for (int x = 0; x < 25; x++) {
			if (draw_ice_demon[y][x] != 0) {
				if (draw_ice_demon[y][x] == 8) {
					attrset(COLOR_PAIR(8));
				}
				else {
					attrset(COLOR_PAIR(draw_ice_demon[y][x]) | A_REVERSE | A_BOLD);
				}
				mvaddstr(iy - (31 - y), ix + x, " ");
			}
		}
	}
}


void reverse_ice_demon(int ix, int iy) {
	for (int y = 31; y >= 0; y--) {
		for (int x = 0; x < 25; x++) {
			if (draw_ice_demon[y][x] != 0) {
				if (draw_ice_demon[y][x] == 8) {
					attrset(COLOR_PAIR(8));
				}
				else {
					attrset(COLOR_PAIR(draw_ice_demon[y][x]) | A_REVERSE | A_BOLD);
				}
				mvaddstr(iy - (31 - y), ix + (24 - x), " ");
			}
		}
	}
}

//ice_demon�̈ړ����̕`��
void ice_demon_move(int ix, int iy) {
	for (int y = 31; y >= 0; y--) {
		for (int x = 0; x < 25; x++) {
			if (draw_ice_demon_move[y][x] != 0) {
				if (draw_ice_demon_move[y][x] == 8) {
					attrset(COLOR_PAIR(8));
				}
				else {
					attrset(COLOR_PAIR(draw_ice_demon_move[y][x]) | A_REVERSE | A_BOLD);
				}
				mvaddstr(iy - (31 - y), ix + x, " ");
			}
		}
	}
}

void reverse_ice_demon_move(int ix, int iy) {
	for (int y = 31; y >= 0; y--) {
		for (int x = 0; x < 25; x++) {
			if (draw_ice_demon_move[y][x] != 0) {
				if (draw_ice_demon_move[y][x] == 8) {
					attrset(COLOR_PAIR(8));
				}
				else {
					attrset(COLOR_PAIR(draw_ice_demon_move[y][x]) | A_REVERSE | A_BOLD);
				}
				mvaddstr(iy - (31 - y), ix + (24 - x), " ");
			}
		}
	}
}

//ice_demon�̍U�����̕`��
void ice_demon_atkmove(int ix, int iy) {
	for (int y = 31; y >= 0; y--) {
		for (int x = 0; x < 31; x++) {
			if (draw_ice_demon_atkmove[y][x] != 0) {
				if (draw_ice_demon_atkmove[y][x] == 8) {
					attrset(COLOR_PAIR(8));
				}
				else {
					attrset(COLOR_PAIR(draw_ice_demon_atkmove[y][x]) | A_REVERSE | A_BOLD);
				}
				mvaddstr(iy - (31 - y), ix + x, " ");
			}
		}
	}
}

void reverse_ice_demon_atkmove(int ix, int iy) {
	for (int y = 31; y >= 0; y--) {
		for (int x = 0; x < 31; x++) {
			if (draw_ice_demon_atkmove[y][x] != 0) {
				if (draw_ice_demon_atkmove[y][x] == 8) {
					attrset(COLOR_PAIR(8));
				}
				else {
					attrset(COLOR_PAIR(draw_ice_demon_atkmove[y][x]) | A_REVERSE | A_BOLD);
				}
				mvaddstr(iy - (31 - y), ix + (30 - x), " ");
			}
		}
	}
}

//ice_demon�̍U���Q�̕`��
void ice_demon_atk2(int ix, int iy) {
	for (int y = 35; y >= 0; y--) {
		for (int x = 0; x < 44; x++) {
			if (draw_ice_demon_atk2[y][x] != 0) {
				if (draw_ice_demon_atk2[y][x] == 8) {
					attrset(COLOR_PAIR(8));
				}
				else {
					attrset(COLOR_PAIR(draw_ice_demon_atk2[y][x]) | A_REVERSE | A_BOLD);
				}
				mvaddstr(iy - (35 - y), ix + x, " ");
			}
		}
	}
}

void reverse_ice_demon_atk2(int ix, int iy) {
	for (int y = 35; y >= 0; y--) {
		for (int x = 0; x < 44; x++) {
			if (draw_ice_demon_atk2[y][x] != 0) {
				if (draw_ice_demon_atk2[y][x] == 8) {
					attrset(COLOR_PAIR(8));
				}
				else {
					attrset(COLOR_PAIR(draw_ice_demon_atk2[y][x]) | A_REVERSE | A_BOLD);
				}
				mvaddstr(iy - (35 - y), ix + (43 - x), " ");
			}
		}
	}
}