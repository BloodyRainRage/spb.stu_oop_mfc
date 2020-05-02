
// CourseAppDlg.h: файл заголовка
//

#pragma once

#include "Mylib.h"
// Диалоговое окно CCourseAppDlg
class CCourseAppDlg : public CDialogEx
{
// Создание
public:
	CCourseAppDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COURSEAPP_DIALOG };
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
	afx_msg void OnBnClickedLoadButton();
//	string m_Edit;
//	CString m_Edit;
//	CString m_Edit;
//	string m_Edit;
	CString m_Edit;
	CEdit m_EditControl;
	CButton m_Loadbtn;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedLogin();

	void saveFile(string toStore);

	CString m_Login;
	CString m_Password;
	CButton m_LogControl;
	CButton m_CancelControl;
	CEdit m_EditLogControl;
	CEdit m_EditPassControl;

	CString filename;
	Mylib* test = new Mylib();
	vector<users> sysUsers;
	bool isLogged{ false };

//	CString m_StatusEdit;
	afx_msg void OnBnClickedStore();
	
	afx_msg void OnBnClickedButton3();
	afx_msg void OnApplicationAbout();
	afx_msg void OnFileInsert();
	afx_msg void OnFileUpdate();
	afx_msg void OnFileDelete();
	CString m_StatusEdit;
	afx_msg void OnGamePlaygame();

	int inserted{ 0 };
	int updated{ 0 };
	int deleted{ 0 };
	void DrawHisto();

};
