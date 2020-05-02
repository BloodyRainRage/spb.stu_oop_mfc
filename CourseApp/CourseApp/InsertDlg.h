#pragma once
#include "Mylib.h"

// Диалоговое окно InsertDlg

class InsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(InsertDlg)

public:
	InsertDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~InsertDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSERT_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString m_Username;
	CString m_Firstname;
	CString m_Lastname;
	CString m_Emale;
//	CEdit m_Password;
	CString m_Position;
	afx_msg void OnBnClickedButton1();

	users GetUser();
	CString m_Password;
};
