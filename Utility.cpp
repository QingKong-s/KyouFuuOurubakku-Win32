#include "Utility.h"

IWICImagingFactory* g_pWicFactory = NULL;

void WICInit()
{
	CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&g_pWicFactory));
}

void WICUniInit()
{
	g_pWicFactory->Release();
}

HBITMAP WICLoadBitmap(PCWSTR pszFile)
{
	IWICBitmap* pBitmap;
	IWICBitmapDecoder* pDecoder;
	IWICBitmapFrameDecode* pFrameDecoder;
	IWICFormatConverter* pConverter;

	HRESULT hr = g_pWicFactory->CreateDecoderFromFilename(pszFile, NULL, GENERIC_READ, WICDecodeMetadataCacheOnDemand, &pDecoder);

	g_pWicFactory->CreateFormatConverter(&pConverter);

	pDecoder->GetFrame(0, &pFrameDecoder);

	pConverter->Initialize(pFrameDecoder, GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone, NULL, 0.0f, WICBitmapPaletteTypeMedianCut);

	g_pWicFactory->CreateBitmapFromSource(pConverter, WICBitmapNoCache, &pBitmap);

	pFrameDecoder->Release();
	pDecoder->Release();
	pConverter->Release();

	UINT cx, cy;
	pBitmap->GetSize(&cx, &cy);

	BITMAPINFO bmi{};
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = cx;
	bmi.bmiHeader.biHeight = -(int)cy;// 自上而下位图
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	void* pDibBits;
	HDC hDC = GetDC(NULL);
	HBITMAP hBitmap = CreateDIBSection(hDC, &bmi, 0, &pDibBits, NULL, 0);
	ReleaseDC(NULL, hDC);

	pBitmap->CopyPixels(NULL, cx * 4, cx * cy * 4, (BYTE*)pDibBits);// GDI将每行位图数据对齐到DWORD
	pBitmap->Release();
	return hBitmap;
}