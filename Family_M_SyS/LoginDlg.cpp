// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Family_M_SyS.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "InfoFile.h"

// CLoginDlg 对话框
IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginDlg::IDD, pParent)
	, m_n_pwd(_T(""))
	, m_n_name(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_n_pwd);
	DDV_MaxChars(pDX, m_n_pwd, 20);
	DDX_Text(pDX, IDC_EDIT1, m_n_name);
	DDV_MaxChars(pDX, m_n_name, 10);
	DDX_Control(pDX, IDC_CHECK1, m_rebr);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SIGNIN, &CLoginDlg::OnBnClickedSignin)
	ON_BN_CLICKED(IDC_QUIT, &CLoginDlg::OnBnClickedQuit)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序

//校对密码
void CLoginDlg::OnBnClickedSignin()
{
	// TODO: 在此添加控件通知处理程序代码
	CString name,pwd;
	CInfoFile f;
	f.Readlogin(name,pwd);
	this->UpdateData( true );
	if(m_n_pwd.IsEmpty())
	{
		this->MessageBox("密码不能为空");
		return;
	}
	if(m_n_pwd != pwd)
	{
		this->MessageBox("密码错误");
		return;
	}
	if(BST_CHECKED == IsDlgButtonChecked( IDC_CHECK1))
	{
		m_rebr.SetCheck(false);
		ofstream ofs;
		ofs.open(_R_PWD);
		ofs.clear();
		string str;
		CStringA stra;
		stra = m_n_pwd;
		str = stra.GetBuffer();
		ofs << str <<endl;
		ofs.close();
	}
	else
	{
		ofstream ofs;
		ofs.open(_R_PWD);
		ofs.clear();
		ofs.close();
	}
	CDialogEx::OnOK();


}

//点取消退出整个系统
void CLoginDlg::OnBnClickedQuit()
{
	// TODO: 在此添加控件通知处理程序代码
	CLoginDlg::OnCancel();
}

//初始化
BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CInfoFile f;
	CString name,pwd;
	f.Readlogin(name,pwd);
	m_n_name = name;
	ifstream ifs;
	ifs.open(_R_PWD);
	if(ifs||!ifs.eof())
	{
		char buf[32];
		ifs.getline(buf,sizeof(buf));
		m_n_pwd = buf;
		m_rebr.SetCheck(true);
	}
	if(m_n_pwd.IsEmpty())
	{
		m_rebr.SetCheck( false );
	}
	this->UpdateData( false );
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

//直接退出系统
void CLoginDlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类
	exit(0);
	CDialogEx::OnCancel();
}

//响应键盘 Enter 键
void CLoginDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
	CLoginDlg::OnBnClickedSignin();
}
