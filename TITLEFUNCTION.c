int title_select(int x, int y) {
	char check;
	char trash;
	int current = 0;//커서 위치 변화량
	KEY pressed;
	int find=0;
	GAMESTATE r;
	//기본으로 게임 시작이 선택되어 있다.
	//게임시작 0 사용자 설정 1 게임 종료 2 이걸 모듈로 연산으로 돌릴 것이다.

	/*1. 키가 눌릴때까지 대기
	* 2. 키가 눌렸으면 키 값을 버퍼에 넣는다.
	* 3. 버퍼의 값에 따라 알맞은 행동을 한다.
	*/
	while(1){
		pressed=input();//눌린 키를 입력받는다.
		//!pressed 값과 KEYSETTING 배열에 저장된 값 비교해서 어디에 들어있는지 찾자.
		for(int i=0;i<KEYNUMBER;i++){
			if(samechar(pressed.buffer1,KEYSETTING[i].buffer1))
				if(samechar(pressed.buffer2,KEYSETTING[i].buffer2))
					find=i;
		}//find 값에 KEYSETTING 배열에 저장된 위치가 나온다.
		switch(find){

			case UP ://상키 눌렸을 때

				gotoxy(x, y + 7 + current);
				printf("□");
				current = (current - 1) % GAME_MENU_NUM;
				if (current < 0)
					current += GAME_MENU_NUM;
				gotoxy(x, y + 7 + current);
				printf("■");
				//trash = _getch();
				break;

			case DOWN : //하키 눌렀을 때

				gotoxy(x, y + 7 + current);
				printf("□");
				current = (current + 1) % GAME_MENU_NUM;
				gotoxy(x, y + 7 + current);
				printf("■");
				//trash = _getch();
				break;
			
			case H_DROP : 
			
				return current;
				break;
			
			case GAMEOFF : 

				return -1;
				break;

			default:
				break;


		}
	}
	

}
//메뉴에서 뭐 입력했는지 입력받은 뒤 그 뒤의 행동을 정해주는 함수

GAMESTATE title() {
	int x = 5;
	int y = 4;
	GAMESTATE r;
	int state=0;//초기 커서 위치
	gotoxy(x, y + 0); printf("■□□□■■■□□■■□□■■"); Sleep(100);
	gotoxy(x, y + 1); printf("■■■□  ■□□    ■■□□■"); Sleep(100);
	gotoxy(x, y + 2); printf("□□□■              □■  ■"); Sleep(100);
	gotoxy(x, y + 3); printf("■■□■■  □  ■  □□■□□"); Sleep(100);
	gotoxy(x, y + 4); printf("■■  ■□□□■■■□■■□□"); Sleep(100);
	gotoxy(x, y + 5); printf("내마위를 밴한 라라의 만행... 잊지 않습니다..."); Sleep(100);
	gotoxy(x + 5, y + 2); printf("P U Y O P U Y O"); Sleep(100);
	gotoxy(x, y + 7); printf("■GAME START");
	gotoxy(x, y + 8); printf("□config");
	gotoxy(x, y + 9); printf("□quit");
	gotoxy(x, y + 10); printf("□how to play");
	gotoxy(x, y + 11); printf("  △   : Shift");
	gotoxy(x, y + 12); printf("◁  ▷ : Left / Right");
	gotoxy(x, y + 13); printf("  ▽   : Soft Drop");
	gotoxy(x, y + 14); printf(" SPACE : Hard Drop");
	gotoxy(x, y + 15); printf("   P   : Pause");
	gotoxy(x, y + 16); printf("  ESC  : Quit");
	gotoxy(x, y + 17); printf("BONUS FOR HARD DROPS / COMBOS");
	state+=title_select(x, y);//초기 커서 위치+변화량=최종 커서 위치
	switch (state) {
				//현재 커서 위치에 따라 지정된 행동을 지시

			case 0:	
				r.gameover = FALSE;
				r.page = GAME_START;
				return r;//게임 시작
				break;

			case 1:
				r.gameover = FALSE;
				r.page = GAME_CONFIG;
				return r;//설정 화면으로
				break;
			
			case -1:
			case 2:
				r.gameover = TRUE;
				r.page = GAME_TURNOFF;
				return r;//게임 종료
				break;

			case 3:
				r.gameover = FALSE;
				r.page = GAME_HOWTOPLAY;
				return r;//게임 설명 출력
				break;
			}
}
