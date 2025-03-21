cls
cl.exe /c /EHsc OGL.c
rc.exe OGL.rc
link.exe OGL.res OGL.obj User32.lib GDI32.lib /SUBSYSTEM:WINDOWS
OGL.exe
