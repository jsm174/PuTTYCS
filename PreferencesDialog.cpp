/**
 * PreferencesDialog.cpp - PuTTYCS Preferences Dialog
 *
 * Copyright (c) 2005 - 2008 Jason Millard (jsm174@gmail.com)
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
 * 12/06/2005: Added mouse Copy/Paste emulation      J. Millard
 * 12/15/2005: Added minimize to system tray         J. Millard
 *             Updated Help/F1 to go visit website   
 *             Added tab completion
 * 12/19/2005: Added window opacity                  J. Millard
 * 11/20/2006: Added support for user defined        J. Millard
 *             cascade size
 * 06/21/2007: Added scroll command history using    J. Millard
 *             up/down arrow keys
 *             Added check for PuTTYCS update
 *             Added run on system startup   
 * 02/29/2008: Added tiling methods                  J. Millard
 *             Added post send transition delay     
 *             Rearranged dialog
 */

#include "stdafx.h"
#include "PuTTYCS.h"
#include "PuTTYCSDialog.h"
#include "PreferencesDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
 * CPreferencesDialog::CPreferencesDialog()
 */

CPreferencesDialog::CPreferencesDialog(CWnd* pParent /*=NULL*/)
   : CDialog(CPreferencesDialog::IDD, pParent)
{
   //{{AFX_DATA_INIT(CPreferencesDialog)
      // NOTE: the ClassWizard will add member initialization here
   //}}AFX_DATA_INIT
}

/**
 * CPreferencesDialog::CPreferencesDialog()
 */

void CPreferencesDialog::DoDataExchange(CDataExchange* pDX)
{
   CDialog::DoDataExchange(pDX);
   //{{AFX_DATA_MAP(CPreferencesDialog)
      // NOTE: the ClassWizard will add DDX and DDV calls here
   //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPreferencesDialog, CDialog)
   //{{AFX_MSG_MAP(CPreferencesDialog)
   ON_BN_CLICKED(IDC_SAVEPASSWORD_CHECKBOX, OnSavePasswordCheckbox)  
   ON_BN_CLICKED(IDC_AUTOMINIMIZE_CHECKBOX, OnAutoMinimizeCheckbox)
   ON_BN_CLICKED(IDC_ARRANGEONSTARTUP_CHECKBOX, OnArrangeOnStartupCheckbox)
   ON_BN_CLICKED(IDC_UNHIDEONEXIT_CHECKBOX, OnUnhideOnExitCheckbox)   
   ON_BN_CLICKED(IDC_TOOLWINDOW_CHECKBOX, OnToolWindowCheckbox)
   ON_BN_CLICKED(IDC_ALWAYSONTOP_CHECKBOX, OnAlwaysOnTopCheckbox)   
   ON_EN_CHANGE(IDC_TRANSITION_EDIT, OnChangeTransition)      
   ON_EN_CHANGE(IDC_POST_SEND_DELAY_EDIT, OnChangePostSendDelay)      
   ON_BN_CLICKED(IDC_EMULATECOPYPASTE_CHECKBOX, OnEmulateCopyPasteCheckbox)
   ON_BN_CLICKED(IDC_CMDHISTORYSCROLLTHROUGH_CHECKBOX, OnCmdHistoryScrollThroughCheckbox)
   ON_BN_CLICKED(IDC_TABCOMPLETION_CHECKBOX, OnTabCompletionCheckbox)   
   ON_BN_CLICKED(IDC_MINIMIZETOSYSTRAY_CHECKBOX, OnMinimizeToSysTrayCheckbox)    	
   ON_BN_CLICKED(IDC_RUNONSYSTEMSTARTUP_CHECKBOX, OnRunOnSystemStartupCheckbox)
   ON_BN_CLICKED(IDC_CHECKFORUPDATES_CHECKBOX, OnCheckForUpdatesCheckbox)
	ON_EN_CHANGE(IDC_CASCADE_HEIGHT_EDIT, OnChangeCascadeHeightEdit)
	ON_EN_CHANGE(IDC_CASCADE_WIDTH_EDIT, OnChangeCascadeWidthEdit)
   ON_BN_CLICKED(IDC_AUTOARRANGE_OFF_RADIO, OnAutoArrangeRadio)
   ON_BN_CLICKED(IDC_AUTOARRANGE_CASCADE_RADIO, OnAutoArrangeRadio)   
   ON_BN_CLICKED(IDC_AUTOARRANGE_TILE_RADIO, OnAutoArrangeRadio)
   ON_BN_CLICKED(IDC_TILEMETHOD_VERTICAL_RADIO, OnTileMethodRadio)
   ON_BN_CLICKED(IDC_TILEMETHOD_HORIZONTAL_RADIO, OnTileMethodRadio)   
   ON_BN_CLICKED(IDC_TILEMETHOD_CLASSIC_RADIO, OnTileMethodRadio)
	ON_BN_CLICKED(IDC_FIND_BUTTON, OnFindButton)
   ON_BN_CLICKED(IDC_OK_BUTTON, OnOKButton)
   ON_WM_HSCROLL()  
   ON_WM_HELPINFO()         
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/**
 * CPreferencesDialog::getAutoArrange()
 */

int CPreferencesDialog::getAutoArrange()
{
   return m_iAutoArrange;
}

/**
 * CPreferencesDialog::setAutoArrange()
 */

void CPreferencesDialog::setAutoArrange( int iAutoArrange )
{
   m_iAutoArrange = iAutoArrange;
}

/**
 * CPreferencesDialog::getAutoMinimize()
 */

int CPreferencesDialog::getAutoMinimize()
{
   return m_iAutoMinimize;
}

/**
 * CPreferencesDialog::setAutoMinimize()
 */

void CPreferencesDialog::setAutoMinimize( int iAutoMinimize )
{
   m_iAutoMinimize = iAutoMinimize;
}

/**
 * CPreferencesDialog::getArrangeOnStartup()
 */

int CPreferencesDialog::getArrangeOnStartup()
{
   return m_iArrangeOnStartup;
}

/**
 * CPreferencesDialog::setArrangeOnStartup()
 */

void CPreferencesDialog::setArrangeOnStartup( int iArrangeOnStartup )
{
   m_iArrangeOnStartup = iArrangeOnStartup;
}

/**
 * CPreferencesDialog::getTileMethod()
 */

int CPreferencesDialog::getTileMethod()
{
   return m_iTileMethod;
}

/**
 * CPreferencesDialog::setTileMethod()
 */

void CPreferencesDialog::setTileMethod( int iTileMethod)
{
   m_iTileMethod = iTileMethod;
}

/**
 * CPreferencesDialog::getCascadeWidth()
 */

int CPreferencesDialog::getCascadeWidth()
{
   return m_iCascadeWidth;
}

/**
 * CPreferencesDialog::setCascadeWidth()
 */

void CPreferencesDialog::setCascadeWidth( int iCascadeWidth )
{
   m_iCascadeWidth = iCascadeWidth;
}

/**
 * CPreferencesDialog::getCascadeHeight()
 */

int CPreferencesDialog::getCascadeHeight()
{
   return m_iCascadeHeight;
}

/**
 * CPreferencesDialog::setCascadeHeight()
 */

void CPreferencesDialog::setCascadeHeight( int iCascadeHeight )
{
   m_iCascadeHeight = iCascadeHeight;
}

/**
 * CPreferencesDialog::getUnhideOnExit()
 */

int CPreferencesDialog::getUnhideOnExit()
{
   return m_iUnhideOnExit;
}

/**
 * CPreferencesDialog::setUnhideOnExit()
 */

void CPreferencesDialog::setUnhideOnExit( int iUnhideOnExit )
{
   m_iUnhideOnExit = iUnhideOnExit;
}

/**
 * CPreferencesDialog::getToolWindow()
 */

int CPreferencesDialog::getToolWindow()
{
   return m_iToolWindow;
}

/**
 * CPreferencesDialog::setToolWindow()
 */

void CPreferencesDialog::setToolWindow( int iToolWindow )
{
   m_iToolWindow = iToolWindow;
}

/**
 * CPreferencesDialog::getAlwaysOnTop()
 */

int CPreferencesDialog::getAlwaysOnTop()
{
   return m_iAlwaysOnTop;
}

/**
 * CPreferencesDialog::setAlwaysOnTop()
 */

void CPreferencesDialog::setAlwaysOnTop( int iAlwaysOnTop )
{
   m_iAlwaysOnTop = iAlwaysOnTop;
}

/**
 * CPreferencesDialog::getMinimizeToSysTray()
 */

int CPreferencesDialog::getMinimizeToSysTray()
{
   return m_iMinimizeToSysTray;
}

/**
 * CPreferencesDialog::setMinimizeToSysTray()
 */

void CPreferencesDialog::setMinimizeToSysTray( int iMinimizeToSysTray )
{
   m_iMinimizeToSysTray = iMinimizeToSysTray;
}

/**
 * CPreferencesDialog::getOpacity()
 */

int CPreferencesDialog::getOpacity()
{
   return m_iOpacity;
}

/**
 * CPreferencesDialog::setOpacity()
 */

void CPreferencesDialog::setOpacity( int iOpacity )
{
   m_iOpacity = iOpacity;
}

/**
 * CPreferencesDialog::getTabCompletion()
 */

int CPreferencesDialog::getTabCompletion()
{
   return m_iTabCompletion;
}

/**
 * CPreferencesDialog::setTabCompletion()
 */

void CPreferencesDialog::setTabCompletion( int iTabCompletion )
{
   m_iTabCompletion = iTabCompletion;
}

/**
 * CPreferencesDialog::getCmdHistoryScrollThrough()
 */

int CPreferencesDialog::getCmdHistoryScrollThrough()
{
   return m_iCmdHistoryScrollThrough;
}

/**
 * CPreferencesDialog::setCmdHistoryScrollThrough()
 */

void CPreferencesDialog::setCmdHistoryScrollThrough( int iCmdHistoryScrollThrough )
{
   m_iCmdHistoryScrollThrough = iCmdHistoryScrollThrough;
}

/**
 * CPreferencesDialog::getEmulateCopyPaste()
 */

int CPreferencesDialog::getEmulateCopyPaste()
{
   return m_iEmulateCopyPaste;
}

/**
 * CPreferencesDialog::setEmulateCopyPaste()
 */

void CPreferencesDialog::setEmulateCopyPaste( int iEmulateCopyPaste )
{
   m_iEmulateCopyPaste = iEmulateCopyPaste;
}

/**
 * CPreferencesDialog::getTransition()
 */

int CPreferencesDialog::getTransition()
{
   return m_iTransition;
}

/**
 * CPreferencesDialog::setTransition()
 */

void CPreferencesDialog::setTransition( int iTransition )
{
   m_iTransition = iTransition;
}

/**
 * CPreferencesDialog::getPostSendDelay()
 */

int CPreferencesDialog::getPostSendDelay()
{
   return m_iPostSendDelay;
}

/**
 * CPreferencesDialog::setPostSendDelay()
 */

void CPreferencesDialog::setPostSendDelay( int iPostSendDelay )
{
   m_iPostSendDelay = iPostSendDelay;
}

/** 
 * CPreferencesDialog::getSavePassword()
 */

int CPreferencesDialog::getSavePassword()
{
   return m_iSavePassword;
}

/** 
 * CPreferencesDialog::setSavePassword()
 */

void CPreferencesDialog::setSavePassword( int iSavePassword )
{
   m_iSavePassword = iSavePassword;
}

/**
 * CPreferencesDialog::getRunOnSystemStartup()
 */

int CPreferencesDialog::getRunOnSystemStartup()
{
   return m_iRunOnSystemStartup;
}

/**
 * CPreferencesDialog::setRunOnSystemStartup()
 */

void CPreferencesDialog::setRunOnSystemStartup( int iRunOnSystemStartup )
{
   m_iRunOnSystemStartup = iRunOnSystemStartup;
}

/**
 * CPreferencesDialog::getCheckForUpdates()
 */

int CPreferencesDialog::getCheckForUpdates()
{
   return m_iCheckForUpdates;
}

/**
 * CPreferencesDialog::setCheckForUpdates()
 */

void CPreferencesDialog::setCheckForUpdates( int iCheckForUpdates )
{
   m_iCheckForUpdates = iCheckForUpdates;
}

/**
 * CPreferencesDialog::OnHelpInfo()
 */

BOOL CPreferencesDialog::OnHelpInfo(HELPINFO* pHelpInfo) 
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
 * CPreferencesDialog::OnInitDialog()
 */

BOOL CPreferencesDialog::OnInitDialog() 
{
   CDialog::OnInitDialog();
   
   CheckDlgButton( IDC_SAVEPASSWORD_CHECKBOX, 
      m_iSavePassword );

   CheckDlgButton( IDC_AUTOARRANGE_OFF_RADIO,
      (m_iAutoArrange == PUTTYCS_PREF_AUTO_ARRANGE_OFF) );

   CheckDlgButton( IDC_AUTOARRANGE_CASCADE_RADIO, 
      (m_iAutoArrange == PUTTYCS_PREF_AUTO_ARRANGE_CASCADE) );

   CheckDlgButton( IDC_AUTOARRANGE_TILE_RADIO, 
      (m_iAutoArrange == PUTTYCS_PREF_AUTO_ARRANGE_TILE) );

   CheckDlgButton( IDC_AUTOMINIMIZE_CHECKBOX,
      m_iAutoMinimize );

   CheckDlgButton( IDC_ARRANGEONSTARTUP_CHECKBOX, 
      m_iArrangeOnStartup );

   CheckDlgButton( IDC_UNHIDEONEXIT_CHECKBOX, 
      m_iUnhideOnExit );

   CheckDlgButton( IDC_TOOLWINDOW_CHECKBOX, 
      m_iToolWindow );

   CheckDlgButton( IDC_ALWAYSONTOP_CHECKBOX, 
      m_iAlwaysOnTop );

   CheckDlgButton( IDC_MINIMIZETOSYSTRAY_CHECKBOX, 
      m_iMinimizeToSysTray );

   CheckDlgButton( IDC_TILEMETHOD_VERTICAL_RADIO, 
      (m_iTileMethod == PUTTYCS_PREF_TILE_METHOD_VERTICAL) );

   CheckDlgButton( IDC_TILEMETHOD_HORIZONTAL_RADIO, 
      (m_iTileMethod == PUTTYCS_PREF_TILE_METHOD_HORIZONTAL) );

   CheckDlgButton( IDC_TILEMETHOD_CLASSIC_RADIO, 
      (m_iTileMethod == PUTTYCS_PREF_TILE_METHOD_CLASSIC) );

   SetDlgItemInt( IDC_CASCADE_WIDTH_EDIT, 
      m_iCascadeWidth );

   SetDlgItemInt( IDC_CASCADE_HEIGHT_EDIT, 
      m_iCascadeHeight );

   if ( CPuTTYCSApp::g_pSetLayeredWindowAttributes )
   {
      ((CSliderCtrl*)GetDlgItem(IDC_OPACITY_SLIDER))->
         SetRange( PUTTYCS_OPACITY_MIN, PUTTYCS_OPACITY_MAX );

      ((CSliderCtrl*)GetDlgItem(IDC_OPACITY_SLIDER))->
         SetPos( m_iOpacity );
   }
   else
   {
      ((CStatic*)GetDlgItem(IDC_OPACITY1_STATIC))->
         ShowWindow( SW_HIDE );
      
      ((CSliderCtrl*)GetDlgItem(IDC_OPACITY_SLIDER))->
         ShowWindow( SW_HIDE );
      
      ((CStatic*)GetDlgItem(IDC_OPACITY2_STATIC))->
         ShowWindow( SW_HIDE );
   }

   CheckDlgButton( IDC_TABCOMPLETION_CHECKBOX, 
      m_iTabCompletion );
 
   CheckDlgButton( IDC_CMDHISTORYSCROLLTHROUGH_CHECKBOX, 
      m_iCmdHistoryScrollThrough );

   CheckDlgButton( IDC_EMULATECOPYPASTE_CHECKBOX, 
      m_iEmulateCopyPaste );

   SetDlgItemInt( IDC_TRANSITION_EDIT, 
      m_iTransition );

   SetDlgItemInt( IDC_POST_SEND_DELAY_EDIT, 
      m_iPostSendDelay );

   CheckDlgButton( IDC_RUNONSYSTEMSTARTUP_CHECKBOX, 
      m_iRunOnSystemStartup );

   CheckDlgButton( IDC_CHECKFORUPDATES_CHECKBOX, 
      m_iCheckForUpdates );

   UpdateDialog();

   return TRUE;  
}

/**
 * CPreferencesDialog::UpdateDialog()
 */ 

void CPreferencesDialog::UpdateDialog()
{   
   ((CButton*) GetDlgItem(IDC_AUTOMINIMIZE_CHECKBOX))->
      EnableWindow( (m_iAutoArrange != 1) );

   ((CButton*) GetDlgItem(IDC_ARRANGEONSTARTUP_CHECKBOX))->
      EnableWindow( (m_iAutoArrange != 1) );

   ((CButton*) GetDlgItem(IDC_OK_BUTTON))->
      EnableWindow( (m_iTransition >= 1) && 
                    (m_iTransition <= 1500) &&
                    (m_iPostSendDelay >= 1) &&
                    (m_iPostSendDelay <= 1500) &&
                    (m_iOpacity >= PUTTYCS_OPACITY_MIN) &&
                    (m_iCascadeWidth >= PUTTYCS_CASCADE_MINIMUM_WIDTH) &&
                    (m_iCascadeWidth <= PUTTYCS_CASCADE_MAXIMUM_WIDTH) &&
                    (m_iCascadeHeight >= PUTTYCS_CASCADE_MINIMUM_HEIGHT) &&
                    (m_iCascadeHeight <= PUTTYCS_CASCADE_MAXIMUM_HEIGHT) ); 
      
   float fPercent = 
      ((float) (m_iOpacity - PUTTYCS_OPACITY_MIN) /
       (float) ((PUTTYCS_OPACITY_MAX + 1) -
                (PUTTYCS_OPACITY_MIN))) * 100.;

   CString csOpacity;
   csOpacity.Format( _T("%d%%"), ((int) fPercent) + 1 );
      
   SetDlgItemText( IDC_OPACITY2_STATIC, csOpacity );
}

/** 
 * CPreferencesDialog::OnHScroll()
 */

void CPreferencesDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{    
   if ( pScrollBar->GetDlgCtrlID() == IDC_OPACITY_SLIDER )
   {
      m_iOpacity = 
         ((CSliderCtrl*) pScrollBar)->GetPos();
   }

   UpdateDialog();

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

/**
 * CPreferencesDialog::OnAutoArrangeRadio()
 */ 

void CPreferencesDialog::OnAutoArrangeRadio() 
{
   m_iAutoArrange =
      ( (((CButton*) GetDlgItem(IDC_AUTOARRANGE_OFF_RADIO))->
          GetCheck() * PUTTYCS_PREF_AUTO_ARRANGE_OFF) +
        (((CButton*) GetDlgItem(IDC_AUTOARRANGE_CASCADE_RADIO))->
          GetCheck() * PUTTYCS_PREF_AUTO_ARRANGE_CASCADE) +
        (((CButton*) GetDlgItem(IDC_AUTOARRANGE_TILE_RADIO))->
          GetCheck() * PUTTYCS_PREF_AUTO_ARRANGE_TILE) );
   
   UpdateDialog();
}

/**
 * CPreferencesDialog::OnTileMethodRadio()
 */ 

void CPreferencesDialog::OnTileMethodRadio() 
{
   m_iTileMethod =
      ( (((CButton*) GetDlgItem(IDC_TILEMETHOD_VERTICAL_RADIO))->
          GetCheck() * PUTTYCS_PREF_TILE_METHOD_VERTICAL) +
        (((CButton*) GetDlgItem(IDC_TILEMETHOD_HORIZONTAL_RADIO))->
          GetCheck() * PUTTYCS_PREF_TILE_METHOD_HORIZONTAL) +
        (((CButton*) GetDlgItem(IDC_TILEMETHOD_CLASSIC_RADIO))->
          GetCheck() * PUTTYCS_PREF_TILE_METHOD_CLASSIC) );
   
   UpdateDialog();
}

/**
 * CPreferencesDialog::OnAutoMinimizeCheckbox()
 */ 

void CPreferencesDialog::OnAutoMinimizeCheckbox() 
{
   m_iAutoMinimize =
      ((CButton*) GetDlgItem(IDC_AUTOMINIMIZE_CHECKBOX))->GetCheck();   

   UpdateDialog();
}

/**
 * CPreferencesDialog::OnArrangeOnStartupCheckbox()
 */ 

void CPreferencesDialog::OnArrangeOnStartupCheckbox() 
{
   m_iArrangeOnStartup =
      ((CButton*) GetDlgItem(IDC_ARRANGEONSTARTUP_CHECKBOX))->GetCheck();   

   UpdateDialog();
}

/** 
 * CPreferencesDialog::OnChangeCascadeWidthEdit()
 */

void CPreferencesDialog::OnChangeCascadeWidthEdit() 
{
   m_iCascadeWidth =
      GetDlgItemInt( IDC_CASCADE_WIDTH_EDIT );

   UpdateDialog();		
}

/** 
 * CPreferencesDialog::OnChangeCascadeHeightEdit()
 */

void CPreferencesDialog::OnChangeCascadeHeightEdit() 
{
   m_iCascadeHeight =
      GetDlgItemInt( IDC_CASCADE_HEIGHT_EDIT );

   UpdateDialog();	
}

/** 
 * CPreferencesDialog::OnFindButton()
 */

void CPreferencesDialog::OnFindButton() 
{		
   CPuTTYCSDialog* pDialog = (CPuTTYCSDialog*) GetParent();
   CObArray* pWindows = pDialog->GetAllWindows();

   int iWidth = 0;
   int iHeight = 0;

   for ( int loop = 0; loop < pWindows->GetSize(); loop++ )
   {
      CWnd* pWnd = (CWnd*) pWindows->GetAt(loop);

      if (pWnd->IsWindowVisible())
      {         
         CRect rect;
         pWnd->GetClientRect(rect);
         
         int iWndWidth = rect.Width();
         int iWndHeight = rect.Height();

         if ( (iWidth * iHeight) < (iWndWidth * iWndHeight) )
         {
            iWidth = iWndWidth;
            iHeight = iWndHeight;
         }
      }
   }

   if ( ((iWidth >= PUTTYCS_CASCADE_MINIMUM_WIDTH) && (iWidth <= PUTTYCS_CASCADE_MAXIMUM_WIDTH)) && 
        ((iHeight >= PUTTYCS_CASCADE_MINIMUM_HEIGHT) && (iHeight <= PUTTYCS_CASCADE_MAXIMUM_HEIGHT)) )
   {
      m_iCascadeWidth = iWidth;
      m_iCascadeHeight = iHeight;
   }
   else
   {
      CString csMessage;

      csMessage.Format( PUTTYCS_MESSAGEBOX_CASCADE, 
         PUTTYCS_CASCADE_MINIMUM_WIDTH, PUTTYCS_CASCADE_MINIMUM_HEIGHT,
         PUTTYCS_CASCADE_MAXIMUM_WIDTH, PUTTYCS_CASCADE_MAXIMUM_HEIGHT );

      MessageBox( csMessage, PUTTYCS_APP_NAME, MB_ICONEXCLAMATION | MB_OK );

      m_iCascadeWidth = PUTTYCS_CASCADE_DEFAULT_WIDTH;
      m_iCascadeHeight = PUTTYCS_CASCADE_DEFAULT_HEIGHT;
   }
          
   SetDlgItemInt( IDC_CASCADE_WIDTH_EDIT, m_iCascadeWidth );
   SetDlgItemInt( IDC_CASCADE_HEIGHT_EDIT, m_iCascadeHeight );

   UpdateDialog();                     
}

/**
 * CPreferencesDialog::OnUnhideOnExitCheckbox()
 */ 

void CPreferencesDialog::OnUnhideOnExitCheckbox() 
{
   m_iUnhideOnExit =
      IsDlgButtonChecked( IDC_UNHIDEONEXIT_CHECKBOX );      
}

/**
 * CPreferencesDialog::OnToolWindowCheckbox()
 */ 

void CPreferencesDialog::OnToolWindowCheckbox() 
{
   m_iToolWindow =
      IsDlgButtonChecked( IDC_TOOLWINDOW_CHECKBOX );   
}

/**
 * CPreferencesDialog::OnAlwaysOnTopCheckbox()
 */ 

void CPreferencesDialog::OnAlwaysOnTopCheckbox() 
{
   m_iAlwaysOnTop =
      IsDlgButtonChecked( IDC_ALWAYSONTOP_CHECKBOX );   
}

/** 
 * CPreferencesDialog::OnMinimizeToSysTrayCheckbox()
 */

void CPreferencesDialog::OnMinimizeToSysTrayCheckbox() 
{
   m_iMinimizeToSysTray =
      IsDlgButtonChecked( IDC_MINIMIZETOSYSTRAY_CHECKBOX );	
}

/** 
 * CPreferencesDialog::OnTabCompletionCheckbox()
 */

void CPreferencesDialog::OnTabCompletionCheckbox() 
{
   m_iTabCompletion =
      IsDlgButtonChecked( IDC_TABCOMPLETION_CHECKBOX );
}

/** 
 * CPreferencesDialog::OnCmdHistoryScrollThroughCheckbox()
 */

void CPreferencesDialog::OnCmdHistoryScrollThroughCheckbox() 
{
   m_iCmdHistoryScrollThrough =
      IsDlgButtonChecked( IDC_CMDHISTORYSCROLLTHROUGH_CHECKBOX );
}

/**
 * CPreferencesDialog::OnEmulateCopyPasteCheckbox()
 */ 

void CPreferencesDialog::OnEmulateCopyPasteCheckbox() 
{
   m_iEmulateCopyPaste =
      IsDlgButtonChecked( IDC_EMULATECOPYPASTE_CHECKBOX );   
}

/**
 * CPreferencesDialog::OnChangeTransition()
 */ 

void CPreferencesDialog::OnChangeTransition() 
{
   m_iTransition =
      GetDlgItemInt( IDC_TRANSITION_EDIT );

   UpdateDialog();
}

/**
 * CPreferencesDialog::OnChangePostSendDelay()
 */ 

void CPreferencesDialog::OnChangePostSendDelay() 
{
   m_iPostSendDelay =
      GetDlgItemInt( IDC_POST_SEND_DELAY_EDIT );

   UpdateDialog();
}

/**
 * CPreferencesDialog::OnSavePasswordCheckbox()
 */ 

void CPreferencesDialog::OnSavePasswordCheckbox() 
{   
   m_iSavePassword =
      IsDlgButtonChecked( IDC_SAVEPASSWORD_CHECKBOX ); 
   
   UpdateDialog();
}

/**
 * CPreferencesDialog::OnRunOnSystemStartupCheckbox()
 */ 

void CPreferencesDialog::OnRunOnSystemStartupCheckbox() 
{
   m_iRunOnSystemStartup =
      IsDlgButtonChecked( IDC_RUNONSYSTEMSTARTUP_CHECKBOX );   
}

/**
 * CPreferencesDialog::OnCheckForUpdatesCheckbox()
 */ 

void CPreferencesDialog::OnCheckForUpdatesCheckbox() 
{
   m_iCheckForUpdates =
      IsDlgButtonChecked( IDC_CHECKFORUPDATES_CHECKBOX );   
}

/** 
 * CPreferencesDialog::OnOKButton()
 */

void CPreferencesDialog::OnOKButton() 
{
   CDialog::OnOK();      
}

