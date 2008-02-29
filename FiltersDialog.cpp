/**
 * FiltersDialog.cpp - PuTTYCS Filters Dialog
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
 * 12/15/2005: Updated Help/F1 to go visit website   J. Millard
 */

#include "stdafx.h"
#include "puttycs.h"
#include "FiltersDialog.h"
#include "FilterDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
 * CFiltersDialog::CFiltersDialog()
 */

CFiltersDialog::CFiltersDialog(CWnd* pParent /*=NULL*/)
   : CDialog(CFiltersDialog::IDD, pParent)
{
   //{{AFX_DATA_INIT(CFiltersDialog)
      // NOTE: the ClassWizard will add member initialization here
   //}}AFX_DATA_INIT
}

/**
 * CFiltersDialog::DoDataExchange()
 */

void CFiltersDialog::DoDataExchange(CDataExchange* pDX)
{
   CDialog::DoDataExchange(pDX);
   //{{AFX_DATA_MAP(CFiltersDialog)
      // NOTE: the ClassWizard will add DDX and DDV calls here
   //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFiltersDialog, CDialog)
   //{{AFX_MSG_MAP(CFiltersDialog)
   ON_BN_CLICKED(IDC_ADD_BUTTON, OnAddButton)
   ON_LBN_DBLCLK(IDC_FILTERS_LISTBOX, OnEditButton)
   ON_BN_CLICKED(IDC_COPY_BUTTON, OnCopyButton)
   ON_BN_CLICKED(IDC_REMOVE_BUTTON, OnRemoveButton)
   ON_BN_CLICKED(IDC_REMOVE_ALL_BUTTON, OnRemoveAllButton)
   ON_BN_CLICKED(IDC_MOVEUP_BUTTON, OnMoveUpButton)
   ON_BN_CLICKED(IDC_MOVEDOWN_BUTTON, OnMoveDownButton)
   ON_BN_CLICKED(IDC_OK_BUTTON, OnOKButton)
   ON_BN_CLICKED(IDC_APPLY_BUTTON, OnApplyButton)         
   ON_LBN_SELCHANGE(IDC_FILTERS_LISTBOX, RefreshDialog)
   ON_BN_CLICKED(IDC_EDIT_BUTTON, OnEditButton)
   ON_BN_CLICKED(IDC_CANCEL_BUTTON, OnCancel)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/**
 * CFiltersDialog::setFilters
 */

void CFiltersDialog::setFilters( CStringArray* pCSAFilters )
{
   m_pCSAFilters = pCSAFilters;

   for ( int loop = 0; loop < pCSAFilters->GetSize(); loop++ )
   {
      m_csaFilters.Add(
         pCSAFilters->GetAt(loop) );
   } 
}

/**
 * CFiltersDialog::getFilter()
 */ 

int CFiltersDialog::getFilter()
{
   return m_iFilter;
}

/**
 * CFiltersDialog::setFilter()
 */ 

void CFiltersDialog::setFilter( int filter )
{
   m_iFilter = filter;
}

/**
 * CFiltersDialog::OnHelpInfo()
 */

BOOL CFiltersDialog::OnHelpInfo(HELPINFO* pHelpInfo) 
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
 * CFiltersDialog::OnInitDialog()
 */

BOOL CFiltersDialog::OnInitDialog() 
{
   CDialog::OnInitDialog();
      
   m_bChanges = false;
  
   InitFilterList( m_iFilter );
   
   return TRUE;
}

/**
 * CFiltersDialog::InitFilterList()
 */

void CFiltersDialog::InitFilterList( int pos )
{
   ((CListBox*) GetDlgItem(IDC_FILTERS_LISTBOX))->
      ResetContent();

   for ( int loop = 0;
      loop < m_csaFilters.GetSize(); loop++ )
   {
      CString csFilter = m_csaFilters.GetAt(loop);
      
      ((CListBox*) GetDlgItem(IDC_FILTERS_LISTBOX))->
         AddString( csFilter.Mid(0, 
            csFilter.Find( PUTTYCS_FILTER_NAME_SEPARATOR)) );
   }   

   ((CListBox*) GetDlgItem(IDC_FILTERS_LISTBOX))->
      SetCurSel( pos );   

   RefreshDialog();
}

/**
 * CFiltersDialog::RefreshDialog()
 */

void CFiltersDialog::RefreshDialog() 
{
   int index =   
      ((CListBox*) GetDlgItem(IDC_FILTERS_LISTBOX))->GetCurSel();

   CString csFilter = 
      m_csaFilters.GetAt(index);

   int pos =
      csFilter.Find( PUTTYCS_FILTER_NAME_SEPARATOR );

   if ( pos != -1 )
   {        
     SetDlgItemText( IDC_FILTERLIST_EDIT, 
         csFilter.Mid(pos + 2) );
   }

   ((CButton*) GetDlgItem(IDC_ADD_BUTTON))->EnableWindow( 
      m_csaFilters.GetSize() < PUTTYCS_PREF_FILTER_MAX_SIZE );  

   ((CButton*) GetDlgItem(IDC_COPY_BUTTON))->EnableWindow( 
      m_csaFilters.GetSize() < PUTTYCS_PREF_FILTER_MAX_SIZE );    

   ((CButton*) GetDlgItem(IDC_EDIT_BUTTON))->
      EnableWindow( index != 0 );

   ((CButton*) GetDlgItem(IDC_REMOVE_BUTTON))->
      EnableWindow( index != 0 );

   ((CButton*) GetDlgItem(IDC_REMOVE_ALL_BUTTON))->
      EnableWindow( m_csaFilters.GetSize() > 1 );

   ((CButton*) GetDlgItem(IDC_MOVEUP_BUTTON))->
      EnableWindow( index > 1 );

   ((CButton*) GetDlgItem(IDC_MOVEDOWN_BUTTON))->
      EnableWindow( (index != 0) && 
                    (index < m_csaFilters.GetSize() - 1) );

   ((CButton*) GetDlgItem(IDC_APPLY_BUTTON))->
      EnableWindow( m_bChanges );
}

/**
 * CFiltersDialog::OnAddButton()
 */

void CFiltersDialog::OnAddButton() 
{
   CFilterDialog* pDialog =
      new CFilterDialog();

   pDialog->setWindowTitle( 
      PUTTYCS_WINDOW_TITLE_FILTER_ADD );
   
   if ( pDialog->DoModal() == IDOK )
   {
      m_csaFilters.Add(
         pDialog->getFilterName() +
         PUTTYCS_FILTER_NAME_SEPARATOR + 
         pDialog->getFilterList() );

      m_bChanges = true;

      InitFilterList( m_csaFilters.GetSize() - 1 );
   }

   delete pDialog;
}

/**
 * CFiltersDialog::OnEditButton()
 */

void CFiltersDialog::OnEditButton() 
{  
   int index =   
      ((CListBox*) GetDlgItem(IDC_FILTERS_LISTBOX))->GetCurSel();

   if ( index > 0 )
   {
      CString csFilterName;
      
      ((CListBox*) GetDlgItem(IDC_FILTERS_LISTBOX))->
         GetText( index, csFilterName );

      CString csFilterList;
      GetDlgItemText(IDC_FILTERLIST_EDIT, csFilterList);
 
      CFilterDialog* pDialog =
         new CFilterDialog();

      pDialog->setWindowTitle( 
         PUTTYCS_WINDOW_TITLE_FILTER_ADD );

      pDialog->setFilterName( csFilterName );
      pDialog->setFilterList( csFilterList );

      if ( pDialog->DoModal() == IDOK )
      {
         m_csaFilters.SetAt( index, 
            pDialog->getFilterName() +
            PUTTYCS_FILTER_NAME_SEPARATOR + 
            pDialog->getFilterList() );

         m_bChanges = true;

         InitFilterList( index );
      }

      delete pDialog;
   }
}

/**
 * CFiltersDialog::OnCopyButton()
 */

void CFiltersDialog::OnCopyButton() 
{
   int index =   
     ((CListBox*) GetDlgItem(IDC_FILTERS_LISTBOX))->GetCurSel();

   if ( index != -1 )
   {
      CString csFilterName;      

      ((CListBox*) GetDlgItem(IDC_FILTERS_LISTBOX))->
         GetText( index, csFilterName );

      csFilterName = "Copy of " + csFilterName;

      CString csFilterList;
      GetDlgItemText( IDC_FILTERLIST_EDIT, csFilterList );

      CFilterDialog* pDialog =
         new CFilterDialog();

      pDialog->setWindowTitle( 
         PUTTYCS_WINDOW_TITLE_FILTER_COPY );

      pDialog->setFilterName( csFilterName );
      pDialog->setFilterList( csFilterList );
   
      if ( pDialog->DoModal() == IDOK )
      {
         m_csaFilters.Add(
             pDialog->getFilterName() +
             PUTTYCS_FILTER_NAME_SEPARATOR + 
             pDialog->getFilterList() );

         m_bChanges = true;

         InitFilterList( m_csaFilters.GetSize() - 1 );
      }     
   }   
}

/**
 * CFiltersDialog::OnRemoveButton()
 */

void CFiltersDialog::OnRemoveButton() 
{
   int index =   
      ((CListBox*) GetDlgItem(IDC_FILTERS_LISTBOX))->GetCurSel();

   if ( index > 0 )
   {
      m_csaFilters.RemoveAt( index );
   
      m_bChanges = true;

      InitFilterList( index - 
         (1 * (index == m_csaFilters.GetSize())) );   
   }
}

/**
 * CFiltersDialog::OnRemoveAllButton()
 */

void CFiltersDialog::OnRemoveAllButton() 
{
   for ( int loop = m_csaFilters.GetSize() - 1;loop > 0; loop-- )
   {        
      m_csaFilters.RemoveAt(loop);
   }

   m_bChanges = true; 

   InitFilterList( 0 );   
}

/**
 * CFiltersDialog::OnMoveUpButton()
 */

void CFiltersDialog::OnMoveUpButton() 
{
   int index =   
      ((CListBox*) GetDlgItem(IDC_FILTERS_LISTBOX))->GetCurSel();

   if ( index > 1 )
   {   
      CString csFilter =
         m_csaFilters.GetAt( index );

      CString csTempFilter =
         m_csaFilters.GetAt( index - 1 );

      m_csaFilters.SetAt( index - 1, csFilter );
      m_csaFilters.SetAt( index, csTempFilter );

      m_bChanges = true;

      InitFilterList( index - 1);   
   }
}

/**
 * CFiltersDialog::OnMoveDownButton()
 */

void CFiltersDialog::OnMoveDownButton() 
{
   int index =   
      ((CListBox*) GetDlgItem(IDC_FILTERS_LISTBOX))->GetCurSel();
   
   if ( index > 0 )
   {
      CString csFilter =
         m_csaFilters.GetAt( index );

      CString csTempFilter =
         m_csaFilters.GetAt( index + 1);

      m_csaFilters.SetAt( index + 1, csFilter );
      m_csaFilters.SetAt( index, csTempFilter );

      m_bChanges = true;

      InitFilterList( index + 1 );
   }
}

/**
 * CFiltersDialog::OnOKButton()
 */

void CFiltersDialog::OnOKButton() 
{
    OnApplyButton();

    OnOK();   
}

/**
 * CFiltersDialog::OnApplyButton()
 */

void CFiltersDialog::OnApplyButton() 
{
   m_pCSAFilters->RemoveAll();

   for ( int loop = 0;
      loop < m_csaFilters.GetSize(); loop++ )
   {
      m_pCSAFilters->Add( m_csaFilters.GetAt( loop ) );
   }
   
   m_iFilter =   
     ((CListBox*) GetDlgItem(IDC_FILTERS_LISTBOX))->GetCurSel();

   m_bChanges = false;

   RefreshDialog();
}