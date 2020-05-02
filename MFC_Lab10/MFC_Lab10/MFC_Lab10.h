
// MFC_Lab10.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCLab10App:
// Сведения о реализации этого класса: MFC_Lab10.cpp
//

class CMFCLab10App : public CWinApp
{
public:
	CMFCLab10App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCLab10App theApp;
