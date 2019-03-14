
// Family_M_SyS.h : Family_M_SyS 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CFamily_M_SySApp:
// 有关此类的实现，请参阅 Family_M_SyS.cpp
//

class CFamily_M_SySApp : public CWinApp
{
public:
	CFamily_M_SySApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFamily_M_SySApp theApp;
