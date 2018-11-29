#ifndef __UIDLGBUILDER_H__
#define __UIDLGBUILDER_H__

#pragma once

namespace DuiLib {

    /*******************************************************************
    * 该接口主要在自定义控件时，当在xml中定义了自定义的控件，用于创建非
    * 标准控件对象实例
    ********************************************************************/
	class IDialogBuilderCallback
	{
	public:
		virtual CControlUI* CreateControl(LPCTSTR pstrClass) = 0;
	};

    /********************************************************************
    * 根据xml文件构建对应的控件
    *********************************************************************/
	class UILIB_API CDialogBuilder
	{
	public:
		CDialogBuilder();
		CControlUI* Create(STRINGorID xml, 
            LPCTSTR type = NULL, 
            IDialogBuilderCallback* pCallback = NULL,
			CPaintManagerUI* pManager = NULL, 
            CControlUI* pParent = NULL);


		CMarkup* GetMarkup();

		void GetLastErrorMessage(LPTSTR pstrMessage, SIZE_T cchMax) const;
		void GetLastErrorLocation(LPTSTR pstrSource, SIZE_T cchMax) const;
	    void SetInstance(HINSTANCE instance){ m_instance = instance;};
	private:
        CControlUI * Create(IDialogBuilderCallback* pCallback = NULL, CPaintManagerUI* pManager = NULL,CControlUI* pParent = NULL);
		CControlUI* _Parse(CMarkupNode* parent, CControlUI* pParent = NULL, CPaintManagerUI* pManager = NULL);

		CMarkup m_xml;
		IDialogBuilderCallback* m_pCallback;
		LPCTSTR m_pstrtype;
    	HINSTANCE m_instance;
	};

} // namespace DuiLib

#endif // __UIDLGBUILDER_H__
