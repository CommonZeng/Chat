; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CChatDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "chat.h"

ClassCount=5
Class1=CChatApp
Class2=CChatDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CHAT_DIALOG
Class4=CFriendNameDlg
Resource4=IDD_DIALOG_FriendName
Class5=CHelpDlg
Resource5=IDD_DIALOGHELP

[CLS:CChatApp]
Type=0
HeaderFile=chat.h
ImplementationFile=chat.cpp
Filter=N

[CLS:CChatDlg]
Type=0
HeaderFile=chatDlg.h
ImplementationFile=chatDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CChatDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=chatDlg.h
ImplementationFile=chatDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDITInfo

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_EDITInfo,edit,1352728644

[DLG:IDD_CHAT_DIALOG]
Type=1
Class=CChatDlg
ControlCount=14
Control1=IDC_IPADDRESS1,SysIPAddress32,1342242816
Control2=IDC_EDIT_CHATING,edit,1352728644
Control3=IDC_EDIT_SENDING,edit,1352732740
Control4=IDC_BtnSend,button,1342242817
Control5=IDC_Btn_clear,button,1342242816
Control6=IDC_Btn_SendFile,button,1342251008
Control7=IDC_PROGRESSSend,msctls_progress32,1350565888
Control8=IDC_STATICFile,static,1342308352
Control9=IDC_STATICOnline,static,1342312961
Control10=IDC_COMBOPEOPLE,combobox,1344339970
Control11=IDC_Btn_Help,button,1342242816
Control12=IDC_EDITMyName,edit,1350631552
Control13=IDC_BUTTONQuit,button,1342246656
Control14=IDC_Btn_SaveFriend,button,1342251008

[DLG:IDD_DIALOG_FriendName]
Type=1
Class=CFriendNameDlg
ControlCount=3
Control1=IDC_EDITFriendName,edit,1350631552
Control2=IDOK,button,1342242816
Control3=IDC_STATIC,static,1342308352

[CLS:CFriendNameDlg]
Type=0
HeaderFile=FriendNameDlg.h
ImplementationFile=FriendNameDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

[DLG:IDD_DIALOGHELP]
Type=1
Class=CHelpDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDITInfo,edit,1352728644

[CLS:CHelpDlg]
Type=0
HeaderFile=HelpDlg.h
ImplementationFile=HelpDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

