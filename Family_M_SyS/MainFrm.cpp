
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "Family_M_SyS.h"

#include "MainFrm.h"
#include "LoginDlg.h"
#include "SelectView.h"
#include "UserDlg.h"
#include "AllDataDlg.h"
#include "AddDlg.h"
#include "C_Del_Cha_Dlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	
	//����NM_X��Ϣ���Զ�����OnMyChange����
	ON_MESSAGE(NM_A, OnMyChange)
	ON_MESSAGE(NM_B, OnMyChange)
	ON_MESSAGE(NM_C, OnMyChange)
	ON_MESSAGE(NM_D, OnMyChange)

	//�˵����˳���¼���˳�ϵͳ
	ON_COMMAND(ID_32772, &CMainFrame::On32772_Quit_SYS)
	ON_WM_CLOSE()
	ON_COMMAND(ID_32771, &CMainFrame::On32771Re_Login)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	return true;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������

//�ָ��
BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���

	//return CFrameWnd::OnCreateClient(lpcs, pContext);
	
	m_spliter.CreateStatic(this,1,2);
	m_spliter.CreateView(0,0,RUNTIME_CLASS(CSelectView),CSize(100,500),pContext);
	m_spliter.CreateView(0,1,RUNTIME_CLASS(CUserDlg),CSize(250,500),pContext);

	return true;
}

//�ر���һ�����沢�����¶�̬����
LRESULT CMainFrame::OnMyChange(WPARAM wParam, LPARAM lParam)
{
	CCreateContext Context;
	switch (wParam)
	{
		case NM_A:
			{
				Context.m_pNewViewClass = RUNTIME_CLASS(CUserDlg); 
				Context.m_pCurrentFrame = this;
				Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1);
				m_spliter.DeleteView(0, 1);
				m_spliter.CreateView(0, 1, RUNTIME_CLASS(CUserDlg), CSize(600,0), &Context);
				CUserDlg *pNewView = (CUserDlg *)m_spliter.GetPane(0, 1);
				m_spliter.RecalcLayout();
				pNewView->OnInitialUpdate();
				m_spliter.SetActivePane(0, 1);
				break;
			}
		case NM_B:
			{
				Context.m_pNewViewClass = RUNTIME_CLASS(CAllDataDlg);
				Context.m_pCurrentFrame = this;
				Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1);
				m_spliter.DeleteView(0, 1);
				m_spliter.CreateView(0, 1, RUNTIME_CLASS(CAllDataDlg), CSize(600, 0), &Context);
				CAllDataDlg *pNewView = (CAllDataDlg *)m_spliter.GetPane(0, 1);
				m_spliter.RecalcLayout();
				pNewView->OnInitialUpdate();
				m_spliter.SetActivePane(0, 1);
				break;
			}
			case NM_C:
			{
				Context.m_pNewViewClass = RUNTIME_CLASS(CAddDlg);
				Context.m_pCurrentFrame = this;
				Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1);
				m_spliter.DeleteView(0, 1);
				m_spliter.CreateView(0, 1, RUNTIME_CLASS(CAddDlg), CSize(600, 0), &Context);
				CAddDlg *pNewView = (CAddDlg *)m_spliter.GetPane(0, 1);
				m_spliter.RecalcLayout();
				pNewView->OnInitialUpdate();
				m_spliter.SetActivePane(0, 1);
				break;
			}
			case NM_D:
			{
				Context.m_pNewViewClass = RUNTIME_CLASS(C_Del_Cha_Dlg);
				Context.m_pCurrentFrame = this;
				Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1);
				m_spliter.DeleteView(0, 1);
				m_spliter.CreateView(0, 1, RUNTIME_CLASS(C_Del_Cha_Dlg), CSize(600,0), &Context);
				C_Del_Cha_Dlg *pNewView = (C_Del_Cha_Dlg *)m_spliter.GetPane(0, 1);
				m_spliter.RecalcLayout();
				pNewView->OnInitialUpdate();
				m_spliter.SetActivePane(0, 1);
				break;
			}
	}
	return 0;
}

//�˳�ϵͳ
void CMainFrame::On32772_Quit_SYS()
{
	// TODO: �ڴ���������������
	exit(0);
}

//�˳���¼
void CMainFrame::On32771Re_Login()
{
	// TODO: �ڴ���������������
	this->ShowWindow(SW_HIDE);
	CLoginDlg dlg;
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
}

//����������
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	HICON m_icon;
	m_icon = AfxGetApp()->LoadIconA(IDI_HEAD);
	SetIcon(m_icon,true);
	this->MoveWindow(0,0,800,600);
	this->CenterWindow();
	CTime tm;
	tm=CTime::GetCurrentTime();
	CString str;
	str=tm.Format("%Y-%m-%d");
	this->SetTitle(str);
	return 0;
}
