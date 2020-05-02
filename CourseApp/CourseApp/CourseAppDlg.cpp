
// CourseAppDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "CourseApp.h"
#include "CourseAppDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <algorithm>
#include <string>
#include "InsertDlg.h"
#include "Update.h"
#include "Delete.h"
#include "GameDlg.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CCourseAppDlg



CCourseAppDlg::CCourseAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COURSEAPP_DIALOG, pParent), m_Edit(_T("")), m_Login(_T("")), m_Password(_T("")), m_StatusEdit(_T("")) {
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCourseAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);



	DDX_Text(pDX, IDC_EDIT1, m_Edit);
	DDX_Control(pDX, IDC_EDIT1, m_EditControl);
	DDX_Control(pDX, IDC_LOAD_BUTTON, m_Loadbtn);
	DDX_Text(pDX, IDC_EDIT2, m_Login);
	DDX_Text(pDX, IDC_EDIT3, m_Password);
	DDX_Control(pDX, IDC_LOGIN, m_LogControl);
	DDX_Control(pDX, IDC_CANCEL, m_CancelControl);
	DDX_Control(pDX, IDC_EDIT2, m_EditLogControl);
	DDX_Control(pDX, IDC_EDIT3, m_EditPassControl);
	DDX_Text(pDX, IDC_EDIT4, m_StatusEdit);	
}

BEGIN_MESSAGE_MAP(CCourseAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOAD_BUTTON, &CCourseAppDlg::OnBnClickedLoadButton)
	ON_BN_CLICKED(IDC_CANCEL, &CCourseAppDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_LOGIN, &CCourseAppDlg::OnBnClickedLogin)
	
	ON_BN_CLICKED(IDC_BUTTON3, &CCourseAppDlg::OnBnClickedButton3)
	ON_COMMAND(ID_APPLICATION_ABOUT, &CCourseAppDlg::OnApplicationAbout)
	ON_COMMAND(ID_FILE_INSERT, &CCourseAppDlg::OnFileInsert)
	ON_COMMAND(ID_FILE_UPDATE, &CCourseAppDlg::OnFileUpdate)
	ON_COMMAND(ID_FILE_DELETE, &CCourseAppDlg::OnFileDelete)
	ON_COMMAND(ID_GAME_PLAYGAME, &CCourseAppDlg::OnGamePlaygame)
END_MESSAGE_MAP()


// Обработчики сообщений CCourseAppDlg

BOOL CCourseAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	m_Loadbtn.EnableWindow(FALSE);
	GetDlgItem(IDC_LOAD_BUTTON)->ShowWindow(SW_HIDE);
	
	
	m_EditControl.EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_HIDE);
	SetWindowPos(NULL, 800, 400, 300, 200, SWP_NOMOVE);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CCourseAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CCourseAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CCourseAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCourseAppDlg::OnBnClickedLoadButton() {
	// TODO: добавьте свой код обработчика уведомлений
	
	CFileDialog file(TRUE);
	//Уставновить аттрибуты диалогового окна
	file.m_ofn.lpstrFilter = TEXT("CSV files *.csv\0*.csv\0All Files *.*\0*.*\0\0");	
	//Вывести диалоговое окно
	CString filename;

	if (file.DoModal() == IDOK)
	{

		filename = file.GetPathName(); // return full path and filename

	} else return;
	
	vector<users> input;
	
	input = test->loadFile(filename);
	sysUsers.insert(sysUsers.end(), input.begin(), input.end());
	CString status = m_StatusEdit;
	status += "Loaded: ";
	status += filename;
	status += "\r\n";
	m_StatusEdit = status;
	
	//input = test->loadFile("res/input.csv");
	CString str = m_Edit;
	for (int i = 0; i < input.size(); ++i) {
		str += "Subject: \r\n";
		str += input[i].getUser().c_str();
		str += "\r\n";
	}
	m_Edit = str;

	UpdateData(FALSE);


}


void CCourseAppDlg::OnBnClickedCancel() {
	
	OnOK();
}


void CCourseAppDlg::OnBnClickedLogin() {
	// TODO: добавьте свой код обработчика уведомлений

		SetWindowPos(NULL, 500, 300, 700, 500, 0);
		m_Loadbtn.EnableWindow(TRUE);
		GetDlgItem(IDC_LOAD_BUTTON)->ShowWindow(SW_SHOW);

		m_EditControl.EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_SHOW);

		UpdateData(FALSE);

		GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_LOGIN)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CANCEL)->ShowWindow(SW_HIDE);
		
		isLogged = true;

}




void CCourseAppDlg::OnBnClickedButton3() {
	
	if (sysUsers.size() == 0) {
		MessageBox(L"Nothing to store");
		return;
	}

	TCHAR szFilters[] = _T("CSV Files (*.csv)|*.csv|All Files (*.*)|*.*||");

	CFileDialog fileDlg(FALSE, _T("result"), _T("result.csv"),
		OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters);
	if (fileDlg.DoModal() != IDOK)
	{
		//the user didn't click OK
		return;
	}
	CString theFileName = fileDlg.GetPathName();

	string result;
	for (int i = 0; i < sysUsers.size(); ++i) {
		result += sysUsers[i].username + ';' +
			sysUsers[i].firstname + ';' +
			sysUsers[i].lastname + ';' +
			sysUsers[i].email + ';' +
			sysUsers[i].firstname + ';' +
			sysUsers[i].password + ';' +
			sysUsers[i].position + "\n";
					
	}

	test->saveFile(theFileName, result);
	CString status = m_StatusEdit;
	status += L"Stored to: ";
	status += theFileName;
	status += "\n";
	m_StatusEdit = status;
	UpdateData(FALSE);

}


void CCourseAppDlg::OnApplicationAbout() {	
	CAboutDlg dlg;

	dlg.DoModal();

}


void CCourseAppDlg::OnFileInsert() {
	
	if (!isLogged) {
		MessageBox(L"You are not logged in");
		return;
	}

	InsertDlg loginDlg;

	// Create and show the dialog box
	INT_PTR nRet = -1;
	nRet = loginDlg.DoModal();

	// Check the return value of DoModal
	if (nRet == IDOK)
	{
		// Process the user's input
		users user = loginDlg.GetUser();
		sysUsers.push_back(user);
		this->inserted++;
		DrawHisto();
	}

	CString str;
	for (int i = 0; i < sysUsers.size(); ++i) {
		str += "Subject: \r\n";
		str += sysUsers[i].getUser().c_str();
		str += "\r\n";
	}
	m_Edit = str;

	UpdateData(FALSE);
	

}


void CCourseAppDlg::OnFileUpdate() {
	
	if (!isLogged) {
		MessageBox(L"You are not logged in");
		return;
	}
	Update update;

	// Create and show the dialog box
	INT_PTR nRet = -1;
	update.setUsers(sysUsers);
	nRet = update.DoModal();	
	// Check the return value of DoModal
	if (nRet == IDOK)
	{
		
		users user = update.getUpdatedUser();

		for (int i = 0; i < sysUsers.size(); ++i) {
			if (sysUsers[i].username == user.username) {
				sysUsers[i] = user;
				break;
			}
		}		
		updated++;
		DrawHisto();
	}

	CString str;
	for (int i = 0; i < sysUsers.size(); ++i) {
		str += "Subject: \r\n";
		str += sysUsers[i].getUser().c_str();
		str += "\r\n";
	}
	m_Edit = str;

	UpdateData(FALSE);
	
}


void CCourseAppDlg::OnFileDelete() {

	if (!isLogged) {
		MessageBox(L"You are not logged in");
		return;
	}

	Delete del;

	// Create and show the dialog box
	INT_PTR nRet = -1;
	del.setUsers(sysUsers);
	nRet = del.DoModal();
	// Check the return value of DoModal
	if (nRet == IDOK)
	{

		string username(CW2A(del.getUsername()));

		for (auto i = sysUsers.begin(); i != sysUsers.end(); i++) {

			if (i->username == username) {

				i = sysUsers.erase(i);
				break;
			} 
		}

		deleted++;
		DrawHisto();
		
	}

	CString str;
	for (int i = 0; i < sysUsers.size(); ++i) {
		str += "Subject: \r\n";
		str += sysUsers[i].getUser().c_str();
		str += "\r\n";
	}
	m_Edit = str;

	UpdateData(FALSE);
	
	
}



void CCourseAppDlg::OnGamePlaygame() {
	
	GameDlg gameDlg;
	gameDlg.difficultyProvided = false;
	gameDlg.difficulty = 10;

	gameDlg.DoModal();

}

void CCourseAppDlg::DrawHisto() {
	
	CClientDC dc(this);

	//Создать новое перо
	CPen MyNewPen;
	MyNewPen.CreatePen(PS_SOLID, 10, RGB(255, 0, 0));
	
	CPen* pOriginalPen;
	pOriginalPen = dc.SelectObject(&MyNewPen);	
	CRect Insert(500, 210-inserted*10, 505, 210);
	dc.Rectangle(&Insert);
	dc.SelectObject(pOriginalPen);

	CPen UpdatePen;
	UpdatePen.CreatePen(PS_SOLID, 10, RGB(0, 255, 0));
	
	pOriginalPen = dc.SelectObject(&UpdatePen);
	CRect Update(520, 210 - updated*10, 525, 210);
	dc.Rectangle(&Update);
	dc.SelectObject(pOriginalPen);


	CPen DeletePen;
	DeletePen.CreatePen(PS_SOLID, 10, RGB(0, 0, 255));
	
	pOriginalPen = dc.SelectObject(&DeletePen);
	CRect Del(540, 210 - deleted*10, 545, 210);
	dc.Rectangle(&Del);
	dc.SelectObject(pOriginalPen);


	CDialog::OnPaint();
	/*UpdateData(TRUE);
	string text = "Inserted: " + inserted;
	text += " Updated: " + updated;
	text += " Deleted: " + deleted;

	m_Count = text.c_str();
	UpdateData(FALSE);*/
}