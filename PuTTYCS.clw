; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPuTTYCSDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "puttycs.h"
LastPage=0

ClassCount=7
Class1=PasswordDialog
Class2=CPuTTYCSApp
Class3=CPuTTYCSDlg

ResourceCount=6
Resource1=IDD_PASSWORD_DIALOG
Resource2=IDD_FILTER_DIALOG
Class4=CAboutDialog
Resource3=IDD_PREFERENCES_DIALOG
Class5=CFiltersDialog
Resource4=IDD_FILTERS_DIALOG
Class6=CFilterEntryDialog
Resource5=IDD_PUTTYCS_DIALOG
Class7=CPuTTYCSDialog
Resource6=IDD_ABOUT_DIALOG

[CLS:PasswordDialog]
Type=0
BaseClass=CDialog
HeaderFile=PasswordDialog.h
ImplementationFile=PasswordDialog.cpp

[CLS:CPuTTYCSApp]
Type=0
BaseClass=CWinApp
HeaderFile=PuTTYCS.h
ImplementationFile=PuTTYCS.cpp
LastObject=CPuTTYCSApp

[CLS:CPuTTYCSDlg]
Type=0
BaseClass=CDialog
HeaderFile=PuTTYCSDlg.h
ImplementationFile=PuTTYCSDlg.cpp
LastObject=CPuTTYCSDlg
Filter=D
VirtualFilter=dWC

[DLG:IDD_PASSWORD_DIALOG]
Type=1
Class=PasswordDialog
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_PASSWORD_CEDIT,edit,1350631584
Control3=IDC_OK_BUTTON,button,1342242817
Control4=IDCANCEL,button,1342242816

[DLG:IDD_PUTTYCS_DIALOG]
Type=1
Class=CPuTTYCSDialog
ControlCount=26
Control1=IDC_STATIC,static,1342308352
Control2=IDC_FILTERS_COMBOBOX,combobox,1344339971
Control3=IDC_CASCADE_BUTTON,button,1342242816
Control4=IDC_TILE_BUTTON,button,1342242816
Control5=IDC_MINIMIZE_BUTTON,button,1342242816
Control6=IDC_HIDE_BUTTON,button,1342242816
Control7=IDC_FILTERS_BUTTON,button,1342242816
Control8=IDC_STATIC,static,1342308352
Control9=IDC_COMMAND_EDIT,edit,1350631492
Control10=IDC_SENDCR_PUSHBUTTON,button,1342246916
Control11=IDC_CMDHISTORYUP_BUTTON,button,1476460544
Control12=IDC_CMDHISTORYDOWN_BUTTON,button,1476464384
Control13=IDC_CMDHISTORYCLEAR_BUTTON,button,1476460544
Control14=IDC_CLEAR_BUTTON,button,1342242816
Control15=IDC_UP_BUTTON,button,1342242816
Control16=IDC_LEFT_BUTTON,button,1342242816
Control17=IDC_DOWN_BUTTON,button,1342242816
Control18=IDC_RIGHT_BUTTON,button,1342246656
Control19=IDC_BREAK_BUTTON,button,1342242816
Control20=IDC_ENDTELNET_BUTTON,button,1342242816
Control21=IDC_ESCAPE_BUTTON,button,1342242816
Control22=IDC_ENTER_BUTTON,button,1342242816
Control23=IDC_SCRIPT_BUTTON,button,1342242816
Control24=IDC_PASSWORD_BUTTON,button,1342242816
Control25=IDC_PREFERENCES_BUTTON,button,1342242816
Control26=IDC_SEND_BUTTON,button,1342242817

[DLG:IDD_PREFERENCES_DIALOG]
Type=1
Class=CAboutDialog
ControlCount=17
Control1=IDC_STATIC,button,1342177287
Control2=IDC_TOOLWINDOW_CHECKBOX,button,1342242819
Control3=IDC_ALWAYSONTOP_CHECKBOX,button,1342242819
Control4=IDC_STATIC,static,1342308352
Control5=IDC_TRANSITION_EDIT,edit,1350639744
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,button,1342177287
Control8=IDC_AUTOARRANGE_OFF_RADIO,button,1342308361
Control9=IDC_AUTOARRANGE_CASCADE_RADIO,button,1342177289
Control10=IDC_AUTOARRANGE_TILE_RADIO,button,1342177289
Control11=IDC_AUTOMINIMIZE_CHECKBOX,button,1342242819
Control12=IDC_ARRANGEONSTARTUP_CHECKBOX,button,1342242819
Control13=IDC_UNHIDEONEXIT_CHECKBOX,button,1342242819
Control14=IDC_STATIC,button,1342177287
Control15=IDC_SAVEPASSWORD_CHECKBOX,button,1342242819
Control16=IDC_OK_BUTTON,button,1342242817
Control17=IDCANCEL,button,1342242816

[DLG:IDD_FILTERS_DIALOG]
Type=1
Class=CFiltersDialog
ControlCount=14
Control1=IDC_STATIC,static,1342308352
Control2=IDC_FILTERS_LISTBOX,listbox,1352728833
Control3=IDC_STATIC,static,1342308352
Control4=IDC_FILTERLIST_EDIT,edit,1350633540
Control5=IDC_ADD_BUTTON,button,1342242816
Control6=IDC_EDIT_BUTTON,button,1342242816
Control7=IDC_COPY_BUTTON,button,1342242816
Control8=IDC_REMOVE_BUTTON,button,1342242816
Control9=IDC_REMOVE_ALL_BUTTON,button,1342242816
Control10=IDC_MOVEUP_BUTTON,button,1342242816
Control11=IDC_MOVEDOWN_BUTTON,button,1342242816
Control12=IDC_OK_BUTTON,button,1342242817
Control13=IDC_CANCEL_BUTTON,button,1342242816
Control14=IDC_APPLY_BUTTON,button,1476460544

[CLS:CFiltersDialog]
Type=0
HeaderFile=FiltersDialog.h
ImplementationFile=FiltersDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CFiltersDialog

[CLS:CFilterEntryDialog]
Type=0
HeaderFile=FilterEntryDialog.h
ImplementationFile=FilterEntryDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CFilterEntryDialog

[DLG:IDD_ABOUT_DIALOG]
Type=1
Class=CAboutDialog
ControlCount=6
Control1=IDC_ABOUT_TEXT_LINE1,static,1342308353
Control2=IDC_ABOUT_TEXT_LINE2,static,1342308353
Control3=IDC_VISITWEBSITE_BUTTON,button,1342242816
Control4=IDC_CLOSE_BUTTON,button,1342242817
Control5=IDC_ABOUT_TEXT_LINE3,static,1342308353
Control6=IDC_STATIC,static,1342177298

[CLS:CAboutDialog]
Type=0
HeaderFile=aboutdialog.h
ImplementationFile=aboutdialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAboutDialog

[DLG:IDD_FILTER_DIALOG]
Type=1
Class=CFilterEntryDialog
ControlCount=10
Control1=IDC_STATIC,static,1342308352
Control2=IDC_FILTERNAME_EDIT,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308354
Control5=IDC_FILTERLIST_EDIT,edit,1350631492
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_OK_BUTTON,button,1342242817
Control10=IDCANCEL,button,1342242816

[CLS:CPuTTYCSDialog]
Type=0
HeaderFile=PuTTYCSDialog.h
ImplementationFile=PuTTYCSDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_CMDHISTORYCLEAR_BUTTON

