@echo off
gcc -c src\statistics.c -o src\statistics.o
ar rcs lib\libstatistics.lib src\statistics.o