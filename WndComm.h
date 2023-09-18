#pragma once
#include <Windows.h>

#include <assert.h>


ATOM RegisterClass_WndComm();

HWND WC_Create(PCWSTR pszText, int x, int y, int cx, int cy, BOOL bVisible = TRUE, BOOL bTop = FALSE);

void WC_SetBitmap(HWND hWnd, HBITMAP hBitmap);

void WC_SetColor(HWND hWnd, COLORREF cr);