/**
 * FilterDialog.cpp - PuTTYCS Filter Dialog
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
 * 12/15/2005: Updated Help/F1 to go visit website   J. Millard
 */

#include "stdafx.h"
#include "puttycs.h"
#include "FilterDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
 * CFilterDialog::CFilterDialog()
 */

CFilterDialog::CFilterDialog(CWnd* pParent /*=NULL*/)
   : CDialog(CFilterDialog::IDD, pParent)
{
   //{{AFX_DATA_INIT(CFilterDialog)
      // NOTE: the ClassWizard will add member initialization here
   //}}AFX_DATA_INIT
}

/**
 * CFilterDialog::DoDataExchange()
 */

void CFilterDialog::DoDataExchange(CDataExchange* pDX)
{
   CDialog::DoDataExchange(pDX);
   //{{AFX_DATA_MAP(CFilterDialog)
      // NOTE: the ClassWizard will add DDX and DDV calls here
   //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFilterDialog, CDialog)
   //{{AFX_MSG_MAP(CFilterDialog)
   ON_EN_CHANGE(IDC_FILTERNAME_EDIT, OnChangeFilterName)
   ON_EN_CHANGE(IDC_FILTERLIST_EDIT, OnChangeFilterList)
   ON_BN_CLICKED(IDC_OK_BUTTON, OnOK)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/**
 * CFiltersDialog::OnHelpInfo()
 */

BOOL CFilterDialog::OnHelpInfo(HELPINFO* pHelpInfo) 
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
 * CFilterDialog::OnInitDialog()
 */

BOOL CFilterDialog::OnInitDialog() 
{
   CDialog::OnInitDialog();
   
   SetWindowText( m_csWindowTitle );

   SetDlgItemText( IDC_FILTERNAME_EDIT, m_csFilterName );
   SetDlgItemText( IDC_FILTERLIST_EDIT, m_csFilterList );

   RefreshDialog();
   
   return TRUE;
}

/**
 * CFilterDialog::RefreshDialog()
 */

void CFilterDialog::RefreshDialog()
{
   ((CButton*) GetDlgItem(IDC_OK_BUTTON))->EnableWindow(
      (!m_csFilterName.IsEmpty()) && 
       (m_csFilterName.Find(PUTTYCS_FILTER_NAME_SEPARATOR) == -1) &&
      (!m_csFilterList.IsEmpty()) &&
       (m_csFilterList.Find(PUTTYCS_FILTER_NAME_SEPARATOR) == -1) );      
}

/**
 * CFilterDialog::setWindowTitle()
 */

void CFilterDialog::setWindowTitle( CString csWindowTitle )
{
   m_csWindowTitle = csWindowTitle;
}

/**
 * CFilterDialog::getFilterName()
 */

CString CFilterDialog::getFilterName( )
{
   return m_csFilterName;
}

/**
 * CFilterDialog::setFilterName()
 */

void CFilterDialog::setFilterName( CString csFilterName )
{
   m_csFilterName = csFilterName;
}

/** 
 * CFilterDialog::getFilterList()
 */

CString CFilterDialog::getFilterList( )
{
   return m_csFilterList;
}

/** 
 * CFilterDialog::setFilterList()
 */

void CFilterDialog::setFilterList( CString csFilterList )
{
   m_csFilterList = csFilterList;
}

/**
 * CFilterDialog::OnChangeFilterName()
 */

void CFilterDialog::OnChangeFilterName() 
{
   GetDlgItemText( IDC_FILTERNAME_EDIT, m_csFilterName );

   m_csFilterName.TrimLeft();
   m_csFilterName.TrimRight();
  
   RefreshDialog();
}

/**
 * CFilterDialog::OnChangeFilterList()
 */

void CFilterDialog::OnChangeFilterList() 
{
   GetDlgItemText(IDC_FILTERLIST_EDIT, m_csFilterList);

   m_csFilterList.TrimLeft();
   m_csFilterList.TrimRight();

   RefreshDialog();   
}