﻿
// MFC_Lab4.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCLab4App:
// Сведения о реализации этого класса: MFC_Lab4.cpp
//

class CMFCLab4App : public CWinApp
{
public:
	CMFCLab4App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCLab4App theApp;
