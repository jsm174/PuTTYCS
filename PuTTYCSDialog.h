/**
 * PuTTYCSDialog.h - PuTTYCS Main Dialog header
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

#if !defined(AFX_PuTTYCSDLG_H__7BCAE5A7_75C4_4831_82FD_5A13F846FE61__INCLUDED_)
#define AFX_PuTTYCSDLG_H__7BCAE5A7_75C4_4831_82FD_5A13F846FE61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPuTTYCSDialog : public CDialog
{
// Construction
public:

	CPuTTYCSDialog(CWnd* pParent = NULL);	// standard constructor
   ~CPuTTYCSDialog();
	   
// Dialog Data
	//{{AFX_DATA(CPuTTYCSDialog)
	enum { IDD = IDD_PUTTYCS_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPuTTYCSDialog)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	HICON m_hIcon;

   bool m_bIsClosing;	
   int m_iDialogHeight;

   /**
    * PuTTY Filters
    */

	CStringArray m_csaFilters;
   int m_iFilter;

 	/**
    * Command history
    */

	CStringArray m_csaCmdHistory;
   int m_iCmdHistory;

 	/**
    * Password
    */
	
   int m_iSavePassword;
   CString m_csPassword;
  
   /**
    * Window
    */

	int m_iToolWindow;
	int m_iAlwaysOnTop;
	int m_iTransition;

   /**
    * Auto arrange 
    */
	
   int m_iAutoArrange;
   int m_iAutoMinimize;
	int m_iArrangeOnStartup;   
 	int m_iUnhideOnExit;

   /**
    * Send CR
    */

  	int m_iSendCR;

   CFont* m_pMarlettNormal;
	CFont* m_pMarlettSmall;
   CFont* m_pSymbolSmall;
 
	void sendBuffer(CString csBuffer, bool parse = false);

   void LoadPreferences();
   void SavePreferences();

   void UpdateDialog();
   void RefreshDialog();

	// Generated message map functions
	//{{AFX_MSG(CPuTTYCSDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
   afx_msg void OnSelChangeFiltersCombobox();	
   afx_msg void OnCascadeButton();	   
	afx_msg void OnTileButton();
	afx_msg void OnMinimizeButton();
   afx_msg void OnHideButton();	
   afx_msg void OnFiltersButton();
	afx_msg void OnSendCRPushButton();		
   afx_msg void OnCmdHistoryUpButton();
	afx_msg void OnCmdHistoryDownButton();   
	afx_msg void OnUpButton();
	afx_msg void OnDownButton();
	afx_msg void OnRightButton();
	afx_msg void OnLeftButton();
   afx_msg void OnClearButton();
   afx_msg void OnBreakButton();
	afx_msg void OnEndTelnetButton();
	afx_msg void OnEscapeButton();
	afx_msg void OnEnterButton();	
   afx_msg void OnPasswordButton();
   afx_msg void OnPreferencesButton();	   
	afx_msg void OnScriptButton();	
	afx_msg void OnSendButton();	
	afx_msg void OnClose();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:

   CSendKeys m_skSendKeys;
	CObArray  m_obaWindows;

	static BOOL CALLBACK enumwindowsProc(HWND hwnd, LPARAM lParam); 
	static int wildcmp(const char* wild, const char* string);
   
	void SortWindows();
   static int Compare(const void* pWndS1, const void* pWndS2);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PuTTYCSDLG_H__7BCAE5A7_75C4_4831_82FD_5A13F846FE61__INCLUDED_)
