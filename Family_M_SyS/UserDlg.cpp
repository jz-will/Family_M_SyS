// UserDlg.cpp : ʵ���ļ�
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


// CUserDlg ���

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


// CUserDlg ��Ϣ�������

//��ʼ��
void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	CInfoFile f;
	CString name,pwd;
	f.Readlogin(name,pwd);
	m_fname = name;
	this->UpdateData( false );
}


//�޸�����
void CUserDlg::OnBnClickedname()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData( true );
	if(m_name.IsEmpty())
	{
		this->MessageBox(TEXT("���˺Ų���Ϊ��"));
		return;
	}
	CInfoFile f;
	CString name,pwd;
	f.Readlogin(name,pwd);
	if(m_name == name)
	{
		this->MessageBox(TEXT("���˺�����˺��ظ���"));
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
	this->MessageBox(TEXT("�޸��˺ųɹ���"));
	m_name.Empty();
	this->UpdateData( false );
}

//�޸�����
void CUserDlg::OnBnClickedpwd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData( true );
	if(m_pwd.IsEmpty() | m_pwd2.IsEmpty())
	{
		this->MessageBox(TEXT("�����벻��Ϊ�գ�"));
		return;
	}
	if(m_pwd != m_pwd2)
	{
		this->MessageBox(TEXT("���벻һ�£�"));
		return;
	}
	CInfoFile f;
	CString name,pwd;
	f.Readlogin(name,pwd);
	if(m_pwd == pwd)
	{
		this->MessageBox(TEXT("�¾����벻��һ�£�"));
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
	this->MessageBox(TEXT("�޸�����ɹ���"));
	this->UpdateData( false );
}