#include "stdafx.h"
#include "draw_mega.h"

int draw_megaman[24][21] = {//�ʏ펞�̃��K�}��
	{ 0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,8,8,8,7,7,8,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,8,1,1,1,8,7,7,8,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,8,1,1,1,1,1,8,8,8,8,0,0,0,0,0 },
	{ 0,0,0,0,0,0,8,1,1,1,1,1,8,7,7,1,8,0,0,0,0 },
	{ 0,0,0,0,0,8,7,1,1,1,1,1,1,8,8,1,8,0,0,0,0 },
	{ 0,0,0,0,0,8,7,1,1,2,4,4,4,1,1,4,8,0,0,0,0 },
	{ 0,0,0,0,0,8,7,1,2,4,4,8,8,2,8,4,8,0,0,0,0 },
	{ 0,0,0,0,0,0,8,1,2,4,4,8,8,2,8,4,8,0,0,0,0 },
	{ 0,0,0,0,0,8,8,1,2,2,4,4,4,2,4,4,8,0,0,0,0 },
	{ 0,0,0,8,8,7,7,8,2,2,8,8,8,8,2,8,8,8,0,0,0 },
	{ 0,0,8,1,7,7,7,7,8,2,2,2,2,2,8,7,7,1,8,0,0 },
	{ 0,0,8,1,1,7,7,7,7,8,8,8,8,8,7,7,1,1,8,0,0 },
	{ 0,8,1,1,1,7,8,7,7,7,7,7,7,7,8,7,1,1,1,8,0 },
	{ 0,8,1,1,8,8,8,7,7,7,7,7,7,7,8,8,8,1,1,8,0 },
	{ 0,8,1,1,1,8,8,7,7,7,7,7,7,7,8,8,1,1,1,8,0 },
	{ 0,8,1,1,1,8,8,1,1,1,1,1,1,1,8,8,1,1,1,8,0 },
	{ 0,0,8,8,8,0,8,1,1,1,1,1,1,1,8,0,8,8,8,0,0 },
	{ 0,0,0,0,0,8,7,7,1,1,1,1,7,7,7,8,0,0,0,0,0 },
	{ 0,0,0,0,8,1,1,7,7,7,8,7,7,7,7,1,8,0,0,0,0 },
	{ 0,0,0,8,8,1,1,1,7,8,0,8,7,1,1,1,8,8,0,0,0 },
	{ 0,8,8,1,1,1,1,1,8,0,0,0,8,1,1,1,1,1,8,8,0 },
	{ 8,1,1,1,1,1,1,1,8,0,0,0,8,1,1,1,1,1,1,1,8 },
	{ 8,8,8,8,8,8,8,8,8,0,0,0,8,8,8,8,8,8,8,8,8 }
};

int draw_mega_move[22][24] = {//�ړ������K�}��
	{ 0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,8,8,8,7,7,8,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,8,1,1,1,8,7,7,8,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,8,1,1,1,1,1,8,8,8,8,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,8,1,1,1,1,1,8,7,7,1,8,0,0,0,0,0 },
	{ 0,0,0,0,0,8,8,8,7,1,1,1,1,1,1,8,8,1,8,0,0,0,0,0 },
	{ 0,0,0,8,8,7,7,8,7,1,1,2,4,4,4,1,1,4,8,0,0,0,0,0 },
	{ 0,0,8,1,8,7,7,8,7,1,2,4,4,8,8,2,8,4,8,0,0,0,0,0 },
	{ 0,8,1,1,1,8,7,7,8,1,2,4,4,8,8,2,8,4,8,0,8,8,8,0 },
	{ 8,1,1,1,1,8,7,7,8,1,2,2,4,4,4,2,4,2,8,8,1,1,1,8 },
	{ 8,1,1,1,8,0,8,7,7,8,2,2,8,8,8,8,2,8,0,8,1,1,1,8 },
	{ 8,1,1,1,8,0,8,7,7,7,8,2,2,2,2,2,8,7,8,8,1,1,1,8 },
	{ 0,8,8,8,0,0,8,1,7,7,7,8,8,8,8,8,7,7,7,1,1,1,8,0 },
	{ 0,0,0,8,8,0,8,1,1,1,7,7,7,7,7,8,7,7,1,1,1,8,0,0 },
	{ 0,0,8,1,1,8,8,1,1,1,1,1,1,7,8,0,8,7,1,1,8,0,0,0 },
	{ 0,8,1,1,1,1,8,8,1,1,7,7,7,8,0,0,0,8,8,8,0,0,0,0 },
	{ 8,1,1,1,1,1,7,8,8,1,7,7,7,7,8,0,0,0,0,0,0,0,0,0 },
	{ 8,1,1,8,1,1,7,7,7,8,8,7,7,7,1,8,0,0,0,0,0,0,0,0 },
	{ 0,8,8,8,8,1,7,7,8,0,8,1,1,1,1,8,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,8,8,8,0,0,8,1,1,1,8,8,8,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,8,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0 }
};

int draw_mega_jp[30][26] = {//�W�����v�����K�}��
	{ 0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,8,8,0,0,0,0,0,0,8,8,8,7,7,8,0,0,0,0,0,0,8,8,0,0 },
	{ 0,8,1,1,8,0,0,0,0,8,1,1,1,8,7,7,8,0,0,0,0,8,1,1,8,0 },
	{ 8,1,1,1,1,8,0,0,8,1,1,1,1,1,8,8,8,8,0,0,8,1,1,1,1,8 },
	{ 8,1,1,1,8,8,0,0,8,1,1,1,1,1,8,7,7,1,8,0,8,8,1,1,1,8 },
	{ 0,8,1,1,8,1,8,8,7,1,1,1,1,1,1,8,8,1,8,8,1,8,1,1,8,0 },
	{ 0,0,8,1,1,1,1,8,7,1,1,2,4,4,4,1,1,4,8,1,1,1,1,8,0,0 },
	{ 0,0,0,8,1,1,1,8,7,1,2,4,4,8,8,2,8,4,8,7,1,1,8,0,0,0 },
	{ 0,0,0,0,8,1,1,7,8,1,2,4,4,8,8,2,8,4,8,7,7,8,0,0,0,0 },
	{ 0,0,0,0,0,8,7,7,8,1,2,2,4,4,4,2,4,2,8,7,8,0,0,0,0,0 },
	{ 0,0,0,0,0,0,8,7,7,8,2,2,8,8,8,8,2,8,7,8,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,8,7,7,8,2,8,8,8,8,8,7,8,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,8,7,7,7,8,8,8,8,8,7,7,8,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,8,7,7,7,7,7,7,7,7,8,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,8,7,7,7,7,7,7,7,7,8,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,8,7,7,7,7,7,7,7,7,8,8,8,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,1,7,7,7,8,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,7,7,7,7,7,8,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,8,7,7,1,1,1,1,7,7,7,7,7,1,8,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,8,7,7,7,7,7,8,8,8,8,7,1,1,8,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,8,7,7,7,7,8,0,0,0,0,8,1,1,1,8,0,0,0 },
	{ 0,0,0,0,0,0,0,0,8,7,7,1,1,8,0,0,0,0,8,1,1,1,1,8,0,0 },
	{ 0,0,0,0,0,0,0,0,8,1,1,1,1,8,0,0,0,0,8,8,1,1,1,8,0,0 },
	{ 0,0,0,0,0,0,0,0,8,1,1,1,1,1,8,0,0,0,0,0,8,8,8,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,8,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,8,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,8,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,8,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,8,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};

int draw_mega_buster[24][33] = {//�U�������K�}��
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,7,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,8,1,1,1,8,7,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,8,7,7,1,8,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,8,7,1,1,1,1,1,1,8,8,1,8,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,8,8,8,7,1,1,2,4,4,4,1,1,4,8,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,8,8,7,7,8,7,1,2,4,4,8,8,2,8,4,8,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,8,7,7,7,7,7,8,1,2,4,4,8,8,2,8,4,8,0,0,0,8,8,8,8,0,0,0,0,0 },
	{ 0,0,0,8,1,7,7,7,7,7,8,1,2,2,4,4,4,2,4,2,8,8,8,8,1,1,1,8,8,8,8,8,0 },
	{ 0,0,0,8,1,1,1,7,8,7,7,8,2,2,8,8,8,8,2,8,8,7,7,8,1,1,7,7,7,8,7,7,8 },
	{ 0,0,0,8,1,1,1,8,1,8,7,7,8,2,2,2,2,2,8,7,7,7,7,8,1,1,1,1,1,8,1,1,8 },
	{ 0,0,0,0,8,1,1,8,1,1,8,7,7,8,8,8,8,8,7,7,7,7,7,8,1,1,1,1,8,8,8,8,0 },
	{ 0,0,0,0,0,8,1,1,1,1,8,7,7,7,7,7,7,7,8,8,8,8,8,0,8,8,8,8,0,0,0,0,0 },
	{ 0,0,0,0,0,0,8,1,1,8,1,7,7,7,7,7,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,8,8,1,1,1,7,7,7,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,8,1,1,1,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,8,7,7,1,1,1,1,1,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,8,7,7,7,7,1,1,7,7,7,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,8,1,7,7,7,7,8,8,7,7,7,1,1,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,8,8,1,1,1,7,7,8,0,0,8,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,8,8,1,1,1,1,1,1,8,0,0,0,8,1,1,1,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 8,1,1,1,1,1,1,1,8,0,0,0,8,1,1,1,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 8,8,8,8,8,8,8,8,8,0,0,0,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0 }
};

int draw_exe_mark[18][18] = {//�G�O�[�}�[�N
	{ 0,0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0 },
	{ 0,0,0,0,2,2,2,2,2,2,2,2,2,2,0,0,0,0 },
	{ 0,0,2,2,2,2,2,3,3,3,3,3,2,2,2,2,0,0 },
	{ 0,0,2,2,2,2,3,3,3,3,3,3,8,2,2,2,0,0 },
	{ 0,2,2,2,3,3,3,3,3,3,3,3,8,8,2,2,2,0 },
	{ 0,2,2,3,3,3,3,3,3,3,3,3,8,8,8,2,2,0 },
	{ 2,2,2,3,3,3,3,3,3,3,3,3,8,8,8,8,2,2 },
	{ 2,2,3,3,3,3,3,3,3,3,3,8,3,3,3,3,2,2 },
	{ 2,2,3,3,3,3,3,3,3,3,8,3,3,3,3,3,2,2 },
	{ 2,2,3,3,3,3,3,3,3,8,3,3,3,3,3,3,2,2 },
	{ 2,2,3,3,3,3,3,3,8,3,3,3,3,3,3,3,2,2 },
	{ 2,2,3,3,3,3,3,8,3,3,3,3,3,3,3,3,2,2 },
	{ 0,2,2,8,8,8,8,3,3,3,3,3,3,3,3,2,2,0 },
	{ 0,2,2,2,8,8,8,3,3,3,3,3,3,3,2,2,2,0 },
	{ 0,0,2,2,2,8,8,3,3,3,3,3,3,2,2,2,0,0 },
	{ 0,0,0,2,2,2,8,3,3,3,3,3,2,2,2,2,0,0 },
	{ 0,0,0,0,2,2,2,2,2,2,2,2,2,2,0,0,0,0 },
	{ 0,0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0 }
};

int sura[21][27] = {//�X���C�f�B���O���̃��K�}��
	{ 0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,8,8,8,7,7,8,0,0,8,8,8,8,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,8,1,1,1,8,7,7,8,8,1,1,1,1,8,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,8,1,1,1,1,1,8,8,8,8,1,1,1,1,8,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,8,1,1,1,1,1,8,7,7,1,8,1,1,1,8,0,0,0,0,0,0,0 },
	{ 0,0,0,0,8,7,1,1,1,1,1,1,8,8,1,8,1,1,8,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,8,7,1,1,2,4,4,4,1,1,4,8,8,8,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,8,7,1,4,4,4,8,8,2,8,4,8,0,8,8,8,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,8,1,4,4,4,8,8,2,8,4,8,8,7,7,1,8,0,0,0,0,0,0 },
	{ 0,0,0,0,8,8,1,4,2,4,4,4,2,4,2,8,7,7,7,1,0,8,8,8,8,0,0 },
	{ 0,0,0,8,7,7,8,1,2,2,8,8,8,2,8,8,7,7,1,1,0,8,1,1,1,8,0 },
	{ 0,0,8,7,7,7,7,8,2,8,8,8,8,8,7,1,7,7,8,1,1,1,1,1,8,0,0 },
	{ 0,8,1,1,7,7,7,7,8,8,8,8,8,7,7,1,7,8,8,1,1,1,1,8,0,0,0 },
	{ 0,8,1,1,8,8,7,7,7,7,7,7,7,7,1,1,1,8,0,8,1,1,8,0,0,0,0 },
	{ 0,8,1,1,8,0,8,8,7,7,7,7,7,7,1,1,1,8,0,0,8,8,8,8,0,0,0 },
	{ 0,8,1,1,1,8,0,0,8,7,7,7,7,1,1,1,7,8,8,8,8,8,1,1,8,0,0 },
	{ 0,8,8,1,1,8,0,0,0,8,8,7,1,1,1,7,7,7,7,1,1,1,1,1,1,8,0 },
	{ 8,1,1,1,1,1,8,0,0,0,0,8,1,1,1,7,7,7,1,1,1,1,1,1,1,1,8 },
	{ 8,1,1,8,8,8,8,0,0,0,0,0,8,8,8,8,8,8,1,1,1,1,1,1,1,1,8 },
	{ 8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,0,1,1,8 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0 }
};
int shot[4][6] = {//�ʏ펞�̒e
	{ 0,8,8,8,8,0 },
	{ 8,2,2,2,4,8 },
	{ 8,2,2,2,2,8 },
	{ 0,8,8,8,8,0 }
};
int shot2[5][4] = {//heat�ɏ������̕���
	{ 0,3,0,0 },
	{ 3,2,3,0 },
	{ 3,3,2,3 },
	{ 3,2,3,0 },
	{ 0,3,0,0 }
};
int shot3[9][9] = {//elect�ɏ������̕���
	{ 0,0,0,8,8,8,0,0,0 },
	{ 0,0,8,2,2,2,8,0,0 },
	{ 0,8,2,4,4,7,2,8,0 },
	{ 8,2,7,4,7,4,4,2,8 },
	{ 8,2,4,7,2,7,4,2,8 },
	{ 8,2,4,4,7,4,7,2,8 },
	{ 0,8,2,7,4,4,2,8,0 },
	{ 0,0,8,2,2,2,8,0,0 },
	{ 0,0,0,8,8,8,0,0,0 }

};
int shot6[7][7] = {//ice_demon�ɏ���
	{ 0,0,0,7,0,0,0 },
	{ 0,0,0,7,0,7,0 },
	{ 0,0,7,0,7,0,0 },
	{ 7,7,0,2,0,7,7 },
	{ 0,0,7,0,7,0,0 },
	{ 0,7,0,7,0,7,0 },
	{ 0,0,0,7,0,0,0 },
};
int shot4[8][7] = {//hub_hound�ɏ������̕���
	{ 0,0,0,31,0,0,0 },
	{ 0,0,31,31,31,0,0 },
	{ 0,31,31,31,31,31,0 },
	{ 31,31,8,8,8,31,31 },
	{ 31,8,5,5,0,8,31 },
	{ 31,8, 5,5,5, 8,31 },
	{ 31,31,8,8,8,31,31 },
	{ 0,31,31,31,31,31,0 },
};
//�ʏ펞���K�}��
void megaman(int mx, int my, int Condition) {//�ʏ펞
											 //�R���f�B�V�������O�̎��ʏ�ӂ̃��K�}���ł��̂ق��͓|�����L�����̐F�ɂȂ�
	switch (Condition) {
	case 0:
		for (int y = 23; y >= 0; y--) {
			for (int x = 20; x >= 0; x--) {
				if (draw_megaman[y][x] != 0) {
					attrset(COLOR_PAIR(draw_megaman[y][x] + Condition) | A_REVERSE | A_BOLD);
					mvaddstr(my - (23 - y), mx + x, " ");
				}
			}
		}
		break;
	case 1:
		for (int y = 23; y >= 0; y--) {
			for (int x = 20; x >= 0; x--) {
				if (draw_megaman[y][x] != 0) {
					if (draw_megaman[y][x] == 1) {
						attrset(COLOR_PAIR(8));
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else if (y<5 && draw_megaman[y][x] == 7) {
						attrset(COLOR_PAIR(2) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else if (draw_megaman[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(draw_megaman[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
				}
			}
		}break;
	case 2:
		for (int y = 23; y >= 0; y--) {
			for (int x = 20; x >= 0; x--) {
				if (draw_megaman[y][x] != 0) {
					if (draw_megaman[y][x] == 1) {
						attrset(COLOR_PAIR(3) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else if (y<5 && draw_megaman[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else if (draw_megaman[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(draw_megaman[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
				}
			}
		}break;
	case 3:
		for (int y = 23; y >= 0; y--) {
			for (int x = 20; x >= 0; x--) {
				if (draw_megaman[y][x] != 0) {
					if (draw_megaman[y][x] == 1) {
						attrset(COLOR_PAIR(5));
						mvaddstr(my - (23 - y), mx + x, " ");
					}

					else if (y<5 && draw_megaman[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else if (draw_megaman[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(draw_megaman[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
				}
			}
		}break;
	case 6:
		for (int y = 23; y >= 0; y--) {
			for (int x = 20; x >= 0; x--) {
				if (draw_megaman[y][x] != 0) {
					if (draw_megaman[y][x] == 1) {
						attrset(COLOR_PAIR(7) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}

					else if (y<5 && draw_megaman[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else if (draw_megaman[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(draw_megaman[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
				}
			}
		}break;
	}

}
//�ʏ펞���K�}���i���]�j
void reverse_megaman(int mx, int my, int Condition) {//�ʏ펞
													 //�R���f�B�V�������O�̎��ʏ�ӂ̃��K�}���ł��̂ق��͓|�����L�����̐F�ɂȂ�
	switch (Condition) {
	case 0:
		for (int y = 23; y >= 0; y--) {
			for (int x = 20; x >= 0; x--) {
				if (draw_megaman[y][x] != 0) {
					attrset(COLOR_PAIR(draw_megaman[y][x] + Condition) | A_REVERSE | A_BOLD);
					mvaddstr(my - (23 - y), mx + (20 - x), " ");
				}
			}
		}break;
	case 1:
		for (int y = 23; y >= 0; y--) {
			for (int x = 20; x >= 0; x--) {
				if (draw_megaman[y][x] != 0) {
					if (draw_megaman[y][x] == 1) {
						attrset(COLOR_PAIR(8));
						mvaddstr(my - (23 - y), mx + (20 - x), " ");
					}
					else if (y<5 && draw_megaman[y][x] == 7) {
						attrset(COLOR_PAIR(2) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (20 - x), " ");
					}
					else if (draw_megaman[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (20 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(draw_megaman[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (20 - x), " ");
					}

				}
			}
		}break;
	case 2:
		for (int y = 23; y >= 0; y--) {
			for (int x = 20; x >= 0; x--) {
				if (draw_megaman[y][x] != 0) {
					if (draw_megaman[y][x] == 1) {
						attrset(COLOR_PAIR(3) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (20 - x), " ");
					}
					else if (y<5 && draw_megaman[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (20 - x), " ");
					}
					else if (draw_megaman[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (20 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(draw_megaman[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (20 - x), " ");
					}
				}
			}
		}break;
	case 3:
		for (int y = 23; y >= 0; y--) {
			for (int x = 20; x >= 0; x--) {
				if (draw_megaman[y][x] != 0) {
					if (draw_megaman[y][x] == 1) {
						attrset(COLOR_PAIR(5));
						mvaddstr(my - (23 - y), mx + (20 - x), " ");
					}
					else if (y<5 && draw_megaman[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (20 - x), " ");
					}
					else if (draw_megaman[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (20 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(draw_megaman[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (20 - x), " ");
					}
				}
			}
		}break;
	case 6:
		for (int y = 23; y >= 0; y--) {
			for (int x = 20; x >= 0; x--) {
				if (draw_megaman[y][x] != 0) {
					if (draw_megaman[y][x] == 1) {
						attrset(COLOR_PAIR(7) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (20 - x), " ");
					}
					else if (y<5 && draw_megaman[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (20 - x), " ");
					}
					else if (draw_megaman[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (20 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(draw_megaman[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (20 - x), " ");
					}
				}
			}
		}break;
	}
}

//�ړ����郁�K�}��
void mega_move(int mx, int my, int Condition) {
	//�R���f�B�V�������O�̎��ʏ�ӂ̃��K�}���ł��̂ق��͓|�����L�����̐F�ɂȂ�
	switch (Condition) {
	case 0:
		for (int y = 21; y >= 0; y--) {
			for (int x = 0; x < 24; x++) {
				if (draw_mega_move[y][x] != 0) {
					attrset(COLOR_PAIR(draw_mega_move[y][x] + Condition) | A_REVERSE | A_BOLD);
					mvaddstr(my - (21 - y), mx + x, " ");
				}
			}
		}
		break;
	case 1:
		for (int y = 21; y >= 0; y--) {
			for (int x = 0; x < 24; x++) {
				if (draw_mega_move[y][x] != 0) {
					if (draw_mega_move[y][x] == 1) {
						attrset(COLOR_PAIR(8));
						mvaddstr(my - (21 - y), mx + x, " ");
					}
					else if (y<5 && draw_mega_move[y][x] == 7) {
						attrset(COLOR_PAIR(2) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + x, " ");
					}
					else if (draw_mega_move[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_move[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + x, " ");
					}
				}
			}
		}break;
	case 2:
		for (int y = 21; y >= 0; y--) {
			for (int x = 0; x <24; x++) {
				if (draw_mega_move[y][x] != 0) {
					if (draw_mega_move[y][x] == 1) {
						attrset(COLOR_PAIR(3) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + x, " ");
					}
					else if (y<5 && draw_mega_move[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + x, " ");
					}
					else if (draw_mega_move[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_move[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + x, " ");
					}
				}
			}
		}break;
	case 3:
		for (int y = 21; y >= 0; y--) {
			for (int x = 0; x <24; x++) {
				if (draw_mega_move[y][x] != 0) {
					if (draw_mega_move[y][x] == 1) {
						attrset(COLOR_PAIR(5));
						mvaddstr(my - (21 - y), mx + x, " ");
					}
					else if (y<5 && draw_mega_move[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + x, " ");
					}
					else if (draw_mega_move[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_move[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + x, " ");
					}
				}
			}
		}break;
	case 6:
		for (int y = 21; y >= 0; y--) {
			for (int x = 0; x <24; x++) {
				if (draw_mega_move[y][x] != 0) {
					if (draw_mega_move[y][x] == 1) {
						attrset(COLOR_PAIR(7) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + x, " ");
					}
					else if (y<5 && draw_mega_move[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + x, " ");
					}
					else if (draw_mega_move[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_move[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + x, " ");
					}
				}
			}
		}break;
	}
}

//�ړ����郁�K�}���i���]�j
void reverse_mega_move(int mx, int my, int Condition) {
	//�R���f�B�V�������O�̎��ʏ�ӂ̃��K�}���ł��̂ق��͓|�����L�����̐F�ɂȂ�
	switch (Condition) {
	case 0:
		for (int y = 21; y >= 0; y--) {
			for (int x = 23; x >= 0; x--) {
				if (draw_mega_move[y][x] != 0) {
					attrset(COLOR_PAIR(draw_mega_move[y][x] + Condition) | A_REVERSE | A_BOLD);
					mvaddstr(my - (21 - y), mx + (23 - x), " ");
				}
			}
		}
		break;
	case 1:
		for (int y = 21; y >= 0; y--) {
			for (int x = 23; x >= 0; x--) {
				if (draw_mega_move[y][x] != 0) {
					if (draw_mega_move[y][x] == 1) {
						attrset(COLOR_PAIR(8));
						mvaddstr(my - (21 - y), mx + (23 - x), " ");
					}
					else if (y < 5 && draw_mega_move[y][x] == 7) {
						attrset(COLOR_PAIR(2) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + (23 - x), " ");
					}
					else if (draw_mega_move[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + (23 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_move[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + (23 - x), " ");
					}
				}
			}
		}break;
	case 2:
		for (int y = 21; y >= 0; y--) {
			for (int x = 0; x <24; x++) {
				if (draw_mega_move[y][x] != 0) {
					if (draw_mega_move[y][x] == 1) {
						attrset(COLOR_PAIR(3) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + (23 - x), " ");
					}
					else if (y<5 && draw_mega_move[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + (23 - x), " ");
					}
					else if (draw_mega_move[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + (23 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_move[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + (23 - x), " ");
					}
				}
			}
		}break;
	case 3:
		for (int y = 21; y >= 0; y--) {
			for (int x = 0; x <24; x++) {
				if (draw_mega_move[y][x] != 0) {
					if (draw_mega_move[y][x] == 1) {
						attrset(COLOR_PAIR(5));
						mvaddstr(my - (21 - y), mx + (23 - x), " ");
					}
					else if (y<5 && draw_mega_move[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + (23 - x), " ");
					}
					else if (draw_mega_move[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + (23 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_move[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + (23 - x), " ");
					}
				}
			}
		}break;
	case 6:
		for (int y = 21; y >= 0; y--) {
			for (int x = 0; x <24; x++) {
				if (draw_mega_move[y][x] != 0) {
					if (draw_mega_move[y][x] == 1) {
						attrset(COLOR_PAIR(7) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + (23 - x), " ");
					}
					else if (y<5 && draw_mega_move[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + (23 - x), " ");
					}
					else if (draw_mega_move[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + (23 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_move[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (21 - y), mx + (23 - x), " ");
					}
				}
			}
		}break;
	}


}

//���K�}���̃W�����v
void mega_jamp(int mx, int my, int Condition) {
	//�R���f�B�V�������O�̎��ʏ�ӂ̃��K�}���ł��̂ق��͓|�����L�����̐F�ɂȂ�
	switch (Condition) {
	case 0:
		for (int y = 29; y >= 0; y--) {
			for (int x = 0; x < 26; x++) {
				if (draw_mega_jp[y][x] != 0) {
					attrset(COLOR_PAIR(draw_mega_jp[y][x] + Condition) | A_REVERSE | A_BOLD);
					mvaddstr(my - (29 - y), mx + x, " ");
				}
			}
		}break;
	case 1:
		for (int y = 29; y >= 0; y--) {
			for (int x = 0; x < 26; x++) {
				if (draw_mega_jp[y][x] != 0) {
					if (draw_mega_jp[y][x] == 1) {
						attrset(COLOR_PAIR(8));
						mvaddstr(my - (29 - y), mx + x, " ");
					}
					else if (y<5 && draw_mega_jp[y][x] == 7) {
						attrset(COLOR_PAIR(2) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + x, " ");
					}
					else if (draw_mega_jp[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_jp[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + x, " ");
					}

				}
			}
		}break;
	case 2:
		for (int y = 29; y >= 0; y--) {
			for (int x = 0; x < 26; x++) {
				if (draw_mega_jp[y][x] != 0) {
					if (draw_mega_jp[y][x] == 1) {
						attrset(COLOR_PAIR(3) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + x, " ");
					}
					else if (y<5 && draw_mega_jp[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + x, " ");
					}
					else if (draw_mega_jp[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_jp[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + x, " ");
					}
				}
			}
		}break;
	case 3:
		for (int y = 29; y >= 0; y--) {
			for (int x = 0; x < 26; x++) {
				if (draw_mega_jp[y][x] != 0) {
					if (draw_mega_jp[y][x] == 1) {
						attrset(COLOR_PAIR(5));
						mvaddstr(my - (29 - y), mx + x, " ");
					}
					else if (y<5 && draw_mega_jp[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + x, " ");
					}
					else if (draw_mega_jp[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_jp[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + x, " ");
					}
				}
			}
		}break;
	case 6:
		for (int y = 29; y >= 0; y--) {
			for (int x = 0; x < 26; x++) {
				if (draw_mega_jp[y][x] != 0) {
					if (draw_mega_jp[y][x] == 1) {
						attrset(COLOR_PAIR(7) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + x, " ");
					}
					else if (y<5 && draw_mega_jp[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + x, " ");
					}
					else if (draw_mega_jp[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_jp[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + x, " ");
					}
				}
			}
		}break;
	}

}

//���K�}���̃W�����v�i���]�j
void reverse_mega_jamp(int mx, int my, int Condition) {
	//�R���f�B�V�������O�̎��ʏ�ӂ̃��K�}���ł��̂ق��͓|�����L�����̐F�ɂȂ�
	switch (Condition) {
	case 0:
		for (int y = 29; y >= 0; y--) {
			for (int x = 25; x > 0; x--) {
				if (draw_mega_jp[y][x] != 0) {
					attrset(COLOR_PAIR(draw_mega_jp[y][x] + Condition) | A_REVERSE | A_BOLD);
					mvaddstr(my - (29 - y), mx + (25 - x), " ");
				}
			}
		}break;
	case 1:
		for (int y = 29; y >= 0; y--) {
			for (int x = 25; x > 0; x--) {
				if (draw_mega_jp[y][x] != 0) {
					if (draw_mega_jp[y][x] == 1) {
						attrset(COLOR_PAIR(8));
						mvaddstr(my - (29 - y), mx + (25 - x), " ");
					}
					else if (y<5 && draw_mega_jp[y][x] == 7) {
						attrset(COLOR_PAIR(2) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + (25 - x), " ");
					}
					else if (draw_mega_jp[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + (25 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_jp[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + (25 - x), " ");
					}

				}
			}
		}break;
	case 2:
		for (int y = 29; y >= 0; y--) {
			for (int x = 25; x > 0; x--) {
				if (draw_mega_jp[y][x] != 0) {
					if (draw_mega_jp[y][x] == 1) {
						attrset(COLOR_PAIR(3) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + (25 - x), " ");
					}
					else if (y<5 && draw_mega_jp[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + (25 - x), " ");
					}
					else if (draw_mega_jp[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + (25 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_jp[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + (25 - x), " ");
					}
				}
			}
		}break;
	case 3:
		for (int y = 29; y >= 0; y--) {
			for (int x = 25; x > 0; x--) {
				if (draw_mega_jp[y][x] != 0) {
					if (draw_mega_jp[y][x] == 1) {
						attrset(COLOR_PAIR(5));
						mvaddstr(my - (29 - y), mx + (25 - x), " ");
					}
					else if (y<5 && draw_mega_jp[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + (25 - x), " ");
					}
					else if (draw_mega_jp[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + (25 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_jp[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + (25 - x), " ");
					}
				}
			}
		}break;
	case 6:
		for (int y = 29; y >= 0; y--) {
			for (int x = 25; x > 0; x--) {
				if (draw_mega_jp[y][x] != 0) {
					if (draw_mega_jp[y][x] == 1) {
						attrset(COLOR_PAIR(7) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + (25 - x), " ");
					}
					else if (y<5 && draw_mega_jp[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + (25 - x), " ");
					}
					else if (draw_mega_jp[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + (25 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_jp[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (29 - y), mx + (25 - x), " ");
					}
				}
			}
		}break;

	}

}

//���K�}���̍U�����
void  mega_buster(int mx, int my, int Condition) {
	//�R���f�B�V�������O�̎��ʏ�ӂ̃��K�}���ł��̂ق��͓|�����L�����̐F�ɂȂ�
	switch (Condition) {
	case 0:
		for (int y = 23; y >= 0; y--) {
			for (int x = 0; x < 33; x++) {
				if (draw_mega_buster[y][x] != 0) {
					attrset(COLOR_PAIR(draw_mega_buster[y][x] + Condition) | A_REVERSE | A_BOLD);
					mvaddstr(my - (23 - y), mx + x, " ");
				}
			}
		}break;
	case 1:
		for (int y = 23; y >= 0; y--) {
			for (int x = 0; x <33; x++) {
				if (draw_mega_buster[y][x] != 0) {
					if (draw_mega_buster[y][x] == 1) {
						attrset(COLOR_PAIR(8));
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else if (y<5 && draw_mega_buster[y][x] == 7) {
						attrset(COLOR_PAIR(2) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else if (draw_mega_buster[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_buster[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}

				}
			}
		}break;
	case 2:
		for (int y = 23; y >= 0; y--) {
			for (int x = 0; x <33; x++) {
				if (draw_mega_buster[y][x] != 0) {
					if (draw_mega_buster[y][x] == 1) {
						attrset(COLOR_PAIR(3) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else if (y<5 && draw_mega_buster[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else if (draw_mega_buster[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_buster[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
				}
			}
		}break;
	case 3:
		for (int y = 23; y >= 0; y--) {
			for (int x = 0; x <33; x++) {
				if (draw_mega_buster[y][x] != 0) {
					if (draw_mega_buster[y][x] == 1) {
						attrset(COLOR_PAIR(5));
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else if (y<5 && draw_mega_buster[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else if (draw_mega_buster[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_buster[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
				}
			}
		}break;

	case 6:
		for (int y = 23; y >= 0; y--) {
			for (int x = 0; x <33; x++) {
				if (draw_mega_buster[y][x] != 0) {
					if (draw_mega_buster[y][x] == 1) {
						attrset(COLOR_PAIR(7) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else if (y<5 && draw_mega_buster[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else if (draw_mega_buster[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_buster[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + x, " ");
					}
				}
			}
		}break;

	}
}

//���K�}���̍U����ԁi���]�j
void reverse_mega_buster(int mx, int my, int Condition) {

	for (int y = 23; y >= 0; y--) {
		for (int x = 32; x > 0; x--) {
			if (draw_mega_buster[y][x] != 0) {
				attrset(COLOR_PAIR(draw_mega_buster[y][x] + Condition) | A_REVERSE | A_BOLD);
				mvaddstr(my - (23 - y), mx + (32 - x), " ");
			}
		}
	}
	//�R���f�B�V�������O�̎��ʏ�ӂ̃��K�}���ł��̂ق��͓|�����L�����̐F�ɂȂ�
	switch (Condition) {
	case 0:
		for (int y = 23; y >= 0; y--) {
			for (int x = 32; x > 0; x--) {
				if (draw_mega_buster[y][x] != 0) {
					attrset(COLOR_PAIR(draw_mega_buster[y][x] + Condition) | A_REVERSE | A_BOLD);
					mvaddstr(my - (23 - y), mx + (32 - x), " ");
				}
			}
		}break;
	case 1:
		for (int y = 23; y >= 0; y--) {
			for (int x = 32; x > 0; x--) {
				if (draw_mega_buster[y][x] != 0) {
					if (draw_mega_buster[y][x] == 1) {
						attrset(COLOR_PAIR(8));
						mvaddstr(my - (23 - y), mx + (32 - x), " ");
					}
					else if (y < 5 && draw_mega_buster[y][x] == 7) {
						attrset(COLOR_PAIR(2) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (32 - x), " ");
					}
					else if (draw_mega_buster[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (32 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_buster[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (32 - x), " ");
					}

				}
			}
		}break;
	case 2:
		for (int y = 23; y >= 0; y--) {
			for (int x = 32; x > 0; x--) {
				if (draw_mega_buster[y][x] != 0) {
					if (draw_mega_buster[y][x] == 1) {
						attrset(COLOR_PAIR(3) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (32 - x), " ");
					}
					else if (y < 5 && draw_mega_buster[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (32 - x), " ");
					}
					else if (draw_mega_buster[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (32 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_buster[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (32 - x), " ");
					}
				}
			}
		}break;
	case 3:
		for (int y = 23; y >= 0; y--) {
			for (int x = 32; x > 0; x--) {
				if (draw_mega_buster[y][x] != 0) {
					if (draw_mega_buster[y][x] == 1) {
						attrset(COLOR_PAIR(5));
						mvaddstr(my - (23 - y), mx + (32 - x), " ");
					}
					else if (y < 5 && draw_mega_buster[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (32 - x), " ");
					}
					else if (draw_mega_buster[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (32 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_buster[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (32 - x), " ");
					}
				}
			}
		}break;
	case 6:
		for (int y = 23; y >= 0; y--) {
			for (int x = 32; x > 0; x--) {
				if (draw_mega_buster[y][x] != 0) {
					if (draw_mega_buster[y][x] == 1) {
						attrset(COLOR_PAIR(7) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (32 - x), " ");
					}
					else if (y < 5 && draw_mega_buster[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (32 - x), " ");
					}
					else if (draw_mega_buster[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (32 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(draw_mega_buster[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(my - (23 - y), mx + (32 - x), " ");
					}
				}
			}
		}break;
	}
}
//�G�O�[�̃}�[�N�`��
void exemark(int mx, int my) {

	for (int y = 17; y >= 0; y--) {
		for (int x = 0; x < 18; x++) {
			if (draw_exe_mark[y][x] != 0) {
				attrset(COLOR_PAIR(draw_exe_mark[y][x]) | A_REVERSE | A_BOLD);
				mvaddstr(my - y, mx + x, " ");
			}
		}
	}
}

void attack(int x, int y, int Condition) {//���K�}���̒e�̕`��
	switch (Condition) {
		//�R���f�B�V�������O�̎��ʏ�ł̃��K�}���ł��̂ق��̓N���A�����X�e�[�W�ɂ���ĈقȂ镐��ɂȂ�B
	case 0:
		for (int i = 3; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (shot[i][j] != 0) {
					attrset(COLOR_PAIR(shot[i][j]) | A_REVERSE | A_BOLD);
					mvaddstr(y + (4 - i), x + j, " ");
				}
			}
		}break;
	case 1:
		for (int i = 8; i >= 0; i--) {
			for (int j = 0; j < 9; j++) {
				if (shot3[i][j] != 0) {
					attrset(COLOR_PAIR(shot3[i][j]) | A_REVERSE | A_BOLD);
					mvaddstr(y + (8 - i), x + j, " ");
				}
			}
		}break;
	case 2:
		for (int i = 4; i >= 0; i--) {
			for (int j = 0; j < 4; j++) {
				if (shot2[i][j] != 0) {
					attrset(COLOR_PAIR(shot2[i][j]) | A_REVERSE | A_BOLD);
					mvaddstr(y + (5 - i), x + j, " ");
				}
			}
		}break;
	case 3:
		for (int i = 7; i >= 0; i--) {
			for (int j = 0; j < 7; j++) {
				if (shot4[i][j] == 31) {
					attrset(COLOR_PAIR(5) | A_REVERSE);
					mvaddstr(y + i, x + j, " ");
				}
				else 	if (shot4[i][j] != 0) {
					{
						attrset(COLOR_PAIR(shot4[i][j]) | A_REVERSE | A_BOLD);
						mvaddstr(y + (7 - i), x + j, " ");
					}
				}
			}
		}
		break;
	case 6:
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				if (shot6[i][j] != 0) {
					attrset(COLOR_PAIR(shot6[i][j]) | A_REVERSE | A_BOLD);
					mvaddstr(y + i, x + j, " ");
				}
			}
		}break;

	}
}

void draw_suraimega(int rx, int ry, int Condition) {//���K�}���̃X���C�f�C���O�̕`��
													//�R���f�B�V�������O�̎��ʏ�ӂ̃��K�}���ł��̂ق��͓|�����L�����̐F�ɂȂ�
	switch (Condition) {
	case 0:
		for (int y = 20; y >= 0; y--) {
			for (int x = 0; x < 27; x++) {
				if (sura[y][x] != 0) {
					attrset(COLOR_PAIR(sura[y][x] + Condition) | A_REVERSE | A_BOLD);
					mvaddstr(ry - (20 - y), rx + x, " ");
				}
			}
		}break;
	case 1:
		for (int y = 20; y >= 0; y--) {
			for (int x = 0; x < 27; x++) {
				if (sura[y][x] != 0) {
					if (sura[y][x] == 1) {
						attrset(COLOR_PAIR(8));
						mvaddstr(ry - (20 - y), rx + x, " ");
					}
					else if (y<5 && sura[y][x] == 7) {
						attrset(COLOR_PAIR(2) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + x, " ");
					}
					else if (sura[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(sura[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + x, " ");
					}

				}
			}
		}break;
	case 2:
		for (int y = 20; y >= 0; y--) {
			for (int x = 0; x <27; x++) {
				if (sura[y][x] != 0) {
					if (sura[y][x] == 1) {
						attrset(COLOR_PAIR(3) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + x, " ");
					}
					else if (y<5 && sura[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + x, " ");
					}
					else if (sura[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(sura[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + x, " ");
					}
				}
			}
		}break;
	case 3:
		for (int y = 20; y >= 0; y--) {
			for (int x = 0; x <27; x++) {
				if (sura[y][x] != 0) {
					if (sura[y][x] == 1) {
						attrset(COLOR_PAIR(5));
						mvaddstr(ry - (20 - y), rx + x, " ");
					}
					else if (y<5 && sura[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + x, " ");
					}
					else if (sura[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(sura[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + x, " ");
					}
				}
			}
		}break;
	case 6:
		for (int y = 20; y >= 0; y--) {
			for (int x = 0; x <27; x++) {
				if (sura[y][x] != 0) {
					if (sura[y][x] == 1) {
						attrset(COLOR_PAIR(7) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + x, " ");
					}
					else if (y<5 && sura[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + x, " ");
					}
					else if (sura[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + x, " ");
					}
					else {
						attrset(COLOR_PAIR(sura[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + x, " ");
					}
				}
			}
		}break;
	}
}
void draw_revslidmega(int rx, int ry, int Condition) {//�X���C�f�C���O�̕`��i���]�j
	//���K�}���̃R���f�B�V�����ɂ���ĐF���ς��
	switch (Condition) {
	case 0:
		for (int y = 20; y >= 0; y--) {
			for (int x = 26; x >= 0; x--) {
				if (sura[y][x] != 0) {
					attrset(COLOR_PAIR(sura[y][x] + Condition) | A_REVERSE | A_BOLD);
					mvaddstr(ry - (20 - y), rx + (26 - x), " ");
				}
			}
		}break;
	case 1:
		for (int y = 20; y >= 0; y--) {
			for (int x = 26; x >= 0; x--) {
				if (sura[y][x] != 0) {
					if (sura[y][x] == 1) {
						attrset(COLOR_PAIR(8));
						mvaddstr(ry - (20 - y), rx + (26 - x), " ");
					}
					else if (y<5 && sura[y][x] == 7) {
						attrset(COLOR_PAIR(2) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + (26 - x), " ");
					}
					else if (sura[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + (26 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(sura[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + (26 - x), " ");
					}

				}
			}
		}break;
	case 2:
		for (int y = 20; y >= 0; y--) {
			for (int x = 26; x >= 0; x--) {
				if (sura[y][x] != 0) {
					if (sura[y][x] == 1) {
						attrset(COLOR_PAIR(3) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + (26 - x), " ");
					}
					else if (y<5 && sura[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + (26 - x), " ");
					}
					else if (sura[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + (26 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(sura[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + (26 - x), " ");
					}
				}
			}
		}break;
	case 3:
		for (int y = 20; y >= 0; y--) {
			for (int x = 26; x >= 0; x--) {
				if (sura[y][x] != 0) {
					if (sura[y][x] == 1) {
						attrset(COLOR_PAIR(5));
						mvaddstr(ry - (20 - y), rx + (26 - x), " ");
					}
					else if (y<5 && sura[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + (26 - x), " ");
					}
					else if (sura[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + (26 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(sura[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + (26 - x), " ");
					}
				}
			}
		}break;
	case 6:
		for (int y = 20; y >= 0; y--) {
			for (int x = 26; x >= 0; x--) {
				if (sura[y][x] != 0) {
					if (sura[y][x] == 1) {
						attrset(COLOR_PAIR(7) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + (26 - x), " ");
					}
					else if (y<5 && sura[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + (26 - x), " ");
					}
					else if (sura[y][x] == 7) {
						attrset(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + (26 - x), " ");
					}
					else {
						attrset(COLOR_PAIR(sura[y][x]) | A_REVERSE | A_BOLD);
						mvaddstr(ry - (20 - y), rx + (26 - x), " ");
					}
				}
			}
		}break;

	}
}
