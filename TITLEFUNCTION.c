GAMESTATE title_select(int x, int y) {
	char check;
	char trash;
	int current = 0;
	GAMESTATE r;
	//�⺻���� ���� ������ ���õǾ� �ִ�.
	//���ӽ��� 0 ����� ���� 1 ���� ���� 2 �̰� ���� �������� ���� ���̴�.

	/*1. Ű�� ���������� ���
	* 2. Ű�� �������� Ű ���� ���ۿ� �ִ´�.
	* 3. ������ ���� ���� �˸��� �ൿ�� �Ѵ�.
	*/

	while (1) {
		check = _getch();
		switch (check) {

		case ESC://esc ������ ��

			r.gameover = TRUE;
			r.page = GAME_TURNOFF;
			return r;//�ϴ� ù ��° ���ۿ� ESC�� ����ִٸ� �ٷ� ������ ����.
			break;
			//esc ���������� �۵���

		case ENTER://���� ������ ��
			//trash = _getch();
			switch (current) {
				//���� Ŀ�� ��ġ�� ���� ������ �ൿ�� ����
			case 0:	
				r.gameover = FALSE;
				r.page = GAME_START;
				return r;//���� ����
			case 1:
				r.gameover = FALSE;
				r.page = GAME_CONFIG;
				return r;//���� ȭ������
			case 2:
				r.gameover = TRUE;
				r.page = GAME_TURNOFF;
				return r;//���� ����
			case 3:
				r.gameover = FALSE;
				r.page = GAME_HOWTOPLAY;
				return r;//���� ���� ���
			}
			//trash = _getch();//���� ������ ����
			break;


		case ARROW:
			check = _getch();
			switch (check) {

			case UP://��Ű ���� ���
				gotoxy(x, y + 7 + current);
				printf("��");
				current = (current - 1) % GAME_MENU_NUM;
				if (current < 0)
					current += GAME_MENU_NUM;
				gotoxy(x, y + 7 + current);
				printf("��");
				//trash = _getch();
				break;

			case DOWN://��Ű ���� ���
				gotoxy(x, y + 7 + current);
				printf("��");
				current = (current + 1) % GAME_MENU_NUM;
				gotoxy(x, y + 7 + current);
				printf("��");
				//trash = _getch();
				break;
			}
		default:
			break;


		}
		//


		//trash = _getch();//���۸� ����.
	}


	//while (_kbhit()) { check2 = _getch(); }//���� ����(���������� �� ���ؾȵ�)
}
//�޴����� �� �Է��ߴ��� �Է¹��� �� �� ���� �ൿ�� �����ִ� �Լ�

GAMESTATE title() {
	int x = 5;
	int y = 4;
	gotoxy(x, y + 0); printf("����������������"); Sleep(100);
	gotoxy(x, y + 1); printf("�����  ����    ������"); Sleep(100);
	gotoxy(x, y + 2); printf("�����              ���  ��"); Sleep(100);
	gotoxy(x, y + 3); printf("������  ��  ��  ������"); Sleep(100);
	gotoxy(x, y + 4); printf("���  �������������"); Sleep(100);
	gotoxy(x, y + 5); printf("�������� ���� ����� ����... ���� �ʽ��ϴ�..."); Sleep(100);
	gotoxy(x + 5, y + 2); printf("P U Y O P U Y O"); Sleep(100);
	gotoxy(x, y + 7); printf("��GAME START");
	gotoxy(x, y + 8); printf("��config");
	gotoxy(x, y + 9); printf("��quit");
	gotoxy(x, y + 10); printf("��how to play");
	gotoxy(x, y + 11); printf("  ��   : Shift");
	gotoxy(x, y + 12); printf("��  �� : Left / Right");
	gotoxy(x, y + 13); printf("  ��   : Soft Drop");
	gotoxy(x, y + 14); printf(" SPACE : Hard Drop");
	gotoxy(x, y + 15); printf("   P   : Pause");
	gotoxy(x, y + 16); printf("  ESC  : Quit");
	gotoxy(x, y + 17); printf("BONUS FOR HARD DROPS / COMBOS");
	return title_select(x, y);
}
//���� ȭ�� �׸��� �Լ�