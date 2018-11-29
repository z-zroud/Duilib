#pragma once
class CMyCombo : public CContainerUI, INotifyUI
{
public:
    CMyCombo();
    ~CMyCombo();

    LPCTSTR GetClass() const;
    LPVOID GetInterface(LPCTSTR pstrName);

    void Init();
    void Notify(TNotifyUI& msg);

private:
    CLabelUI *m_pLable;
    CComboUI *m_pCombo;
    CContainerUI *m_pRoot;
};

