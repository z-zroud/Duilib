#pragma once
class CBrowseButton : public CContainerUI,INotifyUI
{
public:
    CBrowseButton();
    ~CBrowseButton();

    
    LPCTSTR GetClass() const;
    LPVOID GetInterface(LPCTSTR pstrName);
    UINT GetControlFlags() const;

    void Init();
    void Notify(TNotifyUI& msg);
    void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);


private:
    CContainerUI * m_pRoot;
    CEditUI * m_editFilePath;
    CButtonUI* m_btnBrowse;

    int m_nWidth;
    int m_nHeight;
    RECT m_rectPadding;
};

