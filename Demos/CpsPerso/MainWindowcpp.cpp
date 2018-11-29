// MainWnd.cpp

#include "StdAfx.h"
#include "MainWindow.h"
#include "UIBrowseButton.h"
#include "UIMyCombo.h"

DUI_BEGIN_MESSAGE_MAP(CMainWnd, WindowImplBase)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_END_MESSAGE_MAP()

CMainWnd::CMainWnd()
    : m_pStepTabLayout(NULL)
    , m_pInstallText(NULL)
    , m_pBtnOneClick(NULL)
    , m_pBtnOverwrite(NULL)
    , m_pProgressBar(NULL)
{
}

CDuiString CMainWnd::GetSkinFile()
{
    try
    {
        return CDuiString(_T("DlgMain.xml"));
    }
    catch (...)
    {
        throw "CMainWnd::GetSkinFile";
    }
}

LPCTSTR CMainWnd::GetWindowClassName() const
{
    try
    {
        return _T("CpsPerso");
    }
    catch (...)
    {
        throw "CMainWnd::GetWindowClassName";
    }
}

void CMainWnd::InitWindow()
{
    try
    {
        WindowImplBase::InitWindow();

        Init();

    }
    catch (...)
    {
        throw "CMainWnd::Init";
    }
}

void CMainWnd::Notify(TNotifyUI& msg)
{
    if (msg.sType == _T("click"))
    {
        if (msg.pSender == m_pBtnOneClick)
        {
            //InstallStart();
            return;
        }
    }

    WindowImplBase::Notify(msg);
}

void CMainWnd::OnFinalMessage(HWND hWnd)
{
    try
    {
        WindowImplBase::OnFinalMessage(hWnd);
        PostQuitMessage(0);
        delete this;
    }
    catch (...)
    {
        throw "CMainWnd::OnFinalMessage";
    }
}

LRESULT CMainWnd::HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    LRESULT lRes = 0;

    switch (uMsg)
    {
    //case WM_TIMER: lRes = OnTimer(uMsg, wParam, lParam, bHandled); break;
    default: break;
    }

    return lRes;
}

void CMainWnd::Init()
{
    //m_pStepTabLayout = static_cast<CAnimationTabLayoutUI*>(m_pm.FindControl(_T("stepTabLayout")));
    //m_pInstallText = static_cast<CLabelUI*>(m_pm.FindControl(_T("textProgress")));
    //m_pBtnOneClick = static_cast<CButtonUI*>(m_pm.FindControl(_T("BtnOneClick")));
    //m_pBtnOverwrite = static_cast<CButtonUI*>(m_pm.FindControl(_T("BtnOverwrite")));
    //m_pProgressBar = static_cast<CProgressUI*>(m_pm.FindControl(_T("install")));

    //m_pProgressBar->SetValue(0);
}

CControlUI* CMainWnd::CreateControl(LPCTSTR pstrClass)
{
    CControlUI* pControl = NULL;//= new CControl;
    if (_tcsicmp(pstrClass, _T("BrowseButton")) == 0)
    {
        pControl = new CBrowseButton();
    }
    else if (_tcsicmp(pstrClass, _T("MyCombo")) == 0)
    {
        pControl = new CMyCombo();
    }
    return pControl;
}
