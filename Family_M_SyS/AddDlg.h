#pragma once
#include "afxwin.h"



// CAddDlg 窗体视图
// 实现添加的功能

class CAddDlg : public CFormView
{
	DECLARE_DYNCREATE(CAddDlg)

protected:
	CAddDlg();           // 动态创建所使用的受保护的构造函数
	virtual ~CAddDlg();

public:
	enum { IDD = IDD_ADD };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	unsigned int m_money;
	CString m_more;
	CComboBox m_way;
public:
	afx_msg void OnBnClickedAdd();
	virtual void OnInitialUpdate();
};


