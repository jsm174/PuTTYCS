# Microsoft Developer Studio Generated NMAKE File, Based on PuTTYCS.dsp
!IF "$(CFG)" == ""
CFG=PuTTYCS - Win32 Debug Unicode
!MESSAGE No configuration specified. Defaulting to PuTTYCS - Win32 Debug Unicode.
!ENDIF 

!IF "$(CFG)" != "PuTTYCS - Win32 Release" && "$(CFG)" != "PuTTYCS - Win32 Debug" && "$(CFG)" != "PuTTYCS - Win32 Debug Unicode" && "$(CFG)" != "PuTTYCS - Win32 Release Unicode"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PuTTYCS.mak" CFG="PuTTYCS - Win32 Debug Unicode"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PuTTYCS - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "PuTTYCS - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "PuTTYCS - Win32 Debug Unicode" (based on "Win32 (x86) Application")
!MESSAGE "PuTTYCS - Win32 Release Unicode" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PuTTYCS - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\PuTTYCS.exe" "$(OUTDIR)\PuTTYCS.bsc"


CLEAN :
	-@erase "$(INTDIR)\AboutDialog.obj"
	-@erase "$(INTDIR)\AboutDialog.sbr"
	-@erase "$(INTDIR)\Base64.obj"
	-@erase "$(INTDIR)\Base64.sbr"
	-@erase "$(INTDIR)\CommandEdit.obj"
	-@erase "$(INTDIR)\CommandEdit.sbr"
	-@erase "$(INTDIR)\FilterDialog.obj"
	-@erase "$(INTDIR)\FilterDialog.sbr"
	-@erase "$(INTDIR)\FiltersDialog.obj"
	-@erase "$(INTDIR)\FiltersDialog.sbr"
	-@erase "$(INTDIR)\PasswordDialog.obj"
	-@erase "$(INTDIR)\PasswordDialog.sbr"
	-@erase "$(INTDIR)\PreferencesDialog.obj"
	-@erase "$(INTDIR)\PreferencesDialog.sbr"
	-@erase "$(INTDIR)\PuTTYCS.obj"
	-@erase "$(INTDIR)\PuTTYCS.pch"
	-@erase "$(INTDIR)\PuTTYCS.res"
	-@erase "$(INTDIR)\PuTTYCS.sbr"
	-@erase "$(INTDIR)\PuTTYCSDialog.obj"
	-@erase "$(INTDIR)\PuTTYCSDialog.sbr"
	-@erase "$(INTDIR)\SendKeys.obj"
	-@erase "$(INTDIR)\SendKeys.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\PuTTYCS.bsc"
	-@erase "$(OUTDIR)\PuTTYCS.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D _WIN32_WINNT=0x401 /FR"$(INTDIR)\\" /Fp"$(INTDIR)\PuTTYCS.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\PuTTYCS.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PuTTYCS.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\AboutDialog.sbr" \
	"$(INTDIR)\Base64.sbr" \
	"$(INTDIR)\CommandEdit.sbr" \
	"$(INTDIR)\FilterDialog.sbr" \
	"$(INTDIR)\FiltersDialog.sbr" \
	"$(INTDIR)\PasswordDialog.sbr" \
	"$(INTDIR)\PreferencesDialog.sbr" \
	"$(INTDIR)\PuTTYCS.sbr" \
	"$(INTDIR)\PuTTYCSDialog.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\SendKeys.sbr"

"$(OUTDIR)\PuTTYCS.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\PuTTYCS.pdb" /machine:I386 /out:"$(OUTDIR)\PuTTYCS.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AboutDialog.obj" \
	"$(INTDIR)\Base64.obj" \
	"$(INTDIR)\CommandEdit.obj" \
	"$(INTDIR)\FilterDialog.obj" \
	"$(INTDIR)\FiltersDialog.obj" \
	"$(INTDIR)\PasswordDialog.obj" \
	"$(INTDIR)\PreferencesDialog.obj" \
	"$(INTDIR)\PuTTYCS.obj" \
	"$(INTDIR)\PuTTYCSDialog.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\SendKeys.obj" \
	"$(INTDIR)\PuTTYCS.res"

"$(OUTDIR)\PuTTYCS.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\PuTTYCS.exe"


CLEAN :
	-@erase "$(INTDIR)\AboutDialog.obj"
	-@erase "$(INTDIR)\Base64.obj"
	-@erase "$(INTDIR)\CommandEdit.obj"
	-@erase "$(INTDIR)\FilterDialog.obj"
	-@erase "$(INTDIR)\FiltersDialog.obj"
	-@erase "$(INTDIR)\PasswordDialog.obj"
	-@erase "$(INTDIR)\PreferencesDialog.obj"
	-@erase "$(INTDIR)\PuTTYCS.obj"
	-@erase "$(INTDIR)\PuTTYCS.pch"
	-@erase "$(INTDIR)\PuTTYCS.res"
	-@erase "$(INTDIR)\PuTTYCSDialog.obj"
	-@erase "$(INTDIR)\SendKeys.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\PuTTYCS.exe"
	-@erase "$(OUTDIR)\PuTTYCS.ilk"
	-@erase "$(OUTDIR)\PuTTYCS.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D _WIN32_WINNT=0x401 /Fp"$(INTDIR)\PuTTYCS.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\PuTTYCS.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PuTTYCS.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\PuTTYCS.pdb" /debug /machine:I386 /out:"$(OUTDIR)\PuTTYCS.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\AboutDialog.obj" \
	"$(INTDIR)\Base64.obj" \
	"$(INTDIR)\CommandEdit.obj" \
	"$(INTDIR)\FilterDialog.obj" \
	"$(INTDIR)\FiltersDialog.obj" \
	"$(INTDIR)\PasswordDialog.obj" \
	"$(INTDIR)\PreferencesDialog.obj" \
	"$(INTDIR)\PuTTYCS.obj" \
	"$(INTDIR)\PuTTYCSDialog.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\SendKeys.obj" \
	"$(INTDIR)\PuTTYCS.res"

"$(OUTDIR)\PuTTYCS.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug Unicode"

OUTDIR=.\PuTTYCS___Win32_Debug_Unicode
INTDIR=.\PuTTYCS___Win32_Debug_Unicode
# Begin Custom Macros
OutDir=.\PuTTYCS___Win32_Debug_Unicode
# End Custom Macros

ALL : "$(OUTDIR)\PuTTYCS.exe"


CLEAN :
	-@erase "$(INTDIR)\AboutDialog.obj"
	-@erase "$(INTDIR)\Base64.obj"
	-@erase "$(INTDIR)\CommandEdit.obj"
	-@erase "$(INTDIR)\FilterDialog.obj"
	-@erase "$(INTDIR)\FiltersDialog.obj"
	-@erase "$(INTDIR)\PasswordDialog.obj"
	-@erase "$(INTDIR)\PreferencesDialog.obj"
	-@erase "$(INTDIR)\PuTTYCS.obj"
	-@erase "$(INTDIR)\PuTTYCS.pch"
	-@erase "$(INTDIR)\PuTTYCS.res"
	-@erase "$(INTDIR)\PuTTYCSDialog.obj"
	-@erase "$(INTDIR)\SendKeys.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\PuTTYCS.exe"
	-@erase "$(OUTDIR)\PuTTYCS.ilk"
	-@erase "$(OUTDIR)\PuTTYCS.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "UNICODE" /D "_UNICODE" /D "MBCS" /D _WIN32_WINNT=0x401 /Fp"$(INTDIR)\PuTTYCS.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\PuTTYCS.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PuTTYCS.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\PuTTYCS.pdb" /debug /machine:I386 /out:"$(OUTDIR)\PuTTYCS.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\AboutDialog.obj" \
	"$(INTDIR)\Base64.obj" \
	"$(INTDIR)\CommandEdit.obj" \
	"$(INTDIR)\FilterDialog.obj" \
	"$(INTDIR)\FiltersDialog.obj" \
	"$(INTDIR)\PasswordDialog.obj" \
	"$(INTDIR)\PreferencesDialog.obj" \
	"$(INTDIR)\PuTTYCS.obj" \
	"$(INTDIR)\PuTTYCSDialog.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\SendKeys.obj" \
	"$(INTDIR)\PuTTYCS.res"

"$(OUTDIR)\PuTTYCS.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Release Unicode"

OUTDIR=.\PuTTYCS___Win32_Release_Unicode
INTDIR=.\PuTTYCS___Win32_Release_Unicode
# Begin Custom Macros
OutDir=.\PuTTYCS___Win32_Release_Unicode
# End Custom Macros

ALL : "$(OUTDIR)\PuTTYCS.exe" "$(OUTDIR)\PuTTYCS.bsc"


CLEAN :
	-@erase "$(INTDIR)\AboutDialog.obj"
	-@erase "$(INTDIR)\AboutDialog.sbr"
	-@erase "$(INTDIR)\Base64.obj"
	-@erase "$(INTDIR)\Base64.sbr"
	-@erase "$(INTDIR)\CommandEdit.obj"
	-@erase "$(INTDIR)\CommandEdit.sbr"
	-@erase "$(INTDIR)\FilterDialog.obj"
	-@erase "$(INTDIR)\FilterDialog.sbr"
	-@erase "$(INTDIR)\FiltersDialog.obj"
	-@erase "$(INTDIR)\FiltersDialog.sbr"
	-@erase "$(INTDIR)\PasswordDialog.obj"
	-@erase "$(INTDIR)\PasswordDialog.sbr"
	-@erase "$(INTDIR)\PreferencesDialog.obj"
	-@erase "$(INTDIR)\PreferencesDialog.sbr"
	-@erase "$(INTDIR)\PuTTYCS.obj"
	-@erase "$(INTDIR)\PuTTYCS.pch"
	-@erase "$(INTDIR)\PuTTYCS.res"
	-@erase "$(INTDIR)\PuTTYCS.sbr"
	-@erase "$(INTDIR)\PuTTYCSDialog.obj"
	-@erase "$(INTDIR)\PuTTYCSDialog.sbr"
	-@erase "$(INTDIR)\SendKeys.obj"
	-@erase "$(INTDIR)\SendKeys.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\PuTTYCS.bsc"
	-@erase "$(OUTDIR)\PuTTYCS.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /D "UNICODE" /D _WIN32_WINNT=0x401 /FR"$(INTDIR)\\" /Fp"$(INTDIR)\PuTTYCS.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\PuTTYCS.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PuTTYCS.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\AboutDialog.sbr" \
	"$(INTDIR)\Base64.sbr" \
	"$(INTDIR)\CommandEdit.sbr" \
	"$(INTDIR)\FilterDialog.sbr" \
	"$(INTDIR)\FiltersDialog.sbr" \
	"$(INTDIR)\PasswordDialog.sbr" \
	"$(INTDIR)\PreferencesDialog.sbr" \
	"$(INTDIR)\PuTTYCS.sbr" \
	"$(INTDIR)\PuTTYCSDialog.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\SendKeys.sbr"

"$(OUTDIR)\PuTTYCS.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\PuTTYCS.pdb" /machine:I386 /out:"$(OUTDIR)\PuTTYCS.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AboutDialog.obj" \
	"$(INTDIR)\Base64.obj" \
	"$(INTDIR)\CommandEdit.obj" \
	"$(INTDIR)\FilterDialog.obj" \
	"$(INTDIR)\FiltersDialog.obj" \
	"$(INTDIR)\PasswordDialog.obj" \
	"$(INTDIR)\PreferencesDialog.obj" \
	"$(INTDIR)\PuTTYCS.obj" \
	"$(INTDIR)\PuTTYCSDialog.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\SendKeys.obj" \
	"$(INTDIR)\PuTTYCS.res"

"$(OUTDIR)\PuTTYCS.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("PuTTYCS.dep")
!INCLUDE "PuTTYCS.dep"
!ELSE 
!MESSAGE Warning: cannot find "PuTTYCS.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "PuTTYCS - Win32 Release" || "$(CFG)" == "PuTTYCS - Win32 Debug" || "$(CFG)" == "PuTTYCS - Win32 Debug Unicode" || "$(CFG)" == "PuTTYCS - Win32 Release Unicode"
SOURCE=.\AboutDialog.cpp

!IF  "$(CFG)" == "PuTTYCS - Win32 Release"


"$(INTDIR)\AboutDialog.obj"	"$(INTDIR)\AboutDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug"


"$(INTDIR)\AboutDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug Unicode"


"$(INTDIR)\AboutDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Release Unicode"


"$(INTDIR)\AboutDialog.obj"	"$(INTDIR)\AboutDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ENDIF 

SOURCE=.\Base64.cpp

!IF  "$(CFG)" == "PuTTYCS - Win32 Release"


"$(INTDIR)\Base64.obj"	"$(INTDIR)\Base64.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug"


"$(INTDIR)\Base64.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug Unicode"


"$(INTDIR)\Base64.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Release Unicode"


"$(INTDIR)\Base64.obj"	"$(INTDIR)\Base64.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ENDIF 

SOURCE=.\CommandEdit.cpp

!IF  "$(CFG)" == "PuTTYCS - Win32 Release"


"$(INTDIR)\CommandEdit.obj"	"$(INTDIR)\CommandEdit.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug"


"$(INTDIR)\CommandEdit.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug Unicode"


"$(INTDIR)\CommandEdit.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Release Unicode"


"$(INTDIR)\CommandEdit.obj"	"$(INTDIR)\CommandEdit.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ENDIF 

SOURCE=.\FilterDialog.cpp

!IF  "$(CFG)" == "PuTTYCS - Win32 Release"


"$(INTDIR)\FilterDialog.obj"	"$(INTDIR)\FilterDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug"


"$(INTDIR)\FilterDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug Unicode"


"$(INTDIR)\FilterDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Release Unicode"


"$(INTDIR)\FilterDialog.obj"	"$(INTDIR)\FilterDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ENDIF 

SOURCE=.\FiltersDialog.cpp

!IF  "$(CFG)" == "PuTTYCS - Win32 Release"


"$(INTDIR)\FiltersDialog.obj"	"$(INTDIR)\FiltersDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug"


"$(INTDIR)\FiltersDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug Unicode"


"$(INTDIR)\FiltersDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Release Unicode"


"$(INTDIR)\FiltersDialog.obj"	"$(INTDIR)\FiltersDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ENDIF 

SOURCE=.\PasswordDialog.cpp

!IF  "$(CFG)" == "PuTTYCS - Win32 Release"


"$(INTDIR)\PasswordDialog.obj"	"$(INTDIR)\PasswordDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug"


"$(INTDIR)\PasswordDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug Unicode"


"$(INTDIR)\PasswordDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Release Unicode"


"$(INTDIR)\PasswordDialog.obj"	"$(INTDIR)\PasswordDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ENDIF 

SOURCE=.\PreferencesDialog.cpp

!IF  "$(CFG)" == "PuTTYCS - Win32 Release"


"$(INTDIR)\PreferencesDialog.obj"	"$(INTDIR)\PreferencesDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug"


"$(INTDIR)\PreferencesDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug Unicode"


"$(INTDIR)\PreferencesDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Release Unicode"


"$(INTDIR)\PreferencesDialog.obj"	"$(INTDIR)\PreferencesDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ENDIF 

SOURCE=.\PuTTYCS.cpp

!IF  "$(CFG)" == "PuTTYCS - Win32 Release"


"$(INTDIR)\PuTTYCS.obj"	"$(INTDIR)\PuTTYCS.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug"


"$(INTDIR)\PuTTYCS.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug Unicode"


"$(INTDIR)\PuTTYCS.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Release Unicode"


"$(INTDIR)\PuTTYCS.obj"	"$(INTDIR)\PuTTYCS.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ENDIF 

SOURCE=.\PuTTYCS.rc

"$(INTDIR)\PuTTYCS.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\PuTTYCSDialog.cpp

!IF  "$(CFG)" == "PuTTYCS - Win32 Release"


"$(INTDIR)\PuTTYCSDialog.obj"	"$(INTDIR)\PuTTYCSDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug"


"$(INTDIR)\PuTTYCSDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug Unicode"


"$(INTDIR)\PuTTYCSDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Release Unicode"


"$(INTDIR)\PuTTYCSDialog.obj"	"$(INTDIR)\PuTTYCSDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\PuTTYCS.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "PuTTYCS - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D _WIN32_WINNT=0x401 /FR"$(INTDIR)\\" /Fp"$(INTDIR)\PuTTYCS.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\PuTTYCS.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D _WIN32_WINNT=0x401 /Fp"$(INTDIR)\PuTTYCS.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\PuTTYCS.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug Unicode"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "UNICODE" /D "_UNICODE" /D "MBCS" /D _WIN32_WINNT=0x401 /Fp"$(INTDIR)\PuTTYCS.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\PuTTYCS.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Release Unicode"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /D "UNICODE" /D _WIN32_WINNT=0x401 /FR"$(INTDIR)\\" /Fp"$(INTDIR)\PuTTYCS.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\PuTTYCS.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\SendKeys.cpp

!IF  "$(CFG)" == "PuTTYCS - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D _WIN32_WINNT=0x401 /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\SendKeys.obj"	"$(INTDIR)\SendKeys.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D _WIN32_WINNT=0x401 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\SendKeys.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Debug Unicode"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "UNICODE" /D "_UNICODE" /D "MBCS" /D _WIN32_WINNT=0x401 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\SendKeys.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PuTTYCS - Win32 Release Unicode"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /D "UNICODE" /D _WIN32_WINNT=0x401 /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\SendKeys.obj"	"$(INTDIR)\SendKeys.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

