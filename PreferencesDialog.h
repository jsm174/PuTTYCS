/**
 * PreferencesDialog.h - PuTTYCS Preferences Dialog header
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
 * 11/07/2005: Initial version                       J. Millard
 * 11/17/2005: Added UNICODE support                 J. Millard
 *             Added AltGr support 
 * 11/18/2005: Fixed AltGr support                   J. Millard
 * 12/06/2005: Added mouse Copy/Paste emulation      J. Millard
 * 12/15/2005: Added minimize to system tray         J. Millard
 *             Added tab completion
 */

#if !defined(AFX_PREFERENCESDLG_H__4CD996C9_091F_4F4D_BFE3_EDD9236AB74B__INCLUDED_)
#define AFX_PREFERENCESDLG_H__4CD996C9_091F_4F4D_BFE3_EDD9236AB74B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPreferencesDialog : public CDialog
{
// Construction
public:
   CPreferencesDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
   //{{AFX_DATA(CPreferencesDialog)
   enum { IDD = IDD_PREFERENCES_DIALOG };
      // NOTE: the ClassWizard will add data members here
   //}}AFX_DATA

   int getSavePassword();
   void setSavePassword( int iSavePassword );   
   
   int getAutoArrange();
   void setAutoArrange( int iAutoArrange );
   
   int getAutoMinimize();
   void setAutoMinimize( int iAutoMinimize );

   int getArrangeOnStartup();
   void setArrangeOnStartup( int iArrangeOnStartup );

   int getUnhideOnExit();
   void setUnhideOnExit( int iUnhideOnExit);

   int getToolWindow();
   void setToolWindow( int iToolWindow );   
   
   int getAlwaysOnTop();
   void setAlwaysOnTop( int iAlwaysOnTop );   
   
   int getMinimizeToSysTray();
   void setMinimizeToSysTray( int iMinimizeToSysTray );   

   int getTransition();
   void setTransition( int iTransition );

   int getTabCompletion();
   void setTabCompletion( int iTabCompletion );

   int getEmulateCopyPaste();
   void setEmulateCopyPaste( int iEmulateCopyPaste );

// Overrides
   // ClassWizard generated virtual function overrides
   //{{AFX_VIRTUAL(CPreferencesDialog)
   protected:
   virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
   //}}AFX_VIRTUAL

// Implementation
protected:

   int m_iSavePassword;
   int m_iAutoArrange;
   int m_iAutoMinimize;
   int m_iArrangeOnStartup;
   int m_iUnhideOnExit;      
   int m_iToolWindow;   
   int m_iAlwaysOnTop;
   int m_iMinimizeToSysTray;
   int m_iTransition; 
   int m_iEmulateCopyPaste;
   int m_iTabCompletion;
      
   // Generated message map functions
   //{{AFX_MSG(CPreferencesDialog)
   virtual BOOL OnInitDialog();
   afx_msg void OnSavePasswordCheckbox();   
   afx_msg void OnAutoArrangeRadio();
   afx_msg void OnAutoMinimizeCheckbox();
   afx_msg void OnArrangeOnStartupCheckbox();
   afx_msg void OnUnhideOnExitCheckbox();   
   afx_msg void OnToolWindowCheckbox();
   afx_msg void OnAlwaysOnTopCheckbox();
   afx_msg void OnChangeTransition();
   afx_msg void OnEmulateCopyPasteCheckbox();
   afx_msg void OnOKButton();   
	afx_msg void OnMinimizeToSysTrayCheckbox();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnTabCompletionCheckbox();
	//}}AFX_MSG
   DECLARE_MESSAGE_MAP()

   void UpdateDialog();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREFERENCESDLG_H__4CD996C9_091F_4F4D_BFE3_EDD9236AB74B__INCLUDED_)
