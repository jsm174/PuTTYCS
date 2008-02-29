PuTTYCS - PuTTY Command Sender v1.8.1
(C) 2005 - 2008 - Millard Software - jsm174@gmail.com
Release Date: 02/29/08


VERSION HISTORY

02/29/08 - v1.8.1 - Added horizontal and vertical
                    tiling. 
                    Updated tile and cascade to be
                    aware of taskbar. Cascade now 
                    uses entire desktop.               
                    Added additional Post Send delay.
                    [thanks sirandrew]
                    Added --script command line 
                    option.            
                    Rearranged preferences dialog.   
06/21/07 - v1.7   - Added Ctrl-R and Ctrl-D buttons.
                    Added support for any control
                    sequence using {%CTRL%} token in 
                    command input 
                    Added support for an incremental 
                    counter using {%INC%} token in
                    command input
                    Added scroll command history using 
                    up/down arrow keys
                    Changed command history right/left 
                    buttons to up/down buttons
                    Added support to check for PuTTYCS
                    updates                    
                    Added support for automatically
                    running on system startup
11/20/06 - v1.6   - Added support for PuTTYtel, TuTTY,
                    and PieTTY
                    Added support for user defined 
                    cascade size
                    Changed scripting to send CR on
                    last line if Carriage Return is 
                    enabled
05/30/06 - v1.5   - Improved system tray logic
                    Added Windows XP style
                    Added close, backspace, and
                    delete buttons                   
12/21/05 - v1.4a  - Fixed password not sending CR
12/19/05 - v1.4   - Added window opacity
12/15/05 - v1.3   - Added minimize to system tray
                    Added tab completion               
12/06/05 - v1.2   - Added mouse Copy/Paste emulation
                    Navigation through command history
                    moves cursor to end of command 
11/18/05 - v1.1a  - Fixed AltGr support
11/17/05 - v1.1   - Added UNICODE support
                    Added clear command history button
                    Added AltGr support
11/07/05 - v1.0   - Initial release


ABOUT
-----

PuTTYCS is a small windows application that is intended
to be used along with multiple instances of PuTTY
(including PuTTYtel, TuTTY, and PieTTY). It's purpose is
to send the same command to each PuTTY window. It is can
be useful for copying files, starting and stopping
processes, and examining logs on multiple servers. 

If you're not familiar with PuTTY, then this tool is
probably not for you. If you want to find out more 
about PuTTY, visit the PuTTY homepage at:

http://www.chiark.greenend.org.uk/~sgtatham/putty/


INSTALLATION
------------

PuTTYCS is a simple standalone application. It can be
placed and run from anywhere. 


USAGE
-----

Most of PuTTYCS is very self explanatory. You select
a PuTTY filter, enter a command, and click the Send
button. The command will then be sent to each PuTTY
window matching the selected filter. 


FILTERS
-------

A filter is a match to a PuTTY window title. It can
contain wildcards (* and ?). A filter can be inclusive, 
exclusive, or both. 

An inclusive filter should begin with a plus (+), while
an exclusive filter should begin with a minus (-). Multiple
filters should be separated with a semi colon (;).

For example, take the following servers:

www-server1.mydomain.com, www-server2.mydomain.com,
www-server3.mydomain.com, www-server4.mydomain.com

Note: For this example, these server names are exactly
      the same as title of the PuTTY window.

A filter to represent all of these servers could be written 
in the following ways:

      +www-server*

      +www-server?.mydomain.com

      +www-server1.mydomain.com;+www-server2.mydomain.com;
      +www-server3.mydomain.com;+www-server4.mydomain.com;

A filter to represent servers 1, 3, and 4 could be written
as:

      +www-server1.mydomain.com;+www-server3.mydomain.com;
      +www-server4.mydomain.com;

      +www-server*;-www-server2.mydomain.com

      +www-server?.mydomain.com;-*server2*

You can manage the filters by clicking Filters button. Up
to 100 filters can be defined.

From the Filters dialog, filters can be created, modified, 
copied, removed, and re-organized.

   Add - Adds a PuTTY filter
   Edit - Edits the selected PuTTY filter
   Copy - Copies the selected PuTTY filter
   Remove - Removes the selected PuTTY filter
   Remove All - Removes all PuTTY filters

   Move Up - Moves the selected PuTTY filter up the list
   Move Down - Moves the selected PuTTY filter down the list

   NOTE: You can not remove, edit, or move the 
         ALL PuTTYs filter.


PUTTY ARRANGING
---------------

Once filters have been defined, PuTTY windows can easily
be rearranged. They can be cascaded, tiled, minimized, and
even hidden. Just click on the corresponding button.
 
To unhide PuTTY windows, click either the Cascade, Tile,
or Minimize buttons.

To automatically PuTTY windows, close the Close button.


CTRL
----

PuTTYCS supports sending control characters. To send a 
control character, the {%CTRL%} token followed by the
actual control character should be entered in the command
input. For example, to send a control-J, the command input
would be:

   {%CTRL%}J

The CTRL button will automatically add the {%CTRL%} token
at the current position in the command input.


INC
---

The {%INC%} token is used to send an incremental counter to
each filtered PuTTY window. This may be useful, for example,
if you want to copy files with the same name from several
servers into one directory with one command (assume the one
directory is shared across each server):

   cp /opt/WebSphere/AppServer6/profiles/app/logs/SystemOut.log 
   ~user/SystemOut{%INC%}.log

If you have ten filtered PuTTY windows, after executing the 
command, ~user will contain:

   SystemOut1.log
   SystemOut2.log
   SystemOut3.log
   .
   .
   .
   SystemOut10.log

The INC button will automatically add the {%INC%} token
at the current position in the command input.


COMMAND HISTORY
---------------

PuTTYCS supports a command history up to 100 items.
To scroll through the history, use the up and down
arrows above the Command input field. Optionally, you can
use the up and down arrow keys if "Scroll command history
with up/down arrows keys" is checked in the preferences.
The close (x) button will prompt you about clearing the
command history. 


CARRIAGE RETURN
---------------
      
The carriage return push button is to the right of the 
command history buttons. When enabled, a carriage return 
should be sent 1) when the Send button is pressed, and
2) after the last line of a script [see SCRIPT]. This
maybe useful if you want to send most of a command
and than manually complete it.


ARROW PAD
---------

The arrow pad sends arrow key presses to PuTTY windows.
If your comparing files on multiple servers using VI,
you may find this handy.

The center dot can be used to send several carriage
returns to PuTTY windows. If you're tailing log files
and quickly want to clear the screen, you may find
this handy.


BKSP, DELETE, CTRL-C, CTRL-D, CTRL-R, CTRL-], ESC, ENTER
--------------------------------------------------------

These buttons send the corresponding key press to PuTTY
windows. If you use VI, or telnet inside of PuTTY, this
may be useful. 


PASSWORD
--------

This button will bring up the Send Password dialog. If 
you are using PuTTYCS in front of other users, this can
be used to protect your password. 

CAUTION: Make sure all PuTTY windows are waiting for a
         password! 


PREFERENCES
-----------

This button will bring up the Preferences dialog. 
Preferences are loaded each time PuTTYCS is started.

  Window:
  
     Tool Window
        Display PuTTYCS as a tool window with the thin
        title bar.

     Always on top
        Display the PuTTYCS on top of all other windows.

     Minimize to system tray
        Minimizes PuTTYCS to the system tray. If this is
        enabled, PuTTYCS can only be exited through the 
        system tray popup menu.
  
     Opacity
        Use the slider to set the opacity for the PuTTYCS
        window. This maybe useful if PuTTYCS sometimes blocks
        your existing PuTTY windows.


  Auto arrange:
  
     Off, Cascade, Tile
        When switching filters, automatically cascade or
        tile PuTTY windows.

     Minimize other PuTTYs
        When auto arranging filtered PuTTY windows, 
        minimize all other PuTTYs.

     Arrange on startup
        When starting PuTTYCS, auto arranging filtered 
        PuTTY windows.
  
     Unhide PuTTYs on exit
        Unhides any PuTTYs hidden using the Hide button.

  
  Tile method:
  
       Vertical, Horizontal, Classic
       When tiling PuTTY windows use this method. Use
       Classic to tile like PuTTYCS v1.7 and lower.
     

  Cascade dimensions:

       Sets the dimensions of filtered PuTTY windows when 
       the Cascade button is pressed. Press the Find button
       to determine the dimensions of the largest visible 
       PuTTY window.

     NOTE: PuTTYCS only supports cascading dimensions 
           between 98x18 (12x1) and 1042x802 (130x50).
           Default dimensions are 642x386 (80x24).

           These dimensions are hardcoded and will not
           change with system settings. 


  Keyboard/Mouse:

     Enable Tab ccmpletion
        Pressing Tab in the command field, sends the command
        including the Tab key. Useful for file completion in 
        shells like tcsh.
 
     Scroll command history with up/down arrow keys
        Enable this to allow the up and down arrow keys to
        scroll through the command history. 

     Selection copies, right button pastes
        Enable this to emulate PuTTY's selection to 
        clipboard, and right mouse button paste feature.


  Transition delays: (Advanced)

     Window 
        Sets the amount time (in milliseconds) to pause
        after focusing a PuTTY window and before sending the
        command.

        NOTE: The slower the machine or remote connection,
              the higher this value should be.

     Post send
        Sets the amount time (in milliseconds) to pause
        after sending a command to a PuTTY window.

        NOTE: The slower the machine or remote connection,
              the higher this value should be.


  Miscellaneous:

     Save Password
        Saves the password used in the Send Password dialog.

        NOTE: Passwords are encoded in Base64 and stored in
              the PuTTYCS.ini file. This may present a 
              potential security risk. [see CONFIG FILE 
              section]

     Run on system startup
        If enabled, adds a registry entry that automatically 
        executes PuTTYCS when the system is started.
    
        NOTE: The registry entry is:

           HKEY_CURRENT_USER\Software\
              Microsoft\Windows\CurrentVersion\Run\PuTTYCS 

     Check for updates on startup
        If enable, PuTTYCS will check for software updates
        when started.


SCRIPT
------

This button can be used to a load a PuTTYCS script. A
script can be any text file and should end with a .pcs
extension. 

If you do not want to send a carriage return at the end
of the script 1) make sure the last line of the script 
is not blank, and 2) the Carriage Return button is not 
enabled.

PuTTYCS scripts do not support the {%CTRL%} and {%INC%}
tokens.

Because the core of PuTTYCS is based on SendKeys in C++,
the script should follow the syntax defined by SendKeys.
Some features such as application activation have been
removed.

For more information on the SendKeys syntax, visit the
following web site:

http://www.codeproject.com/cpp/sendkeys_cpp_Article.asp


CONFIG FILE
-----------

The configuration file is usually stored in the Windows 
directory:

   C:\Windows\PuTTYCS.ini


COMMAND LINE OPTIONS
--------------------

   -s, --script <path>
      Send a PuTTYCS script. If PuTTYCS is already
      running, the script will be sent to the current
      filter, otherwise the script will be sent to the
      last selected filter.
     
   -h, --help     
      Displays the help dialog. 


KNOWN ISSUES
------------

PuTTYCS does not take over full control of a PuTTY
window. It only activates a PuTTY window and sends the
keystrokes that make up the command. If another application
takes over focus, the keystrokes may be directed to it
instead. Sending keystrokes to multiple PuTTY windows
is usually rather quick so experiencing this problem should
be rare.

The CAPS LOCK and SHIFT keys should not be pressed while
commands are being sent to PuTTY windows. 

Occasionally when launching PuTTYCS with Arrange on Startup 
enabled, PuTTYCS will end up behind the newly arranged
PuTTY windows.

Filters are not checked for uniqueness. Thus you can have
the same filter defined more than once. The Filters are 
scanned in the order they appear in the drop list.

Scripting support is extremely poor. It was added as a "nice
to have". 

PuTTY has some different logic for resizing windows. For 
example, on the Start bar, choose Tile or Cascade. You will 
see that PuTTY windows do not re-arrange themselves properly. 
PuTTYCS gets around this by performing a variety of hide,
move, resize, and show commands. However, at times, PuTTYs
may not arrange as expected. Also, because PuTTY snaps to the
text size, Vertical and Horizontal tiling will contain gaps.

PuTTYCS officially supports PuTTY. I have support to find
PuTTYtel, TuTTY, and PieTTY windows based upon user requests.
I can't guarantee they will work as expected.

To use Tab completion on several windows, press the Tab
key and wait until all windows receive the command. Pressing
the Tab key too early may send an additional Tab to one of
filtered PuTTY windows.

With v1.7+, the Check for Updates uses an API that internally
uses Internet Explorer. Thus, if Internet Explorer can reach
www.millardsoftware.com, PuTTYCS should be able to as well.
However, if it can not, PuTTYCS may appear to freeze for a short
time. For the next release, I will try to improve this code,

PuTTYCS does not work well with multiple monitors. I have 
looked into this and it would be extensive rewrite of the code.


FUTURE
------

When I first released PuTTYCS, I had no plans on releasing
any major updates. However, from all the positive feedback
I've received, I have started coding version 2. It is a 
complete rewrite. Unfortunately, progress is much slower than
I would like.

The next major version supports tabbing and launching PuTTYs.

PuTTYCS still needs a LOGO!! If you can draw and would be 
interested in designing a logo please contact me!!


SOURCE CODE
-----------

Since PuTTY's source code is available, I'm making this source
code available as well. I cleaned it up as best I could, but
comments are sparse. It should compile under Visual C++ 6.


I LIKE IT
---------

If you like this application, drop me a line at jsm174@gmail.com.
It is great to hear from people around the world! 

If you really like and use this application, please consider 
donating. You can use the Paypal link found on the homepage or 
on the "About PuTTYCS..." dialog.


CREDITS
-------

PuTTYCS uses source code from SendKey in C++. For more information
visit: http://www.codeproject.com/cpp/sendkeys_cpp_Article.asp

Base64 encoding and decoding was based on source code found at:
http://www.adp-gmbh.ch/cpp/common/base64.html

The wildcard compare was based on source code found at:
http://www.codeproject.com/string/wildcmp.asp

The ANSI version of CommandLineToArgv() can be found at:
http://www.koders.com/c/fid63F8E1B505B46BF92349E967A24E3DD1D2BFF72D.aspx

Horizontal and vertical tiling routines are based on source code 
found at: http://source.winehq.org/source/dlls/user32/mdi.c
 

DISCLAIMER
----------

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.
