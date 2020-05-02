// InsertDlg.cpp: файл реализации
//

#include "pch.h"
#include "CourseApp.h"
#include "InsertDlg.h"
#include "afxdialogex.h"


// Диалоговое окно InsertDlg

IMPLEMENT_DYNAMIC(InsertDlg, CDialogEx)

InsertDlg::InsertDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INSERT_DLG, pParent)
	, m_Username(_T("")), m_Firstname(_T("")), m_Lastname(_T("")), m_Emale(_T("")), m_Position(_T("")), m_Password(_T("")) {

}

InsertDlg::~InsertDlg()
{
}

void InsertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Username);
	DDX_Text(pDX, IDC_EDIT5, m_Firstname);
	DDX_Text(pDX, IDC_EDIT6, m_Lastname);
	DDX_Text(pDX, IDC_EDIT7, m_Emale);
	//  DDX_Control(pDX, IDC_EDIT8, m_Password);
	DDX_CBString(pDX, IDC_COMBO1, m_Position);
	DDX_Text(pDX, IDC_EDIT8, m_Password);
}


BEGIN_MESSAGE_MAP(InsertDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &InsertDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений InsertDlg


void InsertDlg::OnBnClickedButton1() {
	
	/*string username(CW2A(m_Username.GetString()));
	string firstname(CW2A(m_Firstname.GetString()));
	string lastname(CW2A(m_Lastname.GetString()));
	string email(CW2A(m_Emale.GetString()));
	string password(CW2A(m_Password.GetString()));
	string position(CW2A(m_Position.GetString()));*/
	/*if (m_Position.IsEmpty() || m_Username.IsEmpty() || m_Password.IsEmpty() || m_Emale.IsEmpty() || m_Firstname.IsEmpty() || m_Lastname.IsEmpty()) {
		MessageBox(L"You have not filled all data");
		return;
	}*/

	OnOK();
}

users InsertDlg::GetUser() {
	users user;
		
	string username(CW2A(m_Username.GetString()));
	string firstname(CW2A(m_Firstname.GetString()));
	string lastname(CW2A(m_Lastname.GetString()));
	string email(CW2A(m_Emale.GetString()));
	string password(CW2A(m_Password.GetString()));
	string position(CW2A(m_Position.GetString()));
	user.username = username;
	user.firstname = firstname;
	user.lastname = lastname;
	user.email = email;
	user.password = password;
	user.position = position;

	return user;

}