// chatDlg.h : header file
//

#if !defined(AFX_CHATDLG_H__C20649A8_7882_4370_8CB8_8B035AB39A5D__INCLUDED_)
#define AFX_CHATDLG_H__C20649A8_7882_4370_8CB8_8B035AB39A5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChatDlg dialog

#define WM_RECVDATA WM_USER+1
#define WM_FILEBYTESEND WM_USER+2
#define WM_SHOWTASK WM_USER+1986 


struct PEOPLE
{
	CString name;
	CString ipaddr;
	struct PEOPLE* next;
};

struct RECVPARAM
{
	SOCKET sock;
	HWND hwnd;
};
struct FILEPARAM
{
	int *user;
	HWND hwnd;
};


struct ONLINEPARAM
{
	SOCKET sock;
	CString *user;
	HWND hwnd;
public:
};


struct PROGRESSPARAM
{
	unsigned long bytesend;
	unsigned long filelength;
};

class CChatDlg : public CDialog
{
// Construction
public:
	BOOL InitOnlineSocket();
	SOCKET m_onlinesocket;
	static DWORD WINAPI OnlineRecvProc(LPVOID lpParameter);
	static DWORD WINAPI FileSendProc(LPVOID lpParameter);
	static DWORD WINAPI FileRecvProc(LPVOID lpParameter);
	static DWORD WINAPI RecvProc(LPVOID lpParameter);
	BOOL InitSocket();
	CChatDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CChatDlg)
	enum { IDD = IDD_CHAT_DIALOG };
	CStatic	m_staticonline;
	CProgressCtrl	m_progresssend;
	CString	m_user;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChatDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnSend();
	afx_msg void OnBtnclear();
	afx_msg void OnBtnSendFile();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnClose();
	afx_msg void OnSelchangeCombopeople();
	afx_msg void OnBUTTONQuit();
	afx_msg void OnBtnSaveFriend();
	afx_msg void OnBtnHelp();
	afx_msg void OnChangeEDITMyName();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	//}}AFX_MSG
	afx_msg void OnRecvData(WPARAM wParam,LPARAM lParam);
	afx_msg void OnFILEBYTESEND(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT onShowTask(WPARAM wParam,LPARAM lParam); 
	DECLARE_MESSAGE_MAP()
private:
	void OnFileByteSend(WPARAM wParam,LPARAM lParam);

	CString myname;

	CString chating;
	SOCKET m_socket;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATDLG_H__C20649A8_7882_4370_8CB8_8B035AB39A5D__INCLUDED_)
