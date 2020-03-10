
// MFC_Lab7.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCLab7App:
// Сведения о реализации этого класса: MFC_Lab7.cpp
//

class CMFCLab7App : public CWinApp
{
public:
	CMFCLab7App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCLab7App theApp;
