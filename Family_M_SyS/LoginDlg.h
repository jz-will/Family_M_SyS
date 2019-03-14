#pragma once
#include "afxwin.h"


// CLoginDlg �Ի���
//��¼����

class CLoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLoginDlg();

// �Ի�������
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSignin();
private:
	CString m_n_pwd;
	CString m_n_name;
	CButton m_rebr;
public:
	afx_msg void OnBnClickedQuit();
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnOK();
};
