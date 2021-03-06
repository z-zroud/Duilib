﻿// ADMonSetup.cpp : Defines the entry point for the application.
//

#include "StdAfx.h"
#include "ADMonSetup.h"
#include "MainWnd.h"

//#include <GdiPlus.h>
//#pragma comment( lib, "GdiPlus.lib" )
//using namespace Gdiplus;

//----------------------------------------------------------------------------------------------------------------------------------------

//³ÌÐòÈë¿Ú´¦µ÷ÓÃ¸Ãº¯Êý½øÐÐÄÚ´æÐ¹Â¶¼ì²â
//³ÌÐòÍË³öÇ°µ÷ÓÃ_CrtDumpMemoryLeaks();º¯Êý¿É²é¿´ÄÚ´æÐ¹Â¶µÄIDºÅ£¬¸ÃIDºÅ¿É×÷ÎªBreakpointµÄ²ÎÊý£¬ÔËÐÐÊ±½«»áÔÚÏàÓ¦Î»ÖÃ×Ô¶¯¶Ïµã
inline  void  EnableMemLeakCheck(int Breakpoint = 0){
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG)  |  _CRTDBG_LEAK_CHECK_DF);
	if(Breakpoint)
		_CrtSetBreakAlloc ( 1912 );
}

#ifdef _DEBUG
#define  new   new(_NORMAL_BLOCK, __FILE__, __LINE__) 
#endif 
#define _CRT_SECURE_NO_DEPRECATE

//----------------------------------------------------------------------------------------------------------------------------------------

void InitResource()
{	
	// ×ÊÔ´ÀàÐÍ
	CPaintManagerUI::SetResourceType(UILIB_FILE);
	// ×ÊÔ´Â·¾¶
	CDuiString strResourcePath = CPaintManagerUI::GetInstancePath();
	// ¼ÓÔØ×ÊÔ´
	switch(CPaintManagerUI::GetResourceType())
	{
	case UILIB_FILE:
		{
			strResourcePath += _T("skin\\ADMonSetup\\");
			CPaintManagerUI::SetResourcePath(strResourcePath.GetData());
			// ¼ÓÔØ×ÊÔ´¹ÜÀíÆ÷
			CResourceManager::GetInstance()->LoadResource(_T("DlgMain.xml"), NULL);
			break;
		}
	case UILIB_RESOURCE:
		{
			strResourcePath += _T("skin\\ADMonSetup\\");
			CPaintManagerUI::SetResourcePath(strResourcePath.GetData());
			// ¼ÓÔØ×ÊÔ´¹ÜÀíÆ÷
			CResourceManager::GetInstance()->LoadResource(_T("IDR_RES"), _T("xml"));
			break;
		}
	case UILIB_ZIP:
		{
			strResourcePath += _T("skin\\");
			CPaintManagerUI::SetResourcePath(strResourcePath.GetData());
			CPaintManagerUI::SetResourceZip(_T("ADMonSetup.zip"), true);
			// ¼ÓÔØ×ÊÔ´¹ÜÀíÆ÷
			CResourceManager::GetInstance()->LoadResource(_T("res.xml"), NULL);
			break;
		}
	case UILIB_ZIPRESOURCE:
		{
			strResourcePath += _T("skin\\ADMonSetup\\");
			CPaintManagerUI::SetResourcePath(strResourcePath.GetData());

			HRSRC hResource = ::FindResource(CPaintManagerUI::GetResourceDll(), _T("IDR_ZIPRES"), _T("ZIPRES"));
			if( hResource != NULL ) {
				DWORD dwSize = 0;
				HGLOBAL hGlobal = ::LoadResource(CPaintManagerUI::GetResourceDll(), hResource);
				if( hGlobal != NULL ) {
					dwSize = ::SizeofResource(CPaintManagerUI::GetResourceDll(), hResource);
					if( dwSize > 0 ) {
						CPaintManagerUI::SetResourceZip((LPBYTE)::LockResource(hGlobal), dwSize);
						// ¼ÓÔØ×ÊÔ´¹ÜÀíÆ÷
						CResourceManager::GetInstance()->LoadResource(_T("res.xml"), NULL);
					}
				}
				::FreeResource(hResource);
			}
		}
		break;
	}
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	EnableMemLeakCheck();

	//GdiplusStartupInput   gdiplusStartupInput;
	//ULONG_PTR             gdiplusToken;
	//GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	HRESULT Hr = ::CoInitialize(NULL);
	if( FAILED(Hr) ) return 0;

	CPaintManagerUI::SetInstance(hInstance);
	InitResource();

	if( ::LoadLibrary(_T("d3d9.dll")) == NULL ) 
		::MessageBox(NULL, _T("¼ÓÔØ d3d9.dll Ê§°Ü£¬Ò»Ð©ÌØÐ§¿ÉÄÜÎÞ·¨ÏÔÊ¾£¡"), _T("ÐÅÏ¢ÌáÊ¾"),MB_OK|MB_ICONWARNING);

	CMainWnd* pFrame = new CMainWnd();
	if(pFrame == NULL)
		return 0;

	pFrame->Create(NULL,_T("视频过滤大师"), UI_WNDSTYLE_FRAME, 0L, 0, 0, 900, 600);
	pFrame->CenterWindow();
	::ShowWindow(*pFrame, SW_SHOW);
	CPaintManagerUI::MessageLoop();

	::CoUninitialize();
	//GdiplusShutdown(gdiplusToken);

	_CrtDumpMemoryLeaks();
	return 0;
}
