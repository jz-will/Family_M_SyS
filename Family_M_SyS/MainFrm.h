
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once

//�Զ������Ϣӳ��,�����������Ϣ��ͬ
#define NM_A	(WM_USER + 100)
#define NM_B	(WM_USER + 101)
#define NM_C	(WM_USER + 102)
#define NM_D	(WM_USER + 103)

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

private:
	CSplitterWnd m_spliter;

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
public:
	afx_msg LRESULT OnMyChange(WPARAM wParam, LPARAM lParam);	//��ȡ��Ϣӳ��
	afx_msg void On32772_Quit_SYS();
	afx_msg void On32771Re_Login();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
