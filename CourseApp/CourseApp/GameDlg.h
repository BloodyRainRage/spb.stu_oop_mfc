#pragma once


#include "afxdialogex.h"
#include "pch.h"
#include "CourseApp.h"
#include <vector>
#include <list>

// GameDlg dialog

class GameDlg : public CDialogEx {
	DECLARE_DYNAMIC(GameDlg)

public:
	GameDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~GameDlg();

	// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar, UINT uRepCntm, UINT uFlg);

public:
	void StartNewGame();
	void MoveSnake(int xDir, int yDir);
	void MakeFruit();
	void DrawFruit(int width, int height, CPaintDC* dc);

private:

	std::vector<int> snake_xcoords;
	std::vector<int> snake_ycoords;

	int fruit_xcoord;
	int fruit_ycoord;

	int xDir;  // = -1,0,1
	int yDir;  // = -1,0,1

	bool AteFruit;


public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	//Difficulty
	bool difficultyProvided;
	int difficulty;
};
