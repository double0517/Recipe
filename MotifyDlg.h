#pragma once


// MotifyDlg 对话框

class MotifyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MotifyDlg)

public:
	MotifyDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MotifyDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_MODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
	CString m_count;
	CString m_price;
	CString m_danprice;
	// CString strDisName;        //名字
	// CString strDisCount;      //数量
    // CString strDisPrice;      //总价格
	// CString strDisDanPrice;      //单价
	virtual BOOL OnInitDialog();
	void OnKillfocusEDITcount();
	static CString MotifyDlg::strDisName;        //名字
	static CString MotifyDlg::strDisCount;      //数量
	static CString MotifyDlg::strDisPrice;      //总价格
	static CString MotifyDlg::strDisDanPrice;      //单价
	virtual void OnOK();

};
