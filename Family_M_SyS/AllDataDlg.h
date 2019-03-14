#pragma once
#include "afxcmn.h"



// CAllDataDlg 窗体视图
// 实现展现的功能

class CAllDataDlg : public CFormView
{
	DECLARE_DYNCREATE(CAllDataDlg)

protected:
	CAllDataDlg();           // 动态创建所使用的受保护的构造函数
	virtual ~CAllDataDlg();

public:
	enum { IDD = IDD_ALLINFO };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual void OnInitialUpdate();
};


