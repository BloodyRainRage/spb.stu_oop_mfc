
// MFC_Lab3.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCLab3App:
// Сведения о реализации этого класса: MFC_Lab3.cpp
//

class CMFCLab3App : public CWinApp
{
public:
	CMFCLab3App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCLab3App theApp;
