#pragma once


// CHot 对话框

class CHot : public CDialogEx
{
	DECLARE_DYNAMIC(CHot)

public:
	CHot(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHot();

// 对话框数据
	enum { IDD = IDD_HOT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_name1;
	CString m_price1;
	CString m_name2;
	CString m_price2;
	CString m_name3;
	CString m_price3;
	CString m_name4;
	CString m_price4;
	afx_msg void OnClickedUp1();
	afx_msg void OnClickedDown1();
	afx_msg void OnClickedUp2();
	afx_msg void OnClickedDown2();
	afx_msg void OnClickedUp3();
	afx_msg void OnClickedDown3();
	afx_msg void OnClickedUp4();
	afx_msg void OnClickedDown4();
	int number1;
	int number2;
	int number3;
	int number4;
	int click1;
	int click2;
	int click3;
	int click4;
	void SumMoney();
};
