// Cold.cpp : 实现文件
//

#include "stdafx.h"
#include "Recipe.h"
#include "Cold.h"
#include "afxdialogex.h"


// CCold 对话框

IMPLEMENT_DYNAMIC(CCold, CDialogEx)

CCold::CCold(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCold::IDD, pParent)
{

}

CCold::~CCold()
{
}

void CCold::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCold, CDialogEx)
END_MESSAGE_MAP()


// CCold 消息处理程序
