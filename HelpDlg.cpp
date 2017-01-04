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
	m_Info = _T("请您仔细阅读以下须知\r\n1.本程序不设登录口令，因此只能保证您与指定IP通讯，而不能保证您与确定的某人通讯，请您确认与您通讯的对象的身份，防止欺诈等骗局发生；由使用本程序而引起的任何后果，本人不负任何责任\r\n2.本程序可以传送包括可执行程序(*.exe)在内的任何文件，请在接收好友传给您的文件前甄别，并在接收完成后进行必要的查毒；由使用本程序而引起的任何后果，本人不负任何责任\r\n3.本程序不会修改您电脑里文件，不修改注册表，不含病毒、木马、后门等，请放心使用\r\n4.本程序由Zeng Fan为Peng Jing创作，您可以免费使用并传播本软件，但不得用于商业用途或牟利，Zeng Fan保留对本软件的所有版权和进一步修改的权利\r\n5.您可以通过修改\"IP.txt\"文件的内容来修改自己的昵称和好友列表。该文件位于本程序所在的目录下，第一行为您的昵称，从第二行起以两行为一单位记录一个好友的昵称和IP地址，不能有多余的空行。如果程序运行不正常，您可以尝试修改\"IP.txt\"文件并重新运行程序\r\n6.点击标题栏的\"关闭\"按钮将使程序最小化至托盘，关闭程序的方法是点击\"关闭\"按钮下方的\"X\"按钮或在托盘图标上点右键关闭\r\n7.请确保本程序由Internet访问权限，否则程序无法正常运行\r\n5.您在使用过程中发现bug或有任何疑问，欢迎发邮件至wishinghappiness@sina.com");
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
