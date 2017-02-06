c:\GnuWin32\bin\bison -dyv sintactico.y
c:\GnuWin32\bin\flex lexico.l

c:\MinGW\bin\gcc.exe lex.yy.c y.tab.c -o primera.exe
primera.exe prueba.txt
@echo off
my_calc.exe
del my_calc.exe
del lex.yy.c
del y.tab.c
del y.output
del y.tab.h
