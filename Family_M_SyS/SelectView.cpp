// SelectView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Family_M_SyS.h"
#include "SelectView.h"
#include "UserDlg.h"
#include "MainFrm.h"
// CSelectView

IMPLEMENT_DYNCREATE(CSelectView, CTreeView)

CSelectView::CSelectView()
{

}

CSelectView::~CSelectView()
{
}

BEGIN_MESSAGE_MAP(CSelectView, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CSelectView::OnTvnSelchanged)
END_MESSAGE_MAP()


// CSelectView ���

#ifdef _DEBUG
void CSelectView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectView ��Ϣ�������

//��ʼ��
void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	m_treeCtrl = &GetTreeCtrl();

	m_treeCtrl->InsertItem(TEXT("������Ϣ"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("�ʽ���Ϣ"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("�����Ŀ"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("��ɾ��Ŀ"), 0, 0, NULL);
}


//��ȡ���������ѡ���Ӵ���
void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	//��ȡ��ǰ�ڵ�ѡ����Ŀ CTreeCtrl::GetSelectedItem
	HTREEITEM item = m_treeCtrl->GetSelectedItem();

	//��ȡѡ������ı����� CTreeCtrl::GetItemText
	CString str = m_treeCtrl->GetItemText(item);

	if (str == TEXT("������Ϣ")) 
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
	}
	else if (str == TEXT("�ʽ���Ϣ"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
	}
	else if (str == TEXT("�����Ŀ"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
	}
	else if (str == TEXT("��ɾ��Ŀ"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
	}
	*pResult = 0;
}
