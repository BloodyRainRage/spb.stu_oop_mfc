
// MFC_Lab11View.cpp: реализация класса CMFCLab11View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MFC_Lab11.h"
#endif

#include "MFC_Lab11Doc.h"
#include "MFC_Lab11View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCLab11View

IMPLEMENT_DYNCREATE(CMFCLab11View, CFormView)

BEGIN_MESSAGE_MAP(CMFCLab11View, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Создание или уничтожение CMFCLab11View

CMFCLab11View::CMFCLab11View() noexcept
	: CFormView(IDD_MFC_LAB11_FORM)
{
	// TODO: добавьте код создания

}

CMFCLab11View::~CMFCLab11View()
{
}

void CMFCLab11View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMFCLab11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMFCLab11View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CMFCLab11View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCLab11View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Диагностика CMFCLab11View

#ifdef _DEBUG
void CMFCLab11View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFCLab11View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFCLab11Doc* CMFCLab11View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCLab11Doc)));
	return (CMFCLab11Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CMFCLab11View
