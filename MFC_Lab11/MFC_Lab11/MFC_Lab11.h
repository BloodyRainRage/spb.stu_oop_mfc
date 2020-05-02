
// MFC_Lab11.h: основной файл заголовка для приложения MFC_Lab11
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMFCLab11App:
// Сведения о реализации этого класса: MFC_Lab11.cpp
//

class CMFCLab11App : public CWinAppEx
{
public:
	CMFCLab11App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCLab11App theApp;
