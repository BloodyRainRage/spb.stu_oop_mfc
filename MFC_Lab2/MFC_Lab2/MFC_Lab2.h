
// MFC_Lab2.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCLab2App:
// Сведения о реализации этого класса: MFC_Lab2.cpp
//

class CMFCLab2App : public CWinApp
{
public:
	CMFCLab2App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCLab2App theApp;
