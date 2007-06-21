/**
 * Defines.h - PuTTYCS Defines header
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
 * 11/07/2005: Initial version                       J. Millard
 * 11/17/2005: Added UNICODE support                 J. Millard
 *             Added command history clear message
 *             Added AltGr support
 * 11/18/2005: Fixed AltGr support                   J. Millard
 * 12/06/2005: Added mouse Copy/Paste emulation      J. Millard
 * 12/15/2005: Added minimize to systray             J. Millard
 *             Added tab completion 
 * 12/19/2005: Added window opacity                  J. Millard   
 * 12/21/2005: Fixed password not sending CR         J. Millard
 * 05/27/2006: Added custom window class             J. Millard
 * 11/20/2006: Added support for PuTTYtel, TuTTY,    J. Millard
 *             and PieTTY. Added support for user 
 *             defined cascade size.
 * 06/21/2007: Added Ctrl-R and Ctrl-D buttons       J. Millard
 *             Added {%CTRL%} command token 
 *             Added {%INC%} command token 
 *             Added scroll command history using 
 *             up/down arrow keys
 *             Added check for PuTTYCS update
 *             Added run on system startup   
 */

#if !defined(DEFINES_H__INCLUDED_)
#define DEFINES_H__INCLUDED_

#define PUTTYCS_APP_NAME                         _T( "PuTTYCS" )

#define PUTTYCS_VERSION                          _T( "1.7" )
#define PUTTYCS_VERSION_INT                      _T( "010700" )

#define PUTTYCS_REGKEY_RUN                       _T( "Software\\Microsoft\\Windows\\CurrentVersion\\Run" )

#define PUTTYCS_WINDOW_CLASS_PUTTY               _T( "PuTTY" )
#define PUTTYCS_WINDOW_CLASS_PUTTYTEL            _T( "PuTTYtel" )
#define PUTTYCS_WINDOW_CLASS_TUTTY               _T( "TuTTY" )
#define PUTTYCS_WINDOW_CLASS_PIETTY              _T( "PieTTY" )

#define PUTTYCS_MSG_TASKBAR_CREATED              _T( "TaskbarCreated" )

#define PUTTYCS_WINDOW_TITLE_TOOL                _T( "PuTTYCS ") PUTTYCS_VERSION _T(" - PuTTY Command Sender")
#define PUTTYCS_WINDOW_TITLE_APP                 _T( "PuTTYCS ") PUTTYCS_VERSION 

#define PUTTYCS_WINDOW_TITLE_ABOUT               _T( "About PuTTYCS...")

#define PUTTYCS_ABOUT_TEXT_LINE1                 _T( "PuTTY Command Sender ") PUTTYCS_VERSION
#define PUTTYCS_ABOUT_TEXT_LINE2                 _T( "© 2005 - 2007 Millard Software. All rights reserved." )

#define PUTTYCS_WINDOW_TITLE_FILTER_ADD          _T( "Add Filter" )
#define PUTTYCS_WINDOW_TITLE_FILTER_EDIT         _T( "Edit Filter" )
#define PUTTYCS_WINDOW_TITLE_FILTER_COPY         _T( "Copy Filter" )
#define PUTTYCS_WINDOW_TITLE_OPEN_SCRIPT         _T( "Open PuTTYCS script" )
#define PUTTYCS_WINDOW_TITLE_LOCATE_PUTTY        _T( "Please locate PuTTY" )
  
#define PUTTYCS_MESSAGEBOX_CMDHISTORY            _T( "Are you sure you want to\nclear the command history?" )
#define PUTTYCS_MESSAGEBOX_CASCADE               _T( "Could not determine cascade dimensions.\n\nPlease verify that:\n\n1) At least one PuTTY window is open and visible.\n2) The PuTTY window is no smaller than %d x %d pixels.\n3) The PuTTY window is no larger than %d x %d pixels.\n\nCascade dimensions will be set to defaults." )
#define PUTTYCS_MESSAGEBOX_CLOSE                 _T( "Are you sure you want to\nclose filtered PuTTYs?" )
        
#define PUTTYCS_MESSAGEBOX_UPDATE                _T( "A new version of PuTTYCS is available for download.\n\nCurrent version: %s\nLatest version: %s\n\nWould you like to go to the PuTTYCS homepage?" )
#define PUTTYCS_MESSAGEBOX_NO_UPDATES            _T( "No updates found. PuTTYCS %s is the latest version." )

#define PUTTYCS_URL_HOMEPAGE                     _T( "http://www.millardsoftware.com/puttycs?m=h&app=" ) PUTTYCS_APP_NAME _T( "&iv=" ) PUTTYCS_VERSION_INT 
#define PUTTYCS_URL_DONATION                     _T( "http://www.millardsoftware.com/puttycs?m=d&app=" ) PUTTYCS_APP_NAME _T( "&iv=" ) PUTTYCS_VERSION_INT 
#define PUTTYCS_URL_UPDATES                      _T( "http://www.millardsoftware.com/software.php?app=" ) PUTTYCS_APP_NAME _T( "&iv=" ) PUTTYCS_VERSION_INT 

#define PUTTYCS_FILTER_ALL                       _T( "All PuTTYs||+*")

#define PUTTYCS_FILTER_NAME_SEPARATOR            _T( "||" )

#define PUTTYCS_FILTER_INCLUDE                   _T( '+' )
#define PUTTYCS_FILTER_EXCLUDE                   _T( '-' )
#define PUTTYCS_FILTER_SEPARATOR                 _T( ';' )

#define PUTTYCS_FONT_MARLETT                     _T( "Marlett" )
#define PUTTYCS_FONT_SYMBOL                      _T( "Symbol" )

#define PUTTYCS_PREF_SAVE_PASSWORD               _T( "savePassword" )
#define PUTTYCS_PREF_PASSWORD                    _T( "password" )

#define PUTTYCS_PREF_CMDHISTORY_MAX_SIZE         100
#define PUTTYCS_PREF_CMDHISTORY_ENTRY            _T( "cmdhistory%02d" )

#define PUTTYCS_PREF_FILTER_MAX_SIZE             100
#define PUTTYCS_PREF_FILTER_ENTRY                _T( "filter%02d" )
#define PUTTYCS_PREF_FILTER                      _T( "filter" )

#define PUTTYCS_PREF_WINDOW_TOOL                 _T( "toolWindow" )
#define PUTTYCS_PREF_WINDOW_ALWAYS_ON_TOP        _T( "alwaysOnTop" )
#define PUTTYCS_PREF_MINIMIZE_TO_SYSTRAY         _T( "minimizeToSysTray" )
#define PUTTYCS_PREF_WINDOW_TRANSITION           _T( "transition" )
#define PUTTYCS_PREF_WINDOW_OPACITY              _T( "windowOpacity" )

#define PUTTYCS_PREF_AUTO_ARRANGE                _T( "autoArrange" )
#define PUTTYCS_PREF_AUTO_ARRANGE_OFF            1
#define PUTTYCS_PREF_AUTO_ARRANGE_CASCADE        2
#define PUTTYCS_PREF_AUTO_ARRANGE_TILE           3

#define PUTTYCS_PREF_CASCADE_WIDTH               _T( "cascadeWidth" )
#define PUTTYCS_PREF_CASCADE_HEIGHT              _T( "cascadeHeight" )

#define PUTTYCS_PREF_AUTO_MINIMIZE               _T( "autoMinimize" )
#define PUTTYCS_PREF_ARRANGE_ON_STARTUP          _T( "arrangeOnStartup" )
#define PUTTYCS_PREF_UNHIDE_ON_EXIT              _T( "unhideOnExit" )

#define PUTTYCS_PREF_TAB_COMPLETION              _T( "tabCompletion" )
#define PUTTYCS_PREF_CMDHISTORY_SCROLL_THROUGH   _T( "cmdhistoryScrollThrough" )
#define PUTTYCS_PREF_EMULATE_COPY_PASTE          _T( "emulateCopyPaste" )

#define PUTTYCS_PREF_SEND_CR                     _T( "sendCR" )

#define PUTTYCS_PREF_RUN_ON_SYSTEM_STARTUP       _T( "runOnSystemStartup" )
#define PUTTYCS_PREF_CHECK_FOR_UPDATES           _T( "checkForUpdates" )

#define PUTTYCS_TOKEN_CHAR_TO_STRING             _T( "%c" )
#define PUTTYCS_TOKEN_INT_TO_STRING              _T( "%d" )
#define PUTTYCS_TOKEN_ATTRIBUTE_START            _T( "%s=\"" )
#define PUTTYCS_TOKEN_ATTRIBUTE_END              _T( "\"" )

#define PUTTYCS_TOKEN_INC                        _T( "{%INC%}" )
#define PUTTYCS_TOKEN_CTRL                       _T( "{%CTRL%}" )
#define PUTTYCS_TOKEN_CHAR_INC                   0x01
#define PUTTYCS_TOKEN_CHAR_CTRL                  0x02

#define PUTTYCS_ATTRIBUTE_NAME                   _T( "name" )
#define PUTTYCS_ATTRIBUTE_VERSION                _T( "version" )
#define PUTTYCS_ATTRIBUTE_INT_VERSION            _T( "intVersion" )

#define PUTTYCS_SENDKEY_BUTTON_UP                _T( "{UP}" )
#define PUTTYCS_SENDKEY_BUTTON_DOWN              _T( "{DOWN}" )
#define PUTTYCS_SENDKEY_BUTTON_RIGHT             _T( "{RIGHT}" )
#define PUTTYCS_SENDKEY_BUTTON_LEFT              _T( "{LEFT}" )
#define PUTTYCS_SENDKEY_BUTTON_CAPSLOCK          _T( "{CAPSLOCK}" )

#define PUTTYCS_SENDKEY_BUTTON_CLEAR             _T( "^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m" ) 

#define PUTTYCS_SENDKEY_BUTTON_BREAK             _T( "^C" )
#define PUTTYCS_SENDKEY_BUTTON_ENDTELNET         _T( "^]" )
#define PUTTYCS_SENDKEY_BUTTON_CTRLD             _T( "^D" )
#define PUTTYCS_SENDKEY_BUTTON_CTRLR             _T( "^R" )

#define PUTTYCS_SENDKEY_BUTTON_ESCAPE            _T( "{ESC}" )
#define PUTTYCS_SENDKEY_BUTTON_TAB               _T( "{TAB}" )
#define PUTTYCS_SENDKEY_BUTTON_ENTER             _T( "^m" )
#define PUTTYCS_SENDKEY_BUTTON_BACKSPACE         _T( "{BACKSPACE}" )
#define PUTTYCS_SENDKEY_BUTTON_DELETE            _T( "{DELETE}" )

#define PUTTYCS_SENDKEY_BUTTON_PLUS              _T( "{PLUS}" )
#define PUTTYCS_SENDKEY_BUTTON_AT                _T( "{AT}" )
#define PUTTYCS_SENDKEY_BUTTON_CARET             _T( "{CARET}" )
#define PUTTYCS_SENDKEY_BUTTON_TILDE             _T( "{TILDE}" )
#define PUTTYCS_SENDKEY_BUTTON_LEFTBRACE         _T( "{LEFTBRACE}" )
#define PUTTYCS_SENDKEY_BUTTON_RIGHTBRACE        _T( "{RIGHTBRACE}" )
#define PUTTYCS_SENDKEY_BUTTON_LEFTPAREN         _T( "{LEFTPAREN}" )
#define PUTTYCS_SENDKEY_BUTTON_RIGHTPAREN        _T( "{RIGHTPAREN}" )
#define PUTTYCS_SENDKEY_BUTTON_PERCENT           _T( "{PERCENT}" )
#define PUTTYCS_SENDKEY_BUTTON_CTRL              _T( "^" )

#define PUTTYCS_SENDKEY_DELAY_0                  _T( "{DELAY=0}" )

#define PUTTYCS_SENDKEY_CHAR_PLUS                _T( '+' )
#define PUTTYCS_SENDKEY_CHAR_TILDE               _T( '~' )
#define PUTTYCS_SENDKEY_CHAR_LEFTBRACE           _T( '{' )
#define PUTTYCS_SENDKEY_CHAR_CARET               _T( '^' )
#define PUTTYCS_SENDKEY_CHAR_AT                  _T( '@' )
#define PUTTYCS_SENDKEY_CHAR_RIGHTBRACE          _T( '}' )
#define PUTTYCS_SENDKEY_CHAR_LEFTPAREN           _T( '(' )
#define PUTTYCS_SENDKEY_CHAR_RIGHTPAREN          _T( ')' )
#define PUTTYCS_SENDKEY_CHAR_PERCENT             _T( '%' )
#define PUTTYCS_SENDKEY_CHAR_RIGHTPAREN          _T( ')' )

#define PUTTYCS_SCRIPT_FILETYPE                  _T( "PuTTYCS Scripts (*.pcs)|*.pcs||" )
 
#define PUTTYCS_WILDCMP_WILDCARD                 _T( '*' )
#define PUTTYCS_WILDCMP_ANYCHAR                  _T( '?' )

#define PUTTYCS_SHELL_EXECUTE_OPEN               _T( "open" )

#define PUTTYCS_FILE_MODE_READ                   _T( "r" )

#define PUTTYCS_EMPTY_STRING                     _T( "" )

#define PUTTYCS_CASCADE_DEFAULT_WIDTH            642
#define PUTTYCS_CASCADE_DEFAULT_HEIGHT           386

#define PUTTYCS_CASCADE_MINIMUM_WIDTH            98   
#define PUTTYCS_CASCADE_MINIMUM_HEIGHT           18

#define PUTTYCS_CASCADE_MAXIMUM_WIDTH            1042
#define PUTTYCS_CASCADE_MAXIMUM_HEIGHT           802

#define PUTTYCS_OPACITY_MIN                      50
#define PUTTYCS_OPACITY_MAX                      255

#define PUTTYCS_WND_CLASS                        _T( "PUTTYCS_WND_CLASS" )

#define WM_USER_MULTIPLE_INSTANCE                WM_USER + 1
#define WM_USER_TNI_MESSAGE                      WM_USER + 2

#endif // !defined(DEFINES_H__INCLUDED_)
