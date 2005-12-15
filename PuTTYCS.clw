; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPuTTYCSDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "puttycs.h"
LastPage=0

ClassCount=8
Class1=CAboutDialog
Class2=CCommandEdit
Class3=CPuTTYCSDialog
Class4=CFilterDialog
Class5=CFiltersDialog
Class6=CPasswordDialog
Class7=CPreferencesDialog
Class8=CPuTTYCSApp

ResourceCount=7
Resource1=IDD_PASSWORD_DIALOG
Resource2=IDD_FILTERS_DIALOG
Resource3=IDD_FILTER_DIALOG
Resource4=IDD_PREFERENCES_DIALOG
Resource5=IDD_PUTTYCS_DIALOG
Resource6=IDD_ABOUT_DIALOG
Resource7=IDM_SYSTRAY_MENU

[CLS:CAboutDialog]
Type=0
BaseClass=CDialog
HeaderFile=AboutDialog.h
ImplementationFile=AboutDialog.cpp
Filter=D
VirtualFilter=dWC
LastObject=CAboutDialog

[CLS:CCommandEdit]
Type=0
BaseClass=CEdit
HeaderFile=CommandEdit.h
ImplementationFile=CommandEdit.cpp
LastObject=CCommandEdit

[CLS:CFilterDialog]
Type=0
BaseClass=CDialog
HeaderFile=FilterDialog.h
ImplementationFile=FilterDialog.cpp
Filter=D
VirtualFilter=dWC
LastObject=CFilterDialog

[CLS:CFiltersDialog]
Type=0
BaseClass=CDialog
HeaderFile=FiltersDialog.h
ImplementationFile=FiltersDialog.cpp
Filter=D
VirtualFilter=dWC
LastObject=CFiltersDialog

[CLS:CPasswordDialog]
Type=0
BaseClass=CDialog
HeaderFile=PasswordDialog.h
ImplementationFile=PasswordDialog.cpp
Filter=D
VirtualFilter=dWC
LastObject=CPasswordDialog

[CLS:CPreferencesDialog]
Type=0
BaseClass=CDialog
HeaderFile=PreferencesDialog.h
ImplementationFile=PreferencesDialog.cpp
Filter=D
VirtualFilter=dWC
LastObject=CPreferencesDialog

[CLS:CPuTTYCSApp]
Type=0
BaseClass=CWinApp
HeaderFile=PuTTYCS.h
ImplementationFile=PuTTYCS.cpp

[CLS:CPuTTYCSDialog]
Type=0
BaseClass=CDialog
HeaderFile=PuTTYCSDialog.h
ImplementationFile=PuTTYCSDialog.cpp
Filter=D
VirtualFilter=dWC
LastObject=CPuTTYCSDialog

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

[DLG:IDD_FILTER_DIALOG]
Type=1
Class=CFilterDialog
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

[DLG:IDD_PASSWORD_DIALOG]
Type=1
Class=CPasswordDialog
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_PASSWORD_CEDIT,edit,1350631584
Control3=IDC_OK_BUTTON,button,1342242817
Control4=IDCANCEL,button,1342242816

[DLG:IDD_PREFERENCES_DIALOG]
Type=1
Class=CPreferencesDialog
ControlCount=21
Control1=IDC_STATIC,button,1342177287
Control2=IDC_TOOLWINDOW_CHECKBOX,button,1342242819
Control3=IDC_ALWAYSONTOP_CHECKBOX,button,1342242819
Control4=IDC_MINIMIZETOSYSTRAY_CHECKBOX,button,1342242819
Control5=IDC_STATIC,static,1342308352
Control6=IDC_TRANSITION_EDIT,edit,1350639744
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,button,1342177287
Control9=IDC_AUTOARRANGE_OFF_RADIO,button,1342308361
Control10=IDC_AUTOARRANGE_CASCADE_RADIO,button,1342177289
Control11=IDC_AUTOARRANGE_TILE_RADIO,button,1342177289
Control12=IDC_AUTOMINIMIZE_CHECKBOX,button,1342242819
Control13=IDC_ARRANGEONSTARTUP_CHECKBOX,button,1342242819
Control14=IDC_UNHIDEONEXIT_CHECKBOX,button,1342242819
Control15=IDC_STATIC,button,1342177287
Control16=IDC_EMULATECOPYPASTE_CHECKBOX,button,1342242819
Control17=IDC_TABCOMPLETION_CHECKBOX,button,1342242819
Control18=IDC_STATIC,button,1342177287
Control19=IDC_SAVEPASSWORD_CHECKBOX,button,1342242819
Control20=IDC_OK_BUTTON,button,1342242817
Control21=IDCANCEL,button,1342242816

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
Control9=IDC_SENDCR_PUSHBUTTON,button,1342246916
Control10=IDC_CMDHISTORYUP_BUTTON,button,1476460544
Control11=IDC_CMDHISTORYDOWN_BUTTON,button,1476464384
Control12=IDC_CMDHISTORYCLEAR_BUTTON,button,1476460544
Control13=IDC_COMMAND_EDIT,edit,1350631492
Control14=IDC_UP_BUTTON,button,1342242816
Control15=IDC_LEFT_BUTTON,button,1342242816
Control16=IDC_CLEAR_BUTTON,button,1342242816
Control17=IDC_RIGHT_BUTTON,button,1342246656
Control18=IDC_DOWN_BUTTON,button,1342242816
Control19=IDC_BREAK_BUTTON,button,1342242816
Control20=IDC_ENDTELNET_BUTTON,button,1342242816
Control21=IDC_ESCAPE_BUTTON,button,1342242816
Control22=IDC_ENTER_BUTTON,button,1342242816
Control23=IDC_SCRIPT_BUTTON,button,1342242816
Control24=IDC_PASSWORD_BUTTON,button,1342242816
Control25=IDC_PREFERENCES_BUTTON,button,1342242816
Control26=IDC_SEND_BUTTON,button,1342242817

[MNU:IDM_SYSTRAY_MENU]
Type=1
Class=?
Command1=IDMI_SYSTRAYOPEN_MENUITEM
Command2=IDMI_SYSTRAYCASCADE_MENUITEM
Command3=IDMI_SYSTRAYTILE_MENUITEM
Command4=IDMI_SYSTRAYMINIMIZE_MENUITEM
Command5=IDMI_SYSTRAYHIDE_MENUITEM
Command6=IDMI_SYSTRAYABOUT_MENUITEM
Command7=IDMI_SYSTRAYEXIT_MENUITEM
CommandCount=7

