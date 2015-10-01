
// RedView.h : interface of the CRedView class
//

#pragma once


class CRedView : public CView
{
protected: // create from serialization only
	CRedView();
	DECLARE_DYNCREATE(CRedView)

// Attributes
public:
	CRedDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CRedView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void SwitchView();
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RedView.cpp
inline CRedDoc* CRedView::GetDocument() const
   { return reinterpret_cast<CRedDoc*>(m_pDocument); }
#endif

