// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Family_M_SyS.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "InfoFile.h"

// CLoginDlg �Ի���
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


// CLoginDlg ��Ϣ�������

//У������
void CLoginDlg::OnBnClickedSignin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString name,pwd;
	CInfoFile f;
	f.Readlogin(name,pwd);
	this->UpdateData( true );
	if(m_n_pwd.IsEmpty())
	{
		this->MessageBox("���벻��Ϊ��");
		return;
	}
	if(m_n_pwd != pwd)
	{
		this->MessageBox("�������");
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

//��ȡ���˳�����ϵͳ
void CLoginDlg::OnBnClickedQuit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CLoginDlg::OnCancel();
}

//��ʼ��
BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
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
	// �쳣: OCX ����ҳӦ���� FALSE
}

//ֱ���˳�ϵͳ
void CLoginDlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���
	exit(0);
	CDialogEx::OnCancel();
}

//��Ӧ���� Enter ��
void CLoginDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
	CLoginDlg::OnBnClickedSignin();
}
