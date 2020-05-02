
// MFC_Lab10Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFC_Lab10.h"
#include "MFC_Lab10Dlg.h"
#include "afxdialogex.h"
#include "Showdib.h"

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


// Диалоговое окно CMFCLab10Dlg



CMFCLab10Dlg::CMFCLab10Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_LAB10_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCLab10Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, ID_PIC, m_Pic);
	
}

BEGIN_MESSAGE_MAP(CMFCLab10Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_EXIT, &CMFCLab10Dlg::OnFileExit)
	ON_COMMAND(ID_FILE_OPEN32771, &CMFCLab10Dlg::OnFileOpen)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCLab10Dlg

BOOL CMFCLab10Dlg::OnInitDialog()
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

void CMFCLab10Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCLab10Dlg::OnPaint()
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
		////-Ваш код начинается здесь-////

//Если открыт bmp файл
		//if (hbm) {
		//	CClientDC dc(this);

		//	//Получить указатель на DC.

		//	HDC hdc = ::GetDC(m_hWnd);
		//	HDC hdcBits = ::CreateCompatibleDC(hdc);

		//	//Выбрать объект
		//	SelectObject(hdcBits, hbm);

		//	//Закрасить клиентскую облаcть черным цветом
		//	CRect wdRect;
		//	GetClientRect(&wdRect);
		//	CBrush brush;
		//	brush.CreateSolidBrush(RGB(0, 0, 0));
		//	dc.FillRect(&wdRect, &brush);

		//	//Вывести изображение
		//	BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcBits, 0, 0, SRCCOPY);

		//	//Удалить DC
		//	DeleteDC(hdcBits);
		//	::ReleaseDC(m_hWnd, hdc);
		//}

		////-Ваш код заканчивается здесь-////

		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCLab10Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCLab10Dlg::OnFileExit() {
	OnOK();
}


void CMFCLab10Dlg::OnFileOpen() {
	// TODO: добавьте свой код обработчика команд

	//CString szFilename("oribmp.bmp");
	//HBITMAP hBmp = (HBITMAP)::LoadImage(
	//	NULL,
	//	szFilename,
	//	IMAGE_BITMAP,
	//	0,
	//	0,
	//	LR_LOADFROMFILE | LR_CREATEDIBSECTION
	//);

	//BITMAP bmp;
	//GetObject(hBmp, sizeof(bmp), &bmp); // Here we get the BMP header info.

	//HDC BMPDC = CreateCompatibleDC(NULL); // This will hold the BMP image itself.

	////HDC hDC = GetDC(hWnd);
	//SelectObject(BMPDC, hBmp); // Put the image into the DC.

	//BitBlt(0, 0, 0, bmp.bmWidth, bmp.bmHeight, BMPDC, 0, 0, SRCCOPY);
	//
	///*CClientDC dc(this);
	//CDC bmDC;
	//bmDC.CreateCompatibleDC(&dc);
	//CBitmap* pOldbmp = bmDC.SelectObject(&bmp);

	//BITMAP  bi;
	//bmp.GetBitmap(&bi);
	//dc.BitBlt(0, 0, bi.bmWidth, bi.bmHeight, &bmDC, 0, 0, SRCCOPY);

	//bmDC.SelectObject(pOldbmp);*/
	//

	//
	//UpdateData(FALSE);
	
	

	//Заголовок и путь к файлу
	char FileName[500] = "oribmp.bmp";
	char FileTitle[100] = "oribmp.bmp";
	FileName[0] = '\0';

	//Создать объект диалогового окна
	//CFileDialog file(TRUE);
	////Уставновить аттрибуты диалогового окна
	//file.m_ofn.lpstrFilter = TEXT("Bitmap picture files *.bmp\0*.bmp\0All Files *.*\0*.*\0\0");
	//file.m_ofn.lpstrFileTitle = (LPWSTR) FileTitle;
	//file.m_ofn.lpstrFile = (LPWSTR) FileName;
	//file.m_ofn.lpstrTitle = L"Open BMP File";
	////Вывести диалоговое окно
	//file.DoModal();

	//Если ничего не выбранно, то вернуться
	/*if (FileName[0] == '\0') return;*/
	//Изменить заголовок окна на имя файла
	SetWindowText((LPCTSTR)FileTitle);

	//Получить указатель на объект в памяти
	HANDLE hdibCurrent1 = OpenDIB(FileName);
	hbm = 0;

	//Получить указатель на изображение
	//hbm = BitmapFromDib(hdibCurrent1, 0);

	//Записать параметры изображения
	GetObject(hbm, sizeof(BITMAP), (LPSTR)&bm);

	//Получить координаты окна
	CRect wdRect;
	GetClientRect(&wdRect);
	ClientToScreen(&wdRect);

	//Изменить размеры окна
	SetWindowPos(NULL, wdRect.left - 4, wdRect.top - 42, bm.bmWidth + wdRect.left, bm.bmHeight + wdRect.top, NULL);

	//Вывести картинку
	OnPaint();





}
