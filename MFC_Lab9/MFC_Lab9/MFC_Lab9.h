
// MFC_Lab9.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCLab9App:
// Сведения о реализации этого класса: MFC_Lab9.cpp
//

class CMFCLab9App : public CWinApp
{
public:
	CMFCLab9App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCLab9App theApp;
