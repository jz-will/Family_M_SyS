
// Family_M_SySView.h : CFamily_M_SySView ��Ľӿ�
//

#pragma once


class CFamily_M_SySView : public CView
{
protected: // �������л�����
	CFamily_M_SySView();
	DECLARE_DYNCREATE(CFamily_M_SySView)

// ����
public:
	CFamily_M_SySDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CFamily_M_SySView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Family_M_SySView.cpp �еĵ��԰汾
inline CFamily_M_SySDoc* CFamily_M_SySView::GetDocument() const
   { return reinterpret_cast<CFamily_M_SySDoc*>(m_pDocument); }
#endif

