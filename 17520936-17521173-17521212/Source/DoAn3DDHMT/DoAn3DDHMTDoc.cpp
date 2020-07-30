
// DoAn3DDHMTDoc.cpp : implementation of the CDoAn3DDHMTDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DoAn3DDHMT.h"
#endif

#include "DoAn3DDHMTDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDoAn3DDHMTDoc

IMPLEMENT_DYNCREATE(CDoAn3DDHMTDoc, CDocument)

BEGIN_MESSAGE_MAP(CDoAn3DDHMTDoc, CDocument)
END_MESSAGE_MAP()


// CDoAn3DDHMTDoc construction/destruction

CDoAn3DDHMTDoc::CDoAn3DDHMTDoc() noexcept
{
	// TODO: add one-time construction code here

}

CDoAn3DDHMTDoc::~CDoAn3DDHMTDoc()
{
}

BOOL CDoAn3DDHMTDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

string WcharToString(wchar_t* wch) {
	std::string str("");
	int index = 0;
	while (wch[index] != 0) {
		str += (char)wch[index];
		++index;
	}
	return str;
}
BOOL CDoAn3DDHMTDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	USES_CONVERSION;
	texture_name = WcharToString((wchar_t*)lpszPathName);
	return TRUE;
}

char* CDoAn3DDHMTDoc::encode(const wchar_t* wstr, unsigned int codePage)
{
	int sizeNeeded = WideCharToMultiByte(codePage, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* encodedStr = new char[sizeNeeded];
	WideCharToMultiByte(codePage, 0, wstr, -1, encodedStr, sizeNeeded, NULL, NULL);
	return encodedStr;
}
// CDoAn3DDHMTDoc serialization

void CDoAn3DDHMTDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CDoAn3DDHMTDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CDoAn3DDHMTDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CDoAn3DDHMTDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDoAn3DDHMTDoc diagnostics

#ifdef _DEBUG
void CDoAn3DDHMTDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDoAn3DDHMTDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDoAn3DDHMTDoc commands
