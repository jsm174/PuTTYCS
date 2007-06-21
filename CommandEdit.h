/**
 * CommandEdit.h - Command CEdit Control header
 *
 * Copyright (c) 2005 - 2007 Jason Millard (jsm174@gmail.com)
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
 * 12/06/2005: Initial version                       J. Millard
 * 12/15/2005: Added GetText() method                J. Millard
 * 06/21/2007: Added InsertText() method             J. Millard
 *             Updated for command history scroll
 *             through 
 */

#if !defined(AFX_COMMANDEDIT_H__309531A0_E385_4512_83CF_2A230314E589__INCLUDED_)
#define AFX_COMMANDEDIT_H__309531A0_E385_4512_83CF_2A230314E589__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCommandEdit : public CEdit
{
// Construction
public:
   CCommandEdit();

   CString GetText();
   void InsertText( CString csText);

   void SetText( CString csText );
   void SetEmulateCopyPaste( int iEmulateCopyPaste );
   void SetCmdHistoryScrollThrough( int iCmdHistoryScrollThrough );

// Attributes
public:

// Operations
public:

// Overrides
   // ClassWizard generated virtual function overrides
   //{{AFX_VIRTUAL(CCommandEdit)
   //}}AFX_VIRTUAL

// Implementation
public:
   virtual ~CCommandEdit();

   // Generated message map functions
protected:
   //{{AFX_MSG(CCommandEdit)
   afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
   afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

   int m_iEmulateCopyPaste;
   int m_iCmdHistoryScrollThrough;

   DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMANDEDIT_H__309531A0_E385_4512_83CF_2A230314E589__INCLUDED_)
