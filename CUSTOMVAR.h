#pragma once

enum COLOR {
	r = PUYO_R,
	g = PUYO_G,
	b = PUYO_B,
	y = PUYO_Y,
	u = PUYO_U,
};
//r,g,b,y,u 값을 가지는 색깔 열거형 변수(1,2,3,4,5)

typedef struct COR {
	int x;
	int y;
}cor;//좌표값 구조체

typedef struct PUYO {
	cor ctr;//중심좌표
	int rtt;//회전 상태
	enum COLOR c[2];//색깔 배열 소환
}puyo;
/*낙하중인 뿌요를 정의하기 위한 구조체
  중심 좌표, 회전상태, 뿌요의 2개 색 배열을 변수로 가질 수 있다.
 */

cor relative[4] = { {.x = 0, .y = -1}, {.x = 1,.y = 0}, {.x = 0,.y = 1}, {.x = -1,.y = 0} };
//회전 상태에 따른 나머지 한 뿌요의 상대 좌표값->rtt값으로 탐색한다.
// 0,1,2,3 순서대로 0,1,2,3

typedef struct GAMESTATE{
	BOOLEAN gameover;
	int page;
}GAMESTATE;//게임 화면(머 게임중인지 설정중인지를 나타내는 변수)&게임이 끝났는지 끝나지 않았는지 나타내는 변수