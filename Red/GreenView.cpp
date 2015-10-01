// GreenView.cpp : implementation file
//

#include "stdafx.h"
#include "Red.h"
#include "GreenView.h"


// CGreenView

IMPLEMENT_DYNCREATE(CGreenView, CView)

CGreenView::CGreenView()
{

}

CGreenView::~CGreenView()
{
}

BEGIN_MESSAGE_MAP(CGreenView, CView)
END_MESSAGE_MAP()


// CGreenView drawing

void CGreenView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here


	pDC->TextOut(50, 50, _T("GREEN"));

}


// CGreenView diagnostics

#ifdef _DEBUG
void CGreenView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CGreenView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CGreenView message handlers
