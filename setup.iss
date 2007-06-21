;
; setup.iss - PuTTYCS Inno Setup Script
;
; Copyright (c) 2005 Jason Millard (jsm174@gmail.com)
; All rights reserved.
; 
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions
; are met:
; 1. Redistributions of source code must retain the above copyright
;    notice, this list of conditions and the following disclaimer.
; 2. Redistributions in binary form must reproduce the above copyright
;    notice, this list of conditions and the following disclaimer in the
;    documentation and/or other materials provided with the distribution.
; 
; THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
; ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
; IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
; ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
; FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
; DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
; OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
; HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
; LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
; OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
; SUCH DAMAGE.
;
; REVISION HISTORY:
;
; 12/06/2005: Initial version                       J. Millard
; 12/15/2005: Updated for version 1.3               J. Millard
; 12/19/2005: Updated for version 1.4               J. Millard
; 12/21/2005: Updated for version 1.4a              J. Millard
; 05/30/2006: Updated for version 1.5               J. Millard
; 11/20/2006: Updated for version 1.6               J. Millard
; 06/20/2007: Updated for version 1.7               J. Millard
;

[Setup]
AppName=PuTTYCS 1.7
AppVerName=PuTTY Command Sender 1.7
VersionInfoVersion=1.7.0.0
VersionInfoCopyright=Copyright (C) 2005 - 2007 Millard Software
VersionInfoDescription=PuTTYCS - PuTTY Command Sender 1.7
AppPublisher=Millard Software
AppPublisherURL=http://www.millardsoftware.com/puttycs
AppSupportURL=http://www.millardsoftware.com/puttycs
AppUpdatesURL=http://www.millardsoftware.com/puttycs
DefaultDirName={pf}\PuTTYCS
DefaultGroupName=PuTTY Command Sender
LicenseFile=license.txt
OutputDir=.
OutputBaseFilename=setup
Compression=lzma
SolidCompression=yes

[CustomMessages]
ViewREADME=View the README file

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags:
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: 

[Files]
Source: "PuTTYCS___Win32_Release_Unicode\PuTTYCS.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "README.txt"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\PuTTYCS 1.7"; Filename: "{app}\PuTTYCS.exe"
Name: "{group}\README.txt"; Filename: "{app}\README.txt"
Name: "{userdesktop}\PuTTYCS 1.7"; Filename: "{app}\PuTTYCS.exe"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\PuTTYCS 1.7"; Filename: "{app}\PuTTYCS.exe"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\README.txt"; Description: "{cm:ViewREADME}"; Flags: postinstall shellexec skipifsilent
Filename: "{app}\PuTTYCS.exe"; Description: "{cm:LaunchProgram,PuTTY Command Sender 1.7}"; Flags: nowait postinstall skipifsilent
