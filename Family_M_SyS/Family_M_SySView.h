
// Family_M_SySView.h : CFamily_M_SySView 类的接口
//

#pragma once


class CFamily_M_SySView : public CView
{
protected: // 仅从序列化创建
	CFamily_M_SySView();
	DECLARE_DYNCREATE(CFamily_M_SySView)

// 特性
public:
	CFamily_M_SySDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CFamily_M_SySView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Family_M_SySView.cpp 中的调试版本
inline CFamily_M_SySDoc* CFamily_M_SySView::GetDocument() const
   { return reinterpret_cast<CFamily_M_SySDoc*>(m_pDocument); }
#endif

