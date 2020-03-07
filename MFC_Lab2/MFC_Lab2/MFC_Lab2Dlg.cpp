
// MFC_Lab2Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFC_Lab2.h"
#include "MFC_Lab2Dlg.h"
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


// Диалоговое окно CMFCLab2Dlg



CMFCLab2Dlg::CMFCLab2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_LAB2_DIALOG, pParent)
	, m_TestEdit(_T("")), m_Visible(FALSE), m_Enable(FALSE) {
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCLab2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_TEST_EDIT, m_TestEdit);
	DDX_Text(pDX, IDC_TEST_EDIT, m_TestEdit);
	DDX_Check(pDX, IDC_EDIT_VISIBLE, m_Visible);
	DDX_Check(pDX, IDC_EDIT_ENABLE, m_Enable);
}

BEGIN_MESSAGE_MAP(CMFCLab2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CLEAR_BTN, &CMFCLab2Dlg::OnBnClickedClearBtn)
	ON_BN_CLICKED(IDC_EXIT_BTN, &CMFCLab2Dlg::OnBnClickedExitBtn)
	ON_BN_CLICKED(IDC_EDIT_VISIBLE, &CMFCLab2Dlg::OnBnClickedEditVisible)
	ON_BN_CLICKED(IDC_EDIT_ENABLE, &CMFCLab2Dlg::OnBnClickedEditEnable)
	ON_EN_CHANGE(IDC_TEST_EDIT, &CMFCLab2Dlg::OnEnChangeTestEdit)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCLab2Dlg

BOOL CMFCLab2Dlg::OnInitDialog()
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

	m_Visible = TRUE; 
	m_Enable = TRUE; 
	m_TestEdit = "bruh";
	
	UpdateData(FALSE);
	//MessageBox(m_TestEdit);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCLab2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCLab2Dlg::OnPaint()
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
HCURSOR CMFCLab2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCLab2Dlg::OnBnClickedClearBtn() {
	//SetDlgItemText(IDC_TEST_EDIT, L"");
	m_TestEdit = "";
	UpdateData(FALSE);
	
}


void CMFCLab2Dlg::OnBnClickedExitBtn() {
	OnOK();
}


void CMFCLab2Dlg::OnBnClickedEditVisible() {
	
	UpdateData(TRUE);
	if(m_Visible == TRUE)
		GetDlgItem(IDC_TEST_EDIT)->ShowWindow(SW_SHOW);
	else GetDlgItem(IDC_TEST_EDIT)->ShowWindow(SW_HIDE);

}


void CMFCLab2Dlg::OnBnClickedEditEnable() {
	UpdateData(TRUE);
	if (m_Enable == TRUE)
		GetDlgItem(IDC_TEST_EDIT)->EnableWindow(SW_SHOW);
	else GetDlgItem(IDC_TEST_EDIT)->EnableWindow(SW_HIDE);
}


void CMFCLab2Dlg::OnEnChangeTestEdit() {
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления

	UpdateData(TRUE);

	CString data;
	data = m_TestEdit;
	data.MakeUpper();

	if (data == "PAINT") {
		system("C:\\WINDOWS\\system32\\mspaint.exe");
		m_TestEdit = "";
		
	} else if (data == "CALCULATOR") {
		system("calc.exe");
		m_TestEdit = "";
	} else if (data == "EXIT") OnBnClickedExitBtn();
	else if (data == "BEEP")
	{
		MessageBeep((WORD)-2);
		m_TestEdit = "";		
	}



	UpdateData(FALSE);


}
