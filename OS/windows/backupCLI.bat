set SPath="\\release-server"
set TPath="D:\backup\CLI"
set cpCmd=xcopy /D /E /Y /I

%cpCmd% %SPath%"\CLI\v2.1" %Tpath%"\v2.1"
%cpCmd% %SPath%"\CLI\v3.0" %Tpath%"\v3.0"
%cpCmd% %SPath%"\CLI\ESVA" %Tpath%"\ESVA"
