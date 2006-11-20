/**
 * PuTTYCSDialog.cpp - PuTTYCS Main Dialog
 *
 * Copyright (c) 2005, 2006 Jason Millard (jsm174@gmail.com)
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * REVISION HISTORY:
 *
 * 11/07/2005: Initial version                       J. Millard
 * 11/17/2005: Added UNICODE support                 J. Millard
 *             Added command history clear button
 *             Added AltGr support
 * 11/18/2005: Fixed AltGr support                   J. Millard
 * 12/06/2005: Added mouse Copy/Paste emulation      J. Millard
 *             Navigation through command history
 *             moves cursor to end of command 
 * 12/15/2005: Added minimize to system tray         J. Millard
 *             Added tab completion
 * 12/19/2005: Added window opacity                  J. Millard
 * 12/21/2005: Fixed password not sending CR         J. Millard
 * 05/27/2006: Improved system tray logic            J. Millard
 *             Added Windows XP style
 *             Added close, backspace, and          
 *             delete buttons
 * 05/30/2006: Implemented MSDN KB135788 for         J. Millard
 *             system tray context menu
 * 11/20/2006: Added support for PuTTYtel and        J. Millard
 *             TuTTY. Added support for user 
 *             defined cascade size. Changed 
 *             scripting to send CR on last line
 *             if CR button is on.
 */

#include "stdafx.h"
#include "PuTTYCS.h"
#include "PuTTYCSDialog.h"
#include "PasswordDialog.h"
#include "PreferencesDialog.h"
#include "FiltersDialog.h"
#include "AboutDialog.h"
#include "Base64.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
 * CPuTTYCSDialog()::CPuTTYCSDialog()
 */

CPuTTYCSDialog::CPuTTYCSDialog(CWnd* pParent /*=NULL*/)
   : CDialog(CPuTTYCSDialog::IDD, pParent)
{      
   //{{AFX_DATA_INIT(CPuTTYCSDialog)
   //}}AFX_DATA_INIT

   m_hIcon = AfxGetApp()->LoadIcon( IDR_MAINFRAME );
   
   /**
    * Fonts
    */

   m_pMarlettNormal = new CFont();

   m_pMarlettNormal->CreatePointFont( 
      100, PUTTYCS_FONT_MARLETT );

   m_pMarlettSmall = new CFont();

   m_pMarlettSmall->CreatePointFont(
      80, PUTTYCS_FONT_MARLETT );

   m_pSymbolSmall = new CFont();

   m_pSymbolSmall->CreatePointFont(
      70, PUTTYCS_FONT_SYMBOL );

   /**
    * Taskbar Notification Icon
    */

   m_pTNI = NULL;

   m_uiTaskbarMessage = 0;

   /**
    * Context Menu
    */

   m_pMenu = new CMenu();

   m_pMenu->LoadMenu( IDM_SYSTRAY_MENU );

   m_bDisablePopup = FALSE;   
}

/**
 * CPuTTYCSDialog()::~CPuTTYCSDialog()
 */

CPuTTYCSDialog::~CPuTTYCSDialog()
{
   SavePreferences();

   /**
    * Fonts
    */

   if ( m_pMarlettNormal )
   {
      delete m_pMarlettNormal;
   }

   if ( m_pMarlettSmall )
   {
      delete m_pMarlettSmall;
   }

   if ( m_pSymbolSmall )
   {
      delete m_pSymbolSmall;
   }

   /**
    * Taskbar Notification Icon
    */

   if ( m_pTNI )
   {
      Shell_NotifyIcon( NIM_DELETE, 
         (NOTIFYICONDATA*) m_pTNI ); 

      delete m_pTNI;
   }

   /**
    * Context Menu
    */

   if ( m_pMenu )
   {
      delete m_pMenu;
   }
}

/**
 * LoadPreferences()
 */

void CPuTTYCSDialog::LoadPreferences()
{
   /**
    * PuTTY filters
    */ 

   m_csaFilters.RemoveAll();

   for ( int loop = 0;
      loop < PUTTYCS_PREF_FILTER_MAX_SIZE; loop++ )
   {     
      CString csAttribute;
      csAttribute.Format( PUTTYCS_PREF_FILTER_ENTRY, loop );

      CString csValue =
         AfxGetApp()->GetProfileString( 
            PUTTYCS_APP_NAME, 
            csAttribute,
            PUTTYCS_EMPTY_STRING );

      if ( !csValue.IsEmpty() )
      {
         m_csaFilters.Add( csValue );
      }
   }

   int size = m_csaFilters.GetSize();

   if ( size == 0 )
   {
      m_csaFilters.Add( PUTTYCS_FILTER_ALL );
      m_iFilter = 0;
   }
   else
   {
      m_iFilter = 
         AfxGetApp()->GetProfileInt(
            PUTTYCS_APP_NAME, PUTTYCS_PREF_FILTER, 0 );

      if ( (m_iFilter + 1) > size )
      {
         m_iFilter = 0;
      }
   }

   /**
    * Command history
    */ 

   m_csaCmdHistory.RemoveAll();

   for ( loop = 0;
      loop < PUTTYCS_PREF_CMDHISTORY_MAX_SIZE; loop++ )
   {  
      CString csAttribute;
      csAttribute.Format( PUTTYCS_PREF_CMDHISTORY_ENTRY, loop );

      CString csValue =
        AfxGetApp()->GetProfileString( 
           PUTTYCS_APP_NAME, 
           csAttribute, 
           PUTTYCS_EMPTY_STRING );

      if ( !csValue.IsEmpty() )
      {
         m_csaCmdHistory.Add( csValue );
      }
   }

   m_iCmdHistory = m_csaCmdHistory.GetSize();
    
   /**
    * Password
    */

   m_iSavePassword = 
      AfxGetApp()->GetProfileInt(
         PUTTYCS_APP_NAME, PUTTYCS_PREF_SAVE_PASSWORD, 0 );

   if ( m_iSavePassword )
   {
      m_csPassword =
         AfxGetApp()->GetProfileString( 
            PUTTYCS_APP_NAME,
            PUTTYCS_PREF_PASSWORD, 
            PUTTYCS_EMPTY_STRING );
   }
   else
   {
      m_csPassword = PUTTYCS_EMPTY_STRING;
   }

   /**
    * Window settings
    */

   m_iToolWindow =
      AfxGetApp()->GetProfileInt(
         PUTTYCS_APP_NAME, PUTTYCS_PREF_WINDOW_TOOL, 1 );

   m_iAlwaysOnTop =
      AfxGetApp()->GetProfileInt(
         PUTTYCS_APP_NAME, PUTTYCS_PREF_WINDOW_ALWAYS_ON_TOP, 1 );

   m_iMinimizeToSysTray =
      AfxGetApp()->GetProfileInt(
         PUTTYCS_APP_NAME, PUTTYCS_PREF_MINIMIZE_TO_SYSTRAY, 1 );

   m_iTransition =
      AfxGetApp()->GetProfileInt(
         PUTTYCS_APP_NAME, PUTTYCS_PREF_WINDOW_TRANSITION, 25 );
  
   m_iOpacity =
      AfxGetApp()->GetProfileInt(
         PUTTYCS_APP_NAME, PUTTYCS_PREF_WINDOW_OPACITY, 
         PUTTYCS_OPACITY_MAX );
   
   /**
    * Auto arrange 
    */

   m_iAutoArrange =
      AfxGetApp()->GetProfileInt(
         PUTTYCS_APP_NAME, PUTTYCS_PREF_AUTO_ARRANGE, 1 );

   m_iAutoMinimize =
      AfxGetApp()->GetProfileInt(
         PUTTYCS_APP_NAME, PUTTYCS_PREF_AUTO_MINIMIZE, 0 );

   m_iArrangeOnStartup =
      AfxGetApp()->GetProfileInt(
         PUTTYCS_APP_NAME, PUTTYCS_PREF_ARRANGE_ON_STARTUP, 0 );

   m_iUnhideOnExit =
      AfxGetApp()->GetProfileInt(
         PUTTYCS_APP_NAME, PUTTYCS_PREF_UNHIDE_ON_EXIT, 1 );

   m_iCascadeWidth = 
      AfxGetApp()->GetProfileInt(
         PUTTYCS_APP_NAME, PUTTYCS_PREF_CASCADE_WIDTH, PUTTYCS_CASCADE_DEFAULT_WIDTH );

   m_iCascadeHeight = 
      AfxGetApp()->GetProfileInt(
         PUTTYCS_APP_NAME, PUTTYCS_PREF_CASCADE_HEIGHT, PUTTYCS_CASCADE_DEFAULT_HEIGHT );

   /**
    * Send CR 
    */

   m_iSendCR =
      AfxGetApp()->GetProfileInt(
         PUTTYCS_APP_NAME, PUTTYCS_PREF_SEND_CR, 1 );

   /**
    * Keyboard/Mouse 
    */
  
   m_iEmulateCopyPaste =
      AfxGetApp()->GetProfileInt(
         PUTTYCS_APP_NAME, PUTTYCS_PREF_EMULATE_COPY_PASTE, 1 );

   m_iTabCompletion =
      AfxGetApp()->GetProfileInt(
         PUTTYCS_APP_NAME, PUTTYCS_PREF_TAB_COMPLETION, 0 );
}

/**
 * SavePreferences()
 */

void CPuTTYCSDialog::SavePreferences()
{
   /**
    * PuTTY filters
    */ 

   for ( int loop = 0; loop < PUTTYCS_PREF_FILTER_MAX_SIZE; loop++ )
   {     
      CString csAttribute;
      csAttribute.Format( PUTTYCS_PREF_FILTER_ENTRY, loop );

      CString csValue = PUTTYCS_EMPTY_STRING;

      if ( loop < m_csaFilters.GetSize() )
      {
         csValue = m_csaFilters.GetAt( loop );
      }

      AfxGetApp()->WriteProfileString(
         PUTTYCS_APP_NAME, csAttribute, csValue );
   }

   AfxGetApp()->WriteProfileInt(
      PUTTYCS_APP_NAME, PUTTYCS_PREF_FILTER, m_iFilter );

   /**
    * Command history
    */ 

   for ( loop = 0;
      loop < PUTTYCS_PREF_CMDHISTORY_MAX_SIZE; loop++ )
   {
      CString csAttribute;
      csAttribute.Format( PUTTYCS_PREF_CMDHISTORY_ENTRY, loop );

      CString csValue = PUTTYCS_EMPTY_STRING;

      if ( loop < m_csaCmdHistory.GetSize() )
      {
         csValue = m_csaCmdHistory.GetAt(loop);
      }

      AfxGetApp()->WriteProfileString(
         PUTTYCS_APP_NAME, csAttribute, csValue );
   }

   /**
    * Password
    */

   AfxGetApp()->WriteProfileInt( PUTTYCS_APP_NAME,
      PUTTYCS_PREF_SAVE_PASSWORD, m_iSavePassword );

   if ( m_iSavePassword )
   {
      AfxGetApp()->WriteProfileString( PUTTYCS_APP_NAME, 
         PUTTYCS_PREF_PASSWORD, m_csPassword );
   }
   else
   {
      AfxGetApp()->WriteProfileString( PUTTYCS_APP_NAME, 
         PUTTYCS_PREF_PASSWORD, PUTTYCS_EMPTY_STRING );
   }

   /**
    * Window settings
    */

   AfxGetApp()->WriteProfileInt( PUTTYCS_APP_NAME, 
      PUTTYCS_PREF_WINDOW_TOOL, m_iToolWindow );

   AfxGetApp()->WriteProfileInt( PUTTYCS_APP_NAME, 
      PUTTYCS_PREF_WINDOW_ALWAYS_ON_TOP, m_iAlwaysOnTop );


   AfxGetApp()->WriteProfileInt( PUTTYCS_APP_NAME, 
      PUTTYCS_PREF_MINIMIZE_TO_SYSTRAY, m_iMinimizeToSysTray );

   AfxGetApp()->WriteProfileInt( PUTTYCS_APP_NAME, 
      PUTTYCS_PREF_WINDOW_TRANSITION, m_iTransition );

   AfxGetApp()->WriteProfileInt( PUTTYCS_APP_NAME, 
      PUTTYCS_PREF_WINDOW_OPACITY, m_iOpacity );

   /**
    * Auto arrange 
    */
  
   AfxGetApp()->WriteProfileInt( PUTTYCS_APP_NAME,
      PUTTYCS_PREF_AUTO_ARRANGE, m_iAutoArrange );

   AfxGetApp()->WriteProfileInt( PUTTYCS_APP_NAME,
      PUTTYCS_PREF_AUTO_MINIMIZE, m_iAutoMinimize );

   AfxGetApp()->WriteProfileInt( PUTTYCS_APP_NAME,
      PUTTYCS_PREF_ARRANGE_ON_STARTUP, m_iArrangeOnStartup );

   AfxGetApp()->WriteProfileInt( PUTTYCS_APP_NAME,
      PUTTYCS_PREF_UNHIDE_ON_EXIT, m_iUnhideOnExit );

   AfxGetApp()->WriteProfileInt( PUTTYCS_APP_NAME,
      PUTTYCS_PREF_CASCADE_WIDTH, m_iCascadeWidth );

   AfxGetApp()->WriteProfileInt( PUTTYCS_APP_NAME,
      PUTTYCS_PREF_CASCADE_HEIGHT, m_iCascadeHeight );

   /**
    * Send CR 
    */

   AfxGetApp()->WriteProfileInt( PUTTYCS_APP_NAME,
      PUTTYCS_PREF_SEND_CR, m_iSendCR );

   /**
    * Keyboard/Mouse
    */
 
   AfxGetApp()->WriteProfileInt( PUTTYCS_APP_NAME,
      PUTTYCS_PREF_TAB_COMPLETION, m_iTabCompletion );  
}

/**
 * DoDataExchange()
 */

void CPuTTYCSDialog::DoDataExchange(CDataExchange* pDX)
{
   CDialog::DoDataExchange(pDX);
   //{{AFX_DATA_MAP(CPuTTYCSDialog)
   DDX_Control(pDX, IDC_COMMAND_EDIT, m_cceCommandEdit);
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPuTTYCSDialog, CDialog)
   //{{AFX_MSG_MAP(CPuTTYCSDialog)
   ON_WM_SYSCOMMAND()
   ON_WM_PAINT()
   ON_MESSAGE(WM_USER_MULTIPLE_INSTANCE, OnMultipleInstance)
   ON_WM_QUERYDRAGICON()   
   ON_COMMAND(IDMI_SYSTRAYABOUT_MENUITEM, OnAboutButton)   
   ON_CBN_SELCHANGE(IDC_FILTERS_COMBOBOX, OnSelChangeFiltersCombobox)
   ON_BN_CLICKED(IDC_CASCADE_BUTTON, OnCascadeButton)   
   ON_BN_CLICKED(IDC_TILE_BUTTON, OnTileButton)
   ON_BN_CLICKED(IDC_MINIMIZE_BUTTON, OnMinimizeButton)
   ON_BN_CLICKED(IDC_HIDE_BUTTON, OnHideButton)
   ON_BN_CLICKED(IDC_FILTERS_BUTTON, OnFiltersButton)
   ON_BN_CLICKED(IDC_SENDCR_PUSHBUTTON, OnSendCRPushButton)   
   ON_BN_CLICKED(IDC_CMDHISTORYUP_BUTTON, OnCmdHistoryUpButton)
   ON_BN_CLICKED(IDC_CMDHISTORYDOWN_BUTTON, OnCmdHistoryDownButton)
   ON_BN_CLICKED(IDC_UP_BUTTON, OnUpButton)
   ON_BN_CLICKED(IDC_DOWN_BUTTON, OnDownButton)
   ON_BN_CLICKED(IDC_RIGHT_BUTTON, OnRightButton)   
   ON_BN_CLICKED(IDC_LEFT_BUTTON, OnLeftButton)
   ON_BN_CLICKED(IDC_CLEAR_BUTTON, OnClearButton)
   ON_BN_CLICKED(IDC_BREAK_BUTTON, OnBreakButton)
   ON_BN_CLICKED(IDC_ENDTELNET_BUTTON, OnEndTelnetButton)
   ON_BN_CLICKED(IDC_ESCAPE_BUTTON, OnEscapeButton)      
   ON_BN_CLICKED(IDC_ENTER_BUTTON, OnEnterButton)
   ON_BN_CLICKED(IDC_PASSWORD_BUTTON, OnPasswordButton)
   ON_BN_CLICKED(IDC_PREFERENCES_BUTTON, OnPreferencesButton)
   ON_BN_CLICKED(IDC_SCRIPT_BUTTON, OnScriptButton)
   ON_BN_CLICKED(IDC_SEND_BUTTON, OnSendButton)  
   ON_MESSAGE(WM_USER_TNI_MESSAGE, OnTrayNotify)      
   ON_WM_HELPINFO()   	
   ON_BN_CLICKED(IDC_CMDHISTORYCLEAR_BUTTON, OnCmdHistoryClearButton)
   ON_COMMAND(IDMI_SYSTRAYOPEN_MENUITEM, OnOpenMenuItem)
   ON_BN_CLICKED(IDC_BACKSPACE_BUTTON, OnBackspaceButton)
   ON_BN_CLICKED(IDC_DELETE_BUTTON, OnDeleteButton)   	         
   ON_BN_CLICKED(IDC_CLOSE_BUTTON, OnCloseButton)
   ON_COMMAND(IDMI_SYSTRAYCASCADE_MENUITEM, OnCascadeButton)
   ON_COMMAND(IDMI_SYSTRAYTILE_MENUITEM, OnTileButton)
   ON_COMMAND(IDMI_SYSTRAYMINIMIZE_MENUITEM, OnMinimizeButton)
   ON_COMMAND(IDMI_SYSTRAYHIDE_MENUITEM, OnHideButton)
   ON_COMMAND(IDMI_SYSTRAYPREFERENCES_MENUITEM, OnPreferencesButton)   
   ON_COMMAND(IDMI_SYSTRAYEXIT_MENUITEM, OnOK)   	
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/**
 * CPuTTYCSDialog::SetSysTrayTip()
 */

void CPuTTYCSDialog::SetSysTrayTip( CString csTip )
{
   DWORD dwMessage = NIM_MODIFY;

   if ( !m_pTNI )
   {
      m_pTNI = new NOTIFYICONDATA;
      
      ZeroMemory(
         m_pTNI, sizeof(NOTIFYICONDATA) );

      m_pTNI->hWnd =
         ((CWnd*) this)->GetSafeHwnd();
      
      m_pTNI->cbSize = sizeof( NOTIFYICONDATA );
      m_pTNI->uCallbackMessage = WM_USER_TNI_MESSAGE;
	   m_pTNI->uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE;
      m_pTNI->hIcon	= m_hIcon;
  	   m_pTNI->uTimeout = 1000;
      m_pTNI->uID = 1;	

      dwMessage = NIM_ADD;
   }

   _tcscpy( m_pTNI->szTip, csTip );  
 
   Shell_NotifyIcon( dwMessage,
      (NOTIFYICONDATA*) m_pTNI ); 
}

/**
 * CPuTTYCSDialog::WindowProc()
 */

LRESULT CPuTTYCSDialog::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
   if ( message == m_uiTaskbarMessage )
   {
      if ( m_pTNI )
      {
         delete m_pTNI;
         m_pTNI = NULL;
      }

      if ( m_iMinimizeToSysTray )
      {
         SetSysTrayTip( PUTTYCS_WINDOW_TITLE_APP );
      }
   }

	return CDialog::WindowProc(message, wParam, lParam);	
}

/**
 * CPuTTYCSDialog::PreTranslateMessage()
 */

BOOL CPuTTYCSDialog::PreTranslateMessage(MSG* pMsg) 
{
   if ( pMsg->message == WM_KEYDOWN )
   {
      if ( pMsg->wParam == VK_ESCAPE )
      {
         pMsg->wParam = NULL;
      } 
      else if ( pMsg->wParam == VK_TAB )
      {
		 if ( m_iTabCompletion )
		 {
            UINT uiCtrlId = 
               ((CWnd*) GetFocus())->GetDlgCtrlID();

            if ( uiCtrlId == IDC_COMMAND_EDIT )
			{           
               CString csCommand = 
                  m_cceCommandEdit.GetText();
                        
               sendCommand( csCommand, true );			   
               pMsg->wParam = NULL;
            }
         }
      }
   }

   return CDialog::PreTranslateMessage(pMsg);
}

/**
 * CPuTTYCSDialog::DestroyWindow()
 */

BOOL CPuTTYCSDialog::DestroyWindow() 
{
   m_bIsClosing = true;

   if ( m_iUnhideOnExit )
   {
      m_obaWindows.RemoveAll();

      ::EnumWindows( enumwindowsProc, (LPARAM) this );
    
      SortWindows();

      for ( int loop = 0;
         loop < m_obaWindows.GetSize(); loop++ )
      {
         CWnd* pWnd =
            (CWnd*) m_obaWindows.GetAt( loop );
             
         if ( !pWnd->IsWindowVisible() )
         { 
            pWnd->ShowWindow( SW_SHOW );
         }
      }
   }
	
	return CDialog::DestroyWindow();
}

/**
 * CPuTTYCSDialog::OnCreate()
 */

int CPuTTYCSDialog::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
   m_uiTaskbarMessage =
      RegisterWindowMessage( PUTTYCS_MSG_TASKBAR_CREATED );
	
	return 0;
}

/**
 * CPuTTYCSDialog::OnInitDialog()
 */

BOOL CPuTTYCSDialog::OnInitDialog()
{
   CDialog::OnInitDialog();

   SetIcon(m_hIcon, TRUE);      
   SetIcon(m_hIcon, FALSE);
    
   m_bIsClosing = false;
   m_bFindAll = false;

   /**
    * Preferences
    */

   LoadPreferences();

   /**
    * PuTTY filters
    */

   for ( int loop = 0; loop < m_csaFilters.GetSize(); loop++ )
   {
      CString csFilter = m_csaFilters.GetAt(loop);

      ((CComboBox*) GetDlgItem(IDC_FILTERS_COMBOBOX))->
         AddString(csFilter.Mid(0, 
            csFilter.Find( PUTTYCS_FILTER_NAME_SEPARATOR)) );
   }

   ((CComboBox*) GetDlgItem(IDC_FILTERS_COMBOBOX))->
      SetCurSel( m_iFilter );            
         
   /**
    * Arrows
    */

   ((CButton*) GetDlgItem(IDC_CMDHISTORYUP_BUTTON))->
      SetFont( m_pMarlettNormal );

   ((CButton*) GetDlgItem(IDC_CMDHISTORYDOWN_BUTTON))->
      SetFont( m_pMarlettNormal );

   ((CButton*) GetDlgItem(IDC_CMDHISTORYCLEAR_BUTTON))->
      SetFont( m_pMarlettSmall );
   
   ((CButton*) GetDlgItem(IDC_UP_BUTTON))->
      SetFont( m_pMarlettNormal );

   ((CButton*) GetDlgItem(IDC_DOWN_BUTTON))->
      SetFont( m_pMarlettNormal );

   ((CButton*) GetDlgItem(IDC_LEFT_BUTTON))->
      SetFont( m_pMarlettNormal );

   ((CButton*) GetDlgItem(IDC_RIGHT_BUTTON))->
      SetFont( m_pMarlettNormal );

   /**
    * Clear button
    */

   ((CButton*) GetDlgItem(IDC_CLEAR_BUTTON))->
      SetFont( m_pMarlettSmall );

   /**
    * Command edit
    */

   m_cceCommandEdit.SetEmulateCopyPaste( 
      m_iEmulateCopyPaste );

   /**
    * Send CR
    */

   ((CButton*) GetDlgItem(IDC_SENDCR_PUSHBUTTON))->
      SetFont( m_pSymbolSmall );
   
   ((CButton*) GetDlgItem(IDC_SENDCR_PUSHBUTTON))->
      SetCheck( m_iSendCR );

   /**
    * System Menu
    */

   CMenu* pMenu = GetSystemMenu( FALSE );

   if (pMenu != NULL)
   {
      pMenu->RemoveMenu( SC_MAXIMIZE, MF_BYCOMMAND );

      pMenu->AppendMenu( MF_SEPARATOR );

      pMenu->AppendMenu( MF_STRING,
         IDM_ABOUT_PUTTYCS, PUTTYCS_WINDOW_TITLE_ABOUT );
   }

   /**
    * Dialog size
    */

   CRect dialogRect;
   GetWindowRect(&dialogRect);

   m_iDialogHeight = dialogRect.Height();

   /**
    * Auto arrange
    */

   if ( m_iArrangeOnStartup )
   {
      OnSelChangeFiltersCombobox();
   }
   
   /**
    * Minimize to SysTray
    */

   if ( m_iMinimizeToSysTray )
   {
      SetSysTrayTip( PUTTYCS_WINDOW_TITLE_APP );
   }

   /**
    * Update dialog
    */

   UpdateDialog();

   return FALSE;
}

/**
 * CPuTTYCSDialog::OnSysCommand()
 */

void CPuTTYCSDialog::OnSysCommand(UINT nID, LPARAM lParam)
{
   UINT nCmd = (nID & 0xFFF0);

   if ( nCmd == IDM_ABOUT_PUTTYCS )
   {
      OnAboutButton();
   }
   else 
   {
      if ( (m_iMinimizeToSysTray) &&
           ((nCmd == SC_MINIMIZE)     
         || (nCmd == SC_CLOSE)) )
      {
         ShowWindow( SW_HIDE );
         SetSysTrayTip( PUTTYCS_WINDOW_TITLE_APP );
      }
      else
      {
         CDialog::OnSysCommand(nID, lParam);
      }
   } 
}

/**
 * CPuTTYCSDialog::OnPaint()
 */

void CPuTTYCSDialog::OnPaint() 
{
   if (IsIconic())
   {
      CPaintDC dc(this); // device context for painting

      SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

      int cxIcon = GetSystemMetrics(SM_CXICON);
      int cyIcon = GetSystemMetrics(SM_CYICON);

      CRect rect;
      GetClientRect(&rect);

      int x = (rect.Width() - cxIcon + 1) / 2;
      int y = (rect.Height() - cyIcon + 1) / 2;
      
      dc.DrawIcon(x, y, m_hIcon);
   }
   else
   {
      CDialog::OnPaint();
   }
}

/**
 * CPuTTYCSDialog::OnQueryDragIcon()
 */

HCURSOR CPuTTYCSDialog::OnQueryDragIcon()
{
   return (HCURSOR) m_hIcon;
}

/**
 * CPuTTYCSDialog::OnHelpInfo()
 */

BOOL CPuTTYCSDialog::OnHelpInfo(HELPINFO* pHelpInfo) 
{
   ShellExecute( NULL, 
                 PUTTYCS_SHELL_EXECUTE_OPEN, 
                 PUTTYCS_URL_HOMEPAGE, 
                 NULL, 
                 NULL, 
                 SW_SHOWNORMAL );   

   return TRUE;
}

/**
 * CPuTTYCSDialog::OnMultipleInstance()
 */

void CPuTTYCSDialog::OnMultipleInstance(WPARAM wParam, LPARAM lParam)
{
   OnOpenMenuItem();
}

/**
 * CPuTTYCSDialog::OnAboutButton()
 */

void CPuTTYCSDialog::OnAboutButton()
{
   m_bDisablePopup = true;

   CAboutDialog dialog;
   dialog.DoModal();

   m_bDisablePopup = false;   
}

/**
 * RefreshDialog();
 */ 

void CPuTTYCSDialog::RefreshDialog()
{
   HWND hWnd =
      ((CWnd*) GetDlgItem( IDC_SEND_BUTTON ))->m_hWnd;
   
   SendMessage(WM_NEXTDLGCTL, (WPARAM) hWnd, TRUE); 

   m_cceCommandEdit.SetFocus();

   ((CButton*) GetDlgItem(IDC_CMDHISTORYUP_BUTTON))->
      EnableWindow( m_csaCmdHistory.GetSize() > 0 );
   
   ((CButton*) GetDlgItem(IDC_CMDHISTORYDOWN_BUTTON))->
      EnableWindow( m_csaCmdHistory.GetSize() > 0 );

   ((CButton*) GetDlgItem(IDC_CMDHISTORYCLEAR_BUTTON))->
      EnableWindow( m_csaCmdHistory.GetSize() > 0 );

   SetForegroundWindow();
}

/**
 * UpdateDialog()
 */

void CPuTTYCSDialog::UpdateDialog()
{
   long windowStyle =
      GetWindowLong( m_hWnd, GWL_EXSTYLE );
  
   CRect dialogRect;
   GetWindowRect(&dialogRect);

   if (m_iToolWindow)
   {       
      windowStyle |= WS_EX_TOOLWINDOW;
      
      dialogRect.bottom =
         dialogRect.top + m_iDialogHeight - 
         (GetSystemMetrics(SM_CYCAPTION) / 2);
     
      SetWindowText( PUTTYCS_WINDOW_TITLE_TOOL );
   }
   else
   {
      windowStyle &= ~WS_EX_TOOLWINDOW;       
     
      dialogRect.bottom =
         dialogRect.top + m_iDialogHeight;      

      SetWindowText( PUTTYCS_WINDOW_TITLE_APP );     
   }

   if ( CPuTTYCSApp::g_pSetLayeredWindowAttributes )
   { 
      windowStyle |= WS_EX_LAYERED;    
   }

   SetWindowLong( m_hWnd, GWL_EXSTYLE, windowStyle );
      
   const CWnd* pLocation = &CWnd::wndNoTopMost;

   if ( m_iAlwaysOnTop )
   {
      pLocation = &CWnd::wndTopMost;
   }

   if ( CPuTTYCSApp::g_pSetLayeredWindowAttributes )
   {
      /**
       * Added delay, because top most PuTTY
       * window does not redraw correctly
       */

      ::Sleep( 20 );

      CPuTTYCSApp::g_pSetLayeredWindowAttributes(
         m_hWnd, 0, m_iOpacity, LWA_ALPHA );
   }

   SetWindowPos( pLocation, 0, 0,
      dialogRect.Width(), dialogRect.Height(), SWP_NOMOVE );   

   RefreshDialog();
}

/**
 * CPuTTYCSDialog::OnOpenMenuItem()
 */ 

void CPuTTYCSDialog::OnOpenMenuItem()
{   
   SendMessage(
      WM_SYSCOMMAND, SC_HOTKEY, (LPARAM) m_hWnd );

   SendMessage(
      WM_SYSCOMMAND, SC_RESTORE, (LPARAM) m_hWnd );         

   ShowWindow( SW_SHOW );

   SetForegroundWindow();
}

/**
 * CPuTTYCSDialog::OnSelChangeFiltersCombobox()
 */

void CPuTTYCSDialog::OnSelChangeFiltersCombobox() 
{
   m_iFilter =
      ((CComboBox*) GetDlgItem(IDC_FILTERS_COMBOBOX))->GetCurSel();   

   if ( (m_iAutoArrange == PUTTYCS_PREF_AUTO_ARRANGE_CASCADE) ||
        (m_iAutoArrange == PUTTYCS_PREF_AUTO_ARRANGE_TILE) )
   {
      if ( m_iAutoMinimize )
      {
         int iFilter= m_iFilter;
        
         m_iFilter = 0;

         OnMinimizeButton();
  
         ::Sleep( 250 );

         m_iFilter = iFilter;
      }

      if ( m_iAutoArrange == PUTTYCS_PREF_AUTO_ARRANGE_CASCADE )
      {
         OnCascadeButton();
      }
      else if ( m_iAutoArrange == PUTTYCS_PREF_AUTO_ARRANGE_TILE )
      {
         OnTileButton();
      }
   }

   RefreshDialog();
}

/**
 * CPuTTYCSDialog::GetAllWindows()
 */ 

CObArray* CPuTTYCSDialog::GetAllWindows()
{
   m_obaWindows.RemoveAll();

   m_bFindAll = true;

   ::EnumWindows( enumwindowsProc, (LPARAM) this );
    
   SortWindows();

   m_bFindAll = false;

   return &m_obaWindows;
}

/**
 * CPuTTYCSDialog::OnCascadeButton
 */ 

void CPuTTYCSDialog::OnCascadeButton() 
{
   int x = 0;
   int y = 0;
   int size = GetSystemMetrics( SM_CYSIZE );

   int offset = size;

   m_obaWindows.RemoveAll();

   ::EnumWindows( enumwindowsProc, (LPARAM) this );
    
   SortWindows();

   for ( int loop = 0;
      loop < m_obaWindows.GetSize(); loop++ )
   {
      CWnd* pWnd =
         (CWnd*) m_obaWindows.GetAt(loop);
          
      if ( (loop % 10) == 0 )
      {     
         x = offset;
         y = size;

         offset += ( size * 8 );
      }
      else
      {
         x += size;
         y += size;
      }
      
      pWnd->SendMessage( WM_SYSCOMMAND, SC_RESTORE, 0 );

      pWnd->ShowWindow( SW_HIDE );
      
      pWnd->SetWindowPos( NULL, x, y, 0, 0, SWP_NOSIZE );

      pWnd->SendMessage( WM_ENTERSIZEMOVE, 0, 0 );

      pWnd->
         SendMessage( WM_SIZE,
                      SIZE_RESTORED, 
                      MAKELPARAM( 
                         m_iCascadeWidth,
                         m_iCascadeHeight) );

      pWnd->SendMessage( WM_EXITSIZEMOVE, 0, 0 );      

      pWnd->SendMessage( WM_SYSCOMMAND, SC_MINIMIZE, 0 );      
      pWnd->SendMessage( WM_SYSCOMMAND, SC_RESTORE, 0 );
   }

   RefreshDialog();      
}

/**
 * CPuTTYCSDialog::OnTileButton()
 */

void CPuTTYCSDialog::OnTileButton() 
{
   int x = 0;
   int y = 0;

   m_obaWindows.RemoveAll();

   ::EnumWindows( enumwindowsProc, (LPARAM) this );
    
   SortWindows();

   int size =
      m_obaWindows.GetSize();

   if ( size > 0 )
   {     
      int maxCols =
         (size / 4) + ((size % 4) > 0);
      
      int maxScreenX = GetSystemMetrics(SM_CXFULLSCREEN);
      int maxScreenY = GetSystemMetrics(SM_CYFULLSCREEN);

      int tileHeight = 
         (maxScreenY / ((size / maxCols) + ((size % maxCols) > 0)));

      int tileWidth = (maxScreenX / maxCols);

      for ( int loop = 0;
         loop < m_obaWindows.GetSize(); loop++ )
      {   
         CWnd* pWnd =
           (CWnd*) m_obaWindows.GetAt(loop);
          
         int offset = GetSystemMetrics( SM_CYSIZE );

         pWnd->
            SendMessage( WM_SYSCOMMAND, SC_RESTORE, 0 );
       
         pWnd->ShowWindow( SW_HIDE );
            
         pWnd->SetWindowPos( NULL, x, y, 0, 0, SWP_NOSIZE );

         x += (tileWidth);
         
         if ( x > (tileWidth * (maxCols - 1)) )
         {
            x = 0;
            y += tileHeight;
         }
            
         pWnd->
            SendMessage( WM_ENTERSIZEMOVE, 0, 0 );

         pWnd->
            SendMessage( WM_SIZE, 
                         SIZE_RESTORED,
                         MAKELPARAM(tileWidth,
                                    tileHeight - 20) );

         pWnd->
            SendMessage( WM_EXITSIZEMOVE, 0, 0 );

         pWnd->
            SendMessage( WM_SYSCOMMAND, SC_MINIMIZE, 0 );

         pWnd->
            SendMessage( WM_SYSCOMMAND, SC_RESTORE, 0 );            
      }         
   }   

   RefreshDialog(); 
}

/**
 * CPuTTYCSDialog::OnMinimizeButton() 
 */ 

void CPuTTYCSDialog::OnMinimizeButton() 
{
   m_obaWindows.RemoveAll();

   ::EnumWindows( enumwindowsProc, (LPARAM) this );
    
   SortWindows();

   for ( int loop = 0;
      loop < m_obaWindows.GetSize(); loop++ )
   {
      CWnd* pWnd =
         (CWnd*) m_obaWindows.GetAt( loop );
             
      if ( !pWnd->IsWindowVisible() )
      {
         pWnd->ShowWindow( SW_SHOW );
      }

      pWnd->
         SendMessage( WM_SYSCOMMAND, SC_MINIMIZE, 0 );
   }

   RefreshDialog();      
}

/**
 * CPuTTYCSDialog::OnHideButton()
 */

void CPuTTYCSDialog::OnHideButton() 
{
   m_obaWindows.RemoveAll();

   ::EnumWindows( enumwindowsProc, (LPARAM) this );
    
   SortWindows();

   for ( int loop = 0;
      loop < m_obaWindows.GetSize(); loop++ )
   {
      CWnd* pWnd =
        (CWnd*) m_obaWindows.GetAt( loop );
             
     if ( pWnd->IsWindowVisible() )
     {
        pWnd->ShowWindow(SW_HIDE);
     }
   }

   RefreshDialog();      
}

/**
 * CPuTTYCSDialog::OnCloseButton()
 */

void CPuTTYCSDialog::OnCloseButton() 
{
   m_obaWindows.RemoveAll();

   ::EnumWindows( enumwindowsProc, (LPARAM) this );
    
   SortWindows();

   int iSize = m_obaWindows.GetSize();

   if ( iSize > 0 )
   {
      if ( MessageBox(PUTTYCS_MESSAGEBOX_CLOSE, 
                      PUTTYCS_APP_NAME, 
                      MB_ICONEXCLAMATION | MB_YESNO) == IDYES )
      {
         for ( int loop = 0; loop < iSize; loop++ )
         { 
            CWnd* pWnd =
               (CWnd*) m_obaWindows.GetAt( loop );

            DWORD dwPid;
            
            GetWindowThreadProcessId( pWnd->m_hWnd, &dwPid);

            if ( dwPid )
            {
               HANDLE hProcess =
                  OpenProcess( PROCESS_ALL_ACCESS, FALSE, dwPid );

               if ( hProcess )
               {            
                  ::TerminateProcess( hProcess, (DWORD) -1 );
               }
            }           
         }
      }
   }
}

/**
 * CPuTTYCSDialog::OnFiltersButton()
 */

void CPuTTYCSDialog::OnFiltersButton() 
{
   m_bDisablePopup = TRUE;

   CFiltersDialog* pDialog =
      new CFiltersDialog();
 
   pDialog->setFilters( &m_csaFilters );
   pDialog->setFilter( m_iFilter );
   
   pDialog->DoModal();

   ((CComboBox*) GetDlgItem(IDC_FILTERS_COMBOBOX))->
      ResetContent();

   for ( int loop = 0; loop < m_csaFilters.GetSize(); loop++)
   {
      CString csFilter = m_csaFilters.GetAt(loop);

      ((CComboBox*) GetDlgItem(IDC_FILTERS_COMBOBOX))->
         AddString( csFilter.Mid(0, 
            csFilter.Find(PUTTYCS_FILTER_NAME_SEPARATOR)) );

      m_iFilter = pDialog->getFilter();

      ((CComboBox*) GetDlgItem(IDC_FILTERS_COMBOBOX))->
         SetCurSel( m_iFilter );                 
   }

   SavePreferences();

   RefreshDialog();

   delete( pDialog );   

   m_bDisablePopup = FALSE;
}

/**
 * CPuTTYCSDialog::OnSendCRPushButton()
 */

void CPuTTYCSDialog::OnSendCRPushButton() 
{
   m_iSendCR = !m_iSendCR;

   ((CButton*) GetDlgItem(IDC_SENDCR_PUSHBUTTON))->
      SetCheck ( m_iSendCR );     

   RefreshDialog();    
}

/**
 * CPuTTYCSDialog::OnCmdHistoryUpButton()
 */ 

void CPuTTYCSDialog::OnCmdHistoryUpButton() 
{   
   m_iCmdHistory--;

   if ( m_iCmdHistory < 0 ) 
   {
      m_iCmdHistory =
         m_csaCmdHistory.GetSize() - 1;
   }

   m_cceCommandEdit.SetText( 
      m_csaCmdHistory.GetAt(m_iCmdHistory) );

   RefreshDialog();
}

/**
 * CPuTTYCSDialog::OnCmdHistoryDownButton()
 */ 

void CPuTTYCSDialog::OnCmdHistoryDownButton() 
{
   m_iCmdHistory++;

   if ( m_iCmdHistory >=
      m_csaCmdHistory.GetSize() )
   {
      m_iCmdHistory = 0;
   }

   m_cceCommandEdit.SetText( 
      m_csaCmdHistory.GetAt(m_iCmdHistory) );

   RefreshDialog();
}

/**
 * CPuTTYCSDialog::OnCmdHistoryClearButton()
 */

void CPuTTYCSDialog::OnCmdHistoryClearButton() 
{
   if ( m_csaCmdHistory.GetSize() > 0 )
   {
      if ( MessageBox( 
         PUTTYCS_MESSAGEBOX_CMDHISTORY,
         PUTTYCS_APP_NAME,
         MB_YESNO | MB_ICONEXCLAMATION) == IDYES )
      {      
         m_csaCmdHistory.RemoveAll();
         m_iCmdHistory = 0;
       
         m_cceCommandEdit.SetText( PUTTYCS_EMPTY_STRING );
      }         
   }

   RefreshDialog();
}

/**
 * CPuTTYCSDialog::OnUpButton()
 */

void CPuTTYCSDialog::OnUpButton() 
{
   sendBuffer( PUTTYCS_SENDKEY_BUTTON_UP );   

   RefreshDialog();   
}

/**
 * CPuTTYCSDialog::OnLeftButton()
 */

void CPuTTYCSDialog::OnLeftButton() 
{
   sendBuffer( PUTTYCS_SENDKEY_BUTTON_LEFT );   

   RefreshDialog();         
}

/**
 * CPuTTYCSDialog::OnRightButton()
 */

void CPuTTYCSDialog::OnRightButton() 
{
   sendBuffer( PUTTYCS_SENDKEY_BUTTON_RIGHT );   

   RefreshDialog();         
}

/**
 * CPuTTYCSDialog::OnDownButton()
 */

void CPuTTYCSDialog::OnDownButton() 
{
   sendBuffer( PUTTYCS_SENDKEY_BUTTON_DOWN );   

   RefreshDialog();      
}

/**
 * CPuTTYCSDialog::OnClearButton()
 */

void CPuTTYCSDialog::OnClearButton() 
{
   sendBuffer( PUTTYCS_SENDKEY_BUTTON_CLEAR ); 

   RefreshDialog();   
}

/**
 * CPuTTYCSDialog::OnBreakButton()
 */

void CPuTTYCSDialog::OnBreakButton() 
{
   sendBuffer( PUTTYCS_SENDKEY_BUTTON_BREAK );   

   RefreshDialog();   
}

/**
 * CPuTTYCSDialog::OnEndTelnetButton()
 */

void CPuTTYCSDialog::OnEndTelnetButton() 
{
   sendBuffer( PUTTYCS_SENDKEY_BUTTON_ENDTELNET );   

   RefreshDialog();
}

/**
 * CPuTTYCSDialog::OnEscapeButton()
 */

void CPuTTYCSDialog::OnEscapeButton() 
{
   sendBuffer( PUTTYCS_SENDKEY_BUTTON_ESCAPE );   

   RefreshDialog();   
}

/**
 * CPuTTYCSDialog::OnEnterButton()
 */

void CPuTTYCSDialog::OnEnterButton() 
{
   sendBuffer( PUTTYCS_SENDKEY_BUTTON_ENTER );   

   RefreshDialog();   
}

/**
 * CPuTTYCSDialog::OnBackspaceButton()
 */

void CPuTTYCSDialog::OnBackspaceButton() 
{
   sendBuffer( PUTTYCS_SENDKEY_BUTTON_BACKSPACE );   

   RefreshDialog();  	
}

/**
 * CPuTTYCSDialog::OnDeleteButton()
 */

void CPuTTYCSDialog::OnDeleteButton() 
{
   sendBuffer( PUTTYCS_SENDKEY_BUTTON_DELETE );   

   RefreshDialog();  		
}

/**
 * CPuTTYCSDialog::OnPasswordButton()
 */

void CPuTTYCSDialog::OnPasswordButton() 
{
   m_bDisablePopup = TRUE;

   CPasswordDialog* pDialog =
      new CPasswordDialog();

   pDialog->setPassword( m_csPassword );
   
   if ( pDialog->DoModal() == IDOK )
   {
      m_csPassword = pDialog->getPassword();

      sendBuffer( 
         CBase64::decode(m_csPassword), false, true );

      SavePreferences();
   }

   RefreshDialog();

   delete( pDialog );

   m_bDisablePopup = FALSE;
}

/**
 * CPuTTYCSDialog::OnPreferencesButton()
 */

void CPuTTYCSDialog::OnPreferencesButton() 
{
   m_bDisablePopup = TRUE;

   CPreferencesDialog* pDialog =
      new CPreferencesDialog( this );

   /**
    * Password 
    */

   pDialog->
      setSavePassword( m_iSavePassword );

   /**
    * Auto arrange
    */

   pDialog->
      setAutoArrange( m_iAutoArrange );

   pDialog->
      setAutoMinimize( m_iAutoMinimize );

   pDialog->
      setArrangeOnStartup( m_iArrangeOnStartup );

   pDialog->
      setUnhideOnExit( m_iUnhideOnExit );

   pDialog->
      setCascadeWidth( m_iCascadeWidth );

   pDialog->
      setCascadeHeight( m_iCascadeHeight );

   /**
    * Window
    */

   pDialog->
      setToolWindow( m_iToolWindow );

   pDialog->
      setAlwaysOnTop( m_iAlwaysOnTop );

   pDialog->
      setMinimizeToSysTray( m_iMinimizeToSysTray );

   pDialog->
      setTransition( m_iTransition );

   pDialog->
      setOpacity(m_iOpacity );

   /**
    * Keyboard/Mouse
    */

   pDialog->
	   setTabCompletion( m_iTabCompletion );

   pDialog->
      setEmulateCopyPaste( m_iEmulateCopyPaste );
 
   if ( pDialog->DoModal() == IDOK )
   {  
      /**
       * Password
       */

      m_iSavePassword =
         pDialog->getSavePassword();

      /**
       * Auto arrange
       */

      m_iAutoArrange =
         pDialog->getAutoArrange();

      m_iAutoMinimize = 
         pDialog->getAutoMinimize();

      m_iArrangeOnStartup =
         pDialog->getArrangeOnStartup();

      m_iUnhideOnExit =
         pDialog->getUnhideOnExit();

      m_iCascadeWidth =
         pDialog->getCascadeWidth();

      m_iCascadeHeight =
         pDialog->getCascadeHeight();
            
      /**
       * Window
       */

      int iToolWindow = m_iToolWindow;
      
      m_iToolWindow =
         pDialog->getToolWindow();

      int iAlwaysOnTop = m_iAlwaysOnTop;

      m_iAlwaysOnTop =
         pDialog->getAlwaysOnTop();

      m_iMinimizeToSysTray =
         pDialog->getMinimizeToSysTray();      

      if ( !m_iMinimizeToSysTray )
      {
         if ( m_pTNI )
         {     
            Shell_NotifyIcon( NIM_DELETE, 
               (NOTIFYICONDATA*) m_pTNI ); 

            delete m_pTNI;
            m_pTNI = NULL;
         }

         if ( !IsWindowVisible() )
         {
            OnOpenMenuItem();
         }
      }
      else
      {
         SetSysTrayTip( PUTTYCS_WINDOW_TITLE_APP );
      }

      int iOpacity = m_iOpacity;

      m_iOpacity = 
         pDialog->getOpacity();

      m_iTransition =
         pDialog->getTransition();

      /**
       * Keyboard/Mouse
       */

	   m_iTabCompletion =
		   pDialog->getTabCompletion();

      m_iEmulateCopyPaste =
         pDialog->getEmulateCopyPaste();
      
      m_cceCommandEdit.SetEmulateCopyPaste( m_iEmulateCopyPaste );
    
      /**
       * Window refresh
       */
      
      if ( (iOpacity != m_iOpacity) ||
           (iToolWindow != m_iToolWindow) ||
           (iAlwaysOnTop != m_iAlwaysOnTop) )
      {                  
         ShowWindow(SW_HIDE);

         UpdateDialog();     

         ShowWindow(SW_SHOW);
      }
      else
      {
         RefreshDialog();
      }
      
      SavePreferences();
   }
   else
   {      
      RefreshDialog();   
   }

   delete( pDialog );   

   m_bDisablePopup = FALSE;
}

/**
 * CPuTTYCSDialog::OnScriptButton()
 */

void CPuTTYCSDialog::OnScriptButton() 
{   
   m_bDisablePopup = TRUE;

   CFileDialog* pDialog = 
      new CFileDialog( true, 
                       NULL, 
                       NULL,
                       OFN_HIDEREADONLY, 
                       PUTTYCS_SCRIPT_FILETYPE, 
                       this );

   pDialog->m_ofn.lpstrTitle =
      PUTTYCS_WINDOW_TITLE_OPEN_SCRIPT;
   
   if ( pDialog->DoModal() == IDOK )
   {     
      FILE* pFile;

      if ( (pFile =
         _tfopen(pDialog->GetPathName(), PUTTYCS_FILE_MODE_READ)) )
      {
         CString csBuffer;

         bool capsLock = false;

         if ( ::GetKeyState(VK_CAPITAL) )
         {
            capsLock = true;

            csBuffer +=
               PUTTYCS_SENDKEY_BUTTON_CAPSLOCK;
         }

         bool firstLine = true;

         TCHAR szLine[65536];
    
         while ( _fgetts(szLine, sizeof( szLine ), pFile) != NULL )       
         {
            if ( !firstLine ) 
            {
               csBuffer += PUTTYCS_SENDKEY_BUTTON_ENTER;
            }
         
            csBuffer += szLine; 
                           
            firstLine = false;
         }

         if ( m_iSendCR )
         {
            csBuffer += PUTTYCS_SENDKEY_BUTTON_ENTER;
         }

         if ( capsLock )
         {
            csBuffer +=
               PUTTYCS_SENDKEY_BUTTON_CAPSLOCK;
         }     

         ShowWindow( SW_HIDE );

         sendBuffer( csBuffer );

         ShowWindow( SW_SHOW );
        
         fclose( pFile );
      }          
   }   

   RefreshDialog(); 

   delete( pDialog );   

   m_bDisablePopup = FALSE;
}

/**
 * CPuTTYCSDialog::OnSendButton()
 */

void CPuTTYCSDialog::OnSendButton() 
{
   CString csCommand;
   GetDlgItemText(IDC_COMMAND_EDIT, csCommand);

   sendCommand( csCommand, false );
}

/**
 * CPuTTYCSDialog::OnTrayNotify()
 */

void CPuTTYCSDialog::OnTrayNotify( WPARAM wParam, LPARAM lParam ) 
{ 
   UINT uID = (UINT) wParam;
   UINT uMsg = (UINT) lParam;
 	
   switch ( uMsg ) 
	{       
	   case WM_LBUTTONDBLCLK:     

         if ( !m_bDisablePopup )
         {
            if ( IsWindowVisible() )
            {
               ShowWindow( SW_HIDE );
            }
            else
            {
               OnOpenMenuItem();
            }
         }

		   break;
	
	   case WM_RBUTTONDOWN:      
	   case WM_CONTEXTMENU:

         CPoint pt;	
    	   GetCursorPos(&pt);     
       
         CMenu* pPopup = m_pMenu->GetSubMenu(0);

         pPopup->
            SetDefaultItem( IDMI_SYSTRAYOPEN_MENUITEM, FALSE );	

         UINT uiEnable =
            (m_bDisablePopup) ? MF_GRAYED : MF_ENABLED;

         pPopup->EnableMenuItem( 
            IDMI_SYSTRAYOPEN_MENUITEM, uiEnable );

         pPopup->EnableMenuItem( 2, MF_BYPOSITION | uiEnable );               

         pPopup->EnableMenuItem( 
            IDMI_SYSTRAYPREFERENCES_MENUITEM, uiEnable );

         pPopup->EnableMenuItem( 
            IDMI_SYSTRAYABOUT_MENUITEM, uiEnable );

         pPopup->EnableMenuItem( 
            IDMI_SYSTRAYEXIT_MENUITEM, uiEnable );
      
         ::SetForegroundWindow( this->m_hWnd );

         pPopup->
            TrackPopupMenu( TPM_BOTTOMALIGN |
                            TPM_LEFTBUTTON |
                            TPM_RIGHTBUTTON,
                            pt.x, pt.y, this );
        
         ::PostMessage( this->m_hWnd, WM_NULL, 0, 0 );

	  	   break;
   } 

   return; 
} 

/**
 * CPuTTYCSDialog::sendCommand( )
 */

void CPuTTYCSDialog::sendCommand( CString csCommand, bool bTab ) 
{
   if ( m_csaCmdHistory.GetSize() == 
      PUTTYCS_PREF_CMDHISTORY_MAX_SIZE )
   {
     m_csaCmdHistory.RemoveAt( 0 ) ;
   }

   CString csTempCommand = csCommand;
   csTempCommand.TrimLeft();
   csTempCommand.TrimRight();

   if (csTempCommand.GetLength() > 0 )
   {
      m_csaCmdHistory.Add( csCommand );    
   }
 
   m_iCmdHistory = m_csaCmdHistory.GetSize();

   m_cceCommandEdit.SetText( PUTTYCS_EMPTY_STRING );

   sendBuffer( csCommand, bTab, true );

   RefreshDialog();  
}

/**
 * CPuTTYCSDialog::sendBuffer()
 */

void CPuTTYCSDialog::sendBuffer( CString csBuffer, bool bTab, bool bParse )
{
   CString csOutput =
      PUTTYCS_SENDKEY_DELAY_0;

   if ( !bParse )
   {
      csOutput += csBuffer;
   }
   else
   {
      bool capsLock = false;

      if ( ::GetKeyState(VK_CAPITAL) )
      {
         capsLock = true;

         csOutput +=
            PUTTYCS_SENDKEY_BUTTON_CAPSLOCK;
      }
    
      for ( int loop = 0; loop < csBuffer.GetLength(); loop++ )
      {
         TCHAR chChar = csBuffer.GetAt(loop);

         if ( chChar == PUTTYCS_SENDKEY_CHAR_PLUS )
         {
            csOutput +=
               PUTTYCS_SENDKEY_BUTTON_PLUS;
         }
         else if ( chChar == PUTTYCS_SENDKEY_CHAR_AT )
         {
            csOutput +=
               PUTTYCS_SENDKEY_BUTTON_AT;
         } 
         else if ( chChar == PUTTYCS_SENDKEY_CHAR_CARET )
         {
            csOutput +=
               PUTTYCS_SENDKEY_BUTTON_CARET;
         }
         else if ( chChar == PUTTYCS_SENDKEY_CHAR_TILDE )
         {
            csOutput +=
               PUTTYCS_SENDKEY_BUTTON_TILDE;
         }
         else if ( chChar == PUTTYCS_SENDKEY_CHAR_LEFTBRACE )
         { 
            csOutput +=
               PUTTYCS_SENDKEY_BUTTON_LEFTBRACE;
         }
         else if ( chChar == PUTTYCS_SENDKEY_CHAR_RIGHTBRACE )
         {
            csOutput +=
               PUTTYCS_SENDKEY_BUTTON_RIGHTBRACE;
         }
         else if ( chChar == PUTTYCS_SENDKEY_CHAR_LEFTPAREN )
         {
            csOutput +=
               PUTTYCS_SENDKEY_BUTTON_LEFTPAREN;
         }
         else if ( chChar == PUTTYCS_SENDKEY_CHAR_RIGHTPAREN )
         {
            csOutput +=
               PUTTYCS_SENDKEY_BUTTON_RIGHTPAREN;
         }
         else if ( chChar == PUTTYCS_SENDKEY_CHAR_PERCENT )
         {
            csOutput +=
               PUTTYCS_SENDKEY_BUTTON_PERCENT;
         }
         else 
         {
            csOutput += chChar;
         }
      }

      if ( capsLock )
      {
         csOutput +=
            PUTTYCS_SENDKEY_BUTTON_CAPSLOCK;
      }

      if ( bTab )
      {
         csOutput +=
            PUTTYCS_SENDKEY_BUTTON_TAB;
      }
      else if ( m_iSendCR )
      {
         csOutput +=
            PUTTYCS_SENDKEY_BUTTON_ENTER;    
      }    
   }
   
   m_obaWindows.RemoveAll();

   ::EnumWindows( enumwindowsProc, (LPARAM) this );    
     
   SortWindows();

   if ( m_obaWindows.GetSize() > 0 )
   {      
      for (int loop = 0; loop < m_obaWindows.GetSize(); loop++)
      {
         CWnd* pWnd =
            (CWnd*) m_obaWindows.GetAt(loop);

         pWnd->SendMessage(
            WM_SYSCOMMAND, SC_HOTKEY, (LPARAM) pWnd->m_hWnd );

         pWnd->SendMessage(
            WM_SYSCOMMAND, SC_RESTORE, (LPARAM) pWnd->m_hWnd );         

         pWnd->ShowWindow( SW_SHOW );

         pWnd->SetForegroundWindow();

         pWnd->SetFocus();
     
         m_skSendKeys.SendKeys( (LPCTSTR) csOutput );
         
         ::Sleep( m_iTransition );            
      }          
   }

   RedrawWindow();
}

/**
 * CPuTTYCSDialog::enumwindowsProc()
 */

BOOL CALLBACK CPuTTYCSDialog::enumwindowsProc( HWND hwnd, LPARAM lParam )
{
   CPuTTYCSDialog* pDialog = (CPuTTYCSDialog*) lParam;

   CObArray* pWindowArray =
      &pDialog->m_obaWindows;

   if ( hwnd == NULL )
   {
      return false;
   }

   TCHAR szClass[300];  

   ::GetClassName( hwnd, szClass, sizeof(szClass) );

   if ( (!_tcscmp(szClass, PUTTYCS_WINDOW_CLASS_PUTTY)) 
     || (!_tcscmp(szClass, PUTTYCS_WINDOW_CLASS_PUTTYTEL)) 
     || (!_tcscmp(szClass, PUTTYCS_WINDOW_CLASS_TUTTY)) 
     || (!_tcscmp(szClass, PUTTYCS_WINDOW_CLASS_PIETTY)) )

   {      
      TCHAR szTitle[300];  
      ::GetWindowText(hwnd, szTitle, sizeof(szTitle));

      CString csEntry =
         ((pDialog->m_bIsClosing) || (pDialog->m_bFindAll)) ? PUTTYCS_FILTER_ALL :
         pDialog->m_csaFilters.GetAt(pDialog->m_iFilter);
     
      csEntry = csEntry.Mid(
         csEntry.Find(PUTTYCS_FILTER_NAME_SEPARATOR) + 2 ) +
            PUTTYCS_FILTER_SEPARATOR;
                
      bool bInclude = false;
      bool bExclude = false;
      
      CString csFilter =
         PUTTYCS_EMPTY_STRING;

      for ( int loop = 0; loop < csEntry.GetLength(); loop++ )
      {
         TCHAR ch = csEntry.GetAt(loop);

         if ( ch == PUTTYCS_FILTER_SEPARATOR )
         {
            if ( !csFilter.IsEmpty() )
            {
               csFilter.TrimLeft();
               csFilter.TrimRight();
            
               if ( (csFilter.GetAt(0) == PUTTYCS_FILTER_INCLUDE) || 
                    (csFilter.GetAt(0) != PUTTYCS_FILTER_EXCLUDE))              
               {
                  if ( !bInclude )
                  {            
                     if ( csFilter.GetAt(0) == PUTTYCS_FILTER_INCLUDE )
                     {
                        csFilter =
                           csFilter.Right( csFilter.GetLength() - 1 );
                     }
            
                     bInclude =
                        (wildcmp(szTitle, (LPCTSTR) csFilter ) != 0);               
                  }                        
               }
               else
               {  
                  if ( !bExclude )
                  {
                     csFilter =
                        csFilter.Right( csFilter.GetLength() - 1 );
            
                     bExclude =
                        (wildcmp( szTitle, (LPCTSTR) csFilter ) != 0);               
                  }
               }

               csFilter =
                  PUTTYCS_EMPTY_STRING;
            }
         }
         else
         {
            csFilter += ch;
         }
      }

      if ( bInclude && !bExclude )
      {    
         pWindowArray->Add( CWnd::FromHandle(hwnd) );
      }              
   }
  
   return true;
}

/**
 * CPuTTYCSDialog::wildcmp()
 */


int CPuTTYCSDialog::wildcmp( const TCHAR* s1, const TCHAR* wild )
{  
   const TCHAR* cp = NULL;
   const TCHAR* mp = NULL;

   while ( (*s1) && 
           (*wild != PUTTYCS_WILDCMP_WILDCARD) ) 
   {
      if ( (*wild != *s1) && 
           (*wild != PUTTYCS_WILDCMP_ANYCHAR) ) 
      {
         return 0;
      }

      wild++;
      s1++;
   }

   while ( *s1 ) 
   {
      if ( *wild == PUTTYCS_WILDCMP_WILDCARD ) 
      {
         if ( !*++wild ) 
         {
            return 1;
         }

         mp = wild;
         cp = s1 + 1;
      } 
      else if ( (*wild == *s1) || 
                (*wild == PUTTYCS_WILDCMP_ANYCHAR) ) 
      {
         wild++;
         s1++;
      }
      else 
      {
         wild = mp;
         s1 = cp++;
      }
   }

   while ( *wild == PUTTYCS_WILDCMP_WILDCARD ) 
   {
      wild++;
   }

   return !*wild;
}

/**
 * CPuTTYCSDialog::SortWindows()
 */

void CPuTTYCSDialog::SortWindows()
{
   std::sort(
      m_obaWindows.GetData(),
      m_obaWindows.GetData() + 
         m_obaWindows.GetSize(),
      Compare );
}

/**
 * CPuTTYCSDialog::Compare()
 */

int CPuTTYCSDialog::Compare( const void *pWndS1, const void *pWndS2 )
{
   CWnd* pWnd1 = (CWnd*) pWndS1;
   CWnd* pWnd2 = (CWnd*) pWndS2;

   CString csS1;
   ((CWnd*) pWnd1)->GetWindowText( csS1 );

   CString csS2;
   ((CWnd*) pWnd2)->GetWindowText( csS2 );
    
   return ( csS1 < csS2 );
}