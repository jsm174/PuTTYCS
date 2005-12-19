/**
 * PuTTYCS.cpp - PuTTYCS Main Application
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
 * 12/19/2005: Added window opacity                  J. Millard
 */

#include "stdafx.h"
#include "PuTTYCS.h"
#include "PuTTYCSDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

lpfn CPuTTYCSApp::g_pSetLayeredWindowAttributes = NULL;

BEGIN_MESSAGE_MAP(CPuTTYCSApp, CWinApp)
   //{{AFX_MSG_MAP(CPuTTYCSApp)
      // NOTE - the ClassWizard will add and remove mapping macros here.
      //    DO NOT EDIT what you see in these blocks of generated code!
   //}}AFX_MSG
   ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/**
 * CPuTTYCSApp::CPuTTYCSApp()
 */

CPuTTYCSApp::CPuTTYCSApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPuTTYCSApp object

CPuTTYCSApp theApp;

/**
 * CPuTTYCSApp::InitInstance()
 */

BOOL CPuTTYCSApp::InitInstance()
{
   /**
    * VC++ 6.0 layered windows support 
    */

   HMODULE hUser32 =
      GetModuleHandle( _T("USER32.DLL") );

   g_pSetLayeredWindowAttributes = 
      (lpfn) GetProcAddress(hUser32, "SetLayeredWindowAttributes");
 
   /**
    * Search for existing application 
    * (tool window style first, then app window style)
    */

   CWnd* pAppWnd =
      CWnd::FindWindow( NULL, PUTTYCS_WINDOW_TITLE_TOOL );


   if ( !pAppWnd )
   {
      pAppWnd =
         CWnd::FindWindow( NULL, PUTTYCS_WINDOW_TITLE_APP );
   }

   if ( pAppWnd )
   {
      pAppWnd->SetForegroundWindow();
   }
   else
   {
      CPuTTYCSDialog dialog;
      m_pMainWnd = &dialog;

      dialog.DoModal();
   }
   
   return FALSE;
}