
// MFC_Lab1Dlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CMFCLab1Dlg
class CMFCLab1Dlg : public CDialogEx
{
// Создание
public:
	CMFCLab1Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_LAB1_DIALOG };
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
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedExitBtn();
	afx_msg void OnBnClickedSayhelloBtn();
	afx_msg void OnBnClickedBeeb();

};
