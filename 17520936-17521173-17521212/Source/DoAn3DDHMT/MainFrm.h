
// MainFrm.h : interface of the CMainFrame class
//

#pragma once
/*#include "FileView.h"
#include "ClassView.h"
#include "OutputWnd.h"
#include "PropertiesWnd.h"*/
#include "DoAn3DDHMTView.h"
#include "FORMVIEW.h"

class CMainFrame : public CFrameWndEx
{
	
protected: // create from serialization only
	CMainFrame() noexcept;
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
protected:
	CDoAn3DDHMTView* app_view_;
public:

// Operations
public:
	CDoAn3DDHMTView* GetMainView()
	{
		return app_view_;
	}
// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = nullptr, CCreateContext* pContext = nullptr);
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CMFCMenuBar       m_wndMenuBar;
	CMFCToolBar       m_wndToolBar;
	CMFCStatusBar     m_wndStatusBar;
	CMFCToolBarImages m_UserImages;
	//CFileView         m_wndFileView;
	//CClassView        m_wndClassView;
	//COutputWnd        m_wndOutput;
	//CPropertiesWnd    m_wndProperties;
	CSplitterWnd m_wndSplitter;
// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);
	//afx_msg void OnApplicationLook(UINT id);
	//afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	//afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	DECLARE_MESSAGE_MAP()

	//BOOL CreateDockingWindows();
	//void SetDockingWindowIcons(BOOL bHiColorIcons);
};


