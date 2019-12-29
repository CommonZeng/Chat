// chatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "chat.h"
#include "chatDlg.h"
#include "HelpDlg.h"
#include "FriendNameDlg.h"
#include <Mmsystem.h>  
#pragma comment(lib,"Winmm.lib")   

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CString	m_Info;
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	m_Info = _T("������ϸ�Ķ�������֪\r\n1.���������¼������ֻ�ܱ�֤����ָ��IPͨѶ�������ܱ�֤����ȷ����ĳ��ͨѶ������ȷ������ͨѶ�Ķ������ݣ���ֹ��թ��ƭ�ַ�������ʹ�ñ������������κκ�������˲����κ�����\r\n2.��������Դ��Ͱ�����ִ�г���(*.exe)���ڵ��κ��ļ������ڽ��պ��Ѵ��������ļ�ǰ��𣬲��ڽ�����ɺ���б�Ҫ�Ĳ鶾����ʹ�ñ������������κκ�������˲����κ�����\r\n3.�����򲻻��޸����������ļ������޸�ע�������������ľ�����ŵȣ������ʹ��\r\n4.��������Zeng FanΪPeng Jing���������������ʹ�ò������������������������ҵ��;��Ĳ����Zeng Fan�����Ա���������а�Ȩ�ͽ�һ���޸ĵ�Ȩ��\r\n5.������ͨ���޸�\"IP.txt\"�ļ����������޸��Լ����ǳƺͺ����б����ļ�λ�ڱ��������ڵ�Ŀ¼�£���һ��Ϊ�����ǳƣ��ӵڶ�����������Ϊһ��λ��¼һ�����ѵ��ǳƺ�IP��ַ�������ж���Ŀ��С�����������в������������Գ����޸�\"IP.txt\"�ļ����������г���\r\n6.�����������\"�ر�\"��ť��ʹ������С�������̣��رճ���ķ����ǵ��\"�ر�\"��ť�·���\"X\"��ť��������ͼ���ϵ��Ҽ��ر�\r\n7.��ȷ����������Internet����Ȩ�ޣ���������޷���������\r\n5.����ʹ�ù����з���bug�����κ����ʣ���ӭ���ʼ���wishinghappiness@sina.com");
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Text(pDX, IDC_EDITInfo, m_Info);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatDlg dialog

CChatDlg::CChatDlg(CWnd* pParent /*=NULL*/)
: CDialog(CChatDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChatDlg)
	m_user = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChatDlg)
	DDX_Control(pDX, IDC_STATICOnline, m_staticonline);
	DDX_Control(pDX, IDC_PROGRESSSend, m_progresssend);
	DDX_Text(pDX, IDC_EDITMyName, m_user);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChatDlg, CDialog)
//{{AFX_MSG_MAP(CChatDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BtnSend, OnBtnSend)
ON_BN_CLICKED(IDC_Btn_clear, OnBtnclear)
ON_BN_CLICKED(IDC_Btn_SendFile, OnBtnSendFile)
ON_WM_TIMER()
ON_WM_CLOSE()
ON_CBN_SELCHANGE(IDC_COMBOPEOPLE, OnSelchangeCombopeople)
ON_BN_CLICKED(IDC_BUTTONQuit, OnBUTTONQuit)
ON_BN_CLICKED(IDC_Btn_SaveFriend, OnBtnSaveFriend)
ON_BN_CLICKED(IDC_Btn_Help, OnBtnHelp)
ON_EN_CHANGE(IDC_EDITMyName, OnChangeEDITMyName)
	ON_WM_DROPFILES()
	//}}AFX_MSG_MAP
ON_MESSAGE(WM_RECVDATA,OnRecvData)
ON_MESSAGE(WM_FILEBYTESEND,OnFileByteSend)
ON_MESSAGE(WM_SHOWTASK,onShowTask)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatDlg message handlers

BOOL CChatDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Add "About..." menu item to system menu.
	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	HANDLE hMutex;
	hMutex=CreateMutex(NULL,TRUE,"theonlyonechatinstance");
	if(hMutex){
		if(ERROR_ALREADY_EXISTS==GetLastError())
		{
			MessageBox("��һ��chatʵ����������!");
			exit(1);
		}
	}
	CString   path=AfxGetApp()->m_pszHelpFilePath;  
	CString   str=AfxGetApp()->m_pszExeName;  
	path=path.Left(path.GetLength()-str.GetLength()-4);  
	CString filename=path+"IP.txt";
	
	BOOL isfound;
	CFileFind find;
	isfound=find.FindFile(filename);
	if(!isfound){
		AfxMessageBox("���ڵ�ַ��������Է�IP��ַ����IP.txt�ļ��а�\"����+�س�+IP��ַ+�س�\"�ĸ�ʽ�����Լ���ͨѶ¼",MB_ICONINFORMATION);
		CStdioFile filenew;
		filenew.Open(filename,CFile::modeReadWrite|CFile::modeCreate|CFile::modeNoTruncate);
		CString writeline;
		writeline="�ҵ��ǳ�";
		filenew.WriteString(writeline);
		char enter;
		enter='\n';
		filenew.Write(&enter,1);
		writeline="�ҵĺ���";
		filenew.WriteString(writeline);
		
		filenew.Write(&enter,1);
		writeline="59.66.166.111";
		filenew.WriteString(writeline);
		filenew.Write(&enter,1);
		
		filenew.Close();
		
	}
	CComboBox *pCombo=(CComboBox *)GetDlgItem(IDC_COMBOPEOPLE); 
	CStdioFile ipfile;
	CFileException e;
	int peoplenumber=0;
    if(ipfile.Open(filename,CFile::modeRead,&e) ){
		ipfile.SeekToBegin();   
		PEOPLE *people=new PEOPLE; 
		BOOL notendoffile=TRUE;
		ipfile.ReadString(m_user);
		//AfxMessageBox(m_user);
		UpdateData(FALSE);
		while(notendoffile)
		{
			peoplenumber++;
			ipfile.ReadString(people->name);
			//char a[100];
			//CString peoplename=a;
			//ipfile.ReadString(a,20);
			pCombo->AddString(people->name);
			notendoffile=ipfile.ReadString(people->name);
			//	if(NULL==notendoffile)break;
		}
		pCombo->DeleteString(peoplenumber-1);
		
		ipfile.Close();                                           
		pCombo->SetCurSel(0);
		OnSelchangeCombopeople();}else{
			MessageBox("��IP��ַ�ļ�ʧ��!");
			char err[1500];
			e.GetErrorMessage(err,1024);
			
			MessageBox(err);}
		InitSocket();InitOnlineSocket();
		RECVPARAM *precvparam=new RECVPARAM;
		precvparam->sock=m_socket;
		precvparam->hwnd=m_hWnd;
		HANDLE hThread=CreateThread(NULL,0,RecvProc,(LPVOID)precvparam,0,NULL);
		CloseHandle(hThread);
		
		FILEPARAM *pfileparam=new FILEPARAM;
		//		pfileparam->user=&m_user;
		pfileparam->hwnd=m_hWnd;	
		HANDLE hfileThread=CreateThread(NULL,0,FileRecvProc,(LPVOID)pfileparam,0,NULL);
		CloseHandle(hfileThread);
		
		
		ONLINEPARAM *ponlineparam=new ONLINEPARAM;
		ponlineparam->user=&m_user;
		ponlineparam->hwnd=m_hWnd;
		ponlineparam->sock=m_onlinesocket;
		HANDLE honlineThread=CreateThread(NULL,0,OnlineRecvProc,(LPVOID)ponlineparam,0,NULL);
		CloseHandle(honlineThread);
		
		SetTimer(1,1000,NULL);
		//	SetTimer(2,1000,NULL);
		//		m_user=0;
		Invalidate();
		return TRUE;  // return TRUE  unless you set the focus to a control
}

void CChatDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CChatDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CChatDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CChatDlg::InitSocket()
{
	m_socket=socket(AF_INET,SOCK_DGRAM,0);
	if(INVALID_SOCKET==m_socket)
	{
		MessageBox("�����׽��ִ���ʧ�ܣ�");
		return 0;
	}
	SOCKADDR_IN addrsock;
	addrsock.sin_family=AF_INET;
	addrsock.sin_port=htons(2637);
	addrsock.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
	int retval;
	retval=bind(m_socket,(SOCKADDR *)&addrsock,sizeof(SOCKADDR));
	if(SOCKET_ERROR==retval)
	{
		closesocket(m_socket);
		MessageBox("�����׽��ְ�ʧ�ܣ�");
		return 0;
	}
	return TRUE;
}




DWORD WINAPI CChatDlg::RecvProc(LPVOID lpParameter)
{
	SOCKET sock=((RECVPARAM *)lpParameter)->sock;
	HWND hwnd=((RECVPARAM *)lpParameter)->hwnd;
	SOCKADDR_IN  addrFrom;
	int retval;
	int len,errcode;
	len=sizeof(SOCKADDR);
	char recvbuff[500];
	while(1)
	{
		
		retval=recvfrom(sock,recvbuff,500,0,(SOCKADDR *)&addrFrom,&len);
		if(SOCKET_ERROR==retval)
		{
			errcode=WSAGetLastError();
			
		//	break;
		}
		::PostMessage(hwnd,WM_RECVDATA,0,(LPARAM)recvbuff);
		
	}
	return 0;
}



void CChatDlg::OnRecvData(WPARAM wParam,LPARAM lParam)
{
	
	CString str=(char *)lParam;
	
	GetDlgItemText(IDC_EDIT_CHATING,chating);
	
	chating+=str;
	chating+="\r\n\r\n";
	SetDlgItemText(IDC_EDIT_CHATING,chating);
	GetDlgItem(IDC_EDIT_CHATING)->SendMessage(WM_VSCROLL, MAKEWPARAM(SB_BOTTOM,0),0);
	
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1),AfxGetResourceHandle(),SND_ASYNC|SND_RESOURCE|SND_NODEFAULT);
	
	ShowWindow(SW_SHOW);
	
	
	HWND hWnd=AfxGetMainWnd()->m_hWnd;	
	
	::FlashWindow(hWnd,TRUE);
		CString   path=AfxGetApp()->m_pszHelpFilePath;  
	CString   strpath=AfxGetApp()->m_pszExeName;  
	path=path.Left(path.GetLength()-strpath.GetLength()-4);  
	CString filename=path+"Record.txt";
	
	BOOL isfound;
	CFileFind find;
	isfound=find.FindFile(filename);
		SYSTEMTIME st;
		CString strDate,strTime;
		GetLocalTime(&st);
		strDate.Format("%4d-%2d-%2d",st.wYear,st.wMonth,st.wDay);
		strDate+=str;
		strDate+="\r\n\r\n";
	if(!isfound){
		CStdioFile filechat;
		filechat.Open(filename,CFile::modeReadWrite|CFile::modeCreate|CFile::modeNoTruncate);
		filechat.SeekToEnd();
		filechat.WriteString(strDate);
		filechat.Close();
	}else
	{
		CStdioFile filechat;
		filechat.Open(filename,CFile::modeReadWrite);
		filechat.SeekToEnd();
		filechat.WriteString(strDate);
		filechat.Close();
	}

	
}

void CChatDlg::OnBtnSend() 
{
	int retval,IPnotempty;
	DWORD dwIP;
	
	
	
	
	
	IPnotempty=((CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS1))->GetAddress(dwIP);
	
	SOCKADDR_IN addrTo;
	addrTo.sin_addr.S_un.S_addr=htonl(dwIP);
	addrTo.sin_family=AF_INET;
	addrTo.sin_port=htons(2637);
	CString sendbuff,tempbuff;
	GetDlgItemText(IDC_EDIT_SENDING,tempbuff);
	
	CTime time = CTime::GetCurrentTime();   
	CString m_strTime = time.Format("%H:%M:%S"); 
	UpdateData(TRUE);
	myname=m_user;
	sendbuff+=myname;
	sendbuff+=m_strTime;
	sendbuff+="��\r\n";
	sendbuff+=tempbuff;
	retval=sendto(m_socket,sendbuff,sendbuff.GetLength()+1,0,(SOCKADDR *)&addrTo,sizeof(SOCKADDR));
	
	
	
	chating+=sendbuff;
	chating+="\r\n\r\n";
	
	SetDlgItemText(IDC_EDIT_CHATING,chating);
	SetDlgItemText(IDC_EDIT_SENDING,"");
	GetDlgItem(IDC_EDIT_CHATING)->SendMessage(WM_VSCROLL, MAKEWPARAM(SB_BOTTOM,0),0);




	CString   path=AfxGetApp()->m_pszHelpFilePath;  
	CString   str=AfxGetApp()->m_pszExeName;  
	path=path.Left(path.GetLength()-str.GetLength()-4);  
	CString filename=path+"Record.txt";
	
	BOOL isfound;
	CFileFind find;
	isfound=find.FindFile(filename);
		SYSTEMTIME st;
		CString strDate,strTime;
		GetLocalTime(&st);
		strDate.Format("%4d-%2d-%2d",st.wYear,st.wMonth,st.wDay);
		strDate+=sendbuff;
		strDate+="\r\n\r\n";
	if(!isfound){
		CStdioFile filechat;
		filechat.Open(filename,CFile::modeReadWrite|CFile::modeCreate|CFile::modeNoTruncate);
		filechat.SeekToEnd();
		filechat.WriteString(strDate);
		filechat.Close();
	}else
	{
		CStdioFile filechat;
		filechat.Open(filename,CFile::modeReadWrite);
		filechat.SeekToEnd();
		filechat.WriteString(strDate);
		filechat.Close();
	}
	if(SOCKET_ERROR==retval){
		MessageBox("������Ϣ����ʧ�ܣ�");
		
	}
	
}

void CChatDlg::OnBtnclear() 
{
	chating="";	
	SetDlgItemText(IDC_EDIT_CHATING,chating);
}

void CChatDlg::OnBtnSendFile() 
{
	
	
	FILEPARAM *pfileparam=new FILEPARAM;
	//	pfileparam->user=&m_user;
	pfileparam->hwnd=m_hWnd;
	HANDLE hfileThread=CreateThread(NULL,0,FileSendProc,(LPVOID)pfileparam,0,NULL);
	CloseHandle(hfileThread);
	
	m_progresssend.SetRange(0,100);
	m_progresssend.SetPos(0);
	
	
	
	
}	
DWORD WINAPI CChatDlg::FileRecvProc(LPVOID lpParameter)
{
	
	int *user=((FILEPARAM *)lpParameter)->user;
	HWND hwnd=((FILEPARAM *)lpParameter)->hwnd;
	CSocket sockSrv;
	
	sockSrv.Create(7382); //�˿ں�
	
	sockSrv.Listen(); //��ʼ����
	//	AfxMessageBox("listen");
	while(1){	
		CSocket sockSend;
		
		sockSrv.Accept(sockSend);
		
		PlaySound(MAKEINTRESOURCE(IDR_WAVE1),AfxGetResourceHandle(),SND_ASYNC|SND_RESOURCE|SND_NODEFAULT);
		
		HWND hWnd=AfxGetMainWnd()->m_hWnd;	
		
		::FlashWindow(hWnd,TRUE);
		
		unsigned long filelength;
		unsigned long bytesend=0;		
		int namelength;
		char strName[70];
		char strExt[5];
		
		memset(strName,'\0',70);
		memset(strExt,'\0',5);
		
		
		//�Ƚ������ݳ��ȣ��ٽ������ݱ���
		sockSend.Receive(&namelength,sizeof(int));
		sockSend.Receive(strName,namelength);
		//		sockSend.Receive(&extlength,sizeof(int));
		//		sockSend.Receive(strExt,extlength);
		sockSend.Receive(&filelength,sizeof(unsigned long));
		CString filemesssage;
		CString filename=strName;
		
		char charfilelen[20];
		ultoa(filelength,charfilelen,10);
		CString strfilelen=charfilelen;
		filemesssage+="�Է�Ҫ���ļ�\""+filename+"\"����,��СΪ"+strfilelen+"bytes";
		AfxMessageBox(filemesssage,MB_ICONINFORMATION);
		
		CFileDialog fileDlg(FALSE,NULL,strName,OFN_OVERWRITEPROMPT);
		
		if(IDOK == fileDlg.DoModal())
			
		{			CString strdecline="continue";
		//	AfxMessageBox("continue");
		sockSend.Send(strdecline,strdecline.GetLength());
		
		
		
		
		fileDlg.m_ofn.lpstrTitle = "�����ļ�";
		
		CFile destFile(fileDlg.GetPathName(),
			
			CFile::modeCreate | CFile::modeWrite | CFile::typeBinary);
		
		UINT dwRead = 1;
		
		//д���´������ļ�
		
		while(dwRead)
			
		{
			
			byte* data = new byte[1024000];
			
			memset(data,0,1024000);
			
			dwRead = sockSend.Receive(data, 1024000);
			
			
			bytesend+=dwRead;
			PROGRESSPARAM *pprogressparam=new PROGRESSPARAM;
			pprogressparam->bytesend=bytesend;
			pprogressparam->filelength=filelength;
			::PostMessage(hwnd,WM_FILEBYTESEND,0,(LPARAM)pprogressparam);
			
			
			destFile.Write(data, dwRead);
			free(data);
		}
		
		destFile.Close();
		
		
		AfxMessageBox("�ļ��������!",MB_ICONINFORMATION);
		}else{
			CString strdecline="declined";
			//	AfxMessageBox("declined");
			sockSend.Send(strdecline,strdecline.GetLength());
			AfxMessageBox("��ȡ�����ļ�����!",MB_ICONINFORMATION);
			CChatDlg   *pDlg   =   (CChatDlg*)(AfxGetApp()->m_pMainWnd);   
			
			pDlg->SetDlgItemText(IDC_STATICFile,"��ȡ�����ļ�����");
		}
		
		
		sockSend.Close();
		//				AfxMessageBox("sockSend.Close()");
		//	sockSrv.Close;		AfxMessageBox("sockSrv.Close");
	}
	sockSrv.Close();
	
	
	return 0;
	
	
}	
DWORD WINAPI CChatDlg::FileSendProc(LPVOID lpParameter)
{
	
	int *user=((FILEPARAM *)lpParameter)->user;
	HWND hwnd=((FILEPARAM *)lpParameter)->hwnd;
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrTitle = "���ļ�";
	fileDlg.m_ofn.lpstrFilter = "�����ļ�(*.*) \0 *.*\0";
	if(IDOK == fileDlg.DoModal())
	{
		CFile fileOpen;
		if(!fileOpen.Open(fileDlg.GetPathName(), CFile::modeRead | CFile::typeBinary))
		{
			AfxMessageBox("�޷����ļ�", MB_OK | MB_ICONERROR);
			
		}	
		int IPnotempty;	
		DWORD dwIP;
		CChatDlg   *pDlg   =   (CChatDlg*)(AfxGetApp()->m_pMainWnd);   
		IPnotempty=((CIPAddressCtrl *)pDlg->GetDlgItem(IDC_IPADDRESS1))->GetAddress(dwIP);
		
		CSocket sockClient;
		
		sockClient.Create();
		//		AfxMessageBox("created");
		//����
		CString strIP;
		
		
		if(0==IPnotempty){
			
		}else{ 
			
			strIP.Format("%u.%u.%u.%u",HIBYTE(HIWORD(dwIP)),LOBYTE(HIWORD(dwIP)),HIBYTE(LOWORD(dwIP)),LOBYTE(LOWORD(dwIP)));
			//	AfxMessageBox(strIP);
		}
		sockClient.Connect(strIP, 7382);
		//		AfxMessageBox("connected");
		
		
		char* strExt = new char[5];
		char* strName = new char[70];
		memset(strName,'\0',70);
		memset(strExt,'\0',5);
		
		strcpy(strExt, fileDlg.GetFileExt());
		strcpy(strName, fileDlg.GetFileName());
		int namelength = strlen(strName);
		int extlength = strlen(strExt);
		unsigned long filelength=fileOpen.GetLength();
		
		
		sockClient.Send(&namelength,sizeof(int));
		sockClient.Send(strName,namelength);
		//	sockClient.Send(&extlength,sizeof(int));
		//	sockClient.Send(strExt,extlength);
		sockClient.Send(&filelength,sizeof(unsigned long));
		
		
		pDlg->SetDlgItemText(IDC_STATICFile,"�ȴ��Է������ļ�");
		
		char* checkbuff = new char[9];
		memset(checkbuff,'\0',9);
		sockClient.Receive(checkbuff,9);
		CString strcheck=checkbuff;
		if("continue"==strcheck)
		{		
			
			
			unsigned long bytesend=0;
			
			
			UINT dwRead = 1;
			while(dwRead)
				
			{
				
				//һ�η���1kb
				
				
				
				byte* data = new byte[1024000];
				
				dwRead = fileOpen.Read(data, 1024000);
				
				sockClient.Send(data, dwRead);
				bytesend+=dwRead;
				PROGRESSPARAM *pprogressparam=new PROGRESSPARAM;
				pprogressparam->bytesend=bytesend;
				pprogressparam->filelength=filelength;
				::PostMessage(hwnd,WM_FILEBYTESEND,0,(LPARAM)pprogressparam);
				free(data);
			}
			
			fileOpen.Close();
			
			sockClient.Close();
			//				AfxMessageBox("sockClient.Close");
			AfxMessageBox("�ļ��������!",MB_ICONINFORMATION);
		}else{
			AfxMessageBox("�Է�ȡ�����ļ�����!",MB_ICONINFORMATION);
			pDlg->SetDlgItemText(IDC_STATICFile,"�Է�ȡ�����ļ�����");
			fileOpen.Close();
		}
	}	
	
	
				
				return 0;
}


void CChatDlg::OnFileByteSend(WPARAM wParam, LPARAM lParam)
{
	unsigned long bytesend=((PROGRESSPARAM *)lParam)->bytesend;
	unsigned long filelength=((PROGRESSPARAM *)lParam)->filelength;
	char strtemp[100];
	CString str;
	double progress=bytesend/(double)(filelength/100);
	int prog=(int)progress;
	itoa(bytesend,strtemp,10);str+=strtemp;str+="/";
	itoa(filelength,strtemp,10);str+=strtemp;
	str+="bytes send";
	
	SetDlgItemText(IDC_STATICFile,str);
	m_progresssend.SetPos(prog);
	if(bytesend==filelength)
	{
		SetDlgItemText(IDC_STATICFile,"�ļ��������!");
	}
}

DWORD WINAPI CChatDlg::OnlineRecvProc(LPVOID lpParameter)
{
	
	
	HWND hwnd=((ONLINEPARAM *)lpParameter)->hwnd;
	
	SOCKET sock=((ONLINEPARAM *)lpParameter)->sock;
	
	CChatDlg   *pDlg   =   (CChatDlg*)(AfxGetApp()->m_pMainWnd);  
	//	CString status;
	//	pDlg->m_staticonline.GetWindowText(status);
	//	if("����"!=status){
	while(1){
		char checkstatus[20];
		SOCKADDR_IN  addrFrom;
		int len;
		//int errcode;
		len=sizeof(SOCKADDR);
		
		memset(checkstatus,0,20);
		
		int retval;
		retval=recvfrom(sock,checkstatus,20,0,(SOCKADDR *)&addrFrom,&len);
		DWORD IP;
		IP=addrFrom.sin_addr.S_un.S_addr;
		//	CString strI;
		//					strI.Format("%u.%u.%u.%u",HIBYTE(HIWORD(IP)),LOBYTE(HIWORD(IP)),HIBYTE(LOWORD(IP)),LOBYTE(LOWORD(IP)));
		//	AfxMessageBox(strI);
		if(SOCKET_ERROR==retval)
		{
			//		errcode=WSAGetLastError();
			//			char err[100];
			//	itoa(errcode,err,10);
			//	AfxMessageBox(err);
			pDlg->m_staticonline.SetWindowText("����");
			break;
			
		}
		CString strcheck;
		
		
		
		len=sizeof(SOCKADDR);
		
		
		BOOL IPnotempty;
		DWORD dwIP;
		IPnotempty=((CIPAddressCtrl *)pDlg->GetDlgItem(IDC_IPADDRESS1))->GetAddress(dwIP);
		
		strcheck=checkstatus;
		if(addrFrom.sin_addr.S_un.S_addr==htonl(dwIP)){
			
			
			if("iamonline"==strcheck)
			{
				
				CChatDlg   *pDlg   =   (CChatDlg*)(AfxGetApp()->m_pMainWnd);  
				
				pDlg->m_staticonline.SetWindowText("����");Sleep(1000);
			}
			
		}
		else{
			
			
			pDlg->m_staticonline.SetWindowText("����");
		}
	}
	
	
	return 0;
	
	
}

void CChatDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	SOCKET	m_onlinesock=socket(AF_INET,SOCK_DGRAM,0); 
	if(INVALID_SOCKET==m_onlinesock)
	{
		//		AfxMessageBox("���߼���׽��ִ���ʧ��!");
		
	}
	
	int retval;
	CString   path=AfxGetApp()->m_pszHelpFilePath;  
	CString   str=AfxGetApp()->m_pszExeName;  
	path=path.Left(path.GetLength()-str.GetLength()-4);  
	CString filename=path+"IP.txt";
	CComboBox *pCombo=(CComboBox *)GetDlgItem(IDC_COMBOPEOPLE); 
	CStdioFile ipfile;
	CFileException e;
	int peoplenumber=0;
	if(ipfile.Open(filename,CFile::modeRead,&e) ){
		ipfile.SeekToBegin();   
		PEOPLE *people=new PEOPLE; 
		BOOL notendoffile=TRUE;
		//		pCombo->ResetContent();
		ipfile.ReadString(people->name);
		
		while(notendoffile)
		{
			peoplenumber++;
			ipfile.ReadString(people->name);
			//char a[100];
			//CString peoplename=a;
			//ipfile.ReadString(a,20);
			//			pCombo->AddString(people->name);
			notendoffile=ipfile.ReadString(people->ipaddr);
			
			if(FALSE==notendoffile){break;}
			//			MessageBox(people->ipaddr);
			/*		BYTE IP[5];
			ZeroMemory(IP,5);
			sscanf(people->ipaddr,"%d.%d.%d.%d",&IP[0],&IP[1],&IP[2],&IP[3]); 
			DWORD dwIP;
			dwIP*/
			SOCKADDR_IN addrTo;
			addrTo.sin_addr.S_un.S_addr=inet_addr(people->ipaddr);
			
			addrTo.sin_family=AF_INET;
			addrTo.sin_port=htons(9533);
			CString sendbuff,tempbuff;
			
			sendbuff="";
			sendbuff+="iamonline";
			retval=sendto(m_onlinesock,sendbuff,sendbuff.GetLength()+1,0,(SOCKADDR *)&addrTo,sizeof(SOCKADDR));
			//		MessageBox(sendbuff);
			if(SOCKET_ERROR==retval){
				//								MessageBox("����״̬��Ϣ����ʧ��!");
				
			}
		}
		
		closesocket(m_onlinesock);
		
		ipfile.Close();                                           
	}
	
	
	
	
	CDialog::OnTimer(nIDEvent);
	
	
}	



void CChatDlg::OnClose() 
{
	NOTIFYICONDATA nid;
	nid.cbSize=(DWORD)sizeof(NOTIFYICONDATA);
	nid.hWnd=this->m_hWnd;
	nid.uID=IDR_MAINFRAME;
	nid.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP ;
	nid.uCallbackMessage=WM_SHOWTASK;//�Զ������Ϣ����
	nid.hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));
	strcpy(nid.szTip,"chat"); 
	Shell_NotifyIcon(NIM_ADD,&nid); //�����������ͼ��
	ShowWindow(SW_HIDE); //���������� 	
	//	CDialog::OnClose();
}


LRESULT CChatDlg::onShowTask(WPARAM wParam,LPARAM lParam)
//wParam���յ���ͼ���ID����lParam���յ���������Ϊ
{
	if(wParam!=IDR_MAINFRAME)
		return 1;
	switch(lParam)
	{
	case WM_RBUTTONUP://�Ҽ�����ʱ������ݲ˵�������ֻ��һ�����رա�
		{
			
			LPPOINT lpoint=new tagPOINT;
			::GetCursorPos(lpoint);//�õ����λ��
			CMenu menu;
			menu.CreatePopupMenu();//����һ������ʽ�˵�
			//���Ӳ˵���رա������������ϢWM_DESTROY�������ڣ���
			//���أ��������������
			menu.AppendMenu(MF_STRING,WM_DESTROY,"�ر�");
			//ȷ������ʽ�˵���λ��
			menu.TrackPopupMenu(TPM_LEFTALIGN,lpoint->x,lpoint->y,this);
			
			HMENU hmenu=menu.Detach();
			menu.DestroyMenu();
			delete lpoint;
			NOTIFYICONDATA nid;
			nid.cbSize=(DWORD)sizeof(NOTIFYICONDATA);
			nid.hWnd=this->m_hWnd;
			nid.uID=IDR_MAINFRAME;
			nid.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP ;
			Shell_NotifyIcon(NIM_DELETE,&nid);   
		}
		break;
		//case WM_LBUTTONDBLCLK://˫������Ĵ���
		//	{
		//		this->ShowWindow(SW_SHOW);
		//	}
		//	break;
	case WM_LBUTTONUP://��������Ĵ���
		{
			this->ShowWindow(SW_SHOW);
		}
		break;
	}
	return 0;
}

void CChatDlg::OnSelchangeCombopeople() 
{
	CComboBox *pCombo=(CComboBox *)GetDlgItem(IDC_COMBOPEOPLE); 
	int peoplenumber=0;
	peoplenumber=pCombo->GetCurSel();
	int i;
	
	CStdioFile ipfile;
	CString ipstr;
	CString   path=AfxGetApp()->m_pszHelpFilePath;  
	CString   str=AfxGetApp()->m_pszExeName;  
	path=path.Left(path.GetLength()-str.GetLength()-4);  
	CString filename=path+"IP.txt";
	
	CFileException e;
	
	if(ipfile.Open(filename,CFile::modeRead,&e)){
		for(i=0;i<=(2*peoplenumber)+2;i++){
			ipfile.ReadString(ipstr);
		}
		
		BYTE IP[5];
		ZeroMemory(IP,5);
		sscanf(ipstr,"%d.%d.%d.%d",&IP[0],&IP[1],&IP[2],&IP[3]); 
		((CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS1))->SetAddress(IP[0],IP[1],IP[2],IP[3]);
		ipfile.Close();      
	}else{
		MessageBox("��IP��ַ�ļ�ʧ��!");
		
		
		char err[1500];
		e.GetErrorMessage(err,1024);
		
		MessageBox(err);
	}
	//	closesocket(m_onlinesocket);
	//		MessageBox("change");
	
	//	InitOnlineSocket();
}



void CChatDlg::OnBUTTONQuit() 
{
	// TODO: Add your control notification handler code here
	AfxPostQuitMessage(ID_APP_EXIT);
	//exit(1);
}

void CChatDlg::OnBtnSaveFriend() 
{
	// TODO: Add your control notification handler code here
	
	
	CFriendNameDlg Dlg;
	if(IDOK==Dlg.DoModal()){
		//	Dlg.DoModal();
		
		CString   path=AfxGetApp()->m_pszHelpFilePath;  
		CString   str=AfxGetApp()->m_pszExeName;  
		path=path.Left(path.GetLength()-str.GetLength()-4);  
		CString filename=path+"IP.txt";
		CStdioFile filenew;
		filenew.Open(filename,CFile::modeReadWrite|CFile::modeNoTruncate);
		filenew.SeekToEnd();
		CString writeline;
		
		char enter;
		enter='\n';
		
		CString strIP;
		DWORD dwIP;
		CChatDlg   *pDlg   =   (CChatDlg*)(AfxGetApp()->m_pMainWnd);   
		((CIPAddressCtrl *)pDlg->GetDlgItem(IDC_IPADDRESS1))->GetAddress(dwIP);
		
		strIP.Format("%u.%u.%u.%u",HIBYTE(HIWORD(dwIP)),LOBYTE(HIWORD(dwIP)),HIBYTE(LOWORD(dwIP)),LOBYTE(LOWORD(dwIP)));
		
		
		filenew.WriteString(strIP);
		filenew.Write(&enter,1);
		
		filenew.Close();
		AfxMessageBox("�����ѳɹ�����",MB_ICONINFORMATION);
	}
	CString   path=AfxGetApp()->m_pszHelpFilePath;  
	CString   str=AfxGetApp()->m_pszExeName;  
	path=path.Left(path.GetLength()-str.GetLength()-4);  
	CString filename=path+"IP.txt";
	CComboBox *pCombo=(CComboBox *)GetDlgItem(IDC_COMBOPEOPLE); 
	CStdioFile ipfile;
	CFileException e;
	int peoplenumber=0;
	if(ipfile.Open(filename,CFile::modeRead,&e) ){
		ipfile.SeekToBegin();   
		PEOPLE *people=new PEOPLE; 
		BOOL notendoffile=TRUE;
		pCombo->ResetContent();
		ipfile.ReadString(people->name);
		
		while(notendoffile)
		{
			peoplenumber++;
			ipfile.ReadString(people->name);
			//char a[100];
			//CString peoplename=a;
			//ipfile.ReadString(a,20);
			pCombo->AddString(people->name);
			notendoffile=ipfile.ReadString(people->name);
			//	if(NULL==notendoffile)break;
		}
		pCombo->DeleteString(peoplenumber-1);
		
		ipfile.Close();                                           
		
		
		peoplenumber=pCombo->GetCount();
		
		pCombo->SetCurSel(peoplenumber-1);
		OnSelchangeCombopeople(); 
	}
}

void CChatDlg::OnBtnHelp() 
{
	// TODO: Add your control notification handler code here
	
	CHelpDlg Dlg;
	if(IDOK==Dlg.DoModal()){
		AfxMessageBox("��ӭ��ʹ��!",MB_ICONINFORMATION);
		
	}else{
		//		AfxMessageBox("����ͬ���������ݣ��ʳ����˳�",MB_ICONINFORMATION);
		//		exit(1);
	}
}



void CChatDlg::OnChangeEDITMyName() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString   path=AfxGetApp()->m_pszHelpFilePath;  
	CString   str=AfxGetApp()->m_pszExeName;  
	path=path.Left(path.GetLength()-str.GetLength()-4);  
	CString filename=path+"IP.txt";
	CString fileoldname=path+"IPold.txt";
	CStdioFile fileold;
	//	fileold.Open(filename,CFile::modeReadWrite);
	fileold.Rename(filename,fileoldname);
	fileold.Open(fileoldname,CFile::modeRead);
	CStdioFile filenew;
	filenew.Open(filename,CFile::modeCreate|CFile::modeWrite);
	fileold.SeekToBegin();
	filenew.SeekToBegin();
	
	CString writeline;
	
	UpdateData(TRUE);
	writeline=m_user;
	filenew.WriteString(writeline);
	char enter;
	enter='\n';
	filenew.Write(&enter,1);
	fileold.ReadString(writeline);
	BOOL notendoffile=TRUE;
	while(notendoffile)
	{
		notendoffile=fileold.ReadString(writeline);
		if(FALSE==notendoffile){break;}
		filenew.WriteString(writeline);
		filenew.Write(&enter,1);
	}	
	fileold.Close();
	filenew.Close();
	fileold.Remove(fileoldname);
}

BOOL CChatDlg::InitOnlineSocket()
{
	m_onlinesocket=socket(AF_INET,SOCK_DGRAM,0); 
	if(INVALID_SOCKET==m_onlinesocket)
	{
		AfxMessageBox("���߼���׽��ִ���ʧ��!");
		
	}
	BOOL IPnotempty=TRUE;
	DWORD dwIP;
	
	CChatDlg   *pDlg   =   (CChatDlg*)(AfxGetApp()->m_pMainWnd);   
	IPnotempty=((CIPAddressCtrl *)pDlg->GetDlgItem(IDC_IPADDRESS1))->GetAddress(dwIP);
	
	SOCKADDR_IN addrsock;
	addrsock.sin_family=AF_INET;
	addrsock.sin_port=htons(9533);
	addrsock.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
	int retval;
	
	
	retval=bind(m_onlinesocket,(SOCKADDR *)&addrsock,sizeof(SOCKADDR));
	
//	retval=WSAGetLastError();
//	char err[100];
//	itoa(retval,err,10);
	//	AfxMessageBox("changed");
	if(SOCKET_ERROR==retval)
	{
		closesocket(m_onlinesocket);
		AfxMessageBox("���߼���׽��ְ�ʧ��!");
	}
	return 0;
}

void CChatDlg::OnDropFiles(HDROP hDropInfo) 
{
	MessageBox("��Ǹ��������в��߱������������ļ���ť��");	

	CDialog::OnDropFiles(hDropInfo);
}


