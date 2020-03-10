// CSetDlg.cpp: файл реализации
//

#include "pch.h"
#include "MFC_Lab7.h"
#include "CSetDlg.h"
#include "afxdialogex.h"


// Диалоговое окно CSetDlg

IMPLEMENT_DYNAMIC(CSetDlg, CDialogEx)

CSetDlg::CSetDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CUSTOM_DIALOG, pParent)
	, m_RedRadio(0) {

}

CSetDlg::~CSetDlg()
{
}

void CSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RED_RADIO, m_RedRadio);
}


BEGIN_MESSAGE_MAP(CSetDlg, CDialogEx)

	ON_BN_CLICKED(IDC_OK, &CSetDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CANCEL, &CSetDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_RED_RADIO, &CSetDlg::OnBnClickedRedRadio)
	ON_BN_CLICKED(IDC_GREEN_RADIO, &CSetDlg::OnBnClickedGreenRadio)
	ON_BN_CLICKED(IDC_BLUE_RADIO, &CSetDlg::OnBnClickedBlueRadio)
END_MESSAGE_MAP()


// Обработчики сообщений CSetDlg




void CSetDlg::OnBnClickedOk() {
	// TODO: добавьте свой код обработчика уведомлений
	OnOK();
}


void CSetDlg::OnBnClickedCancel() {
	// TODO: добавьте свой код обработчика уведомлений
	OnCancel();
}

//last task
void CSetDlg::OnBnClickedRedRadio() {
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(TRUE);
}


void CSetDlg::OnBnClickedGreenRadio() {
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(TRUE);
}


void CSetDlg::OnBnClickedBlueRadio() {
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(TRUE);
}
