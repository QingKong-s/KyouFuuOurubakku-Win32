#include "WndBK.h"
#include "Win32Template.h"

constexpr PCWSTR WCN_BK = L"QK.WndClass.BK";
// {D58D1733-E24A-481B-B7BE-D6A2EB9BD4D0}
constexpr GUID c_guidTray{ 0xd58d1733, 0xe24a, 0x481b, { 0xb7, 0xbe, 0xd6, 0xa2, 0xeb, 0x9b, 0xd4, 0xd0 } };

UINT g_uMsgTaskBarCreated = 0u;
NOTIFYICONDATAW g_nid{};

struct WNDBKCTX
{
	std::wstring sText;
	COLORREF crBK;
	HFONT hFont;
	int cxClient;
	int cyClient;

	BOOL bLabel;
	int cLabel;
	struct
	{
		RECT rcText;
		UINT uDTFlags;
		std::wstring sText;
	}
	Label[4];

	BOOL bClosed;
};

LRESULT CALLBACK WndProc_BK(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


ATOM RegisterClass_WndBK()
{
	WNDCLASSEXW wcex{ sizeof(WNDCLASSEX) };
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc_BK;
	wcex.hInstance = g_hInst;
	wcex.hIcon = LoadIconW(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursorW(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszClassName = WCN_BK;
	wcex.cbWndExtra = sizeof(void*);
	ATOM atom = RegisterClassExW(&wcex);
	assert(atom);

	g_uMsgTaskBarCreated = RegisterWindowMessageW(L"TaskbarCreated");
	return atom;
}

LRESULT CALLBACK WndProc_BK(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	auto p = (WNDBKCTX*)GetWindowLongPtrW(hWnd, 0);
	if (uMsg == g_uMsgTaskBarCreated)
	{
		Shell_NotifyIconW(NIM_DELETE, &g_nid);
		Shell_NotifyIconW(NIM_ADD, &g_nid);
		return 0;
	}

	switch (uMsg)
	{
	case WM_NCCREATE:
	{
		p = new WNDBKCTX{};
		SetWindowLongPtrW(hWnd, 0, (LONG_PTR)p);
		p->hFont = EzFont(L"Î¢ÈíÑÅºÚ", 140, 800);
		p->crBK = c_crYellow;
		p->bLabel = FALSE;
	}
	break;

	case WM_CREATE:
	{
		g_nid.cbSize = sizeof(NOTIFYICONDATAW);
		g_nid.hWnd = hWnd;
		g_nid.dwInfoFlags = NIF_GUID;
		g_nid.guidItem = c_guidTray;

		Shell_NotifyIconW(NIM_ADD, &g_nid);
	}
	return 0;

	case WM_SIZE:
	{
		p->cxClient = LOWORD(lParam);
		p->cyClient = HIWORD(lParam);
	}
	return 0;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		BeginPaint(hWnd, &ps);

		SetDCBrushColor(ps.hdc, p->crBK);
		FillRect(ps.hdc, &ps.rcPaint, (HBRUSH)GetStockObject(DC_BRUSH));
		
		SetTextColor(ps.hdc, 0xFFFFFF);
		SetBkMode(ps.hdc, TRANSPARENT);
		SelectObject(ps.hdc, p->hFont);

		if (p->cLabel)
		{
			for (int i = 0; i < p->cLabel; ++i)
			{
				DrawTextW(ps.hdc, 
					p->Label[i].sText.c_str(), (int)p->Label[i].sText.size(), 
					&p->Label[i].rcText, p->Label[i].uDTFlags);
			}
		}
		else
		{
			RECT rc{ 0,p->cyClient * 1 / 10,p->cxClient,p->cyClient };
			DrawTextW(ps.hdc, p->sText.c_str(), (int)p->sText.size(), &rc, DT_SINGLELINE | DT_CENTER);
		}

		EndPaint(hWnd, &ps);
	}
	return 0;

	case WM_DESTROY:
		Shell_NotifyIconW(NIM_DELETE, &g_nid);
		if (p->bClosed)
			PostQuitMessage(0);
		return 0;

	case WM_NCDESTROY:
	{
		DeleteObject(p->hFont);
		delete p;
	}
	return 0;

	case WM_CLOSE:
		p->bClosed = TRUE;
		DestroyWindow(hWnd);
		return 0;
	}

	return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}

HWND WB_Create(PCWSTR pszText, int x, int y, int cx, int cy)
{
	return CreateWindowExW(0, WCN_BK, pszText, WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
		x, y, cx, cy, NULL, NULL, g_hInst, NULL);
}

void WB_SetColor(HWND hWnd, COLORREF crBK)
{
	auto p = (WNDBKCTX*)GetWindowLongPtrW(hWnd, 0);
	p->crBK = crBK;
	InvalidateRect(hWnd, NULL, FALSE);
	UpdateWindow(hWnd);
}

void WB_SetText(HWND hWnd, PCWSTR pszText)
{
	auto p = (WNDBKCTX*)GetWindowLongPtrW(hWnd, 0);
	p->sText = pszText;
	InvalidateRect(hWnd, NULL, FALSE);
	UpdateWindow(hWnd);
}

void WB_SetLabelCount(HWND hWnd, int cLabel)
{
	auto p = (WNDBKCTX*)GetWindowLongPtrW(hWnd, 0);
	assert(cLabel >= 0 && cLabel <= 4);
	p->cLabel = cLabel;
	InvalidateRect(hWnd, NULL, FALSE);
	UpdateWindow(hWnd);
}

void WB_SetLabel(HWND hWnd, int idx, PCWSTR pszText, RECT* prcText, UINT uDTFlags)
{
	auto p = (WNDBKCTX*)GetWindowLongPtrW(hWnd, 0);
	assert(idx >= 0 && idx < 4);
	p->Label[idx].sText = pszText;
	p->Label[idx].rcText = *prcText;
	p->Label[idx].uDTFlags = uDTFlags;
}

void WB_PopTrayMsg(PCWSTR pszTitle, PCWSTR pszInfo, UINT uIcon)
{
	const UINT uOldFlags = g_nid.uFlags;
	g_nid.uFlags = NIF_INFO | NIF_REALTIME;
	wcscpy_s(g_nid.szInfo, pszInfo);
	wcscpy_s(g_nid.szInfoTitle, pszTitle);
	g_nid.dwInfoFlags = uIcon;
	Shell_NotifyIconW(NIM_MODIFY, &g_nid);
	g_nid.uFlags = uOldFlags;
}