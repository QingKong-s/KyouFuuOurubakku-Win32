#pragma once
#include <Windows.h>

#include <assert.h>
#include <string>

#include "Utility.h"


ATOM RegisterClass_WndBK();

HWND WB_Create(PCWSTR pszText, int x, int y, int cx, int cy);

void WB_SetColor(HWND hWnd, COLORREF crBK);

void WB_SetText(HWND hWnd, PCWSTR pszText);

void WB_SetLabelCount(HWND hWnd, int cLabel);

void WB_SetLabel(HWND hWnd, int idx, PCWSTR pszText, RECT* prcText, UINT uDTFlags);