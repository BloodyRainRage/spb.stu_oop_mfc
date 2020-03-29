
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
	//�������� ��������� �� ������� ���������� Picture
	CWnd* p_Canvas = GetDlgItem(IDC_CANVAS);

	//�������� ���������� ���� � ���������� m_Canvas
	p_Canvas->GetWindowRect(&m_Canvas);

	//����������� ���������� ��� ���������� �������
	ScreenToClient(&m_Canvas);

	//�������� ���������� ����
	m_Canvas.DeflateRect(2, 2, 1, 1);

	//�������� ��������� �� ������� ����������
	CWnd* pPenColor = GetDlgItem(IDC_PENCOLOR);

	//�������� ���������� �������� ����������
	pPenColor->GetWindowRect(&m_PenColorSwatch);

	//�������� ���������� ������������ ���������� �������
	ScreenToClient(&m_PenColorSwatch);

	//C����� ����� 
	m_PenColorSwatch.DeflateRect(2,2,1,1);

	//�������� ��������� �� ������� ����������
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1);

	/*���������� �������� �������� ��������������� ��� IDC_SPIN1*/
	pSpin->SetRange(1, 32);

	//���������� ��������� �������� �������� � 1;
	pSpin->SetPos(1);

	//���������� ��������� ������� �������
	m_ShapesCombo.SetCurSel(0);

	//�������� ��������� �� ������� ����������
	CWnd* pBrushColor = GetDlgItem(IDC_BRUSHCOLOR);

	//�������� ���������� �������� ����������
	pBrushColor->GetWindowRect(&m_BrushColorSwatch);

	//�������� ���������� ������������ ���������� �������
	ScreenToClient(&m_BrushColorSwatch);

	//C����� �����
	m_BrushColorSwatch.DeflateRect(2, 2, 1, 1);



	//�������� ��������� �� ������� ����������
	CWnd* pPreviewColor = GetDlgItem(IDC_BRUSHPREVIEW);

	//�������� ���������� �������� ����������
	pPreviewColor->GetWindowRect(&m_BrushPreviewSwatch);

	//�������� ���������� ������������ ���������� �������
	ScreenToClient(&m_BrushPreviewSwatch);

	//C����� �����
	m_BrushPreviewSwatch.DeflateRect(2, 2, 1, 1);

	//���������� ��������� ���� �����
	m_BrushColor = RGB(0, 0, 0);

	//������� ����� �����
	m_Brush.CreateStockObject(WHITE_BRUSH);

	// �������� �������� ������ � ������� ListBox
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

	//���������� ��������� ������� ������� �� 8 ��������
	m_BrushStyleList.SetCurSel(8);

	//���������� � ������ ������ ���������
	m_pMF = new CMetaFileDC;
	//������� ��������
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

	//�������� ���������
	HMETAFILE hmf = m_pMF->Close();
	//��������������� ���������
	dc.PlayMetaFile(hmf);

	//������������ ��������� �� ������ ������ ���������� temp
	CMetaFileDC* temp = new CMetaFileDC;
	//�������� �������
	temp->Create();
	//������������ ���������
	temp->PlayMetaFile(hmf);

	//�������� ������������� � ���������
	DeleteMetaFile(hmf);
	//delete hmf;

	//������������ ���������� ��������� �����������
	m_pMF = temp;
	/*���� ������ ��� ���� ������� ������ OnPaint, �� �������� ������� ������*/
	static bool firstTime = TRUE;
	if (firstTime)
	{
		OnClickedClearbtn();
		firstTime = FALSE;
	}


	//if (IsIconic())
	//{
	//	CPaintDC dc(this);

	//	//�������� ���������
	//	HMETAFILE hmf = m_pMF->Close();
	//	//��������������� ���������
	//	dc.PlayMetaFile(hmf);

	//	//������������ ��������� �� ������ ������ ���������� temp
	//	CMetaFileDC* temp = new CMetaFileDC;
	//	//�������� �������
	//	temp->Create();
	//	//������������ ���������
	//	temp->PlayMetaFile(hmf);

	//	//�������� ������������� � ���������
	//	DeleteMetaFile(hmf);
	//	delete hmf;

	//	//������������ ���������� ��������� �����������
	//	m_pMF = temp;
	//	/*���� ������ ��� ���� ������� ������ OnPaint, �� �������� ������� ������*/
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
	//�������� ��������� �� �������� ����������
	CClientDC dc(this);
	//������� ��������
	HMETAFILE hmf = m_pMF->Close();
	//������� ������ � ���������
	DeleteMetaFile(hmf);
	//delete hmf;

	//C������ ����� ��������
	m_pMF = new CMetaFileDC();
	m_pMF->Create();
	m_pMF->SetAttribDC(dc);

	//������� ������� ����
	dc.SelectStockObject(NULL_PEN);
	dc.Rectangle(m_Canvas);

	//�������� ������� � ��������
	m_pMF->SelectStockObject(NULL_PEN);
	m_pMF->Rectangle(m_Canvas.left, m_Canvas.top,
	m_Canvas.right + 1, m_Canvas.bottom + 1);

	//�������� ����
	dc.Rectangle(m_Canvas);
}



void CMFC_Lab8Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//��������� ���� �� ������� ������ ������� ���������.
	if (m_Canvas.PtInRect(point))
	{
		//��������� ���������� ������ ���� ����������
		m_LineStart = point;
		m_LineEnd = point;
		m_IsDrawing = true;

		m_Pen.DeleteObject();
		//�������� ���������� ���������� � ���� ��������
		UpdateData(TRUE);
		//������� ����� ����� � ������ �������
		m_Pen.CreatePen(m_PenStyle, m_PenWidth, m_PenColor);

		//��������� ����
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
		//	//�������� ��������� �� �������� ����������
		//	CClientDC dc(this);

		//	//��������� ���������� ������ ���������� m_LineEnd
		//	m_LineEnd = point;

		//	//���������� �����
		//	dc.MoveTo(m_LineStart);
		//	dc.LineTo(m_LineEnd);
		//	
		//	/*��������� ������� ���������� m_LineStart �������� ������� �������*/
		//	m_LineStart = m_LineEnd;
		//	
		//}
		//end of code for freehand

		//���������� ������ ������� ��������� ����
		globalPoint = point;
		DrawShape(true);

		//�������� ���������� ����� �� ������� ��������� �������
		m_LineStart=m_LineEnd;

		//������� ���������� � ���������� ����� ������
		DrawShape(true);

	}

//	CDialogEx::OnMouseMove(nFlags, point);
}


void CMFC_Lab8Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{	
	m_IsDrawing = FALSE;

	/*���� ����� �������� ������ ������� ���������, �� ���������� ������ ������������*/
	if (m_Canvas.PtInRect(point))
	{
		m_LineEnd = point;
		DrawShape(false);
	}
	//���� ���, �� �������
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
	/*������� ������ ������ ���������� ������ ������ ����� � �������� ��� � ������������ ������� �������� �����*/
	CColorDialog dlg(m_PenColor);

	//����� ����������� ����
	if (dlg.DoModal() == IDOK)
	{
		//��������� �����
		m_PenColor = dlg.GetColor();

		//�������� �����
		CBrush swatch;
		swatch.CreateSolidBrush(m_PenColor);

		//�������� ������ ��������� ����������
		CClientDC dc(this);

		//������������ ���������� ��������� ������
		dc.FillRect(&m_PenColorSwatch, &swatch);
	}
}


void CMFC_Lab8Dlg::DrawShape(bool stretch)
{
	//�������� ������ ��������� ����������
	CClientDC dc(this);

	//���������� �������� DC
	dc.SetAttribDC(dc);
	dc.SelectObject(&m_Brush);
	m_pMF->SetAttribDC(dc);
	dc.IntersectClipRect(m_Canvas);
	m_pMF->IntersectClipRect(m_Canvas);

	//�������� ����� ������� �� ����� �������� �����
	int drawmode = m_ShapesCombo.GetCurSel();

	dc.SelectObject(&m_Brush);
	//������� ����
	dc.SelectObject(&m_Pen);
	//�������� ��������� � ��������
	m_pMF->SelectObject(&m_Pen);
	m_pMF->SelectObject(&m_Brush);

	//����� ��������� ����
	if (stretch && drawmode != 0)
	{
		//���������� ����� ��������� ����
		dc.SetROP2(R2_NOT);
	}

	//if (drawmode == 0) {
	//	m_LineEnd = globalPoint;
	//	dc.MoveTo(m_LineStart);
	//	dc.LineTo(m_LineEnd);
	//	m_LineStart = m_LineEnd;
	//	//�������� ��������� � ��������
	//	m_pMF->MoveTo(m_LineStart);
	//	m_pMF->LineTo(m_LineEnd);




	//} else

	//����������� ������ ������
	switch (drawmode)
	{
		//��������� ���������
	case 0:
		m_LineEnd = globalPoint;
		dc.MoveTo(m_LineStart);
		dc.LineTo(m_LineEnd);
		m_LineStart = m_LineEnd;
		//�������� ��������� � ��������
		m_pMF->MoveTo(m_LineStart);
		m_pMF->LineTo(m_LineEnd);
		break;
	//	//��������� �����
	case 1:
		dc.MoveTo(m_LineStart);
		dc.LineTo(m_LineEnd);
		/*�������� ��������� � ��������, ���� �� ������ ����� ��������� ����*/
		if (!stretch)
		{
			m_pMF->MoveTo(m_LineStart);
			m_pMF->LineTo(m_LineEnd);
		}
		break;
		//��������� �������
	case 2:
		dc.Ellipse(CRect(m_LineStart, m_LineEnd));
		//�������� ��������� � ��������
		if (!stretch)
		{
			m_pMF->Ellipse(CRect(m_LineStart, m_LineEnd));
		}
		break;
		//��������� ��������������
	case 3:
		dc.Rectangle(CRect(m_LineStart, m_LineEnd));
		//�������� ��������� � ��������
		if (!stretch)
		{
			m_pMF->Rectangle(CRect(m_LineStart, m_LineEnd));
		}
		break;
	}


}


void CMFC_Lab8Dlg::OnSelchangeBrushstyle()
{
	//������� ���������� ������
	m_Brush.DeleteObject();

	//�������� ����� ��������� �������
	int style = m_BrushStyleList.GetCurSel();

	//�� ������ ������� �����, � ��������� ������
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

		//������� ����� �� ���������
	default:
		m_Brush.CreateStockObject(WHITE_BRUSH);
		break;
	}

	//������� ������� ��������� ���� Preview
	PaintBrushPreview();
}


void CMFC_Lab8Dlg::PaintBrushPreview()
{
	CClientDC dc(this);
	dc.FillRect(&m_BrushPreviewSwatch, &m_Brush);
}


void CMFC_Lab8Dlg::OnClickedBrushcolor()
{
	//������� ������ ����������� ���� ����� �����
	CColorDialog dlg(m_BrushColor);

	/*���� ���� ������ ������ ��, �� ��������� ��������� �����*/
	if (dlg.DoModal() == IDOK)
	{
		m_BrushColor = dlg.GetColor();
		CClientDC dc(this);
		CBrush b(m_BrushColor);

		//������������ ���������� ����� �����
		dc.FillRect(&m_BrushColorSwatch, &b);
	}

	/*��������� ������� �������� �����, ��������� ������*/
	OnSelchangeBrushstyle();
}


void CMFC_Lab8Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	//������� � ������� ��������
	m_pMF->Close();
	delete m_pMF;

}
