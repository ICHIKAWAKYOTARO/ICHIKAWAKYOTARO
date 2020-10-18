void gotoxy(int x, int y) {
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}//콘솔창 내 위치를 잡아주는 함수

int alphabet(char a) {
	if ('a' <= a && 'z' >= a)
		return -'a'+'A';
	else if ('A' <= a && 'Z' >= a)
		return 'a'-'A';
	return 0;
}//문자열이 알파벳인지 판단하고, 대소문자를 바꿔주기 위한 보정값을 리턴하는 함수

BOOLEAN samechar(char a, char b) {//두 문자를 대소문자를 구별하지 않고 같은지 다른지 판단하는 함수. 예를들면 A와 a는 같은 것으로 취급한다. 하나 A와 ;는 같지 않다.
	if (alphabet(a) != 0) {
		if (alphabet(b) != 0) {
			if (b + alphabet(b) == a || b == a)
				return true;
			else
				return false;
		}
		return false;
	}
	else if (a == b)
		return true;
	else
		return false;

}

KEY input(){
	KEY k = { 0,0 };
	k.buffer1=_getch();
	if(k.buffer1==DOUBLE_1||k.buffer1==DOUBLE_2)
		k.buffer2=_getch();
	else
		k.buffer2=0;
	return k;
}
