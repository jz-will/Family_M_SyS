#pragma once
#include "afxwin.h"
#include "afxdtctl.h"



// C_Del_Cha_Dlg ������ͼ
// ʵ��ɾ���Ͳ��ҵĹ���

class C_Del_Cha_Dlg : public CFormView
{
	DECLARE_DYNCREATE(C_Del_Cha_Dlg)

protected:
	C_Del_Cha_Dlg();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~C_Del_Cha_Dlg();

public:
	enum { IDD = IDD_DEL_CHA };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

private:
	CString m_more;
	CComboBox m_way;
public:
	virtual void OnInitialUpdate();
	
	afx_msg void OnBnClickedChange();
private:
	CComboBox m_time;
	int m_money;
public:
	afx_msg void OnBnClickedDel();
	afx_msg void OnCbnSelchangeTime();
//	virtual void PostNcDestroy();

};


