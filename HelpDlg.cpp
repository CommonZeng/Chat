// HelpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "chat.h"
#include "HelpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHelpDlg dialog


CHelpDlg::CHelpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHelpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHelpDlg)
	m_Info = _T("������ϸ�Ķ�������֪\r\n1.���������¼������ֻ�ܱ�֤����ָ��IPͨѶ�������ܱ�֤����ȷ����ĳ��ͨѶ������ȷ������ͨѶ�Ķ������ݣ���ֹ��թ��ƭ�ַ�������ʹ�ñ������������κκ�������˲����κ�����\r\n2.��������Դ��Ͱ�����ִ�г���(*.exe)���ڵ��κ��ļ������ڽ��պ��Ѵ��������ļ�ǰ��𣬲��ڽ�����ɺ���б�Ҫ�Ĳ鶾����ʹ�ñ������������κκ�������˲����κ�����\r\n3.�����򲻻��޸����������ļ������޸�ע�������������ľ�����ŵȣ������ʹ��\r\n4.��������Zeng FanΪPeng Jing���������������ʹ�ò������������������������ҵ��;��Ĳ����Zeng Fan�����Ա���������а�Ȩ�ͽ�һ���޸ĵ�Ȩ��\r\n5.������ͨ���޸�\"IP.txt\"�ļ����������޸��Լ����ǳƺͺ����б����ļ�λ�ڱ��������ڵ�Ŀ¼�£���һ��Ϊ�����ǳƣ��ӵڶ�����������Ϊһ��λ��¼һ�����ѵ��ǳƺ�IP��ַ�������ж���Ŀ��С�����������в������������Գ����޸�\"IP.txt\"�ļ����������г���\r\n6.�����������\"�ر�\"��ť��ʹ������С�������̣��رճ���ķ����ǵ��\"�ر�\"��ť�·���\"X\"��ť��������ͼ���ϵ��Ҽ��ر�\r\n7.��ȷ����������Internet����Ȩ�ޣ���������޷���������\r\n5.����ʹ�ù����з���bug�����κ����ʣ���ӭ���ʼ���wishinghappiness@sina.com");
	//}}AFX_DATA_INIT
}


void CHelpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHelpDlg)
	DDX_Text(pDX, IDC_EDITInfo, m_Info);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHelpDlg, CDialog)
	//{{AFX_MSG_MAP(CHelpDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHelpDlg message handlers
