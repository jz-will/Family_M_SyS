
// MainFrm.h : CMainFrame 类的接口
//

#pragma once

//自定义的消息映射,避免和其他消息相同
#define NM_A	(WM_USER + 100)
#define NM_B	(WM_USER + 101)
#define NM_C	(WM_USER + 102)
#define NM_D	(WM_USER + 103)

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

private:
	CSplitterWnd m_spliter;

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
public:
	afx_msg LRESULT OnMyChange(WPARAM wParam, LPARAM lParam);	//获取消息映射
	afx_msg void On32772_Quit_SYS();
	afx_msg void On32771Re_Login();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
