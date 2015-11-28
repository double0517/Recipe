// MotifyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Recipe.h"
#include "MotifyDlg.h"
#include "afxdialogex.h"


// MotifyDlg 对话框
CString MotifyDlg::strDisName = "";
CString MotifyDlg::strDisCount = "";
CString MotifyDlg::strDisPrice = "";
CString MotifyDlg::strDisDanPrice = "";


IMPLEMENT_DYNAMIC(MotifyDlg, CDialogEx)

MotifyDlg::MotifyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MotifyDlg::IDD, pParent)
	, m_name(_T(""))
	, m_count(_T(""))
	, m_price(_T(""))
	, m_danprice(_T(""))
//	, strDisName(_T(""))
	//, strDisCount(_T(""))
	///,strDisPrice (_T(""))
	//,strDisDanPrice (_T(""))
{


}

MotifyDlg::~MotifyDlg()
{
}

void MotifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_name, m_name);
	DDX_Text(pDX, IDC_EDIT_count, m_count);
	DDX_Text(pDX, IDC_STATIC_price, m_price);
	DDX_Text(pDX, IDC_Danprice, m_danprice);
}


BEGIN_MESSAGE_MAP(MotifyDlg, CDialogEx)
	ON_WM_KILLFOCUS()
END_MESSAGE_MAP()


// MotifyDlg 消息处理程序


BOOL MotifyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_name =  strDisName  ;
	m_count = strDisCount ; 
	m_price = strDisPrice ; 
	m_danprice = strDisDanPrice  ;
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
void MotifyDlg::OnKillfocusEDITcount() 
{
	// TODO: Add your control notification handler code here

}


void MotifyDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
		UpdateData(TRUE);
	int price ;
	price = atoi(m_count)*atoi(m_danprice) ; 
	m_price.Format("%d",price);
	m_price=m_price+"元";
    strDisCount  =  m_count; 
	strDisPrice = m_price ; 
	UpdateData(FALSE);
    CDialogEx::OnOK();
}

