PuTTYCS - PuTTY Command Sender v1.4
(C) 2005 - Jason Millard - jsm174@gmail.com
Release Date: 12/19/05


VERSION HISTORY
---------------

12/19/05 - v1.4  - Added window opacity
12/15/05 - v1.3  - Added minimize to system tray
                   Added tab completion				   
12/06/05 - v1.2  - Added mouse Copy/Paste emulation
                   Navigation through command history
                   moves cursor to end of command 
11/18/05 - v1.1a - Fixed AltGr support
11/17/05 - v1.1  - Added UNICODE support
                   Added clear command history button
                   Added AltGr support
11/07/05 - v1.0  - Initial release


ABOUT
-----

PuTTYCS is a small windows application that is intended
to be used along with multiple instances of PuTTY. It's
purpose is to send the same command to each PuTTY window.
It is can be useful for copying files, starting and 
stopping processes, and examine logs on multiple servers. 

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


COMMAND HISTORY
---------------

PuTTYCS supports a command history up to 100 items.
To scroll through the history, use the left and right
arrows above the Command input field. The x button 
will prompt you about clearing the command history.


CARRIAGE RETURN
---------------
      
The carriage return push button next to the command
history arrow button determines if a carriage return 
should be send when the Send button is pressed. This
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


CTRL-C, CTRL-], ESC, ENTER
--------------------------

These buttons send the corresponding key press to PuTTY
windows. If you use VI, or telnet inside of PuTTY,
this may be useful. 


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

  Tool Window:
     Display PuTTYCS as a tool window with the thin
     title bar.

  Always on top:
     Display the PuTTYCS on top of all other windows.

  Minimize to system tray:
     Minimizes PuTTYCS to the system tray.
  
  Transition:
     Sets the amount time (in milliseconds) to pause
     before sending a command to next PuTTY window. 

     NOTE: The slower the machine the higher this value
           should be.

  Opacity:
     Use the slider to set the opacity for the PuTTYCS
	 window. This maybe useful if PuTTYCS sometimes blocks
	 your existing PuTTY windows.

  Auto Arrange (Off, Cascade, Tile) 
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
     

  Enable Tab Completion
     Pressing Tab in the command field, sends the command
     including the Tab key. Useful for file completion in 
     shells like tcsh.

  Selection copies, right button pastes
     Enable this to emulate PuTTY's selection to 
     clipboard, and right mouse button paste feature.


  Save Password
     Saves the password used in the Send Password dialog.

     NOTE: Passwords are encoded in Base64, so they
           are not secure.

  
SCRIPT
------

This button can be used to a load a PuTTYCS script. A
script can be any text file and should end with a .pcs
extension. 

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
see that PuTTY windows does not re-arrange themselves 
properly. PuTTYCS gets around this by performing a variety
of hide, move, resize, and show commands. However, at times
PuTTYs may not arrange as expected. 

To use Tab completion on several windows, press the Tab
key and wait until all windows receive the command. Pressing
the Tab key too early may send an additional Tab to one of
filtered PuTTY windows.



FUTURE
------

Currently I have no plans to update PuTTYCS. Of course, 
if there are reported bugs, I will try to fix them. 

If enough interested is generated, I would consider another
release. I would really like to remove the dependency on 
SendKeys. Don't get me wrong, it's a slick piece of software.
It's just not as bulletproof as I would like for an application 
of this type.


SOURCE CODE
-----------

Since PuTTY's source code is available, I'm making this
source code available as well. I cleaned it up as best I could,
but comments are sparse. It should compile under Visual C++ 6
and above.


I LIKE IT
---------

If you like this application, drop me a line at jsm174@gmail.com.
It's just cool to hear from people around the world!


CREDITS
-------

PuTTYCS uses source code from SendKey in C++. For more information
visit: http://www.codeproject.com/cpp/sendkeys_cpp_Article.asp

Base64 encoding and decoding was based on source code found at:
http://www.adp-gmbh.ch/cpp/common/base64.html

The wildcard compare was based on source code found at:
http://www.codeproject.com/string/wildcmp.asp


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
