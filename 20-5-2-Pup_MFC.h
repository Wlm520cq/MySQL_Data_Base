
// 20-5-2-Pup_MFC.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号


// CMy2052PupMFCApp:
// 有关此类的实现，请参阅 20-5-2-Pup_MFC.cpp
//

class CMy2052PupMFCApp : public CWinApp
{
public:
	CMy2052PupMFCApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMy2052PupMFCApp theApp;
