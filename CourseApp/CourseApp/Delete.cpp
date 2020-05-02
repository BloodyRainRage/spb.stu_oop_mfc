// Delete.cpp: файл реализации
//

#include "pch.h"
#include "CourseApp.h"
#include "Delete.h"
#include "afxdialogex.h"


// Диалоговое окно Delete

IMPLEMENT_DYNAMIC(Delete, CDialogEx)

Delete::Delete(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DELETE_DLG, pParent)
	, m_Username(_T("")) {

}

Delete::~Delete()
{
}

void Delete::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Username);
}


BEGIN_MESSAGE_MAP(Delete, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Delete::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений Delete

void Delete::setUsers(vector<users> users) {

	incomeUsers.resize(users.size());

	copy(users.begin(), users.end(), incomeUsers.begin());

}


void Delete::OnBnClickedButton1() {

	int iResults;
	string username(CW2A(m_Username));
	
	iResults = MessageBox(L"Are you sure you want to delete " + m_Username + " user?",
		L"Delete confirmation",
		MB_YESNO + MB_ICONEXCLAMATION);

	if (iResults == IDYES) {
		OnOK();
	} else if (iResults == IDNO)
	{
		return;
	}

}


CString Delete::getUsername() {
	return m_Username;
}