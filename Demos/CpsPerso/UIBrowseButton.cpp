#include "stdafx.h"
#include "UIBrowseButton.h"


CBrowseButton::CBrowseButton()
{
}


CBrowseButton::~CBrowseButton()
{
}

void CBrowseButton::Notify(TNotifyUI& msg)
{
    if (msg.sType == DUI_MSGTYPE_CLICK)
    {
        if (msg.pSender == m_btnBrowse)
        {
            MessageBox(NULL, _T("SHIT"), _T("SHIT"), MB_OK);
        }
    }
}

LPCTSTR CBrowseButton::GetClass()const
{
    return _T("BrowseButton");
}

LPVOID CBrowseButton::GetInterface(LPCTSTR pstrName)
{
    if (_tcscmp(pstrName, _T("BrowseButton")) == 0) return static_cast<CBrowseButton*>(this);
    return CContainerUI::GetInterface(pstrName);
}

UINT CBrowseButton::GetControlFlags()const
{
    return CContainerUI::GetControlFlags();
}


void CBrowseButton::Init()
{
    CDialogBuilder builder;
    m_pRoot = static_cast<CHorizontalLayoutUI*>(builder.Create(_T("BrowseButton.xml"), (UINT)0, NULL, m_pManager));
    if (m_pRoot)
    {
        this->Add(m_pRoot);
        m_pManager->AddNotifier(this); //可能是因为我参考的另一个人的东西；他是用class CMainWnd : public CWindowWnd, p
        //public INotifyUI,public IDialogBuilderCallback;这种方式加载主窗口的，他的不会在分发消息
        //时崩溃；我是用的windowimpbase，所以此处不能添加这行代码,  如果需要用到这个控件的消息，还是在使用控件的位置处理，让控件自己处理会导致崩溃
    }
    else
    {
        this->RemoveAll();
    }
    m_editFilePath = static_cast<CEditUI*>(m_pManager->FindControl(_T("editFilePath")));
    m_btnBrowse = static_cast<CButtonUI*>(m_pManager->FindControl(_T("btnBrowse")));
    m_pRoot->SetFixedHeight(m_nHeight);
}


void CBrowseButton::SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue)
{
    if (_tcsicmp(pstrName, _T("width")) == 0)
    {
        m_nWidth = _ttoi(pstrValue);
    }
    else if (_tcsicmp(pstrName, _T("height")) == 0)
    {
        m_nHeight = _ttoi(pstrValue);
    }
}