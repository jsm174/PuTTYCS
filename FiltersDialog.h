/**
 * FiltersDialog.cpp - PuTTYCS Filters Dialog header
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

#if !defined(AFX_FILTERSDIALOG_H__4D53D37A_8AFC_4E18_9D8E_BCE2978E4D7A__INCLUDED_)
#define AFX_FILTERSDIALOG_H__4D53D37A_8AFC_4E18_9D8E_BCE2978E4D7A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFiltersDialog : public CDialog
{
// Construction
public:
   CFiltersDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
   //{{AFX_DATA(CFiltersDialog)
   enum { IDD = IDD_FILTERS_DIALOG };
      // NOTE: the ClassWizard will add data members here
   //}}AFX_DATA

   void setFilters( CStringArray* pCSAFilters );

   int getFilter();
   void setFilter(int);
      
// Overrides
   // ClassWizard generated virtual function overrides
   //{{AFX_VIRTUAL(CFiltersDialog)
   protected:
   virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
   //}}AFX_VIRTUAL

// Implementation
protected:

   CStringArray m_csaFilters;
   CStringArray* m_pCSAFilters;

   bool m_bChanges;
   int m_iFilter;

   void RefreshDialog();
   void InitFilterList( int );

   // Generated message map functions
   //{{AFX_MSG(CFiltersDialog)
   virtual BOOL OnInitDialog();
   afx_msg void OnAddButton();
   afx_msg void OnEditButton();
   afx_msg void OnCopyButton();
   afx_msg void OnRemoveButton();
   afx_msg void OnRemoveAllButton();
   afx_msg void OnMoveUpButton();
   afx_msg void OnMoveDownButton();
   afx_msg void OnOKButton();   
   afx_msg void OnCancelButton();
   afx_msg void OnApplyButton();
   //}}AFX_MSG
   DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILTERSDIALOG_H__4D53D37A_8AFC_4E18_9D8E_BCE2978E4D7A__INCLUDED_)
