#pragma once



// CUserDlg 窗体视图
//个人信息栏

class CUserDlg : public CFormView
{
	DECLARE_DYNCREATE(CUserDlg)

protected:
	CUserDlg();           // 动态创建所使用的受保护的构造函数
	virtual ~CUserDlg();

public:
	enum { IDD = IDD_USR };
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
	virtual void OnInitialUpdate();

private:
	//校对
	CString m_name;
	CString m_pwd;
	CString m_pwd2;
	CString m_fname;

public:
	afx_msg void OnBnClickedname();
	afx_msg void OnBnClickedpwd();
};


