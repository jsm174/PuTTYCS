/**
 * CommandEdit.cpp - Command CEdit Control
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

#include "stdafx.h"
#include "puttycs.h"
#include "CommandEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
 * CCommandEdit::CCommandEdit()
 */ 

CCommandEdit::CCommandEdit()
{
   m_iEmulateCopyPaste = 0;
   m_iCmdHistoryScrollThrough = 1;
}

/**
 * CCommandEdit::~CCommandEdit()
 */ 

CCommandEdit::~CCommandEdit()
{
}

BEGIN_MESSAGE_MAP(CCommandEdit, CEdit)
   //{{AFX_MSG_MAP(CCommandEdit)
   ON_WM_LBUTTONUP()
   ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/**
 * CCommandEdit::GetText()
 */ 

CString CCommandEdit::GetText()
{
   CString csText;
   GetWindowText(csText);

   return csText;
}

/**
 * CCommandEdit::SetText()
 */ 

void CCommandEdit::SetText( CString csText )
{
   SetWindowText( csText );

   SetSel( csText.GetLength(), -1 );
}

/**
 * CCommandEdit::InsertText()
 */ 

void CCommandEdit::InsertText( CString csText )
{
   ReplaceSel( csText );
}

/**
 * CCommandEdit::SetEmulateCopyPaste()
 */ 

void CCommandEdit::SetEmulateCopyPaste( int iEmulateCopyPaste )
{
   m_iEmulateCopyPaste = iEmulateCopyPaste;
}

/**
 * CCommandEdit::SetCmdHistoryScrollThrough()
 */ 

void CCommandEdit::SetCmdHistoryScrollThrough( int iCmdHistoryScrollThrough )
{
   m_iCmdHistoryScrollThrough = iCmdHistoryScrollThrough;
}

/**
 * CCommandEdit::OnLButtonUp()
 */ 

void CCommandEdit::OnLButtonUp(UINT nFlags, CPoint point) 
{
   CEdit::OnLButtonUp(nFlags, point);

   if ( m_iEmulateCopyPaste )
   {
      int iStart;
      int iEnd;

      GetSel( iStart, iEnd );
   
      if ( iStart != iEnd )
      {                  
         if ( OpenClipboard() ) 
         {      
            CString csText = GetText(); 
       
            CString csCommand = 
               csText.Mid( iStart, (iEnd - iStart) );
                       
            EmptyClipboard(); 
    
            HGLOBAL hglbCopy =
               GlobalAlloc( GMEM_MOVEABLE, 
               ((csCommand.GetLength() + 1) * sizeof(TCHAR)) ); 

            if ( hglbCopy != NULL )
            {
               LPTSTR lptstrCopy =
                  (TCHAR*) GlobalLock( hglbCopy );

               _tcscpy( lptstrCopy, csCommand );

               GlobalUnlock( hglbCopy ); 

               #ifdef UNICODE
                SetClipboardData( CF_UNICODETEXT, hglbCopy );
               #else
                SetClipboardData( CF_TEXT, hglbCopy );
               #endif
            }

            CloseClipboard();                   
         }
      }
   }

}

/**
 * CCommandEdit::OnRButtonUp()
 */ 

void CCommandEdit::OnRButtonUp(UINT nFlags, CPoint point) 
{
   if ( m_iEmulateCopyPaste )
   {  
      Paste();
   }
   else
   {   
      CEdit::OnRButtonUp(nFlags, point);
   }
}

/**
 * CCommandEdit::OnKeyDown()
 */ 

void CCommandEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
   if ( (m_iCmdHistoryScrollThrough) && ((nChar == VK_UP) || (nChar == VK_DOWN)) )
   {	      
      GetParent()->SendMessage( 
         WM_KEYDOWN, (WPARAM) nChar, MAKELPARAM((nRepCnt), (nFlags)) );
   }
   else 
   {
      CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
   }
}