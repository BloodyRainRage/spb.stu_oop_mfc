
// MFC_Lab11View.h: интерфейс класса CMFCLab11View
//

#pragma once


class CMFCLab11View : public CFormView
{
protected: // создать только из сериализации
	CMFCLab11View() noexcept;
	DECLARE_DYNCREATE(CMFCLab11View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC_LAB11_FORM };
#endif

// Атрибуты
public:
	CMFCLab11Doc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора

// Реализация
public:
	virtual ~CMFCLab11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в MFC_Lab11View.cpp
inline CMFCLab11Doc* CMFCLab11View::GetDocument() const
   { return reinterpret_cast<CMFCLab11Doc*>(m_pDocument); }
#endif

