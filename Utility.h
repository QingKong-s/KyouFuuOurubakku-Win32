#pragma once
#include <Windows.h>
#include <wincodec.h>
#include <Shlwapi.h>

#include <process.h>

constexpr COLORREF
c_crYellow = RGB(255, 217, 82),
c_crBlue = RGB(98, 191, 247);

inline HFONT EzFont(PCWSTR pszFontName, int iPoint, int iWeight = 400, BOOL bItalic = FALSE,
	BOOL bUnderline = FALSE, BOOL bStrikeOut = FALSE, HWND hWnd = NULL, DWORD dwCharSet = GB2312_CHARSET)
{
	HDC hDC = GetDC(hWnd);
	int iSize;
	iSize = -MulDiv(iPoint, GetDeviceCaps(hDC, LOGPIXELSY), 72);
	ReleaseDC(hWnd, hDC);
	return CreateFontW(iSize, 0, 0, 0, iWeight, bItalic, bUnderline,
		bStrikeOut, dwCharSet, 0, 0, 0, 0, pszFontName);
}

__forceinline HANDLE CRTCreateThread(_beginthreadex_proc_type lpStartAddress, void* lpParameter = NULL,
	UINT* lpThreadId = NULL, UINT dwCreationFlags = 0u)
{
	return (HANDLE)_beginthreadex(NULL, 0, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
}

__forceinline void SetWindowXY(HWND hWnd, int x, int y)
{
	SetWindowPos(hWnd, NULL, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE | SWP_NOREDRAW | SWP_NOACTIVATE);
}

inline int GetDpi(HWND hWnd)
{
#if _WIN32_WINNT >= _WIN32_WINNT_WIN10 // Win10 1607Ö®ºó
	if (hWnd)
		return GetDpiForWindow(hWnd);
	else
		return GetDpiForSystem();
#else
	HDC hDC = GetDC(hWnd);
	int i = GetDeviceCaps(hDC, LOGPIXELSX);
	ReleaseDC(hWnd, hDC);
	return i;
#endif
}

void WICInit();

void WICUniInit();

HBITMAP WICLoadBitmap(PCWSTR pszFile);