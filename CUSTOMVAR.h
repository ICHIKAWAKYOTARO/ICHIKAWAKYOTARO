#pragma once

enum COLOR {
	r = PUYO_R,
	g = PUYO_G,
	b = PUYO_B,
	y = PUYO_Y,
	u = PUYO_U,
};
//r,g,b,y,u ���� ������ ���� ������ ����(1,2,3,4,5)

typedef struct COR {
	int x;
	int y;
}cor;//��ǥ�� ����ü

typedef struct PUYO {
	cor ctr;//�߽���ǥ
	int rtt;//ȸ�� ����
	enum COLOR c[2];//���� �迭 ��ȯ
}puyo;
/*�������� �ѿ並 �����ϱ� ���� ����ü
  �߽� ��ǥ, ȸ������, �ѿ��� 2�� �� �迭�� ������ ���� �� �ִ�.
 */

cor relative[4] = { {.x = 0, .y = -1}, {.x = 1,.y = 0}, {.x = 0,.y = 1}, {.x = -1,.y = 0} };
//ȸ�� ���¿� ���� ������ �� �ѿ��� ��� ��ǥ��->rtt������ Ž���Ѵ�.
// 0,1,2,3 ������� 0,1,2,3

typedef struct GAMESTATE{
	BOOLEAN gameover;
	int page;
}GAMESTATE;//���� ȭ��(�� ���������� ������������ ��Ÿ���� ����)&������ �������� ������ �ʾҴ��� ��Ÿ���� ����