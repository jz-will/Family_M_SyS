#pragma once
#include "afxwin.h"



// CAddDlg ������ͼ
// ʵ����ӵĹ���

class CAddDlg : public CFormView
{
	DECLARE_DYNCREATE(CAddDlg)

protected:
	CAddDlg();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CAddDlg();

public:
	enum { IDD = IDD_ADD };
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
	unsigned int m_money;
	CString m_more;
	CComboBox m_way;
public:
	afx_msg void OnBnClickedAdd();
	virtual void OnInitialUpdate();
};


