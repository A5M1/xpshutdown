@echo off
windres -i rsrc.rc -O coff res.res
gcc -o classicshutdown.exe shutdown.c res.res
echo done.
pause