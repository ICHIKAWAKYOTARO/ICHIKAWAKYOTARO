#include "MACROSETTING.h"//������ ������ �� �⺻ ����
#include "DERIVEDVAR.h"//���� ������ ����ü, ������ ����
#include "VITALFUNCTION.h"//�߿� �Լ��� ��Ƴ�����
#include "TITLEFUNCTION.c"//����ȭ�� �׷��ִ� �Լ� ������� ��
//���� ���� ���� �Լ� ������� ��


//ȭ�� ���� Ư�� ������ �̵��ϴ� �Լ�

GAMESTATE gameplay() {

}
//�����÷��� ȭ��

GAMESTATE totalconfig() {
	char trash;
	GAMESTATE r;
	r.gameover = FALSE;
	r.page = GAME_TITLE;
	char a[KEYNUMBER][100] = { "��","��","��","��","Ȯ�� �� �ϵ���","�Ͻ�����","��������" };

	printf("��ü Ű ������ �����ϰڽ��ϴ�.\n"); Sleep(1000);
	system("cls");
	for (int i = 0; i < KEYNUMBER; i++) {

		//! ������! ��Ű�� �� ȭ��ǥ�� �Է��ϸ� ��Ű �Է��� �ȹް� ��/�� Ű�� �Ѿ��.
		//! ���� ��ĭ������ �̷� ������ �߻����� �ʴ´�.
		
		printf("%s", a[i]); printf("Ű�� �����ּ���.");
		KEYSETTING[i]=input();
		printf("�Է� �Ϸ�!");Sleep(1000);
		system("cls");
	}
	printf("Ű ������ �Ϸ�Ǿ����ϴ�.");Sleep(1000);
	system("cls");
	//�ݺ��� �������鼭 ��,��,��,�� ��� ���� Ű�� �Է¹���.
	/* XŰ �Է��϶� �޼���->Ű�� ������->KEYSETTING[i].buffer 1,2�� ���� ä���.->i++ �ݺ�
	todo �� ä��� �Լ��� ��ü������ ������ ����.
	�ϴ� ���ϰ��� KEY�� ������ �Ǿ�� �Ѵ�.
	ù ��° ���ۿ��� ���� �����ͼ� ���� �װ��� -32 Ȥ�� 0�̶�� ���۸� �ѹ� �� �ҷ��� �� ���� ��� ä���
	�׷��� �ʴٸ� .buffer2�� 0�� �����Ѵ�.
	*/
	return r;
	
}
//Ű ��ü�� �����ϴ� �Լ��̴�.

GAMESTATE config() {
	char trash;
	system("cls");
	printf("Ű ������ �����ϰڽ��ϴ�.\n"); Sleep(1000);
	system("cls");
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
	game.page = GAME_CONFIG;
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