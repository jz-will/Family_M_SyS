// AddDlg.cpp : 实现文件
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


// CAddDlg 诊断

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


// CAddDlg 消息处理程序


void CAddDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData( true );
	if(m_money == 0)
	{
		this->MessageBox("金额不能为零，请检查！");
		return;
	}
	else if(m_money < 0)
	{
		this->MessageBox("只记录正数哒，可选择收入还是支出哦！");
		return;
	}
	if(m_more.IsEmpty())
	{
		this->MessageBox("请记录金钱何去何从哦！");
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
	this->MessageBox("添加条目成功！");
}

//默认初始值为收入
void CAddDlg::OnInitialUpdate()
{
	// TODO: 在此添加专用代码和/或调用基类
	CFormView::OnInitialUpdate();
	m_way.SetCurSel(0);
	this->UpdateData( false );
}
