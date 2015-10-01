
// RedView.cpp : implementation of the CRedView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Red.h"
#endif

#include "RedDoc.h"
#include "RedView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRedView

IMPLEMENT_DYNCREATE(CRedView, CView)

BEGIN_MESSAGE_MAP(CRedView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRedView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CRedView construction/destruction

CRedView::CRedView()
{
	// TODO: add construction code here

}

CRedView::~CRedView()
{
}

BOOL CRedView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CRedView drawing

void CRedView::OnDraw(CDC* pDC)
{
	CRedDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	pDC->TextOut(50, 50, _T("RED"));

}


// CRedView printing


void CRedView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CRedView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRedView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRedView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CRedView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CRedView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CRedView diagnostics

#ifdef _DEBUG
void CRedView::AssertValid() const
{
	CView::AssertValid();
}

void CRedView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRedDoc* CRedView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRedDoc)));
	return (CRedDoc*)m_pDocument;
}
#endif //_DEBUG


// CRedView message handlers
