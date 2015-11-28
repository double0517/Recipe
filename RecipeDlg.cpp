
// RecipeDlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CRecipeDlg 对话框




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


// CRecipeDlg 消息处理程序

BOOL CRecipeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	OnConnection();

    m_tab.SetImageList(&m_TabImageList);
	m_tab.InsertItem(0, _T("      热食            "),0);
	m_tab.InsertItem(1, _T("      冷食            "),1);
	GetRecordConnect();
	_variant_t PRICE,NAME;
	PRICE=m_pRecordset->GetCollect("菜名");
	NAME=m_pRecordset->GetCollect("价格");
	m_hot.m_name1=(LPCTSTR)(_bstr_t)(PRICE);
	m_hot.m_price1=(LPCTSTR)(_bstr_t)(NAME);
	m_hot.m_price1=m_hot.m_price1+(_T("元"));
	//m_pRecordset->MoveLast();
	m_pRecordset->MoveNext();
	//m_pRecordset->MoveNext();
	//GetRecordConnect();
	PRICE=m_pRecordset->GetCollect("菜名");
	NAME=m_pRecordset->GetCollect("价格");
	m_hot.m_name2=(LPCTSTR)(_bstr_t)(PRICE);
	m_hot.m_price2=(LPCTSTR)(_bstr_t)(NAME);
	m_hot.m_price2=m_hot.m_price2+(_T("元"));
	m_pRecordset->MoveNext();
	PRICE=m_pRecordset->GetCollect("菜名");
	NAME=m_pRecordset->GetCollect("价格");
	m_hot.m_name3=(LPCTSTR)(_bstr_t)(PRICE);
	m_hot.m_price3=(LPCTSTR)(_bstr_t)(NAME);
	m_hot.m_price3=m_hot.m_price3+(_T("元"));
	m_pRecordset->MoveNext();
	PRICE=m_pRecordset->GetCollect("菜名");
	NAME=m_pRecordset->GetCollect("价格");
	m_hot.m_name4=(LPCTSTR)(_bstr_t)(PRICE);
	m_hot.m_price4=(LPCTSTR)(_bstr_t)(NAME);
	m_hot.m_price4=m_hot.m_price4+(_T("元"));

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//1.初始化tab变量
	m_hot.Create(IDD_HOT,GetDlgItem(IDC_TAB1));
	m_cold.Create(IDD_COLD, GetDlgItem(IDC_TAB1));	
	CRect rs;
	m_tab.GetClientRect(&rs);//获得IDC_TAB客户区大小
	rs.top -= 2;
	rs.bottom -= 42;
	rs.left -=2;
	rs.right+= 0;//调整子对话框在父窗口的位置
	m_hot.MoveWindow(&rs);//设置子对话框尺寸并移动到指定位置
	m_cold.MoveWindow(&rs);
	m_hot.ShowWindow(true);
	m_cold.ShowWindow(false);//分别设置隐藏和显示
	m_tab.SetCurSel(0);//设置默认的选项卡
	//设置list控件
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//4.初始化表头
	m_list.SetTextColor(RGB(255, 0, 0));//设置列表中字体的颜色
	//m_ctrlListConnections.SetBkColor(RGB(127,255, 212));
	m_list.InsertColumn(0,_T("名称"),LVCFMT_LEFT,65,-1);
	m_list.InsertColumn(1,_T("单价"),LVCFMT_LEFT,65,-1);
	m_list.InsertColumn(2, _T("数量"), LVCFMT_LEFT,65, -1);
    m_list.InsertColumn(3, _T("金额"), LVCFMT_LEFT,65, -1);
    DWORD dwStyle = m_list.GetExtendedStyle();
    dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl）
    dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl）
    //dwStyle |= LVS_EX_CHECKBOXES;//item前生成checkbox控件
    m_list.SetExtendedStyle(dwStyle); //设置扩展风格


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRecipeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CRecipeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CRecipeDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
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
			hr=m_pConnection->Open("provider=SQLOLEDB.1;Data Source = USER-20150316US;Initial Catalog = 菜谱;Integrated Security=SSPI;","sa","123456",adModeUnknown );
		if(m_pConnection->State)
			MessageBox(_T("数据库连接成功"));
		else
			MessageBox(_T("数据库连接失败"));
	
	}
	catch(_com_error e)
	{
	CString log;
	log.Format(_T("数据库连接失败原因:%s"),e.ErrorMessage());
	MessageBox(log);
	}
}

void CRecipeDlg::GetRecordConnect()
{

	if(m_pConnection==NULL)
	return;
	m_pConnection->CursorLocation=adUseServer;
	m_pRecordset.CreateInstance("ADODB.Recordset");
	m_pRecordset->Open("SELECT * FROM 热食",_variant_t((IDispatch*)m_pConnection,TRUE),adOpenStatic,adLockOptimistic,adCmdText);
	if(m_pRecordset==NULL)
		return;
	if((m_pRecordset->BOF)||(m_pRecordset->adoEOF))
		return;
	
	UpdateData(FALSE);
}



void CRecipeDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
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
		MessageBox("钱不足","警告", MB_ICONEXCLAMATION ); 
		//SetDlgItemText(IDC_STATIC_Rest,"");
		//m_f.Clear();//清空数据
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
		  SetDlgItemText(IDC_EDIT_GiveMoney,s+"元");
          SetDlgItemText(IDC_EDIT_Rest,m_rest+"元");
          GetDlgItem(IDC_EDIT_Rest)->ShowWindow(SW_SHOW);
	
	}
	//CDialogEx::OnOK();
}


void CRecipeDlg::OnClickedClear()
{
	// TODO: 在此添加控件通知处理程序代码

	if (m_list.GetItemCount() <= 0)
	{
		return;
	}
	
	if (IDYES == AfxMessageBox("是否要放弃该顾客所有菜单？", MB_YESNO | MB_ICONQUESTION))
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
	// TODO: 在此添加控件通知处理程序代码
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

	CTime tm = CTime::GetCurrentTime();                    //定义一个CTime类型的对象。
    CString strTime = "";
	strTime = tm.Format("%H:%M:%S");
	
	CString write_content,strSum ;  /// 写入字符串 
	char *pFileName = "餐饮小票.txt" ;
   	
	strSum += _T("\n***************************")  ; 
	strSum += _T("\n\t欢迎光临") ;
	strSum += _T("\n时间")+strTime+_T("\n很高兴为您服务") ; 
    strSum += _T("\n小计        数量         价格        名称\n");
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
	
	strmoney.Format(_T("\n总计%2d元"),summoney);
    strSum += strmoney ;
    GetDlgItemText(IDC_EDIT_GiveMoney,s);
	strSum+=_T("  收取");
	strSum+=s;
	strSum+=_T("元");
	 GetDlgItemText(IDC_EDIT_Rest,ss);
	 strSum+=_T("   找零");
	strSum+=ss;
	strSum+=_T("元");
	strSum += _T("\n\t欢迎下次光临") ; 
	strSum += _T("\n***************************")  ;

	file.Open( pFileName, CFile::modeCreate
		| CFile::modeWrite | CFile::typeText|CFile::modeNoTruncate )  ;
	// 每次写入到文件尾 保证不覆盖文件
	file.SeekToEnd();
	file.WriteString(strSum);
	file.Close();
	AfxMessageBox("注册成功已载入txt文件中");

	

}

void CRecipeDlg::OpenSQL()
{
   




}


void CRecipeDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
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
	m_pRecordset->Open("SELECT * FROM 菜品",_variant_t((IDispatch*)m_pConnection,TRUE),adOpenStatic,adLockOptimistic,adCmdText);
	   try{
	if(m_pRecordset==NULL)
		return;
	if((m_pRecordset->BOF)||(m_pRecordset->adoEOF))
		return;
	

     m_pRecordset->AddNew(); 
	m_pRecordset->PutCollect("名称", _variant_t(m_list.GetItemText(i , 0))); 
	m_pRecordset->PutCollect("单价", _variant_t(m_list.GetItemText(i , 1)));
	
	m_pRecordset->PutCollect("数量", _variant_t(m_list.GetItemText(i , 2))); 
	m_pRecordset->PutCollect("金额", _variant_t(m_list.GetItemText(i , 3)));
	m_pRecordset->Update();
	m_pRecordset->Close();
	MessageBox(_T("添加成功"));
	}
	catch(_com_error&e)
	{
	CString log;
	log.Format(_T("数据库连接失败原因:%s"),e.ErrorMessage());
	MessageBox(log);
	}
	 
	}
	
}

void CRecipeDlg::OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	int g_nItem;
	

	if(pNMItemActivate != NULL)
	{
		g_nItem = pNMItemActivate->iItem;
		MotifyDlg::strDisName = m_list.GetItemText(g_nItem, 0);//菜名称
		if (MotifyDlg::strDisName == "")
		{
			return;
		}
       MotifyDlg::strDisDanPrice = m_list.GetItemText(g_nItem, 1);//单价
		MotifyDlg::strDisPrice = m_list.GetItemText(g_nItem, 3);//总价
		MotifyDlg::strDisCount = m_list.GetItemText(g_nItem, 2);//数量
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

     m_list.SetItemText(g_nItem, 3,MotifyDlg::strDisPrice ) ;//总价
	m_list.SetItemText(g_nItem, 2,MotifyDlg::strDisCount)  ;//数量
	
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
	
	strmoneyy.Format(_T("\n%3d元"),summoneyy);

		SetDlgItemText(IDC_MONEY,strmoneyy);

	*pResult = 0;
}
