#pragma once

#include "resource.h"

#include "../../GB_moudle/GB_moudles.h"
#include "../../GB_moudle/GB_palette.h"
#include "../../GB_moudle/GB_Button.h"
#include "../../GB_moudle/GB_Sscreen_Save.h"

using namespace std;


DWORD WINAPI drawing(LPVOID points);    // 리플레이 스레드
bool is_area(LPARAM lParam);            // 색칠 가능 영역인지 반환해주는 함수
void paint_signed_area(HWND hWnd, HDC hdc);
void mouse_proc(HWND hWnd, UINT message, LPARAM lParam, int size, COLORREF col);
void mouse_paint(HDC hdc);
DWORD button_check(LPARAM lParam);
void Center_Screen(HWND window, DWORD style, DWORD exStyle); // Window 화면 가운데 위치로 옮기는 함수
void Critical_flag(bool flag);

