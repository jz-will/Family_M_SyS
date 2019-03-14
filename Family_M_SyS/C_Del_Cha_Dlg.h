#pragma once
#include "afxwin.h"
#include "afxdtctl.h"



// C_Del_Cha_Dlg 窗体视图
// 实现删除和查找的功能

class C_Del_Cha_Dlg : public CFormView
{
	DECLARE_DYNCREATE(C_Del_Cha_Dlg)

protected:
	C_Del_Cha_Dlg();           // 动态创建所使用的受保护的构造函数
	virtual ~C_Del_Cha_Dlg();

public:
	enum { IDD = IDD_DEL_CHA };
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
	CString m_more;
	CComboBox m_way;
public:
	virtual void OnInitialUpdate();
	
	afx_msg void OnBnClickedChange();
private:
	CComboBox m_time;
	int m_money;
public:
	afx_msg void OnBnClickedDel();
	afx_msg void OnCbnSelchangeTime();
//	virtual void PostNcDestroy();

};


