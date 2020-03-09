
// MFC_Lab6.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCLab6App:
// Сведения о реализации этого класса: MFC_Lab6.cpp
//

class CMFCLab6App : public CWinApp
{
public:
	CMFCLab6App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCLab6App theApp;
