#pragma once
#include "afxwin.h"


// CLoginDlg 对话框
//登录界面

class CLoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLoginDlg();

// 对话框数据
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSignin();
private:
	CString m_n_pwd;
	CString m_n_name;
	CButton m_rebr;
public:
	afx_msg void OnBnClickedQuit();
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnOK();
};
