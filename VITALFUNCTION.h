void gotoxy(int x, int y) {
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}//�ܼ�â �� ��ġ�� ����ִ� �Լ�

int alphabet(char a) {
	if ('a' <= a && 'z' >= a)
		return -'a'+'A';
	else if ('A' <= a && 'Z' >= a)
		return 'a'-'A';
	return 0;
}//���ڿ��� ���ĺ����� �Ǵ��ϰ�, ��ҹ��ڸ� �ٲ��ֱ� ���� �������� �����ϴ� �Լ�

BOOLEAN samechar(char a, char b) {//�� ���ڸ� ��ҹ��ڸ� �������� �ʰ� ������ �ٸ��� �Ǵ��ϴ� �Լ�. ������� A�� a�� ���� ������ ����Ѵ�. �ϳ� A�� ;�� ���� �ʴ�.
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
