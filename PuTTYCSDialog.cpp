/**
 * PuTTYCSDialog.cpp - PuTTYCS Main Dialog
 *
 * Copyright (c) 2005 Jason Millard (jsm174@gmail.com)
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
 * 11/05/2005: Initial version                       J. Millard
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
      110, PUTTYCS_FONT_MARLETT );

	m_pMarlettSmall = new CFont();

   m_pMarlettSmall->CreatePointFont(
	   80, PUTTYCS_FONT_MARLETT );

	m_pSymbolSmall = new CFont();

   m_pSymbolSmall->CreatePointFont(
	   80, PUTTYCS_FONT_SYMBOL );
}

/**
 * CPuTTYCSDialog()::~CPuTTYCSDialog()
 */

CPuTTYCSDialog::~CPuTTYCSDialog()
{
   SavePreferences();

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
	         PUTTYCS_APP_NAME, csAttribute, _T("") );

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
	        PUTTYCS_APP_NAME, csAttribute, _T("") );

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
	         PUTTYCS_APP_NAME, PUTTYCS_PREF_PASSWORD, _T("") );
   }
   else
   {
      m_csPassword = _T("");
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

	m_iTransition =
	   AfxGetApp()->GetProfileInt(
	      PUTTYCS_APP_NAME, PUTTYCS_PREF_WINDOW_TRANSITION, 25 );

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

   /**
    * Send CR 
    */

   m_iSendCR =
	   AfxGetApp()->GetProfileInt(
	      PUTTYCS_APP_NAME, PUTTYCS_PREF_SEND_CR, 1 );
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

	   CString csValue = _T("");

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

	   CString csValue = _T("");

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
         PUTTYCS_PREF_PASSWORD, _T("") );
   }

   /**
    * Window settings
    */

   AfxGetApp()->WriteProfileInt( PUTTYCS_APP_NAME, 
      PUTTYCS_PREF_WINDOW_TOOL, m_iToolWindow );

   AfxGetApp()->WriteProfileInt( PUTTYCS_APP_NAME, 
      PUTTYCS_PREF_WINDOW_ALWAYS_ON_TOP, m_iAlwaysOnTop );

   AfxGetApp()->WriteProfileInt( PUTTYCS_APP_NAME, 
      PUTTYCS_PREF_WINDOW_TRANSITION, m_iTransition );

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

   /**
    * Send CR 
    */

   AfxGetApp()->WriteProfileInt( PUTTYCS_APP_NAME,
      PUTTYCS_PREF_SEND_CR, m_iSendCR );
}

/**
 * DoDataExchange()
 */

void CPuTTYCSDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPuTTYCSDialog)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPuTTYCSDialog, CDialog)
	//{{AFX_MSG_MAP(CPuTTYCSDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
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
	ON_WM_CLOSE()
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPuTTYCSDialog message handlers

/**
 * PreTranslateMessage()
 */

BOOL CPuTTYCSDialog::PreTranslateMessage(MSG* pMsg) 
{
   if ( pMsg->message == WM_KEYDOWN )
   {
      if ( pMsg->wParam==VK_ESCAPE )
      {
	      pMsg->wParam = NULL;
      } 
   }

	return CDialog::PreTranslateMessage(pMsg);
}

/**
 * OnInitDialog()
 */

BOOL CPuTTYCSDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

 	SetIcon(m_hIcon, TRUE);		
	SetIcon(m_hIcon, FALSE);
    
   m_bIsClosing = false;

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

   UpdateDialog();

   return FALSE;
}

/**
 * CPuTTYCSDialog::OnSysCommand()
 */

void CPuTTYCSDialog::OnSysCommand(UINT nID, LPARAM lParam)
{
  	if ((nID & 0xFFF0) == IDM_ABOUT_PUTTYCS)
	{
		CAboutDialog dialog;
		dialog.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
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
                 "open", 
                 PUTTYCS_URL_HOMEPAGE, 
                 NULL, 
                 NULL, 
                 SW_SHOWNORMAL );	

   return TRUE;
}

/**
 * RefreshDialog();
 */ 

void CPuTTYCSDialog::RefreshDialog()
{
   HWND hWnd =
      ((CWnd*) GetDlgItem( IDC_SEND_BUTTON ))->m_hWnd;
   
   SendMessage(WM_NEXTDLGCTL, (WPARAM) hWnd, TRUE); 

   ((CEdit*) GetDlgItem( IDC_COMMAND_EDIT) )->SetFocus();    

   ((CButton*) GetDlgItem(IDC_CMDHISTORYUP_BUTTON))->
      EnableWindow( m_csaCmdHistory.GetSize() > 0 );
	
	((CButton*) GetDlgItem(IDC_CMDHISTORYDOWN_BUTTON))->
      EnableWindow( m_csaCmdHistory.GetSize() > 0 );

   SetForegroundWindow();
}

/**
 * UpdateDialog()
 */

void CPuTTYCSDialog::UpdateDialog()
{
   CRect dialogRect;
   GetWindowRect(&dialogRect);

   long windowStyle =
      GetWindowLong( m_hWnd, GWL_EXSTYLE );

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

   SetWindowLong( m_hWnd, GWL_EXSTYLE, windowStyle );
		
   const CWnd* pLocation = &CWnd::wndNoTopMost;

   if ( m_iAlwaysOnTop )
   {
      pLocation = &CWnd::wndTopMost;
   }

   SetWindowPos( pLocation, 0, 0,
      dialogRect.Width(), dialogRect.Height(), SWP_NOMOVE );	

   RefreshDialog();
}

/**
 * CPuTTYCSDialog::OnClose()
 */

void CPuTTYCSDialog::OnClose() 
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

   CDialog::OnClose();
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
  
		  ::Sleep(250);

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
 * OnCascadeButton
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
                         PUTTYCS_CASCADE_DIMENSION_WIDTH,
                         PUTTYCS_CASCADE_DIMENSION_HEIGHT) );

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
                         MAKELPARAM( tileWidth,
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
 * CPuTTYCSDialog::OnFiltersButton()
 */

void CPuTTYCSDialog::OnFiltersButton() 
{
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

   ((CEdit*) GetDlgItem(IDC_COMMAND_EDIT))->
      SetWindowText( m_csaCmdHistory.GetAt(m_iCmdHistory) );

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

   ((CEdit*) GetDlgItem(IDC_COMMAND_EDIT))->
      SetWindowText( m_csaCmdHistory.GetAt(m_iCmdHistory) );

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
 * CPuTTYCSDialog::OnPasswordButton()
 */

void CPuTTYCSDialog::OnPasswordButton() 
{
   CPasswordDialog* pDialog =
      new CPasswordDialog();

	pDialog->setPassword( m_csPassword );
	
	if ( pDialog->DoModal() == IDOK )
	{
		m_csPassword = pDialog->getPassword();

      sendBuffer( 
         CBase64::decode(m_csPassword), true );

      SavePreferences();
	}

	RefreshDialog();

 	delete( pDialog );
}

/**
 * CPuTTYCSDialog::OnPreferencesButton()
 */

void CPuTTYCSDialog::OnPreferencesButton() 
{
   CPreferencesDialog* pDialog =
      new CPreferencesDialog();

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

   /**
    * Window
    */

   pDialog->
      setToolWindow( m_iToolWindow );

   pDialog->
      setAlwaysOnTop( m_iAlwaysOnTop );

   pDialog->
      setTransition( m_iTransition );

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
            
      /**
       * Window
       */

      int iToolWindow = m_iToolWindow;
      
      m_iToolWindow =
         pDialog->getToolWindow();

      int iAlwaysOnTop = m_iAlwaysOnTop;

	   m_iAlwaysOnTop =
         pDialog->getAlwaysOnTop();

      
	   m_iTransition =
         pDialog->getTransition();

      /**
       * Window refresh
       */

      if ( (iToolWindow != m_iToolWindow) ||
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
}

/**
 * CPuTTYCSDialog::OnScriptButton()
 */

void CPuTTYCSDialog::OnScriptButton() 
{	
   CFileDialog* pDialog = 
      new CFileDialog( true, 
	                    NULL, 
					        NULL,
	                    OFN_HIDEREADONLY, 
					        PUTTYCS_SCRIPT_FILETYPE, 
					        this );

   pDialog->m_ofn.lpstrTitle = "Open PuTTYCS Script";
   
   if ( pDialog->DoModal() == IDOK )
   {	  
      FILE* pFile;

      if ( (pFile = fopen(pDialog->GetPathName(), "r")) )
      {
     	   CString csBuffer;

		   bool capsLock = false;

         if ( ::GetKeyState(VK_CAPITAL) )
         {
            capsLock = true;

            csBuffer +=
               PUTTYCS_SENDKEY_BUTTON_CAPSLOCK;
         }

         char szLine[65536];
    
         while ( fgets(szLine, sizeof( szLine ), pFile) != NULL )		 
         {
		      csBuffer += szLine;
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
}

/**
 * CPuTTYCSDialog::OnSendButton()
 */

void CPuTTYCSDialog::OnSendButton() 
{
   if ( m_csaCmdHistory.GetSize() == 
      PUTTYCS_PREF_CMDHISTORY_MAX_SIZE )
   {
	  m_csaCmdHistory.RemoveAt( 0 ) ;
   }

   CString csCommand;
   GetDlgItemText(IDC_COMMAND_EDIT, csCommand);
 
   CString csTempCommand = csCommand;
   csTempCommand.TrimLeft();
   csTempCommand.TrimRight();


   if (csTempCommand.GetLength() > 0 )
   {
      m_csaCmdHistory.Add( csCommand );    
   }
 
   m_iCmdHistory = m_csaCmdHistory.GetSize();
   
   ((CEdit*) GetDlgItem(IDC_COMMAND_EDIT))->
      SetWindowText("");

   sendBuffer( csCommand, true );

   RefreshDialog();  
}

/**
 * CPuTTYCSDialog::sendBuffer()
 */

void CPuTTYCSDialog::sendBuffer( CString csBuffer, bool parse )
{
   CString csOutput =
      PUTTYCS_SENDKEY_DELAY_0;

   if ( !parse )
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
	      char ch = csBuffer.GetAt(loop);

         if ( ch == PUTTYCS_SENDKEY_CHAR_PLUS )
         {
            csOutput +=
               PUTTYCS_SENDKEY_BUTTON_PLUS;
         }
	      else if ( ch == PUTTYCS_SENDKEY_CHAR_AT )
         {
		      csOutput +=
               PUTTYCS_SENDKEY_BUTTON_AT;
         } 
	      else if ( ch == PUTTYCS_SENDKEY_CHAR_CARET )
         {
		      csOutput +=
               PUTTYCS_SENDKEY_BUTTON_CARET;
         }
	      else if ( ch == PUTTYCS_SENDKEY_CHAR_TILDE )
         {
		      csOutput +=
               PUTTYCS_SENDKEY_BUTTON_TILDE;
         }
	      else if ( ch == PUTTYCS_SENDKEY_CHAR_LEFTBRACE )
         { 
		      csOutput +=
               PUTTYCS_SENDKEY_BUTTON_LEFTBRACE;
         }
	      else if ( ch == PUTTYCS_SENDKEY_CHAR_RIGHTBRACE )
         {
            csOutput +=
               PUTTYCS_SENDKEY_BUTTON_RIGHTBRACE;
         }
	      else if ( ch == PUTTYCS_SENDKEY_CHAR_LEFTPAREN )
         {
            csOutput +=
               PUTTYCS_SENDKEY_BUTTON_LEFTPAREN;
         }
	      else if ( ch == PUTTYCS_SENDKEY_CHAR_RIGHTPAREN )
         {
            csOutput +=
               PUTTYCS_SENDKEY_BUTTON_RIGHTPAREN;
         }
	      else if ( ch == PUTTYCS_SENDKEY_CHAR_PERCENT )
         {
		      csOutput +=
               PUTTYCS_SENDKEY_BUTTON_PERCENT;
         }
	      else 
         {
		      csOutput += ch;
         }
      }

	   if ( capsLock )
      {
	      csOutput +=
            PUTTYCS_SENDKEY_BUTTON_CAPSLOCK;
      }

	   if ( m_iSendCR )
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
	  
   	   m_skSendKeys.SendKeys( (LPCSTR) csOutput );
	 	  
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

   if ( !_tcscmp(szClass, PUTTYCS_WINDOW_CLASS_PUTTY) )
   {	   
      TCHAR szTitle[300];  
      ::GetWindowText(hwnd, szTitle, sizeof(szTitle));

	   CString csEntry =
	      (pDialog->m_bIsClosing) ? PUTTYCS_FILTER_ALL :
	      pDialog->m_csaFilters.GetAt(pDialog->m_iFilter);
	  
	   csEntry = csEntry.Mid(
         csEntry.Find(PUTTYCS_FILTER_NAME_SEPARATOR) + 2 ) +
            PUTTYCS_FILTER_SEPARATOR;
      	  	  
	   bool bInclude = false;
	   bool bExclude = false;
      
	   CString csFilter = "";

	   for ( int loop = 0; loop < csEntry.GetLength(); loop++ )
      {
	      char ch = csEntry.GetAt(loop);

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
                        (wildcmp(szTitle, csFilter ) != 0);				   
                  }								
               }
			      else
               {  
                  if ( !bExclude )
                  {
			            csFilter =
				            csFilter.Right( csFilter.GetLength() - 1 );
				
				         bExclude = (wildcmp(szTitle, csFilter ) != 0);				   
                  }
               }

			      csFilter = "";
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

int CPuTTYCSDialog::wildcmp( const char *s1, const char *wild )
{  
   const char *cp = NULL;
   const char *mp = NULL;

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