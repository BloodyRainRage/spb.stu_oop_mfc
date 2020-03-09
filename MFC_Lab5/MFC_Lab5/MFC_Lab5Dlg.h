
// MFC_Lab5Dlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CMFCLab5Dlg
class CMFCLab5Dlg : public CDialogEx
{
// Создание
public:
	CMFCLab5Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_LAB5_DIALOG };
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
	int m_Edit;
	afx_msg void OnFileCurrentspeed();
	afx_msg void OnEnChangeSpeedEdit();
	afx_msg void OnFileExit();
	afx_msg void OnHelpAbout();
	afx_msg void OnHelpBruh();
};
