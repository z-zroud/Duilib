// ADMonSetup.cpp : Defines the entry point for the application.
//

#include "StdAfx.h"
#include "CpsPerso.h"
#include "MainWindow.h"


inline  void  EnableMemLeakCheck(int Breakpoint = 0) {
    _CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
    if (Breakpoint)
        _CrtSetBreakAlloc(1912);
}

#ifdef _DEBUG
#define  new   new(_NORMAL_BLOCK, __FILE__, __LINE__) 
#endif 
#define _CRT_SECURE_NO_DEPRECATE

//----------------------------------------------------------------------------------------------------------------------------------------

void InitResource()
{

    CPaintManagerUI::SetResourceType(UILIB_FILE);

    CDuiString strResourcePath = CPaintManagerUI::GetInstancePath();

    strResourcePath += _T("skin\\CpsPerso\\");
    CPaintManagerUI::SetResourcePath(strResourcePath.GetData());
    CResourceManager::GetInstance()->LoadResource(_T("DlgMain.xml"), NULL);

}

int APIENTRY _tWinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPTSTR    lpCmdLine,
    int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    EnableMemLeakCheck();


    HRESULT Hr = ::CoInitialize(NULL);
    if (FAILED(Hr)) return 0;

    CPaintManagerUI::SetInstance(hInstance);
    InitResource();


    CMainWnd* pFrame = new CMainWnd();
    if (pFrame == NULL)
        return 0;

    pFrame->Create(NULL, _T("CpsPerso"), UI_WNDSTYLE_FRAME, 0L, 0, 0, 1000, 600);
    pFrame->CenterWindow();
    ::ShowWindow(*pFrame, SW_SHOW);
    CPaintManagerUI::MessageLoop();

    ::CoUninitialize();

    _CrtDumpMemoryLeaks();
    return 0;
}
