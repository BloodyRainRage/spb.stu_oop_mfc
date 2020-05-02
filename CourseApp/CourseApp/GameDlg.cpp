//
//
#include "pch.h"
#include "GameDlg.h"
#include "afxdialogex.h"
#include <time.h>

// GameDlg dialog

IMPLEMENT_DYNAMIC(GameDlg, CDialogEx)

GameDlg::GameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(GameDlg::IDD, pParent) {
	StartNewGame();
}

GameDlg::~GameDlg() {
}

void GameDlg::DoDataExchange(CDataExchange* pDX) {
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(GameDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()



// GameDlg message handlers

void GameDlg::OnPaint() {
	CPaintDC dc(this);

	// Background
	CRect gameRect;
	GetClientRect(gameRect);

	dc.FillSolidRect(gameRect, RGB(0, 50, 50));

	//Check if the snake is out of bounds
	if (snake_xcoords.back() > gameRect.right || snake_xcoords.back() < gameRect.left || 
		snake_ycoords.back() > gameRect.bottom || snake_ycoords.back() < gameRect.top){
		
		StartNewGame();

	}

	// Check if snake ate itself
	for (int i = 0; i < (snake_xcoords.size() - 1); i++){
		if (snake_xcoords.back() == snake_xcoords[i]){
			if (snake_ycoords.back() == snake_ycoords[i])
			{
				StartNewGame();
			}
		}
	}

	//Draws the fruit
	DrawFruit(gameRect.right, gameRect.bottom, &dc);

	//Draws the snake
	for (int i = 0; i < snake_xcoords.size(); i++)
	{
		Rectangle(dc, snake_xcoords[i], snake_ycoords[i], snake_xcoords[i] + 10, snake_ycoords[i] + 10);
	}

	//Check if snake ate the fruit
	if (abs(snake_xcoords.back() - fruit_xcoord) < 6)
		if (abs(snake_ycoords.back() - fruit_ycoord) < 6){
			AteFruit = true;
		}

	//Timer
	UINT_PTR myTimer = SetTimer(1, 1000 / difficulty, NULL); // one event every 500 ms = 0.5 s

	//OnTimer(myTimer);



}

void GameDlg::StartNewGame() {
	snake_xcoords.resize(0);
	snake_ycoords.resize(0);

	snake_xcoords.push_back(100);
	snake_ycoords.push_back(100);

	snake_xcoords.push_back(110);
	snake_ycoords.push_back(100);

	xDir = 1;
	yDir = 0;

	srand(time(NULL));
	fruit_xcoord = rand() % 445 + 10;
	srand(time(NULL));
	fruit_ycoord = rand() % 445 + 10;
	AteFruit = false;
}

void GameDlg::OnKeyDown(UINT nChar, UINT uRepCntm, UINT uFlg)
{
	switch (nChar){
	// Turn right
	case 0x44: xDir = 1;  yDir = 0; break; // D is pressed
	// Turn up
	case 0x57: xDir = 0;  yDir = -1; break; // W is pressed
	// Trun left
	case 0x41: xDir = -1;  yDir = 0; break; // A is pressed
	//Turn Down
	case 0x53: xDir = 0;  yDir = 1; break; // S is pressed
	}


}

void GameDlg::MoveSnake(int xDir, int yDir) {
	snake_xcoords.push_back(snake_xcoords.back() + 10 * xDir);
	snake_ycoords.push_back(snake_ycoords.back() + 10 * yDir);

	if (AteFruit == false){
		snake_xcoords.erase(snake_xcoords.begin());
		snake_ycoords.erase(snake_ycoords.begin());
	}

	Invalidate();
	UpdateWindow();
}



void GameDlg::OnTimer(UINT_PTR nIDEvent) {
	// TODO: Add your message handler code here and/or call default
	MoveSnake(xDir, yDir);

	CDialogEx::OnTimer(nIDEvent);
}

void GameDlg::MakeFruit() {
	AteFruit = false;

	srand(time(NULL));
	fruit_xcoord = rand();
	srand(fruit_xcoord * time(NULL));
	fruit_ycoord = rand();
}

void GameDlg::DrawFruit(int width, int height, CPaintDC* dc) {
	if (AteFruit == false){
		Rectangle(*dc, fruit_xcoord + 1, fruit_ycoord + 1, fruit_xcoord + 10, fruit_ycoord + 10);
	} else{
		MakeFruit();
		fruit_xcoord = fruit_xcoord % (width - 15) + 8;
		fruit_ycoord = fruit_ycoord % (height - 15) + 8;
		Rectangle(*dc, fruit_xcoord + 1, fruit_ycoord + 1, fruit_xcoord + 10, fruit_ycoord + 10);
	}

}
