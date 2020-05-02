
// CourseApp.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CCourseAppApp:
// Сведения о реализации этого класса: CourseApp.cpp
//

class CCourseAppApp : public CWinApp
{
public:
	CCourseAppApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};


