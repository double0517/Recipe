
// RecipeDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "cold.h"
#include "hot.h"


// CRecipeDlg 对话框
class CRecipeDlg : public CDialogEx
{
// 构造
public:
	CRecipeDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_RECIPE_DIALOG };
	
	_ConnectionPtr m_pConnection; // 数据库
    _RecordsetPtr m_pRecordset; // 命令
    _CommandPtr m_pCommand; // 记录

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	CTabCtrl m_tab;
	CCold m_cold;
	CHot m_hot;

	CImageList m_TabImageList;
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
	void OnConnection();
	void GetRecordConnect();
//	CString m_last;
//	CString m_sum;
//	CStatic m_summ;
	int m_sum;
	int column;
	int summoneyy;
	CString strmoney;
	virtual void OnOK();
	CString m_rest;
	afx_msg void OnClickedClear();
	afx_msg void OnClickedOrder();

	void OpenSQL();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult);
	//MotifyDlg m_modify;
};
