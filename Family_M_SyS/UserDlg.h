#pragma once



// CUserDlg ������ͼ
//������Ϣ��

class CUserDlg : public CFormView
{
	DECLARE_DYNCREATE(CUserDlg)

protected:
	CUserDlg();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CUserDlg();

public:
	enum { IDD = IDD_USR };
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
	virtual void OnInitialUpdate();

private:
	//У��
	CString m_name;
	CString m_pwd;
	CString m_pwd2;
	CString m_fname;

public:
	afx_msg void OnBnClickedname();
	afx_msg void OnBnClickedpwd();
};


