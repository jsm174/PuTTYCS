/**
 * AboutDialog.cpp - PuTTYCS About Dialog
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
 * 12/15/2005: Updated Help/F1 to go visit website   J. Millard
 */

#include "stdafx.h"
#include "puttycs.h"
#include "AboutDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
 * CAboutDialog::CAboutDialog()
 */

CAboutDialog::CAboutDialog(CWnd* pParent /*=NULL*/)
   : CDialog(CAboutDialog::IDD, pParent)
{
   //{{AFX_DATA_INIT(CAboutDialog)
      // NOTE: the ClassWizard will add member initialization here
   //}}AFX_DATA_INIT
}

/**
 * CAboutDialog::DoDataExchange()
 */

void CAboutDialog::DoDataExchange(CDataExchange* pDX)
{
   CDialog::DoDataExchange(pDX);
   //{{AFX_DATA_MAP(CAboutDialog)
      // NOTE: the ClassWizard will add DDX and DDV calls here
   //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDialog, CDialog)
   //{{AFX_MSG_MAP(CAboutDialog)
   ON_BN_CLICKED(IDC_VISITWEBSITE_BUTTON, OnVisitWebSiteButton)
   ON_BN_CLICKED(IDC_CLOSE_BUTTON, OnOK)   
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/**
 * CAboutDialog::OnHelpInfo()
 */

BOOL CAboutDialog::OnHelpInfo(HELPINFO* pHelpInfo) 
{
   OnVisitWebSiteButton();
   
   return TRUE;	
}

/**
 * CAboutDialog::OnInitDialog()
 */

BOOL CAboutDialog::OnInitDialog() 
{
   CDialog::OnInitDialog();
   
   SetDlgItemText(
      IDC_ABOUT_TEXT_LINE1, PUTTYCS_ABOUT_TEXT_LINE1 );

   SetDlgItemText(
      IDC_ABOUT_TEXT_LINE2, PUTTYCS_ABOUT_TEXT_LINE2 );
   
   return TRUE;  
}

/**
 * CAboutDialog::OnVisitWebSiteButton()
 */

void CAboutDialog::OnVisitWebSiteButton() 
{
   ShellExecute( NULL, 
                 PUTTYCS_SHELL_EXECUTE_OPEN, 
                 PUTTYCS_URL_HOMEPAGE, 
                 NULL, 
                 NULL, 
                 SW_SHOWNORMAL );   
}