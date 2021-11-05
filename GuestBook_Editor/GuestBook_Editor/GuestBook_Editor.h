#pragma once

#include "resource.h"

#include "../../GB_moudle/GB_moudles.h"
#include "../../GB_moudle/GB_palette.h"
#include "../../GB_moudle/GB_Button.h"

using namespace std;




DWORD WINAPI drawing(LPVOID points);    // 리플레이 스레드
bool is_area(LPARAM lParam);            // 색칠 가능 영역인지 반환해주는 함수
void paint_signed_area(HWND hWnd, HDC hdc);
void mouse_proc(HWND hWnd, UINT message, LPARAM lParam, int size, COLORREF col);
DWORD button_check(LPARAM lParam);

