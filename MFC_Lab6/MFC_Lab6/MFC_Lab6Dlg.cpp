﻿
// MFC_Lab6Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFC_Lab6.h"
#include "MFC_Lab6Dlg.h"
#include "afxdialogex.h"

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


// Диалоговое окно CMFCLab6Dlg



CMFCLab6Dlg::CMFCLab6Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_LAB6_DIALOG, pParent)
	, m_Edit(_T("")) {
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCLab6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RESULT_EDIT, m_Edit);
}

BEGIN_MESSAGE_MAP(CMFCLab6Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCLab6Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_OKCANCEL_BTN, &CMFCLab6Dlg::OnBnClickedOkcancelBtn)
	ON_BN_CLICKED(IDC_YESNOCANCEL_BTN, &CMFCLab6Dlg::OnBnClickedYesnocancelBtn)
	ON_BN_CLICKED(IDC_RETRYCANCEL_BTN, &CMFCLab6Dlg::OnBnClickedRetrycancelBtn)
	ON_BN_CLICKED(IDC_YESNO_BTN, &CMFCLab6Dlg::OnBnClickedYesnoBtn)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCLab6Dlg

BOOL CMFCLab6Dlg::OnInitDialog()
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

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCLab6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCLab6Dlg::OnPaint()
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
HCURSOR CMFCLab6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCLab6Dlg::OnBnClickedButton5() {
	// TODO: добавьте свой код обработчика уведомлений

	int iResults;
	iResults = MessageBox(L"Do you really want to exit this amazing program?",
		L"Exit confirm",
		MB_YESNO + MB_ICONEXCLAMATION);	

	if (iResults == IDYES) {
		OnOK();
	} else if (iResults == IDNO)
	{
		return;
	}

}


void CMFCLab6Dlg::OnBnClickedOkcancelBtn() {
	// TODO: добавьте свой код обработчика уведомлений

	int iResults;
	iResults = MessageBox(L"You want Ok and Cancel buttons.",
		L"I am the second parameter of the MessageBox function",
		MB_OKCANCEL + MB_ICONSTOP);
	CString str = m_Edit;
	if (str != "") str += "\r\n";	
	if (iResults == IDOK){
		str += "You Clicked the Ok button";		
	} else if (iResults == IDCANCEL){
		str += "You clicked on the Cancel button";		
	}

	m_Edit = str;

	UpdateData(FALSE);

}


void CMFCLab6Dlg::OnBnClickedYesnocancelBtn() {
	// TODO: добавьте свой код обработчика уведомлений

	int iResults;
	iResults = MessageBox(L"You want Yes, No and Cancel buttons.",
		L"I am the second parameter of the MessageBox function",
		MB_YESNOCANCEL + MB_ICONINFORMATION);
	CString str = m_Edit;
	if (str != "") str += "\r\n";
	if (iResults == IDYES){
		str += "You clicked on the Yes button.";
	} else if (iResults == IDNO){
		str += "You clicked on the No button";
	} else if (iResults == IDCANCEL){
		str += "You clicked on the Cancel button.";
	}
	m_Edit = str;
	UpdateData(FALSE);

}


void CMFCLab6Dlg::OnBnClickedRetrycancelBtn() {
	// TODO: добавьте свой код обработчика уведомлений

	int iResults;
	iResults = MessageBox(L"You want Retry and Cancel buttons.",
		L"I am the second parameter of the MessageBox function",
		MB_RETRYCANCEL + MB_ICONQUESTION);
	CString str = m_Edit;
	if (str != "") str += "\r\n";
	if (iResults == IDRETRY){
		str += "You clicked on the Retry button.";		
	} else if (iResults == IDCANCEL){
		str += "You clicked on the Cancel button.";	
	}

	m_Edit = str;
	UpdateData(FALSE);

}


void CMFCLab6Dlg::OnBnClickedYesnoBtn() {
	// TODO: добавьте свой код обработчика уведомлений

	int iResults;
	iResults = MessageBox(L"You want Yes and No buttons.",
		L"I am the second parameter of the MessageBox function",
		MB_YESNO + MB_ICONEXCLAMATION);
	CString str = m_Edit;
	if (str != "") str += "\r\n";

	if (iResults == IDYES){
		str += "You clicked on the OK button.";
	} else if (iResults == IDNO)
	{
		str += "You clicked on the NO button.";
	}

	m_Edit = str;
	UpdateData(FALSE);

}
