#include "GB_Sscreen_Save.h"

void ScrnTimer(HWND hWnd)
{
	KillTimer(hWnd, ScrnSave_Timer);
	SetTimer(hWnd, ScrnSave_Timer, ScrnSaveToTime, NULL);
}

void ScrnSavePaint(HWND hWnd)
{
	HDC s_hdc = GetDC(hWnd);
	Rectangle(s_hdc, 0, 0, 1920, 1030);
	ReleaseDC(0, s_hdc);
}
