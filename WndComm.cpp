#include "WndComm.h"

#include "Win32Template.h"

constexpr PCWSTR WCN_COMM = L"QK.WndClass.Comm";


struct WNDCOMMCTX
{
	int cxClient;
	int cyClient;
	HDC hCDC;
	HBITMAP hBitmap;
	HDC hCDCDbbf;
	HBITMAP hBitmapDbbf;
	HGDIOBJ hOld;
	int cxPic;
	int cyPic;
	COLORREF crBK;
};

LRESULT CALLBACK WndProc_COMM(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


ATOM RegisterClass_WndComm()
{
	WNDCLASSEXW wcex{ sizeof(WNDCLASSEX) };
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc_COMM;
	wcex.hInstance = g_hInst;
	wcex.hIcon = LoadIconW(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursorW(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszClassName = WCN_COMM;
	wcex.cbWndExtra = sizeof(void*);
	ATOM atom = RegisterClassExW(&wcex);
	assert(atom);
	return atom;
}

LRESULT CALLBACK WndProc_COMM(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	auto p = (WNDCOMMCTX*)GetWindowLongPtrW(hWnd, 0);
	switch (uMsg)
	{
	case WM_NCCREATE:
	{
		p = new WNDCOMMCTX{};
		SetWindowLongPtrW(hWnd, 0, (LONG_PTR)p);
		HDC hDC = GetDC(hWnd);
		p->hCDC = CreateCompatibleDC(NULL);
		p->hCDCDbbf = CreateCompatibleDC(NULL);
		p->hBitmapDbbf = CreateCompatibleBitmap(hDC, 8, 8);
		p->hOld = SelectObject(p->hCDCDbbf, p->hBitmapDbbf);
		ReleaseDC(hWnd, hDC);
		p->crBK = c_crYellow;
		SetDCBrushColor(p->hCDCDbbf, p->crBK);
	}
	return TRUE;

	case WM_SIZE:
	{
		p->cxClient = LOWORD(lParam);
		p->cyClient = HIWORD(lParam);
		SelectObject(p->hCDCDbbf, p->hOld);
		DeleteObject(p->hBitmapDbbf);
		HDC hDC = GetDC(hWnd);
		p->hBitmapDbbf = CreateCompatibleBitmap(hDC, p->cxClient, p->cyClient);
		p->hOld = SelectObject(p->hCDCDbbf, p->hBitmapDbbf);
		ReleaseDC(hWnd, hDC);
	}
	return 0;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		BeginPaint(hWnd, &ps);

		FillRect(p->hCDCDbbf, &ps.rcPaint, (HBRUSH)GetStockObject(DC_BRUSH));

		HGDIOBJ hOld = SelectObject(p->hCDC, p->hBitmap);
		BLENDFUNCTION bf;
		bf.BlendOp = AC_SRC_OVER;
		bf.BlendFlags = 0;
		bf.SourceConstantAlpha = 255;
		bf.AlphaFormat = AC_SRC_ALPHA;
		GdiAlphaBlend(p->hCDCDbbf, 0, 0, p->cxClient, p->cyClient, p->hCDC, 0, 0, p->cxPic, p->cyPic, bf);
		SelectObject(p->hCDC, hOld);// 位图是共享的，尽快移除占用

		BitBlt(ps.hdc,
			ps.rcPaint.left,
			ps.rcPaint.top,
			ps.rcPaint.right - ps.rcPaint.left,
			ps.rcPaint.bottom - ps.rcPaint.top,
			p->hCDCDbbf,
			ps.rcPaint.left,
			ps.rcPaint.top,
			SRCCOPY);
		EndPaint(hWnd, &ps);
	}
	return 0;

	case WM_NCDESTROY:
	{
		SelectObject(p->hCDCDbbf, p->hOld);
		DeleteObject(p->hBitmapDbbf);
		DeleteDC(p->hCDCDbbf);
		DeleteDC(p->hCDC);
		delete p;
	}
	return 0;

	case WM_CLOSE:
		return 0;
	}

	return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}

HWND WC_Create(PCWSTR pszText, int x, int y, int cx, int cy, BOOL bVisible, BOOL bTop)
{
	return CreateWindowExW((bTop ? WS_EX_TOPMOST : 0), WCN_COMM, pszText, 
		WS_CAPTION | WS_SYSMENU | (bVisible ? WS_VISIBLE : 0),
		x, y, cx, cy, NULL, NULL, g_hInst, NULL);
}

void WC_SetBitmap(HWND hWnd, HBITMAP hBitmap)
{
	auto p = (WNDCOMMCTX*)GetWindowLongPtrW(hWnd, 0);

	BITMAP bitmap;
	GetObjectW(hBitmap, sizeof(bitmap), &bitmap);
	p->cxPic = bitmap.bmWidth;
	p->cyPic = bitmap.bmHeight;

	p->hBitmap = hBitmap;

	InvalidateRect(hWnd, NULL, FALSE);
	UpdateWindow(hWnd);
}

void WC_SetColor(HWND hWnd, COLORREF cr)
{
	auto p = (WNDCOMMCTX*)GetWindowLongPtrW(hWnd, 0);

	p->crBK = cr;
	SetDCBrushColor(p->hCDCDbbf, p->crBK);

	InvalidateRect(hWnd, NULL, FALSE);
	UpdateWindow(hWnd);
}