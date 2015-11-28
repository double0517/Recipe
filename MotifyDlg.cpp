// MotifyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Recipe.h"
#include "MotifyDlg.h"
#include "afxdialogex.h"


// MotifyDlg �Ի���
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


// MotifyDlg ��Ϣ�������


BOOL MotifyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_name =  strDisName  ;
	m_count = strDisCount ; 
	m_price = strDisPrice ; 
	m_danprice = strDisDanPrice  ;
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
void MotifyDlg::OnKillfocusEDITcount() 
{
	// TODO: Add your control notification handler code here

}


void MotifyDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
		UpdateData(TRUE);
	int price ;
	price = atoi(m_count)*atoi(m_danprice) ; 
	m_price.Format("%d",price);
	m_price=m_price+"Ԫ";
    strDisCount  =  m_count; 
	strDisPrice = m_price ; 
	UpdateData(FALSE);
    CDialogEx::OnOK();
}

