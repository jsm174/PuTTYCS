/**
 * PasswordDialog.cpp - PuTTYCS Password Dialog
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
 */

#include "stdafx.h"
#include "PuTTYCS.h"
#include "PasswordDialog.h"
#include "Base64.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
 * CPasswordDialog::CPasswordDialog()
 */

CPasswordDialog::CPasswordDialog(CWnd* pParent /*=NULL*/)
   : CDialog(CPasswordDialog::IDD, pParent)
{
   //{{AFX_DATA_INIT(CPasswordDialog)
      // NOTE: the ClassWizard will add member initialization here   
   //}}AFX_DATA_INIT
}

/**
 * CPasswordDialog::DoDataExchange()
 */

void CPasswordDialog::DoDataExchange(CDataExchange* pDX)
{
   CDialog::DoDataExchange(pDX);
   //{{AFX_DATA_MAP(CPasswordDialog)
      // NOTE: the ClassWizard will add DDX and DDV calls here
   //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPasswordDialog, CDialog)
   //{{AFX_MSG_MAP(CPasswordDialog)
   ON_BN_CLICKED(IDC_OK_BUTTON, OnOKButton)
   //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/**
 * CPasswordDialog::setPassword()
 */

void CPasswordDialog::setPassword( CString csPassword )
{
   m_csPassword = csPassword;
}

/**
 * CPasswordDialog::getPassword()
 */

CString CPasswordDialog::getPassword()
{
   return m_csPassword;
}

/**
 * CPasswordDialog::OnInitDialog()
 */

BOOL CPasswordDialog::OnInitDialog() 
{
   CDialog::OnInitDialog();
   
   SetDlgItemText(
      IDC_PASSWORD_CEDIT, CBase64::decode(m_csPassword) );

   return TRUE;  
}

/**
 * CPasswordDialog::OnOKButton()
 */

void CPasswordDialog::OnOKButton() 
{
   CString csPassword;
   
   ((CEdit*) GetDlgItem(IDC_PASSWORD_CEDIT))->
      GetWindowText( csPassword );
   
   m_csPassword =
      CBase64::encode( csPassword );

   OnOK();
}