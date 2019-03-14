// AllDataDlg.cpp : ʵ���ļ�

#include "stdafx.h"
#include "Family_M_SyS.h"
#include "AllDataDlg.h"
#include "InfoFile.h"

// CAllDataDlg

IMPLEMENT_DYNCREATE(CAllDataDlg, CFormView)

CAllDataDlg::CAllDataDlg()
	: CFormView(CAllDataDlg::IDD)
{

}

CAllDataDlg::~CAllDataDlg()
{
}

void CAllDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CAllDataDlg, CFormView)
END_MESSAGE_MAP()


// CAllDataDlg ���

#ifdef _DEBUG
void CAllDataDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAllDataDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAllDataDlg ��Ϣ�������

//չʾ�ļ��е�������Ŀ
void CAllDataDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	CString hd[] = {"���","��ע","��¼ʱ��","����"};

	m_list.InsertColumn(0,hd[0],LVCFMT_CENTER,50);
	m_list.InsertColumn(1,hd[1],LVCFMT_CENTER,200);
	m_list.InsertColumn(2,hd[2],LVCFMT_CENTER,150);
	m_list.InsertColumn(3,hd[3],LVCFMT_CENTER,50);
	m_list.SetExtendedStyle(m_list.GetExtendedStyle()| LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);


	CInfoFile f;
	f.Read_All();
	if(f.num==0)
	{
		this->MessageBox("�����ݣ�");
		return;
	}
	int i = 0;
	CString str;
	for(list<msg>::iterator it=f.ls.begin();it!=f.ls.end(); it++,i++)
	{
		str.Format(_T("%d"), it->money);
		m_list.InsertItem(i,  str);
		int column = 1;
		m_list.SetItemText(i, column++, (CString)it->more.c_str());
		m_list.SetItemText(i, column++, (CString)it->tm.c_str());
		if(it->ty==0)
		{
			m_list.SetItemText(i, column++, "����");
		}
		else
		{
			m_list.SetItemText(i, column++, "֧��");
		}
		
	}
}