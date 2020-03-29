
// MFC_Lab8Dlg.h : header file
//

#pragma once


// CMFC_Lab8DlgDlg dialog
class CMFC_Lab8Dlg : public CDialogEx
{
// Construction
public:
	CMFC_Lab8Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAINTORAMA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CRect m_Canvas;
public:
	afx_msg void OnClickedClearbtn();
private:
	CPoint m_LineEnd;
	CPoint m_LineStart;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	COLORREF m_PenColor;
	CRect m_PenColorSwatch;
public:
	afx_msg void OnStnClickedPencolor();
private:
	CPen m_Pen;
public:
	int m_PenWidth;
	int m_PenStyle;
	CComboBox m_ShapesCombo;
private:
	bool m_IsDrawing;
	void DrawShape(bool stretch);
	CPoint globalPoint;
public:
	CBrush m_Brush;
	COLORREF m_BrushColor;
	CRect m_BrushColorSwatch;
	CRect m_BrushPreviewSwatch;
	int m_BrushStyle;
	CListBox m_BrushStyleList;
	afx_msg void OnSelchangeBrushstyle();
	void PaintBrushPreview();
	afx_msg void OnClickedBrushcolor();
	CMetaFileDC* m_pMF;
	afx_msg void OnDestroy();
};
