#include "MAINSETTING.h"//게임판 사이즈 등 기본 설정
#include "CUSTOMVAR.h"//내가 선언한 구조체, 열거형 변수
#include "VITALFUNCTION.h"//중요 함수들 모아놓은곳
#include "TITLEFUNCTION.c"//시작화면 그려주는 함수 적어놓은 곳
//게임 오버 관련 함수 적어놓은 곳


//화면 위의 특정 점으로 이동하는 함수

GAMESTATE gameplay() {

}
//게임플레이 화면

GAMESTATE totalconfig() {
	GAMESTATE r;
	r.gameover = FALSE;
	r.page = GAME_TITLE;
	return r;
	
}

GAMESTATE config() {
	System("cls");
	gotoxy(1, 1); printf("키 설정을 시작하겠습니다."); Sleep(1000);
	return totalconfig();//일단은 게임 키 전부 처음부터 설정하는걸로 시작하자.
}//게임 설정 화면


GAMESTATE howtoplay() {
	GAMESTATE r;
	system("cls");
	printf("라라바보"); Sleep(1000);
	system("cls");
	r.gameover = FALSE;
	r.page = GAME_TITLE;
	return r;
}

GAMESTATE turnoff() {
	int x = 5;
	int y = 4;
	GAMESTATE r;
	system("cls");//화면 지우기!
	gotoxy(x, y + 0); printf("Thanks For PLAYING"); Sleep(100);
	r.gameover = TRUE;
	r.page = GAME_TURNOFF;
	return r;
}//게임 종료 함수

void main() {
	//printf("애기라라 잘자");
	//int game.page = GAME_TITLE;//화면 골라주는 변수
	GAMESTATE game;
	game.gameover = FALSE;
	game.page = GAME_TITLE;
	while (!game.gameover) {
		switch (game.page) {
		case GAME_TURNOFF:
			game = turnoff();//게임 종료 함수
			break;
		case GAME_TITLE:
			game = title();//타이틀 화면 함수
			break;
		case GAME_START:
			game = gameplay();
			break;
		case GAME_CONFIG:
			game = config();
			break;
		case GAME_HOWTOPLAY:	
			game = howtoplay();
			break;
			
		}
	}


}
//메인 화면