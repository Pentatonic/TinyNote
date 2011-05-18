@echo off

::It will detect the short path of the current version 
::of the Java runtime executable

::First test to see if we are on NT or similar OS by seeing 
::if the ampersand is interpreted as a command separator
> reg1.txt echo 1234&rem
type reg1.txt | find "rem"


::Find the current (most recent) Java version
start /w regedit /e reg1.txt "HKEY_LOCAL_MACHINE\SOFTWARE\JavaSoft\Java Runtime Environment"
type reg1.txt | find "CurrentVersion" > reg2.txt

if errorlevel 1 goto 64BITVER
for /f "tokens=2 delims==" %%x in (reg2.txt) do set JavaTemp=%%~x

if errorlevel 1 goto ERROR
if %JavaTemp% LSS 1.5 goto ERROR
echo Java Version = %JavaTemp%
del reg1.txt
del reg2.txt

::Get the home directory of the most recent Java
start /w regedit /e reg1.txt "HKEY_LOCAL_MACHINE\SOFTWARE\JavaSoft\Java Runtime Environment\%JavaTemp%"
type reg1.txt | find "JavaHome" > reg2.txt

if errorlevel 1 goto ERROR
for /f "tokens=2 delims==" %%x in (reg2.txt) do set JavaTemp=%%~x

if errorlevel 1 goto ERROR
echo Java home path (per registry) = %JavaTemp%

del reg1.txt
del reg2.txt

goto CONVERT








::Find the current (most recent) Java version (for Windows 64bit)
: 64BITVER
start /w regedit /e reg1.txt "HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\JavaSoft\Java Runtime Environment"
type reg1.txt | find "CurrentVersion" > reg2.txt

if errorlevel 1 goto ERROR
for /f "tokens=2 delims==" %%x in (reg2.txt) do set JavaTemp=%%~x

if errorlevel 1 goto ERROR
if %JavaTemp% LSS 1.5 goto ERROR
echo Java Version = %JavaTemp%
del reg1.txt
del reg2.txt

::Get the home directory of the most recent Java
start /w regedit /e reg1.txt "HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\JavaSoft\Java Runtime Environment\%JavaTemp%"
type reg1.txt | find "JavaHome" > reg2.txt

if errorlevel 1 goto ERROR
for /f "tokens=2 delims==" %%x in (reg2.txt) do set JavaTemp=%%~x

if errorlevel 1 goto ERROR
echo Java home path (per registry) = %JavaTemp%

del reg1.txt
del reg2.txt



goto CONVERT









::Convert double backslashes to single backslashes
: CONVERT
set JavaHome=
:WHILE
  if "%JavaTemp%"=="" goto WEND
  if not "%JavaHome%"=="" set JavaHome=%JavaHome%\
    
  
  for /f "delims=\" %%x in ("%JavaTemp%") do set JavaHome=%JavaHome%%%x
  
  
  for /f "tokens=1,* delims=\" %%x in ("%JavaTemp%") do set JavaTemp=%%y
  
  goto WHILE
:WEND
set JavaTemp=


::Convert long path (with spaces) into a short path
::for %%x in ("%JavaHome%") do set JavaHome=%%~dpsx
::  echo final = %JavaHome%

goto DONE


:ERROR
echo Java.exe can't be found, please install JRE v1.5 or above.
del reg1.txt
del reg2.txt
pause
goto EXIT

:DONE



IF "%1"=="" GOTO RUNCLI
GOTO RUNSCRIPT

:RUNCLI
"%JavaHome%\bin\java.exe" -jar qqq.jar
GOTO EXIT

:RUNSCRIPT
"%JavaHome%\bin\java.exe" -jar qqq.jar %1 %2 %3 %4 %5 %6 %7 %8 %9
GOTO EXIT

:EXIT

