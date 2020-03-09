
// MFC_Lab6Dlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CMFCLab6Dlg
class CMFCLab6Dlg : public CDialogEx
{
// Создание
public:
	CMFCLab6Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_LAB6_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedOkcancelBtn();
	CString m_Edit;
	afx_msg void OnBnClickedYesnocancelBtn();
	afx_msg void OnBnClickedRetrycancelBtn();
	afx_msg void OnBnClickedYesnoBtn();
};
