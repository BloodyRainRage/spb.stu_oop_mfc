#pragma once
#include "Mylib.h"

// Диалоговое окно Delete

class Delete : public CDialogEx
{
	DECLARE_DYNAMIC(Delete)

public:
	Delete(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~Delete();

	void setUsers(vector<users>);

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELETE_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	vector<users> incomeUsers;

	DECLARE_MESSAGE_MAP()
public:
	CString m_Username;
	afx_msg void OnBnClickedButton1();
	CString getUsername();

};
