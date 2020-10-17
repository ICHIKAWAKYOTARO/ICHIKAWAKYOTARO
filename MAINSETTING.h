#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>//헤더파일들

//게임 기본설정들

#define CRT_SECURE_NO_WARNINGS//경고 설정

#define LEFT 75 //좌로 이동    //키보드값들 
#define RIGHT 77 //우로 이동 
#define UP 72 //회전 
#define DOWN 80 //soft drop
#define SPACE 32 //hard drop
#define p 112 //일시정지 
#define P 80 //일시정지
#define ESC 27 //게임종료 
#define ARROW -32 //키보드 눌린건지 확인
#define ENTER 13//엔터 쳤는지 확인

#define MAIN_X 8 //게임판 가로크기 //게임판 기본 설정
#define MAIN_Y 14 //게임판 세로크기 
#define MAIN_X_ADJ 3 //게임판 위치조정 
#define MAIN_Y_ADJ 1 //게임판 위치조정 
#define STATUS_X_ADJ MAIN_X_ADJ+MAIN_X+1 //게임정보표시 위치조정 


#define false 0
#define true 1

#define GAME_MENU_NUM 4
#define GAME_TITLE 0
#define GAME_START 1
#define GAME_CONFIG 2
#define GAME_HOWTOPLAY 3
#define GAME_TURNOFF -1

#define CEILLING -1  //벽
#define EMPTY 0 //빈칸
//색깔별 뿌요 설정
#define PUYO_R 1//적
#define PUYO_G 2//녹
#define PUYO_B 3//청
#define PUYO_Y 4//노
#define PUYO_U 5//보

