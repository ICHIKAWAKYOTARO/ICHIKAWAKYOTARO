#include "MACROSETTING.h"//게임판 사이즈 등 기본 설정
#include "DERIVEDVAR.h"//내가 선언한 구조체, 열거형 변수
#include "VITALFUNCTION.h"//중요 함수들 모아놓은곳
#include "TITLEFUNCTION.c"//시작화면 그려주는 함수 적어놓은 곳
//게임 오버 관련 함수 적어놓은 곳


//화면 위의 특정 점으로 이동하는 함수

GAMESTATE gameplay() {

}
//게임플레이 화면

GAMESTATE totalconfig() {
	char trash;
	GAMESTATE r;
	r.gameover = FALSE;
	r.page = GAME_TITLE;
	char a[KEYNUMBER][100] = { "상","하","좌","우","확인 및 하드드롭","일시정지","게임종료" };

	printf("전체 키 설정을 시작하겠습니다.\n"); Sleep(1000);
	system("cls");
	for (int i = 0; i < KEYNUMBER; i++) {

		//! 문제점! 상키를 위 화살표로 입력하면 하키 입력을 안받고 좌/우 키로 넘어간다.
		//! 버퍼 한칸따리는 이런 문제가 발생하지 않는다.
		
		printf("%s", a[i]); printf("키를 눌러주세요.");
		KEYSETTING[i]=input();
		printf("입력 완료!");Sleep(1000);
		system("cls");
	}
	printf("키 설정이 완료되었습니다.");Sleep(1000);
	system("cls");
	//반복문 돌려가면서 상,하,좌,우 등등 여러 키를 입력받자.
	/* X키 입력하라 메세지->키를 누른다->KEYSETTING[i].buffer 1,2에 값을 채운다.->i++ 반복
	todo 값 채우는 함수를 구체적으로 정의해 보자.
	일단 리턴값은 KEY값 형식이 되어야 한다.
	첫 번째 버퍼에서 값을 가져와서 만약 그것이 -32 혹은 0이라면 버퍼를 한번 더 불러와 두 값을 모두 채우고
	그렇지 않다면 .buffer2에 0을 저장한다.
	*/
	return r;
	
}
//키 전체를 설정하는 함수이다.

GAMESTATE config() {
	char trash;
	system("cls");
	printf("키 설정을 시작하겠습니다.\n"); Sleep(1000);
	system("cls");
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
	game.page = GAME_CONFIG;
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