#pragma once
#include "afxcmn.h"



// CAllDataDlg ������ͼ
// ʵ��չ�ֵĹ���

class CAllDataDlg : public CFormView
{
	DECLARE_DYNCREATE(CAllDataDlg)

protected:
	CAllDataDlg();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CAllDataDlg();

public:
	enum { IDD = IDD_ALLINFO };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual void OnInitialUpdate();
};


