// Hot.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Recipe.h"
#include "Hot.h"
#include "afxdialogex.h"
#include"RecipeDlg.h"


// CHot �Ի���

IMPLEMENT_DYNAMIC(CHot, CDialogEx)

CHot::CHot(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHot::IDD, pParent)
	, m_name1(_T(""))
	, m_price1(_T(""))
	, m_name2(_T(""))
	, m_price2(_T(""))
	, m_name3(_T(""))
	, m_price3(_T(""))
	, m_name4(_T(""))
	, m_price4(_T(""))
	,number1(0)
	,number2(0)
	,number3(0)
	,number4(0)
	,click1(0)
	,click2(0)
	,click3(0)
	,click4(0)
{

}

CHot::~CHot()
{
}

void CHot::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME1, m_name1);
	DDX_Text(pDX, IDC_PRICE1, m_price1);
	DDX_Text(pDX, IDC_NAME2, m_name2);
	DDX_Text(pDX, IDC_PRICE2, m_price2);
	DDX_Text(pDX, IDC_NAME3, m_name3);
	DDX_Text(pDX, IDC_PRICE3, m_price3);
	DDX_Text(pDX, IDC_NAME4, m_name4);
	DDX_Text(pDX, IDC_PRICE4, m_price4);
}


BEGIN_MESSAGE_MAP(CHot, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_UP1, &CHot::OnClickedUp1)
	ON_BN_CLICKED(IDC_BUTTON_DOWN1, &CHot::OnClickedDown1)
	ON_BN_CLICKED(IDC_BUTTON_UP2, &CHot::OnClickedUp2)
	ON_BN_CLICKED(IDC_BUTTON_DOWN2, &CHot::OnClickedDown2)
	ON_BN_CLICKED(IDC_BUTTON_UP3, &CHot::OnClickedUp3)
	ON_BN_CLICKED(IDC_BUTTON_DOWN3, &CHot::OnClickedDown3)
	ON_BN_CLICKED(IDC_BUTTON_UP4, &CHot::OnClickedUp4)
	ON_BN_CLICKED(IDC_BUTTON_DOWN4, &CHot::OnClickedDown4)
END_MESSAGE_MAP()


// CHot ��Ϣ�������


void CHot::OnClickedUp1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CRecipeDlg *pDlg = (CRecipeDlg*)GetParent()->GetParent();
	   number1++;
	   if (number1<=0)
	   {	
		   click1=0;
	   }
	   else
	   {
		   click1=1;
	   }


	   int  j = click2+click3+click4;
		int summoney  = 0; 
		CString strName = m_name1;
		CString strsum ;  /// �ܼ�
		CString strcount= _T("1") ;  ///����
		//char *strText = (LPSTR)(LPCTSTR)(strName);  //��CString ǿ��ת��
		 
		     pDlg->m_list.InsertItem(j, strName);//�����
	         if(strName == pDlg->m_list.GetItemText(j,0))
			 pDlg->m_list.DeleteItem(j+1);
		         summoney=atoi(m_price1)*number1;
                 strsum.Format(_T("%2d"),summoney);
                 strcount.Format(_T("%2d"),number1);
				 pDlg->m_list.SetItemText(j,1,m_price1);
				 pDlg->m_list.SetItemText(j,2,strcount);
				 pDlg->m_list.SetItemText(j,3,strsum+"Ԫ");
				  SumMoney();

 }




void CHot::OnClickedDown1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	number1--;
		  if (number1<=0)
	  {	
		   click1=0;
	  }
	   else
	  {
		   click1=1;
	  }
	CRecipeDlg *pDlg = (CRecipeDlg*)GetParent()->GetParent();
	   int j = click2+click3+click4;
		int summoney  = 0; 
		CString strName = m_name1;
		CString strsum ;  /// �ܼ�
		CString strcount= _T("1") ;  ///����
	    pDlg->m_list.InsertItem(j, strName);//�����
	         if(strName == pDlg->m_list.GetItemText(j,0))
			 pDlg->m_list.DeleteItem(j+1);
		         summoney=atoi(m_price1)*number1;
                 strsum.Format(_T("%2d"),summoney);
                 strcount.Format(_T("%2d"),number1);
				 pDlg->m_list.SetItemText(j,1,m_price1);
				 pDlg->m_list.SetItemText(j,2,strcount);
				 pDlg->m_list.SetItemText(j,3,strsum+"Ԫ");
				 if (number1<=0)
				 {
				  pDlg->m_list.DeleteItem(j);
				  number1=0;
				 }
				  SumMoney();
}


void CHot::OnClickedUp2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	number2++;
		   if (number2<=0)
	   {	
		   click2=0;
	   }
	   else
	   {
		   click2=1;
	   }
	CRecipeDlg *pDlg = (CRecipeDlg*)GetParent()->GetParent();
	   int  j = click1+click3+click4;
		int summoney  = 0; 
		CString strName = m_name2;
		CString strsum ;  /// �ܼ�
		CString strcount= _T("1") ;  ///����
		//char *strText = (LPSTR)(LPCTSTR)(strName);  //��CString ǿ��ת��
		 
		     pDlg->m_list.InsertItem(j, strName);//�����
	         if(strName == pDlg->m_list.GetItemText(j,0))
			 pDlg->m_list.DeleteItem(j+1);
		         summoney=atoi(m_price2)*number2;
                 strsum.Format(_T("%2d"),summoney);
                 strcount.Format(_T("%2d"),number2);
				 pDlg->m_list.SetItemText(j,1,m_price2);
				 pDlg->m_list.SetItemText(j,2,strcount);
				 pDlg->m_list.SetItemText(j,3,strsum+"Ԫ");
				  SumMoney();
}


void CHot::OnClickedDown2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	number2--;
	if (number2<=0)
	   {	
		   click2=0;
	   }
	  else
	  {
		   click2=1;
	  }
	CRecipeDlg *pDlg = (CRecipeDlg*)GetParent()->GetParent();
	   int j = click1+click3+click4;
		int summoney  = 0; 
		CString strName = m_name2;
		CString strsum ;  /// �ܼ�
		CString strcount= _T("1") ;  ///����
	    pDlg->m_list.InsertItem(j, strName);//�����
	         if(strName == pDlg->m_list.GetItemText(j,0))
			 pDlg->m_list.DeleteItem(j+1);
		         summoney=atoi(m_price1)*number2;
                 strsum.Format(_T("%2d"),summoney);
                 strcount.Format(_T("%2d"),number2);
				 pDlg->m_list.SetItemText(j,1,m_price2);
				 pDlg->m_list.SetItemText(j,2,strcount);
				 pDlg->m_list.SetItemText(j,3,strsum+"Ԫ");
				 if (number2<=0)
				 {
				  pDlg->m_list.DeleteItem(j);
				  number2=0;
				 }
				  SumMoney();

}


void CHot::OnClickedUp3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	number3++;
	
		   if (number3<=0)
	   {	
		   click3=0;
	   }
	   else
	   {
		   click3=1;
	   }
	CRecipeDlg *pDlg = (CRecipeDlg*)GetParent()->GetParent();
	   int  j =click1+click2+click4;
		int summoney  = 0; 
		CString strName = m_name3;
		CString strsum ;  /// �ܼ�
		CString strcount= _T("1") ;  ///����
		//char *strText = (LPSTR)(LPCTSTR)(strName);  //��CString ǿ��ת��
		 
		     pDlg->m_list.InsertItem(j, strName);//�����
	         if(strName == pDlg->m_list.GetItemText(j,0))
			 pDlg->m_list.DeleteItem(j+1);
		         summoney=atoi(m_price3)*number3;
                 strsum.Format(_T("%2d"),summoney);
                 strcount.Format(_T("%2d"),number3);
				 pDlg->m_list.SetItemText(j,1,m_price3);
				 pDlg->m_list.SetItemText(j,2,strcount);
				 pDlg->m_list.SetItemText(j,3,strsum+"Ԫ");
				  SumMoney();
}


void CHot::OnClickedDown3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	number3--;
	if (number3<=0)
	   {	
		   click3=0;
	   }
	   else
	   {
		   click3=1;
	   }
	CRecipeDlg *pDlg = (CRecipeDlg*)GetParent()->GetParent();
	   int j = click1+click2+click4;
		int summoney  = 0; 
		CString strName = m_name3;
		CString strPrice1 =m_price3;
		CString strsum ;  /// �ܼ�
		CString strcount= _T("1") ;  ///����
	    pDlg->m_list.InsertItem(j, strName);//�����
	         if(strName == pDlg->m_list.GetItemText(j,0))
			 pDlg->m_list.DeleteItem(j+1);
		         summoney=atoi(m_price1)*number3;
                 strsum.Format(_T("%2d"),summoney);
                 strcount.Format(_T("%2d"),number3);
				 pDlg->m_list.SetItemText(j,1,m_price3);
				 pDlg->m_list.SetItemText(j,2,strcount);
				 pDlg->m_list.SetItemText(j,3,strsum+"Ԫ");
				 if (number3<=0)
				 {
				  pDlg->m_list.DeleteItem(j);
				  number3=0;
				 }

				  SumMoney();
}


void CHot::OnClickedUp4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	number4++;
	
		   if (number4<=0)
	   {	
		   click4=0;
	   }
	   else
	   {
		   click4=1;
	   }
	CRecipeDlg *pDlg = (CRecipeDlg*)GetParent()->GetParent();
	   int  j = click1+click2+click3;
		int summoney  = 0; 
		CString strName = m_name4;
		CString strsum ;  /// �ܼ�
		CString strcount= _T("1") ;  ///����
		//char *strText = (LPSTR)(LPCTSTR)(strName);  //��CString ǿ��ת��
		 
		     pDlg->m_list.InsertItem(j, strName);//�����
	         if(strName == pDlg->m_list.GetItemText(j,0))
			 pDlg->m_list.DeleteItem(j+1);
		         summoney=atoi(m_price4)*number4;
                 strsum.Format(_T("%2d"),summoney);
                 strcount.Format(_T("%2d"),number4);
				 pDlg->m_list.SetItemText(j,1,m_price4);
				 pDlg->m_list.SetItemText(j,2,strcount);
				 pDlg->m_list.SetItemText(j,3,strsum+"Ԫ");

				 
				 
			 SumMoney();

				 
				 

}


void CHot::OnClickedDown4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	number4--;
	if (number4<=0)
	   {	
		   click4=0;
	   }
	   else
	   {
		   click4=1;
	   }
	CRecipeDlg *pDlg = (CRecipeDlg*)GetParent()->GetParent();
	   int j = click1+click2+click3;
		int summoney  = 0; 
		CString strName = m_name4;
		CString strsum ;  /// �ܼ�
		CString strcount= _T("1") ;  ///����
	    pDlg->m_list.InsertItem(j, strName);//�����
	         if(strName == pDlg->m_list.GetItemText(j,0))
			 pDlg->m_list.DeleteItem(j+1);
		         summoney=atoi(m_price4)*number4;
                 strsum.Format(_T("%2d"),summoney);
                 strcount.Format(_T("%2d"),number4);
				 pDlg->m_list.SetItemText(j,1,m_price4);
				 pDlg->m_list.SetItemText(j,2,strcount);
				 pDlg->m_list.SetItemText(j,3,strsum+"Ԫ");
				 if (number4<=0)
				 {
				  pDlg->m_list.DeleteItem(j);
				  number4=0;
				 }
				 SumMoney();
}

void CHot::SumMoney()
{
     	CRecipeDlg *pDlg = (CRecipeDlg*)GetParent()->GetParent();
		int sumlenn =  pDlg->m_list.GetItemCount(),i=0,jj=1;
				CString strSumm;
				CString strmoneyy ; 
                int summoneyy = 0;
				while(sumlenn--)
	                {
                   for(jj = 3 ; jj >=0 ; jj--)
	                {
		     strSumm +=  pDlg->m_list.GetItemText(i,jj) +_T("         ");
	              }
	               summoneyy += atoi( pDlg->m_list.GetItemText(i , 3));
	                 strSumm += _T("\n");
	                 i++;
                   	}
	
	        strmoneyy.Format(_T("\n%3dԪ"),summoneyy);

	     	pDlg->SetDlgItemText(IDC_MONEY,strmoneyy);

}
