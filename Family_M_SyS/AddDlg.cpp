// AddDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Family_M_SyS.h"
#include "AddDlg.h"
#include "InfoFile.h"

// CAddDlg

IMPLEMENT_DYNCREATE(CAddDlg, CFormView)

CAddDlg::CAddDlg()
	: CFormView(CAddDlg::IDD)
	, m_money(0)
	, m_more(_T(""))
{

}

CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MONEY, m_money);
	DDX_Control(pDX, IDC_WAY, m_way);
	DDX_Text(pDX, IDC_MORE, m_more);
}

BEGIN_MESSAGE_MAP(CAddDlg, CFormView)
	ON_BN_CLICKED(IDC_ADD, &CAddDlg::OnBnClickedAdd)
END_MESSAGE_MAP()


// CAddDlg ���

#ifdef _DEBUG
void CAddDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAddDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAddDlg ��Ϣ�������


void CAddDlg::OnBnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData( true );
	if(m_money == 0)
	{
		this->MessageBox("����Ϊ�㣬���飡");
		return;
	}
	else if(m_money < 0)
	{
		this->MessageBox("ֻ��¼�����գ���ѡ�����뻹��֧��Ŷ��");
		return;
	}
	if(m_more.IsEmpty())
	{
		this->MessageBox("���¼��Ǯ��ȥ�δ�Ŷ��");
		return;
	}

	CInfoFile f;
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	f.Read_All();
	
	msg tmp;
	CString str;
	CStringA stra;
	tmp.money = m_money;

	str = m_more;
	stra = str;
	tmp.more = stra.GetBuffer();

	str.Format(_T("%d-%d-%d %d:%d:%d"),tm.wYear,tm.wMonth, tm.wDay, tm.wHour, tm.wMinute, tm.wSecond);
	stra = str;
	tmp.tm = stra.GetBuffer();

	tmp.ty = m_way.GetCurSel();

	f.ls.push_back(tmp);

	f.Write_All();
	f.ls.clear();

	m_money = 0;
	m_more.Empty();
	this->UpdateData( false );
	this->MessageBox("�����Ŀ�ɹ���");
}

//Ĭ�ϳ�ʼֵΪ����
void CAddDlg::OnInitialUpdate()
{
	// TODO: �ڴ����ר�ô����/����û���
	CFormView::OnInitialUpdate();
	m_way.SetCurSel(0);
	this->UpdateData( false );
}
