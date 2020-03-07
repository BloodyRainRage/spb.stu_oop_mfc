
// MFC_Lab1.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCLab1App:
// Сведения о реализации этого класса: MFC_Lab1.cpp
//

class CMFCLab1App : public CWinApp
{
public:
	CMFCLab1App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCLab1App theApp;
