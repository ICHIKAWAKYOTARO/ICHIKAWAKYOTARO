#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>//������ϵ�

//���� �⺻������

#define CRT_SECURE_NO_WARNINGS//��� ����

#define LEFT 75 //�·� �̵�    //Ű���尪�� 
#define RIGHT 77 //��� �̵� 
#define UP 72 //ȸ�� 
#define DOWN 80 //soft drop
#define SPACE 32 //hard drop
#define p 112 //�Ͻ����� 
#define P 80 //�Ͻ�����
#define ESC 27 //�������� 
#define ARROW -32 //Ű���� �������� Ȯ��
#define ENTER 13//���� �ƴ��� Ȯ��

#define MAIN_X 8 //������ ����ũ�� //������ �⺻ ����
#define MAIN_Y 14 //������ ����ũ�� 
#define MAIN_X_ADJ 3 //������ ��ġ���� 
#define MAIN_Y_ADJ 1 //������ ��ġ���� 
#define STATUS_X_ADJ MAIN_X_ADJ+MAIN_X+1 //��������ǥ�� ��ġ���� 


#define false 0
#define true 1

#define GAME_MENU_NUM 4
#define GAME_TITLE 0
#define GAME_START 1
#define GAME_CONFIG 2
#define GAME_HOWTOPLAY 3
#define GAME_TURNOFF -1

#define CEILLING -1  //��
#define EMPTY 0 //��ĭ
//���� �ѿ� ����
#define PUYO_R 1//��
#define PUYO_G 2//��
#define PUYO_B 3//û
#define PUYO_Y 4//��
#define PUYO_U 5//��

