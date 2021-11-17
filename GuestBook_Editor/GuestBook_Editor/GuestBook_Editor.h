#pragma once

#include "resource.h"

#include "../../GB_moudle/GB_moudles.h"
#include "../../GB_moudle/GB_palette.h"
#include "../../GB_moudle/GB_Button.h"
#include "../../GB_moudle/GB_Sscreen_Save.h"
#include "../../GB_moudle/GB_Image.h"
#include "../../GB_moudle/GB_FIle_io.h"

using namespace std;


DWORD WINAPI drawing(LPVOID points);    // 리플레이 스레드
DWORD WINAPI Scr_Save_thread(LPVOID points);
bool is_area(LPARAM lParam);            // 색칠 가능 영역인지 반환해주는 함수
void paint_signed_area(HWND hWnd, HDC hdc);
void mouse_proc(HWND hWnd, UINT message, LPARAM lParam, int size, COLORREF col);
void mouse_paint(HDC hdc);
DWORD button_check(LPARAM lParam);
void Center_Screen(HWND window, DWORD style, DWORD exStyle); // Window 화면 가운데 위치로 옮기는 함수
void Critical_flag(bool flag);
void Scr_Creitical_flag(bool flag);

#pragma once

// 새로 프로그램에서 사용할 상수값
#ifndef WINDOW_COLOR
#define WINDOW_COLOR RGB(230,230,230)
#endif
#define Window_Size_Width 1370                  // 윈도우 넓이
#define Window_Size_Height 900                  // 윈도우 높이

#define SRC_TIME 3000							// 30초

#define RAINBOW 1

// 서명 영역
#define BOUNDARY_LEFT 50
#define BOUNDARY_RIGHT 1300
#define BOUNDARY_TOP 120
#define BOUNDARY_BOTTOM 800

// 팔레트
#define Palette_x 735
#define Palette_y 35

// 펜
#define Pen_x 500
#define Pen_y 30
#define Pen_width 200
#define Pen_height 50
#define Pen_text_x 370
#define Pen_text_y 40
#define Pen_size 30		//폰트사이즈


// +버튼
#define PLUS 1001
#define PLUS_text L"+"	//┼로 출력시 오류
#define PLUS_x 420
#define PLUS_y 35
#define PLUS_size 40

// - 버튼
#define MINUS 1002
#define MINUS_text L"─"
#define MINUS_x 315 
#define MINUS_y 35
#define MINUS_size 40 

// CLEAR 버튼
#define CLEAR 1003
#define CLEAR_text L"CLEAR"
#define CLEAR_x 160
#define CLEAR_y 35
#define CLEAR_width 100
#define CLEAR_height 40

// REPLAY 버튼
#define REPLAY 1004
#define REPLAY_text L"REPLAY"
#define REPLAY_x 50
#define REPLAY_y 35
#define REPLAY_width 100
#define REPLAY_height 40

// RANDOM 버튼
#define RANDOM 1005
#define RANDOM_text L"RANDOM"
#define RANDOM_x 1170
#define RANDOM_y 75
#define RANDOM_width 130
#define RANDOM_height 40

// CREDIT 버튼
#define CREDIT 1006
#define CREDIT_text L"CREDIT"
#define CREDIT_x 970
#define CREDIT_y 75
#define CREDIT_width 130
#define CREDIT_height 40



/*
#define
#define _text L""
#define _x
#define _y
#define _size
#define _width
#define _height
*/
