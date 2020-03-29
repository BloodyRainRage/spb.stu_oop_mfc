
// MFC_Lab8DlgDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFC_Lab8.h"
#include "MFC_Lab8Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CPaintORamaDlg dialog



CMFC_Lab8Dlg::CMFC_Lab8Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PAINTORAMA_DIALOG, pParent)
	, m_PenWidth(0)
	, m_PenStyle(0)
{
	m_PenColor = RGB(0, 0, 0);
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_PenWidth = 1;
}

void CMFC_Lab8Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PENWIDTH, m_PenWidth);
	DDV_MinMaxInt(pDX, m_PenWidth, 1, 32);
	DDX_Radio(pDX, IDC_SOLID_PEN, m_PenStyle);
	DDX_Control(pDX, IDC_SHAPES, m_ShapesCombo);
	DDX_Control(pDX, IDC_BRUSHSTYLE, m_BrushStyleList);
}

BEGIN_MESSAGE_MAP(CMFC_Lab8Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CLEARBTN, &CMFC_Lab8Dlg::OnClickedClearbtn)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_STN_CLICKED(IDC_PENCOLOR, &CMFC_Lab8Dlg::OnStnClickedPencolor)
	ON_LBN_SELCHANGE(IDC_BRUSHSTYLE, &CMFC_Lab8Dlg::OnSelchangeBrushstyle)
	ON_STN_CLICKED(IDC_BRUSHCOLOR, &CMFC_Lab8Dlg::OnClickedBrushcolor)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CPaintORamaDlg message handlers

BOOL CMFC_Lab8Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();



	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	//Получить указатель на элемент управления Picture
	CWnd* p_Canvas = GetDlgItem(IDC_CANVAS);

	//Записать координаты окна в переменную m_Canvas
	p_Canvas->GetWindowRect(&m_Canvas);

	//Сопоставить координаты для клиентской области
	ScreenToClient(&m_Canvas);

	//Изменить координаты окна
	m_Canvas.DeflateRect(2, 2, 1, 1);

	//Получить указатель на элемент управления
	CWnd* pPenColor = GetDlgItem(IDC_PENCOLOR);

	//Получить координаты элемента управления
	pPenColor->GetWindowRect(&m_PenColorSwatch);

	//Изменить координаты относительно клиентской области
	ScreenToClient(&m_PenColorSwatch);

	//Cузить рамку 
	m_PenColorSwatch.DeflateRect(2,2,1,1);

	//Получить указатель на элемент управления
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1);

	/*Установить диапазон значений непосредственно для IDC_SPIN1*/
	pSpin->SetRange(1, 32);

	//Установить начальное значение счетчика в 1;
	pSpin->SetPos(1);

	//Установить начальную позицию курсора
	m_ShapesCombo.SetCurSel(0);

	//Получить указатель на элемент управления
	CWnd* pBrushColor = GetDlgItem(IDC_BRUSHCOLOR);

	//Получить координаты элемента управления
	pBrushColor->GetWindowRect(&m_BrushColorSwatch);

	//Изменить координаты относительно клиентской области
	ScreenToClient(&m_BrushColorSwatch);

	//Cузить рамку
	m_BrushColorSwatch.DeflateRect(2, 2, 1, 1);



	//Получить указатель на элемент управления
	CWnd* pPreviewColor = GetDlgItem(IDC_BRUSHPREVIEW);

	//Получить координаты элемента управления
	pPreviewColor->GetWindowRect(&m_BrushPreviewSwatch);

	//Изменить координаты относительно клиентской области
	ScreenToClient(&m_BrushPreviewSwatch);

	//Cузить рамку
	m_BrushPreviewSwatch.DeflateRect(2, 2, 1, 1);

	//Установить начальный цвет кисти
	m_BrushColor = RGB(0, 0, 0);

	//Создать белую кисть
	m_Brush.CreateStockObject(WHITE_BRUSH);

	// Добавить названия стилей в элемент ListBox
	m_BrushStyleList.AddString(L"(none)");
	m_BrushStyleList.AddString(L"Solid");
	m_BrushStyleList.AddString(L"LL-UR Diagonal");
	m_BrushStyleList.AddString(L"UL-LR Diagonal");
	m_BrushStyleList.AddString(L"Grid");
	m_BrushStyleList.AddString(L"Grid Diagonal");
	m_BrushStyleList.AddString(L"Horizontal");
	m_BrushStyleList.AddString(L"Vertical");
	m_BrushStyleList.AddString(L"White");
	m_BrushStyleList.AddString(L"Light Gray");
	m_BrushStyleList.AddString(L"Medium Gray");
	m_BrushStyleList.AddString(L"Dark Gray");
	m_BrushStyleList.AddString(L"Black");

	//Установить начальную позицию курсора на 8 элементе
	m_BrushStyleList.SetCurSel(8);

	//Разместить в памяти объект метафайла
	m_pMF = new CMetaFileDC;
	//Создать МетаФайл
	m_pMF->Create();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFC_Lab8Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFC_Lab8Dlg::OnPaint()
{

	CPaintDC dc(this);

	//Закрытие метафайла
	HMETAFILE hmf = m_pMF->Close();
	//Воспроизведение метафайла
	dc.PlayMetaFile(hmf);

	//Присваивание указателя на старый объект переменной temp
	CMetaFileDC* temp = new CMetaFileDC;
	//Закрытие объекта
	temp->Create();
	//Проигрование метафайла
	temp->PlayMetaFile(hmf);

	//Удаление метаструктуры и метафайла
	DeleteMetaFile(hmf);
	//delete hmf;

	//Присваивание временного указателя постоянному
	m_pMF = temp;
	/*Если первый раз была вызвана функия OnPaint, то вызавать очистку экрана*/
	static bool firstTime = TRUE;
	if (firstTime)
	{
		OnClickedClearbtn();
		firstTime = FALSE;
	}


	//if (IsIconic())
	//{
	//	CPaintDC dc(this);

	//	//Закрытие метафайла
	//	HMETAFILE hmf = m_pMF->Close();
	//	//Воспроизведение метафайла
	//	dc.PlayMetaFile(hmf);

	//	//Присваивание указателя на старый объект переменной temp
	//	CMetaFileDC* temp = new CMetaFileDC;
	//	//Закрытие объекта
	//	temp->Create();
	//	//Проигрование метафайла
	//	temp->PlayMetaFile(hmf);

	//	//Удаление метаструктуры и метафайла
	//	DeleteMetaFile(hmf);
	//	delete hmf;

	//	//Присваивание временного указателя постоянному
	//	m_pMF = temp;
	//	/*Если первый раз была вызвана функия OnPaint, то вызавать очистку экрана*/
	//	static bool firstTime = TRUE;
	//	if (firstTime)
	//	{
	//		OnClickedClearbtn();
	//		firstTime = FALSE;
	//	}
	//}
	//else
	//{
	//	CDialogEx::OnPaint();
	//}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFC_Lab8Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_Lab8Dlg::OnClickedClearbtn()
{
	//Получить указатель на контекст устройства
	CClientDC dc(this);
	//Закрыть метафайл
	HMETAFILE hmf = m_pMF->Close();
	//Удалить данные о метафайле
	DeleteMetaFile(hmf);
	//delete hmf;

	//Cоздать новый метафайл
	m_pMF = new CMetaFileDC();
	m_pMF->Create();
	m_pMF->SetAttribDC(dc);

	//Выбрать нулевое перо
	dc.SelectStockObject(NULL_PEN);
	dc.Rectangle(m_Canvas);

	//Записать команды в метафайл
	m_pMF->SelectStockObject(NULL_PEN);
	m_pMF->Rectangle(m_Canvas.left, m_Canvas.top,
	m_Canvas.right + 1, m_Canvas.bottom + 1);

	//Очистить окно
	dc.Rectangle(m_Canvas);
}



void CMFC_Lab8Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//Проверить было ли нажатие внутри области рисования.
	if (m_Canvas.PtInRect(point))
	{
		//Присвоить координаты начала двум переменным
		m_LineStart = point;
		m_LineEnd = point;
		m_IsDrawing = true;

		m_Pen.DeleteObject();
		//Обновить переменные значениями в окне прграммы
		UpdateData(TRUE);
		//Создать новую кисть с учетом размера
		m_Pen.CreatePen(m_PenStyle, m_PenWidth, m_PenColor);

		//Захватить мышь
		SetCapture();
	}

	//CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFC_Lab8Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_IsDrawing && (nFlags & MK_LBUTTON) && m_Canvas.PtInRect(point))
	{
		//this code for freehand
		//if (m_ShapesCombo.GetCurSel() == 0) {
		//	//Получить указатель на контекст устройства
		//	CClientDC dc(this);

		//	//Присвоить координаты щелчка переменной m_LineEnd
		//	m_LineEnd = point;

		//	//Нарисовать линию
		//	dc.MoveTo(m_LineStart);
		//	dc.LineTo(m_LineEnd);
		//	
		//	/*Присвоить текущее переменной m_LineStart значение позиции курсора*/
		//	m_LineStart = m_LineEnd;
		//	
		//}
		//end of code for freehand

		//Нарисовать фигуру методом резиновой нити
		globalPoint = point;
		DrawShape(true);

		//Поменять координаты конца на текущее положение курсора
		m_LineStart=m_LineEnd;

		//Стереть предыдущую и нарисовать новую фигуру
		DrawShape(true);

	}

//	CDialogEx::OnMouseMove(nFlags, point);
}


void CMFC_Lab8Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{	
	m_IsDrawing = FALSE;

	/*Если мышка отпущена внутри области рисования, то нарисовать фигуру окончательно*/
	if (m_Canvas.PtInRect(point))
	{
		m_LineEnd = point;
		DrawShape(false);
	}
	//Если нет, то стереть
	else
	{
		DrawShape(true);
	}
	m_LineStart = point;

	ReleaseCapture();

	//CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFC_Lab8Dlg::OnStnClickedPencolor()
{
	/*Создать объект класса диалоговой панели выбора цвета и передать ему в конструкторе текущее значение цвета*/
	CColorDialog dlg(m_PenColor);

	//Вывод диалогового окна
	if (dlg.DoModal() == IDOK)
	{
		//Установка цвета
		m_PenColor = dlg.GetColor();

		//Создание кисти
		CBrush swatch;
		swatch.CreateSolidBrush(m_PenColor);

		//Получить объект контекста устройства
		CClientDC dc(this);

		//Закрашивание индикатора выбранным цветом
		dc.FillRect(&m_PenColorSwatch, &swatch);
	}
}


void CMFC_Lab8Dlg::DrawShape(bool stretch)
{
	//Получить объект контекста устройства
	CClientDC dc(this);

	//Установить атрибуты DC
	dc.SetAttribDC(dc);
	dc.SelectObject(&m_Brush);
	m_pMF->SetAttribDC(dc);
	dc.IntersectClipRect(m_Canvas);
	m_pMF->IntersectClipRect(m_Canvas);

	//Получить номер позиции из спика названий фигур
	int drawmode = m_ShapesCombo.GetCurSel();

	dc.SelectObject(&m_Brush);
	//Выбрать перо
	dc.SelectObject(&m_Pen);
	//Записать операторы в метафайл
	m_pMF->SelectObject(&m_Pen);
	m_pMF->SelectObject(&m_Brush);

	//Метод резиновой нити
	if (stretch && drawmode != 0)
	{
		//Установить метод резиновой нити
		dc.SetROP2(R2_NOT);
	}

	//if (drawmode == 0) {
	//	m_LineEnd = globalPoint;
	//	dc.MoveTo(m_LineStart);
	//	dc.LineTo(m_LineEnd);
	//	m_LineStart = m_LineEnd;
	//	//Записать операторы в метафайл
	//	m_pMF->MoveTo(m_LineStart);
	//	m_pMF->LineTo(m_LineEnd);




	//} else

	//Конструкция выбора фигуры
	switch (drawmode)
	{
		//Свободное рисование
	case 0:
		m_LineEnd = globalPoint;
		dc.MoveTo(m_LineStart);
		dc.LineTo(m_LineEnd);
		m_LineStart = m_LineEnd;
		//Записать операторы в метафайл
		m_pMF->MoveTo(m_LineStart);
		m_pMF->LineTo(m_LineEnd);
		break;
	//	//Рисование линий
	case 1:
		dc.MoveTo(m_LineStart);
		dc.LineTo(m_LineEnd);
		/*Записать операторы в метафайл, если не выбран режим резиновой нити*/
		if (!stretch)
		{
			m_pMF->MoveTo(m_LineStart);
			m_pMF->LineTo(m_LineEnd);
		}
		break;
		//Рисование элипсов
	case 2:
		dc.Ellipse(CRect(m_LineStart, m_LineEnd));
		//Записать операторы в метафайл
		if (!stretch)
		{
			m_pMF->Ellipse(CRect(m_LineStart, m_LineEnd));
		}
		break;
		//Рисование прямоугольника
	case 3:
		dc.Rectangle(CRect(m_LineStart, m_LineEnd));
		//Записать операторы в метафайл
		if (!stretch)
		{
			m_pMF->Rectangle(CRect(m_LineStart, m_LineEnd));
		}
		break;
	}


}


void CMFC_Lab8Dlg::OnSelchangeBrushstyle()
{
	//Удалить предыдущий объект
	m_Brush.DeleteObject();

	//Получить номер выбранной позиции
	int style = m_BrushStyleList.GetCurSel();

	//По номеру создать кисть, с выбранным стилем
	switch (style)
	{
	case 0:
		m_Brush.CreateStockObject(NULL_BRUSH);
		break;

	case 1:
		m_Brush.CreateSolidBrush(m_BrushColor);
		break;

	case 2:
		m_Brush.CreateHatchBrush(HS_BDIAGONAL, m_BrushColor);
		break;

	case 3:
		m_Brush.CreateHatchBrush(HS_FDIAGONAL, m_BrushColor);
		break;

	case 4:
		m_Brush.CreateHatchBrush(HS_CROSS, m_BrushColor);
		break;

	case 5:
		m_Brush.CreateHatchBrush(HS_DIAGCROSS, m_BrushColor);
		break;

	case 6:
		m_Brush.CreateHatchBrush(HS_HORIZONTAL, m_BrushColor);
		break;

	case 7:
		m_Brush.CreateHatchBrush(HS_VERTICAL, m_BrushColor);
		break;

	case 9:
		m_Brush.CreateStockObject(LTGRAY_BRUSH);
		break;


	case 10:
		m_Brush.CreateStockObject(GRAY_BRUSH);
		break;

	case 11:
		m_Brush.CreateStockObject(DKGRAY_BRUSH);
		break;

	case 12:
		m_Brush.CreateStockObject(BLACK_BRUSH);
		break;

		//Создать кисть по умолчанию
	default:
		m_Brush.CreateStockObject(WHITE_BRUSH);
		break;
	}

	//Вызвать функцию зарисовки окна Preview
	PaintBrushPreview();
}


void CMFC_Lab8Dlg::PaintBrushPreview()
{
	CClientDC dc(this);
	dc.FillRect(&m_BrushPreviewSwatch, &m_Brush);
}


void CMFC_Lab8Dlg::OnClickedBrushcolor()
{
	//Создать объект диалогового окна выбор цвета
	CColorDialog dlg(m_BrushColor);

	/*Если была нажата кнопка ОК, то закрасить индикатор цвета*/
	if (dlg.DoModal() == IDOK)
	{
		m_BrushColor = dlg.GetColor();
		CClientDC dc(this);
		CBrush b(m_BrushColor);

		//Закрашивание индикатора цвета кисти
		dc.FillRect(&m_BrushColorSwatch, &b);
	}

	/*Запустить функцию создания кисти, выбранным цветом*/
	OnSelchangeBrushstyle();
}


void CMFC_Lab8Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	//Закрыть и удалить метафайл
	m_pMF->Close();
	delete m_pMF;

}
