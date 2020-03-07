
// MFC_Lab2Dlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CMFCLab2Dlg
class CMFCLab2Dlg : public CDialogEx
{
// Создание
public:
	CMFCLab2Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_LAB2_DIALOG };
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
	afx_msg void OnBnClickedClearBtn();
	afx_msg void OnBnClickedExitBtn();
//	CEdit m_TestEdit;
	CString m_TestEdit;
	BOOL m_Visible;
	BOOL m_Enable;
	afx_msg void OnBnClickedEditVisible();
	afx_msg void OnBnClickedEditEnable();
	afx_msg void OnEnChangeTestEdit();
};
