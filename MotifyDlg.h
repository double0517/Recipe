#pragma once


// MotifyDlg �Ի���

class MotifyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MotifyDlg)

public:
	MotifyDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MotifyDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_MODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
	CString m_count;
	CString m_price;
	CString m_danprice;
	// CString strDisName;        //����
	// CString strDisCount;      //����
    // CString strDisPrice;      //�ܼ۸�
	// CString strDisDanPrice;      //����
	virtual BOOL OnInitDialog();
	void OnKillfocusEDITcount();
	static CString MotifyDlg::strDisName;        //����
	static CString MotifyDlg::strDisCount;      //����
	static CString MotifyDlg::strDisPrice;      //�ܼ۸�
	static CString MotifyDlg::strDisDanPrice;      //����
	virtual void OnOK();

};
