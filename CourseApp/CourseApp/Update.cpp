// Update.cpp: файл реализации
//

#include "pch.h"
#include "CourseApp.h"
#include "Update.h"
#include "afxdialogex.h"


// Диалоговое окно Update

IMPLEMENT_DYNAMIC(Update, CDialogEx)

Update::Update(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_UPDATE_DLG, pParent)
	, m_Find(_T("")), m_Firstname(_T("")), m_Lastname(_T("")), m_Password(_T("")), m_Position(_T("")), m_Username(_T("")), m_Email(_T("")), m_Label(_T("")) {	
}

Update::~Update()
{
}

void Update::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FIND, m_Find);
	DDX_Text(pDX, IDC_FNAME, m_Firstname);
	DDX_Text(pDX, IDC_LNAME, m_Lastname);
	DDX_Text(pDX, IDC_PASS, m_Password);
	DDX_CBString(pDX, IDC_POSITION, m_Position);
	DDX_Text(pDX, IDC_USERNAME, m_Username);
	DDX_Text(pDX, IDC_EMAIL, m_Email);
	DDX_Text(pDX, IDC_RESULT_LABEL, m_Label);
}


BEGIN_MESSAGE_MAP(Update, CDialogEx)
	ON_BN_CLICKED(IDC_FIND_BTN, &Update::OnBnClickedFindBtn)
	ON_BN_CLICKED(IDC_COMMIT_BTN, &Update::OnBnClickedCommitBtn)
END_MESSAGE_MAP()


// Обработчики сообщений Update

void Update::setUsers(vector<users> users) {

	incomeUsers.resize(users.size());

	copy(users.begin(), users.end(), incomeUsers.begin());

}




void Update::OnBnClickedFindBtn() {
	UpdateData(TRUE);
	string username(CW2A(m_Find.GetString()));
	bool flag;
	for (int i = 0; i < incomeUsers.size(); ++i) {
		if (incomeUsers[i].username == username) {
			m_Username = username.c_str();
			m_Firstname = incomeUsers[i].firstname.c_str();
			m_Lastname = incomeUsers[i].lastname.c_str();
			m_Email = incomeUsers[i].email.c_str();
			m_Password = incomeUsers[i].password.c_str();
			
			m_Position = incomeUsers[i].position.c_str();
			m_Label = "";
			UpdateData(FALSE);
			return;

		}
	}

	m_Label = "nothing found";
	UpdateData(FALSE);

}


users Update::getUpdatedUser() {

	users user;

	string username(CW2A(m_Username.GetString()));
	string firstname(CW2A(m_Firstname.GetString()));
	string lastname(CW2A(m_Lastname.GetString()));
	string email(CW2A(m_Email.GetString()));
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

void Update::OnBnClickedCommitBtn() {
	
	OnOK();

}
