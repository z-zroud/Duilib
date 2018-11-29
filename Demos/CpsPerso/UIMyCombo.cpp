#include "stdafx.h"
#include "UIMyCombo.h"


CMyCombo::CMyCombo()
{
}


CMyCombo::~CMyCombo()
{
}


LPCTSTR CMyCombo::GetClass() const
{
    return _T("MyCombo");
}

LPVOID CMyCombo::GetInterface(LPCTSTR pstrName)
{
    if (_tcsicmp(pstrName, _T("MyCombo")) == 0) return static_cast<CMyCombo*>(this);
    return CContainerUI::GetInterface(pstrName);
}

void CMyCombo::Init()
{
    CDialogBuilder builder;
    m_pRoot = static_cast<CHorizontalLayoutUI*>(builder.Create(_T("Combo.xml"), (UINT)0, NULL, m_pManager));
    if (m_pRoot)
    {
        this->Add(m_pRoot);
        m_pManager->AddNotifier(this); 
    }
    else
    {
        this->RemoveAll();
    }
    m_pCombo = static_cast<CComboUI*>(m_pManager->FindControl(_T("combo")));
    m_pLable = static_cast<CButtonUI*>(m_pManager->FindControl(_T("combo_arrow")));
}

void CMyCombo::Notify(TNotifyUI& msg)
{

}
