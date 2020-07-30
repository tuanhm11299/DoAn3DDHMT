
// DoAn3DDHMT.h : main header file for the DoAn3DDHMT application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDoAn3DDHMTApp:
// See DoAn3DDHMT.cpp for the implementation of this class
//

class CDoAn3DDHMTApp : public CWinAppEx
{
public:
	CDoAn3DDHMTApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDoAn3DDHMTApp theApp;
