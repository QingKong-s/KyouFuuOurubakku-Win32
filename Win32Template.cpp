#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#pragma warning (disable:4996)

#include <numbers>

#include "Win32Template.h"
#include "Resource.h"
#include "WndBK.h"
#include "WndComm.h"

#include "bass.h"

#include <unordered_map>

#if defined _WIN64
#pragma comment(lib,R"(.\BassLib\bass_x64.lib)")
#elif defined _WIN32
#pragma comment(lib,R"(.\BassLib\bass.lib)")
#endif

#pragma comment(lib,"Winmm.lib")
#pragma comment(lib,"Shlwapi.lib")
#pragma comment(lib,"ComCtl32.lib")

#define THM_WB_SETTEXT			3000// (pszText,hWnd)
#define THM_WB_SETCLR			3001// (cr,hWnd)
#define THM_WB_SETLABELCOUNT	3002// (cLabel,hWnd)
#define THM_WB_SETLABEL			3003// (TMSETLABEL*,hWnd)
#define THM_CREATEWND			3004// (idx,0)
#define THM_DESTROYWND			3005// (hWnd,0)
#define THM_WC_SETBITMAP		3006// (hBitmap,hWnd)
#define THM_WC_SETCLR			3007// (cr,hWnd)
#define THM_WB_POPTRAYMSG		3008// (pszTitle,pszInfo)
#define THM_CREATEDLG			3009// (uType,0)
#define THM_QUIT				3010// (0,0)
struct TMSETLABEL
{
	int idx;
	UINT uDTFlags;
	RECT rc;
	PCWSTR pszText;
};

struct TMWCCREATE
{
	PCWSTR pszText;
	int x;
	int y;
	int cx;
	int cy;
};

enum
{
	IIDX_AHHHH = 0,
	IIDX_BLACKBIRD1,
	IIDX_BLACKBIRD2,
	IIDX_BLACKBIRDWAVE1,
	IIDX_BLACKBIRDWAVE2,
	IIDX_BLACKBIRDWAVE3,
	IIDX_BLUE,
	IIDX_BWYUKI,
	IIDX_YUKICUT1,
	IIDX_YUKICUT2,
	IIDX_YUKICUT3,
	IIDX_YUKICUT4,
	IIDX_CUTTINGYUKI,
	IIDX_DOGWALK1,
	IIDX_DOGWALK2,
	IIDX_FIGHT1,
	IIDX_FIGHT2,
	IIDX_FIGHT3,
	IIDX_GREYPIGEON,
	IIDX_HUGEBLOW1,
	IIDX_HUGEBLOW2,
	IIDX_JUMPDOWN,
	IIDX_JUMPDOWNBLOW,
	IIDX_JUMPDOWNBLOWBLUE,
	IIDX_JUMPUP,
	IIDX_JUMPUPBLOW,
	IIDX_JUMPUPBLOWBLUE,
	IIDX_PIGEONPEEK,
	IIDX_PIGEONPEEK2,
	IIDX_ROLLINGDOG,
	IIDX_WALK1,
	IIDX_WALK2,
	IIDX_WALK3,
	IIDX_WALK4,
	IIDX_WHITEBIRD1,
	IIDX_WHITEBIRD2,
	IIDX_WHITEBIRD3,
	IIDX_WHITEBIRDWAVE1,
	IIDX_WHITEBIRDWAVE2,
	IIDX_WHITEBIRDWAVE3,
	IIDX_WHITEPIGEON,
	IIDX_YELLOW,
	IIDX_YUKICLAP,
	IIDX_YUKICLAP2,
	IIDX_ROLLINGDOG2,
	IIDX_ROLLINGDOG3,
	IIDX_ROLLINGDOG4,
	IIDX_YUKIBACK,
	IIDX_TRIANGLE1,
	IIDX_TRIANGLE2,
	IIDX_YUKIPEEK,
	IIDX_YUKIPEEK2,
	IIDX_YUKIPEEKWITHBIRD,
	IIDX_EGG1,
	IIDX_EGG2,


	IIDX_MAX
};

enum
{
	HIDX___ = -3000,

	HIDX_YUKIJUMPD2,
	HIDX_YUKIJUMPD3,
	HIDX_YUKIJUMPD4,
	HIDX_DOGMOVEROLL1_1,

	HIDX_DOGMOVEROLL2_1,
	HIDX_DOGMOVEROLL2_2,

	HIDX_DOGMOVEROLL3_1,// 2个
	HIDX_DOGMOVEROLL4_1,// 3个
	HIDX_DOGMOVEROLL5_1,// 4个

	HIDX_DOGMOVEROLL6_1,

	HIDX_DOGFOUR,
	HIDX_DOGFOUR2,
	HIDX_YUKIJUMPMOVE2,
	HIDX_YUKIJUMPMOVE3,
	HIDX_YUKIJUMPMOVE4,
	HIDX_BIRDWAVESIX,
	HIDX_BIRDWAVEFOUR,
	HIDX_BIRDWAVESIX2,
	HIDX_DOGTWO1,
	HIDX_DOGTWO2,
	HIDX_YUKIJUMPS2_1,
	HIDX_YUKIJUMPS2_2,
	HIDX_YUKIJUMPS2_3,
	HIDX_YUKIJUMPS3_1,
	HIDX_YUKIJUMPS3_2,
	HIDX_YUKIJUMPS3_3,
	HIDX_YUKIJUMPS4_1,
	HIDX_YUKIJUMPS4_2,
	HIDX_YUKIJUMPS4_3,
	HIDX_DOGEIGHT_1,
	HIDX_DOGEIGHT_2,
	HIDX_DOGFIVE1,
	HIDX_YUKIJUMPBLOW3,
	HIDX_BLACKBIRD2,
	HIDX_WHITEBIRD2,

	HIDX_YUKIJUMPD = 0,
	HIDX_YUKIJUMPS1,
	HIDX_YUKIJUMPS2,
	HIDX_YUKIJUMPS3,
	HIDX_YUKIJUMPMOVE,
	HIDX_YUKIJUMPBLOW,
	HIDX_YUKIJUMPBLOW2,
	HIDX_YUKICLAP,
	HIDX_YUKICLAPTOP,
	HIDX_PIGEONPEEK,
	HIDX_PIGEONPEEKTOP,
	HIDX_DOG1,
	HIDX_DOG2,
	HIDX_DOG3,
	HIDX_DOG4,
	HIDX_DOG5,
	HIDX_DOG6,
	HIDX_DOG7,
	HIDX_DOG8,
	HIDX_DOGMOVEROLL1,
	HIDX_DOGMOVEROLL2,
	HIDX_DOGMOVEROLL3,
	HIDX_DOGMOVEROLL4,
	HIDX_BLACKBIRD,
	HIDX_WHITEBIRD,
	HIDX_YUKIWALK,
	HIDX_GREYPIGEON1,
	HIDX_GREYPIGEON2,
	HIDX_GREYPIGEON3,
	HIDX_WHITEPIGEON,
	HIDX_FIGHT,
	HIDX_FIGHT2,
	HIDX_DOGFOLLOWING1,
	HIDX_DOGFOLLOWING2,
	HIDX_YUKIBACK,
	HIDX_TRIANGLE1,
	HIDX_TRIANGLE2,
	HIDX_YUKIAHHHH,

	HIDX_YUKICUT1_1,

	HIDX_YUKICUT2_1,
	HIDX_YUKICUT2_2,// 

	HIDX_YUKICUT3_1,
	HIDX_YUKICUT3_2,
	HIDX_YUKICUT3_3,
	HIDX_YUKICUT3_4,

	HIDX_YUKICUT4_1,

	HIDX_YUKICUT5_1,
	HIDX_YUKICUT5_2,// 

	HIDX_YUKICUT6_1,
	HIDX_YUKICUT6_2,
	HIDX_YUKICUT6_3,

	HIDX_YUKICUT7_1,

	HIDX_HUGEBLOW,
	HIDX_BLACKBIRDWAVE1,
	HIDX_BLACKBIRDWAVE2,
	HIDX_BLACKBIRDWAVE3,
	HIDX_BLACKBIRDWAVE4,
	HIDX_WHITEBIRDWAVE1,
	HIDX_WHITEBIRDWAVE2,
	HIDX_WHITEBIRDWAVE3,

	HIDX_BWYUKI1,
	HIDX_BWYUKI2,
	HIDX_BWYUKI3,
	HIDX_BWYUKI4,
	HIDX_BWYUKI5,
	HIDX_BWYUKI6,
	HIDX_BWYUKI7,

	HIDX_YUKIPEEK,
	HIDX_YUKIPEEK2,
	HIDX_YUKIPEEKWITHBIRD,
	HIDX_EGG,

	HIDX_TD1,
	HIDX_TD2,
	HIDX_TD3,
	HIDX_TD4,
	HIDX_TD5,

	HIDX_MAX
};

using CRTThread = _beginthreadex_proc_type;

HBITMAP		g_hbm[IIDX_MAX]{};	// 所有位图
HWND		g_hWnd[HIDX_MAX]{};	// 窗口句柄
MMRESULT	g_idTimer = 0u;		// 定时器ID
UINT		g_uTime = 0;		// 时钟滴答计数
HWND		g_hBK = NULL;		// 背景窗口
int			g_iDpi = USER_DEFAULT_SCREEN_DPI;	// DPI
UINT		g_idMainThread = 0u;// 主线程ID
HSTREAM		g_hStream = NULL;	// 音频流
HINSTANCE	g_hInst = NULL;		// 实例句柄
std::unordered_map<HWND, int> g_RefCount{};		// 线程对窗口引用计数

struct
{
	float fJumpingAnCoefficient;
	float fBWYuKiCoefficient;
	float fBWYuKiMaxMove;
	int cxScreen;
	int cyScreen;

	int cxYuKiJump;
	int cyYuKiJump;
	int cxDog;
	int cyDog;
	int cxClap;
	int cyClap;
	int cxBlackBird;
	int cyBlackBird;
	int cxYuKiWalk;
	int cyYuKiWalk;
	int cxWhiteBird;
	int cyWhiteBird;
	int cxPigeon;
	int cyPigeon;
	int cxYuKiBack;
	int cyYuKiBack;
	int cxTriangle;
	int cyTriangle;
	int cxYuKiAhhhh;
	int cyYuKiAhhhh;
	int cxYuKiCut;
	int cyYuKiCut;
	int cxBirdWave;
	int cyBirdWave;
	int cxBWYuKi;
	int cyBWYuKi;
	int cxYuKiPeek;
	int cyYuKiPeek;
	int cxYuKiPeekWithBird;
	int cyYuKiPeekWithBird;
	int cxEgg;
	int cyEgg;
	int cxFight;
	int cyFight;
	int iTDGap;
}
g_Const;

void CALLBACK TimerProc(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);

void LoadAllImage()
{
	WCHAR szPath[MAX_PATH];
	GetModuleFileNameW(NULL, szPath, MAX_PATH);
	PWSTR pszFileName = PathFindFileNameW(szPath);

	wcscpy(pszFileName, LR"(Res\Ahhhh.png)");
	g_hbm[IIDX_AHHHH] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\BlackBird1.png)");
	g_hbm[IIDX_BLACKBIRD1] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\BlackBird2.png)");
	g_hbm[IIDX_BLACKBIRD2] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\BlackBirdWave1.png)");
	g_hbm[IIDX_BLACKBIRDWAVE1] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\BlackBirdWave2.png)");
	g_hbm[IIDX_BLACKBIRDWAVE2] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\BlackBirdWave3.png)");
	g_hbm[IIDX_BLACKBIRDWAVE3] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\blue.png)");
	g_hbm[IIDX_BLUE] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\BWYuki.png)");
	g_hbm[IIDX_BWYUKI] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\YukiCut1.png)");
	g_hbm[IIDX_YUKICUT1] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\YukiCut2.png)");
	g_hbm[IIDX_YUKICUT2] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\YukiCut3.png)");
	g_hbm[IIDX_YUKICUT3] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\YukiCut4.png)");
	g_hbm[IIDX_YUKICUT4] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\CuttingYuki.png)");
	g_hbm[IIDX_CUTTINGYUKI] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\DogWalk1.png)");
	g_hbm[IIDX_DOGWALK1] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\DogWalk2.png)");
	g_hbm[IIDX_DOGWALK2] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\Fight1.png)");
	g_hbm[IIDX_FIGHT1] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\Fight2.png)");
	g_hbm[IIDX_FIGHT2] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\Fight3.png)");
	g_hbm[IIDX_FIGHT3] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\GreyPigeon.png)");
	g_hbm[IIDX_GREYPIGEON] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\HugeBlow1.png)");
	g_hbm[IIDX_HUGEBLOW1] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\HugeBlow2.png)");
	g_hbm[IIDX_HUGEBLOW2] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\JumpDown.png)");
	g_hbm[IIDX_JUMPDOWN] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\JumpDownBlow.png)");
	g_hbm[IIDX_JUMPDOWNBLOW] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\JumpDownBlowBlue.png)");
	g_hbm[IIDX_JUMPDOWNBLOWBLUE] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\JumpUp.png)");
	g_hbm[IIDX_JUMPUP] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\JumpUpBlow.png)");
	g_hbm[IIDX_JUMPUPBLOW] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\JumpUpBlowBlue.png)");
	g_hbm[IIDX_JUMPUPBLOWBLUE] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\PigeonPeek.png)");
	g_hbm[IIDX_PIGEONPEEK] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\PigeonPeek2.png)");
	g_hbm[IIDX_PIGEONPEEK2] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\RollingDog.png)");
	g_hbm[IIDX_ROLLINGDOG] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\Walk1.png)");
	g_hbm[IIDX_WALK1] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\Walk2.png)");
	g_hbm[IIDX_WALK2] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\Walk3.png)");
	g_hbm[IIDX_WALK3] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\Walk4.png)");
	g_hbm[IIDX_WALK4] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\WhiteBird1.png)");
	g_hbm[IIDX_WHITEBIRD1] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\WhiteBird2.png)");
	g_hbm[IIDX_WHITEBIRD2] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\WhiteBird3.png)");
	g_hbm[IIDX_WHITEBIRD3] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\WhiteBirdWave1.png)");
	g_hbm[IIDX_WHITEBIRDWAVE1] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\WhiteBirdWave2.png)");
	g_hbm[IIDX_WHITEBIRDWAVE2] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\WhiteBirdWave3.png)");
	g_hbm[IIDX_WHITEBIRDWAVE3] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\WhitePigeon.png)");
	g_hbm[IIDX_WHITEPIGEON] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\yellow.png)");
	g_hbm[IIDX_YELLOW] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\YukiClap.png)");
	g_hbm[IIDX_YUKICLAP] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\YukiClap2.png)");
	g_hbm[IIDX_YUKICLAP2] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\RollingDog2.png)");
	g_hbm[IIDX_ROLLINGDOG2] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\RollingDog3.png)");
	g_hbm[IIDX_ROLLINGDOG3] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\RollingDog4.png)");
	g_hbm[IIDX_ROLLINGDOG4] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\YukiBack.png)");
	g_hbm[IIDX_YUKIBACK] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\Triangle1.png)");
	g_hbm[IIDX_TRIANGLE1] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\Triangle2.png)");
	g_hbm[IIDX_TRIANGLE2] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\YukiPeek.png)");
	g_hbm[IIDX_YUKIPEEK] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\YukiPeek2.png)");
	g_hbm[IIDX_YUKIPEEK2] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\YukiPeekWithBird.png)");
	g_hbm[IIDX_YUKIPEEKWITHBIRD] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\Egg1.png)");
	g_hbm[IIDX_EGG1] = WICLoadBitmap(szPath);
	wcscpy(pszFileName, LR"(Res\Egg2.png)");
	g_hbm[IIDX_EGG2] = WICLoadBitmap(szPath);
}

__forceinline int DPI(int i)
{
	return i * g_iDpi / USER_DEFAULT_SCREEN_DPI;
}

__forceinline float DPI(float i)
{
	return i * (float)g_iDpi / (float)USER_DEFAULT_SCREEN_DPI;
}

void CalcConst()
{
	g_Const.fJumpingAnCoefficient = DPI(200.f);
	g_Const.fBWYuKiCoefficient = DPI(40.f);
	g_Const.fBWYuKiMaxMove = DPI(400.f);
	g_Const.cxScreen = GetSystemMetrics(SM_CXSCREEN);
	g_Const.cyScreen = GetSystemMetrics(SM_CYSCREEN);
	g_Const.cxYuKiJump = DPI(215);
	g_Const.cyYuKiJump = DPI(500);
	g_Const.cxDog = DPI(150);
	g_Const.cyDog = DPI(150);
	g_Const.cxClap = DPI(190);
	g_Const.cyClap = DPI(190);
	g_Const.cxBlackBird = DPI(190);
	g_Const.cyBlackBird = DPI(148);
	g_Const.cxYuKiWalk = DPI(215);
	g_Const.cyYuKiWalk = DPI(439);
	g_Const.cxWhiteBird = DPI(205);
	g_Const.cyWhiteBird = DPI(304);
	g_Const.cxPigeon = DPI(300);
	g_Const.cyPigeon = DPI(259);
	g_Const.cxYuKiBack = DPI(280);
	g_Const.cyYuKiBack = DPI(378);
	g_Const.cxTriangle = DPI(200);
	g_Const.cyTriangle = DPI(202);
	g_Const.cxYuKiAhhhh = DPI(215);
	g_Const.cyYuKiAhhhh = DPI(386);
	g_Const.cxYuKiCut = DPI(270);
	g_Const.cyYuKiCut = DPI(266);
	g_Const.cxBirdWave = DPI(140);
	g_Const.cyBirdWave = DPI(129);
	g_Const.cxBWYuKi = DPI(215);
	g_Const.cyBWYuKi = DPI(504);
	g_Const.cxYuKiPeek = DPI(215);
	g_Const.cyYuKiPeek = DPI(479);
	g_Const.cxYuKiPeekWithBird = DPI(215);
	g_Const.cyYuKiPeekWithBird = DPI(600);
	g_Const.cxEgg = DPI(280);
	g_Const.cyEgg = DPI(285);
	g_Const.cxFight = DPI(470);
	g_Const.cyFight = DPI(341);
	g_Const.iTDGap = DPI(80);
}

void TSWB_SetText(PCWSTR pszText)
{
	PostThreadMessageW(g_idMainThread, THM_WB_SETTEXT, (WPARAM)pszText, (LPARAM)g_hBK);
}

void TSWB_SetColor(COLORREF cr)
{
	PostThreadMessageW(g_idMainThread, THM_WB_SETCLR, cr, (LPARAM)g_hBK);
}

void TSWB_SetLabelCount(int cLabel)
{
	PostThreadMessageW(g_idMainThread, THM_WB_SETLABELCOUNT, cLabel, (LPARAM)g_hBK);
}

void TSWB_SetLabel(int idx, PCWSTR pszText, RECT* prcText, UINT uDTFlags)
{
	auto p = new TMSETLABEL;
	p->pszText = pszText;
	p->rc = *prcText;
	p->uDTFlags = uDTFlags;
	p->idx = idx;
	PostThreadMessageW(g_idMainThread, THM_WB_SETLABEL, (WPARAM)p, (LPARAM)g_hBK);
}

void TSWB_PopTrayMsg(PCWSTR pszTitle, PCWSTR pszInfo)
{
	PostThreadMessageW(g_idMainThread, THM_WB_POPTRAYMSG, (WPARAM)pszTitle, (LPARAM)pszInfo);
}

void TSCALL_CreateWindow(int idx)
{
	PostThreadMessageW(g_idMainThread, THM_CREATEWND, idx, 0);
}

void TSCALL_DestroyWindow(HWND hWnd)
{
	PostThreadMessageW(g_idMainThread, THM_DESTROYWND, (WPARAM)hWnd, 0);
}

void TSWC_SetBitmap(HWND hWnd, HBITMAP hBitmap)
{
	PostThreadMessageW(g_idMainThread, THM_WC_SETBITMAP, (WPARAM)hBitmap, (LPARAM)hWnd);
}

void TSWC_SetColor(HWND hWnd, COLORREF cr)
{
	PostThreadMessageW(g_idMainThread, THM_WC_SETCLR, cr, (LPARAM)hWnd);
}

void CreateAnThread(HWND* phWnd, int cWnds, HBITMAP* pBitmaps, int cBitmaps, int msInterval, UINT uEndTick)
{
	struct ANTHREADCTX
	{
		std::vector<HBITMAP> hbm;
		std::vector<HWND> hWnd;
		int msInterval;
		UINT uEndTick;
	};

	auto p = new ANTHREADCTX;
	p->hbm.resize(cBitmaps);
	for (int i = 0; i < cBitmaps; ++i)
		p->hbm[i] = pBitmaps[i];
	p->hWnd.resize(cWnds);
	for (int i = 0; i < cWnds; ++i)
		p->hWnd[i] = phWnd[i];
	p->msInterval = msInterval;
	p->uEndTick = uEndTick;
	for (auto x : p->hWnd)
		TSWC_SetBitmap(x, p->hbm[0]);
	CloseHandle(CRTCreateThread([](void* pParam)->UINT
		{
			auto p = (ANTHREADCTX*)pParam;
			int i = 0;

			for (;;)
			{
				++i;
				if (i == (int)p->hbm.size())
					i = 0;

				if (g_uTime >= p->uEndTick)
				{
					for (auto x : p->hWnd)
						TSCALL_DestroyWindow(x);
					delete p;
					return 0;
				}

				Sleep(p->msInterval);

				for (auto x : p->hWnd)
					TSWC_SetBitmap(x, p->hbm[i]);
			}
			delete p;
			return 0;
		}, (void*)p));
}

void CreateDogMoveThread(int idx, int x, UINT uEndTick, UINT uSwitchTick, UINT uSustain)
{
	struct DMTHREADCTX
	{
		HWND hWnd;
		UINT uEndTick;
		UINT uSwitchTick;
		UINT uSustain;
	};
	RECT rc;
	GetWindowRect(g_hBK, &rc);
	g_hWnd[idx] = WC_Create(L"",
		x,
		rc.top + (rc.bottom - rc.top) * 7 / 10,
		g_Const.cxDog,
		g_Const.cyDog);

	g_RefCount.insert(std::make_pair(g_hWnd[idx], 3));
	auto p = new DMTHREADCTX;
	p->hWnd = g_hWnd[idx];
	p->uEndTick = uEndTick;
	p->uSwitchTick = uSwitchTick;
	p->uSustain = uSustain;
	CloseHandle(CRTCreateThread([](void* pParam)->UINT
		{
			auto p = (DMTHREADCTX*)pParam;
			UINT uStartTick = g_uTime;
			HWND hWnd = p->hWnd;

			HBITMAP hbm[]{ g_hbm[IIDX_DOGWALK1],g_hbm[IIDX_DOGWALK2] };
			CreateAnThread(&hWnd, 1, hbm, ARRAYSIZE(hbm), 60, p->uSwitchTick - 2);

			RECT rc, rcBK;
			GetWindowRect(hWnd, &rc);
			GetWindowRect(g_hBK, &rcBK);
			const int v = (g_Const.cxScreen - (rcBK.left + (rcBK.right - rcBK.left) * 2 / 10)) / p->uSustain;// 像素每滴答

			int cxDistance = g_Const.cxScreen - rc.left;
			BOOL b = FALSE;
			for (;;)
			{
				SetWindowXY(hWnd, rc.left + (g_uTime - uStartTick) * v, rc.top);
				Sleep(20);
				if (g_uTime >= p->uEndTick)
				{
					TSCALL_DestroyWindow(hWnd);
					delete p;
					return 0;
				}
				else if (g_uTime >= p->uSwitchTick && !b)
				{
					TSWB_PopTrayMsg(L"风力实在是太强了！", L"我整条狗都快被吹飞了！");
					b = TRUE;
					HBITMAP hbm[]{ g_hbm[IIDX_ROLLINGDOG],g_hbm[IIDX_ROLLINGDOG2],g_hbm[IIDX_ROLLINGDOG3],g_hbm[IIDX_ROLLINGDOG4] };
					CreateAnThread(&hWnd, 1, hbm, ARRAYSIZE(hbm), 60, p->uEndTick - 2);
				}
			}

			delete p;
			return 0;
		}, (void*)p));
}

void CreateDogMoveThread(int iType)
{
	RECT rc;
	GetWindowRect(g_hBK, &rc);
	switch (iType)
	{
	case HIDX_DOGMOVEROLL1_1:
		CreateDogMoveThread(HIDX_DOGMOVEROLL1, rc.left + (rc.right - rc.left) * 2 / 10, 220u, 180u, 70u);
		break;
	case HIDX_DOGMOVEROLL2_1:
		CreateDogMoveThread(HIDX_DOGMOVEROLL1, rc.left + (rc.right - rc.left) * 2 / 10, 820u, 780u, 60u);
		break;
	case HIDX_DOGMOVEROLL2_2:
		CreateDogMoveThread(HIDX_DOGMOVEROLL1, rc.left + (rc.right - rc.left) * 3 / 10, 980u, 940u, 80u);
		break;
	case HIDX_DOGMOVEROLL3_1:
		CreateDogMoveThread(HIDX_DOGMOVEROLL1, rc.left + (rc.right - rc.left) * 2 / 10, 1354u, 1314u, 64u);
		CreateDogMoveThread(HIDX_DOGMOVEROLL2, rc.left + (rc.right - rc.left) * 3 / 10, 1354u, 1314u, 64u);
		break;
	case HIDX_DOGMOVEROLL4_1:
		CreateDogMoveThread(HIDX_DOGMOVEROLL1, rc.left + (rc.right - rc.left) * 2 / 10, 1910u, 1870u, 40u);
		CreateDogMoveThread(HIDX_DOGMOVEROLL2, rc.left + (rc.right - rc.left) * 3 / 10, 1910u, 1870u, 40u);
		CreateDogMoveThread(HIDX_DOGMOVEROLL3, rc.left + (rc.right - rc.left) * 4 / 10, 1910u, 1870u, 40u);
		break;
	case HIDX_DOGMOVEROLL5_1:
		CreateDogMoveThread(HIDX_DOGMOVEROLL1, rc.left + (rc.right - rc.left) * 2 / 10, 2190u, 2150u, 50u);
		CreateDogMoveThread(HIDX_DOGMOVEROLL2, rc.left + (rc.right - rc.left) * 3 / 10, 2190u, 2150u, 50u);
		CreateDogMoveThread(HIDX_DOGMOVEROLL3, rc.left + (rc.right - rc.left) * 4 / 10, 2190u, 2150u, 50u);
		CreateDogMoveThread(HIDX_DOGMOVEROLL4, rc.left + (rc.right - rc.left) * 5 / 10, 2190u, 2150u, 50u);
		break;
	case HIDX_DOGMOVEROLL6_1:
		CreateDogMoveThread(HIDX_DOGMOVEROLL1, rc.left + (rc.right - rc.left) * 2 / 10, 2270u, 2230u, 20u);
		break;
	default:
		assert(FALSE);
		break;
	}
}

void CreateYuKiJumpThread(UINT uEndTick)
{
	g_hWnd[HIDX_YUKIJUMPD] = WC_Create(L"",
		(g_Const.cxScreen - g_Const.cxYuKiJump) / 2,
		(g_Const.cyScreen - g_Const.cyYuKiJump) / 2,
		g_Const.cxYuKiJump,
		g_Const.cyYuKiJump);
	g_RefCount.insert(std::make_pair(g_hWnd[HIDX_YUKIJUMPD], 2));
	CloseHandle(CRTCreateThread([](void* pParam)->UINT
		{
			const HWND hWnd = g_hWnd[HIDX_YUKIJUMPD];
			const UINT uEndTick = (UINT)(UINT_PTR)pParam;
			RECT rc;
			GetWindowRect(hWnd, &rc);
			float f = 0.f;
			int yNew;
			for (;;)
			{
				while (f < 0.4f)
				{
					f += 0.02f;
					yNew = rc.top + (int)((g_Const.fJumpingAnCoefficient * f) * logf(f * 2.5f));
					SetWindowXY(hWnd, rc.left, yNew);
					Sleep(20);
					if (g_uTime >= uEndTick)
					{
						TSCALL_DestroyWindow(hWnd);
						return 0;
					}
				}
				f = 0.f;
				Sleep(50);
			}
			return 0;
		}, (void*)(UINT_PTR)uEndTick));
	HBITMAP hbm[]{ g_hbm[IIDX_JUMPUP],g_hbm[IIDX_JUMPDOWN] };
	CreateAnThread(&g_hWnd[HIDX_YUKIJUMPD], 1, hbm, ARRAYSIZE(hbm), 400, uEndTick);
}

void CreateYuKiJumpMoveThread(UINT uEndTick)
{
	g_hWnd[HIDX_YUKIJUMPMOVE] = WC_Create(L"",
		(g_Const.cxScreen - g_Const.cxYuKiJump) / 2,
		(g_Const.cyScreen - g_Const.cyYuKiJump) / 2,
		g_Const.cxYuKiJump,
		g_Const.cyYuKiJump);
	g_RefCount.insert(std::make_pair(g_hWnd[HIDX_YUKIJUMPMOVE], 2));
	CloseHandle(CRTCreateThread([](void* pParam)->UINT
		{
			const UINT uEndTick = (UINT)(UINT_PTR)pParam;
			const HWND hWnd = g_hWnd[HIDX_YUKIJUMPMOVE];
			UINT uStartTick = g_uTime;
			RECT rc;
			GetWindowRect(hWnd, &rc);
			int cxDistance = g_Const.cxScreen - rc.left;
			for (;;)
			{
				SetWindowXY(hWnd, rc.left + cxDistance * (g_uTime - uStartTick) / (uEndTick - 2 - uStartTick), rc.top);
				Sleep(20);
				if (g_uTime >= uEndTick)
				{
					TSCALL_DestroyWindow(hWnd);
					return 0;
				}
			}

			return 0;
		}, (void*)(UINT_PTR)uEndTick));
	HBITMAP hbm[]{ g_hbm[IIDX_JUMPUP],g_hbm[IIDX_JUMPDOWN] };
	CreateAnThread(&g_hWnd[HIDX_YUKIJUMPMOVE], 1, hbm, ARRAYSIZE(hbm), 60, uEndTick);
}

void CreateDogFourThread(UINT uEndTick)
{
	RECT rc;
	GetWindowRect(g_hBK, &rc);
	const int xLeftEdge = (g_Const.cxScreen - g_Const.cxYuKiJump) / 2;

	g_hWnd[HIDX_DOG1] = WC_Create(L"",
		xLeftEdge - g_Const.cxDog * 2,
		rc.top + (rc.bottom - rc.top) * 7 / 10,
		g_Const.cxDog,
		g_Const.cyDog);
	g_hWnd[HIDX_DOG2] = WC_Create(L"",
		xLeftEdge - g_Const.cxDog,
		rc.top + (rc.bottom - rc.top) * 7 / 10,
		g_Const.cxDog,
		g_Const.cyDog);
	g_hWnd[HIDX_DOG3] = WC_Create(L"",
		xLeftEdge + g_Const.cxYuKiJump,
		rc.top + (rc.bottom - rc.top) * 7 / 10,
		g_Const.cxDog,
		g_Const.cyDog);
	g_hWnd[HIDX_DOG4] = WC_Create(L"",
		xLeftEdge + g_Const.cxYuKiJump + g_Const.cxDog,
		rc.top + (rc.bottom - rc.top) * 7 / 10,
		g_Const.cxDog,
		g_Const.cyDog);
	g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOG1], 1));
	g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOG2], 1));
	g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOG3], 1));
	g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOG4], 1));
	HBITMAP hbm[]{ g_hbm[IIDX_DOGWALK1],g_hbm[IIDX_DOGWALK2] };
	CreateAnThread(&g_hWnd[HIDX_DOG1], 4, hbm, ARRAYSIZE(hbm), 60, uEndTick);
}

void CreateYuKiCutThread(int idx, int msInterval, UINT uEndTick)
{
	struct CUTTHREADCTX
	{
		HWND hWnd;
		int msInterval;
		UINT uEndTick;
	};
	auto p = new CUTTHREADCTX;

	RECT rc;
	GetWindowRect(g_hBK, &rc);
	int x;

	switch (idx)
	{
	case HIDX_YUKICUT1_1:
	case HIDX_YUKICUT4_1:
	case HIDX_YUKICUT7_1:
		x = (g_Const.cxScreen - g_Const.cxYuKiCut) / 2;
		break;
	case HIDX_YUKICUT2_1:
	case HIDX_YUKICUT5_1:
		x = (g_Const.cxScreen - g_Const.cxYuKiCut * 2) / 2;
		break;
	case HIDX_YUKICUT2_2:
	case HIDX_YUKICUT5_2:
		x = (g_Const.cxScreen - g_Const.cxYuKiCut * 2) / 2 + g_Const.cxYuKiCut;
		break;
	case HIDX_YUKICUT3_1:
	case HIDX_YUKICUT3_2:
	case HIDX_YUKICUT3_3:
	case HIDX_YUKICUT3_4:
	{
		int i = idx - HIDX_YUKICUT3_1;
		x = rc.left + (rc.right - rc.left - g_Const.cxYuKiCut * 4) + i * g_Const.cxYuKiCut;
	}
	break;
	case HIDX_YUKICUT6_1:
	case HIDX_YUKICUT6_2:
	case HIDX_YUKICUT6_3:
	{
		int i = idx - HIDX_YUKICUT6_1;
		x = rc.left + (rc.right - rc.left) * 8 * i / 10 / 2;
	}
	break;
	}

	g_hWnd[idx] = WC_Create(L"",
		x,
		(g_Const.cyScreen - g_Const.cyYuKiCut) / 2,
		g_Const.cxYuKiCut,
		g_Const.cyYuKiCut);

	p->hWnd = g_hWnd[idx];
	p->uEndTick = uEndTick;
	p->msInterval = msInterval;

	g_RefCount.insert(std::make_pair(g_hWnd[idx], 1));
	CloseHandle(CRTCreateThread([](void* pParam)->UINT
		{
			auto p = (CUTTHREADCTX*)pParam;
			const HWND hWnd = (HWND)p->hWnd;

			TSWC_SetBitmap(hWnd, g_hbm[IIDX_YUKICUT1]);
			Sleep(p->msInterval);
			TSWC_SetBitmap(hWnd, g_hbm[IIDX_YUKICUT2]);
			Sleep(p->msInterval);
			TSWC_SetBitmap(hWnd, g_hbm[IIDX_YUKICUT3]);
			Sleep(p->msInterval);
			TSWC_SetBitmap(hWnd, g_hbm[IIDX_YUKICUT4]);
			
			for (;;)
			{
				if (g_uTime >= p->uEndTick)
				{
					TSCALL_DestroyWindow(hWnd);
					delete p;
					return 0;
				}
				Sleep(10);
			}

			delete p;
			return 0;
		}, (void*)p));
}

void CreateYuKiJumpBlowThread(int c, UINT uEndTick)
{
	struct YJBTHREADCTX
	{
		UINT uEndTick;
		HWND hWnd[2];
		int cWnds;
	};

	CRTThread pfnThread = [](void* pParam)->UINT
		{
			auto p = (YJBTHREADCTX*)pParam;
			RECT rc[2];
			for (int i = 0; i < p->cWnds; ++i)
				GetWindowRect(p->hWnd[i], &rc[i]);
			float f = 0.f;
			int yNew;
			for (;;)
			{
				while (f < 0.4f)
				{
					f += 0.02f;
					for (int i = 0; i < p->cWnds; ++i)
					{
						yNew = rc[i].top + (int)((g_Const.fJumpingAnCoefficient * f) * logf(f * 2.5f));
						SetWindowXY(p->hWnd[i], rc[i].left, yNew);
					}
					Sleep(20);

					if (g_uTime >= p->uEndTick)
					{
						for (int i = 0; i < p->cWnds; ++i)
							TSCALL_DestroyWindow(p->hWnd[i]);
						delete p;
						return 0;
					}
				}
				f = 0.f;
				Sleep(50);
			}

			delete p;
			return 0;
		};

	RECT rc;
	GetWindowRect(g_hBK, &rc);

	auto p = new YJBTHREADCTX;
	p->uEndTick = uEndTick;
	p->cWnds = c;
	if (c == 2)
	{
		g_hWnd[HIDX_YUKIJUMPBLOW] = WC_Create(L"",
			rc.left + DPI(80),
			(g_Const.cyScreen - g_Const.cyYuKiJump) / 2,
			g_Const.cxYuKiJump,
			g_Const.cyYuKiJump);
		g_hWnd[HIDX_YUKIJUMPBLOW2] = WC_Create(L"",
			rc.right - DPI(80) - g_Const.cxYuKiJump,
			(g_Const.cyScreen - g_Const.cyYuKiJump) / 2,
			g_Const.cxYuKiJump,
			g_Const.cyYuKiJump);
		g_RefCount.insert(std::make_pair(g_hWnd[HIDX_YUKIJUMPBLOW], 2));
		g_RefCount.insert(std::make_pair(g_hWnd[HIDX_YUKIJUMPBLOW2], 2));
		p->hWnd[0] = g_hWnd[HIDX_YUKIJUMPBLOW];
		p->hWnd[1] = g_hWnd[HIDX_YUKIJUMPBLOW2];
	}
	else
	{
		g_hWnd[HIDX_YUKIJUMPBLOW] = WC_Create(L"",
			(g_Const.cxScreen - g_Const.cxYuKiJump) / 2,
			(g_Const.cyScreen - g_Const.cyYuKiJump) / 2,
			g_Const.cxYuKiJump,
			g_Const.cyYuKiJump);
		g_RefCount.insert(std::make_pair(g_hWnd[HIDX_YUKIJUMPBLOW], 2));
		p->hWnd[0] = g_hWnd[HIDX_YUKIJUMPBLOW];
	}

	CloseHandle(CRTCreateThread(pfnThread, p));
	HBITMAP hbm[]{ g_hbm[IIDX_JUMPDOWNBLOW],g_hbm[IIDX_JUMPUPBLOW] };
	CreateAnThread(&g_hWnd[HIDX_YUKIJUMPBLOW], c, hbm, 2, 400, uEndTick);
}

void CreateDogTwoThread(UINT uEndTick)
{
	RECT rc;
	GetWindowRect(g_hBK, &rc);
	g_hWnd[HIDX_DOG1] = WC_Create(L"",
		rc.left + (rc.right - rc.left) * 2 / 10,
		rc.top + (rc.bottom - rc.top) * 7 / 10,
		g_Const.cxDog,
		g_Const.cyDog);
	g_hWnd[HIDX_DOG2] = WC_Create(L"",
		rc.right - (rc.right - rc.left) * 2 / 10 - g_Const.cxDog,
		rc.top + (rc.bottom - rc.top) * 7 / 10,
		g_Const.cxDog,
		g_Const.cyDog);
	g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOG1], 1));
	g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOG2], 1));
	HBITMAP hbm[]{ g_hbm[IIDX_DOGWALK1],g_hbm[IIDX_DOGWALK2] };
	HWND hWnd[]{ g_hWnd[HIDX_DOG1],g_hWnd[HIDX_DOG2] };
	CreateAnThread(hWnd, ARRAYSIZE(hWnd), hbm, ARRAYSIZE(hbm), 60, uEndTick);
}

void CreateYuKiJumpSThread(int idx, UINT uEndTick)
{
	int i = idx - HIDX_YUKIJUMPS1;
	RECT rc;
	GetWindowRect(g_hBK, &rc);
	g_hWnd[idx] = WC_Create(L"",
		rc.left + ((rc.right - rc.left) / 10) * (i + 1) + g_Const.cxYuKiJump * i,
		(g_Const.cyScreen - g_Const.cyYuKiJump) / 2,
		g_Const.cxYuKiJump,
		g_Const.cyYuKiJump);
	g_RefCount.insert(std::make_pair(g_hWnd[idx], 1));
	HBITMAP hbm[]{ g_hbm[IIDX_JUMPUP],g_hbm[IIDX_JUMPDOWN] };
	CreateAnThread(&g_hWnd[idx], 1, hbm, ARRAYSIZE(hbm), 260, uEndTick);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pszCmdLine, _In_ int nCmdShow)
{
	CoInitialize(NULL);
	g_hInst = hInstance;
	g_idMainThread = GetCurrentThreadId();
	g_iDpi = GetDpi(NULL);
	WICInit();
	CalcConst();
	LoadAllImage();

	EnumWindows([](HWND hWnd, LPARAM lParam)->BOOL
		{
			if (IsWindowVisible(hWnd) &&// 可见
				!IsIconic(hWnd) &&// 没有最小化
				!(GetWindowLongPtrW(hWnd, GWL_EXSTYLE) & WS_EX_TOOLWINDOW) &&// 不是工具条窗口
				(GetWindowLongPtrW(hWnd, GWL_STYLE) & (WS_CAPTION | WS_MINIMIZEBOX)))// 有标题栏和最小化按钮
			{
				ShowWindowAsync(hWnd, SW_MINIMIZE);
			}
			return TRUE;
		}, 0);

	ATOM atomBK = RegisterClass_WndBK();
	ATOM atomComm = RegisterClass_WndComm();
	assert(atomBK);
	assert(atomComm);

	g_hBK = WB_Create(NULL,
		g_Const.cxScreen * 2 / 10,
		g_Const.cyScreen * 2 / 10,
		g_Const.cxScreen * 6 / 10,
		g_Const.cyScreen * 6 / 10);

	if (!BASS_Init(-1, 44100, 0, g_hBK, 0))
	{
		CoUninitialize();
		MessageBoxW(NULL, L"Bass初始化失败！", NULL, MB_ICONERROR);
		return 1;
	}

	WCHAR szPath[MAX_PATH];
	GetModuleFileNameW(NULL, szPath, MAX_PATH);
	PWSTR pszFileName = PathFindFileNameW(szPath);
	wcscpy(pszFileName, LR"(Res\Audio.mp3)");

	g_hStream = BASS_StreamCreateFile(FALSE, szPath, 0, 0, 0);
	BASS_ChannelSetSync(g_hStream, BASS_SYNC_END | BASS_SYNC_ONETIME, 0, [](HSYNC handle, DWORD channel, DWORD data, void* user)
		{
			PostThreadMessageW(g_idMainThread, WM_QUIT, 0, 0);
		}, NULL);
	BASS_ChannelPlay(g_hStream, TRUE);

//#define TickToSec(x) ((x) * 50. / 1000.)
	//g_uTime = 1040;
	//if (g_uTime)
	//	BASS_ChannelSetPosition(g_hStream, BASS_ChannelSeconds2Bytes(g_hStream, TickToSec(g_uTime)), BASS_POS_BYTE);

	g_idTimer = timeSetEvent(50, 0, TimerProc, 0, TIME_PERIODIC | TIME_KILL_SYNCHRONOUS);

	MSG msg;
	while (GetMessageW(&msg, NULL, 0, 0))
	{
		if (msg.hwnd)
		{
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
		else
		{
			switch (msg.message)
			{
			case THM_WB_SETTEXT:
				WB_SetText((HWND)msg.lParam, (PCWSTR)msg.wParam);
				break;
			case THM_WB_SETCLR:
				WB_SetColor((HWND)msg.lParam, (COLORREF)msg.wParam);
				break;
			case THM_WB_SETLABELCOUNT:
				WB_SetLabelCount((HWND)msg.lParam, (int)msg.wParam);
				break;
			case THM_WB_SETLABEL:
			{
				auto p = (TMSETLABEL*)msg.wParam;
				WB_SetLabel((HWND)msg.lParam, p->idx, p->pszText, &p->rc, p->uDTFlags);
				delete p;
			}
			break;
			case THM_WB_POPTRAYMSG:
				WB_PopTrayMsg((PCWSTR)msg.wParam, (PCWSTR)msg.lParam, (rand() % 3) + 1);
				break;
			case THM_WC_SETBITMAP:
				WC_SetBitmap((HWND)msg.lParam, (HBITMAP)msg.wParam);
				break;
			case THM_WC_SETCLR:
				WC_SetColor((HWND)msg.lParam, (COLORREF)msg.wParam);
				break;
			case THM_DESTROYWND:
			{
				auto it = g_RefCount.find((HWND)msg.wParam);
				assert(it != g_RefCount.end());
				it->second--;
				if (it->second == 0)
				{
					DestroyWindow(it->first);
					g_RefCount.erase(it);
				}
			}
			break;
			case THM_CREATEWND:
			{
				switch (msg.wParam)
				{
				case HIDX_YUKIJUMPD:
					CreateYuKiJumpThread(130u);
					break;
				case HIDX_YUKIJUMPD2:
					CreateYuKiJumpThread(1270u);
					break;
				case HIDX_YUKIJUMPD3:
					CreateYuKiJumpThread(1860u);
					break;
				case HIDX_YUKIJUMPD4:
					CreateYuKiJumpThread(2130u);
					break;

				case HIDX_DOGTWO1:
					CreateDogTwoThread(140u);
					break;
				case HIDX_DOGTWO2:
					CreateDogTwoThread(1860u);
					break;

				case HIDX_YUKIJUMPMOVE:
					CreateYuKiJumpMoveThread(210u);
					break;
				case HIDX_YUKIJUMPMOVE2:
					CreateYuKiJumpMoveThread(1356u);
					break;
				case HIDX_YUKIJUMPMOVE3:
					CreateYuKiJumpMoveThread(1910u);
					break;
				case HIDX_YUKIJUMPMOVE4:
					CreateYuKiJumpMoveThread(2190u);
					break;

				case HIDX_DOGMOVEROLL1_1:
				case HIDX_DOGMOVEROLL2_1:
				case HIDX_DOGMOVEROLL2_2:
				case HIDX_DOGMOVEROLL3_1:
				case HIDX_DOGMOVEROLL4_1:
				case HIDX_DOGMOVEROLL5_1:
				case HIDX_DOGMOVEROLL6_1:
					CreateDogMoveThread((int)msg.wParam);
					break;

				case HIDX_YUKIJUMPS1:
				case HIDX_YUKIJUMPS2:
				case HIDX_YUKIJUMPS3:
					CreateYuKiJumpSThread((int)msg.wParam, 260u);
					break;
				case HIDX_YUKIJUMPS2_1:
				case HIDX_YUKIJUMPS2_2:
				case HIDX_YUKIJUMPS2_3:
					CreateYuKiJumpSThread(HIDX_YUKIJUMPS1 + ((int)msg.wParam - HIDX_YUKIJUMPS2_1), 1390u);
					break;
				case HIDX_YUKIJUMPS3_1:
				case HIDX_YUKIJUMPS3_2:
				case HIDX_YUKIJUMPS3_3:
					CreateYuKiJumpSThread(HIDX_YUKIJUMPS1 + ((int)msg.wParam - HIDX_YUKIJUMPS3_1), 1970u);
					break;
				case HIDX_YUKIJUMPS4_1:
				case HIDX_YUKIJUMPS4_2:
				case HIDX_YUKIJUMPS4_3:
					CreateYuKiJumpSThread(HIDX_YUKIJUMPS1 + ((int)msg.wParam - HIDX_YUKIJUMPS4_1), 2250u);
					break;

				case HIDX_YUKICLAP:
				{
					g_hWnd[HIDX_PIGEONPEEK] = WC_Create(L"",
						0,
						g_Const.cyScreen - DPI(60),
						g_Const.cxClap,
						g_Const.cyClap);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_PIGEONPEEK], 2));

					g_hWnd[HIDX_YUKICLAP] = WC_Create(L"",
						g_Const.cxScreen - g_Const.cxClap,
						g_Const.cyScreen - DPI(60),
						g_Const.cxClap,
						g_Const.cyClap);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_YUKICLAP], 2));

					CRTThread pfnWndAn = [](void* pParam)->UINT
						{
							HWND hWnd = (HWND)pParam;
							RECT rc;
							GetWindowRect(hWnd, &rc);
							int iCount = 0;
							int yNew;
							const int cyDistance = (rc.bottom - rc.top) + 60;
							const int yStart = GetSystemMetrics(SM_CYSCREEN);
							auto F = [](float x)->float
								{
									float t = -(std::numbers::e_v<float>) * x * logf(x);
									return fabsf(-powf(t, 0.4f));
								};

							while (iCount < 100)
							{
								yNew = yStart - (int)(F(iCount / 99.f) * cyDistance);
								SetWindowXY(hWnd, rc.left, yNew);
								++iCount;
								Sleep(9);
							}

							TSCALL_DestroyWindow(hWnd);
							return 0;
						};

					CloseHandle(CRTCreateThread(pfnWndAn, (void*)g_hWnd[HIDX_YUKICLAP]));
					CloseHandle(CRTCreateThread(pfnWndAn, (void*)g_hWnd[HIDX_PIGEONPEEK]));

					HBITMAP hbm[]{ g_hbm[IIDX_YUKICLAP],g_hbm[IIDX_YUKICLAP2] };
					CreateAnThread(&g_hWnd[HIDX_YUKICLAP], 1, hbm, ARRAYSIZE(hbm), 100, g_uTime + 18);
					hbm[0] = g_hbm[IIDX_PIGEONPEEK];
					hbm[1] = g_hbm[IIDX_PIGEONPEEK2];
					CreateAnThread(&g_hWnd[HIDX_PIGEONPEEK], 1, hbm, ARRAYSIZE(hbm), 100, g_uTime + 18);
				}
				break;

				case HIDX_DOGFIVE1:
				{
					RECT rc;
					GetWindowRect(g_hBK, &rc);
					const int cxPadding = (rc.right - rc.left) * 3 / 100;
					const int cxLeftPadding = ((rc.right - rc.left) - (cxPadding * 4 + g_Const.cxDog * 5)) / 2;

					g_hWnd[HIDX_DOG1] = WC_Create(L"",
						rc.left + cxLeftPadding,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxDog,
						g_Const.cyDog);
					g_hWnd[HIDX_DOG2] = WC_Create(L"",
						rc.left + cxLeftPadding + g_Const.cxDog + cxPadding,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxDog,
						g_Const.cyDog);
					g_hWnd[HIDX_DOG3] = WC_Create(L"",
						rc.left + cxLeftPadding + (g_Const.cxDog + cxPadding) * 2,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxDog,
						g_Const.cyDog);
					g_hWnd[HIDX_DOG4] = WC_Create(L"",
						rc.left + cxLeftPadding + (g_Const.cxDog + cxPadding) * 3,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxDog,
						g_Const.cyDog);
					g_hWnd[HIDX_DOG5] = WC_Create(L"",
						rc.left + cxLeftPadding + (g_Const.cxDog + cxPadding) * 4,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxDog,
						g_Const.cyDog);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOG1], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOG2], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOG3], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOG4], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOG5], 1));
					HBITMAP hbm[]{ g_hbm[IIDX_DOGWALK1],g_hbm[IIDX_DOGWALK2] };
					CreateAnThread(&g_hWnd[HIDX_DOG1], 5, hbm, ARRAYSIZE(hbm), 60, 280u);
				}
				break;

				case HIDX_DOGFOUR:
					CreateDogFourThread(1270u);
					break;
				case HIDX_DOGFOUR2:
					CreateDogFourThread(1420u);
					break;

				case HIDX_YUKIJUMPBLOW:
				{
					g_hWnd[HIDX_YUKIJUMPBLOW] = WC_Create(L"",
						(g_Const.cxScreen - g_Const.cxYuKiJump) / 2,
						(g_Const.cyScreen - g_Const.cyYuKiJump) / 2,
						g_Const.cxYuKiJump,
						g_Const.cyYuKiJump);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_YUKIJUMPBLOW], 2));

				CloseHandle(CRTCreateThread([](void* pParam)->UINT
					{
						HWND hWnd = (HWND)pParam;
						RECT rc;
						GetWindowRect(hWnd, &rc);
						float f = 0.f;
						int yNew;
						for (;;)
						{
							while (f < 0.4f)
							{
								f += 0.02f;
								yNew = rc.top + (int)((g_Const.fJumpingAnCoefficient * f) * logf(f * 2.5f));
								SetWindowXY(hWnd, rc.left, yNew);
								Sleep(20);

								if (g_uTime >= 570u)
								{
									TSCALL_DestroyWindow(hWnd);
									return 0;
								}
							}
							f = 0.f;
							Sleep(50);
						}

						return 0;
					}, (void*)g_hWnd[HIDX_YUKIJUMPBLOW]));

				CloseHandle(CRTCreateThread([](void* pParam)->UINT
					{
						HWND hWnd = (HWND)pParam;
						HBITMAP hbm[]{ g_hbm[IIDX_JUMPDOWNBLOW],g_hbm[IIDX_JUMPUPBLOW] };
						int i = 0;
						int iTime = 400;
						BOOL bYellow = TRUE;
						for (;;)
						{
							if (g_uTime >= 578u)
							{
								TSCALL_DestroyWindow(hWnd);
								return 0;
							}
							else if (bYellow && ((g_uTime >= 366u && g_uTime < 440u) ||
								(g_uTime >= 510u && g_uTime < 580u)))
							{
								bYellow = FALSE;
								hbm[0] = g_hbm[IIDX_JUMPDOWNBLOWBLUE];
								hbm[1] = g_hbm[IIDX_JUMPUPBLOWBLUE];
								TSWC_SetBitmap(hWnd, hbm[i]);
							}
							else if (!bYellow && (g_uTime >= 440u && g_uTime < 510u))
							{
								bYellow = TRUE;
								hbm[0] = g_hbm[IIDX_JUMPDOWNBLOW];
								hbm[1] = g_hbm[IIDX_JUMPUPBLOW];
								TSWC_SetBitmap(hWnd, hbm[i]);
							}

							if (iTime == 400)
							{
								iTime = 0;
								TSWC_SetBitmap(hWnd, hbm[i]);
								++i;
								if (i == 2)
									i = 0;
							}

							Sleep(100);
							iTime += 100;
						}

						return 0;
					}, (void*)g_hWnd[HIDX_YUKIJUMPBLOW]));
				}
				break;

				case HIDX_YUKIJUMPBLOW2:
					CreateYuKiJumpBlowThread(1, 1680u);
					break;
				case HIDX_YUKIJUMPBLOW3:
					CreateYuKiJumpBlowThread(2, 2620u);
					break;

				case HIDX_BLACKBIRD:
				{
					RECT rc;
					GetWindowRect(g_hBK, &rc);
					g_hWnd[HIDX_BLACKBIRD] = WC_Create(L"",
						rc.left - g_Const.cyBlackBird * 4 / 10,
						rc.bottom - g_Const.cyBlackBird * 6 / 10,
						g_Const.cxBlackBird,
						g_Const.cyBlackBird);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_BLACKBIRD], 2));
					HBITMAP hbm[]{ g_hbm[IIDX_BLACKBIRD1],g_hbm[IIDX_BLACKBIRD2] };
					CreateAnThread(&g_hWnd[HIDX_BLACKBIRD], 1, hbm, ARRAYSIZE(hbm), 240, 570u);

					CloseHandle(CRTCreateThread([](void* pParam)->UINT
						{
							HWND hWnd = (HWND)pParam;
							BOOL bYellow = TRUE;
							for (;;)
							{
								if (g_uTime >= 570u)
								{
									TSCALL_DestroyWindow(hWnd);
									return 0;
								}
								else if (bYellow && ((g_uTime >= 366u && g_uTime < 440u) ||
									(g_uTime >= 510u && g_uTime < 580u)))
								{
									bYellow = FALSE;
									TSWC_SetColor(hWnd, c_crBlue);
								}
								else if (!bYellow && (g_uTime >= 440u && g_uTime < 510u))
								{
									bYellow = TRUE;
									TSWC_SetColor(hWnd, c_crYellow);
								}
								Sleep(100);
							}

							return 0;
						}, (void*)g_hWnd[HIDX_BLACKBIRD]));
				}
				break;

				case HIDX_WHITEBIRD:
				{
					RECT rc;
					GetWindowRect(g_hBK, &rc);
					g_hWnd[HIDX_WHITEBIRD] = WC_Create(L"",
						rc.right - g_Const.cyBlackBird * 6 / 10,
						rc.bottom - g_Const.cyWhiteBird + g_Const.cyBlackBird * 6 / 10,
						g_Const.cxWhiteBird,
						g_Const.cyWhiteBird);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_WHITEBIRD], 2));
					CloseHandle(CRTCreateThread([](void* pParam)->UINT
						{
							HWND hWnd = (HWND)pParam;
							HBITMAP hbm[]{ g_hbm[IIDX_WHITEBIRD1],g_hbm[IIDX_WHITEBIRD2] };
							int i = 0;
							int iTime = 200;
							BOOL bHitTriangle[4]{};// 是否击打过三角铁

							for (;;)
							{
								if (g_uTime >= 570u)
								{
									TSCALL_DestroyWindow(hWnd);
									return 0;
								}
								else if (!bHitTriangle[0] && g_uTime >= 270u)
								{
									bHitTriangle[0] = TRUE;
									TSWC_SetBitmap(hWnd, g_hbm[IIDX_WHITEBIRD3]);
									iTime = 0;
								}
								else if (!bHitTriangle[1] && g_uTime >= 366u)
								{
									bHitTriangle[1] = TRUE;
									TSWC_SetBitmap(hWnd, g_hbm[IIDX_WHITEBIRD3]);
									iTime = 0;
								}
								else if (!bHitTriangle[2] && g_uTime >= 440u)
								{
									bHitTriangle[2] = TRUE;
									TSWC_SetBitmap(hWnd, g_hbm[IIDX_WHITEBIRD3]);
									iTime = 0;
								}
								else if (!bHitTriangle[3] && g_uTime >= 510u)
								{
									bHitTriangle[3] = TRUE;
									TSWC_SetBitmap(hWnd, g_hbm[IIDX_WHITEBIRD3]);
									iTime = 0;
								}

								if (iTime == 200)
								{
									iTime = 0;
									TSWC_SetBitmap(hWnd, hbm[i]);
									++i;
									if (i == 2)
										i = 0;
								}

								Sleep(100);
								iTime += 100;
							}

							return 0;
						}, (void*)g_hWnd[HIDX_WHITEBIRD]));

					CloseHandle(CRTCreateThread([](void* pParam)->UINT
						{
							HWND hWnd = (HWND)pParam;
							BOOL bYellow = TRUE;
							for (;;)
							{
								if (g_uTime >= 570u)
								{
									TSCALL_DestroyWindow(hWnd);
									return 0;
								}
								else if (bYellow && ((g_uTime >= 366u && g_uTime < 440u) ||
									(g_uTime >= 510u && g_uTime < 580u)))
								{
									bYellow = FALSE;
									TSWC_SetColor(hWnd, c_crBlue);
								}
								else if (!bYellow && (g_uTime >= 440u && g_uTime < 510u))
								{
									bYellow = TRUE;
									TSWC_SetColor(hWnd, c_crYellow);
								}

								Sleep(100);
							}

							return 0;
						}, (void*)g_hWnd[HIDX_WHITEBIRD]));
				}
				break;

				case HIDX_BLACKBIRD2:
				{
					RECT rc;
					GetWindowRect(g_hBK, &rc);
					g_hWnd[HIDX_BLACKBIRD] = WC_Create(L"",
						rc.left - g_Const.cyBlackBird * 4 / 10,
						rc.bottom - g_Const.cyBlackBird * 6 / 10,
						g_Const.cxBlackBird,
						g_Const.cyBlackBird);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_BLACKBIRD], 1));
					CreateAnThread(&g_hWnd[HIDX_BLACKBIRD], 1, &g_hbm[IIDX_BLACKBIRD1], 2, 240, 2620u);
				}
				break;

				case HIDX_WHITEBIRD2:
				{
					RECT rc;
					GetWindowRect(g_hBK, &rc);
					g_hWnd[HIDX_WHITEBIRD] = WC_Create(L"",
						rc.right - g_Const.cyBlackBird * 6 / 10,
						rc.bottom - g_Const.cyWhiteBird + g_Const.cyBlackBird * 6 / 10,
						g_Const.cxWhiteBird,
						g_Const.cyWhiteBird);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_WHITEBIRD], 1));
					CloseHandle(CRTCreateThread([](void* pParam)->UINT
						{
							HWND hWnd = (HWND)pParam;
							HBITMAP hbm[]{ g_hbm[IIDX_WHITEBIRD1],g_hbm[IIDX_WHITEBIRD2] };
							int i = 0;
							int iTime = 200;
							BOOL bHitTriangle[3]{};// 是否击打过三角铁

							for (;;)
							{
								if (g_uTime >= 2620)
								{
									TSCALL_DestroyWindow(hWnd);
									return 0;
								}
								else if (!bHitTriangle[0] && g_uTime >= 2424u)
								{
									bHitTriangle[0] = TRUE;
									TSWC_SetBitmap(hWnd, g_hbm[IIDX_WHITEBIRD3]);
									iTime = 0;
								}
								else if (!bHitTriangle[1] && g_uTime >= 2496u)
								{
									bHitTriangle[1] = TRUE;
									TSWC_SetBitmap(hWnd, g_hbm[IIDX_WHITEBIRD3]);
									iTime = 0;
								}
								else if (!bHitTriangle[2] && g_uTime >= 2570u)
								{
									bHitTriangle[2] = TRUE;
									TSWC_SetBitmap(hWnd, g_hbm[IIDX_WHITEBIRD3]);
									iTime = 0;
								}

								if (iTime == 200)
								{
									iTime = 0;
									TSWC_SetBitmap(hWnd, hbm[i]);
									++i;
									if (i == 2)
										i = 0;
								}

								Sleep(100);
								iTime += 100;
							}

							return 0;
						}, (void*)g_hWnd[HIDX_WHITEBIRD]));
				}
				break;

				case HIDX_YUKIWALK:
				{
					g_hWnd[HIDX_YUKIWALK] = WC_Create(L"",
						g_Const.cxScreen - g_Const.cxYuKiWalk,
						(g_Const.cyScreen - g_Const.cyYuKiWalk) / 2,
						g_Const.cxYuKiWalk,
						g_Const.cyYuKiWalk);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_YUKIWALK], 1));
					CloseHandle(CRTCreateThread([](void* pParam)->UINT
						{
							UINT uStartTick = g_uTime;
							HWND hWnd = (HWND)pParam;
							int i = 0;
							RECT rc, rcBK;
							GetWindowRect(hWnd, &rc);
							GetWindowRect(g_hBK, &rcBK);
							const int cxDistance = g_Const.cxScreen - g_Const.cxBlackBird - (rcBK.right - (rcBK.right - rcBK.left) * 2 / 10);
							int iTime = 0;
							for (;;)
							{
								SetWindowXY(hWnd, rc.left - cxDistance * (g_uTime - uStartTick) / (1068u - uStartTick), rc.top);
								Sleep(20);

								iTime += 20;
								if (iTime >= 300)
								{
									TSWC_SetBitmap(hWnd, g_hbm[IIDX_WALK1 + i]);
									++i;
									if (i == 4)
										i = 0;
									iTime = 0;
								}

								if (g_uTime >= 1068u)
								{
									TSCALL_DestroyWindow(hWnd);
									return 0;
								}
							}

							return 0;
						}, (void*)g_hWnd[HIDX_YUKIWALK]));
				}
				break;

				case HIDX_GREYPIGEON1:
				case HIDX_GREYPIGEON2:
				case HIDX_GREYPIGEON3:
				{
					int i = (int)msg.wParam - HIDX_GREYPIGEON1;
					RECT rc;
					GetWindowRect(g_hBK, &rc);
					const int iLeft = rc.left + (rc.right - rc.left) / 10;
					const int cxValid = (rc.right - rc.left) - (rc.right - rc.left) * 2 / 10;
					g_hWnd[msg.wParam] = WC_Create(L"",
						iLeft + (cxValid - g_Const.cxPigeon) * i / 3,
						(g_Const.cyScreen - g_Const.cyPigeon) * 2 / 3,
						g_Const.cxPigeon,
						g_Const.cyPigeon);
					WC_SetBitmap(g_hWnd[msg.wParam], g_hbm[IIDX_GREYPIGEON]);
					g_RefCount.insert(std::make_pair(g_hWnd[msg.wParam], 1));
				}
				break;

				case HIDX_WHITEPIGEON:
				{
					const int i = 3;
					RECT rc;
					GetWindowRect(g_hBK, &rc);
					const int iLeft = rc.left + (rc.right - rc.left) / 10;
					const int cxValid = (rc.right - rc.left) - (rc.right - rc.left) * 2 / 10;
					g_hWnd[HIDX_WHITEPIGEON] = WC_Create(L"",
						iLeft + (cxValid - g_Const.cxPigeon) * i / 3,
						(g_Const.cyScreen - g_Const.cyPigeon) * 2 / 3,
						g_Const.cxPigeon,
						g_Const.cyPigeon);
					WC_SetBitmap(g_hWnd[HIDX_WHITEPIGEON], g_hbm[IIDX_WHITEPIGEON]);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_WHITEPIGEON], 1));
				}
				break;

				case HIDX_FIGHT:
				{
					RECT rc;
					GetWindowRect(g_hBK, &rc);
					g_hWnd[HIDX_FIGHT] = WC_Create(L"",
						(g_Const.cxScreen - g_Const.cxFight) / 2,
						rc.top + (rc.bottom - rc.top) * 3 / 5,
						g_Const.cxFight,
						g_Const.cyFight);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_FIGHT], 1));
					CreateAnThread(&g_hWnd[HIDX_FIGHT], 1, &g_hbm[IIDX_FIGHT1], 3, 40, 1140u);
				}
				break;

				case HIDX_FIGHT2:
				{
					RECT rc;
					GetWindowRect(g_hBK, &rc);
					const int xLeft = rc.left + (rc.right - rc.left) * 2 / 5;
					const int xRight = rc.left + (rc.right - rc.left) * 3 / 5;
					g_hWnd[HIDX_FIGHT] = WC_Create(L"",
						xLeft - g_Const.cxFight,
						(g_Const.cyScreen - g_Const.cyFight) / 2,
						g_Const.cxFight,
						g_Const.cyFight);
					g_hWnd[HIDX_FIGHT2] = WC_Create(L"",
						xRight,
						(g_Const.cyScreen - g_Const.cyFight) / 2,
						g_Const.cxFight,
						g_Const.cyFight);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_FIGHT], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_FIGHT2], 1));
					CreateAnThread(&g_hWnd[HIDX_FIGHT], 2, &g_hbm[IIDX_FIGHT1], 3, 40, 2140u);
				}
				break;

				case HIDX_DOGFOLLOWING1:
				{
					RECT rc;
					GetWindowRect(g_hWnd[HIDX_YUKIWALK], &rc);
					g_hWnd[HIDX_DOGFOLLOWING1] = WC_Create(L"",
						rc.right,
						rc.bottom - g_Const.cyDog,
						g_Const.cxDog,
						g_Const.cyDog);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOGFOLLOWING1], 1));
					CloseHandle(CRTCreateThread([](void* pParam)->UINT
						{
							HWND hWnd = (HWND)pParam;
							RECT rc;
							int i = 0;
							for (;;)
							{
								GetWindowRect(g_hWnd[HIDX_YUKIWALK], &rc);
								SetWindowXY(hWnd, rc.right, rc.bottom - g_Const.cyDog);
								Sleep(60);

								TSWC_SetBitmap(hWnd, g_hbm[IIDX_DOGWALK1 + i]);
								++i;
								if (i == 2)
									i = 0;

								if (g_uTime >= 1068u)
								{
									TSCALL_DestroyWindow(hWnd);
									return 0;
								}
							}

							return 0;
						}, (void*)g_hWnd[HIDX_DOGFOLLOWING1]));
				}
				break;

				case HIDX_DOGFOLLOWING2:
				{
					RECT rc;
					GetWindowRect(g_hWnd[HIDX_YUKIWALK], &rc);
					g_hWnd[HIDX_DOGFOLLOWING2] = WC_Create(L"",
						rc.right,
						rc.bottom - g_Const.cyDog,
						g_Const.cxDog,
						g_Const.cyDog);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOGFOLLOWING2], 1));
					CloseHandle(CRTCreateThread([](void* pParam)->UINT
						{
							HWND hWnd = (HWND)pParam;
							RECT rc;
							int i = 0;
							for (;;)
							{
								GetWindowRect(g_hWnd[HIDX_DOGFOLLOWING1], &rc);
								SetWindowXY(hWnd, rc.right - (rc.right - rc.left) / 2, rc.top);
								Sleep(60);

								TSWC_SetBitmap(hWnd, g_hbm[IIDX_DOGWALK1 + i]);
								++i;
								if (i == 2)
									i = 0;

								if (g_uTime >= 1068u)
								{
									TSCALL_DestroyWindow(hWnd);
									return 0;
								}
							}

							return 0;
						}, (void*)g_hWnd[HIDX_DOGFOLLOWING2]));
				}
				break;

				case HIDX_YUKIBACK:
				{
					RECT rc;
					GetWindowRect(g_hBK, &rc);
					g_hWnd[HIDX_YUKIBACK] = WC_Create(L"",
						rc.right - g_Const.cxYuKiBack,
						rc.bottom - g_Const.cyYuKiBack,
						g_Const.cxYuKiBack,
						g_Const.cyYuKiBack);
					WC_SetBitmap(g_hWnd[HIDX_YUKIBACK], g_hbm[IIDX_YUKIBACK]);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_YUKIBACK], 1));
				}
				break;

				case HIDX_YUKIAHHHH:
				{
					RECT rc;
					GetWindowRect(g_hBK, &rc);
					g_hWnd[HIDX_YUKIAHHHH] = WC_Create(L"",
						(g_Const.cxScreen - g_Const.cxYuKiAhhhh) / 2,
						(g_Const.cyScreen - g_Const.cyYuKiAhhhh) / 2,
						g_Const.cxYuKiAhhhh,
						g_Const.cyYuKiAhhhh);
					WC_SetBitmap(g_hWnd[HIDX_YUKIAHHHH], g_hbm[IIDX_AHHHH]);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_YUKIAHHHH], 1));

					static constexpr CRTThread pfnCreateDlg = [](void* pParam)->UINT
						{
							UINT uType = (UINT)(UINT_PTR)pParam;
							WCHAR szPath[MAX_PATH];
							GetModuleFileNameW(NULL, szPath, MAX_PATH);
							PCWSTR pszFileName = PathFindFileNameW(szPath);
							TASKDIALOGCONFIG tdc{ sizeof(tdc) };
							tdc.dwFlags = TDF_USE_HICON_MAIN | TDF_USE_COMMAND_LINKS | TDF_ALLOW_DIALOG_CANCELLATION;
							tdc.pszWindowTitle = pszFileName;
							tdc.hMainIcon = LoadIconW(NULL, IDI_APPLICATION);

							constexpr WCHAR szBack[] = L" 已停止工作";
							PWSTR pszMain = (PWSTR)_malloca(wcslen(pszFileName) * sizeof(WCHAR) + sizeof(szBack));
							wcscpy(pszMain, pszFileName);
							wcscat(pszMain, szBack);
							tdc.pszMainInstruction = pszMain;
							tdc.pszContent = L"程序无法正常运行，因为有鸽子在大乱斗";

							TASKDIALOG_BUTTON Btns[2];
							Btns[0].nButtonID = 101;
							Btns[0].pszButtonText = L"关闭程序";
							Btns[1].nButtonID = 102;
							Btns[1].pszButtonText = L"赶走鸽子(*￣︿￣)";

							tdc.cButtons = ARRAYSIZE(Btns);
							tdc.pButtons = Btns;

							tdc.pfCallback = [](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, LONG_PTR pRefData)->HRESULT
								{
									switch (uMsg)
									{
									case TDN_CREATED:
									{
										UINT uType = (UINT)pRefData;
										g_hWnd[HIDX_TD1 + uType] = hWnd;
										RECT rc;
										GetWindowRect(hWnd, &rc);
										rc.left = g_Const.cxScreen / 12 + (g_Const.iTDGap * uType);
										rc.top = g_Const.cyScreen / 12 + (g_Const.iTDGap * uType);
										SetWindowXY(hWnd, rc.left, rc.top);
									}
									break;

									case TDN_BUTTON_CLICKED:
										return S_OK;
									}

									return S_FALSE;
								};
							tdc.lpCallbackData = uType;

							int n1, n2;
							BOOL b1;
							TaskDialogIndirect(&tdc, &n1, &n2, &b1);
							_freea(pszMain);
							return 0;
						};

					CloseHandle(CRTCreateThread([](void* pParam)->UINT
						{
							constexpr DWORD dwGapTime = 80;
							CloseHandle(CRTCreateThread(pfnCreateDlg, (void*)0));
							Sleep(dwGapTime);
							CloseHandle(CRTCreateThread(pfnCreateDlg, (void*)1));
							Sleep(dwGapTime);
							CloseHandle(CRTCreateThread(pfnCreateDlg, (void*)2));
							Sleep(dwGapTime);
							CloseHandle(CRTCreateThread(pfnCreateDlg, (void*)3));
							Sleep(dwGapTime);
							CloseHandle(CRTCreateThread(pfnCreateDlg, (void*)4));
							return 0;
						}));
				}
				break;

				case HIDX_TRIANGLE1:
				{
					RECT rc;
					GetWindowRect(g_hBK, &rc);
					const int iPadding = (rc.right - rc.left) / 10;
					g_hWnd[HIDX_TRIANGLE1] = WC_Create(L"",
						rc.left+iPadding,
						(g_Const.cyScreen - g_Const.cyTriangle) / 2,
						g_Const.cxTriangle,
						g_Const.cyTriangle);

					g_hWnd[HIDX_TRIANGLE2] = WC_Create(L"",
						rc.right - iPadding-g_Const.cxTriangle,
						(g_Const.cyScreen - g_Const.cyTriangle) / 2,
						g_Const.cxTriangle,
						g_Const.cyTriangle);

					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_TRIANGLE1], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_TRIANGLE2], 1));
					CreateAnThread(&g_hWnd[HIDX_TRIANGLE1], 2, &g_hbm[IIDX_TRIANGLE1], 2, 300, 1148u);
				}
				break;

				case HIDX_YUKICUT1_1:
					CreateYuKiCutThread(HIDX_YUKICUT1_1, 120, 1460u);
					break;
				case HIDX_YUKICUT2_1:
					CreateYuKiCutThread(HIDX_YUKICUT2_1, 120, 1500u);
					CreateYuKiCutThread(HIDX_YUKICUT2_2, 120, 1500u);
					break;
				case HIDX_YUKICUT3_1:
				case HIDX_YUKICUT3_2:
				case HIDX_YUKICUT3_3:
				case HIDX_YUKICUT3_4:
					CreateYuKiCutThread((int)msg.wParam, 100, 1530u);
					break;
				case HIDX_YUKICUT4_1:
					CreateYuKiCutThread(HIDX_YUKICUT4_1, 100, 1538u);
					break;
				case HIDX_YUKICUT5_1:
					CreateYuKiCutThread(HIDX_YUKICUT5_1, 100, 1544u);
					CreateYuKiCutThread(HIDX_YUKICUT5_2, 100, 1544u);
					break;
				case HIDX_YUKICUT6_1:
					CreateYuKiCutThread(HIDX_YUKICUT6_1, 100, 1550u);
					CreateYuKiCutThread(HIDX_YUKICUT6_2, 100, 1550u);
					CreateYuKiCutThread(HIDX_YUKICUT6_3, 100, 1550u);
					break;
				case HIDX_YUKICUT7_1:
					CreateYuKiCutThread(HIDX_YUKICUT7_1, 100, 1560u);
					break;

				case HIDX_HUGEBLOW:
				{
					RECT rc;
					GetWindowRect(g_hBK, &rc);
					g_hWnd[HIDX_HUGEBLOW] = WC_Create(L"",
						rc.left,
						rc.top,
						(rc.right - rc.left),
						(rc.bottom - rc.top));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_HUGEBLOW], 1));
					CloseHandle(CRTCreateThread([](void* pParam)->UINT
						{
							const HWND hWnd = (HWND)pParam;
							TSWC_SetBitmap(hWnd, g_hbm[IIDX_HUGEBLOW1]);
							Sleep(500);
							TSWC_SetBitmap(hWnd, g_hbm[IIDX_HUGEBLOW2]);
							for (;;)
							{
								if (g_uTime >= 1710u)
								{
									TSCALL_DestroyWindow(hWnd);
									return 0;
								}

								Sleep(60);
							}

							return 0;
						}, (void*)g_hWnd[HIDX_HUGEBLOW]));
				}
				break;

				case HIDX_BIRDWAVESIX:
				{
					RECT rc;
					GetWindowRect(g_hBK, &rc);
					const int xLeftEdge = (g_Const.cxScreen - g_Const.cxYuKiJump) / 2;

					g_hWnd[HIDX_BLACKBIRDWAVE1] = WC_Create(L"",
						xLeftEdge - g_Const.cxBirdWave * 3,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxBirdWave,
						g_Const.cyBirdWave);
					g_hWnd[HIDX_BLACKBIRDWAVE2] = WC_Create(L"",
						xLeftEdge - g_Const.cxBirdWave * 2,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxBirdWave,
						g_Const.cyBirdWave);
					g_hWnd[HIDX_BLACKBIRDWAVE3] = WC_Create(L"",
						xLeftEdge - g_Const.cxBirdWave,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxBirdWave,
						g_Const.cyBirdWave);

					g_hWnd[HIDX_WHITEBIRDWAVE1] = WC_Create(L"",
						xLeftEdge + g_Const.cxYuKiJump,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxBirdWave,
						g_Const.cyBirdWave);
					g_hWnd[HIDX_WHITEBIRDWAVE2] = WC_Create(L"",
						xLeftEdge + g_Const.cxYuKiJump + g_Const.cxBirdWave,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxBirdWave,
						g_Const.cyBirdWave);
					g_hWnd[HIDX_WHITEBIRDWAVE3] = WC_Create(L"",
						xLeftEdge + g_Const.cxYuKiJump + g_Const.cxBirdWave * 2,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxBirdWave,
						g_Const.cyBirdWave);

					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_BLACKBIRDWAVE1], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_BLACKBIRDWAVE2], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_BLACKBIRDWAVE3], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_WHITEBIRDWAVE1], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_WHITEBIRDWAVE2], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_WHITEBIRDWAVE3], 1));

					HBITMAP hbm[]{ g_hbm[IIDX_BLACKBIRDWAVE1],g_hbm[IIDX_BLACKBIRDWAVE2],g_hbm[IIDX_BLACKBIRDWAVE3],g_hbm[IIDX_BLACKBIRDWAVE2] };
					CreateAnThread(&g_hWnd[HIDX_BLACKBIRDWAVE1], 3, hbm, 4, 240, 1680u);
					hbm[0] = g_hbm[IIDX_WHITEBIRDWAVE1];
					hbm[1] = g_hbm[IIDX_WHITEBIRDWAVE2];
					hbm[2] = g_hbm[IIDX_WHITEBIRDWAVE3];
					hbm[3] = g_hbm[IIDX_WHITEBIRDWAVE2];
					CreateAnThread(&g_hWnd[HIDX_WHITEBIRDWAVE1], 3, hbm, 4, 240, 1680u);
				}
				break;

				case HIDX_BIRDWAVESIX2:
				{
					RECT rc;
					GetWindowRect(g_hBK, &rc);
					const int xLeftEdge = (g_Const.cxScreen - g_Const.cxBirdWave * 7) / 2;

					g_hWnd[HIDX_BLACKBIRDWAVE1] = WC_Create(L"",
						xLeftEdge,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxBirdWave,
						g_Const.cyBirdWave);
					g_hWnd[HIDX_BLACKBIRDWAVE2] = WC_Create(L"",
						xLeftEdge + g_Const.cxBirdWave * 2,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxBirdWave,
						g_Const.cyBirdWave);
					g_hWnd[HIDX_BLACKBIRDWAVE3] = WC_Create(L"",
						xLeftEdge + g_Const.cxBirdWave * 4,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxBirdWave,
						g_Const.cyBirdWave);
					g_hWnd[HIDX_BLACKBIRDWAVE4] = WC_Create(L"",
						xLeftEdge + g_Const.cxBirdWave * 6,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxBirdWave,
						g_Const.cyBirdWave);

					g_hWnd[HIDX_WHITEBIRDWAVE1] = WC_Create(L"",
						xLeftEdge + g_Const.cxBirdWave,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxBirdWave,
						g_Const.cyBirdWave);
					g_hWnd[HIDX_WHITEBIRDWAVE2] = WC_Create(L"",
						xLeftEdge + g_Const.cxBirdWave * 3,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxBirdWave,
						g_Const.cyBirdWave);
					g_hWnd[HIDX_WHITEBIRDWAVE3] = WC_Create(L"",
						xLeftEdge + g_Const.cxBirdWave * 5,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxBirdWave,
						g_Const.cyBirdWave);

					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_BLACKBIRDWAVE1], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_BLACKBIRDWAVE2], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_BLACKBIRDWAVE3], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_BLACKBIRDWAVE4], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_WHITEBIRDWAVE1], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_WHITEBIRDWAVE2], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_WHITEBIRDWAVE3], 1));

					HBITMAP hbm[]{ g_hbm[IIDX_BLACKBIRDWAVE1],g_hbm[IIDX_BLACKBIRDWAVE2],g_hbm[IIDX_BLACKBIRDWAVE3],g_hbm[IIDX_BLACKBIRDWAVE2] };
					CreateAnThread(&g_hWnd[HIDX_BLACKBIRDWAVE1], 4, hbm, 4, 240, 2330u);
					hbm[0] = g_hbm[IIDX_WHITEBIRDWAVE1];
					hbm[1] = g_hbm[IIDX_WHITEBIRDWAVE2];
					hbm[2] = g_hbm[IIDX_WHITEBIRDWAVE3];
					hbm[3] = g_hbm[IIDX_WHITEBIRDWAVE2];
					CreateAnThread(&g_hWnd[HIDX_WHITEBIRDWAVE1], 3, hbm, 4, 240, 2330u);
				}
				break;

				case HIDX_BIRDWAVEFOUR:
				{
					RECT rc;
					GetWindowRect(g_hBK, &rc);
					const int cxGap = (rc.right - rc.left - g_Const.cxBirdWave) / 3;

					g_hWnd[HIDX_BLACKBIRDWAVE1] = WC_Create(L"",
						rc.left + cxGap,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxBirdWave,
						g_Const.cyBirdWave);
					g_hWnd[HIDX_BLACKBIRDWAVE2] = WC_Create(L"",
						rc.left + cxGap * 3,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxBirdWave,
						g_Const.cyBirdWave);

					g_hWnd[HIDX_WHITEBIRDWAVE1] = WC_Create(L"",
						rc.left,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxBirdWave,
						g_Const.cyBirdWave);
					g_hWnd[HIDX_WHITEBIRDWAVE2] = WC_Create(L"",
						rc.left + cxGap * 2,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxBirdWave,
						g_Const.cyBirdWave);

					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_BLACKBIRDWAVE1], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_BLACKBIRDWAVE2], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_WHITEBIRDWAVE1], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_WHITEBIRDWAVE2], 1));

					HBITMAP hbm[]{ g_hbm[IIDX_BLACKBIRDWAVE1],g_hbm[IIDX_BLACKBIRDWAVE2],g_hbm[IIDX_BLACKBIRDWAVE3],g_hbm[IIDX_BLACKBIRDWAVE2] };
					CreateAnThread(&g_hWnd[HIDX_BLACKBIRDWAVE1], 2, hbm, 4, 240, 1988u);
					hbm[0] = g_hbm[IIDX_WHITEBIRDWAVE1];
					hbm[1] = g_hbm[IIDX_WHITEBIRDWAVE2];
					hbm[2] = g_hbm[IIDX_WHITEBIRDWAVE3];
					hbm[3] = g_hbm[IIDX_WHITEBIRDWAVE2];
					CreateAnThread(&g_hWnd[HIDX_WHITEBIRDWAVE1], 2, hbm, 4, 240, 1988u);
				}
				break;

				case HIDX_BWYUKI1:
				{
					static const float f[]{ 0.f,0.16666667f,0.33333334f,0.5f,0.6666667f,0.8333333f,1.f };
					const int xStart = (g_Const.cxScreen - g_Const.cxBWYuKi) / 2 + (int)g_Const.fBWYuKiMaxMove;
					const int yStart = (g_Const.cyScreen - g_Const.cyBWYuKi) / 2;
					RECT rc;
					for (int i = 0; i < 7; ++i)
					{
						g_hWnd[HIDX_BWYUKI1 + i] = WC_Create(L"",
							xStart + (int)(f[i] * g_Const.fBWYuKiMaxMove),
							yStart + (int)(g_Const.fBWYuKiCoefficient * sinf(f[i] * 2.f * std::numbers::pi_v<float>)),
							g_Const.cxBWYuKi,
							g_Const.cyBWYuKi,
							FALSE);
						g_RefCount.insert(std::make_pair(g_hWnd[HIDX_BWYUKI1 + i], 1));
						TSWC_SetBitmap(g_hWnd[HIDX_BWYUKI1 + i], g_hbm[IIDX_BWYUKI]);
						GetClientRect(g_hWnd[HIDX_BWYUKI1 + i], &rc);
						SendMessageW(g_hWnd[HIDX_BWYUKI1 + i], WM_SIZE, 0, MAKELPARAM(rc.right, rc.bottom));
					}

					CloseHandle(CRTCreateThread([](void* pParam)->UINT
						{
							for (int i = 0; i < 7; ++i)
							{
								InvalidateRect(g_hWnd[HIDX_BWYUKI1 + i], NULL, FALSE);
								ShowWindow(g_hWnd[HIDX_BWYUKI1 + i], SW_SHOW);
								if (i == 5)
									TSCALL_CreateWindow(HIDX_YUKIPEEK);
								Sleep(160);
							}
							return 0;
						}, NULL));
				}
				break;

				case HIDX_YUKIPEEK:
				{
					g_hWnd[HIDX_YUKIPEEK] = WC_Create(L"",
						g_Const.cxScreen - g_Const.cxYuKiPeek,
						g_Const.cyScreen - g_Const.cyYuKiPeek - DPI(40),
						g_Const.cxYuKiPeek,
						g_Const.cyYuKiPeek, TRUE, TRUE);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_YUKIPEEK], 1));
					TSWC_SetBitmap(g_hWnd[HIDX_YUKIPEEK], g_hbm[IIDX_YUKIPEEK]);
				}
				break;

				case HIDX_YUKIPEEK2:
				{
					g_hWnd[HIDX_YUKIPEEK] = WC_Create(L"",
						g_Const.cxScreen - g_Const.cxYuKiPeek,
						g_Const.cyScreen - g_Const.cyYuKiPeek - DPI(40),
						g_Const.cxYuKiPeek,
						g_Const.cyYuKiPeek, TRUE, TRUE);
					g_hWnd[HIDX_YUKIPEEK2] = WC_Create(L"",
						0,
						g_Const.cyScreen - g_Const.cyYuKiPeek - DPI(40),
						g_Const.cxYuKiPeek,
						g_Const.cyYuKiPeek, TRUE, TRUE);

					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_YUKIPEEK], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_YUKIPEEK2], 1));

					TSWC_SetBitmap(g_hWnd[HIDX_YUKIPEEK], g_hbm[IIDX_YUKIPEEK]);
					TSWC_SetBitmap(g_hWnd[HIDX_YUKIPEEK2], g_hbm[IIDX_YUKIPEEK2]);
				}
				break;

				case HIDX_YUKIPEEKWITHBIRD:
				{
					g_hWnd[HIDX_YUKIPEEKWITHBIRD] = WC_Create(L"",
						g_Const.cxScreen - g_Const.cxYuKiPeekWithBird,
						g_Const.cyScreen - g_Const.cyYuKiPeekWithBird - DPI(40),
						g_Const.cxYuKiPeekWithBird,
						g_Const.cyYuKiPeekWithBird, TRUE, TRUE);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_YUKIPEEKWITHBIRD], 1));
					TSWC_SetBitmap(g_hWnd[HIDX_YUKIPEEKWITHBIRD], g_hbm[IIDX_YUKIPEEKWITHBIRD]);
				}
				break;

				case HIDX_DOGEIGHT_1:
				{
					RECT rc;
					GetWindowRect(g_hBK, &rc);
					const int xLeftEdge = (g_Const.cxScreen - g_Const.cxYuKiJump) / 2;

					g_hWnd[HIDX_DOG1] = WC_Create(L"",
						xLeftEdge - g_Const.cxDog * 3,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxDog,
						g_Const.cyDog);
					g_hWnd[HIDX_DOG2] = WC_Create(L"",
						xLeftEdge - g_Const.cxDog * 2,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxDog,
						g_Const.cyDog);
					g_hWnd[HIDX_DOG3] = WC_Create(L"",
						xLeftEdge - g_Const.cxDog,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxDog,
						g_Const.cyDog);
					g_hWnd[HIDX_DOG4] = WC_Create(L"",
						xLeftEdge + g_Const.cxYuKiJump,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxDog,
						g_Const.cyDog);
					g_hWnd[HIDX_DOG5] = WC_Create(L"",
						xLeftEdge + g_Const.cxYuKiJump + g_Const.cxDog,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxDog,
						g_Const.cyDog);
					g_hWnd[HIDX_DOG6] = WC_Create(L"",
						xLeftEdge + g_Const.cxYuKiJump + g_Const.cxDog * 2,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxDog,
						g_Const.cyDog);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOG1], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOG2], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOG3], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOG4], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOG5], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOG6], 1));
					CreateAnThread(&g_hWnd[HIDX_DOG1], 6, &g_hbm[IIDX_DOGWALK1], 2, 60, 2130u);
				}
				break;
				case HIDX_DOGEIGHT_2:
				{
					RECT rc;
					GetWindowRect(g_hBK, &rc);
					const int xLeftEdge = (g_Const.cxScreen - g_Const.cxYuKiJump) / 2;

					g_hWnd[HIDX_DOG7] = WC_Create(L"",
						xLeftEdge - g_Const.cxDog * 4,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxDog,
						g_Const.cyDog);
					g_hWnd[HIDX_DOG8] = WC_Create(L"",
						xLeftEdge + g_Const.cxYuKiJump + g_Const.cxDog * 3,
						rc.top + (rc.bottom - rc.top) * 7 / 10,
						g_Const.cxDog,
						g_Const.cyDog);
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOG7], 1));
					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_DOG8], 1));
					CreateAnThread(&g_hWnd[HIDX_DOG7], 2, &g_hbm[IIDX_DOGWALK1], 2, 60, 2130u);
				}
				break;

				case HIDX_EGG:
				{
					g_hWnd[HIDX_EGG] = WC_Create(L"",
						(g_Const.cxScreen - g_Const.cxEgg) / 2,
						(g_Const.cyScreen - g_Const.cyEgg) / 2,
						g_Const.cxEgg,
						g_Const.cyEgg);

					g_RefCount.insert(std::make_pair(g_hWnd[HIDX_EGG], 1));
					CloseHandle(CRTCreateThread([](void* pParam)->UINT
						{
							HWND hWnd = (HWND)pParam;

							TSWC_SetBitmap(hWnd, g_hbm[IIDX_EGG1]);
							Sleep(500);
							TSWC_SetBitmap(hWnd, g_hbm[IIDX_EGG2]);
							Sleep(500);
							TSCALL_DestroyWindow(hWnd);

							return 0;
						}, (void*)g_hWnd[HIDX_EGG]));
				}
				break;
				}
			}
			break;
			case THM_QUIT:
				PostQuitMessage(0);
				break;
			}
		}
	}
	
	WICUniInit();
	timeKillEvent(g_idTimer);
	for (auto x : g_hbm)
		DeleteObject(x);
	BASS_StreamFree(g_hStream);
	BASS_Free();
	DestroyWindow(g_hBK);

	CoUninitialize();
	return (int)msg.wParam;
}

void CALLBACK TimerProc(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2)
{
	++g_uTime;
	switch (g_uTime)
	{
	case 10u:
		TSCALL_CreateWindow(HIDX_YUKIJUMPD);
		TSCALL_CreateWindow(HIDX_DOGTWO1);
		TSWB_SetText(L"外出た瞬間");
		return;

	case 40u:
		TSWB_SetText(L"終わったわ");
		return;

	case 64u:
		TSCALL_CreateWindow(HIDX_YUKICLAP);
		break;

	case 76u:
		TSWB_SetText(L"天気は良いのに");
		return;

	case 120u:
		TSWB_SetText(L"進めない");
		return;

	case 140u:
		TSWB_SetText(L"風");
		return;

	case 150u:
		TSCALL_CreateWindow(HIDX_YUKIJUMPMOVE);
		TSCALL_CreateWindow(HIDX_DOGMOVEROLL1_1);
		TSWB_SetText(L"強すぎて");
		return;

	case 180u:
		TSWB_SetText(L"お亡くなり");
		return;

	case 200u:
		TSCALL_CreateWindow(HIDX_YUKICLAP);
		break;

	case 220u:
	{
		TSCALL_CreateWindow(HIDX_YUKIJUMPS1);
		RECT rc;
		GetClientRect(g_hBK, &rc);
		rc.right = rc.right / 2;
		rc.top = rc.bottom / 10;
		TSWB_SetLabel(0, L"定期", &rc, DT_SINGLELINE | DT_RIGHT);

		TSWB_SetLabelCount(1);
	}
	return;

	case 230u:
	{
		TSCALL_CreateWindow(HIDX_YUKIJUMPS2);
		RECT rc;
		GetClientRect(g_hBK, &rc);
		rc.left = rc.right / 2;
		rc.top = rc.bottom / 10;
		TSWB_SetLabel(1, L"定期", &rc, DT_SINGLELINE);

		TSWB_SetLabelCount(2);
	}
	return;

	case 240u:
	{
		TSCALL_CreateWindow(HIDX_YUKIJUMPS3);
		RECT rc;
		GetClientRect(g_hBK, &rc);
		rc.top = rc.bottom / 2;
		TSWB_SetLabel(2, L"的に", &rc, DT_SINGLELINE | DT_CENTER);

		TSWB_SetLabelCount(3);
	}
	return;

	case 260u:
		TSCALL_CreateWindow(HIDX_DOGFIVE1);
		TSWB_SetLabelCount(0);
		TSWB_SetText(L"オールバック");
		return;

	case 280u:
		TSCALL_CreateWindow(HIDX_YUKIJUMPBLOW);
		TSCALL_CreateWindow(HIDX_BLACKBIRD);
		TSCALL_CreateWindow(HIDX_WHITEBIRD);
		return;

	case 366u:
		TSWB_SetColor(c_crBlue);
		return;

	case 440u:
		TSWB_SetColor(c_crYellow);
		return;

	case 510u:
		TSWB_SetColor(c_crBlue);
		return;

	case 580u:
		TSWB_SetColor(c_crYellow);
		TSCALL_CreateWindow(HIDX_YUKIWALK);
		TSWB_SetText(L"地下に");
		return;

	case 610u:
		TSWB_SetText(L"潜りたいな");
		return;

	case 660u:
		TSWB_SetText(L"って");
		return;

	case 680u:
		TSWB_SetText(L"思いました");
		return;

	case 720u:
		TSWB_SetText(L"風さえ");
		return;

	case 760u:
		TSCALL_CreateWindow(HIDX_DOGMOVEROLL2_1);
		TSWB_SetText(L"なくなれば");
		return;

	case 820u:
		TSWB_SetText(L"あったかいのに");
		return;

	case 860u:
		TSCALL_CreateWindow(HIDX_DOGFOLLOWING1);
		TSWB_SetText(L"ずっと");
		return;

	case 900u:
		TSCALL_CreateWindow(HIDX_DOGMOVEROLL2_2);
		TSWB_SetText(L"座りたいな");
		return;

	case 950u:
		TSWB_SetText(L"って");
		return;

	case 960u:
		TSWB_SetText(L"思いました");
		return;

	case 1000u:
		TSCALL_CreateWindow(HIDX_DOGFOLLOWING2);
		TSWB_SetText(L"いやいや");
		return;

	case 1034u:
		TSWB_SetText(L"と");
		return;

	case 1040u:
		TSWB_SetText(L"外でたら");
		return;

	case 1074u:
	{
		TSCALL_CreateWindow(HIDX_GREYPIGEON1);
		RECT rc;
		GetClientRect(g_hBK, &rc);
		rc.top = rc.bottom / 10;
		rc.left = 0;
		TSWB_SetLabel(0, L"ハト", &rc, DT_SINGLELINE);

		TSWB_SetLabelCount(1);
	}
	return;

	case 1080u:
	{
		TSCALL_CreateWindow(HIDX_GREYPIGEON2);
		RECT rc;
		GetClientRect(g_hBK, &rc);
		rc.top = rc.bottom / 10;
		rc.left = rc.right * 7 * 1 / 10 / 4;
		TSWB_SetLabel(0, L"ハト", &rc, DT_SINGLELINE);

		TSWB_SetLabelCount(1);
	}
	return;

	case 1090u:
	{
		TSCALL_CreateWindow(HIDX_GREYPIGEON3);
		RECT rc;
		GetClientRect(g_hBK, &rc);
		rc.top = rc.bottom / 10;
		rc.left = rc.right * 7 * 2 / 10 / 4;
		TSWB_SetLabel(0, L"ハト", &rc, DT_SINGLELINE);

		TSWB_SetLabelCount(1);
	}
	return;

	case 1100u:
	{
		TSCALL_CreateWindow(HIDX_WHITEPIGEON);
		RECT rc;
		GetClientRect(g_hBK, &rc);
		rc.top = rc.bottom / 10;
		rc.left = rc.right * 7 * 3 / 10 / 4;
		TSWB_SetLabel(0, L"ハト", &rc, DT_SINGLELINE);

		TSWB_SetLabelCount(1);
	}
	return;

	case 1108u:
		TSCALL_CreateWindow(HIDX_FIGHT);
		TSWB_SetLabelCount(0);
		TSWB_SetText(L"大乱闘");
		return;

	case 1114u:
		TSCALL_CreateWindow(HIDX_YUKIBACK);
		return;

	case 1136:
		TSCALL_DestroyWindow(g_hWnd[HIDX_GREYPIGEON1]);
		TSCALL_DestroyWindow(g_hWnd[HIDX_GREYPIGEON2]);
		TSCALL_DestroyWindow(g_hWnd[HIDX_GREYPIGEON3]);
		TSCALL_DestroyWindow(g_hWnd[HIDX_WHITEPIGEON]);
		TSCALL_DestroyWindow(g_hWnd[HIDX_YUKIBACK]);
		TSCALL_CreateWindow(HIDX_TRIANGLE1);
		TSCALL_CreateWindow(HIDX_YUKIAHHHH);
		break;

	case 1150u:
		TSCALL_DestroyWindow(g_hWnd[HIDX_YUKIAHHHH]);
		PostMessageW(g_hWnd[HIDX_TD1], WM_CLOSE, 0, 0);
		PostMessageW(g_hWnd[HIDX_TD2], WM_CLOSE, 0, 0);
		PostMessageW(g_hWnd[HIDX_TD3], WM_CLOSE, 0, 0);
		PostMessageW(g_hWnd[HIDX_TD4], WM_CLOSE, 0, 0);
		PostMessageW(g_hWnd[HIDX_TD5], WM_CLOSE, 0, 0);
		TSCALL_CreateWindow(HIDX_YUKIJUMPD2);
		TSCALL_CreateWindow(HIDX_DOGFOUR);
		TSWB_SetText(L"外出た瞬間");
		return;

	case 1180u:
		TSWB_SetText(L"終わったわ");
		return;

	case 1200u:
		TSCALL_CreateWindow(HIDX_YUKICLAP);
		break;

	case 1220u:
		TSWB_SetText(L"天気は良いのに");
		return;

	case 1246u:
		TSWB_SetText(L"進めない");
		return;

	case 1280u:
		TSWB_SetText(L"風");
		return;

	case 1290u:
		TSCALL_CreateWindow(HIDX_YUKIJUMPMOVE2);
		TSCALL_CreateWindow(HIDX_DOGMOVEROLL3_1);
		TSWB_SetText(L"強すぎて");
		return;

	case 1320u:
		TSWB_SetText(L"お亡くなり");
		return;

	case 1340u:
		TSCALL_CreateWindow(HIDX_YUKICLAP);
		break;

	case 1356u:
	{
		TSCALL_CreateWindow(HIDX_YUKIJUMPS2_1);
		RECT rc;
		GetClientRect(g_hBK, &rc);
		rc.right = rc.right / 2;
		rc.top = rc.bottom / 10;
		TSWB_SetLabel(0, L"定期", &rc, DT_SINGLELINE | DT_RIGHT);

		TSWB_SetLabelCount(1);
	}
	return;

	case 1366u:
	{
		TSCALL_CreateWindow(HIDX_YUKIJUMPS2_2);
		RECT rc;
		GetClientRect(g_hBK, &rc);
		rc.left = rc.right / 2;
		rc.top = rc.bottom / 10;
		TSWB_SetLabel(1, L"定期", &rc, DT_SINGLELINE);

		TSWB_SetLabelCount(2);
	}
	return;

	case 1376u:
	{
		TSCALL_CreateWindow(HIDX_YUKIJUMPS2_3);
		RECT rc;
		GetClientRect(g_hBK, &rc);
		rc.top = rc.bottom / 2;
		TSWB_SetLabel(2, L"的に", &rc, DT_SINGLELINE | DT_CENTER);

		TSWB_SetLabelCount(3);
	}
	return;

	case 1390u:
		TSCALL_CreateWindow(HIDX_DOGFOUR2);
		TSWB_SetLabelCount(0);
		TSWB_SetText(L"オールバック");
		return;

	case 1400u:
		TSCALL_CreateWindow(HIDX_YUKICLAP);
		break;

	case 1430u:
		TSCALL_CreateWindow(HIDX_YUKICUT1_1);
		break;

	case 1460u:
		TSCALL_CreateWindow(HIDX_YUKICUT2_1);
		break;

	case 1500u:
		TSCALL_CreateWindow(HIDX_YUKICUT3_1);
		break;
	case 1508u:
		TSCALL_CreateWindow(HIDX_YUKICUT3_2);
		break;
	case 1516u:
		TSCALL_CreateWindow(HIDX_YUKICUT3_3);
		break;
	case 1524u:
		TSCALL_CreateWindow(HIDX_YUKICUT3_4);
		break;
	case 1530u:
		TSCALL_CreateWindow(HIDX_YUKICUT4_1);
		TSCALL_CreateWindow(HIDX_YUKICLAP);
		break;
	case 1538u:
		TSCALL_CreateWindow(HIDX_YUKICUT5_1);
		break;
	case 1544u:
		TSCALL_CreateWindow(HIDX_YUKICUT6_1);
		break;
	case 1550u:
		TSCALL_CreateWindow(HIDX_YUKICUT7_1);
		break;
	case 1570u:
		TSCALL_CreateWindow(HIDX_YUKIJUMPBLOW2);
		TSCALL_CreateWindow(HIDX_BIRDWAVESIX);
		break;

	case 1680u:
		TSCALL_CreateWindow(HIDX_HUGEBLOW);
		break;

	case 1720u:
		TSCALL_CreateWindow(HIDX_BWYUKI1);
		TSWB_SetText(L"外出た瞬間");
		return;

	case 1750u:
		TSCALL_DestroyWindow(g_hWnd[HIDX_YUKIPEEK]);
		for (int i = 0; i < 7; ++i)
			TSCALL_DestroyWindow(g_hWnd[HIDX_BWYUKI1 + i]);
		TSCALL_CreateWindow(HIDX_YUKIJUMPD3);
		TSCALL_CreateWindow(HIDX_DOGTWO2);
		TSWB_SetText(L"終わったわ");
		return;

	case 1770u:
		TSCALL_CreateWindow(HIDX_YUKICLAP);
		break;

	case 1790u:
		TSWB_SetText(L"天気は良いのに");
		return;

	case 1826u:
		TSWB_SetText(L"進めない");
		return;

	case 1860u:
		TSWB_SetText(L"風");
		return;

	case 1870u:
		TSCALL_CreateWindow(HIDX_YUKIJUMPMOVE3);
		TSCALL_CreateWindow(HIDX_DOGMOVEROLL4_1);
		TSWB_SetText(L"強すぎて");
		return;

	case 1900u:
		TSCALL_CreateWindow(HIDX_YUKICLAP);
		TSWB_SetText(L"お亡くなり");
		return;

	case 1928u:
	{
		TSCALL_CreateWindow(HIDX_YUKIJUMPS3_1);
		RECT rc;
		GetClientRect(g_hBK, &rc);
		rc.right = rc.right / 2;
		rc.top = rc.bottom / 10;
		TSWB_SetLabel(0, L"定期", &rc, DT_SINGLELINE | DT_RIGHT);

		TSWB_SetLabelCount(1);
	}
	return;

	case 1938u:
	{
		TSCALL_CreateWindow(HIDX_YUKIJUMPS3_2);
		RECT rc;
		GetClientRect(g_hBK, &rc);
		rc.left = rc.right / 2;
		rc.top = rc.bottom / 10;
		TSWB_SetLabel(1, L"定期", &rc, DT_SINGLELINE);

		TSWB_SetLabelCount(2);
	}
	return;

	case 1948u:
	{
		TSCALL_CreateWindow(HIDX_YUKIJUMPS3_3);
		RECT rc;
		GetClientRect(g_hBK, &rc);
		rc.top = rc.bottom / 2;
		TSWB_SetLabel(2, L"的に", &rc, DT_SINGLELINE | DT_CENTER);

		TSWB_SetLabelCount(3);
	}
	return;

	case 1970u:
		TSWB_SetLabelCount(0);
		TSCALL_CreateWindow(HIDX_BIRDWAVEFOUR);
		TSWB_SetText(L"オールバック");
		return;

	case 1988u:
		TSCALL_CreateWindow(HIDX_YUKIPEEKWITHBIRD);
		TSWB_SetText(L"そっ");
		return;

	case 2000u:
		TSWB_SetText(L"と");
		return;

	case 2010u:
		TSCALL_DestroyWindow(g_hWnd[HIDX_YUKIPEEKWITHBIRD]);
		TSCALL_CreateWindow(HIDX_YUKIJUMPD4);
		TSCALL_CreateWindow(HIDX_DOGEIGHT_1);
		TSWB_SetText(L"出た瞬間");
		return;

	case 2020u:
		TSCALL_CreateWindow(HIDX_YUKICLAP);
		break;

	case 2030u:
		TSWB_SetText(L"終わったわ");
		return;

	case 2060u:
		TSCALL_CreateWindow(HIDX_DOGEIGHT_2);
		TSWB_SetText(L"天気は良いのに");
		return;

	case 2096u:
		TSWB_SetText(L"進めない");
		return;

	case 2130u:
		TSCALL_CreateWindow(HIDX_FIGHT2);
		TSWB_SetText(L"風");
		return;

	case 2140u:
		TSCALL_CreateWindow(HIDX_YUKIJUMPMOVE4);
		TSCALL_CreateWindow(HIDX_DOGMOVEROLL5_1);
		TSWB_SetText(L"強すぎて");
		return;

	case 2174u:
		TSWB_SetText(L"お亡くなり");
		return;

	case 2200u:
	{
		TSCALL_CreateWindow(HIDX_YUKIJUMPS4_1);
		RECT rc;
		GetClientRect(g_hBK, &rc);
		rc.right = rc.right / 2;
		rc.top = rc.bottom / 10;
		TSWB_SetLabel(0, L"定期", &rc, DT_SINGLELINE | DT_RIGHT);

		TSWB_SetLabelCount(1);
	}
	return;

	case 2210u:
	{
		TSCALL_CreateWindow(HIDX_YUKIJUMPS4_2);
		RECT rc;
		GetClientRect(g_hBK, &rc);
		rc.left = rc.right / 2;
		rc.top = rc.bottom / 10;
		TSWB_SetLabel(1, L"定期", &rc, DT_SINGLELINE);

		TSWB_SetLabelCount(2);
	}
	return;

	case 2220u:
	{
		TSCALL_CreateWindow(HIDX_YUKIJUMPS4_3);
		RECT rc;
		GetClientRect(g_hBK, &rc);
		rc.top = rc.bottom / 2;
		TSWB_SetLabel(2, L"的に", &rc, DT_SINGLELINE | DT_CENTER);

		TSWB_SetLabelCount(3);
	}
	return;

	case 2250u:
		TSWB_SetLabelCount(0);
		TSCALL_CreateWindow(HIDX_DOGMOVEROLL6_1);
		TSWB_SetText(L"オールバック");
		return;

	case 2280u:
		TSCALL_CreateWindow(HIDX_BIRDWAVESIX2);
		TSWB_SetText(L"髪の毛");
		return;

	case 2320u:
		TSCALL_CreateWindow(HIDX_YUKIPEEK2);
		TSWB_SetText(L"強風");
		return;

	case 2330u:
		TSCALL_DestroyWindow(g_hWnd[HIDX_YUKIPEEK]);
		TSCALL_DestroyWindow(g_hWnd[HIDX_YUKIPEEK2]);
		TSWB_SetText(L"オールバック");
		return;

	case 2336u:
		TSCALL_CreateWindow(HIDX_EGG);
		return;

	case 2350u:
		TSCALL_CreateWindow(HIDX_YUKIJUMPBLOW3);
		TSCALL_CreateWindow(HIDX_BLACKBIRD2);
		TSCALL_CreateWindow(HIDX_WHITEBIRD2);
		return;

	//case 2470u:
	//	// staff
	//	return;

	case 2620u:
		TSCALL_CreateWindow(HIDX_YUKICLAP);
		return;

	case 2720:
		PostThreadMessageW(g_idMainThread, THM_QUIT, 0, 0);
		return;
	}
}