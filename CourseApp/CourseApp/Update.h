#pragma once
#include "Mylib.h"


// Диалоговое окно Update

class Update : public CDialogEx
{
	DECLARE_DYNAMIC(Update)

public:
	Update(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~Update();
	void setUsers(vector<users>);

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UPDATE_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	vector<users> incomeUsers;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFindBtn();
	users getUpdatedUser();

	CString m_Find;
	CString m_Firstname;
	CString m_Lastname;
	CString m_Password;
	CString m_Position;
	CString m_Username;
	CString m_Email;
	CString m_Label;
	afx_msg void OnBnClickedCommitBtn();
};
