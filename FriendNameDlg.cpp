// FriendNameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "chat.h"
#include "FriendNameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFriendNameDlg dialog


CFriendNameDlg::CFriendNameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFriendNameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFriendNameDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFriendNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFriendNameDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFriendNameDlg, CDialog)
	//{{AFX_MSG_MAP(CFriendNameDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFriendNameDlg message handlers

void CFriendNameDlg::OnOK() 
{
	CString   path=AfxGetApp()->m_pszHelpFilePath;  
   CString   str=AfxGetApp()->m_pszExeName;  
   path=path.Left(path.GetLength()-str.GetLength()-4);  
   CString filename=path+"IP.txt";
 	  CStdioFile filenew;
   filenew.Open(filename,CFile::modeReadWrite|CFile::modeNoTruncate);
   filenew.SeekToEnd();
   CString writeline;
	GetDlgItemText(IDC_EDITFriendName,writeline);
   filenew.WriteString(writeline);
   char enter;
   enter='\n';
   filenew.Write(&enter,1);
  	
	CDialog::OnOK();
}
