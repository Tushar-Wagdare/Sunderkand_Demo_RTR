cls

cl.exe /c /EHsc OGL.c

rc.exe OGL.rc

Link.exe OGL.obj OGL.res User32.lib GDI32.lib /SUBSYSTEM:WINDOWS

OGL.exe