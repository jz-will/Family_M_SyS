// C_Del_Cha_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Family_M_SyS.h"
#include "C_Del_Cha_Dlg.h"
#include "InfoFile.h"

// C_Del_Cha_Dlg

IMPLEMENT_DYNCREATE(C_Del_Cha_Dlg, CFormView)
 
bool one; //用于处理仅第一次选择时间是弹出提示

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


// C_Del_Cha_Dlg 诊断

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


// C_Del_Cha_Dlg 消息处理程序


void C_Del_Cha_Dlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	// TODO: 在此添加专用代码和/或调用基类
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


//修改
void C_Del_Cha_Dlg::OnBnClickedChange()
{
	// TODO: 在此添加控件通知处理程序代码
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
						this->MessageBox("数据无改动！");
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
	this->MessageBox("修改成功！");
	this->OnInitialUpdate();
}

//删除
void C_Del_Cha_Dlg::OnBnClickedDel()
{
	// TODO: 在此添加控件通知处理程序代码
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
						this->MessageBox("删除成功！");
						f.ls.clear();
						this->OnInitialUpdate();
						return;
					}
				}
			}
			this->MessageBox("数据有改动，不能直接删除！");
			return;
		}
	}
}

//选择时间后响应Combo Box控件再可修改或删除
void C_Del_Cha_Dlg::OnCbnSelchangeTime()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData( true );
	CString str;
	this->GetDlgItem(IDC_TIME)->GetWindowText(str);
	if(str.IsEmpty())
	{
		this->MessageBox("选项缺失，请重新选择时间！");
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
				this->MessageBox("找到条目，现可以修改或删除！");
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