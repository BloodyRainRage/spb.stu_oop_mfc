﻿
// MFC_Lab5Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFC_Lab5.h"
#include "MFC_Lab5Dlg.h"
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


// Диалоговое окно CMFCLab5Dlg



CMFCLab5Dlg::CMFCLab5Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_LAB5_DIALOG, pParent)
	, m_Edit(0) {
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCLab5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SPEED_EDIT, m_Edit);
}

BEGIN_MESSAGE_MAP(CMFCLab5Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_CURRENTSPEED, &CMFCLab5Dlg::OnFileCurrentspeed)
	ON_EN_CHANGE(IDC_SPEED_EDIT, &CMFCLab5Dlg::OnEnChangeSpeedEdit)
	ON_COMMAND(ID_FILE_EXIT, &CMFCLab5Dlg::OnFileExit)
	ON_COMMAND(ID_HELP_ABOUT, &CMFCLab5Dlg::OnHelpAbout)
	ON_COMMAND(ID_HELP_BRUH, &CMFCLab5Dlg::OnHelpBruh)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCLab5Dlg

BOOL CMFCLab5Dlg::OnInitDialog()
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

void CMFCLab5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCLab5Dlg::OnPaint()
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
HCURSOR CMFCLab5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCLab5Dlg::OnFileCurrentspeed() {
	// TODO: добавьте свой код обработчика команд

	char strSpeed[10];
	_itoa_s(m_Edit, strSpeed, 10);
	MessageBox((CString)strSpeed);
}


void CMFCLab5Dlg::OnEnChangeSpeedEdit() {
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления

	UpdateData(TRUE);

}


void CMFCLab5Dlg::OnFileExit() {
	// TODO: добавьте свой код обработчика команд

	OnOK();
}


void CMFCLab5Dlg::OnHelpAbout() {
	// TODO: добавьте свой код обработчика команд

	CAboutDlg dlg;
	
	dlg.DoModal();

}


void CMFCLab5Dlg::OnHelpBruh() {
	// TODO: добавьте свой код обработчика команд

	MessageBox(L"Bruh");
}
