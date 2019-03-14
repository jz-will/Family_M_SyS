
// Family_M_SySView.cpp : CFamily_M_SySView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CFamily_M_SySView 构造/析构

CFamily_M_SySView::CFamily_M_SySView()
{
	// TODO: 在此处添加构造代码
}

CFamily_M_SySView::~CFamily_M_SySView()
{
}

BOOL CFamily_M_SySView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CFamily_M_SySView 绘制

void CFamily_M_SySView::OnDraw(CDC* /*pDC*/)
{
	CFamily_M_SySDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CFamily_M_SySView 打印

BOOL CFamily_M_SySView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CFamily_M_SySView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CFamily_M_SySView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CFamily_M_SySView 诊断

#ifdef _DEBUG
void CFamily_M_SySView::AssertValid() const
{
	CView::AssertValid();
}

void CFamily_M_SySView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFamily_M_SySDoc* CFamily_M_SySView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFamily_M_SySDoc)));
	return (CFamily_M_SySDoc*)m_pDocument;
}
#endif //_DEBUG


// CFamily_M_SySView 消息处理程序
