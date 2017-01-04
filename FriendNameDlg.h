#if !defined(AFX_FRIENDNAMEDLG_H__75202331_A87E_460E_A9C9_465BDC85C551__INCLUDED_)
#define AFX_FRIENDNAMEDLG_H__75202331_A87E_460E_A9C9_465BDC85C551__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FriendNameDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFriendNameDlg dialog

class CFriendNameDlg : public CDialog
{
// Construction
public:
	CFriendNameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFriendNameDlg)
	enum { IDD = IDD_DIALOG_FriendName };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFriendNameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFriendNameDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FRIENDNAMEDLG_H__75202331_A87E_460E_A9C9_465BDC85C551__INCLUDED_)
