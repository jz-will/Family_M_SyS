
// Family_M_SySView.cpp : CFamily_M_SySView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Family_M_SyS.h"
#endif

#include "Family_M_SySDoc.h"
#include "Family_M_SySView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFamily_M_SySView

IMPLEMENT_DYNCREATE(CFamily_M_SySView, CView)

BEGIN_MESSAGE_MAP(CFamily_M_SySView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CFamily_M_SySView ����/����

CFamily_M_SySView::CFamily_M_SySView()
{
	// TODO: �ڴ˴���ӹ������
}

CFamily_M_SySView::~CFamily_M_SySView()
{
}

BOOL CFamily_M_SySView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CFamily_M_SySView ����

void CFamily_M_SySView::OnDraw(CDC* /*pDC*/)
{
	CFamily_M_SySDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CFamily_M_SySView ��ӡ

BOOL CFamily_M_SySView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CFamily_M_SySView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CFamily_M_SySView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CFamily_M_SySView ���

#ifdef _DEBUG
void CFamily_M_SySView::AssertValid() const
{
	CView::AssertValid();
}

void CFamily_M_SySView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFamily_M_SySDoc* CFamily_M_SySView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFamily_M_SySDoc)));
	return (CFamily_M_SySDoc*)m_pDocument;
}
#endif //_DEBUG


// CFamily_M_SySView ��Ϣ�������
