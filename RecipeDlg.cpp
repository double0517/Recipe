
// RecipeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Recipe.h"
#include "RecipeDlg.h"
#include "afxdialogex.h"
#include "Cold.h"
#include"Hot.h"
#include"MotifyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRecipeDlg �Ի���




CRecipeDlg::CRecipeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRecipeDlg::IDD, pParent)
	, m_rest(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRecipeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Text(pDX, IDC_EDIT_Rest, m_rest);
}

BEGIN_MESSAGE_MAP(CRecipeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CLEAR, &CRecipeDlg::OnClickedClear)
	ON_BN_CLICKED(IDC_ORDER, &CRecipeDlg::OnClickedOrder)
	ON_BN_CLICKED(IDC_BUTTON1, &CRecipeDlg::OnBnClickedButton1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, &CRecipeDlg::OnNMDblclkList)
END_MESSAGE_MAP()


// CRecipeDlg ��Ϣ�������

BOOL CRecipeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	OnConnection();

    m_tab.SetImageList(&m_TabImageList);
	m_tab.InsertItem(0, _T("      ��ʳ            "),0);
	m_tab.InsertItem(1, _T("      ��ʳ            "),1);
	GetRecordConnect();
	_variant_t PRICE,NAME;
	PRICE=m_pRecordset->GetCollect("����");
	NAME=m_pRecordset->GetCollect("�۸�");
	m_hot.m_name1=(LPCTSTR)(_bstr_t)(PRICE);
	m_hot.m_price1=(LPCTSTR)(_bstr_t)(NAME);
	m_hot.m_price1=m_hot.m_price1+(_T("Ԫ"));
	//m_pRecordset->MoveLast();
	m_pRecordset->MoveNext();
	//m_pRecordset->MoveNext();
	//GetRecordConnect();
	PRICE=m_pRecordset->GetCollect("����");
	NAME=m_pRecordset->GetCollect("�۸�");
	m_hot.m_name2=(LPCTSTR)(_bstr_t)(PRICE);
	m_hot.m_price2=(LPCTSTR)(_bstr_t)(NAME);
	m_hot.m_price2=m_hot.m_price2+(_T("Ԫ"));
	m_pRecordset->MoveNext();
	PRICE=m_pRecordset->GetCollect("����");
	NAME=m_pRecordset->GetCollect("�۸�");
	m_hot.m_name3=(LPCTSTR)(_bstr_t)(PRICE);
	m_hot.m_price3=(LPCTSTR)(_bstr_t)(NAME);
	m_hot.m_price3=m_hot.m_price3+(_T("Ԫ"));
	m_pRecordset->MoveNext();
	PRICE=m_pRecordset->GetCollect("����");
	NAME=m_pRecordset->GetCollect("�۸�");
	m_hot.m_name4=(LPCTSTR)(_bstr_t)(PRICE);
	m_hot.m_price4=(LPCTSTR)(_bstr_t)(NAME);
	m_hot.m_price4=m_hot.m_price4+(_T("Ԫ"));

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//1.��ʼ��tab����
	m_hot.Create(IDD_HOT,GetDlgItem(IDC_TAB1));
	m_cold.Create(IDD_COLD, GetDlgItem(IDC_TAB1));	
	CRect rs;
	m_tab.GetClientRect(&rs);//���IDC_TAB�ͻ�����С
	rs.top -= 2;
	rs.bottom -= 42;
	rs.left -=2;
	rs.right+= 0;//�����ӶԻ����ڸ����ڵ�λ��
	m_hot.MoveWindow(&rs);//�����ӶԻ���ߴ粢�ƶ���ָ��λ��
	m_cold.MoveWindow(&rs);
	m_hot.ShowWindow(true);
	m_cold.ShowWindow(false);//�ֱ��������غ���ʾ
	m_tab.SetCurSel(0);//����Ĭ�ϵ�ѡ�
	//����list�ؼ�
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//4.��ʼ����ͷ
	m_list.SetTextColor(RGB(255, 0, 0));//�����б����������ɫ
	//m_ctrlListConnections.SetBkColor(RGB(127,255, 212));
	m_list.InsertColumn(0,_T("����"),LVCFMT_LEFT,65,-1);
	m_list.InsertColumn(1,_T("����"),LVCFMT_LEFT,65,-1);
	m_list.InsertColumn(2, _T("����"), LVCFMT_LEFT,65, -1);
    m_list.InsertColumn(3, _T("���"), LVCFMT_LEFT,65, -1);
    DWORD dwStyle = m_list.GetExtendedStyle();
    dwStyle |= LVS_EX_FULLROWSELECT;//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
    dwStyle |= LVS_EX_GRIDLINES;//�����ߣ�ֻ������report����listctrl��
    //dwStyle |= LVS_EX_CHECKBOXES;//itemǰ����checkbox�ؼ�
    m_list.SetExtendedStyle(dwStyle); //������չ���


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CRecipeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRecipeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CRecipeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CRecipeDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	switch(m_tab.GetCurSel())
	{
	    case 0: 
		m_hot.ShowWindow(SW_SHOW);
		m_cold.ShowWindow(SW_HIDE);
		break;
		case 1: 
		m_hot.ShowWindow(SW_HIDE);
		m_cold.ShowWindow(SW_SHOW);
		break;
		default:
		break;

	}
	*pResult = 0;
}

void CRecipeDlg::OnConnection()
{

	::CoInitialize(NULL); 
	HRESULT hr;
	try{
		hr=m_pConnection.CreateInstance("ADODB.Connection");
		if(SUCCEEDED(hr))
			hr=m_pConnection->Open("provider=SQLOLEDB.1;Data Source = USER-20150316US;Initial Catalog = ����;Integrated Security=SSPI;","sa","123456",adModeUnknown );
		if(m_pConnection->State)
			MessageBox(_T("���ݿ����ӳɹ�"));
		else
			MessageBox(_T("���ݿ�����ʧ��"));
	
	}
	catch(_com_error e)
	{
	CString log;
	log.Format(_T("���ݿ�����ʧ��ԭ��:%s"),e.ErrorMessage());
	MessageBox(log);
	}
}

void CRecipeDlg::GetRecordConnect()
{

	if(m_pConnection==NULL)
	return;
	m_pConnection->CursorLocation=adUseServer;
	m_pRecordset.CreateInstance("ADODB.Recordset");
	m_pRecordset->Open("SELECT * FROM ��ʳ",_variant_t((IDispatch*)m_pConnection,TRUE),adOpenStatic,adLockOptimistic,adCmdText);
	if(m_pRecordset==NULL)
		return;
	if((m_pRecordset->BOF)||(m_pRecordset->adoEOF))
		return;
	
	UpdateData(FALSE);
}



void CRecipeDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	CString s,zongjia;
	double m_number1=0.0f;
	double m_number2=0.0f;
	double m_number3=0.0f;


	GetDlgItemText(IDC_EDIT_GiveMoney,s);
	GetDlgItemText(IDC_MONEY,zongjia);
	m_number1=atof(s);
	m_number2=atof(zongjia);
	m_number3=m_number1-m_number2;
	if (m_number3<0)
	{
		MessageBox("Ǯ����","����", MB_ICONEXCLAMATION ); 
		//SetDlgItemText(IDC_STATIC_Rest,"");
		//m_f.Clear();//�������
		GetDlgItem(IDC_EDIT_Rest)->SetWindowText(_T(""));
		UpdateData(TRUE);
	}
	else
	{
		if(m_number3-int(m_number3<=1e-5))
		{
		m_rest.Format("%d",(int)(m_number3));
		}
		else
		{
			m_rest.Format("%f",m_number3);
		}

		 GetDlgItem(IDC_EDIT_Rest)->ShowWindow(SW_HIDE);
		  SetDlgItemText(IDC_EDIT_GiveMoney,s+"Ԫ");
          SetDlgItemText(IDC_EDIT_Rest,m_rest+"Ԫ");
          GetDlgItem(IDC_EDIT_Rest)->ShowWindow(SW_SHOW);
	
	}
	//CDialogEx::OnOK();
}


void CRecipeDlg::OnClickedClear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	if (m_list.GetItemCount() <= 0)
	{
		return;
	}
	
	if (IDYES == AfxMessageBox("�Ƿ�Ҫ�����ù˿����в˵���", MB_YESNO | MB_ICONQUESTION))
	{
		m_list.DeleteAllItems();
		SetDlgItemText(IDC_MONEY,"");

		SetDlgItemText(IDC_EDIT_GiveMoney,"");
		GetDlgItem(IDC_EDIT_Rest)->SetWindowText(_T(""));
		UpdateData(TRUE);
	}
}


void CRecipeDlg::OnClickedOrder()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OpenSQL();
	UpdateData(TRUE);
	CStdioFile file ;
	CString strmoney ; 
	CString givemoneyy,s,ss;
	CString moneyrestt;
	int sumlen = m_list.GetItemCount() , i = 0 , j ;
    int summoney = 0;
	int givemoney=0;
	int moneyrest=0;

	CTime tm = CTime::GetCurrentTime();                    //����һ��CTime���͵Ķ���
    CString strTime = "";
	strTime = tm.Format("%H:%M:%S");
	
	CString write_content,strSum ;  /// д���ַ��� 
	char *pFileName = "����СƱ.txt" ;
   	
	strSum += _T("\n***************************")  ; 
	strSum += _T("\n\t��ӭ����") ;
	strSum += _T("\nʱ��")+strTime+_T("\n�ܸ���Ϊ������") ; 
    strSum += _T("\nС��        ����         �۸�        ����\n");
    while(sumlen--)
	{
       for(j = 3 ; j >=0 ; j--)
	   {
		   strSum += m_list.GetItemText(i,j) +_T("         ");
	   }
	   summoney += atoi(m_list.GetItemText(i , 3));
	   strSum += _T("\n");
	   i++;
	}
	
	strmoney.Format(_T("\n�ܼ�%2dԪ"),summoney);
    strSum += strmoney ;
    GetDlgItemText(IDC_EDIT_GiveMoney,s);
	strSum+=_T("  ��ȡ");
	strSum+=s;
	strSum+=_T("Ԫ");
	 GetDlgItemText(IDC_EDIT_Rest,ss);
	 strSum+=_T("   ����");
	strSum+=ss;
	strSum+=_T("Ԫ");
	strSum += _T("\n\t��ӭ�´ι���") ; 
	strSum += _T("\n***************************")  ;

	file.Open( pFileName, CFile::modeCreate
		| CFile::modeWrite | CFile::typeText|CFile::modeNoTruncate )  ;
	// ÿ��д�뵽�ļ�β ��֤�������ļ�
	file.SeekToEnd();
	file.WriteString(strSum);
	file.Close();
	AfxMessageBox("ע��ɹ�������txt�ļ���");

	

}

void CRecipeDlg::OpenSQL()
{
   




}


void CRecipeDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//if(m_pConnection==NULL)
	//return;
		int sumlen = m_list.GetItemCount() , i  , j ;
    int summoney = 0;
	int givemoney=0;
	int moneyrest=0;
	CString strSum;
	 for (i=0;i<sumlen;i++)
	{
	m_pConnection->CursorLocation=adUseServer;
	//m_pRecordset.CreateInstance("ADODB.Recordset");
	m_pRecordset.CreateInstance(__uuidof( Recordset ));
	m_pRecordset->Open("SELECT * FROM ��Ʒ",_variant_t((IDispatch*)m_pConnection,TRUE),adOpenStatic,adLockOptimistic,adCmdText);
	   try{
	if(m_pRecordset==NULL)
		return;
	if((m_pRecordset->BOF)||(m_pRecordset->adoEOF))
		return;
	

     m_pRecordset->AddNew(); 
	m_pRecordset->PutCollect("����", _variant_t(m_list.GetItemText(i , 0))); 
	m_pRecordset->PutCollect("����", _variant_t(m_list.GetItemText(i , 1)));
	
	m_pRecordset->PutCollect("����", _variant_t(m_list.GetItemText(i , 2))); 
	m_pRecordset->PutCollect("���", _variant_t(m_list.GetItemText(i , 3)));
	m_pRecordset->Update();
	m_pRecordset->Close();
	MessageBox(_T("��ӳɹ�"));
	}
	catch(_com_error&e)
	{
	CString log;
	log.Format(_T("���ݿ�����ʧ��ԭ��:%s"),e.ErrorMessage());
	MessageBox(log);
	}
	 
	}
	
}

void CRecipeDlg::OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int g_nItem;
	

	if(pNMItemActivate != NULL)
	{
		g_nItem = pNMItemActivate->iItem;
		MotifyDlg::strDisName = m_list.GetItemText(g_nItem, 0);//������
		if (MotifyDlg::strDisName == "")
		{
			return;
		}
       MotifyDlg::strDisDanPrice = m_list.GetItemText(g_nItem, 1);//����
		MotifyDlg::strDisPrice = m_list.GetItemText(g_nItem, 3);//�ܼ�
		MotifyDlg::strDisCount = m_list.GetItemText(g_nItem, 2);//����
	}
	else
	{
		return;
	}
	MotifyDlg Dlg ; 
	 Dlg.DoModal();
	 if(MotifyDlg::strDisCount == "0")
	 {
		 m_list.DeleteItem(g_nItem);
	     *pResult = 0;
		 return ;
	 }

     m_list.SetItemText(g_nItem, 3,MotifyDlg::strDisPrice ) ;//�ܼ�
	m_list.SetItemText(g_nItem, 2,MotifyDlg::strDisCount)  ;//����
	
	 	int sumlenn = m_list.GetItemCount(),i=0,j=1;
				CString strSumm;
				CString strmoneyy ; 
                int summoneyy = 0;
				while(sumlenn--)
	       {
             for(j = 3 ; j >=0 ; j--)
	       {
		   strSumm += m_list.GetItemText(i,j) +_T("         ");
	   }
	   summoneyy += atoi(m_list.GetItemText(i , 3));
	   strSumm += _T("\n");
	   i++;
	}
	
	strmoneyy.Format(_T("\n%3dԪ"),summoneyy);

		SetDlgItemText(IDC_MONEY,strmoneyy);

	*pResult = 0;
}
