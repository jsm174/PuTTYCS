/**
 * Defines.h - PuTTYCS Defines header
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
 *             Added command history clear message
 *             Added AltGr support
 * 11/18/2005: Fixed AltGr support                   J. Millard
 * 12/06/2005: Added mouse Copy/Paste emulation      J. Millard
 */

#if !defined(DEFINES_H__INCLUDED_)
#define DEFINES_H__INCLUDED_

#define PUTTYCS_APP_NAME                    _T( "PuTTYCS" )

#define PUTTYCS_WINDOW_CLASS_PUTTY          _T( "PuTTY" )

#define PUTTYCS_WINDOW_TITLE_TOOL           _T( "PuTTYCS 1.2 - PuTTY Command Sender")
#define PUTTYCS_WINDOW_TITLE_APP            _T( "PuTTYCS 1.2")

#define PUTTYCS_WINDOW_TITLE_ABOUT          _T( "About PuTTYCS 1.2")

#define PUTTYCS_ABOUT_TEXT_LINE1            _T( "PuTTY Command Sender 1.2" )
#define PUTTYCS_ABOUT_TEXT_LINE2            _T( "© 2005  Jason Millard. All rights reserved." )

#define PUTTYCS_WINDOW_TITLE_FILTER_ADD     _T( "Add Filter" )
#define PUTTYCS_WINDOW_TITLE_FILTER_EDIT    _T( "Edit Filter" )
#define PUTTYCS_WINDOW_TITLE_FILTER_COPY    _T( "Copy Filter" )
#define PUTTYCS_WINDOW_TITLE_OPEN_SCRIPT    _T( "Open PuTTYCS Script" )

#define PUTTYCS_MESSAGEBOX_CMDHISTORY       _T( "Are you sure you want to\nclear the command history?" )
        
#define PUTTYCS_URL_HOMEPAGE                _T( "http://www.millardsoftware.com/puttycs/index.php?app=1" )

#define PUTTYCS_FILTER_ALL                  _T( "All PuTTYs||+*")

#define PUTTYCS_FILTER_NAME_SEPARATOR       _T( "||" )

#define PUTTYCS_FILTER_INCLUDE              _T( '+' )
#define PUTTYCS_FILTER_EXCLUDE              _T( '-' )
#define PUTTYCS_FILTER_SEPARATOR            _T( ';' )

#define PUTTYCS_FONT_MARLETT                _T( "Marlett" )
#define PUTTYCS_FONT_SYMBOL                 _T( "Symbol" )

#define PUTTYCS_PREF_SAVE_PASSWORD          _T( "savePassword" )
#define PUTTYCS_PREF_PASSWORD               _T( "password" )

#define PUTTYCS_PREF_CMDHISTORY_MAX_SIZE    100
#define PUTTYCS_PREF_CMDHISTORY_ENTRY       _T( "cmdhistory%02d" )

#define PUTTYCS_PREF_FILTER_MAX_SIZE        100
#define PUTTYCS_PREF_FILTER_ENTRY           _T( "filter%02d" )
#define PUTTYCS_PREF_FILTER                 _T( "filter" )

#define PUTTYCS_PREF_WINDOW_TOOL            _T( "toolWindow" )
#define PUTTYCS_PREF_WINDOW_ALWAYS_ON_TOP   _T( "alwaysOnTop" )
#define PUTTYCS_PREF_WINDOW_TRANSITION      _T( "transition" )

#define PUTTYCS_PREF_AUTO_ARRANGE           _T( "autoArrange" )
#define PUTTYCS_PREF_AUTO_ARRANGE_OFF       1
#define PUTTYCS_PREF_AUTO_ARRANGE_CASCADE   2
#define PUTTYCS_PREF_AUTO_ARRANGE_TILE      3

#define PUTTYCS_PREF_AUTO_MINIMIZE          _T( "autoMinimize" )
#define PUTTYCS_PREF_ARRANGE_ON_STARTUP     _T( "arrangeOnStartup" )
#define PUTTYCS_PREF_UNHIDE_ON_EXIT         _T( "unhideOnExit" )

#define PUTTYCS_PREF_EMULATE_COPY_PASTE     _T( "emulateCopyPaste" )

#define PUTTYCS_PREF_SEND_CR                _T( "sendCR" )

#define PUTTYCS_SENDKEY_BUTTON_UP           _T( "{UP}" )
#define PUTTYCS_SENDKEY_BUTTON_DOWN         _T( "{DOWN}" )
#define PUTTYCS_SENDKEY_BUTTON_RIGHT        _T( "{RIGHT}" )
#define PUTTYCS_SENDKEY_BUTTON_LEFT         _T( "{LEFT}" )
#define PUTTYCS_SENDKEY_BUTTON_CAPSLOCK     _T( "{CAPSLOCK}" )

#define PUTTYCS_SENDKEY_BUTTON_CLEAR        _T( "^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m^m" ) 

#define PUTTYCS_SENDKEY_BUTTON_BREAK        _T( "^c" )
#define PUTTYCS_SENDKEY_BUTTON_ENDTELNET    _T( "^]" )

#define PUTTYCS_SENDKEY_BUTTON_ESCAPE       _T( "{ESC}" )
#define PUTTYCS_SENDKEY_BUTTON_ENTER        _T( "^m" )

#define PUTTYCS_SENDKEY_BUTTON_PLUS         _T( "{PLUS}" )
#define PUTTYCS_SENDKEY_BUTTON_AT           _T( "{AT}" )
#define PUTTYCS_SENDKEY_BUTTON_CARET        _T( "{CARET}" )
#define PUTTYCS_SENDKEY_BUTTON_TILDE        _T( "{TILDE}" )
#define PUTTYCS_SENDKEY_BUTTON_LEFTBRACE    _T( "{LEFTBRACE}" )
#define PUTTYCS_SENDKEY_BUTTON_RIGHTBRACE   _T( "{RIGHTBRACE}" )
#define PUTTYCS_SENDKEY_BUTTON_LEFTPAREN    _T( "{LEFTPAREN}" )
#define PUTTYCS_SENDKEY_BUTTON_RIGHTPAREN   _T( "{RIGHTPAREN}" )
#define PUTTYCS_SENDKEY_BUTTON_PERCENT      _T( "{PERCENT}" )
#define PUTTYCS_SENDKEY_BUTTON_ALTGR        _T( "%" )

#define PUTTYCS_SENDKEY_DELAY_0             _T( "{DELAY=0}" )

#define PUTTYCS_SENDKEY_CHAR_PLUS           _T( '+' )
#define PUTTYCS_SENDKEY_CHAR_TILDE          _T( '~' )
#define PUTTYCS_SENDKEY_CHAR_LEFTBRACE      _T( '{' )
#define PUTTYCS_SENDKEY_CHAR_CARET          _T( '^' )
#define PUTTYCS_SENDKEY_CHAR_AT             _T( '@' )
#define PUTTYCS_SENDKEY_CHAR_RIGHTBRACE     _T( '}' )
#define PUTTYCS_SENDKEY_CHAR_LEFTPAREN      _T( '(' )
#define PUTTYCS_SENDKEY_CHAR_RIGHTPAREN     _T( ')' )
#define PUTTYCS_SENDKEY_CHAR_PERCENT        _T( '%' )
#define PUTTYCS_SENDKEY_CHAR_RIGHTPAREN     _T( ')' )

#define PUTTYCS_SCRIPT_FILETYPE             _T( "PuTTYCS Scripts (*.pcs)|*.pcs||" )

#define PUTTYCS_WILDCMP_WILDCARD            _T( '*' )
#define PUTTYCS_WILDCMP_ANYCHAR             _T( '?' )

#define PUTTYCS_SHELL_EXECUTE_OPEN          _T( "open" )

#define PUTTYCS_FILE_MODE_READ              _T( "r" )

#define PUTTYCS_EMPTY_STRING                _T( "" )

#define PUTTYCS_CASCADE_DIMENSION_WIDTH     600
#define PUTTYCS_CASCADE_DIMENSION_HEIGHT    400

#endif // !defined(DEFINES_H__INCLUDED_)
