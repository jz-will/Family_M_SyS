// C_Del_Cha_Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Family_M_SyS.h"
#include "C_Del_Cha_Dlg.h"
#include "InfoFile.h"

// C_Del_Cha_Dlg

IMPLEMENT_DYNCREATE(C_Del_Cha_Dlg, CFormView)
 
bool one; //���ڴ������һ��ѡ��ʱ���ǵ�����ʾ

C_Del_Cha_Dlg::C_Del_Cha_Dlg()
	: CFormView(C_Del_Cha_Dlg::IDD)
	, m_more(_T(""))
	, m_money(0)
{
	one = true;
}

C_Del_Cha_Dlg::~C_Del_Cha_Dlg()
{
	one = false;
}

void C_Del_Cha_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_way);
	DDX_Text(pDX, IDC_EDIT2, m_more);
	DDX_Control(pDX, IDC_TIME, m_time);
	DDX_Text(pDX, IDC_EDIT1, m_money);
}

BEGIN_MESSAGE_MAP(C_Del_Cha_Dlg, CFormView)
	ON_BN_CLICKED(IDC_Change, &C_Del_Cha_Dlg::OnBnClickedChange)
	ON_BN_CLICKED(IDC_DEL, &C_Del_Cha_Dlg::OnBnClickedDel)
	ON_CBN_SELCHANGE(IDC_TIME, &C_Del_Cha_Dlg::OnCbnSelchangeTime)
END_MESSAGE_MAP()


// C_Del_Cha_Dlg ���

#ifdef _DEBUG
void C_Del_Cha_Dlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void C_Del_Cha_Dlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// C_Del_Cha_Dlg ��Ϣ�������


void C_Del_Cha_Dlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	// TODO: �ڴ����ר�ô����/����û���
	this->UpdateData( true );
	this->GetDlgItem(IDC_Change)->EnableWindow( false );
	this->GetDlgItem(IDC_DEL)->EnableWindow( false );
	this->GetDlgItem(IDC_COMBO1)->EnableWindow( false );
	this->GetDlgItem(IDC_EDIT1)->EnableWindow( false );
	this->GetDlgItem(IDC_EDIT2)->EnableWindow( false );
	CInfoFile f;
	f.Read_All();
	m_time.ResetContent();
	for(list<msg>::iterator it=f.ls.begin();it!=f.ls.end(); it++)
	{
		//str.Format(_T("%s"),it->tm.c_str());
		CA2T str(it->tm.c_str());
		m_time.AddString(str);
	}
	f.ls.clear();
	this->UpdateData( false );
}


//�޸�
void C_Del_Cha_Dlg::OnBnClickedChange()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData( true );
	CInfoFile f;
	f.Read_All();
	CString str,str2;
	CStringA stra;
	this->GetDlgItem(IDC_TIME)->GetWindowText(str);
	for(list<msg>::iterator it=f.ls.begin();it!=f.ls.end(); it++)
	{
		CA2T str2(it->tm.c_str());
		if(str == str2)
		{
			stra = m_more;
			if(it->more == stra.GetBuffer())
			{
				if(it->ty == m_way.GetCurSel())
				{
					if(it->money == m_money)
					{
						this->MessageBox("�����޸Ķ���");
						return;
					}
					it->money = m_money;
				}
				
				it->money = m_money;
				it->ty = m_way.GetCurSel();
			}
			stra = m_more;
			it->more = stra.GetBuffer();
			it->ty = m_way.GetCurSel();
		}
	}
	f.Write_All();
	f.ls.clear();
	this->MessageBox("�޸ĳɹ���");
	this->OnInitialUpdate();
}

//ɾ��
void C_Del_Cha_Dlg::OnBnClickedDel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData( true );
	CInfoFile f;
	f.Read_All();
	CString str,str2;
	CStringA stra;
	this->GetDlgItem(IDC_TIME)->GetWindowText(str);
	for(list<msg>::iterator it=f.ls.begin(); it!=f.ls.end(); it++)
	{
		CA2T str2(it->tm.c_str());
		if(str == str2)
		{
			if(it->money == m_money)
			{
				stra = m_more;
				if(it->more == stra.GetBuffer())
				{
					if(it->ty == m_way.GetCurSel())
					{
						msg tmp;
						tmp.money = m_money;
						stra = m_more;
						tmp.more = stra.GetBuffer();
						tmp.ty = m_way.GetCurSel();
						tmp.tm = str;
						f.ls.erase(it);
						f.Write_All();
						this->MessageBox("ɾ���ɹ���");
						f.ls.clear();
						this->OnInitialUpdate();
						return;
					}
				}
			}
			this->MessageBox("�����иĶ�������ֱ��ɾ����");
			return;
		}
	}
}

//ѡ��ʱ�����ӦCombo Box�ؼ��ٿ��޸Ļ�ɾ��
void C_Del_Cha_Dlg::OnCbnSelchangeTime()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData( true );
	CString str;
	this->GetDlgItem(IDC_TIME)->GetWindowText(str);
	if(str.IsEmpty())
	{
		this->MessageBox("ѡ��ȱʧ��������ѡ��ʱ�䣡");
		return;
	}
	CInfoFile f;
	f.Read_All();
	for(list<msg>::iterator it=f.ls.begin();it!=f.ls.end(); it++)
	{
		CA2T str2(it->tm.c_str());
		if(str == str2)
		{
			if(one == true)
			{
				one=false;
				this->MessageBox("�ҵ���Ŀ���ֿ����޸Ļ�ɾ����");
			}
			m_way.SetCurSel(it->ty);
			m_money = it->money;
			//CString strc = it->more.c_str();
			//m_more = strc;
			m_more = it->more.c_str();
			this->GetDlgItem(IDC_Change)->EnableWindow( true );
			this->GetDlgItem(IDC_DEL)->EnableWindow( true );
			this->GetDlgItem(IDC_COMBO1)->EnableWindow( true );
			this->GetDlgItem(IDC_EDIT1)->EnableWindow( true );
			this->GetDlgItem(IDC_EDIT2)->EnableWindow( true );
			
			this->UpdateData( false );
			f.ls.clear();
			return;
		}
	}
}