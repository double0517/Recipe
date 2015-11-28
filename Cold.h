#pragma once


// CCold 对话框

class CCold : public CDialogEx
{
	DECLARE_DYNAMIC(CCold)

public:
	CCold(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCold();

// 对话框数据
	enum { IDD = IDD_COLD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
