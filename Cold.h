#pragma once


// CCold �Ի���

class CCold : public CDialogEx
{
	DECLARE_DYNAMIC(CCold)

public:
	CCold(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCold();

// �Ի�������
	enum { IDD = IDD_COLD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
