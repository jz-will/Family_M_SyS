
// Family_M_SyS.h : Family_M_SyS Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CFamily_M_SySApp:
// �йش����ʵ�֣������ Family_M_SyS.cpp
//

class CFamily_M_SySApp : public CWinApp
{
public:
	CFamily_M_SySApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFamily_M_SySApp theApp;
