CLS
del OGL.obj
del OGL.res
del OGL.exe

cl.exe /c /EHsc OGL.c

rc.exe OGL.rc

link.exe OGL.obj OGL.res User32.lib Gdi32.lib /SUBSYSTEM:WINDOWS

OGL.exe
