// UserDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Family_M_SyS.h"
#include "UserDlg.h"
#include "InfoFile.h"

// CUserDlg

IMPLEMENT_DYNCREATE(CUserDlg, CFormView)

CUserDlg::CUserDlg()
	: CFormView(CUserDlg::IDD)
	, m_name(_T(""))
	, m_pwd(_T(""))
	, m_pwd2(_T(""))
	, m_fname(_T(""))
{

}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, m_name);
	DDX_Text(pDX, IDC_EDIT1, m_pwd);
	DDX_Text(pDX, IDC_EDIT4, m_name);
	DDV_MaxChars(pDX, m_name, 10);
	DDX_Text(pDX, IDC_EDIT1, m_pwd);
	DDV_MaxChars(pDX, m_pwd, 20);
	DDX_Text(pDX, IDC_EDIT2, m_pwd2);
	DDV_MaxChars(pDX, m_pwd2, 20);
	DDX_Text(pDX, IDC_EDIT3, m_fname);
	DDV_MaxChars(pDX, m_fname, 10);
}

BEGIN_MESSAGE_MAP(CUserDlg, CFormView)
	ON_BN_CLICKED(IDC_name, &CUserDlg::OnBnClickedname)
	ON_BN_CLICKED(IDC_pwd, &CUserDlg::OnBnClickedpwd)
END_MESSAGE_MAP()


// CUserDlg 诊断

#ifdef _DEBUG
void CUserDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserDlg 消息处理程序

//初始化
void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	CInfoFile f;
	CString name,pwd;
	f.Readlogin(name,pwd);
	m_fname = name;
	this->UpdateData( false );
}


//修改名称
void CUserDlg::OnBnClickedname()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData( true );
	if(m_name.IsEmpty())
	{
		this->MessageBox(TEXT("新账号不能为空"));
		return;
	}
	CInfoFile f;
	CString name,pwd;
	f.Readlogin(name,pwd);
	if(m_name == name)
	{
		this->MessageBox(TEXT("新账号与旧账号重复！"));
		return;
	}
	char *tname, *tpwd;
	CStringA tmp1,tmp2;
	tmp1 = m_name;
	tname = tmp1.GetBuffer();
	tmp2 = pwd;
	tpwd = tmp2.GetBuffer();
	f.WritePwd(tname,tpwd);
	m_fname = m_name;
	this->MessageBox(TEXT("修改账号成功！"));
	m_name.Empty();
	this->UpdateData( false );
}

//修改密码
void CUserDlg::OnBnClickedpwd()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData( true );
	if(m_pwd.IsEmpty() | m_pwd2.IsEmpty())
	{
		this->MessageBox(TEXT("新密码不能为空！"));
		return;
	}
	if(m_pwd != m_pwd2)
	{
		this->MessageBox(TEXT("密码不一致！"));
		return;
	}
	CInfoFile f;
	CString name,pwd;
	f.Readlogin(name,pwd);
	if(m_pwd == pwd)
	{
		this->MessageBox(TEXT("新旧密码不能一致！"));
		return;
	}
	char *tname,*tpwd;
	CStringA tmp1,tmp2;
	tmp1 = name;
	tname = tmp1.GetBuffer();
	tmp2 = m_pwd;
	tpwd = tmp2.GetBuffer();
	f.WritePwd(tname,tpwd);
	m_pwd.Empty();
	m_pwd2.Empty();
	this->MessageBox(TEXT("修改密码成功！"));
	this->UpdateData( false );
}