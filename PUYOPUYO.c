#include "MAINSETTING.h"//������ ������ �� �⺻ ����
#include "CUSTOMVAR.h"//���� ������ ����ü, ������ ����
#include "VITALFUNCTION.h"//�߿� �Լ��� ��Ƴ�����
#include "TITLEFUNCTION.c"//����ȭ�� �׷��ִ� �Լ� ������� ��
//���� ���� ���� �Լ� ������� ��


//ȭ�� ���� Ư�� ������ �̵��ϴ� �Լ�

GAMESTATE gameplay() {

}
//�����÷��� ȭ��

GAMESTATE totalconfig() {
	GAMESTATE r;
	r.gameover = FALSE;
	r.page = GAME_TITLE;
	return r;
	
}

GAMESTATE config() {
	System("cls");
	gotoxy(1, 1); printf("Ű ������ �����ϰڽ��ϴ�."); Sleep(1000);
	return totalconfig();//�ϴ��� ���� Ű ���� ó������ �����ϴ°ɷ� ��������.
}//���� ���� ȭ��


GAMESTATE howtoplay() {
	GAMESTATE r;
	system("cls");
	printf("���ٺ�"); Sleep(1000);
	system("cls");
	r.gameover = FALSE;
	r.page = GAME_TITLE;
	return r;
}

GAMESTATE turnoff() {
	int x = 5;
	int y = 4;
	GAMESTATE r;
	system("cls");//ȭ�� �����!
	gotoxy(x, y + 0); printf("Thanks For PLAYING"); Sleep(100);
	r.gameover = TRUE;
	r.page = GAME_TURNOFF;
	return r;
}//���� ���� �Լ�

void main() {
	//printf("�ֱ��� ����");
	//int game.page = GAME_TITLE;//ȭ�� ����ִ� ����
	GAMESTATE game;
	game.gameover = FALSE;
	game.page = GAME_TITLE;
	while (!game.gameover) {
		switch (game.page) {
		case GAME_TURNOFF:
			game = turnoff();//���� ���� �Լ�
			break;
		case GAME_TITLE:
			game = title();//Ÿ��Ʋ ȭ�� �Լ�
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
//���� ȭ��